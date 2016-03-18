<?php

/**
 * @file
 * Everything related to plus_tapi's Admin.
 */

/**
 * Implements hook_form.
 */
function plus_tapi_config_form() {
  $item = array();

  $item['plus_tapi'] = array(
    '#type' => 'fieldset',
    '#title' => t('Plus7 TAPI Configuration'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $item['plus_tapi']['plus_tapi_request_method'] = array(
    '#type' => 'select',
    '#required' => TRUE,
    '#options' => array(
      '' => 'Select',
      'curl' => t('cURL'),
      'http' => t('HTTP'),
    ),
    '#title' => t('Plus7 TAPI request method'),
    '#default_value' => variable_get('plus_tapi_request_method', 'curl'),
  );

  return system_settings_form($item);
}
