<!DOCTYPE html>
<html lang="ko">
    <div>
        </style>
        <div class="col">
            <div class="row">
                <div class="col-12 col-md-6 card">
                    <div class="card-header">공지사항</div>
                        <div>

                            <?
                                $sql = "SELECT * FROM spk where bid=12 order by idx desc  limit 5";
                                $result = mysql_query($sql);
                                $data = mysql_fetch_array($result);
                                while($data)
                                {	
                                    ?>

                                    <div class="card-body">
                                        <div class='row rowLine'>
                                            <div class='col'><a href='<?=$PHP_SELF?>?cmd=<?=$cmd?>spk&bid=12<?=$bid?>&mode=show&idx=<?=$data[idx]?>'><?=$data[title]?></a></div>
                                        </div>
                                    </div>
                                    <?
                                    $data = mysql_fetch_array($result);
                                }
                            ?>
                        </div>
                    </div>
                    <div class="col-12 col-md-6 card">
                        <div class="card-header">수행평가</div>
                        <?
                            $sql = "SELECT * FROM eq where bid=11 order by idx desc  limit 5";
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

                                <div class="card-body">
                                    <div class='row rowLine'>
                                        <div class='col'><a href='<?=$PHP_SELF?>?cmd=<?=$cmd?>eq&bid=11<?=$bid?>&mode=show&idx=<?=$data[idx]?>'><?=$data[html]?></a></div>
                                        <div class='col-5 text-right ellipsis'><?=$test?></div>
                                    </div>
                                </div>
                                <?
                                $data = mysql_fetch_array($result);
                            }
                        ?>
                    </div>
                </div>
            </div>
        </div>
        <div>
            <div class="col card">
                <div class="row card-header">
                    자유게시판
                </div>
                <div>

                        <?
                            $sql = "SELECT * FROM homeboard where bid=1 order by idx desc  limit 10";
                            $result = mysql_query($sql);
                            $data = mysql_fetch_array($result);
                            while($data)
                            {	
                                list($y, $m, $d) = sscanf($data[time], "%04d-%02d-%02d ");
                                $y = $y % 100;
                                $test = "$y/$m/$d";
                                ?>

                                <div class="card-body">
                                    <div class='row rowLine'>
                                        <div class='col text-left ellipsis'><a href='<?=$PHP_SELF?>?cmd=<?=$cmd?>homebord&bid=1<?=$bid?>&mode=show&idx=<?=$data[idx]?>'><?=$data[title]?></a></div>
                                        <div class='col '><?=$data[name]?></div>
                                        <div class='col-5 text-right ellipsis'><?=$test?></div>
                                    </div>
                                </div>
                                <?
                                $data = mysql_fetch_array($result);
                            }
                        ?>
                </div>
                
            </div>
        </div>
        <br>
        <br>
        <br>
        <br>

    </div>
</html>