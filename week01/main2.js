var isplaying = false;
function play(){
	var player = document.getElementById('M-bang');
	if(isplaying){
		player.pause();
		player.src = '';
	}
	else {
		player.src='BANG BANG BANG.mp3';
		player.play();
	}
	isplaying = !isplaying;
}

var isplaying = false;
function play2(){
	var player = document.getElementById('A-sober');
	if(isplaying){
		player.pause();
		player.src = '';
	}
	else {
		player.src='SOBER.mp3';
		player.play();
	}
	isplaying = !isplaying;
}

var isplaying = false;
function play3(){
	var player = document.getElementById('D-ifyou');
	if(isplaying){
		player.pause();
		player.src = '';
	}
	else {
		player.src='IF YOU.mp3';
		player.play();
	}
	isplaying = !isplaying;
}
var isplaying = false;
function play4(){
	var player = document.getElementById('E-zutter');
	if(isplaying){
		player.pause();
		player.src = '';
	}
	else {
		player.src='ZUTTER.mp3';
		player.play();
	}
	isplaying = !isplaying;
}
 