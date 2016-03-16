<?php
/**
 * @file
 * groups.features.inc
 */

/**
 * Implements hook_node_info().
 */
function groups_node_info() {
  $items = array(
    'group' => array(
      'name' => t('Group'),
      'base' => 'node_content',
      'description' => t('Create user groups.'),
      'has_title' => '1',
      'title_label' => t('GroupName'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
