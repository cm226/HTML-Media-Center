<ul data-role="listview" data-inset="true">

<?php 
	foreach($agents as $agent){
?>
	<li><a href="../Remote/controller/<?php echo $agent[1];?>"> <?php echo $agent[0];?> </a></li>
<?php }?>
</ul>



