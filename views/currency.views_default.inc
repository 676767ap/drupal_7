<?php
/**
 * Implements hook_views_default_views().
 */
function currency_views_default_views() {
  $view = new view();
  $view->name = 'chart_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Rates view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Курс';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['width'] = '1400';
  $handler->display->display_options['style_options']['height'] = '400';
  $handler->display->display_options['style_options']['yaxis_title'] = 'RUB';
  $handler->display->display_options['style_options']['yaxis_min'] = '0';
  $handler->display->display_options['style_options']['label_field'] = 'field_range_item_date';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'field_cur_day_value' => 'field_cur_day_value',
    'field_range_item_date' => 'field_range_item_date',
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'field_cur_day_value' => '#2f7ed8',
    'field_range_item_date' => '#0d233a',
  );
  /* Field: Content: Currency rate value */
  $handler->display->display_options['fields']['field_cur_day_value']['id'] = 'field_cur_day_value';
  $handler->display->display_options['fields']['field_cur_day_value']['table'] = 'field_data_field_cur_day_value';
  $handler->display->display_options['fields']['field_cur_day_value']['field'] = 'field_cur_day_value';
  $handler->display->display_options['fields']['field_cur_day_value']['label'] = 'Курс';
  $handler->display->display_options['fields']['field_cur_day_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Date (humanreadable) */
  $handler->display->display_options['fields']['field_range_item_date']['id'] = 'field_range_item_date';
  $handler->display->display_options['fields']['field_range_item_date']['table'] = 'field_data_field_range_item_date';
  $handler->display->display_options['fields']['field_range_item_date']['field'] = 'field_range_item_date';
  $handler->display->display_options['fields']['field_range_item_date']['label'] = '';
  $handler->display->display_options['fields']['field_range_item_date']['element_label_colon'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'currency' => 'currency',
  );

  /* Display: All days rates */
  $handler = $view->new_display('page', 'All days rates', 'page_all_days_rates');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '34';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<button><a href="/exchange">График курса валюты</a></button><button><a href="/load_data">Загрузка данных</a></button>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Character currency code */
  $handler->display->display_options['fields']['field_char_code']['id'] = 'field_char_code';
  $handler->display->display_options['fields']['field_char_code']['table'] = 'field_data_field_char_code';
  $handler->display->display_options['fields']['field_char_code']['field'] = 'field_char_code';
  $handler->display->display_options['fields']['field_char_code']['label'] = '';
  $handler->display->display_options['fields']['field_char_code']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Название';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Currency rate value */
  $handler->display->display_options['fields']['field_cur_value']['id'] = 'field_cur_value';
  $handler->display->display_options['fields']['field_cur_value']['table'] = 'field_data_field_cur_value';
  $handler->display->display_options['fields']['field_cur_value']['field'] = 'field_cur_value';
  $handler->display->display_options['fields']['field_cur_value']['label'] = 'Курс';
  $handler->display->display_options['fields']['field_cur_value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cur_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Date of measure in humanreadable form */
  $handler->display->display_options['fields']['field_cur_date_formated']['id'] = 'field_cur_date_formated';
  $handler->display->display_options['fields']['field_cur_date_formated']['table'] = 'field_data_field_cur_date_formated';
  $handler->display->display_options['fields']['field_cur_date_formated']['field'] = 'field_cur_date_formated';
  $handler->display->display_options['fields']['field_cur_date_formated']['label'] = 'Дата';
  $handler->display->display_options['fields']['field_cur_date_formated']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date of measure (field_cur_date) */
  $handler->display->display_options['sorts']['field_cur_date_value']['id'] = 'field_cur_date_value';
  $handler->display->display_options['sorts']['field_cur_date_value']['table'] = 'field_data_field_cur_date';
  $handler->display->display_options['sorts']['field_cur_date_value']['field'] = 'field_cur_date_value';
  $handler->display->display_options['sorts']['field_cur_date_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_cur_date_value']['expose']['label'] = 'Дата';
  /* Sort criterion: Content: Currency rate value (field_cur_value) */
  $handler->display->display_options['sorts']['field_cur_value_value']['id'] = 'field_cur_value_value';
  $handler->display->display_options['sorts']['field_cur_value_value']['table'] = 'field_data_field_cur_value';
  $handler->display->display_options['sorts']['field_cur_value_value']['field'] = 'field_cur_value_value';
  $handler->display->display_options['sorts']['field_cur_value_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_cur_value_value']['expose']['label'] = 'Курс';
  /* Sort criterion: Content: Date of measure (field_cur_date) */
  $handler->display->display_options['sorts']['field_cur_date_value_1']['id'] = 'field_cur_date_value_1';
  $handler->display->display_options['sorts']['field_cur_date_value_1']['table'] = 'field_data_field_cur_date';
  $handler->display->display_options['sorts']['field_cur_date_value_1']['field'] = 'field_cur_date_value';
  $handler->display->display_options['sorts']['field_cur_date_value_1']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'currency' => 'currency',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Название валюты';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
  );
  /* Filter criterion: Content: Date of measure in humanreadable form (field_cur_date_formated) */
  $handler->display->display_options['filters']['field_cur_date_formated_value']['id'] = 'field_cur_date_formated_value';
  $handler->display->display_options['filters']['field_cur_date_formated_value']['table'] = 'field_data_field_cur_date_formated';
  $handler->display->display_options['filters']['field_cur_date_formated_value']['field'] = 'field_cur_date_formated_value';
  $handler->display->display_options['filters']['field_cur_date_formated_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_cur_date_formated_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cur_date_formated_value']['expose']['operator_id'] = 'field_cur_date_formated_value_op';
  $handler->display->display_options['filters']['field_cur_date_formated_value']['expose']['label'] = 'Дата';
  $handler->display->display_options['filters']['field_cur_date_formated_value']['expose']['description'] = 'Дата в формате d.m.Y (например 01.03.2020)';
  $handler->display->display_options['filters']['field_cur_date_formated_value']['expose']['operator'] = 'field_cur_date_formated_value_op';
  $handler->display->display_options['filters']['field_cur_date_formated_value']['expose']['identifier'] = 'field_cur_date_formated_value';
  $handler->display->display_options['filters']['field_cur_date_formated_value']['expose']['remember_roles'] = array(
    2 => '2',
  );
  $handler->display->display_options['path'] = 'all_days_rates';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Курсы валют';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block for load page */
  $handler = $view->new_display('block', 'Block for load page', 'block_load_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Курс за выбранный период';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '34';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_cur_day_value' => 'field_cur_day_value',
    'field_range_item_date' => 'field_range_item_date',
  );
  $handler->display->display_options['style_options']['class'] = '';
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_cur_day_value' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_range_item_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Character currency code */
  $handler->display->display_options['fields']['field_char_code']['id'] = 'field_char_code';
  $handler->display->display_options['fields']['field_char_code']['table'] = 'field_data_field_char_code';
  $handler->display->display_options['fields']['field_char_code']['field'] = 'field_char_code';
  $handler->display->display_options['fields']['field_char_code']['label'] = '';
  $handler->display->display_options['fields']['field_char_code']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Название';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Currency rate value */
  $handler->display->display_options['fields']['field_cur_value']['id'] = 'field_cur_value';
  $handler->display->display_options['fields']['field_cur_value']['table'] = 'field_data_field_cur_value';
  $handler->display->display_options['fields']['field_cur_value']['field'] = 'field_cur_value';
  $handler->display->display_options['fields']['field_cur_value']['label'] = 'Курс';
  $handler->display->display_options['fields']['field_cur_value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cur_value']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Date of measure in humanreadable form */
  $handler->display->display_options['fields']['field_cur_date_formated']['id'] = 'field_cur_date_formated';
  $handler->display->display_options['fields']['field_cur_date_formated']['table'] = 'field_data_field_cur_date_formated';
  $handler->display->display_options['fields']['field_cur_date_formated']['field'] = 'field_cur_date_formated';
  $handler->display->display_options['fields']['field_cur_date_formated']['label'] = 'Дата';
  $handler->display->display_options['fields']['field_cur_date_formated']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date of measure (field_cur_date) */
  $handler->display->display_options['sorts']['field_cur_date_value']['id'] = 'field_cur_date_value';
  $handler->display->display_options['sorts']['field_cur_date_value']['table'] = 'field_data_field_cur_date';
  $handler->display->display_options['sorts']['field_cur_date_value']['field'] = 'field_cur_date_value';
  $handler->display->display_options['sorts']['field_cur_date_value']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'currency' => 'currency',
  );
  /* Filter criterion: Content: Date of measure in humanreadable form (field_cur_date_formated) */
  $handler->display->display_options['filters']['field_cur_date_formated_value']['id'] = 'field_cur_date_formated_value';
  $handler->display->display_options['filters']['field_cur_date_formated_value']['table'] = 'field_data_field_cur_date_formated';
  $handler->display->display_options['filters']['field_cur_date_formated_value']['field'] = 'field_cur_date_formated_value';
  $handler->display->display_options['filters']['field_cur_date_formated_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_cur_date_formated_value']['value'] = '.';
  $handler->display->display_options['filters']['field_cur_date_formated_value']['expose']['operator_id'] = 'field_cur_date_formated_value_op';
  $handler->display->display_options['filters']['field_cur_date_formated_value']['expose']['label'] = 'Date of measure in humanreadable form (field_cur_date_formated)';
  $handler->display->display_options['filters']['field_cur_date_formated_value']['expose']['operator'] = 'field_cur_date_formated_value_op';
  $handler->display->display_options['filters']['field_cur_date_formated_value']['expose']['identifier'] = 'field_cur_date_formated_value';
  $handler->display->display_options['filters']['field_cur_date_formated_value']['expose']['remember_roles'] = array(
    2 => '2',
  );
  $translatables['chart_view'] = array(
    t('Master'),
    t('Курс'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All days rates'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('<button><a href="/exchange">График курса валюты</a></button><button><a href="/load_data">Загрузка данных</a></button>'),
    t('Название'),
    t('Дата'),
    t('Название валюты'),
    t('Дата в формате d.m.Y (например 01.03.2020)'),
    t('Block for load page'),
    t('Курс за выбранный период'),
    t('Date of measure in humanreadable form (field_cur_date_formated)'),
  );
  $views[$view->name] = $view;
  return $views;
}
?>
