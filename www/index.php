<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<title>Deitel & Deitel - "C How To Program" - solutions to exercises</title>
<meta name="author" content="Luca Braglia">
<meta name="keywords" content="deitel, & , c, how, to, program,
 exercise, answer, solution, exercises, solutions, answers">
<meta name="description" content="Deitel & Deitel - "C How To
Program" - solutions to exercises">
<meta http-equiv="content-type" content="text/html; charset=UTF-8">
<meta http-equiv="content-style-type" content="text/css">
<link rel="stylesheet" type="text/css" href="dlf/styles.css" />
</head>
<body>
<div align="center"><h1>Deitel & Deitel - "C How To Program"
- solutions to exercises</h1></div>

<h4>Intro</h4>
Here you can find my solutions.
<b>The following code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY (correctness, safety, etc). </b>
Anyway I compiled and ran it before putting on the web, and it
worked as expected. <br> 

Consider that exercises enumeration is based on italian
translation of the book (english 5th edition); likely (I
hope) it will be the same for others. Further it's all work in
progress (hey, I'm learning C, too ). <br>

The author will <b>not</b> reply to mail asking for help (and
believe me when I'm saying that this's for your good :) ); use
forums or USENET instead.  And <b>don't ask for exercises other
than those presented</b>. I've putted all of my solutions on the
web. <br>
Anyway, thank you & good C programming!

<h4>Please, contribute</h4> 

If you wrote an exercise(s) solution(s) that I haven't done, feel
free to send it (them) to me ;) ...  have a look at the end of
this page for some instructions. Please, contact me also if
you've found any bug in the sources on the web. Finally, I'm not
an english mothertongue, so, if I've made big mistakes, please
let me know!<br>

A <b>list of contributors</b> is maintained (more easily) <a href="https://raw.github.com/lbraglia/chtp/master/CONTRIBUTORS">here</a>.


<h4>How to download all of the exercises</h4> 

If you'd like to download all the exercises (and you use <a
href="http://www.mozilla.com/en-US/firefox/">Firefox</a>),
try <a href="http://www.downthemall.net/">DownThemAll</a>
plugin. Otherwise check the "main" directory
in <a href="https://github.com/lbraglia/chtp/archive/master.zip">this
  zip file</a>.

<h4>Syntax highlighting?</h4> 
Yes... look
<a href="https://github.com/lbraglia/chtp/tree/master/src"> here</a>
(equivalent contents).
<br>
<br>
</body>
</html>


<?
/*
Start Directory - To list the files contained within the current 
directory enter '.', otherwise enter the path to the directory 
you wish to list. The path must be relative to the current 
directory.
*/
$startdir = '.';

/*
Show Thumbnails? - Set to true if you wish to use the 
scripts auto-thumbnail generation capabilities.
This requires that GD2 is installed.
*/
$showthumbnails = false; 

/*
Show Directories - Do you want to make subdirectories available?
If not set this to false
*/
$showdirs = true;

/* 
Force downloads - Do you want to force people to download the files
rather than viewing them in their browser?
*/
$forcedownloads = false;

/*
Hide Files - If you wish to hide certain files or directories 
then enter their details here. The values entered are matched
against the file/directory names. If any part of the name 
matches what is entered below then it is now shown.
*/
$hide = array(
				'dlf',
				'index.php',
				'Thumbs',
				'.htaccess',
				'.htpasswd'
			);
			 
/* 
Show index files - if an index file is found in a directory
to you want to display that rather than the listing output 
from this script?
*/			
$displayindex = false;

/*
Allow uploads? - If enabled users will be able to upload 
files to any viewable directory. You should really only enable
this if the area this script is in is already password protected.
*/
$allowuploads = false;

/*
Overwrite files - If a user uploads a file with the same
name as an existing file do you want the existing file
to be overwritten?
*/
$overwrite = false;

/*
Index files - The follow array contains all the index files
that will be used if $displayindex (above) is set to true.
Feel free to add, delete or alter these
*/

$indexfiles = array (
				'index.html',
				'index.htm',
				'default.htm',
				'default.html'
			);
			
