<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying reply links to
 * forum forum_posts as fields.
 */
class taxonomy_term_data_handler_field_last_reply extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['tid'] = 'tid';
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['text'] = array(
      'default' => '',
      'translatable' => TRUE,
    );

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $forums = forum_ng_forum_load();
    $forum = $forums->forums[$values->tid];

    $last_reply = theme('forum_ng_submitted', array('topic' => $forum->last_post));
    return isset($last_reply) ? $last_reply : 'n/a';
  }
}
