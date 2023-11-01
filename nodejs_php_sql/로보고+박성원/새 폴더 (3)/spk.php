<?
	echo "spk , bid = $bid<br>";


	// mode = 기능
	//			list, show, write, dbwrite, delete, reply...
	if(!$mode)
		$mode = "list";

	if($mode == "show")
	{
		// 내용보기 idx

		$sql = "select * from spk where bid='$bid' and idx='$idx'";
		$result = mysql_query($sql);
		$data = mysql_fetch_array($result);

		if($data)
		{

			// html은 줄바꿈을 <br>태그로 바꿔줘야한다.
			$data[html] = nl2br($data[html]);

			?>
			<div class='row rowLine'>
				<div class='col-2'>제목</div>
				<div class='col'><?=$data[title]?></div>
			</div>
			<div class='row rowLine'>
				<div class='col-2'>작성자</div>
				<div class='col-2'><?=$data[name]?></div>
				<div class='col-2'>작성일</div>
				<div class='col-2'><?=$data[time]?></div>
				<div class='col-2'>읽음</div>
				<div class='col-2'><?=$data[hit]?></div>
			</div>

			<div class='row rowLine'>
				<div class='col' style='min-height:300px;'>
					<?=$data[html]?> <br>


				</div>
			</div>
			<div class='row rowLine'>
				<div class='col text-center'>
					<button type='button' class='btn btn-primary' onClick="location.href='<?=$PHP_SELF?>?cmd=<?=$cmd?>&bid=<?=$bid?>'">목록</button>
				</div>
			</div>

			<?
		}


	}

	if($mode == "writedb")
	{

		$sql = "insert into spk (bid, title, id, name, time, hit, html)
					values('$bid', '$title', '$_SESSION[$ssession_id]', '$_SESSION[$ssession_name]', now(), '0', '$html')";
		$result = mysql_query($sql);
		if($result)
			$msg = "새글이 등록되었습니다.";
		else
			$msg = "새글 등록 에러입니다.";

		echo "
		<script>
			alert('$msg');
			location.href='$PHP_SELF?cmd=$cmd&bid=$bid';
		</script>
		";
	}

	if($mode == "write")
	{
		
		// 제목, 내용, 첨부, 등록
		?>
		<form method='post'  enctype="multipart/form-data"  action='<?=$PHP_SELF?>?cmd=<?=$cmd?>&bid=<?=$bid?>&mode=writedb'>
		<div class='row rowLine'>
			<div class='col-2'>제목</div>
			<div class='col'><input type='text' name='title' placeholder='제목입력하세요' class='form-control'></div>
		</div>
		<div class='row rowLine'>
			<div class='col-2'>내용</div>
			<div class='col'>
				<textarea name='html' class='form-control' rows='15' placeholder='내용을 입력하세요'></textarea>
			</div>
		</div>
		<div class='row rowLine'>
			<div class='col'>
				<button type='reset' class='btn btn-primary' onClick="location.href='<?=$PHP_SELF?>?cmd=<?=$cmd?>&bid=<?=$bid?>'">취소</button>	
				<button type='submit' class='btn btn-primary'>등록</button></div>
		</div>
		</form>
		<?
	}

	if($mode == "list")
	{
		// 순서, 제목, 작성자, 날짜, 첨부......
		?>
		<div class='row rowLine'>
			<div class='col'>순서</div>
			<div class='col'>제목</div>
			<div class='col'>작성자</div>
			<div class='col'>등록날짜</div>
		</div>

		<?
			$LPP = 15;


			$sql = "SELECT * FROM spk where bid='$bid' order by idx desc ";
			$result = mysql_query($sql);
			$dataCount = mysql_num_rows($result);

			echo "dataCount = $dataCount<br>";
			// 총페이지수 계산
			$totalPage = ceil($dataCount / $LPP);
			echo "totalPage = $totalPage<br>";

			if(!$page)
				$page = 1;

			$start = ($page -1) * $LPP;
			$sql = "SELECT * FROM spk where bid='$bid' order by idx desc ";
			$result = mysql_query($sql);
			$data = mysql_fetch_array($result);

			$sql = "SELECT * FROM spk where bid='$bid' order by idx";
			$result = mysql_query($sql);
			$data = mysql_fetch_array($result);
			while($data)
			{	

				// 2021-12-26 12:34:56

				$splitTime = explode(" ", $data[time]);
				if($splitTime[0] == $today)
					$printTime = substr($data[time], 11, 5);
				else
					$printTime = $splitTime[0];

				// 참고 코드... 21.12.26  21/12/26
				list($y, $m, $d) = sscanf($data[time], "%04d-%02d-%02d ");
				$y = $y % 100;
				$test = "$y/$m/$d";


				?>

				
				<div class='row rowLine'>
					<div class='col'><?=$data[idx]?></div>
					<div class='col'><a href='<?=$PHP_SELF?>?cmd=<?=$cmd?>&bid=<?=$bid?>&mode=show&idx=<?=$data[idx]?>'><?=$data[title]?></a></div>
					<div class='col-3'><?=$data[name]?></div>
					<div class='col'><?=$test?></div>
				</div>
				<?
				$data = mysql_fetch_array($result);
			}
		?>



		<div  class="row rowLine">
			<div class='col'><button type='button' class='btn btn-primary' onClick="location.href='<?=$PHP_SELF?>?cmd=<?=$cmd?>&bid=<?=$bid?>&mode=write'">글쓰기</button></div>
			<div class='col'>검색화면</div>
		</div>
		<div class="row rowLine">
			<div class="col text-center">
				<?
					for($i=1; $i<=$totalPage; $i++)
					{
						if($i == $page)
							$color = "primary";
						else
							$color = "secondary";
						echo "<a href='$PHP_SELF?cmd=$cmd&bid=$bid&photo=$photo&page=$i'><span class='badge badge-$color rounded-circle'>$i</span></a> ";
					}
				?>
			</div>
		</div>
		<?
	}


?>