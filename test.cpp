#include <hls_video.h>
#include <hls_stream.h>
#include <ap_int.h>


typedef hls::stream<ap_axiu<24,1,1,1> >		AXI_STREAM;

ap_uint<24> set_rgb_8_pixel_value(hls::rgb_8 pixel)
{

	ap_uint<24> pixel_out;

	pixel_out = (pixel.R << 16) + (pixel.B << 8) + pixel.G;
	return pixel_out;
}
#define HEIGHT 	1024
#define WIDTH  	1280

//Top Level Function
void video_pattern_generator(AXI_STREAM& m_axis_video,ap_int<1>&out_test)
{
	#pragma HLS INTERFACE s_axilite port=return bundle=CTRL
	#pragma HLS INTERFACE axis register both port=m_axis_video
    #pragma HLS INTERFACE ap_none register port=out_test

	ap_axiu<24, 1, 1, 1> video;
	hls::rgb_8 pixel;


	//Add code for output video generation here
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			#pragma HLS PIPELINE

			// Start of frame, assert tuser
			if ((i==0)&&(j==0))
				video.user=1;
			else
				video.user=0;

			//End of line, assert tlast
			if(j==WIDTH-1){
				video.last=1;
			}
			else{
				video.last=0;

			}
			if((i==HEIGHT-1)&&(j==WIDTH-1)){

	            out_test = 1;
			}
			else{

				out_test =0;
			}


			if (j < WIDTH / 3) {
				pixel.R = 255;
				pixel.G = 0;
				pixel.B = 0;

			} else if (j >= WIDTH/3 && j < WIDTH * 2 / 3){
				pixel.R = 0;
				pixel.G = 255;
				pixel.B = 0;
			} else{
				pixel.R = 0;
				pixel.G = 0;
				pixel.B = 255;
			}


			// Assign the pixel value to the data output
			video.data = set_rgb_8_pixel_value(pixel);

			// Send video to stream
			m_axis_video << video;
		}
	}
}



