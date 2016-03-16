<?php
echo shell_exec('cd /var/www/html/plus-me/ && git pull');
die('Done. ' . mktime());
?>
