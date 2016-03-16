<?php
/**
 * @file
 * plan.features.inc
 */

/**
 * Implements hook_node_info().
 */
function plan_node_info() {
  $items = array(
    'plan' => array(
      'name' => t('Plan'),
      'base' => 'node_content',
      'description' => t('Create paln my day event.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
