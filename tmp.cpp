$(document).ready(function(){ 
	$.get("a.html",function(data){ //初始將a.html include div#iframe
　　　　$("#iframe").html(data);
	}); 
	$(function(){
	$('.list-side li').click(function() {
		// 找出 li 中的超链接 href(#id)
		var $this = $(this),
		_clickTab = $this.find('a').attr('target'); // 找到链接a中的targer的值
		$.get(_clickTab,function(data){
			$("#iframe").html(data); 
		});
	});
})});
