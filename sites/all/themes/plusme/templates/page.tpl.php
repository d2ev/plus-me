<div class="<?php print $navbar_classes ?>">
  <div class="container">
    <div class="navbar-header">
      <?php if (!empty($logo) || !empty($site_name)): ?>
      <a class="navbar-brand" href="<?php print $front_page ?>" title="<?php print t('Home') ?>">
        <?php if (!empty($logo)): ?>
        <img src="<?php print $logo ?>" alt="<?php print t('Home') ?>" />
        <?php endif ?>
        <?php if (!empty($site_name)): ?>
        <span><?php print $site_name ?></span>
        <?php endif ?>
      </a>
      <?php endif ?>
      <!--<button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>-->
    </div>
    <?php /*if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): */?><!--
      <div class="navbar-collapse collapse">
        <nav role="navigation">
          <?php /*print render($primary_nav) */?>
          <?php /*print render($secondary_nav) */?>
          <?php /*print render($page['navigation']) */?>
        </nav>
      </div>
    --><?php /*endif */?>
  </div>
</div>

<header class="header" <?php print $header_attributes ?>>
  <?php if ($page['header']): ?>
  <?php print render($page['header']) ?>
  <?php endif ?>
</header>

<section class="main">
  <div class="container">
    <div class="row">
      <?php $_content_cols = 12 - 3 * !empty($page['sidebar_first']) - 3 * !empty($page['sidebar_second']) ?>
      <section class="main-col col-md-<?php print $_content_cols  ?><?php print !empty($page['sidebar_first']) ? ' col-md-push-3' : '' ?>">
        <?php print $messages ?>
        <?php print render($page['help']) ?>
        <?php print render($page['highlighted']) ?>
        <div class="panel panel-default">
          <div class="panel-heading">
            <h3 class="panel-title"><?php print $title ?></h3>
          </div>
          <div class="panel-body">
            <div class="header">
                <?php if ($action_links): ?>
                  <ul class="action-links pull-right">
                    <?php print render($action_links) ?>
                  </ul>
                <?php endif ?>
                <?php print render($tabs) ?>
            </div>
            <?php print render($page['content']) ?>
          </div>
        </div>
      </section>
    </div>
  </div>
</section>

<footer class="footer">
  <div class="container">
    <?php print render($page['footer']) ?>
  </div>
</footer>
