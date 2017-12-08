// https://stackoverflow.com/questions/11541795/channel-and-bit-values-of-a-yuv2-data
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
// 1.1 By reference
cv::Mat img(IMAGE_HEIGHT, IMAGE_WIDTH, CV_8UC2, (char*) ptr);

// 1.2 By value
Mat img(height, width, CV_8UC2);
uchar *pix = img.ptr<uchar>(r); // first byte of the row in image
for (int r = 0, b=0; r < height; r++) {
    for (int c = 0; c < width; c+=4) {
        *pix++ = image_yuv[b++]; // y
        *pix++ = image_yuv[b++]; // u
        *pix++ = image_yuv[b++]; // y
        *pix++ = image_yuv[b++]; // v
    }
}

cv::Mat img_p;
// Change to RGB
cv::cvtColor(img, img_p, cv::COLOR_YUV2BGR_YUY2);
imshow("window", img_p);

// Change to Grayscale
cv::cvtColor(img, img_p, cv::COLOR_YUV2GRAY_YUY2);
imshow("window", img_p);
