<?php

/**
 * @file
 * todo.
 */

/**
 * Implements hook_views_data_alter().
 */
function forum_ng_views_data_alter(&$data) {
  // Add forum level handler
  $data['taxonomy_term_data']['forum_ng_level'] = array(
    'title' => t('Forum level'),
    'help' => t('Level (starting from 0) for this forum term'),
    'field' => array(
      'handler' => 'taxonomy_term_data_handler_field_forum_ng_level',
    ),
  );

  // Add total posts handler
  $data['taxonomy_term_data']['num_posts'] = array(
    'title' => t('Total posts'),
    'help' => t('Total posts'),
    'field' => array(
      'handler' => 'taxonomy_term_data_handler_field_posts',
    ),
  );

  // Add number of topics handler
  $data['taxonomy_term_data']['num_topics'] = array(
    'title' => t('Total topics'),
    'help' => t('Total topics'),
    'field' => array(
      'handler' => 'taxonomy_term_data_handler_field_topics',
    ),
  );

  // Add reply link field
  $data['taxonomy_term_data']['last_reply'] = array(
    'title' => t('Last post'),
    'help' => t('Last post'),
    'field' => array(
      'handler' => 'taxonomy_term_data_handler_field_last_reply',
    ),
  );

  // Add a relationship handler.
  $data['taxonomy_term_data']['forum_ng'] = array(
    'title' => t('Forum'),
    'help' => t('Provide a forum'),
    'relationship' => array(
      'base' => 'forum_index',
      'field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Forum index'),
    ),
  );

}

/**
 * Implements hook_views_data().
 */
function forum_ng_views_data() {

  $data['forum_index']['table']['group'] = t('Forum');
  $data['forum_index']['table']['base'] = array(
    'field' => 'nid',
    'title' => t('Forum content'),
    'access query tag' => 'node_access',
  );

  $data['forum_index']['nid'] = array(
    'title' => t('Nid'),
    'help' => t('The content ID of the forum index entry.'),
    'field' => array(
      'id' => 'numeric',
    ),
    'filter' => array(
      'id' => 'numeric',
    ),
    'argument' => array(
      'id' => 'numeric',
    ),
    'sort' => array(
      'id' => 'standard',
    ),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'label' => t('Node'),
    ),
  );

  $data['forum_index']['title'] = array(
    'title' => t('Title'),
    'help' => t('The content title.'),
    'field' => array(
      'id' => 'standard',
      'link_to_node default' => TRUE,
    ),
    'sort' => array(
      'id' => 'standard',
    ),
    'filter' => array(
      'id' => 'string',
    ),
    'argument' => array(
      'id' => 'string',
    ),
  );

  $data['forum_index']['tid'] = array(
    'title' => t('Has taxonomy term ID'),
    'help' => t('Display content if it has the selected taxonomy terms.'),
    'argument' => array(
      'id' => 'taxonomy_index_tid',
      'name table' => 'taxonomy_term_data',
      'name field' => 'name',
      'empty field name' => t('Uncategorized'),
      'numeric' => TRUE,
      'skip base' => 'taxonomy_term_data',
    ),
    'field' => array(
      'id' => 'numeric',
    ),
    'filter' => array(
      'title' => t('Has taxonomy term'),
      'id' => 'taxonomy_index_tid',
      'hierarchy table' => 'taxonomy_term_hierarchy',
      'numeric' => TRUE,
      'skip base' => 'taxonomy_term_data',
      'allow empty' => TRUE,
    ),
    'relationship' => array(
      'base' => 'taxonomy_term',
      'base field' => 'tid',
      'label' => t('Term'),
    ),
  );


  $data['forum_index']['created'] = array(
    'title' => t('Post date'),
    'help' => t('The date the content was posted.'),
    'field' => array(
      'id' => 'date',
    ),
    'sort' => array(
      'id' => 'date'
    ),
    'filter' => array(
      'id' => 'date',
    ),
  );

  $data['forum_index']['sticky'] = array(
    'title' => t('Sticky'),
    'help' => t('Whether or not the content is sticky.'),
    'field' => array(
      'id' => 'boolean',
      'click sortable' => TRUE,
      'output formats' => array(
        'sticky' => array(t('Sticky'), t('Not sticky')),
      ),
    ),
    'filter' => array(
      'id' => 'boolean',
      'label' => t('Sticky'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'id' => 'standard',
      'help' => t('Whether or not the content is sticky. To list sticky content first, set this to descending.'),
    ),
  );

  $data['forum_index']['last_comment_timestamp'] = array(
    'title' => t('Last comment time'),
    'help' => t('Date and time of when the last comment was posted.'),
    'field' => array(
      'id' => 'comment_last_timestamp',
    ),
    'sort' => array(
      'id' => 'date',
    ),
    'filter' => array(
      'id' => 'date',
    ),
  );

  $data['forum_index']['comment_count'] = array(
    'title' => t('Comment count'),
    'help' => t('The number of comments a node has.'),
    'field' => array(
      'id' => 'numeric',
    ),
    'filter' => array(
      'id' => 'numeric',
    ),
    'sort' => array(
      'id' => 'standard',
    ),
    'argument' => array(
      'id' => 'standard',
    ),
  );

  return $data;
}
