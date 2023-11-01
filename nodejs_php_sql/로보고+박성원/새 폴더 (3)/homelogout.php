<?
	$name = $_SESSION[$session_name];

	session_destroy();
	echo "
	<script>
		alert('$name 님 안녕히가세요');
		location.href='$PHP_SELF';
	</script>
	";
?>