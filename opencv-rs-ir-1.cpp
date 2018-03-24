// This program is handling intel realsense  R200 with infrared image.
// Note. This program surely is used on R200.

// https://github.com/IntelRealSense/librealsense/issues/210

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "librealsense/rs.hpp"

using std::cout;
using std::endl;

int main(int argc, char const* argv[])
{
    rs::context ctx;
    cout << "[ INFO ] connected " << ctx.get_device_count()
        << "realsense deveces" << endl;
    if (ctx.get_device_count() == 0) {
        cout << "[ ERROR ] No devece is connected" << endl;
        return 0;
    }

    rs::device *dev = ctx.get_device(0);
    cout << "------------------------------------------" << endl;
    cout << "[ INFO ] Devece name\t" << dev->get_name() << endl;
    cout << "[ INFO ] Serial number\t" << dev->get_serial() << endl;
    cout << "[ INFO ] Firmware version\t" << dev->get_firmware_version() << endl;
    cout << "------------------------------------------" << endl;

    // Setting for realsense device
    const int frameHeight = 480;
    const int frameWidth = 640;

    try{
        dev->enable_stream(rs::stream::infrared2, frameWidth, frameHeight, rs::format::y8, 30);
    }catch(...){
    }

    dev->start();

    // Setting for openCV
    cv::Mat infrared(frameHeight, frameWidth, CV_8UC1);

    while(cv::waitKey(30) <= 0){
        dev->wait_for_frames();
        if (!dev->is_streaming()) {
            cout << "[ ERROR ] Disable streaming  " << endl;
        }

        if (!dev->is_stream_enabled(rs::stream::infrared2)) {
            cout << "[ ERROR ] Disable infrared stream" << endl;
            return 1;
        }

        infrared.data = (unsigned char*)dev->get_frame_data(rs::stream::infrared2);
        cv::imshow("infrared", infrared);
    }

    return 0;
}
