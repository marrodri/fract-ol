void mandelbrot_algo()
{
    double x;
    double y;
    int maxiterations; //every pixel will iterate number of iterations
    double width;
    double height;


    var minval = -0.5;
    var maxval = 0.5;

    var minsSlider;
    var maxSlider;

    minSlider = createSlider(-2.5, 0, -2.5, 0.01); //zoomin, zoomout with mouse
    minSlider = createSlider(0, 2.5, 2.5, 0.01); 
//this is suppose to draw
    maxiterations = 100;
    for (x = 0; x < width; x++) //for each x pixel
    {
        for (y =0 ; y < height; y++) //for each y pixel
        {
            var a = map(x, 0, width, -2, 2); //add the sliders for 
            var b = map(y, 0, height, -2, 2);

            var ca = a;
            var cb = b;
            
            var n = 0;
            var z = 0;
            while (n < 100) //number of steps for the fullscreen
            {
                var a_sq = (a * a) - (b * b);
                var b_sq = 2 * a * b;

                a = a_sq + a;
                b = b_sq + b;

                if (abs(a + b) > 16)
                {
                    break;
                } ///abs is fabs for c
                n++;
            }

            var bright = map(n, 0, maxiterations, 0, 1);//color
            bright = map(sqrt(bright), 0, 1, 0, 255);//normalize bright

            if (n == maxinterations)
            {
                bright = 0; //whitegrey
            }
        //add pixel draw
        }
    }
}