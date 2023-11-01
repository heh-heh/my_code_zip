<?
	session_save_path("sess");
	session_start();
	include "inc/homeconfig.inc.php";
	include "inc/homedb.inc.php";
	include "inc/function.inc.php";
?>
<!doctype html>
<html lang="ko">
   <head>
          <meta charset="UTF-8">
          <title>반응형 홈페이지</title>
          <meta name="viewport"
				content="width=device-width, maximum-scale=3.0, user-scalable=yes">
          <link href="style2.css" rel="stylesheet" type="text/css"> 
          <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css"> 
          <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
          <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
          <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/js/bootstrap.min.js"></script>
     </head>
<body>
     <!-- container -->
     <div class="container col">
		<!-- 상단 네비 영역 -->
		<nav class="navbar navbar-expand-sm bg-dark navbar-dark " id="mainMenuNav">
		
			<button type="button" class="btn btn-dark" onClick="location.href='<?=$PHP_SELF?>'">
				<span class="material-icons">home</span>
			</button>
			<!--<a class="navbar-brand" href="/info/main.php"> HOME</a> -->
			<button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#collapsibleNavbar">
				<span class="navbar-toggler-icon"></span>
			</button>
			<div class="collapse navbar-collapse" id="collapsibleNavbar">
				<ul class="navbar-nav">

					<li class="nav-item dropdown" style='margin-left:40px;'>
						<a href="#" class="nav-link dropdown-toggle" data-toggle="dropdown" style='color:#FFFFFF;'> 공지사항 <b class="caret"></b></a>
						<div class="dropdown-menu">
							<a class='dropdown-item' href='<?=$PHP_SELF?>?cmd=spk&bid=11'>1-1</a>
							<a class='dropdown-item' href='<?=$PHP_SELF?>?cmd=spk&bid=12'>1-2</a>
							<a class='dropdown-item' href='<?=$PHP_SELF?>?cmd=spk&bid=21'>2-1</a>
							<a class='dropdown-item' href='<?=$PHP_SELF?>?cmd=spk&bid=22'>2-2</a>
							<a class='dropdown-item' href='<?=$PHP_SELF?>?cmd=spk&bid=31'>3-2</a>
							<a class='dropdown-item' href='<?=$PHP_SELF?>?cmd=spk&bid=32'>3-2</a>
						</div>
					</li>
					<li class="nav-item dropdown" style='margin-left:40px;'>
						<a href="#" class="nav-link dropdown-toggle" data-toggle="dropdown" style='color:#FFFFFF;'> 수행평가 <b class="caret"></b></a>
						<div class="dropdown-menu">
							<a class='dropdown-item' href='<?=$PHP_SELF?>?cmd=eq&bid=11'>1-1</a>
							<a class='dropdown-item' href='<?=$PHP_SELF?>?cmd=eq&bid=12'>1-2</a>
							<a class='dropdown-item' href='<?=$PHP_SELF?>?cmd=eq&bid=21'>2-1</a>
							<a class='dropdown-item' href='<?=$PHP_SELF?>?cmd=eq&bid=22'>2-2</a>
							<a class='dropdown-item' href='<?=$PHP_SELF?>?cmd=eq&bid=31'>3-1</a>
							<a class='dropdown-item' href='<?=$PHP_SELF?>?cmd=eq&bid=32'>3-2</a>
						</div>
					</li>
                    <button type="button" class="btn btn-dark">급식</button>
                    <li class="nav-item dropdown" style='margin-left:40px;'>
						<a href="#" class="nav-link dropdown-toggle col-1" data-toggle="dropdown" style='color:#FFFFFF;'> 게시판 <b class="caret"></b></a>
						<div class="dropdown-menu">
							<a class='dropdown-item' href='<?=$PHP_SELF?>?cmd=homebord&bid=1'>자유게시판</a>
							<a class='dropdown-item' href='<?=$PHP_SELF?>?cmd=homebord&bid=2&photo=1'>사진/그림 게시판</a>
						</div>
					</li>
					<form class="d-flex text-right">
						<input class="form-control me-2 float-end" type="search" placeholder="Search" aria-label="Search">
						<button class="btn btn-outline-success" type="submit">Search</button>
					</form>
				</ul>
			</div>  
		</nav>
		<?
		if($_SESSION[$session_id])
		{
			?>
			<div class="row rowLine">
				<div class="col text-right">
					<button type="button" class="btn btn-primary" onClick="location.href='<?=$PHP_SELF?>?cmd=homelogout'">
						<span class="material-icons">logout</span> <?=$_SESSION[$ssession_name]?> 로그아웃
					</button>
				</div>
			</div>
			<?
		}else
		{
			?>
				
				<form name="loginForm" method="POST" action="<?=$PHP_SELF?>?cmd=login">
				<div class="row rowLine">
					<div class="col-4"></div>
					<div class="col-3">
						<input type="text" name="id" class="form-control" placeholder="ID" required>
					</div>
					<div class="col-3">
						<input type="password" name="pass" class="form-control" placeholder="PW" required>
					</div>
					<div class="col-2">
						<button type="submit" class="btn btn-primary form-control">
							<span class="material-icons">login</span> 로그인
						</button>
					</div>
				</div>
				</form>
				
			<?
		}
		?>
		<!-- display 영역 -->
		
        <?
			if($cmd)
				include("$cmd.php");
			else
				include("homeinit.php");
			
		?>
		<!-- site info 영역 -->
<?
	mysql_close($conn);
?>	
     </div>
     <!-- container -->
<body>
</html>
