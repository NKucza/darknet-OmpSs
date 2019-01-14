#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "option_list.h"

#include "network.h"
#include "image.h"
#include "detection_layer.h"
#include "region_layer.h"
#include "cost_layer.h"
#include "utils.h"
#include "parser.h"
#include "box.h"

#include "opencv2/highgui/highgui_c.h"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/core/types_c.h"
#include "opencv2/core/version.hpp"

#include "opencv2/videoio/videoio_c.h"
#include "opencv2/imgcodecs/imgcodecs_c.h"

static network net;
static image in_s ;
static image det_s;
static CvCapture * cap;
static int cpp_video_capture = 0;

image get_image_from_stream_resize(CvCapture *cap, int w, int h, int c, IplImage** in_img, int cpp_video_capture, int dont_close);
image make_empty_image(int w, int h, int c);

IplImage* in_img;
IplImage* det_img;
IplImage* show_img;

int main(int argc, char **argv)
{
	bool run = true;

	printf("starting simple test\n");

	char *datacfg = argv[1];
	char *cfgfile = argv[2];
	char *weightfile = argv[3];

	printf("datacfg = %s\n",datacfg);
	printf("cfgfile = %s\n",cfgfile);
	printf("weightfile = %s\n",weightfile);

	list *options = read_data_cfg(datacfg);
    char *name_list = option_find_str(options, "names", "data/names.list");
    int names_size = 0;
    char **names = get_labels_custom(name_list, &names_size);

	printf("found %i classes\n", names_size);

	image **alphabet = load_alphabet();

	printf("Alphabet loaded. Start loading network\n");

	net = parse_network_cfg_custom(cfgfile, 2);    // set batch=1

	printf("loaded network. Start loading weight file\n");

    if(weightfile){
        load_weights(&net, weightfile);
    }

	fuse_conv_batchnorm(net);
    calculate_binary_weights(net);
	srand(2222222);

	printf("open camera\n");

	cpp_video_capture = 1;
    cap = get_capture_webcam(1);

	if (!cap) {
		error("Couldn't connect to webcam.\n");
	}

	while(run){
		IplImage* src;
		//in_s = get_image_from_stream_resize(cap, net.w, net.h, net.c, &in_img, cpp_video_capture, 0);
		//do {
		//	src = get_webcam_frame(cap);
		src= cvRetrieveFrame(cap,0); //cvQueryFrame(cap);
        //} while (src->width < 1 || src->height < 1 || src->nChannels < 1);

	}
	
	printf("the end\n");

}
