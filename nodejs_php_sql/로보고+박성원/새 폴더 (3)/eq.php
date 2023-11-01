<?
	echo "eq , bid = $bid<br>";


	if(!$year)
		$year = $sys_year;
	
	if(!$month)
		$month = $sys_month;
	
	// mode = 기능
	//			list, show, write, dbwrite, delete, reply...
	if(!$mode)
		$mode = "list";
		if($mode == "delete")
	{
		
		
		/*
			중요!!!
			지우기전에 원본글을 확인해서 파일이 첨부되어있으면, 
			파일을 먼저 지운후 삭제해햐한다.
			그렇지 않으면 사용하지도 않는 파일이 서버에 쌓인다.
		*/

		$sql = "select * from eq where bid='$bid' and idx='$idx' ";
		$result = mysql_query($sql);
		$org = mysql_fetch_array($result);

		$sql = "delete from eq where idx='$idx' ";
		$result = mysql_query($sql);
		if($result)
			$msg = "삭제되었습니다.";
		else
			$msg = "삭제 오류입니다.";

		echo "
		<script>
			alert('$msg');
			location.href='$PHP_SELF?cmd=$cmd&bid=$bid';
		</script>
		";

	}

	if($mode == "show")
	{
		// 내용보기 idx

		$sql = "select * from eq where bid='$bid' and idx='$idx'";
		$result = mysql_query($sql);
		$data = mysql_fetch_array($result);

		if($data)
		{

			// html은 줄바꿈을 <br>태그로 바꿔줘야한다.
			$data[html] = nl2br($data[html]);

			?>
			<div class='row rowLine'>
				<div class='col-2'>수행 날짜</div>
				<div class='col'><?=$data[year]?>-<?=$data[month]?>-<?=$data[day]?></div>
			</div>
			<div class='row rowLine'>
				<div class='col-2'>작성자</div>
				<div class='col-2'><?=$data[name]?></div>

				<div class='col-2'>읽음</div>
				<div class='col-2'><?=$data[hit]?></div>
			</div>
			<div class='row rowLine'>
				<div class='col-2'>수행평가 내용</div>
				<div class='col-2'><?=$data[html]?></div>
			</div>
			<div class='row rowLine'>
				<div class='col text-center'>
					<button type='button' class='btn btn-primary' onClick="location.href='<?=$PHP_SELF?>?cmd=<?=$cmd?>&bid=<?=$bid?>'">목록</button>
					<?

						// 글 쓴 사람이거나, 관리자 일때만 삭제할 수 있다.
						if($_SESSION[$session_id] == $data[id] or $_SESSION[$session_level]== $adminLevel)
						{

							echo "
							<script>
								function confirmDelete()
								{
									if(confirm('정말 삭제하시겠습니까?'))
									{
										location.href='$PHP_SELF?cmd=$cmd&bid=$bid&idx=$data[idx]&mode=delete';
									}
								}
							</script>

							<button type='button' class='btn btn-primary' onClick=confirmDelete()>삭제</button>
							";
						}

					?>
				</div>
			</div>

			<?
		}


	}

	if($mode == "writedb")
	{
		


		$sql = "insert into eq (bid, year, month, day, id, name, hit, html)
					values('$bid', '$year', '$month', '$day', '$_SESSION[$ssession_id]', '$_SESSION[$ssession_name]', '0', '$html')";
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
			<div class="col">
				<select name="year"  class="form-control" onChange=moveYear(this)>
					<?
						for($i=year(); $i<=year() + 1; $i++)
						{
							if($i == $year)
								$mark = "selected";
							else
								$mark = "";
							echo "<option value='$i' $mark>$i 년</option>";
						}

					?>
				</select>
			</div>
			<div class="col">
				<select name="month"  class="form-control" onChange=moveMonth(this)>
					<?
						for($i=1; $i<=12; $i++)
						{
							if($i == $month)
								$mark = "selected";
							else
								$mark = "";
							echo "<option value='$i' $mark>$i 월</option>";
						}

					?>
				</select>
			</div>
			<div class="col">
				<select name="day"  class="form-control" onChange=moveDay(this)>
					<?
						for($i=1; $i<=get_last_day(year(), $month); $i++)
						{
							if($i == $day)
								$mark = "selected";
							else
								$mark = "";
							echo "<option value='$i' $mark>$i 일</option>";
						}

					?>
				</select>
			</div>
		</div>
		<div class='row rowLine'>
			<div class='col'>
				<textarea name='html' class='form-control' rows='15' placeholder='수행평가 내용'></textarea>
			</div>
		</div>
		<div class='row rowLine'>
			<div class='col row'>
				<div class="col-3"><button type='reset' class='col btn btn-primary' onClick="location.href='<?=$PHP_SELF?>?cmd=<?=$cmd?>&bid=<?=$bid?>'">취소</button></div>	
				<div class="col-3"><button type='submit' class='col btn btn-primary'>등록</button></div>
			</div>
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
			<div class='col'>내용</div>
			<div class='col'>수행평가 날짜</div>
		</div>

		<?
			$LPP = 15;


			$sql = "SELECT * FROM eq where bid='$bid' order by idx desc ";
			$result = mysql_query($sql);
			$dataCount = mysql_num_rows($result);

			echo "dataCount = $dataCount<br>";
			// 총페이지수 계산
			$totalPage = ceil($dataCount / $LPP);
			echo "totalPage = $totalPage<br>";

			if(!$page)
				$page = 1;

			$start = ($page -1) * $LPP;
			$sql = "SELECT * FROM eq where bid='$bid' order by idx desc ";
			$result = mysql_query($sql);
			$data = mysql_fetch_array($result);
			
			while($data)
			{	
				$y=$data[year];
				$m=$data[month];
				$d=$data[day];
				$y=$y%100;
				$test = "$y/$m/$d";
				?>
				<div class='row rowLine'>
					<div class='col'><?=$data[idx]?></div>
					<div class='col'><a href='<?=$PHP_SELF?>?cmd=<?=$cmd?>&bid=<?=$bid?>&mode=show&idx=<?=$data[idx]?>'><?=$data[html]?></a></div>
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