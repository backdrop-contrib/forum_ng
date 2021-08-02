<?php

/**
 * @file
 * Contains a Views field handler to provide the level of the forum. Top level
 * parent forums start from 0 and count up, so a first level child forum would
 * be level 1.
 */
class taxonomy_term_data_handler_field_forum_ng_level extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['tid'] = 'tid';
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['level'] = array(
      'default' => 0,
      'translatable' => FALSE,
    );

    return $options;
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    if (!empty($values->tid)) {
      $tid = $values->tid;
    }
    else if (!empty($values->taxonomy_term_data_field_data_forum_ng_taxonomy_tid)) {
      $tid = $values->taxonomy_term_data_field_data_forum_ng_taxonomy_tid;
    }
    else {
      return 0;
    }
    $parents = taxonomy_term_load_parents_all($tid);
    $levels = count($parents) - 1;
    return $levels;
  }
}
