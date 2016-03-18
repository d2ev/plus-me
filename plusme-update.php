<?php
echo shell_exec('cd /var/www/html/plus-me/ && git pull https://phanimohan:plusme.care@github.com/d2ev/plus-me');
//echo shell_exec('sh plusme-update.sh');
die('Done. ' . mktime());
?>
