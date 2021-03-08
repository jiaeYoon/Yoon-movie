<!DOCTYPE html>
<html lang="en">
 <head>
  <meta charset="UTF-8">
  <title>Check</title>
  <style type="text/css">
  body {color: white};
  </style>
 </head>

 <body>
 <h3>만족도 조사 응답 확인</h3><hr>
  <?php
	$g = $_GET["good"];
	$f = $_GET["feedback"];
  ?>

  <p>이 홈페이지에 대해 5점 만점에 &#91;<?php print $g; ?>&#93;만큼 만족한다고 답했습니다.</p>
  <p>이 홈페이지에 대해 &#91;<?php print $f; ?>&#93;라고 피드백했습니다.</p>
 </body>
</html>
