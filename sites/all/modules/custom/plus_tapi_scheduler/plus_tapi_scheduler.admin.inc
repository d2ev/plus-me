<?php

/**
 * @file
 * Everything related to plus_tapi_scheduler's Admin.
 */

/**
 * Implements hook_form.
 */
function plus_tapi_scheduler_config_form() {
  $item = array();

  $item['plus_tapi_scheduler'] = array(
    '#type' => 'fieldset',
    '#title' => t('Scheduler Configuration'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $hours = array(
    '' => 'select',
    '1' => 'Every 1 hour',
    '2' => 'Every 2 hours',
    '3' => 'Every 3 hours',
    '6' => 'Every 6 hours',
    '12' => 'Every 12 hours',
    '24' => 'Every day at 12AM',
  );

  $item['plus_tapi_scheduler']['plus_tapi_scheduler_frequency'] = array(
    '#type' => 'select',
    '#required' => TRUE,
    '#options' => $hours,
    '#title' => t('Plus7 TAPI Scheduler Frequency'),
    '#default_value' => variable_get('plus_tapi_scheduler_frequency', '6'),
  );

  $item['plus_tapi_events'] = array(
    '#type' => 'fieldset',
    '#title' => t('Scheduler Events'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $vocabulary = taxonomy_vocabulary_machine_name_load('Event');
  $terms = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
  $events_list = array();
  foreach ($terms as $key => $value) {
    $events_list[$value->name] = $value->name;
  }

  $suffix = '';
  if (count($events_list) == 0) {
    $suffix = t('Please add atleast one event at ') . l('Add Event', 'admin/structure/taxonomy/event');
  }

  $item['plus_tapi_events']['plus_tapi_scheduler_events'] = array(
    '#type' => 'checkboxes',
    '#required' => TRUE,
    '#options' => $events_list,
    '#title' => t('Plus7 TAPI Events'),
    "#suffix" => $suffix,
    '#default_value' => variable_get('plus_tapi_scheduler_events', array()),
  );

  return system_settings_form($item);
}

function plus_tapi_scheduler_events_list() {
  if (empty($events = variable_get('plus_tapi_scheduler_events', array()))) {
    drupal_set_message('Please select & submit list of events from Scheduler Configuration page.');
    return l('Back to scheduler configuration', 'admin/config/system/plus_tapi_scheduler');
  }

  $item = array();

  $item['plus_tapi_event_scheduler'] = array(
    '#type' => 'fieldset',
    '#title' => t('Scheduler Event Configuration'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  foreach ($events as $term) {
    if (!empty($term)) {
      $term_resource = plus_tapi_get_resource($term);

      if (!empty($term_resource->field_developer_config)) {
        $term_config = drupal_json_decode($term_resource->field_developer_config[LANGUAGE_NONE][0]['value']);
        foreach ($term_config['config'] as $key => $value) {
          $item['plus_tapi_event_scheduler']['plus_tapi_' . strtolower($term) . '_' . $key . '_events'] = array(
            '#type' => 'checkbox',
            '#required' => TRUE,
            '#title' => t('@term', array('@term' => $key)),
            '#default_value' => variable_get('plus_tapi_' . strtolower($term) . '_' . $key . '_events', array()),
          );
        }
      }
    }
  }

  $item['submit'] = array(
    '#type' => 'submit',
    '#value' => 'SUBMIT'
  );

  return $item;
}