/*
File Icons - If you want to add your own special file icons use 
this section below. Each entry relates to the extension of the 
given file, in the form <extension> => <filename>. 
These files must be located within the dlf directory.
*/
$filetypes = array (
				'png' => 'jpg.gif',
				'jpeg' => 'jpg.gif',
				'bmp' => 'jpg.gif',
				'jpg' => 'jpg.gif', 
				'gif' => 'gif.gif',
				'zip' => 'archive.png',
				'rar' => 'archive.png',
				'exe' => 'exe.gif',
				'setup' => 'setup.gif',
				'txt' => 'text.png',
				'htm' => 'html.gif',
				'html' => 'html.gif',
				'fla' => 'fla.gif',
				'swf' => 'swf.gif',
				'xls' => 'xls.gif',
				'doc' => 'doc.gif',
				'sig' => 'sig.gif',
				'fh10' => 'fh10.gif',
				'pdf' => 'pdf.gif',
				'psd' => 'psd.gif',
				'rm' => 'real.gif',
				'mpg' => 'video.gif',
				'mpeg' => 'video.gif',
				'mov' => 'video2.gif',
				'avi' => 'video.gif',
				'eps' => 'eps.gif',
				'gz' => 'archive.png',
				'asc' => 'sig.gif',
			);
			
/*
That's it! You are now ready to upload this script to the server.

Only edit what is below this line if you are sure that you know what you
are doing!
*/
error_reporting(0);
if(!function_exists('imagecreatetruecolor')) $showthumbnails = false;
$leadon = $startdir;
if($leadon=='.') $leadon = '';
if((substr($leadon, -1, 1)!='/') && $leadon!='') $leadon = $leadon . '/';
$startdir = $leadon;

if($_GET['dir']) {
	//check this is okay.
	
	if(substr($_GET['dir'], -1, 1)!='/') {
		$_GET['dir'] = $_GET['dir'] . '/';
	}
	
	$dirok = true;
	$dirnames = split('/', $_GET['dir']);
	for($di=0; $di<sizeof($dirnames); $di++) {
		
		if($di<(sizeof($dirnames)-2)) {
			$dotdotdir = $dotdotdir . $dirnames[$di] . '/';
		}
		
		if($dirnames[$di] == '..') {
			$dirok = false;
		}
	}
	
	if(substr($_GET['dir'], 0, 1)=='/') {
		$dirok = false;
	}
	
	if($dirok) {
		 $leadon = $leadon . $_GET['dir'];
	}
}

if($_GET['download'] && $forcedownloads) {
	$file = str_replace('/', '', $_GET['download']);
	$file = str_replace('..', '', $file);

	if(file_exists($leadon . $file)) {
		header("Content-type: application/x-download");
		header("Content-Length: ".filesize($leadon . $file)); 
		header('Content-Disposition: attachment; filename="'.$file.'"');
		readfile($leadon . $file);
		die();
	}
}

if($allowuploads && $_FILES['file']) {
	$upload = true;
	if(!$overwrite) {
		if(file_exists($leadon.$_FILES['file']['name'])) {
			$upload = false;
		}
	}
	
	if($upload) {
		move_uploaded_file($_FILES['file']['tmp_name'], $leadon . $_FILES['file']['name']);
	}
}

$opendir = $leadon;
if(!$leadon) $opendir = '.';
if(!file_exists($opendir)) {
	$opendir = '.';
	$leadon = $startdir;
}

clearstatcache();
if ($handle = opendir($opendir)) {
	while (false !== ($file = readdir($handle))) { 
		//first see if this file is required in the listing
		if ($file == "." || $file == "..")  continue;
		$discard = false;
		for($hi=0;$hi<sizeof($hide);$hi++) {
			if(strpos($file, $hide[$hi])!==false) {
				$discard = true;
			}
		}
		
		if($discard) continue;
		if (@filetype($leadon.$file) == "dir") {
			if(!$showdirs) continue;
		
			$n++;
			if($_GET['sort']=="date") {
				$key = @filemtime($leadon.$file) . ".$n";
			}
			else {
				$key = $n;
			}
			$dirs[$key] = $file . "/";
		}
		else {
			$n++;
			if($_GET['sort']=="date") {
				$key = @filemtime($leadon.$file) . ".$n";
			}
			elseif($_GET['sort']=="size") {
				$key = @filesize($leadon.$file) . ".$n";
			}
			else {
				$key = $n;
			}
			$files[$key] = $file;
			
			if($displayindex) {
				if(in_array(strtolower($file), $indexfiles)) {
					header("Location: $file");
					die();
				}
			}
		}
	}
	closedir($handle); 
}

