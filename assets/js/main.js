
$(function(){
    // settings
    var $slider      = $('.slider'); // class or id of carousel slider
    var $slider_text = $('.slider_text'); // class or id of carousel slider
    var $slide       = 'li'; // could also use 'img' if you're not using a ul
    var $transition_time = 2000; // 2 second
    var $time_between_slides = 5000; // 5 seconds
    var $slides      = $slider.find($slide);
    var $slide_texts = $slider_text.find($slide);

    //$slides.fadeOut();

    // set active classes
    $slides.first().addClass('active');
    $slides.first().fadeIn($transition_time);
    $slide_texts.first().fadeIn($transition_time);

    var i = 0;

    // auto scroll
    $interval = setInterval(
        function(){
            $slide_texts.eq(i).fadeOut($transition_time/2);
            $slides.eq(i).fadeOut($transition_time/2, function() {
                i++;
                if ($slides.length == i) i = 0; // loop to start
                $slides.eq(i).fadeIn($transition_time);
                $slide_texts.eq(i).fadeIn($transition_time);
            });
        }
        , $transition_time +  $time_between_slides
    );
});