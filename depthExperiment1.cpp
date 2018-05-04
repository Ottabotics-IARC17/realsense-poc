#include "opencv2/opencv.hpp"
#include <librealsense/rs.hpp>
#include <cstdio>

int const INPUT_WIDTH      = 320;
int const INPUT_HEIGHT     = 240;
int const FRAMERATE        = 60;


int main()
{
    cv::namedWindow( "frame", 0 );

    // Create a context object. This object owns the handles to all connected realsense devices.
    rs::context ctx;
    printf("There are %d connected RealSense devices.\n", ctx.get_device_count());
    if(ctx.get_device_count() == 0) return EXIT_FAILURE;

    // This tutorial will access only a single device, but it is trivial to extend to multiple devices
    rs::device * dev = ctx.get_device(0);
    printf("\nUsing device 0, an %s\n", dev->get_name());
    printf("    Serial number: %s\n", dev->get_serial());
    printf("    Firmware version: %s\n", dev->get_firmware_version());

    rs::context rs_context;
    rs::device &rs_camera = *rs_context.get_device(0);

    rs_camera.enable_stream(rs::stream::color, INPUT_WIDTH, INPUT_HEIGHT, rs::format::rgb8, FRAMERATE);

    // WIP
    waitKey() ; 
    return EXIT_SUCCESS;
}