//sort our files
if($_GET['sort']=="date") {
	@ksort($dirs, SORT_NUMERIC);
	@ksort($files, SORT_NUMERIC);
}
elseif($_GET['sort']=="size") {
	@natcasesort($dirs); 
	@ksort($files, SORT_NUMERIC);
}
else {
	@natcasesort($dirs); 
	@natcasesort($files);
}

//order correctly
if($_GET['order']=="desc" && $_GET['sort']!="size") {$dirs = @array_reverse($dirs);}
if($_GET['order']=="desc") {$files = @array_reverse($files);}
$dirs = @array_values($dirs); $files = @array_values($files);


?>

<?
if($showthumbnails) {
?>
<script language="javascript" type="text/javascript">
</script>
<?
}
?>
</head>
<body>
<div id="container">
  <h1>Exercises</h1>
  <div id="breadcrumbs">  
  <?
 	 $breadcrumbs = split('/', $leadon);
  	if(($bsize = sizeof($breadcrumbs))>0) {
  		$sofar = '';
  		for($bi=0;$bi<($bsize-1);$bi++) {
			$sofar = $sofar . $breadcrumbs[$bi] . '/';
			echo ' &gt; <a href="'.$_SERVER['PHP_SELF'].'?dir='.urlencode($sofar).'">'.$breadcrumbs[$bi].'</a>';
		}
  	}
  
	$baseurl = $_SERVER['PHP_SELF'] . '?dir='.$_GET['dir'] . '&amp;';
	$fileurl = 'sort=name&amp;order=asc';
	$sizeurl = 'sort=size&amp;order=asc';
	$dateurl = 'sort=date&amp;order=asc';
	
	switch ($_GET['sort']) {
		case 'name':
			if($_GET['order']=='asc') $fileurl = 'sort=name&amp;order=desc';
			break;
		case 'size':
			if($_GET['order']=='asc') $sizeurl = 'sort=size&amp;order=desc';
			break;
			
		case 'date':
			if($_GET['order']=='asc') $dateurl = 'sort=date&amp;order=desc';
			break;  
		default:
			$fileurl = 'sort=name&amp;order=desc';
			break;
	}
  ?>
  </div>
  <div id="listingcontainer">
    <div id="listingheader"> 
	<div id="headerfile"><a href="<?=$baseurl . $fileurl;?>">File</a></div>
	<div id="headersize"><a href="<?=$baseurl . $sizeurl;?>">Size</a></div>
	<div id="headermodified"><a href="<?=$baseurl . $dateurl;?>">Last Modified</a></div>
	</div>
    <div id="listing">
	<?
	$class = 'b';
	if($dirok) {
	?>
	<div><a href="<?=$_SERVER['PHP_SELF'].'?dir='.urlencode($dotdotdir);?>" class="<?=$class;?>"><img src="dlf/dirup.png" alt="Folder" /><strong>..</strong> <em>-</em> <?=date ("M d Y h:i:s A", filemtime($dotdotdir));?></a></div>
	<?
		if($class=='b') $class='w';
		else $class = 'b';
	}
	$arsize = sizeof($dirs);
	for($i=0;$i<$arsize;$i++) {
	?>
	<div><a href="<?=$_SERVER['PHP_SELF'].'?dir='.urlencode($leadon.$dirs[$i]);?>" class="<?=$class;?>"><img src="dlf/folder.png" alt="<?=$dirs[$i];?>" /><strong><?=$dirs[$i];?></strong> <em>-</em> <?=date ("M d Y h:i:s A", filemtime($leadon.$dirs[$i]));?></a></div>
	<?
		if($class=='b') $class='w';
		else $class = 'b';	
	}
	
	$arsize = sizeof($files);
	for($i=0;$i<$arsize;$i++) {
		$icon = 'unknown.png';
		$ext = strtolower(substr($files[$i], strrpos($files[$i], '.')+1));
		$supportedimages = array('gif', 'png', 'jpeg', 'jpg');
		$thumb = '';
		
		if($showthumbnails && in_array($ext, $supportedimages)) {
			$thumb = '<span><img src="dlf/trans.gif" alt="'.$files[$i].'" name="thumb'.$i.'" /></span>';
			$thumb2 = ' onmouseover="o('.$i.', \''.urlencode($leadon . $files[$i]).'\');" onmouseout="f('.$i.');"';
			
		}
		
		if($filetypes[$ext]) {
			$icon = $filetypes[$ext];
		}
		
		$filename = $files[$i];
		if(strlen($filename)>43) {
			$filename = substr($files[$i], 0, 40) . '...';
		}
		
		$fileurl = $leadon . $files[$i];
		if($forcedownloads) {
			$fileurl = $_SESSION['PHP_SELF'] . '?dir=' . urlencode($leadon) . '&download=' . urlencode($files[$i]);
		}

	?>
	<div><a href="<?=$fileurl;?>" class="<?=$class;?>"<?=$thumb2;?>><img src="dlf/<?=$icon;?>" alt="<?=$files[$i];?>" /><strong><?=$filename;?></strong> <em><?=round(filesize($leadon.$files[$i])/1024);?>KB</em> <?=date ("M d Y h:i:s A", filemtime($leadon.$files[$i]));?><?=$thumb;?></a></div>
	<?
		if($class=='b') $class='w';
		else $class = 'b';	
	}	
	?></div>
	<?
	if($allowuploads) {
		$phpallowuploads = (bool) ini_get('file_uploads');		
		$phpmaxsize = ini_get('upload_max_filesize');
		$phpmaxsize = trim($phpmaxsize);
		$last = strtolower($phpmaxsize{strlen($phpmaxsize)-1});
		switch($last) {
			case 'g':
				$phpmaxsize *= 1024;
			case 'm':
				$phpmaxsize *= 1024;
		}
	
	?>
	<div id="upload">
		<div id="uploadtitle"><strong>File Upload</strong> (Max Filesize: <?=$phpmaxsize;?>KB)</div>
		<div id="uploadcontent">
			<?
			if($phpallowuploads) {
			?>
			<form method="post" action="<?=$_SERVER['PHP_SELF'];?>?dir=<?=urlencode($leadon);?>" enctype="multipart/form-data">
			<input type="file" name="file" /> <input type="submit" value="Upload" />
			</form>
			<?
			}
			else {
			?>
			File uploads are disabled in your php.ini file. Please enable them.
			<?
			}
			?>
		</div>
		
	</div>
	<?
	}
	?>
  </div>
</div>
</body>
</html>


<h4>Notes for contributors</h4>
First of all, you can find my e-mail <a
href="../contact.php">here</a> ; then 
<ul>
<li> write your code (variable names, comments, strings
  etc) <b>in english</b>;
<li> put "chtp" and/or "deitel" somewhere in order to make the
  mail quickly searchable (code update performed once a year),
  otherwhise it will be "lost";
<li> please, test your code before sending it: it must work as
  expected by exercise question;
<li> don't, I repeat, <b>don't copy and paste from copyrighted
  material</b> available online;
<li> every solution must be based only on chapter stuff or
  concepts from previous chapters: not on stuff to be explained
  yet;
<li> please send me files like xx_yy.c (where xx == chapter, yy
  == exercise_number);
<li> tell me if you <b>don't</b> want to be mentioned in the
  contributors list;
<li> I will not specify "who made what" (extra work for me :(
  ). If you want the code paternity to be knowable, put a comment
  like /*Solution provided by foo*/ or something similar;
<li> The solutions will checked be with
<pre> gcc -W -Wall -ansi -pedantic xx_yy.c </pre>
<li> and if badly (badly) indented, cleaned up with Emacs.
</ul>
<br>
Thank you again, Luca
<br>
<br>




