<?
	echo "code = $code<br>";

	$sql = "SELECT * FROM $user_name WHERE id='$id' and pass=password('$pass') ";
	$result = mysql_query($sql);
	$data = mysql_fetch_array($result);

	if($data)
	{
		$_SESSION[$ssession_name] = $data["name"];
		$_SESSION[$ssession_level] = $data["level"];
		$_SESSION[$ssession_id] = $data["id"];

		$msg = $_SESSION[$ssession_name]."님 반갑습니다.";
	}
    
    else
	{ // 데이터 없음 = 로그인 실패
		$msg = "아이디와 비밀번호를 확인하세요.";
	}

	echo "
	<script>
		alert('$msg');
		location.href='$PHP_SELF';
	</script>
	";
?>