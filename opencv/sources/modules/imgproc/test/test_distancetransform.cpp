/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                        Intel License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2000, Intel Corporation, all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * The name of Intel Corporation may not be used to endorse or promote products
//     derived from this software without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is" and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are disclaimed.
// In no event shall the Intel Corporation or contributors be liable for any direct,
// indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
//
//M*/

#include "test_precomp.hpp"

using namespace cv;
using namespace std;

class CV_DisTransTest : public cvtest::ArrayTest
{
public:
    CV_DisTransTest();

protected:
    void get_test_array_types_and_sizes( int test_case_idx, vector<vector<Size> >& sizes, vector<vector<int> >& types );
    double get_success_error_level( int test_case_idx, int i, int j );
    void run_func();
    void prepare_to_validation( int );

    void get_minmax_bounds( int i, int j, int type, Scalar& low, Scalar& high );
    int prepare_test_case( int test_case_idx );

    int mask_size;
    int dist_type;
    int fill_labels;
    float mask[3];
};


CV_DisTransTest::CV_DisTransTest()
{
    test_array[INPUT].push_back(NULL);
    test_array[OUTPUT].push_back(NULL);
    test_array[OUTPUT].push_back(NULL);
    test_array[REF_OUTPUT].push_back(NULL);
    test_array[REF_OUTPUT].push_back(NULL);
    optional_mask = false;
    element_wise_relative_error = true;
}


void CV_DisTransTest::get_test_array_types_and_sizes( int test_case_idx,
                                                vector<vector<Size> >& sizes, vector<vector<int> >& types )
{
    RNG& rng = ts->get_rng();
    cvtest::ArrayTest::get_test_array_types_and_sizes( test_case_idx, sizes, types );

    types[INPUT][0] = CV_8UC1;
    types[OUTPUT][0] = types[REF_OUTPUT][0] = CV_32FC1;
    types[OUTPUT][1] = types[REF_OUTPUT][1] = CV_32SC1;

    if( cvtest::randInt(rng) & 1 )
    {
        mask_size = 3;
        dist_type = cvtest::randInt(rng) % 4;
        dist_type = dist_type == 0 ? CV_DIST_C : dist_type == 1 ? CV_DIST_L1 :
                    dist_type == 2 ? CV_DIST_L2 : CV_DIST_USER;
    }
    else
    {
        mask_size = 5;
        dist_type = cvtest::randInt(rng) % 10;
        dist_type = dist_type == 0 ? CV_DIST_C : dist_type == 1 ? CV_DIST_L1 :
                    dist_type < 6 ? CV_DIST_L2 : CV_DIST_USER;
    }

    // for now, check only the "labeled" distance transform mode
    fill_labels = 0;

    if( !fill_labels )
        sizes[OUTPUT][1] = sizes[REF_OUTPUT][1] = cvSize(0,0);

    if( dist_type == CV_DIST_USER )
    {
        mask[0] = (float)(1.1 - cvtest::randReal(rng)*0.2);
        mask[1] = (float)(1.9 - cvtest::randReal(rng)*0.8);
        mask[2] = (float)(3. - cvtest::randReal(rng));
    }
}


double CV_DisTransTest::get_success_error_level( int /*test_case_idx*/, int /*i*/, int /*j*/ )
{
    Size sz = test_mat[INPUT][0].size();
    return dist_type == CV_DIST_C || dist_type == CV_DIST_L1 ? 0 : 0.01*MAX(sz.width, sz.height);
}


void CV_DisTransTest::get_minmax_bounds( int i, int j, int type, Scalar& low, Scalar& high )
{
    cvtest::ArrayTest::get_minmax_bounds( i, j, type, low, high );
    if( i == INPUT && CV_MAT_DEPTH(type) == CV_8U )
    {
        low = Scalar::all(0);
        high = Scalar::all(10);
    }
}

int CV_DisTransTest::prepare_test_case( int test_case_idx )
{
    int code = cvtest::ArrayTest::prepare_test_case( test_case_idx );
    if( code > 0 )
    {
        // the function's response to an "all-nonzeros" image is not determined,
        // so put at least one zero point
        Mat& mat = test_mat[INPUT][0];
        RNG& rng = ts->get_rng();
        int i = cvtest::randInt(rng) % mat.rows;
        int j = cvtest::randInt(rng) % mat.cols;
        mat.at<uchar>(i,j) = 0;
    }

    return code;
}


void CV_DisTransTest::run_func()
{
    cvDistTransform( test_array[INPUT][0], test_array[OUTPUT][0], dist_type, mask_size,
                     dist_type == CV_DIST_USER ? mask : 0, test_array[OUTPUT][1] );
}


