// Script Written by Shubham Kumar Baranwal ------------------------

$(document).ready(function(){
	// show scroll to top button if window scroll 100px from top.
	$(window).scroll(function(){ 
		if ($(this).scrollTop() > 200) { 
			$('#scrollTopBtn').stop().fadeIn(); 
		} 
		else { 
			$('#scrollTopBtn').stop().fadeOut(); 
		} 
	});
	
	// here is the code to scroll to top when someone hit the scollBtn.
	$('#scrollTopBtn').click(function(){ 
		$("html, body").animate({ scrollTop: 0 }, 600); 
		return false; 
	});

	// scroll to full type problems table on clicking full buttton.
	$("body").on('click','.fullScrollBtn',function() {
		$('html,body').animate({
			scrollTop: $(".fullProblemTable").offset().top - 35},
		'slow');
	});

	// scroll to function type problems table on clicking function buttton.
	$("body").on('click','.functionScrollBtn',function() {
		$('html,body').animate({
			scrollTop: $(".functionProblemTable").offset().top - 35},
		'slow');
	});

	// scroll to subjective type problems table on clicking subjective buttton.
	$("body").on('click','.subjectiveScrollBtn',function() {
		$('html,body').animate({
			scrollTop: $(".subjectiveProblemTable").offset().top - 35},
		'slow');
	});

	// scroll to contest type problems table on clicking contest buttton.
	$("body").on('click','.contestsScrollBtn',function() {
		$('html,body').animate({
			scrollTop: $(".contestsProblemTable").offset().top},
		'slow');
	});

	// toggle side left company and problem tags list
	$('body').on('click','.toggleTree',function(){
		$(this).closest('.branch').find('i').toggleClass('glyphicon-plus-sign glyphicon-minus-sign');
		$(this).closest('.branch').find('.treeElements').stop().toggle(800);
	});

	if($(window).width() < 768){
		$('.branch').find('i').toggleClass('glyphicon-plus-sign glyphicon-minus-sign');
		$('.treeElements').hide();
		// change first column div with second column div and vice versa.
		var $a = $('.leftTreeDiv').clone();
//		var $b = $('.leftTreeDiv').siblings().first().clone();
//		$('.leftTreeDiv').siblings().first().remove();
		$('.leftTreeDiv').remove();
		$a.insertBefore('#col_sidebar');
		$a.insertBefore($('#sidebar').parent());
//		$b.insertBefore('.leftTreeDiv');
	}

	// $(window).resize(function(){
	//     if($(window).width() < 768){
	//     	$('.branch').find('i').toggleClass('glyphicon-plus-sign glyphicon-minus-sign');
	// 		$('.treeElements').stop().slideUp(800);
	// 	}
	// 	else{
	// 		$('.branch').find('i').toggleClass('glyphicon-plus-sign glyphicon-minus-sign');
	// 		$('.treeElements').stop().slideDown(800);	
	// 	}
	// });

	// initialize tooltip.	
	$(function () {
		if($('[data-toggle="tooltip"]').length != 0){
			$('[data-toggle="tooltip"]').tooltip();
		}
	});

	// new way to intialize tooltip for dynamic elements
	$('body').tooltip({
   		selector: '[data-toggle=tooltip]'
	});

	// trigger modal for rules in add problem and add problem function page.
	$('body').on('click','.rulesModalTriggerBtn',function(){
		$('#rulesModal').modal('show');
	});

	// when window resize swap both first and second column div content with each other.
/*	$(window).on('resize', function() {
	    if ((!$('html').hasClass('small')) && ($(window).width() < 768)) {
	        $('html').addClass('small').removeClass('large');
	        var $a = $('.leftTreeDiv').clone();
			var $b = $('.leftTreeDiv').siblings().first().clone();
			$('.leftTreeDiv').siblings().first().remove();
			$('.leftTreeDiv').remove();
			$a.insertBefore('#col_sidebar');
			$a.insertBefore($('#sidebar').parent());
			$b.insertBefore('.leftTreeDiv');
	    }
	    else if ((!$('html').hasClass('large')) && ($(window).width() > 768)) {
	        $('html').addClass('large').removeClass('small');
	        var $a = $('.leftTreeDiv').clone();
			var $b = $('.leftTreeDiv').siblings().first().clone();
			$('.leftTreeDiv').siblings().first().remove();
			$('.leftTreeDiv').remove();
			$a.insertBefore('#col_sidebar');
			$a.insertBefore($('#sidebar').parent());
			$b.insertBefore('#col_sidebar');
			$b.insertBefore($('#sidebar').parent());
	    }
	}); */

});
