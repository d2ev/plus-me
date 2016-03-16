<?php

/**
 * Implements hook_html_head_alter().
 */
function plusme_html_head_alter(&$head_elements) {
  foreach ($head_elements as &$element) {
    if (isset($element['#attributes']['rel'])
        && in_array($element['#attributes']['rel'], array('canonical', 'shortlink'))
        && drupal_is_front_page()) {
      $element['#attributes']['href'] = '/';
    }
  }
}

/**
 * Preprocesses variables for page.tpl.php.
 */
function plusme_preprocess_page(&$vars) {
  $vars['header_attributes'] = '';
  $page = &$vars['page'];
}

/**
 * Processes variables for page.tpl.php.
 */
function plusme_process_page(&$vars) {
  $page = &$vars['page'];

  if ($vars['is_front'] && !$vars['title']) {
    $vars['title'] = $vars['site_name'];
  }
}

/**
 * Preprocesses variables for region.tpl.php.
 */
function plusme_preprocess_region(&$vars) {
  $vars['block_count'] = count(element_children($vars['elements']));
}

/**
 * Preprocesses variables for block.tpl.php.
 */
function plusme_preprocess_block(&$vars) {
  $block = &$vars['block'];

  if ($block->region == 'footer' && $block->module == 'menu' && $block->delta == 'menu-footer-sitemap') {
    $vars['classes_array'][] = 'row';
  }
}

/**
 * Overrides theme_menu_tree() for menu_footer_sitemap.
 */
function plusme_menu_tree__menu_footer_sitemap($vars) {
  return '<ul class="list-unstyled">' . $vars['tree'] . '</ul>';
}

/**
 * Overrides theme_menu_link() for menu_footer_sitemap.
 */
function plusme_menu_link__menu_footer_sitemap($vars) {
  $element = $vars['element'];

  $sub_menu = $element['#below'] ? drupal_render($element['#below']) : '';
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  if ($element['#original_link']['depth'] == 1) {
    $element['#attributes']['class'][] = 'root col-xs-6 col-sm-4 col-md-2';
  }
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Overrides theme_system_powered_by().
 */
function plusme_system_powered_by() {
  return '© ' . date('Y') . ' <a href="' . base_path() . '">' . variable_get('site_name') . '</a>.';
}

/**
 * Preprocesses variables for theme_item_list().
 */
function plusme_preprocess_item_list(&$vars) {
  $vars['attributes']['class'][] = 'list-unstyled';
}

/**
 * Preprocesses variables for theme_links().
 */
function plusme_preprocess_links(&$vars) {
  $vars['attributes']['class'][] = 'list-unstyled';
}