static void
cvTsDistTransform( const CvMat* _src, CvMat* _dst, int dist_type,
                   int mask_size, float* _mask, CvMat* /*_labels*/ )
{
    int i, j, k;
    int width = _src->cols, height = _src->rows;
    const float init_val = 1e6;
<<<<<<< HEAD
    float mask[3];
    CvMat* temp;
    int ofs[16];
    float delta[16];
=======
    float mask[3] = { 0 };
    CvMat* temp;
    int ofs[16] = { 0 };
    float delta[16] = { 0 };
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    int tstep, count;

    assert( mask_size == 3 || mask_size == 5 );

    if( dist_type == CV_DIST_USER )
        memcpy( mask, _mask, sizeof(mask) );
    else if( dist_type == CV_DIST_C )
    {
        mask_size = 3;
        mask[0] = mask[1] = 1.f;
    }
    else if( dist_type == CV_DIST_L1 )
    {
        mask_size = 3;
        mask[0] = 1.f;
        mask[1] = 2.f;
    }
    else if( mask_size == 3 )
    {
        mask[0] = 0.955f;
        mask[1] = 1.3693f;
    }
    else
    {
        mask[0] = 1.0f;
        mask[1] = 1.4f;
        mask[2] = 2.1969f;
    }

    temp = cvCreateMat( height + mask_size-1, width + mask_size-1, CV_32F );
    tstep = temp->step / sizeof(float);

    if( mask_size == 3 )
    {
        count = 4;
        ofs[0] = -1; delta[0] = mask[0];
        ofs[1] = -tstep-1; delta[1] = mask[1];
        ofs[2] = -tstep; delta[2] = mask[0];
        ofs[3] = -tstep+1; delta[3] = mask[1];
    }
    else
    {
        count = 8;
        ofs[0] = -1; delta[0] = mask[0];
        ofs[1] = -tstep-2; delta[1] = mask[2];
        ofs[2] = -tstep-1; delta[2] = mask[1];
        ofs[3] = -tstep; delta[3] = mask[0];
        ofs[4] = -tstep+1; delta[4] = mask[1];
        ofs[5] = -tstep+2; delta[5] = mask[2];
        ofs[6] = -tstep*2-1; delta[6] = mask[2];
        ofs[7] = -tstep*2+1; delta[7] = mask[2];
    }

    for( i = 0; i < mask_size/2; i++ )
    {
        float* t0 = (float*)(temp->data.ptr + i*temp->step);
        float* t1 = (float*)(temp->data.ptr + (temp->rows - i - 1)*temp->step);

        for( j = 0; j < width + mask_size - 1; j++ )
            t0[j] = t1[j] = init_val;
    }

    for( i = 0; i < height; i++ )
    {
        uchar* s = _src->data.ptr + i*_src->step;
        float* tmp = (float*)(temp->data.ptr + temp->step*(i + (mask_size/2))) + (mask_size/2);

        for( j = 0; j < mask_size/2; j++ )
            tmp[-j-1] = tmp[j + width] = init_val;

        for( j = 0; j < width; j++ )
        {
            if( s[j] == 0 )
                tmp[j] = 0;
            else
            {
                float min_dist = init_val;
                for( k = 0; k < count; k++ )
                {
                    float t = tmp[j+ofs[k]] + delta[k];
                    if( min_dist > t )
                        min_dist = t;
                }
                tmp[j] = min_dist;
            }
        }
    }

    for( i = height - 1; i >= 0; i-- )
    {
        float* d = (float*)(_dst->data.ptr + i*_dst->step);
        float* tmp = (float*)(temp->data.ptr + temp->step*(i + (mask_size/2))) + (mask_size/2);

        for( j = width - 1; j >= 0; j-- )
        {
            float min_dist = tmp[j];
            if( min_dist > mask[0] )
            {
                for( k = 0; k < count; k++ )
                {
                    float t = tmp[j-ofs[k]] + delta[k];
                    if( min_dist > t )
                        min_dist = t;
                }
                tmp[j] = min_dist;
            }
            d[j] = min_dist;
        }
    }

    cvReleaseMat( &temp );
}


void CV_DisTransTest::prepare_to_validation( int /*test_case_idx*/ )
{
    CvMat _input = test_mat[INPUT][0], _output = test_mat[REF_OUTPUT][0];

    cvTsDistTransform( &_input, &_output, dist_type, mask_size, mask, 0 );
}


TEST(Imgproc_DistanceTransform, accuracy) { CV_DisTransTest test; test.safe_run(); }
