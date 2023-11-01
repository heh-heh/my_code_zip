<?
	include "inc/homedb.inc.php";

	$query = "select * from homeboard where idx='$idx' ";
	$result = mysql_query($query);
	$data = mysql_fetch_array($result);

	if($pos ==1)
	{
		$file_real = $data[file1];
		$fname = $data[fname1];
	}else if($pos ==2)
	{
		$file_real = $data[file2];
		$fname = $data[fname2];
	}

	$file = "./data/homeboard/$pos/$file_real";

	$file_size = filesize($file);
	$file_dest = urlencode("$fname");
	$file_dest = urldecode("$fname");
	
	header("content-type:application/octet-stream");
	@header("content-length:".$file_size);
	header('content-disposition:attachment;filename='.$file_dest);
	header('content-description:PHP Generated Data');
	header('Pragma:no-cache');
	header('Expires:0');

	if(is_file("$file"))
	{
		$fp = fopen("$file", "r");
		if(!fpassthru($fp))
			fclose($fp);
	}
	
	mysql_close($conn);
?>