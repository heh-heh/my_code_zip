<?
	echo "homeboard , bid = $bid<br>";


	// mode = 기능
	//			list, show, write, dbwrite, delete, reply...
	if(!$mode)
		$mode = "list";


	if($mode == "delete")
	{
		
		

		$sql = "select * from homeboard where bid='$bid' and idx='$idx' ";
		$result = mysql_query($sql);
		$org = mysql_fetch_array($result);
		if($org and $org[file1])
		{
			unlink("data/homeboard/1/$org[file1]");
		}
		if($org and $org[file2])
		{
			unlink("data/homeboard/2/$org[file2]");
		}

		$sql = "delete from homeboard where idx='$idx' ";
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


		if($photo==1)
		{
			$sql = "select * from homeboard where bid='$bid' and idx='$idx'";
			$result = mysql_query($sql);
			$data = mysql_fetch_array($result);
			
			if($data)
			{
				echo "
				<div class='row rowLine'>
					<div class='col text-center'>
						<img src='data/homeboard/1/$data[file1]' class='img-fluid rounded'>
					</div>
				</div>
				";

				if($data[file2])
				{
					echo "
					<div class='row rowLine'>
						<div class='col text-center'>
							<img src='data/homeboard/2/$data[file2]' class='img-fluid rounded'>
						</div>
					</div>
					";				
				}

				$prev = "";
				$next = "";
				$findFlag = false;

				// 내가 글을 목록에서 가져오는 순서대로 목록 가져와봅니다.
				$pnSql = "SELECT * FROM homeboard where bid='$bid' order by idx desc ";
				$pnResult = mysql_query($pnSql);
				$pn = mysql_fetch_array($pnResult);
				while($pn)
				{
					if($pn[idx] == $idx)
					{
						$findFlag = true;
					}else
					{
						if($findFlag == true)
						{
							$next = $pn[idx];
							break;
						}else
						{
							$prev = $pn[idx];
						}
						
					}

					$pn = mysql_fetch_array($pnResult);
				}

				// prev가 없으면.. 맨첫번째 글
				// next가 없다.... 마지막글
				?>
			
				<div class='row rowLine'>
					<div class='col text-left'>
						<?	
							if($prev)
							{
								echo "<button type='button' class='btn btn-primary' onClick=\"location.href='$PHP_SELF?cmd=$cmd&bid=$bid&mode=$mode&photo=$photo&idx=$prev'\">이전</button>";
							}else
							{
								echo "<button type='button' class='btn btn-secondary' onClick=\"alert('첫번째 게시물입니다.')\">이전</button>";
							}
						?>
						
					</div>

					<div class='col text-right'>
						<?	
							if($next)
							{
								echo "<button type='button' class='btn btn-primary' onClick=\"location.href='$PHP_SELF?cmd=$cmd&bid=$bid&mode=$mode&photo=$photo&idx=$next'\">다음</button>";
							}else
							{
								echo "<button type='button' class='btn btn-secondary' onClick=\"alert('마지막 게시물입니다.')\">다음</button>";
							}
						?>
						
					</div>
				</div>


				<div class='row rowLine'>
					<div class='col text-center'>
						<button type='button' class='btn btn-primary' onClick="location.href='<?=$PHP_SELF?>?cmd=<?=$cmd?>&bid=<?=$bid?>&photo=<?=$photo?>'">목록</button> 

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

		}else
		{
			$sql = "select * from homeboard where bid='$bid' and idx='$idx'";
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

						<?
							if($data[file1])
							{
								?>
								<img src='./data/homeboard/1/<?=$data[file1]?>' class='img-fluid rounded'><br>
								<?
							}
							if($data[file2])
							{
								?>
								<img src='./data/homeboard/2/<?=$data[file2]?>' class='img-fluid rounded'><br>
								<?
							}
						?>



					</div>
				</div>

				<?
					if($data[file1] or $data[file2])
					{
						echo "
						<div class='row rowLine'>
							<div class='col-2'>첨부파일</div>
							<div class='col'>";
					
							if($data[file1])
							{
								echo "<a href='./download.php?idx=$data[idx]&pos=1'>$data[fname1]</a>";
							}
							if($data[file2])
							{
								echo "&nbsp; &nbsp; <a href='./download.php?idx=$data[idx]&pos=2'>$data[fname2]</a>";
							}

							echo "
							</div>
						</div>
						";
					}

				$prev = "";
				$next = "";
				$findFlag = false;

				// 내가 글을 목록에서 가져오는 순서대로 목록 가져와봅니다.
				$pnSql = "SELECT * FROM homeboard where bid='$bid' order by idx desc ";
				$pnResult = mysql_query($pnSql);
				$pn = mysql_fetch_array($pnResult);
				while($pn)
				{
					if($pn[idx] == $idx)
					{
						$findFlag = true;
					}else
					{
						if($findFlag == true)
						{
							$next = $pn[idx];
							break;
						}else
						{
							$prev = $pn[idx];
						}
						
					}

					$pn = mysql_fetch_array($pnResult);
				}

				// prev가 없으면.. 맨첫번째 글
				// next가 없다.... 마지막글
				?>
			
				<div class='row rowLine'>
					<div class='col text-left'>
						<?	
							if($prev)
							{
								echo "<button type='button' class='btn btn-primary' onClick=\"location.href='$PHP_SELF?cmd=$cmd&bid=$bid&mode=$mode&photo=$photo&idx=$prev'\">이전</button>";
							}else
							{
								echo "<button type='button' class='btn btn-secondary' onClick=\"alert('첫번째 게시물입니다.')\">이전</button>";
							}
						?>
						
					</div>

					<div class='col text-right'>
						<?	
							if($next)
							{
								echo "<button type='button' class='btn btn-primary' onClick=\"location.href='$PHP_SELF?cmd=$cmd&bid=$bid&mode=$mode&photo=$photo&idx=$next'\">다음</button>";
							}else
							{
								echo "<button type='button' class='btn btn-secondary' onClick=\"alert('마지막 게시물입니다.')\">다음</button>";
							}
						?>
						
					</div>
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

		} // 일반게시판일 때 화면 보여주기
	}

	if($mode == "writedb")
	{
		if($upfile1)
		{
			// file name : $upfile1_name
			$fname1 = $upfile1_name;
			// copy ... data/board
			// 현재는 한글이름을 사용하지 말고, 영문파일이름만 테스트
			// 로봇고.jpg
			// 20211125123456.jpg , 로봇고.jpg

			$ext = getFileExt($upfile1_name);
			$file1 = getnow();

			copy($upfile1, "./data/homeboard/1/$file1");
			chmod("data/homeboard/1/$file1", 0777);
		}else
		{
			$file1 = "";
			$fname1 = "";
		}
		if($upfile2)
		{
			// file name : $upfile1_name
			$fname2 = $upfile2_name;
			// copy ... data/board
			// 현재는 한글이름을 사용하지 말고, 영문파일이름만 테스트
			// 로봇고.jpg
			// 20211125123456.jpg , 로봇고.jpg

			$ext = getFileExt($upfile2_name);
			$file2 = getnow();

			copy($upfile2, "./data/homeboard/2/$file2");
			chmod("data/homeboard/2/$file2", 0777);
		}else
		{
			$file2 = "";
			$fname2 = "";
		}

		$sql = "insert into homeboard (bid, title, id, name, time, hit, html, file1, fname1, file2, fname2)
					values('$bid', '$title', '$_SESSION[$session_id]', '$_SESSION[$session_name]', now(), '0', '$html', '$file1', '$fname1', '$file2', '$fname2')";
		$result = mysql_query($sql);
		if($result)
			$msg = "새글이 등록되었습니다.";
		else
			$msg = "새글 등록 에러입니다.";

		echo "
		<script>
			alert('$msg');
			location.href='$PHP_SELF?cmd=$cmd&bid=$bid&photo=$photo';
		</script>
		";
	}

	if($mode == "write")
	{
		
		// 제목, 내용, 첨부, 등록
		?>
		<form method='post'  enctype="multipart/form-data"  action='<?=$PHP_SELF?>?cmd=<?=$cmd?>&bid=<?=$bid?>&mode=writedb&photo=<?=$photo?>'>
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
			<div class='col-2'>첨부1</div>
			<div class='col'><input type='file' name='upfile1' class='form-control'></div>
		</div>

		<div class='row rowLine'>
			<div class='col-2'>첨부2</div>
			<div class='col'><input type='file' name='upfile2' class='form-control'></div>
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
		if($photo==1)
		{
			echo "사진갤러리..";
			// 1  2  3
			// 4  5  6
			// 7

			$DPL = 5; // Data per Line

			$sql = "SELECT * FROM homeboard where bid='$bid' order by idx desc ";
			$result = mysql_query($sql);
			$data = mysql_fetch_array($result);
			$cnt = 0;
			$openCnt = 0;
			$closeCnt = 0;
			while($data)
			{	
				$cnt ++;

				if($cnt % $DPL == 1)
				{
					$openCnt ++;
					echo "<div class='row rowLine'>";
				}

				?>
				<div class='col'>
					<a href='<?=$PHP_SELF?>?cmd=<?=$cmd?>&bid=<?=$bid?>&mode=show&idx=<?=$data[idx]?>&photo=<?=$photo?>'><img src='./data/homeboard/1/<?=$data[file1]?>' class='img-fluid rounded'></a>
				</div>

				<?

				if($cnt % $DPL == 0)
				{
					$closeCnt ++;
					echo "</div>";
				}
				
				$data = mysql_fetch_array($result);
			}


			for($i=$cnt +1 ;  $i<100; $i++)
			{
				echo "<div class='col'></div>";
				if($i % $DPL == 0)
					break;
			}

			if($closeCnt != $openCnt)
			{
				echo "
				</div>";
			}

		}else
		{
		?>
		<div class='row rowLine'>
			<div class='col'>순서</div>
			<div class='col'>제목</div>
			<div class='col'>작성자</div>
			<div class='col'>생성날짜</div>
			<div class='col'>첨부</div>
		</div>

		<?
			$LPP = 15;


			$sql = "SELECT * FROM homeboard where bid='$bid' order by idx desc ";
			$result = mysql_query($sql);
			$dataCount = mysql_num_rows($result);

			echo "dataCount = $dataCount<br>";
			// 총페이지수 계산
			$totalPage = ceil($dataCount / $LPP);
			echo "totalPage = $totalPage<br>";

			if(!$page)
				$page = 1;

			$start = ($page -1) * $LPP;

			

			$sql = "SELECT * FROM homeboard where bid='$bid' order by idx desc limit $start, $LPP";
			$result = mysql_query($sql);
			$data = mysql_fetch_array($result);
			while($data)
			{	
				list($y, $m, $d) = sscanf($data[time], "%04d-%02d-%02d ");
				$y = $y % 100;
				$test = "$y/$m/$d";
				?>
				<div class='row rowLine'>
					<div class='col'><?=$data[idx]?></div>
					<div class='col'><a href='<?=$PHP_SELF?>?cmd=<?=$cmd?>&bid=<?=$bid?>&mode=show&idx=<?=$data[idx]?>'><?=$data[title]?></a></div>
					<div class='col'><?=$data[name]?></div>
					<div class='col'><?=$printTime?> <?=$test?></div>
					<div class='col'>-</div>
				</div>
				<?
				$data = mysql_fetch_array($result);
			}

		}
		?>

		<div  class="row rowLine">
			<div class='col'><button type='button' class='btn btn-primary' onClick="location.href='<?=$PHP_SELF?>?cmd=<?=$cmd?>&bid=<?=$bid?>&mode=write&photo=<?=$photo?>'">글쓰기</button></div>
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