<?php

/**
 * @file
 * Formats a forum post submission string.
 *
 * The submission string indicates when and by whom a topic was submitted.
 *
 * Available variables:
 * - $author_picture: The author of the post's picture (thumbnail).
 * - $author: The author of the post.
 * - $time: How long ago the post was created.
 * - $topic: An object with the raw data of the post. Potentially unsafe. Be
 *   sure to clean this data before printing.
 *
 * @see template_preprocess_forum_ng_submitted()
 * @see theme_forum_ng_submitted()
 *
 * @ingroup themeable
 */
?>
<?php if ($time): ?>
  <div class="submitted forum-ng-submitted">
    <?php print $author_picture; ?>
    <?php print $author; ?>
    <div class="small">
      <?php print $time; ?>
    </div>
</div>
<?php else: ?>
  <?php print t('n/a'); ?>
<?php endif; ?>
