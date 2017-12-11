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
#include "precomp.hpp"
#if (defined WIN32 || defined _WIN32) && defined HAVE_MSMF
/*
   Media Foundation-based Video Capturing module is based on
   videoInput library by Evgeny Pereguda:
   http://www.codeproject.com/Articles/559437/Capturing-of-video-from-web-camera-on-Windows-7-an
   Originaly licensed under The Code Project Open License (CPOL) 1.02:
   http://www.codeproject.com/info/cpol10.aspx
*/
<<<<<<< HEAD
=======
//require Windows 8 for some of the formats defined otherwise could baseline on lower version
#if WINVER < _WIN32_WINNT_WIN7
#undef WINVER
#define WINVER _WIN32_WINNT_WIN7
#endif
#if defined _MSC_VER && _MSC_VER >= 1600
    #define HAVE_CONCURRENCY
#endif
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
#include <windows.h>
#include <guiddef.h>
#include <mfidl.h>
#include <Mfapi.h>
#include <mfplay.h>
#include <mfobjects.h>
<<<<<<< HEAD
=======
#include <tchar.h>
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
#include <strsafe.h>
#include <Mfreadwrite.h>
#include <new>
#include <map>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

<<<<<<< HEAD
=======
#ifdef _MSC_VER
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
#pragma warning(disable:4503)
#pragma comment(lib, "mfplat")
#pragma comment(lib, "mf")
#pragma comment(lib, "mfuuid")
#pragma comment(lib, "Strmiids")
#pragma comment(lib, "Mfreadwrite")
<<<<<<< HEAD
#pragma comment(lib, "MinCore_Downlevel")

// for ComPtr usage
#include <wrl/client.h>
using namespace Microsoft::WRL;

struct IMFMediaType;
struct IMFActivate;
struct IMFMediaSource;
=======
#if (WINVER >= 0x0602) // Available since Win 8
#pragma comment(lib, "MinCore_Downlevel")
#endif
#endif

#include <mferror.h>

#ifdef HAVE_WINRT
    // for ComPtr usage
#include <wrl/client.h>
#ifdef __cplusplus_winrt
#include <agile.h>
#include <vccorlib.h>
#endif

#include <wrl\async.h>
#include <wrl\implements.h>
#include <wrl\module.h>
#include <wrl\wrappers\corewrappers.h>
#include <windows.media.capture.h>
#include <windows.devices.enumeration.h>
#ifdef HAVE_CONCURRENCY
#include <concrt.h>
#ifndef __cplusplus_winrt
__declspec(noreturn) void __stdcall __abi_WinRTraiseException(long);

inline void __abi_ThrowIfFailed(long __hrArg)
{
    if (__hrArg < 0)
    {
        __abi_WinRTraiseException(__hrArg);
    }
}

struct Guid
{
public:
    Guid();
    Guid(__rcGUID_t);
    operator ::__rcGUID_t();
    bool Equals(Guid __guidArg);
    bool Equals(__rcGUID_t __guidArg);
    Guid(unsigned int __aArg, unsigned short __bArg, unsigned short __cArg, unsigned __int8 __dArg,
        unsigned __int8 __eArg, unsigned __int8 __fArg, unsigned __int8 __gArg, unsigned __int8 __hArg,
        unsigned __int8 __iArg, unsigned __int8 __jArg, unsigned __int8 __kArg);
    Guid(unsigned int __aArg, unsigned short __bArg, unsigned short __cArg, const unsigned __int8* __dArg);
private:
    unsigned long  __a;
    unsigned short __b;
    unsigned short __c;
    unsigned char __d;
    unsigned char __e;
    unsigned char __f;
    unsigned char __g;
    unsigned char __h;
    unsigned char __i;
    unsigned char __j;
    unsigned char __k;
};

static_assert(sizeof(Guid) == sizeof(::_GUID), "Incorect size for Guid");
static_assert(sizeof(__rcGUID_t) == sizeof(::_GUID), "Incorect size for __rcGUID_t");

////////////////////////////////////////////////////////////////////////////////
inline Guid::Guid() : __a(0), __b(0), __c(0), __d(0), __e(0), __f(0), __g(0), __h(0), __i(0), __j(0), __k(0)
{
}

inline Guid::Guid(__rcGUID_t __guid) :
__a(reinterpret_cast<const __s_GUID&>(__guid).Data1),
__b(reinterpret_cast<const __s_GUID&>(__guid).Data2),
__c(reinterpret_cast<const __s_GUID&>(__guid).Data3),
__d(reinterpret_cast<const __s_GUID&>(__guid).Data4[0]),
__e(reinterpret_cast<const __s_GUID&>(__guid).Data4[1]),
__f(reinterpret_cast<const __s_GUID&>(__guid).Data4[2]),
__g(reinterpret_cast<const __s_GUID&>(__guid).Data4[3]),
__h(reinterpret_cast<const __s_GUID&>(__guid).Data4[4]),
__i(reinterpret_cast<const __s_GUID&>(__guid).Data4[5]),
__j(reinterpret_cast<const __s_GUID&>(__guid).Data4[6]),
__k(reinterpret_cast<const __s_GUID&>(__guid).Data4[7])
{
}

inline Guid::operator ::__rcGUID_t()
{
    return reinterpret_cast<__rcGUID_t>(*this);
}

inline bool Guid::Equals(Guid __guidArg)
{
    return *this == __guidArg;
}

inline bool Guid::Equals(__rcGUID_t __guidArg)
{
    return *this == static_cast< Guid>(__guidArg);
}

inline bool operator==(Guid __aArg, Guid __bArg)
{
    auto __a = reinterpret_cast<unsigned long*>(&__aArg);
    auto __b = reinterpret_cast<unsigned long*>(&__bArg);

    return (__a[0] == __b[0] && __a[1] == __b[1] && __a[2] == __b[2] && __a[3] == __b[3]);
}

inline bool operator!=(Guid __aArg, Guid __bArg)
{
    return !(__aArg == __bArg);
}

inline bool operator<(Guid __aArg, Guid __bArg)
{
    auto __a = reinterpret_cast<unsigned long*>(&__aArg);
    auto __b = reinterpret_cast<unsigned long*>(&__bArg);

    if (__a[0] != __b[0])
    {
        return __a[0] < __b[0];
    }

    if (__a[1] != __b[1])
    {
        return __a[1] < __b[1];
    }

    if (__a[2] != __b[2])
    {
        return __a[2] < __b[2];
    }

    if (__a[3] != __b[3])
    {
        return __a[3] < __b[3];
    }

    return false;
}

inline Guid::Guid(unsigned int __aArg, unsigned short __bArg, unsigned short __cArg, unsigned __int8 __dArg,
    unsigned __int8 __eArg, unsigned __int8 __fArg, unsigned __int8 __gArg, unsigned __int8 __hArg,
    unsigned __int8 __iArg, unsigned __int8 __jArg, unsigned __int8 __kArg) :
    __a(__aArg), __b(__bArg), __c(__cArg), __d(__dArg), __e(__eArg), __f(__fArg), __g(__gArg), __h(__hArg), __i(__iArg), __j(__jArg), __k(__kArg)
{
}

inline Guid::Guid(unsigned int __aArg, unsigned short __bArg, unsigned short __cArg, const unsigned __int8 __dArg[8]) :
__a(__aArg), __b(__bArg), __c(__cArg)
{
    __d = __dArg[0];
    __e = __dArg[1];
    __f = __dArg[2];
    __g = __dArg[3];
    __h = __dArg[4];
    __i = __dArg[5];
    __j = __dArg[6];
    __k = __dArg[7];
}

__declspec(selectany) Guid __winrt_GUID_NULL(0x00000000, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);

//
//// Don't want to define the real IUnknown from unknown.h here. That would means if the user has
//// any broken code that uses it, compile errors will take the form of e.g.:
////     predefined C++ WinRT types (compiler internal)(41) : see declaration of 'IUnknown::QueryInterface'
//// This is not helpful. If they use IUnknown, we still need to point them to the actual unknown.h so
//// that they can see the original definition.
////
//// For WinRT, we'll instead have a parallel COM interface hierarchy for basic interfaces starting with _.
//// The type mismatch is not an issue. COM passes types through GUID / void* combos - the original type
//// doesn't come into play unless the user static_casts an implementation type to one of these, but
//// the WinRT implementation types are hidden.
__interface __declspec(uuid("00000000-0000-0000-C000-000000000046")) __abi_IUnknown
{
public:
    virtual long __stdcall __abi_QueryInterface(Guid&, void**) = 0;
    virtual unsigned long __stdcall __abi_AddRef() = 0;
    virtual unsigned long __stdcall __abi_Release() = 0;
};
#endif
#include "ppltasks_winrt.h"
#endif
#else
#include <comdef.h>
#endif

struct IMFMediaType;
#ifndef HAVE_WINRT
struct IMFActivate;
struct IMFMediaSource;
#endif
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
struct IMFAttributes;

namespace
{

template <class T> void SafeRelease(T **ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = NULL;
    }
}

<<<<<<< HEAD
/// Class for printing info into consol
class DebugPrintOut
{
public:
    ~DebugPrintOut(void);
    static DebugPrintOut& getInstance();
=======
#ifdef _DEBUG
/// Class for printing info into console
class DPO
{
public:
    ~DPO(void);
    static DPO& getInstance();
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    void printOut(const wchar_t *format, ...);
    void setVerbose(bool state);
    bool verbose;
private:
<<<<<<< HEAD
    DebugPrintOut(void);
};
=======
    DPO(void);
};
#define DebugPrintOut(...) DPO::getInstance().printOut(__VA_ARGS__)
#else
#define DebugPrintOut(...) void()
#endif

#include "cap_msmf.hpp"
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d

// Structure for collecting info about types of video, which are supported by current video device
struct MediaType
{
    unsigned int MF_MT_FRAME_SIZE;
    unsigned int height;
    unsigned int width;
    unsigned int MF_MT_YUV_MATRIX;
    unsigned int MF_MT_VIDEO_LIGHTING;
    int MF_MT_DEFAULT_STRIDE; // stride is negative if image is bottom-up
    unsigned int MF_MT_VIDEO_CHROMA_SITING;
    GUID MF_MT_AM_FORMAT_TYPE;
    wchar_t *pMF_MT_AM_FORMAT_TYPEName;
    unsigned int MF_MT_FIXED_SIZE_SAMPLES;
    unsigned int MF_MT_VIDEO_NOMINAL_RANGE;
    unsigned int MF_MT_FRAME_RATE_NUMERATOR;
    unsigned int MF_MT_FRAME_RATE_DENOMINATOR;
    unsigned int MF_MT_PIXEL_ASPECT_RATIO;
    unsigned int MF_MT_PIXEL_ASPECT_RATIO_low;
    unsigned int MF_MT_ALL_SAMPLES_INDEPENDENT;
    unsigned int MF_MT_FRAME_RATE_RANGE_MIN;
    unsigned int MF_MT_FRAME_RATE_RANGE_MIN_low;
    unsigned int MF_MT_SAMPLE_SIZE;
    unsigned int MF_MT_VIDEO_PRIMARIES;
    unsigned int MF_MT_INTERLACE_MODE;
    unsigned int MF_MT_FRAME_RATE_RANGE_MAX;
    unsigned int MF_MT_FRAME_RATE_RANGE_MAX_low;
    GUID MF_MT_MAJOR_TYPE;
    GUID MF_MT_SUBTYPE;
    wchar_t *pMF_MT_MAJOR_TYPEName;
    wchar_t *pMF_MT_SUBTYPEName;
    MediaType();
    ~MediaType();
    void Clear();
};

/// Class for parsing info from IMFMediaType into the local MediaType
class FormatReader
{
public:
    static MediaType Read(IMFMediaType *pType);
    ~FormatReader(void);
private:
    FormatReader(void);
};

DWORD WINAPI MainThreadFunction( LPVOID lpParam );
typedef void(*emergensyStopEventCallback)(int, void *);

class RawImage
{
public:
    ~RawImage(void);
    // Function of creation of the instance of the class
    static long CreateInstance(RawImage **ppRImage,unsigned int size);
    void setCopy(const BYTE * pSampleBuffer);
    void fastCopy(const BYTE * pSampleBuffer);
    unsigned char * getpPixels();
    bool isNew();
    unsigned int getSize();
private:
    bool ri_new;
    unsigned int ri_size;
    unsigned char *ri_pixels;
    RawImage(unsigned int size);
};

<<<<<<< HEAD
// Class for grabbing image from video stream
class ImageGrabber : public IMFSampleGrabberSinkCallback
{
public:
    ~ImageGrabber(void);
    HRESULT initImageGrabber(IMFMediaSource *pSource, GUID VideoFormat);
    HRESULT startGrabbing(void);
    void pauseGrabbing();
    void resumeGrabbing();
    void stopGrabbing();
    RawImage *getRawImage();
    // Function of creation of the instance of the class
    static HRESULT CreateInstance(ImageGrabber **ppIG, unsigned int deviceID, bool synchronous = false);
=======
class ImageGrabberCallback : public IMFSampleGrabberSinkCallback
{
public:
    void pauseGrabbing();
    void resumeGrabbing();
    RawImage *getRawImage();
    // IMFClockStateSink methods
    STDMETHODIMP OnClockStart(MFTIME hnsSystemTime, LONGLONG llClockStartOffset);
    STDMETHODIMP OnClockStop(MFTIME hnsSystemTime);
    STDMETHODIMP OnClockPause(MFTIME hnsSystemTime);
    STDMETHODIMP OnClockRestart(MFTIME hnsSystemTime);
    STDMETHODIMP OnClockSetRate(MFTIME hnsSystemTime, float flRate);
    // IMFSampleGrabberSinkCallback methods
    STDMETHODIMP OnSetPresentationClock(IMFPresentationClock* pClock);
    STDMETHODIMP OnProcessSample(REFGUID guidMajorMediaType, DWORD dwSampleFlags,
        LONGLONG llSampleTime, LONGLONG llSampleDuration, const BYTE * pSampleBuffer,
        DWORD dwSampleSize);
    STDMETHODIMP OnShutdown();
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d

    const HANDLE ig_hFrameReady;
    const HANDLE ig_hFrameGrabbed;
    const HANDLE ig_hFinish;
<<<<<<< HEAD

private:
=======
protected:
    ImageGrabberCallback(bool synchronous);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    bool ig_RIE;
    bool ig_Close;
    bool ig_Synchronous;
    long m_cRef;
<<<<<<< HEAD
    unsigned int ig_DeviceID;
    IMFMediaSource *ig_pSource;
    IMFMediaSession *ig_pSession;
    IMFTopology *ig_pTopology;
    RawImage *ig_RIFirst;
    RawImage *ig_RISecond;
    RawImage *ig_RIOut;
=======

    RawImage *ig_RIFirst;
    RawImage *ig_RISecond;
    RawImage *ig_RIOut;
private:
    ImageGrabberCallback& operator=(const ImageGrabberCallback&);   // Declared to fix compilation warning.
 };

#ifdef HAVE_WINRT
extern const __declspec(selectany) WCHAR RuntimeClass_CV_ImageGrabberWinRT[] = L"cv.ImageGrabberWinRT";

class ImageGrabberWinRT :
    public Microsoft::WRL::RuntimeClass<
    Microsoft::WRL::RuntimeClassFlags< Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
    IMFSampleGrabberSinkCallback>, public ImageGrabberCallback
{
    InspectableClass(RuntimeClass_CV_ImageGrabberWinRT, BaseTrust)
public:
    ImageGrabberWinRT(bool synchronous);
    ~ImageGrabberWinRT(void);

    HRESULT initImageGrabber(MAKE_WRL_REF(_MediaCapture) pSource,
        GUID VideoFormat);
    HRESULT startGrabbing(MAKE_WRL_REF(_AsyncAction)* action);
    HRESULT stopGrabbing(MAKE_WRL_REF(_AsyncAction)* action);
    // IMFClockStateSink methods
    STDMETHODIMP OnClockStart(MFTIME hnsSystemTime, LONGLONG llClockStartOffset) { return ImageGrabberCallback::OnClockStart(hnsSystemTime, llClockStartOffset); }
    STDMETHODIMP OnClockStop(MFTIME hnsSystemTime) { return ImageGrabberCallback::OnClockStop(hnsSystemTime); }
    STDMETHODIMP OnClockPause(MFTIME hnsSystemTime) { return ImageGrabberCallback::OnClockPause(hnsSystemTime); }
    STDMETHODIMP OnClockRestart(MFTIME hnsSystemTime) { return ImageGrabberCallback::OnClockRestart(hnsSystemTime); }
    STDMETHODIMP OnClockSetRate(MFTIME hnsSystemTime, float flRate) { return ImageGrabberCallback::OnClockSetRate(hnsSystemTime, flRate); }
    // IMFSampleGrabberSinkCallback methods
    STDMETHODIMP OnSetPresentationClock(IMFPresentationClock* pClock) { return ImageGrabberCallback::OnSetPresentationClock(pClock); }
    STDMETHODIMP OnProcessSample(REFGUID guidMajorMediaType, DWORD dwSampleFlags,
        LONGLONG llSampleTime, LONGLONG llSampleDuration, const BYTE * pSampleBuffer,
        DWORD dwSampleSize) { return ImageGrabberCallback::OnProcessSample(guidMajorMediaType, dwSampleFlags, llSampleTime, llSampleDuration, pSampleBuffer, dwSampleSize); }
    STDMETHODIMP OnShutdown() { return ImageGrabberCallback::OnShutdown(); }
    // Function of creation of the instance of the class
    static HRESULT CreateInstance(ImageGrabberWinRT **ppIG, bool synchronous = false);
private:
    MAKE_WRL_AGILE_REF(_MediaCapture) ig_pMedCapSource;
    MediaSink* ig_pMediaSink;
};
#endif

// Class for grabbing image from video stream
class ImageGrabber : public ImageGrabberCallback
{
public:
    ~ImageGrabber(void);
    HRESULT initImageGrabber(IMFMediaSource *pSource);
    HRESULT startGrabbing(void);
    void stopGrabbing();
    // IUnknown methods
    STDMETHODIMP QueryInterface(REFIID iid, void** ppv);
    STDMETHODIMP_(ULONG) AddRef();
    STDMETHODIMP_(ULONG) Release();
    // Function of creation of the instance of the class
    static HRESULT CreateInstance(ImageGrabber **ppIG, unsigned int deviceID, bool synchronous = false);

private:
    unsigned int ig_DeviceID;

    IMFMediaSource *ig_pSource;
    IMFMediaSession *ig_pSession;
    IMFTopology *ig_pTopology;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    ImageGrabber(unsigned int deviceID, bool synchronous);
    HRESULT CreateTopology(IMFMediaSource *pSource, IMFActivate *pSinkActivate, IMFTopology **ppTopo);
    HRESULT AddSourceNode(IMFTopology *pTopology, IMFMediaSource *pSource,
        IMFPresentationDescriptor *pPD, IMFStreamDescriptor *pSD, IMFTopologyNode **ppNode);
    HRESULT AddOutputNode(IMFTopology *pTopology, IMFActivate *pActivate, DWORD dwId, IMFTopologyNode **ppNode);
<<<<<<< HEAD
    // IUnknown methods
    STDMETHODIMP QueryInterface(REFIID iid, void** ppv);
    STDMETHODIMP_(ULONG) AddRef();
    STDMETHODIMP_(ULONG) Release();
    // IMFClockStateSink methods
    STDMETHODIMP OnClockStart(MFTIME hnsSystemTime, LONGLONG llClockStartOffset);
    STDMETHODIMP OnClockStop(MFTIME hnsSystemTime);
    STDMETHODIMP OnClockPause(MFTIME hnsSystemTime);
    STDMETHODIMP OnClockRestart(MFTIME hnsSystemTime);
    STDMETHODIMP OnClockSetRate(MFTIME hnsSystemTime, float flRate);
    // IMFSampleGrabberSinkCallback methods
    STDMETHODIMP OnSetPresentationClock(IMFPresentationClock* pClock);
    STDMETHODIMP OnProcessSample(REFGUID guidMajorMediaType, DWORD dwSampleFlags,
        LONGLONG llSampleTime, LONGLONG llSampleDuration, const BYTE * pSampleBuffer,
        DWORD dwSampleSize);
    STDMETHODIMP OnShutdown();
=======

    ImageGrabber& operator=(const ImageGrabber&);   // Declared to fix comiplation error.
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
};

/// Class for controlling of thread of the grabbing raw data from video device
class ImageGrabberThread
{
    friend DWORD WINAPI MainThreadFunction( LPVOID lpParam );
public:
    ~ImageGrabberThread(void);
    static HRESULT CreateInstance(ImageGrabberThread **ppIGT, IMFMediaSource *pSource, unsigned int deviceID, bool synchronious = false);
    void start();
    void stop();
    void setEmergencyStopEvent(void *userData, void(*func)(int, void *));
    ImageGrabber *getImageGrabber();
protected:
    virtual void run();
private:
    ImageGrabberThread(IMFMediaSource *pSource, unsigned int deviceID, bool synchronious);
    HANDLE igt_Handle;
    DWORD   igt_ThreadIdArray;
    ImageGrabber *igt_pImageGrabber;
    emergensyStopEventCallback igt_func;
    void *igt_userData;
    bool igt_stop;
    unsigned int igt_DeviceID;
};

// Structure for collecting info about one parametr of current video device
struct Parametr
{
    long CurrentValue;
    long Min;
    long Max;
    long Step;
    long Default;
    long Flag;
    Parametr();
};

// Structure for collecting info about 17 parametrs of current video device
struct CamParametrs
{
        Parametr Brightness;
        Parametr Contrast;
        Parametr Hue;
        Parametr Saturation;
        Parametr Sharpness;
        Parametr Gamma;
        Parametr ColorEnable;
        Parametr WhiteBalance;
        Parametr BacklightCompensation;
        Parametr Gain;
        Parametr Pan;
        Parametr Tilt;
        Parametr Roll;
        Parametr Zoom;
        Parametr Exposure;
        Parametr Iris;
        Parametr Focus;
};

typedef std::wstring String;
typedef std::vector<int> vectorNum;
typedef std::map<String, vectorNum> SUBTYPEMap;
typedef std::map<UINT64, SUBTYPEMap> FrameRateMap;
typedef void(*emergensyStopEventCallback)(int, void *);

/// Class for controlling of video device
class videoDevice
{
public:
    videoDevice(void);
    ~videoDevice(void);
    void closeDevice();
    CamParametrs getParametrs();
    void setParametrs(CamParametrs parametrs);
    void setEmergencyStopEvent(void *userData, void(*func)(int, void *));
<<<<<<< HEAD
    long readInfoOfDevice(IMFActivate *pActivate, unsigned int Num);
=======
#ifdef HAVE_WINRT
    long readInfoOfDevice(MAKE_WRL_REF(_IDeviceInformation) pDevice, unsigned int Num);
    void waitForDevice()
    {
#ifdef HAVE_CONCURRENCY
        vd_pAction.wait();
#endif
    }
#else
    long readInfoOfDevice(IMFActivate *pActivate, unsigned int Num);
#endif
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    wchar_t *getName();
    int getCountFormats();
    unsigned int getWidth();
    unsigned int getHeight();
<<<<<<< HEAD
=======
    unsigned int getFrameRate() const;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    MediaType getFormat(unsigned int id);
    bool setupDevice(unsigned int w, unsigned int h, unsigned int idealFramerate = 0);
    bool setupDevice(unsigned int id);
    bool isDeviceSetup();
    bool isDeviceMediaSource();
    bool isDeviceRawDataSource();
    bool isFrameNew();
    IMFMediaSource *getMediaSource();
    RawImage *getRawImageOut();
private:
    enum typeLock
    {
        MediaSourceLock,
        RawDataLock,
        OpenLock
    } vd_LockOut;
    wchar_t *vd_pFriendlyName;
    ImageGrabberThread *vd_pImGrTh;
    CamParametrs vd_PrevParametrs;
    unsigned int vd_Width;
    unsigned int vd_Height;
<<<<<<< HEAD
=======
    unsigned int vd_FrameRate;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    unsigned int vd_CurrentNumber;
    bool vd_IsSetuped;
    std::map<UINT64, FrameRateMap> vd_CaptureFormats;
    std::vector<MediaType> vd_CurrentFormats;
    IMFMediaSource *vd_pSource;
<<<<<<< HEAD
=======
#ifdef HAVE_WINRT
    MAKE_WRL_AGILE_REF(_MediaCapture) vd_pMedCap;
    EventRegistrationToken vd_cookie;
    ImageGrabberWinRT *vd_pImGr;
    DEFINE_TASK<void> vd_pAction;
#endif
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    emergensyStopEventCallback vd_func;
    void *vd_userData;
    HRESULT enumerateCaptureFormats(IMFMediaSource *pSource);
    long setDeviceFormat(IMFMediaSource *pSource, unsigned long dwFormatIndex);
    void buildLibraryofTypes();
    int findType(unsigned int size, unsigned int frameRate = 0);
<<<<<<< HEAD
    long resetDevice(IMFActivate *pActivate);
    long initDevice();
    long checkDevice(IMFAttributes *pAttributes, IMFActivate **pDevice);
=======
#ifdef HAVE_WINRT
    HRESULT enumerateCaptureFormats(MAKE_WRL_REF(_MediaCapture) pSource);
    long setDeviceFormat(MAKE_WRL_REF(_MediaCapture) pSource, unsigned long dwFormatIndex, MAKE_WRL_REF(_AsyncAction)* pAction);
    long resetDevice(MAKE_WRL_REF(_IDeviceInformation) pDevice);
#ifdef HAVE_CONCURRENCY
    long checkDevice(_DeviceClass devClass, DEFINE_TASK<void>* pTask, MAKE_WRL_REF(_IDeviceInformation)* ppDevice);
#endif
#else
    long resetDevice(IMFActivate *pActivate);
    long checkDevice(IMFAttributes *pAttributes, IMFActivate **pDevice);
#endif
    long initDevice();
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
};

/// Class for managing of list of video devices
class videoDevices
{
public:
    ~videoDevices(void);
<<<<<<< HEAD
    long initDevices(IMFAttributes *pAttributes);
=======
#ifdef HAVE_WINRT
    long initDevices(_DeviceClass devClass);
    void waitInit() {
#ifdef HAVE_CONCURRENCY
        vds_enumTask.wait();
#endif
    }
#else
    long initDevices(IMFAttributes *pAttributes);
#endif
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    static videoDevices& getInstance();
    videoDevice *getDevice(unsigned int i);
    unsigned int getCount();
    void clearDevices();
private:
    UINT32 count;
<<<<<<< HEAD
=======
#ifdef HAVE_WINRT
    DEFINE_TASK<void> vds_enumTask;
#endif
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    std::vector<videoDevice *> vds_Devices;
    videoDevices(void);
};

// Class for creating of Media Foundation context
class Media_Foundation
{
public:
    virtual ~Media_Foundation(void);
    static Media_Foundation& getInstance();
    bool buildListOfDevices();
private:
    Media_Foundation(void);
};

/// The only visiable class for controlling of video devices in format singelton
class videoInput
{
public:
    virtual ~videoInput(void);
    // Getting of static instance of videoInput class
    static videoInput& getInstance();
    // Closing video device with deviceID
    void closeDevice(int deviceID);
    // Setting callback function for emergency events(for example: removing video device with deviceID) with userData
    void setEmergencyStopEvent(int deviceID, void *userData, void(*func)(int, void *));
    // Closing all devices
    void closeAllDevices();
    // Getting of parametrs of video device with deviceID
    CamParametrs getParametrs(int deviceID);
    // Setting of parametrs of video device with deviceID
    void setParametrs(int deviceID, CamParametrs parametrs);
    // Getting numbers of existence videodevices with listing in consol
    unsigned int listDevices(bool silent = false);
    // Getting numbers of formats, which are supported by videodevice with deviceID
    unsigned int getCountFormats(int deviceID);
    // Getting width of image, which is getting from videodevice with deviceID
    unsigned int getWidth(int deviceID);
    // Getting height of image, which is getting from videodevice with deviceID
    unsigned int getHeight(int deviceID);
<<<<<<< HEAD
=======
    // Getting frame rate, which is getting from videodevice with deviceID
    unsigned int getFrameRate(int deviceID) const;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    // Getting name of videodevice with deviceID
    wchar_t *getNameVideoDevice(int deviceID);
    // Getting interface MediaSource for Media Foundation from videodevice with deviceID
    IMFMediaSource *getMediaSource(int deviceID);
    // Getting format with id, which is supported by videodevice with deviceID
    MediaType getFormat(int deviceID, int unsigned id);
    // Checking of existence of the suitable video devices
    bool isDevicesAcceable();
    // Checking of using the videodevice with deviceID
    bool isDeviceSetup(int deviceID);
    // Checking of using MediaSource from videodevice with deviceID
    bool isDeviceMediaSource(int deviceID);
    // Checking of using Raw Data of pixels from videodevice with deviceID
    bool isDeviceRawDataSource(int deviceID);
<<<<<<< HEAD
    // Setting of the state of outprinting info in console
    static void setVerbose(bool state);
=======
#ifdef _DEBUG
    // Setting of the state of outprinting info in console
    static void setVerbose(bool state);
#endif
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    // Initialization of video device with deviceID by media type with id
    bool setupDevice(int deviceID, unsigned int id = 0);
    // Initialization of video device with deviceID by wisth w, height h and fps idealFramerate
    bool setupDevice(int deviceID, unsigned int w, unsigned int h, unsigned int idealFramerate = 30);
    // Checking of recivig of new frame from video device with deviceID
    bool isFrameNew(int deviceID);
<<<<<<< HEAD
=======
#ifdef HAVE_WINRT
    void waitForDevice(int deviceID);
#endif
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    // Writing of Raw Data pixels from video device with deviceID with correction of RedAndBlue flipping flipRedAndBlue and vertical flipping flipImage
    bool getPixels(int deviceID, unsigned char * pixels, bool flipRedAndBlue = false, bool flipImage = false);
    static void processPixels(unsigned char * src, unsigned char * dst, unsigned int width, unsigned int height, unsigned int bpp, bool bRGB, bool bFlip);
private:
    bool accessToDevices;
    videoInput(void);
    void updateListOfDevices();
};

<<<<<<< HEAD
DebugPrintOut::DebugPrintOut(void):verbose(true)
{
}

DebugPrintOut::~DebugPrintOut(void)
{
}

DebugPrintOut& DebugPrintOut::getInstance()
{
    static DebugPrintOut instance;
    return instance;
}

void DebugPrintOut::printOut(const wchar_t *format, ...)
=======
#ifdef _DEBUG
DPO::DPO(void):verbose(true)
{
}

DPO::~DPO(void)
{
}

DPO& DPO::getInstance()
{
    static DPO instance;
    return instance;
}

void DPO::printOut(const wchar_t *format, ...)
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
{
    if(verbose)
    {
        int i = 0;
        wchar_t *p = NULL;
        va_list args;
        va_start(args, format);
<<<<<<< HEAD
        if(wcscmp(format, L"%i"))
        {
            i = va_arg (args, int);
        }
        if(wcscmp(format, L"%s"))
        {
            p = va_arg (args, wchar_t *);
        }
        wprintf(format, i,p);
=======
        if( ::IsDebuggerPresent() )
        {
            WCHAR szMsg[512];
            ::StringCchVPrintfW(szMsg, sizeof(szMsg)/sizeof(szMsg[0]), format, args);
            ::OutputDebugStringW(szMsg);
        }
        else
        {
            if(wcscmp(format, L"%i"))
            {
                i = va_arg (args, int);
            }
            if(wcscmp(format, L"%s"))
            {
                p = va_arg (args, wchar_t *);
            }
            wprintf(format, i,p);
        }
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        va_end (args);
    }
}

<<<<<<< HEAD
void DebugPrintOut::setVerbose(bool state)
{
    verbose = state;
}
=======
void DPO::setVerbose(bool state)
{
    verbose = state;
}
#endif
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d

LPCWSTR GetGUIDNameConstNew(const GUID& guid);
HRESULT GetGUIDNameNew(const GUID& guid, WCHAR **ppwsz);
HRESULT LogAttributeValueByIndexNew(IMFAttributes *pAttr, DWORD index);
HRESULT SpecialCaseAttributeValueNew(GUID guid, const PROPVARIANT& var, MediaType &out);

unsigned int *GetParametr(GUID guid, MediaType &out)
{
    if(guid == MF_MT_YUV_MATRIX)
        return &(out.MF_MT_YUV_MATRIX);
    if(guid == MF_MT_VIDEO_LIGHTING)
        return &(out.MF_MT_VIDEO_LIGHTING);
    if(guid == MF_MT_DEFAULT_STRIDE)
        return (unsigned int*)&(out.MF_MT_DEFAULT_STRIDE);
    if(guid == MF_MT_VIDEO_CHROMA_SITING)
        return &(out.MF_MT_VIDEO_CHROMA_SITING);
    if(guid == MF_MT_VIDEO_NOMINAL_RANGE)
        return &(out.MF_MT_VIDEO_NOMINAL_RANGE);
    if(guid == MF_MT_ALL_SAMPLES_INDEPENDENT)
        return &(out.MF_MT_ALL_SAMPLES_INDEPENDENT);
    if(guid == MF_MT_FIXED_SIZE_SAMPLES)
        return &(out.MF_MT_FIXED_SIZE_SAMPLES);
    if(guid == MF_MT_SAMPLE_SIZE)
        return &(out.MF_MT_SAMPLE_SIZE);
    if(guid == MF_MT_VIDEO_PRIMARIES)
        return &(out.MF_MT_VIDEO_PRIMARIES);
    if(guid == MF_MT_INTERLACE_MODE)
        return &(out.MF_MT_INTERLACE_MODE);
    return NULL;
}

HRESULT LogAttributeValueByIndexNew(IMFAttributes *pAttr, DWORD index, MediaType &out)
{
    WCHAR *pGuidName = NULL;
    WCHAR *pGuidValName = NULL;
    GUID guid = { 0 };
    PROPVARIANT var;
    PropVariantInit(&var);
    HRESULT hr = pAttr->GetItemByIndex(index, &guid, &var);
    if (FAILED(hr))
    {
        goto done;
    }
    hr = GetGUIDNameNew(guid, &pGuidName);
    if (FAILED(hr))
    {
        goto done;
    }
    hr = SpecialCaseAttributeValueNew(guid, var, out);
    unsigned int *p;
    if (FAILED(hr))
    {
        goto done;
    }
    if (hr == S_FALSE)
    {
        switch (var.vt)
        {
        case VT_UI4:
            p = GetParametr(guid, out);
            if(p)
            {
                *p = var.ulVal;
            }
            break;
        case VT_UI8:
            break;
        case VT_R8:
            break;
        case VT_CLSID:
            if(guid == MF_MT_AM_FORMAT_TYPE)
            {
                hr = GetGUIDNameNew(*var.puuid, &pGuidValName);
                if (SUCCEEDED(hr))
                {
<<<<<<< HEAD
                    out.MF_MT_AM_FORMAT_TYPE = MF_MT_AM_FORMAT_TYPE;
=======
                    out.MF_MT_AM_FORMAT_TYPE = *var.puuid;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
                    out.pMF_MT_AM_FORMAT_TYPEName = pGuidValName;
                    pGuidValName = NULL;
                }
            }
            if(guid == MF_MT_MAJOR_TYPE)
            {
                hr = GetGUIDNameNew(*var.puuid, &pGuidValName);
                if (SUCCEEDED(hr))
                {
<<<<<<< HEAD
                    out.MF_MT_MAJOR_TYPE = MF_MT_MAJOR_TYPE;
=======
                    out.MF_MT_MAJOR_TYPE = *var.puuid;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
                    out.pMF_MT_MAJOR_TYPEName = pGuidValName;
                    pGuidValName = NULL;
                }
            }
            if(guid == MF_MT_SUBTYPE)
            {
                hr = GetGUIDNameNew(*var.puuid, &pGuidValName);
                if (SUCCEEDED(hr))
                {
<<<<<<< HEAD
                    out.MF_MT_SUBTYPE = MF_MT_SUBTYPE;
=======
                    out.MF_MT_SUBTYPE = *var.puuid;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
                    out.pMF_MT_SUBTYPEName = pGuidValName;
                    pGuidValName = NULL;
                }
            }
            break;
        case VT_LPWSTR:
            break;
        case VT_VECTOR | VT_UI1:
            break;
        case VT_UNKNOWN:
            break;
        default:
            break;
        }
    }
done:
    CoTaskMemFree(pGuidName);
    CoTaskMemFree(pGuidValName);
    PropVariantClear(&var);
    return hr;
}

HRESULT GetGUIDNameNew(const GUID& guid, WCHAR **ppwsz)
{
    HRESULT hr = S_OK;
    WCHAR *pName = NULL;
    LPCWSTR pcwsz = GetGUIDNameConstNew(guid);
    if (pcwsz)
    {
        size_t cchLength = 0;
        hr = StringCchLengthW(pcwsz, STRSAFE_MAX_CCH, &cchLength);
        if (FAILED(hr))
        {
            goto done;
        }
        pName = (WCHAR*)CoTaskMemAlloc((cchLength + 1) * sizeof(WCHAR));
        if (pName == NULL)
        {
            hr = E_OUTOFMEMORY;
            goto done;
        }
        hr = StringCchCopyW(pName, cchLength + 1, pcwsz);
        if (FAILED(hr))
        {
            goto done;
        }
    }
    else
    {
        hr = StringFromCLSID(guid, &pName);
    }
done:
    if (FAILED(hr))
    {
        *ppwsz = NULL;
        CoTaskMemFree(pName);
    }
    else
    {
        *ppwsz = pName;
    }
    return hr;
}

void LogUINT32AsUINT64New(const PROPVARIANT& var, UINT32 &uHigh, UINT32 &uLow)
{
    Unpack2UINT32AsUINT64(var.uhVal.QuadPart, &uHigh, &uLow);
}

float OffsetToFloatNew(const MFOffset& offset)
{
    return offset.value + (static_cast<float>(offset.fract) / 65536.0f);
}

HRESULT LogVideoAreaNew(const PROPVARIANT& var)
{
    if (var.caub.cElems < sizeof(MFVideoArea))
    {
        return S_OK;
    }
    return S_OK;
}

HRESULT SpecialCaseAttributeValueNew(GUID guid, const PROPVARIANT& var, MediaType &out)
{
    if (guid == MF_MT_DEFAULT_STRIDE)
    {
        out.MF_MT_DEFAULT_STRIDE = var.intVal;
    } else
    if (guid == MF_MT_FRAME_SIZE)
    {
        UINT32 uHigh = 0, uLow = 0;
        LogUINT32AsUINT64New(var, uHigh, uLow);
        out.width = uHigh;
        out.height = uLow;
        out.MF_MT_FRAME_SIZE = out.width * out.height;
    }
    else
    if (guid == MF_MT_FRAME_RATE)
    {
        UINT32 uHigh = 0, uLow = 0;
        LogUINT32AsUINT64New(var, uHigh, uLow);
        out.MF_MT_FRAME_RATE_NUMERATOR = uHigh;
        out.MF_MT_FRAME_RATE_DENOMINATOR = uLow;
    }
    else
    if (guid == MF_MT_FRAME_RATE_RANGE_MAX)
    {
        UINT32 uHigh = 0, uLow = 0;
        LogUINT32AsUINT64New(var, uHigh, uLow);
        out.MF_MT_FRAME_RATE_RANGE_MAX = uHigh;
        out.MF_MT_FRAME_RATE_RANGE_MAX_low = uLow;
    }
    else
    if (guid == MF_MT_FRAME_RATE_RANGE_MIN)
    {
        UINT32 uHigh = 0, uLow = 0;
        LogUINT32AsUINT64New(var, uHigh, uLow);
        out.MF_MT_FRAME_RATE_RANGE_MIN = uHigh;
        out.MF_MT_FRAME_RATE_RANGE_MIN_low = uLow;
    }
    else
    if (guid == MF_MT_PIXEL_ASPECT_RATIO)
    {
        UINT32 uHigh = 0, uLow = 0;
        LogUINT32AsUINT64New(var, uHigh, uLow);
        out.MF_MT_PIXEL_ASPECT_RATIO = uHigh;
        out.MF_MT_PIXEL_ASPECT_RATIO_low = uLow;
    }
    else
    {
        return S_FALSE;
    }
    return S_OK;
}

#ifndef IF_EQUAL_RETURN
#define IF_EQUAL_RETURN(param, val) if(val == param) return L#val
#endif

LPCWSTR GetGUIDNameConstNew(const GUID& guid)
{
    IF_EQUAL_RETURN(guid, MF_MT_MAJOR_TYPE);
    IF_EQUAL_RETURN(guid, MF_MT_MAJOR_TYPE);
    IF_EQUAL_RETURN(guid, MF_MT_SUBTYPE);
    IF_EQUAL_RETURN(guid, MF_MT_ALL_SAMPLES_INDEPENDENT);
    IF_EQUAL_RETURN(guid, MF_MT_FIXED_SIZE_SAMPLES);
    IF_EQUAL_RETURN(guid, MF_MT_COMPRESSED);
    IF_EQUAL_RETURN(guid, MF_MT_SAMPLE_SIZE);
    IF_EQUAL_RETURN(guid, MF_MT_WRAPPED_TYPE);
    IF_EQUAL_RETURN(guid, MF_MT_AUDIO_NUM_CHANNELS);
    IF_EQUAL_RETURN(guid, MF_MT_AUDIO_SAMPLES_PER_SECOND);
    IF_EQUAL_RETURN(guid, MF_MT_AUDIO_FLOAT_SAMPLES_PER_SECOND);
    IF_EQUAL_RETURN(guid, MF_MT_AUDIO_AVG_BYTES_PER_SECOND);
    IF_EQUAL_RETURN(guid, MF_MT_AUDIO_BLOCK_ALIGNMENT);
    IF_EQUAL_RETURN(guid, MF_MT_AUDIO_BITS_PER_SAMPLE);
    IF_EQUAL_RETURN(guid, MF_MT_AUDIO_VALID_BITS_PER_SAMPLE);
    IF_EQUAL_RETURN(guid, MF_MT_AUDIO_SAMPLES_PER_BLOCK);
    IF_EQUAL_RETURN(guid, MF_MT_AUDIO_CHANNEL_MASK);
    IF_EQUAL_RETURN(guid, MF_MT_AUDIO_FOLDDOWN_MATRIX);
    IF_EQUAL_RETURN(guid, MF_MT_AUDIO_WMADRC_PEAKREF);
    IF_EQUAL_RETURN(guid, MF_MT_AUDIO_WMADRC_PEAKTARGET);
    IF_EQUAL_RETURN(guid, MF_MT_AUDIO_WMADRC_AVGREF);
    IF_EQUAL_RETURN(guid, MF_MT_AUDIO_WMADRC_AVGTARGET);
    IF_EQUAL_RETURN(guid, MF_MT_AUDIO_PREFER_WAVEFORMATEX);
    IF_EQUAL_RETURN(guid, MF_MT_AAC_PAYLOAD_TYPE);
    IF_EQUAL_RETURN(guid, MF_MT_AAC_AUDIO_PROFILE_LEVEL_INDICATION);
    IF_EQUAL_RETURN(guid, MF_MT_FRAME_SIZE);
    IF_EQUAL_RETURN(guid, MF_MT_FRAME_RATE);
    IF_EQUAL_RETURN(guid, MF_MT_FRAME_RATE_RANGE_MAX);
    IF_EQUAL_RETURN(guid, MF_MT_FRAME_RATE_RANGE_MIN);
    IF_EQUAL_RETURN(guid, MF_MT_PIXEL_ASPECT_RATIO);
    IF_EQUAL_RETURN(guid, MF_MT_DRM_FLAGS);
    IF_EQUAL_RETURN(guid, MF_MT_PAD_CONTROL_FLAGS);
    IF_EQUAL_RETURN(guid, MF_MT_SOURCE_CONTENT_HINT);
    IF_EQUAL_RETURN(guid, MF_MT_VIDEO_CHROMA_SITING);
    IF_EQUAL_RETURN(guid, MF_MT_INTERLACE_MODE);
    IF_EQUAL_RETURN(guid, MF_MT_TRANSFER_FUNCTION);
    IF_EQUAL_RETURN(guid, MF_MT_VIDEO_PRIMARIES);
    IF_EQUAL_RETURN(guid, MF_MT_CUSTOM_VIDEO_PRIMARIES);
    IF_EQUAL_RETURN(guid, MF_MT_YUV_MATRIX);
    IF_EQUAL_RETURN(guid, MF_MT_VIDEO_LIGHTING);
    IF_EQUAL_RETURN(guid, MF_MT_VIDEO_NOMINAL_RANGE);
    IF_EQUAL_RETURN(guid, MF_MT_GEOMETRIC_APERTURE);
    IF_EQUAL_RETURN(guid, MF_MT_MINIMUM_DISPLAY_APERTURE);
    IF_EQUAL_RETURN(guid, MF_MT_PAN_SCAN_APERTURE);
    IF_EQUAL_RETURN(guid, MF_MT_PAN_SCAN_ENABLED);
    IF_EQUAL_RETURN(guid, MF_MT_AVG_BITRATE);
    IF_EQUAL_RETURN(guid, MF_MT_AVG_BIT_ERROR_RATE);
    IF_EQUAL_RETURN(guid, MF_MT_MAX_KEYFRAME_SPACING);
    IF_EQUAL_RETURN(guid, MF_MT_DEFAULT_STRIDE);
    IF_EQUAL_RETURN(guid, MF_MT_PALETTE);
    IF_EQUAL_RETURN(guid, MF_MT_USER_DATA);
    IF_EQUAL_RETURN(guid, MF_MT_AM_FORMAT_TYPE);
    IF_EQUAL_RETURN(guid, MF_MT_MPEG_START_TIME_CODE);
    IF_EQUAL_RETURN(guid, MF_MT_MPEG2_PROFILE);
    IF_EQUAL_RETURN(guid, MF_MT_MPEG2_LEVEL);
    IF_EQUAL_RETURN(guid, MF_MT_MPEG2_FLAGS);
    IF_EQUAL_RETURN(guid, MF_MT_MPEG_SEQUENCE_HEADER);
    IF_EQUAL_RETURN(guid, MF_MT_DV_AAUX_SRC_PACK_0);
    IF_EQUAL_RETURN(guid, MF_MT_DV_AAUX_CTRL_PACK_0);
    IF_EQUAL_RETURN(guid, MF_MT_DV_AAUX_SRC_PACK_1);
    IF_EQUAL_RETURN(guid, MF_MT_DV_AAUX_CTRL_PACK_1);
    IF_EQUAL_RETURN(guid, MF_MT_DV_VAUX_SRC_PACK);
    IF_EQUAL_RETURN(guid, MF_MT_DV_VAUX_CTRL_PACK);
    IF_EQUAL_RETURN(guid, MF_MT_ARBITRARY_HEADER);
    IF_EQUAL_RETURN(guid, MF_MT_ARBITRARY_FORMAT);
    IF_EQUAL_RETURN(guid, MF_MT_IMAGE_LOSS_TOLERANT);
    IF_EQUAL_RETURN(guid, MF_MT_MPEG4_SAMPLE_DESCRIPTION);
    IF_EQUAL_RETURN(guid, MF_MT_MPEG4_CURRENT_SAMPLE_ENTRY);
    IF_EQUAL_RETURN(guid, MF_MT_ORIGINAL_4CC);
    IF_EQUAL_RETURN(guid, MF_MT_ORIGINAL_WAVE_FORMAT_TAG);
    // Media types
    IF_EQUAL_RETURN(guid, MFMediaType_Audio);
    IF_EQUAL_RETURN(guid, MFMediaType_Video);
    IF_EQUAL_RETURN(guid, MFMediaType_Protected);
    IF_EQUAL_RETURN(guid, MFMediaType_SAMI);
    IF_EQUAL_RETURN(guid, MFMediaType_Script);
    IF_EQUAL_RETURN(guid, MFMediaType_Image);
    IF_EQUAL_RETURN(guid, MFMediaType_HTML);
    IF_EQUAL_RETURN(guid, MFMediaType_Binary);
    IF_EQUAL_RETURN(guid, MFMediaType_FileTransfer);
    IF_EQUAL_RETURN(guid, MFVideoFormat_AI44); //     FCC('AI44')
    IF_EQUAL_RETURN(guid, MFVideoFormat_ARGB32); //   D3DFMT_A8R8G8B8
    IF_EQUAL_RETURN(guid, MFVideoFormat_AYUV); //     FCC('AYUV')
    IF_EQUAL_RETURN(guid, MFVideoFormat_DV25); //     FCC('dv25')
    IF_EQUAL_RETURN(guid, MFVideoFormat_DV50); //     FCC('dv50')
    IF_EQUAL_RETURN(guid, MFVideoFormat_DVH1); //     FCC('dvh1')
    IF_EQUAL_RETURN(guid, MFVideoFormat_DVSD); //     FCC('dvsd')
    IF_EQUAL_RETURN(guid, MFVideoFormat_DVSL); //     FCC('dvsl')
    IF_EQUAL_RETURN(guid, MFVideoFormat_H264); //     FCC('H264')
    IF_EQUAL_RETURN(guid, MFVideoFormat_I420); //     FCC('I420')
    IF_EQUAL_RETURN(guid, MFVideoFormat_IYUV); //     FCC('IYUV')
    IF_EQUAL_RETURN(guid, MFVideoFormat_M4S2); //     FCC('M4S2')
    IF_EQUAL_RETURN(guid, MFVideoFormat_MJPG);
    IF_EQUAL_RETURN(guid, MFVideoFormat_MP43); //     FCC('MP43')
    IF_EQUAL_RETURN(guid, MFVideoFormat_MP4S); //     FCC('MP4S')
    IF_EQUAL_RETURN(guid, MFVideoFormat_MP4V); //     FCC('MP4V')
    IF_EQUAL_RETURN(guid, MFVideoFormat_MPG1); //     FCC('MPG1')
    IF_EQUAL_RETURN(guid, MFVideoFormat_MSS1); //     FCC('MSS1')
    IF_EQUAL_RETURN(guid, MFVideoFormat_MSS2); //     FCC('MSS2')
    IF_EQUAL_RETURN(guid, MFVideoFormat_NV11); //     FCC('NV11')
    IF_EQUAL_RETURN(guid, MFVideoFormat_NV12); //     FCC('NV12')
    IF_EQUAL_RETURN(guid, MFVideoFormat_P010); //     FCC('P010')
    IF_EQUAL_RETURN(guid, MFVideoFormat_P016); //     FCC('P016')
    IF_EQUAL_RETURN(guid, MFVideoFormat_P210); //     FCC('P210')
    IF_EQUAL_RETURN(guid, MFVideoFormat_P216); //     FCC('P216')
    IF_EQUAL_RETURN(guid, MFVideoFormat_RGB24); //    D3DFMT_R8G8B8
    IF_EQUAL_RETURN(guid, MFVideoFormat_RGB32); //    D3DFMT_X8R8G8B8
    IF_EQUAL_RETURN(guid, MFVideoFormat_RGB555); //   D3DFMT_X1R5G5B5
    IF_EQUAL_RETURN(guid, MFVideoFormat_RGB565); //   D3DFMT_R5G6B5
    IF_EQUAL_RETURN(guid, MFVideoFormat_RGB8);
    IF_EQUAL_RETURN(guid, MFVideoFormat_UYVY); //     FCC('UYVY')
    IF_EQUAL_RETURN(guid, MFVideoFormat_v210); //     FCC('v210')
    IF_EQUAL_RETURN(guid, MFVideoFormat_v410); //     FCC('v410')
    IF_EQUAL_RETURN(guid, MFVideoFormat_WMV1); //     FCC('WMV1')
    IF_EQUAL_RETURN(guid, MFVideoFormat_WMV2); //     FCC('WMV2')
    IF_EQUAL_RETURN(guid, MFVideoFormat_WMV3); //     FCC('WMV3')
    IF_EQUAL_RETURN(guid, MFVideoFormat_WVC1); //     FCC('WVC1')
    IF_EQUAL_RETURN(guid, MFVideoFormat_Y210); //     FCC('Y210')
    IF_EQUAL_RETURN(guid, MFVideoFormat_Y216); //     FCC('Y216')
    IF_EQUAL_RETURN(guid, MFVideoFormat_Y410); //     FCC('Y410')
    IF_EQUAL_RETURN(guid, MFVideoFormat_Y416); //     FCC('Y416')
    IF_EQUAL_RETURN(guid, MFVideoFormat_Y41P);
    IF_EQUAL_RETURN(guid, MFVideoFormat_Y41T);
    IF_EQUAL_RETURN(guid, MFVideoFormat_YUY2); //     FCC('YUY2')
    IF_EQUAL_RETURN(guid, MFVideoFormat_YV12); //     FCC('YV12')
    IF_EQUAL_RETURN(guid, MFVideoFormat_YVYU);
    IF_EQUAL_RETURN(guid, MFAudioFormat_PCM); //              WAVE_FORMAT_PCM
    IF_EQUAL_RETURN(guid, MFAudioFormat_Float); //            WAVE_FORMAT_IEEE_FLOAT
    IF_EQUAL_RETURN(guid, MFAudioFormat_DTS); //              WAVE_FORMAT_DTS
    IF_EQUAL_RETURN(guid, MFAudioFormat_Dolby_AC3_SPDIF); //  WAVE_FORMAT_DOLBY_AC3_SPDIF
    IF_EQUAL_RETURN(guid, MFAudioFormat_DRM); //              WAVE_FORMAT_DRM
    IF_EQUAL_RETURN(guid, MFAudioFormat_WMAudioV8); //        WAVE_FORMAT_WMAUDIO2
    IF_EQUAL_RETURN(guid, MFAudioFormat_WMAudioV9); //        WAVE_FORMAT_WMAUDIO3
    IF_EQUAL_RETURN(guid, MFAudioFormat_WMAudio_Lossless); // WAVE_FORMAT_WMAUDIO_LOSSLESS
    IF_EQUAL_RETURN(guid, MFAudioFormat_WMASPDIF); //         WAVE_FORMAT_WMASPDIF
    IF_EQUAL_RETURN(guid, MFAudioFormat_MSP1); //             WAVE_FORMAT_WMAVOICE9
    IF_EQUAL_RETURN(guid, MFAudioFormat_MP3); //              WAVE_FORMAT_MPEGLAYER3
    IF_EQUAL_RETURN(guid, MFAudioFormat_MPEG); //             WAVE_FORMAT_MPEG
    IF_EQUAL_RETURN(guid, MFAudioFormat_AAC); //              WAVE_FORMAT_MPEG_HEAAC
    IF_EQUAL_RETURN(guid, MFAudioFormat_ADTS); //             WAVE_FORMAT_MPEG_ADTS_AAC
    return NULL;
}

FormatReader::FormatReader(void)
{
}

MediaType FormatReader::Read(IMFMediaType *pType)
{
    UINT32 count = 0;
<<<<<<< HEAD
    HRESULT hr = S_OK;
    MediaType out;
    hr = pType->LockStore();
=======
    MediaType out;
    HRESULT hr = pType->LockStore();
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    if (FAILED(hr))
    {
        return out;
    }
    hr = pType->GetCount(&count);
    if (FAILED(hr))
    {
        return out;
    }
    for (UINT32 i = 0; i < count; i++)
    {
        hr = LogAttributeValueByIndexNew(pType, i, out);
        if (FAILED(hr))
        {
            break;
        }
    }
    hr = pType->UnlockStore();
    if (FAILED(hr))
    {
        return out;
    }
    return out;
}

FormatReader::~FormatReader(void)
{
}

#define CHECK_HR(x) if (FAILED(x)) { goto done; }

<<<<<<< HEAD
ImageGrabber::ImageGrabber(unsigned int deviceID, bool synchronous):
    m_cRef(1),
    ig_DeviceID(deviceID),
    ig_pSource(NULL),
    ig_pSession(NULL),
    ig_pTopology(NULL),
=======
ImageGrabberCallback::ImageGrabberCallback(bool synchronous):
    m_cRef(1),
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    ig_RIE(true),
    ig_Close(false),
    ig_Synchronous(synchronous),
    ig_hFrameReady(synchronous ? CreateEvent(NULL, FALSE, FALSE, NULL): 0),
    ig_hFrameGrabbed(synchronous ? CreateEvent(NULL, FALSE, TRUE, NULL): 0),
    ig_hFinish(CreateEvent(NULL, TRUE, FALSE, NULL))
{}

<<<<<<< HEAD
=======
ImageGrabber::ImageGrabber(unsigned int deviceID, bool synchronous):
    ImageGrabberCallback(synchronous),
    ig_DeviceID(deviceID),
    ig_pSource(NULL),
    ig_pSession(NULL),
    ig_pTopology(NULL)
{}

>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
ImageGrabber::~ImageGrabber(void)
{
    if (ig_pSession)
    {
        ig_pSession->Shutdown();
    }

    CloseHandle(ig_hFinish);

    if (ig_Synchronous)
    {
        CloseHandle(ig_hFrameReady);
        CloseHandle(ig_hFrameGrabbed);
    }

    SafeRelease(&ig_pSession);
    SafeRelease(&ig_pTopology);
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();

    DPO->printOut(L"IMAGEGRABBER VIDEODEVICE %i: Destroing instance of the ImageGrabber class\n", ig_DeviceID);
}

HRESULT ImageGrabber::initImageGrabber(IMFMediaSource *pSource, GUID VideoFormat)
{
    ComPtr<IMFActivate> pSinkActivate = NULL;
    ComPtr<IMFMediaType> pType = NULL;
    ComPtr<IMFPresentationDescriptor> pPD = NULL;
    ComPtr<IMFStreamDescriptor> pSD = NULL;
    ComPtr<IMFMediaTypeHandler> pHandler = NULL;
    ComPtr<IMFMediaType> pCurrentType = NULL;
    HRESULT hr = S_OK;
=======

    DebugPrintOut(L"IMAGEGRABBER VIDEODEVICE %i: Destroying instance of the ImageGrabber class\n", ig_DeviceID);
}

#ifdef HAVE_WINRT

ImageGrabberWinRT::ImageGrabberWinRT(bool synchronous):
    ImageGrabberCallback(synchronous),
    ig_pMediaSink(NULL)
{
    ig_pMedCapSource = nullptr;
}

ImageGrabberWinRT::~ImageGrabberWinRT(void)
{
    //stop must already be performed and complete by object owner
    if (ig_pMediaSink != NULL) {
        ((IMFMediaSink*)ig_pMediaSink)->Shutdown();
    }
    SafeRelease(&ig_pMediaSink);
    RELEASE_AGILE_WRL(ig_pMedCapSource)

    CloseHandle(ig_hFinish);

    if (ig_Synchronous)
    {
        CloseHandle(ig_hFrameReady);
        CloseHandle(ig_hFrameGrabbed);
    }

    DebugPrintOut(L"IMAGEGRABBER VIDEODEVICE: Destroying instance of the ImageGrabberWinRT class\n");
}

HRESULT ImageGrabberWinRT::initImageGrabber(MAKE_WRL_REF(_MediaCapture) pSource,
    GUID VideoFormat)
{
    HRESULT hr;
    MAKE_WRL_OBJ(_VideoDeviceController) pDevCont;
    WRL_PROP_GET(pSource, VideoDeviceController, pDevCont, hr)
    if (FAILED(hr)) return hr;
    GET_WRL_OBJ_FROM_OBJ(_MediaDeviceController, pMedDevCont, pDevCont, hr)
    if (FAILED(hr)) return hr;
    MAKE_WRL_OBJ(_MediaEncodingProperties) pMedEncProps;
    WRL_METHOD(pMedDevCont, GetMediaStreamProperties, pMedEncProps, hr, WRL_ENUM_GET(_MediaStreamType, MediaStreamType, VideoPreview))
    if (FAILED(hr)) return hr;
    GET_WRL_OBJ_FROM_OBJ(_VideoEncodingProperties, pVidProps, pMedEncProps, hr);
    if (FAILED(hr)) return hr;
    _ComPtr<IMFMediaType> pType = NULL;
    hr = MediaSink::ConvertPropertiesToMediaType(DEREF_AS_NATIVE_WRL_OBJ(ABI::Windows::Media::MediaProperties::IMediaEncodingProperties, pMedEncProps), &pType);
    if (FAILED(hr)) return hr;
    MediaType MT = FormatReader::Read(pType.Get());
    unsigned int sizeRawImage = 0;
    if(VideoFormat == MFVideoFormat_RGB24)
    {
        sizeRawImage = MT.MF_MT_FRAME_SIZE * 3;
    }
    else if(VideoFormat == MFVideoFormat_RGB32)
    {
        sizeRawImage = MT.MF_MT_FRAME_SIZE * 4;
    }
    sizeRawImage = MT.MF_MT_SAMPLE_SIZE;
    CHECK_HR(hr = RawImage::CreateInstance(&ig_RIFirst, sizeRawImage));
    CHECK_HR(hr = RawImage::CreateInstance(&ig_RISecond, sizeRawImage));
    ig_RIOut = ig_RISecond;
    ig_pMedCapSource = pSource;
done:
    return hr;
}

HRESULT ImageGrabberWinRT::stopGrabbing(MAKE_WRL_REF(_AsyncAction)* action)
{
    HRESULT hr = S_OK;
    if (ig_pMedCapSource != nullptr) {
        GET_WRL_OBJ_FROM_REF(_MediaCaptureVideoPreview, imedPrevCap, DEREF_AGILE_WRL_OBJ(ig_pMedCapSource), hr)
        if (FAILED(hr)) return hr;
        MAKE_WRL_REF(_AsyncAction) pAction;
        WRL_METHOD_BASE(imedPrevCap, StopPreviewAsync, pAction, hr)
        if (SUCCEEDED(hr)) {
#ifdef HAVE_CONCURRENCY
            DEFINE_TASK<void> _task = CREATE_TASK DEFINE_RET_TYPE(void)(pAction);
            *action = BEGIN_CREATE_ASYNC(void, _task, this)
                HRESULT hr = S_OK;
                _task.wait();
                SafeRelease(&ig_pMediaSink);
                SetEvent(ig_hFinish);
            END_CREATE_ASYNC(hr);
#else
            *action = nullptr;
#endif
        }
    }
    return hr;
}

HRESULT ImageGrabberWinRT::startGrabbing(MAKE_WRL_REF(_AsyncAction)* action)
{
    HRESULT hr = S_OK;
    GET_WRL_OBJ_FROM_REF(_MediaCaptureVideoPreview, imedPrevCap, DEREF_AGILE_WRL_OBJ(ig_pMedCapSource), hr)
    if (FAILED(hr)) return hr;
    ACTIVATE_OBJ(RuntimeClass_Windows_Foundation_Collections_PropertySet, _PropertySet, pSet, hr)
    if (FAILED(hr)) return hr;
    GET_WRL_OBJ_FROM_OBJ(_Map, spSetting, pSet, hr)
    if (FAILED(hr)) return hr;
    ACTIVATE_STATIC_OBJ(RuntimeClass_Windows_Foundation_PropertyValue, MAKE_WRL_OBJ(_PropertyValueStatics), spPropVal, hr)
    if (FAILED(hr)) return hr;
    _ObjectObj pVal;
    boolean bReplaced;
    WRL_METHOD(spPropVal, CreateUInt32, pVal, hr, (unsigned int)WRL_ENUM_GET(_MediaStreamType, MediaStreamType, VideoPreview))
    if (FAILED(hr)) return hr;
    WRL_METHOD(spSetting, Insert, bReplaced, hr, DEREF_WRL_OBJ(_StringReference(MF_PROP_VIDTYPE)), DEREF_WRL_OBJ(pVal))
    if (FAILED(hr)) return hr;
    WRL_METHOD(spSetting, Insert, bReplaced, hr, DEREF_WRL_OBJ(_StringReference(MF_PROP_SAMPLEGRABBERCALLBACK)), reinterpret_cast<_Object>(this))
    if (FAILED(hr)) return hr;
    MAKE_WRL_OBJ(_VideoDeviceController) pDevCont;
    WRL_PROP_GET(ig_pMedCapSource, VideoDeviceController, pDevCont, hr)
    if (FAILED(hr)) return hr;
    GET_WRL_OBJ_FROM_OBJ(_MediaDeviceController, pMedDevCont, pDevCont, hr)
    if (FAILED(hr)) return hr;
    MAKE_WRL_OBJ(_MediaEncodingProperties) pMedEncProps;
    WRL_METHOD(pMedDevCont, GetMediaStreamProperties, pMedEncProps, hr, WRL_ENUM_GET(_MediaStreamType, MediaStreamType, VideoPreview))
    if (FAILED(hr)) return hr;
    GET_WRL_OBJ_FROM_OBJ(_VideoEncodingProperties, pVidProps, pMedEncProps, hr);
    if (FAILED(hr)) return hr;
    ACTIVATE_OBJ(RuntimeClass_Windows_Media_MediaProperties_MediaEncodingProfile, _MediaEncodingProfile, pEncProps, hr)
    if (FAILED(hr)) return hr;
    WRL_PROP_PUT(pEncProps, Video, DEREF_WRL_OBJ(pVidProps), hr)
    if (FAILED(hr)) return hr;
    WRL_METHOD(spSetting, Insert, bReplaced, hr, DEREF_WRL_OBJ(_StringReference(MF_PROP_VIDENCPROPS)), DEREF_WRL_OBJ(pVidProps))
    if (SUCCEEDED(hr)) {
        //can start/stop multiple times with same MediaCapture object if using activatable class
        WRL_METHOD(imedPrevCap, _StartPreviewToCustomSinkIdAsync, *action, hr, DEREF_WRL_OBJ(pEncProps), DEREF_WRL_OBJ(_StringReference(RuntimeClass_CV_MediaSink)), DEREF_WRL_OBJ(pSet))
        if (FAILED(hr) && hr == REGDB_E_CLASSNOTREG) {
            hr = Microsoft::WRL::Make<MediaSink>().CopyTo(&ig_pMediaSink);
            if (FAILED(hr)) return hr;
            hr = ((ABI::Windows::Media::IMediaExtension*)ig_pMediaSink)->SetProperties(DEREF_AS_NATIVE_WRL_OBJ(ABI::Windows::Foundation::Collections::IPropertySet, pSet));
            if (FAILED(hr)) return hr;
            WRL_METHOD(imedPrevCap, StartPreviewToCustomSinkAsync, *action, hr, DEREF_WRL_OBJ(pEncProps), reinterpret_cast<MAKE_WRL_REF(_MediaExtension)>(ig_pMediaSink))
        }
    }
    return hr;
}

HRESULT ImageGrabberWinRT::CreateInstance(ImageGrabberWinRT **ppIG, bool synchronous)
{
    *ppIG = Microsoft::WRL::Make<ImageGrabberWinRT>(synchronous).Detach();
    if (ppIG == NULL)
    {
        return E_OUTOFMEMORY;
    }
    DebugPrintOut(L"IMAGEGRABBER VIDEODEVICE: Creating instance of ImageGrabberWinRT\n");
    return S_OK;
}
#endif

HRESULT ImageGrabber::initImageGrabber(IMFMediaSource *pSource)
{
    _ComPtr<IMFActivate> pSinkActivate = NULL;
    _ComPtr<IMFMediaType> pType = NULL;
    _ComPtr<IMFPresentationDescriptor> pPD = NULL;
    _ComPtr<IMFStreamDescriptor> pSD = NULL;
    _ComPtr<IMFMediaTypeHandler> pHandler = NULL;
    _ComPtr<IMFMediaType> pCurrentType = NULL;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    MediaType MT;
     // Clean up.
    if (ig_pSession)
    {
        ig_pSession->Shutdown();
    }
    SafeRelease(&ig_pSession);
    SafeRelease(&ig_pTopology);
    ig_pSource = pSource;
<<<<<<< HEAD
    hr = pSource->CreatePresentationDescriptor(&pPD);
=======
    HRESULT hr = pSource->CreatePresentationDescriptor(&pPD);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    if (FAILED(hr))
    {
        goto err;
    }
    BOOL fSelected;
    hr = pPD->GetStreamDescriptorByIndex(0, &fSelected, &pSD);
    if (FAILED(hr)) {
        goto err;
    }
    hr = pSD->GetMediaTypeHandler(&pHandler);
    if (FAILED(hr)) {
        goto err;
    }
    DWORD cTypes = 0;
    hr = pHandler->GetMediaTypeCount(&cTypes);
    if (FAILED(hr)) {
        goto err;
    }
    if(cTypes > 0)
    {
        hr = pHandler->GetCurrentMediaType(&pCurrentType);
        if (FAILED(hr)) {
            goto err;
        }
        MT = FormatReader::Read(pCurrentType.Get());
    }
err:
<<<<<<< HEAD
    unsigned int sizeRawImage = 0;
    if(VideoFormat == MFVideoFormat_RGB24)
    {
        sizeRawImage = MT.MF_MT_FRAME_SIZE * 3;
    }
    else if(VideoFormat == MFVideoFormat_RGB32)
    {
        sizeRawImage = MT.MF_MT_FRAME_SIZE * 4;
    }
    CHECK_HR(hr = RawImage::CreateInstance(&ig_RIFirst, sizeRawImage));
    CHECK_HR(hr = RawImage::CreateInstance(&ig_RISecond, sizeRawImage));
=======
    CHECK_HR(hr);
    CHECK_HR(hr = RawImage::CreateInstance(&ig_RIFirst, MT.MF_MT_SAMPLE_SIZE));
    CHECK_HR(hr = RawImage::CreateInstance(&ig_RISecond, MT.MF_MT_SAMPLE_SIZE));
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    ig_RIOut = ig_RISecond;
    // Configure the media type that the Sample Grabber will receive.
    // Setting the major and subtype is usually enough for the topology loader
    // to resolve the topology.
    CHECK_HR(hr = MFCreateMediaType(pType.GetAddressOf()));
<<<<<<< HEAD
    CHECK_HR(hr = pType->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Video));
    CHECK_HR(hr = pType->SetGUID(MF_MT_SUBTYPE, VideoFormat));
=======
    CHECK_HR(hr = pType->SetGUID(MF_MT_MAJOR_TYPE, MT.MF_MT_MAJOR_TYPE));
    CHECK_HR(hr = pType->SetGUID(MF_MT_SUBTYPE, MT.MF_MT_SUBTYPE));
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    // Create the sample grabber sink.
    CHECK_HR(hr = MFCreateSampleGrabberSinkActivate(pType.Get(), this, pSinkActivate.GetAddressOf()));
    // To run as fast as possible, set this attribute (requires Windows 7):
    CHECK_HR(hr = pSinkActivate->SetUINT32(MF_SAMPLEGRABBERSINK_IGNORE_CLOCK, TRUE));
    // Create the Media Session.
    CHECK_HR(hr = MFCreateMediaSession(NULL, &ig_pSession));
    // Create the topology.
    CHECK_HR(hr = CreateTopology(pSource, pSinkActivate.Get(), &ig_pTopology));
done:
    // Clean up.
    if (FAILED(hr))
    {
        if (ig_pSession)
        {
            ig_pSession->Shutdown();
        }
        SafeRelease(&ig_pSession);
        SafeRelease(&ig_pTopology);
    }
<<<<<<< HEAD

=======
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    return hr;
}

void ImageGrabber::stopGrabbing()
{
    if(ig_pSession)
        ig_pSession->Stop();
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    DPO->printOut(L"IMAGEGRABBER VIDEODEVICE %i: Stopping of of grabbing of images\n", ig_DeviceID);
=======
    DebugPrintOut(L"IMAGEGRABBER VIDEODEVICE %i: Stopping of of grabbing of images\n", ig_DeviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
}

HRESULT ImageGrabber::startGrabbing(void)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    ComPtr<IMFMediaEvent> pEvent = NULL;
    PROPVARIANT var;
    PropVariantInit(&var);
    HRESULT hr = S_OK;
    hr = ig_pSession->SetTopology(0, ig_pTopology);
    DPO->printOut(L"IMAGEGRABBER VIDEODEVICE %i: Start Grabbing of the images\n", ig_DeviceID);
    hr = ig_pSession->Start(&GUID_NULL, &var);
    for(;;)
    {
=======
    PROPVARIANT var;
    PropVariantInit(&var);
    HRESULT hr = ig_pSession->SetTopology(0, ig_pTopology);
    DebugPrintOut(L"IMAGEGRABBER VIDEODEVICE %i: Start Grabbing of the images\n", ig_DeviceID);
    hr = ig_pSession->Start(&GUID_NULL, &var);
    for(;;)
    {
        _ComPtr<IMFMediaEvent> pEvent = NULL;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        HRESULT hrStatus = S_OK;
        MediaEventType met;
        if(!ig_pSession) break;
        hr = ig_pSession->GetEvent(0, &pEvent);
        if(!SUCCEEDED(hr))
        {
            hr = S_OK;
            goto done;
        }
        hr = pEvent->GetStatus(&hrStatus);
        if(!SUCCEEDED(hr))
        {
            hr = S_OK;
            goto done;
        }
        hr = pEvent->GetType(&met);
        if(!SUCCEEDED(hr))
        {
            hr = S_OK;
            goto done;
        }
        if (met == MESessionEnded)
        {
<<<<<<< HEAD
            DPO->printOut(L"IMAGEGRABBER VIDEODEVICE %i: MESessionEnded \n", ig_DeviceID);
=======
            DebugPrintOut(L"IMAGEGRABBER VIDEODEVICE %i: MESessionEnded\n", ig_DeviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
            ig_pSession->Stop();
            break;
        }
        if (met == MESessionStopped)
        {
<<<<<<< HEAD
            DPO->printOut(L"IMAGEGRABBER VIDEODEVICE %i: MESessionStopped \n", ig_DeviceID);
            break;
        }
        if (met == MEVideoCaptureDeviceRemoved)
        {
            DPO->printOut(L"IMAGEGRABBER VIDEODEVICE %i: MEVideoCaptureDeviceRemoved \n", ig_DeviceID);
            break;
        }
        if ((met == MEError) || (met == MENonFatalError))
        {
            pEvent->GetStatus(&hrStatus);
            DPO->printOut(L"IMAGEGRABBER VIDEODEVICE %i: MEError | MENonFatalError: %u\n", ig_DeviceID, hrStatus);
            break;
        }
    }
    DPO->printOut(L"IMAGEGRABBER VIDEODEVICE %i: Finish startGrabbing \n", ig_DeviceID);
=======
            DebugPrintOut(L"IMAGEGRABBER VIDEODEVICE %i: MESessionStopped \n", ig_DeviceID);
            break;
        }
#if (WINVER >= 0x0602) // Available since Win 8
        if (met == MEVideoCaptureDeviceRemoved)
        {
            DebugPrintOut(L"IMAGEGRABBER VIDEODEVICE %i: MEVideoCaptureDeviceRemoved \n", ig_DeviceID);
            break;
        }
#endif
        if ((met == MEError) || (met == MENonFatalError))
        {
            pEvent->GetStatus(&hrStatus);
            DebugPrintOut(L"IMAGEGRABBER VIDEODEVICE %i: MEError | MENonFatalError: %u\n", ig_DeviceID, hrStatus);
            break;
        }
    }
    DebugPrintOut(L"IMAGEGRABBER VIDEODEVICE %i: Finish startGrabbing \n", ig_DeviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d

done:
    SetEvent(ig_hFinish);

    return hr;
}

<<<<<<< HEAD
void ImageGrabber::pauseGrabbing()
{
}

void ImageGrabber::resumeGrabbing()
=======
void ImageGrabberCallback::pauseGrabbing()
{
}

void ImageGrabberCallback::resumeGrabbing()
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
{
}

HRESULT ImageGrabber::CreateTopology(IMFMediaSource *pSource, IMFActivate *pSinkActivate, IMFTopology **ppTopo)
{
    IMFTopology* pTopology = NULL;
<<<<<<< HEAD
    ComPtr<IMFPresentationDescriptor> pPD = NULL;
    ComPtr<IMFStreamDescriptor> pSD = NULL;
    ComPtr<IMFMediaTypeHandler> pHandler = NULL;
    ComPtr<IMFTopologyNode> pNode1 = NULL;
    ComPtr<IMFTopologyNode> pNode2 = NULL;
=======
    _ComPtr<IMFPresentationDescriptor> pPD = NULL;
    _ComPtr<IMFStreamDescriptor> pSD = NULL;
    _ComPtr<IMFMediaTypeHandler> pHandler = NULL;
    _ComPtr<IMFTopologyNode> pNode1 = NULL;
    _ComPtr<IMFTopologyNode> pNode2 = NULL;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    HRESULT hr = S_OK;
    DWORD cStreams = 0;
    CHECK_HR(hr = MFCreateTopology(&pTopology));
    CHECK_HR(hr = pSource->CreatePresentationDescriptor(pPD.GetAddressOf()));
    CHECK_HR(hr = pPD->GetStreamDescriptorCount(&cStreams));
    for (DWORD i = 0; i < cStreams; i++)
    {
        // In this example, we look for audio streams and connect them to the sink.
        BOOL fSelected = FALSE;
        GUID majorType;
        CHECK_HR(hr = pPD->GetStreamDescriptorByIndex(i, &fSelected, &pSD));
        CHECK_HR(hr = pSD->GetMediaTypeHandler(&pHandler));
        CHECK_HR(hr = pHandler->GetMajorType(&majorType));
        if (majorType == MFMediaType_Video && fSelected)
        {
            CHECK_HR(hr = AddSourceNode(pTopology, pSource, pPD.Get(), pSD.Get(), pNode1.GetAddressOf()));
            CHECK_HR(hr = AddOutputNode(pTopology, pSinkActivate, 0, pNode2.GetAddressOf()));
            CHECK_HR(hr = pNode1->ConnectOutput(0, pNode2.Get(), 0));
            break;
        }
        else
        {
            CHECK_HR(hr = pPD->DeselectStream(i));
        }
    }
    *ppTopo = pTopology;
    (*ppTopo)->AddRef();

done:
    return hr;
}

HRESULT ImageGrabber::AddSourceNode(
    IMFTopology *pTopology,           // Topology.
    IMFMediaSource *pSource,          // Media source.
    IMFPresentationDescriptor *pPD,   // Presentation descriptor.
    IMFStreamDescriptor *pSD,         // Stream descriptor.
    IMFTopologyNode **ppNode)         // Receives the node pointer.
{
<<<<<<< HEAD
    ComPtr<IMFTopologyNode> pNode = NULL;
=======
    _ComPtr<IMFTopologyNode> pNode = NULL;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    HRESULT hr = S_OK;
    CHECK_HR(hr = MFCreateTopologyNode(MF_TOPOLOGY_SOURCESTREAM_NODE, pNode.GetAddressOf()));
    CHECK_HR(hr = pNode->SetUnknown(MF_TOPONODE_SOURCE, pSource));
    CHECK_HR(hr = pNode->SetUnknown(MF_TOPONODE_PRESENTATION_DESCRIPTOR, pPD));
    CHECK_HR(hr = pNode->SetUnknown(MF_TOPONODE_STREAM_DESCRIPTOR, pSD));
    CHECK_HR(hr = pTopology->AddNode(pNode.Get()));
    // Return the pointer to the caller.
    *ppNode = pNode.Get();
    (*ppNode)->AddRef();

done:
    return hr;
}

HRESULT ImageGrabber::AddOutputNode(
    IMFTopology *pTopology,     // Topology.
    IMFActivate *pActivate,     // Media sink activation object.
    DWORD dwId,                 // Identifier of the stream sink.
    IMFTopologyNode **ppNode)   // Receives the node pointer.
{
<<<<<<< HEAD
    ComPtr<IMFTopologyNode> pNode = NULL;
=======
    _ComPtr<IMFTopologyNode> pNode = NULL;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    HRESULT hr = S_OK;
    CHECK_HR(hr = MFCreateTopologyNode(MF_TOPOLOGY_OUTPUT_NODE, pNode.GetAddressOf()));
    CHECK_HR(hr = pNode->SetObject(pActivate));
    CHECK_HR(hr = pNode->SetUINT32(MF_TOPONODE_STREAMID, dwId));
    CHECK_HR(hr = pNode->SetUINT32(MF_TOPONODE_NOSHUTDOWN_ON_REMOVE, FALSE));
    CHECK_HR(hr = pTopology->AddNode(pNode.Get()));
    // Return the pointer to the caller.
    *ppNode = pNode.Get();
    (*ppNode)->AddRef();

done:
    return hr;
}

HRESULT ImageGrabber::CreateInstance(ImageGrabber **ppIG, unsigned int deviceID, bool synchronious)
{
    *ppIG = new (std::nothrow) ImageGrabber(deviceID, synchronious);
    if (ppIG == NULL)
    {
        return E_OUTOFMEMORY;
    }
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    DPO->printOut(L"IMAGEGRABBER VIDEODEVICE %i: Creating instance of ImageGrabber\n", deviceID);
=======
    DebugPrintOut(L"IMAGEGRABBER VIDEODEVICE %i: Creating instance of ImageGrabber\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    return S_OK;
}

STDMETHODIMP ImageGrabber::QueryInterface(REFIID riid, void** ppv)
{
    HRESULT hr = E_NOINTERFACE;
    *ppv = NULL;
    if(riid == IID_IUnknown || riid == IID_IMFSampleGrabberSinkCallback)
    {
        *ppv = static_cast<IMFSampleGrabberSinkCallback *>(this);
        hr = S_OK;
    }
    if(riid == IID_IMFClockStateSink)
    {
        *ppv = static_cast<IMFClockStateSink *>(this);
        hr = S_OK;
    }
    if(SUCCEEDED(hr))
    {
        reinterpret_cast<IUnknown *>(*ppv)->AddRef();
    }
    return hr;
}

STDMETHODIMP_(ULONG) ImageGrabber::AddRef()
{
    return InterlockedIncrement(&m_cRef);
}

STDMETHODIMP_(ULONG) ImageGrabber::Release()
{
    ULONG cRef = InterlockedDecrement(&m_cRef);
    if (cRef == 0)
    {
        delete this;
    }
    return cRef;
}

<<<<<<< HEAD
STDMETHODIMP ImageGrabber::OnClockStart(MFTIME hnsSystemTime, LONGLONG llClockStartOffset)
=======
STDMETHODIMP ImageGrabberCallback::OnClockStart(MFTIME hnsSystemTime, LONGLONG llClockStartOffset)
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
{
    (void)hnsSystemTime;
    (void)llClockStartOffset;
    return S_OK;
}

<<<<<<< HEAD
STDMETHODIMP ImageGrabber::OnClockStop(MFTIME hnsSystemTime)
=======
STDMETHODIMP ImageGrabberCallback::OnClockStop(MFTIME hnsSystemTime)
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
{
    (void)hnsSystemTime;
    return S_OK;
}

<<<<<<< HEAD
STDMETHODIMP ImageGrabber::OnClockPause(MFTIME hnsSystemTime)
=======
STDMETHODIMP ImageGrabberCallback::OnClockPause(MFTIME hnsSystemTime)
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
{
    (void)hnsSystemTime;
    return S_OK;
}

<<<<<<< HEAD
STDMETHODIMP ImageGrabber::OnClockRestart(MFTIME hnsSystemTime)
=======
STDMETHODIMP ImageGrabberCallback::OnClockRestart(MFTIME hnsSystemTime)
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
{
    (void)hnsSystemTime;
    return S_OK;
}

<<<<<<< HEAD
STDMETHODIMP ImageGrabber::OnClockSetRate(MFTIME hnsSystemTime, float flRate)
=======
STDMETHODIMP ImageGrabberCallback::OnClockSetRate(MFTIME hnsSystemTime, float flRate)
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
{
    (void)flRate;
    (void)hnsSystemTime;
    return S_OK;
}

<<<<<<< HEAD
STDMETHODIMP ImageGrabber::OnSetPresentationClock(IMFPresentationClock* pClock)
=======
STDMETHODIMP ImageGrabberCallback::OnSetPresentationClock(IMFPresentationClock* pClock)
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
{
    (void)pClock;
    return S_OK;
}

<<<<<<< HEAD
STDMETHODIMP ImageGrabber::OnProcessSample(REFGUID guidMajorMediaType, DWORD dwSampleFlags,
=======
STDMETHODIMP ImageGrabberCallback::OnProcessSample(REFGUID guidMajorMediaType, DWORD dwSampleFlags,
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    LONGLONG llSampleTime, LONGLONG llSampleDuration, const BYTE * pSampleBuffer,
    DWORD dwSampleSize)
{
    (void)guidMajorMediaType;
    (void)llSampleTime;
    (void)dwSampleFlags;
    (void)llSampleDuration;
    (void)dwSampleSize;

    HANDLE tmp[] = {ig_hFinish, ig_hFrameGrabbed, NULL};

    DWORD status = WaitForMultipleObjects(2, tmp, FALSE, INFINITE);
    if (status == WAIT_OBJECT_0)
    {
<<<<<<< HEAD
        printf("OnProcessFrame called after ig_hFinish event\n");
=======
        DebugPrintOut(L"OnProcessFrame called after ig_hFinish event\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        return S_OK;
    }

    if(ig_RIE)
    {
        ig_RIFirst->fastCopy(pSampleBuffer);
        ig_RIOut = ig_RIFirst;
    }
    else
    {
        ig_RISecond->fastCopy(pSampleBuffer);
        ig_RIOut = ig_RISecond;
    }

    if (ig_Synchronous)
    {
        SetEvent(ig_hFrameReady);
    }
    else
    {
        ig_RIE = !ig_RIE;
    }

    return S_OK;
}

<<<<<<< HEAD
STDMETHODIMP ImageGrabber::OnShutdown()
=======
STDMETHODIMP ImageGrabberCallback::OnShutdown()
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
{
    SetEvent(ig_hFinish);
    return S_OK;
}

<<<<<<< HEAD
RawImage *ImageGrabber::getRawImage()
=======
RawImage *ImageGrabberCallback::getRawImage()
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
{
    return ig_RIOut;
}

DWORD WINAPI MainThreadFunction( LPVOID lpParam )
{
    ImageGrabberThread *pIGT = (ImageGrabberThread *)lpParam;
    pIGT->run();
    return 0;
}

HRESULT ImageGrabberThread::CreateInstance(ImageGrabberThread **ppIGT, IMFMediaSource *pSource, unsigned int deviceID, bool synchronious)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    *ppIGT = new (std::nothrow) ImageGrabberThread(pSource, deviceID, synchronious);
    if (ppIGT == NULL)
    {
        DPO->printOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Memory cannot be allocated\n", deviceID);
        return E_OUTOFMEMORY;
    }
    else
        DPO->printOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Creating of the instance of ImageGrabberThread\n", deviceID);
    return S_OK;
}

ImageGrabberThread::ImageGrabberThread(IMFMediaSource *pSource, unsigned int deviceID, bool synchronious):
=======
    *ppIGT = new (std::nothrow) ImageGrabberThread(pSource, deviceID, synchronious);
    if (ppIGT == NULL)
    {
        DebugPrintOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Memory cannot be allocated\n", deviceID);
        return E_OUTOFMEMORY;
    }
    else
        DebugPrintOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Creating of the instance of ImageGrabberThread\n", deviceID);
    return S_OK;
}

ImageGrabberThread::ImageGrabberThread(IMFMediaSource *pSource, unsigned int deviceID, bool synchronious) :
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    igt_func(NULL),
    igt_Handle(NULL),
    igt_stop(false)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
=======
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    HRESULT hr = ImageGrabber::CreateInstance(&igt_pImageGrabber, deviceID, synchronious);
    igt_DeviceID = deviceID;
    if(SUCCEEDED(hr))
    {
<<<<<<< HEAD
        hr = igt_pImageGrabber->initImageGrabber(pSource, MFVideoFormat_RGB24);
        if(!SUCCEEDED(hr))
        {
            DPO->printOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: There is a problem with initialization of the instance of the ImageGrabber class\n", deviceID);
        }
        else
        {
            DPO->printOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Initialization of instance of the ImageGrabber class\n", deviceID);
=======
        hr = igt_pImageGrabber->initImageGrabber(pSource);
        if(!SUCCEEDED(hr))
        {
            DebugPrintOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: There is a problem with initialization of the instance of the ImageGrabber class\n", deviceID);
        }
        else
        {
            DebugPrintOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Initialization of instance of the ImageGrabber class\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        }
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i There is a problem with creation of the instance of the ImageGrabber class\n", deviceID);
=======
        DebugPrintOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: There is a problem with creation of the instance of the ImageGrabber class\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
}

void ImageGrabberThread::setEmergencyStopEvent(void *userData, void(*func)(int, void *))
{
    if(func)
    {
        igt_func = func;
        igt_userData = userData;
    }
}

ImageGrabberThread::~ImageGrabberThread(void)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    DPO->printOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Destroing ImageGrabberThread\n", igt_DeviceID);
=======
    DebugPrintOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Destroing ImageGrabberThread\n", igt_DeviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    if (igt_Handle)
        WaitForSingleObject(igt_Handle, INFINITE);
    delete igt_pImageGrabber;
}

void ImageGrabberThread::stop()
{
    igt_stop = true;
    if(igt_pImageGrabber)
    {
        igt_pImageGrabber->stopGrabbing();
    }
}

void ImageGrabberThread::start()
{
    igt_Handle = CreateThread(
            NULL,                  // default security attributes
            0,                     // use default stack size
            MainThreadFunction,    // thread function name
            this,                  // argument to thread function
            0,                     // use default creation flags
            &igt_ThreadIdArray);   // returns the thread identifier
}

void ImageGrabberThread::run()
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    if(igt_pImageGrabber)
    {
        DPO->printOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Thread for grabbing images is started\n", igt_DeviceID);
        HRESULT hr = igt_pImageGrabber->startGrabbing();
        if(!SUCCEEDED(hr))
        {
            DPO->printOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: There is a problem with starting the process of grabbing\n", igt_DeviceID);
=======
    if(igt_pImageGrabber)
    {
        DebugPrintOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Thread for grabbing images is started\n", igt_DeviceID);
        HRESULT hr = igt_pImageGrabber->startGrabbing();
        if(!SUCCEEDED(hr))
        {
            DebugPrintOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: There is a problem with starting the process of grabbing\n", igt_DeviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        }
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i The thread is finished without execution of grabbing\n", igt_DeviceID);
    }
    if(!igt_stop)
    {
        DPO->printOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Emergency Stop thread\n", igt_DeviceID);
=======
        DebugPrintOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i The thread is finished without execution of grabbing\n", igt_DeviceID);
    }
    if(!igt_stop)
    {
        DebugPrintOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Emergency Stop thread\n", igt_DeviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        if(igt_func)
        {
            igt_func(igt_DeviceID, igt_userData);
        }
    }
    else
<<<<<<< HEAD
        DPO->printOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Finish thread\n", igt_DeviceID);
=======
        DebugPrintOut(L"IMAGEGRABBERTHREAD VIDEODEVICE %i: Finish thread\n", igt_DeviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
}

ImageGrabber *ImageGrabberThread::getImageGrabber()
{
    return igt_pImageGrabber;
}

Media_Foundation::Media_Foundation(void)
{
    HRESULT hr = MFStartup(MF_VERSION);
    if(!SUCCEEDED(hr))
    {
<<<<<<< HEAD
        DebugPrintOut *DPO = &DebugPrintOut::getInstance();
        DPO->printOut(L"MEDIA FOUNDATION: It cannot be created!!!\n");
=======
        DebugPrintOut(L"MEDIA FOUNDATION: It cannot be created!!!\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
}

Media_Foundation::~Media_Foundation(void)
{
    HRESULT hr = MFShutdown();
    if(!SUCCEEDED(hr))
    {
<<<<<<< HEAD
        DebugPrintOut *DPO = &DebugPrintOut::getInstance();
        DPO->printOut(L"MEDIA FOUNDATION: Resources cannot be released\n");
=======
        DebugPrintOut(L"MEDIA FOUNDATION: Resources cannot be released\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
}

bool Media_Foundation::buildListOfDevices()
{
    HRESULT hr = S_OK;
<<<<<<< HEAD
    ComPtr<IMFAttributes> pAttributes = NULL;
=======
#ifdef HAVE_WINRT
    videoDevices *vDs = &videoDevices::getInstance();
    hr = vDs->initDevices(WRL_ENUM_GET(_DeviceClass, DeviceClass, VideoCapture));
#else
    _ComPtr<IMFAttributes> pAttributes = NULL;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    CoInitialize(NULL);
    hr = MFCreateAttributes(pAttributes.GetAddressOf(), 1);
    if (SUCCEEDED(hr))
    {
        hr = pAttributes->SetGUID(
            MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE,
            MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID
            );
    }
    if (SUCCEEDED(hr))
    {
        videoDevices *vDs = &videoDevices::getInstance();
        hr = vDs->initDevices(pAttributes.Get());
    }
<<<<<<< HEAD
    else
    {
       DebugPrintOut *DPO = &DebugPrintOut::getInstance();
       DPO->printOut(L"MEDIA FOUNDATION: The access to the video cameras denied\n");
=======
#endif
    if (FAILED(hr))
    {
       DebugPrintOut(L"MEDIA FOUNDATION: The access to the video cameras denied\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }

    return (SUCCEEDED(hr));
}

Media_Foundation& Media_Foundation::getInstance()
{
    static Media_Foundation instance;
    return instance;
}

RawImage::RawImage(unsigned int size): ri_new(false), ri_pixels(NULL)
{
    ri_size = size;
    ri_pixels = new unsigned char[size];
    memset((void *)ri_pixels,0,ri_size);
}

bool RawImage::isNew()
{
    return ri_new;
}

unsigned int RawImage::getSize()
{
    return ri_size;
}

RawImage::~RawImage(void)
{
    delete []ri_pixels;
    ri_pixels = NULL;
}

long RawImage::CreateInstance(RawImage **ppRImage,unsigned int size)
{
    *ppRImage = new (std::nothrow) RawImage(size);
    if (ppRImage == NULL)
    {
        return E_OUTOFMEMORY;
    }
    return S_OK;
}

void RawImage::setCopy(const BYTE * pSampleBuffer)
{
    memcpy(ri_pixels, pSampleBuffer, ri_size);
    ri_new = true;
}

void RawImage::fastCopy(const BYTE * pSampleBuffer)
{
    memcpy(ri_pixels, pSampleBuffer, ri_size);
    ri_new = true;
}

unsigned char * RawImage::getpPixels()
{
    ri_new = false;
    return ri_pixels;
}

videoDevice::videoDevice(void): vd_IsSetuped(false), vd_LockOut(OpenLock), vd_pFriendlyName(NULL),
<<<<<<< HEAD
    vd_Width(0), vd_Height(0), vd_pSource(NULL), vd_func(NULL), vd_userData(NULL)
{
=======
    vd_Width(0), vd_Height(0), vd_FrameRate(0), vd_pSource(NULL), vd_pImGrTh(NULL), vd_func(NULL), vd_userData(NULL)
{
#ifdef HAVE_WINRT
    vd_pMedCap = nullptr;
    vd_cookie.value = 0;
    vd_pImGr = NULL;
#endif
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
}

void videoDevice::setParametrs(CamParametrs parametrs)
{
    if(vd_IsSetuped)
    {
        if(vd_pSource)
        {
            Parametr *pParametr = (Parametr *)(&parametrs);
            Parametr *pPrevParametr = (Parametr *)(&vd_PrevParametrs);
            IAMVideoProcAmp *pProcAmp = NULL;
            HRESULT hr = vd_pSource->QueryInterface(IID_PPV_ARGS(&pProcAmp));
            if (SUCCEEDED(hr))
            {
                for(unsigned int i = 0; i < 10; i++)
                {
                    if(pPrevParametr[i].CurrentValue != pParametr[i].CurrentValue || pPrevParametr[i].Flag != pParametr[i].Flag)
                        hr = pProcAmp->Set(VideoProcAmp_Brightness + i, pParametr[i].CurrentValue, pParametr[i].Flag);
                }
                pProcAmp->Release();
            }
            IAMCameraControl *pProcControl = NULL;
            hr = vd_pSource->QueryInterface(IID_PPV_ARGS(&pProcControl));
            if (SUCCEEDED(hr))
            {
                for(unsigned int i = 0; i < 7; i++)
                {
                    if(pPrevParametr[10 + i].CurrentValue != pParametr[10 + i].CurrentValue || pPrevParametr[10 + i].Flag != pParametr[10 + i].Flag)
                    hr = pProcControl->Set(CameraControl_Pan+i, pParametr[10 + i].CurrentValue, pParametr[10 + i].Flag);
                }
                pProcControl->Release();
            }
            vd_PrevParametrs = parametrs;
        }
    }
}

CamParametrs videoDevice::getParametrs()
{
    CamParametrs out;
    if(vd_IsSetuped)
    {
        if(vd_pSource)
        {
            Parametr *pParametr = (Parametr *)(&out);
            IAMVideoProcAmp *pProcAmp = NULL;
            HRESULT hr = vd_pSource->QueryInterface(IID_PPV_ARGS(&pProcAmp));
            if (SUCCEEDED(hr))
            {
                for(unsigned int i = 0; i < 10; i++)
                {
                    Parametr temp;
                    hr = pProcAmp->GetRange(VideoProcAmp_Brightness+i, &temp.Min, &temp.Max, &temp.Step, &temp.Default, &temp.Flag);
                    if (SUCCEEDED(hr))
                    {
                        temp.CurrentValue = temp.Default;
                        pParametr[i] = temp;
                    }
                }
                pProcAmp->Release();
            }
            IAMCameraControl *pProcControl = NULL;
            hr = vd_pSource->QueryInterface(IID_PPV_ARGS(&pProcControl));
            if (SUCCEEDED(hr))
            {
                for(unsigned int i = 0; i < 7; i++)
                {
                    Parametr temp;
                    hr = pProcControl->GetRange(CameraControl_Pan+i, &temp.Min, &temp.Max, &temp.Step, &temp.Default, &temp.Flag);
                    if (SUCCEEDED(hr))
                    {
                        temp.CurrentValue = temp.Default;
                        pParametr[10 + i] = temp;
                    }
                }
                pProcControl->Release();
            }
        }
    }
    return out;
}

<<<<<<< HEAD
long videoDevice::resetDevice(IMFActivate *pActivate)
{
    HRESULT hr = -1;
=======
#ifdef HAVE_WINRT
long videoDevice::resetDevice(MAKE_WRL_REF(_IDeviceInformation) pDevice)
#else
long videoDevice::resetDevice(IMFActivate *pActivate)
#endif
{
    HRESULT hr = E_FAIL;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    vd_CurrentFormats.clear();
    if(vd_pFriendlyName)
        CoTaskMemFree(vd_pFriendlyName);
    vd_pFriendlyName = NULL;
<<<<<<< HEAD
=======
#ifdef HAVE_WINRT
    if (pDevice)
    {
        ACTIVATE_OBJ(RuntimeClass_Windows_Media_Capture_MediaCapture, _MediaCapture, pIMedCap, hr)
        if (FAILED(hr)) return hr;
        ACTIVATE_OBJ(RuntimeClass_Windows_Media_Capture_MediaCaptureInitializationSettings, _MediaCaptureInitializationSettings, pCapInitSet, hr)
        if (FAILED(hr)) return hr;
        _StringObj str;
        WRL_PROP_GET(pDevice, Name, *REF_WRL_OBJ(str), hr)
        if (FAILED(hr)) return hr;
        unsigned int length = 0;
        PCWSTR wstr = WindowsGetStringRawBuffer(reinterpret_cast<HSTRING>(DEREF_WRL_OBJ(str)), &length);
        vd_pFriendlyName = (wchar_t*)CoTaskMemAlloc((length + 1) * sizeof(wchar_t));
        wcscpy(vd_pFriendlyName, wstr);
        WRL_PROP_GET(pDevice, Id, *REF_WRL_OBJ(str), hr)
        if (FAILED(hr)) return hr;
        WRL_PROP_PUT(pCapInitSet, VideoDeviceId, DEREF_WRL_OBJ(str), hr)
        if (FAILED(hr)) return hr;
        WRL_PROP_PUT(pCapInitSet, StreamingCaptureMode, WRL_ENUM_GET(_StreamingCaptureMode, StreamingCaptureMode, Video), hr)
        if (FAILED(hr)) return hr;
        MAKE_WRL_REF(_AsyncAction) pAction;
        WRL_METHOD(DEREF_WRL_OBJ(pIMedCap), _InitializeWithSettingsAsync, pAction, hr, DEREF_WRL_OBJ(pCapInitSet))
#ifdef HAVE_CONCURRENCY
        if (FAILED(hr)) return hr;
        MAKE_WRL_AGILE_OBJ(_MediaCapture) pAgileMedCap;
        pAgileMedCap = PREPARE_TRANSFER_WRL_OBJ(pIMedCap);
        SAVE_CURRENT_CONTEXT(context);
        DEFINE_TASK<void> task = CREATE_TASK DEFINE_RET_TYPE(void)(pAction);
        auto func = [task]() { task.wait(); RET_VAL_BASE };
        CREATE_OR_CONTINUE_TASK(vd_pAction, void, func);
        vd_pAction = vd_pAction.then([context, pAgileMedCap, this]()->DEFINE_RET_FORMAL(void) {
            HRESULT hr = S_OK;
            if (SUCCEEDED(hr)) {
                //all camera capture calls only in original context
                BEGIN_CALL_IN_CONTEXT(hr, context, pAgileMedCap, this)
                    enumerateCaptureFormats(DEREF_AGILE_WRL_MADE_OBJ(pAgileMedCap));
                END_CALL_IN_CONTEXT_BASE
            }
            buildLibraryofTypes();
            RET_VAL_BASE
        });
#endif
    }
#else
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    if(pActivate)
    {
        IMFMediaSource *pSource = NULL;
        hr = pActivate->GetAllocatedString(
                MF_DEVSOURCE_ATTRIBUTE_FRIENDLY_NAME,
                &vd_pFriendlyName,
                NULL
                );
        hr = pActivate->ActivateObject(
            __uuidof(IMFMediaSource),
            (void**)&pSource
            );
        enumerateCaptureFormats(pSource);
        buildLibraryofTypes();
        SafeRelease(&pSource);
        if(FAILED(hr))
        {
            vd_pFriendlyName = NULL;
<<<<<<< HEAD
            DebugPrintOut *DPO = &DebugPrintOut::getInstance();
            DPO->printOut(L"VIDEODEVICE %i: IMFMediaSource interface cannot be created \n", vd_CurrentNumber);
        }
    }
    return hr;
}

long videoDevice::readInfoOfDevice(IMFActivate *pActivate, unsigned int Num)
{
    HRESULT hr = -1;
    vd_CurrentNumber = Num;
    hr = resetDevice(pActivate);
    return hr;
}

long videoDevice::checkDevice(IMFAttributes *pAttributes, IMFActivate **pDevice)
{
    HRESULT hr = S_OK;
    IMFActivate **ppDevices = NULL;
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    UINT32 count;
    wchar_t *newFriendlyName = NULL;
    hr = MFEnumDeviceSources(pAttributes, &ppDevices, &count);
=======
            DebugPrintOut(L"VIDEODEVICE %i: IMFMediaSource interface cannot be created \n", vd_CurrentNumber);
        }
    }
#endif
    return hr;
}

#ifdef HAVE_WINRT
long videoDevice::readInfoOfDevice(MAKE_WRL_REF(_IDeviceInformation) pDevice, unsigned int Num)
{
    HRESULT hr = -1;
    vd_CurrentNumber = Num;
    hr = resetDevice(pDevice);
    return hr;
}
#else
long videoDevice::readInfoOfDevice(IMFActivate *pActivate, unsigned int Num)
{
    vd_CurrentNumber = Num;
    return resetDevice(pActivate);
}
#endif

#ifdef HAVE_WINRT
#ifdef HAVE_CONCURRENCY
long videoDevice::checkDevice(_DeviceClass devClass, DEFINE_TASK<void>* pTask, MAKE_WRL_REF(_IDeviceInformation)* ppDevice)
{
    HRESULT hr = S_OK;
    ACTIVATE_STATIC_OBJ(RuntimeClass_Windows_Devices_Enumeration_DeviceInformation, MAKE_WRL_OBJ(_DeviceInformationStatics), pDevStat, hr)
    if (FAILED(hr)) return hr;
    MAKE_WRL_REF(_AsyncOperation<MAKE_WRL_REF(_DeviceInformationCollection)>) pAction;
    WRL_METHOD(pDevStat, _FindAllAsyncDeviceClass, pAction, hr, devClass)
    if (SUCCEEDED(hr)) {
        *pTask = CREATE_TASK DEFINE_RET_TYPE(void)([pAction, &ppDevice, this]() -> DEFINE_RET_FORMAL(void) {
            HRESULT hr = S_OK;
            MAKE_WRL_OBJ(_VectorView<MAKE_WRL_REF(_DeviceInformation)>) pVector =
                CREATE_TASK DEFINE_RET_TYPE(MAKE_WRL_REF(_VectorView<MAKE_WRL_REF(_DeviceInformation)>))(pAction).get();
            UINT32 count = 0;
            if (SUCCEEDED(hr)) WRL_PROP_GET(pVector, Size, count, hr)
            if (SUCCEEDED(hr) && count > 0) {
                for (UINT32 i = 0; i < count; i++) {
                    MAKE_WRL_OBJ(_IDeviceInformation) pDevice;
                    WRL_METHOD(pVector, GetAt, pDevice, hr, i)
                    if (SUCCEEDED(hr)) {
                        _StringObj str;
                        unsigned int length = 0;
                        WRL_PROP_GET(pDevice, Name, *REF_WRL_OBJ(str), hr)
                        PCWSTR wstr = WindowsGetStringRawBuffer(reinterpret_cast<HSTRING>(DEREF_WRL_OBJ(str)), &length);
                        if (wcscmp(wstr, vd_pFriendlyName) == 0) {
                            *ppDevice = PREPARE_TRANSFER_WRL_OBJ(pDevice);
                        }
                    }
                }
            }
            RET_VAL_BASE;
        });
    }
    return hr;
}
#endif
#else
long videoDevice::checkDevice(IMFAttributes *pAttributes, IMFActivate **pDevice)
{
    IMFActivate **ppDevices = NULL;
    UINT32 count;
    wchar_t *newFriendlyName = NULL;
    HRESULT hr = MFEnumDeviceSources(pAttributes, &ppDevices, &count);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    if (SUCCEEDED(hr))
    {
        if(count > 0)
        {
            if(count > vd_CurrentNumber)
            {
                hr = ppDevices[vd_CurrentNumber]->GetAllocatedString(
                MF_DEVSOURCE_ATTRIBUTE_FRIENDLY_NAME,
                &newFriendlyName,
                NULL
                );
                if (SUCCEEDED(hr))
                {
                    if(wcscmp(newFriendlyName, vd_pFriendlyName) != 0)
                    {
<<<<<<< HEAD
                        DPO->printOut(L"VIDEODEVICE %i: Chosen device cannot be found \n", vd_CurrentNumber);
                        hr = -1;
=======
                        DebugPrintOut(L"VIDEODEVICE %i: Chosen device cannot be found \n", vd_CurrentNumber);
                        hr = E_INVALIDARG;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
                        pDevice = NULL;
                    }
                    else
                    {
                        *pDevice = ppDevices[vd_CurrentNumber];
                        (*pDevice)->AddRef();
                    }
                }
                else
                {
<<<<<<< HEAD
                    DPO->printOut(L"VIDEODEVICE %i: Name of device cannot be gotten \n", vd_CurrentNumber);
=======
                    DebugPrintOut(L"VIDEODEVICE %i: Name of device cannot be gotten \n", vd_CurrentNumber);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
                }
            }
            else
            {
<<<<<<< HEAD
                DPO->printOut(L"VIDEODEVICE %i: Number of devices more than corrent number of the device \n", vd_CurrentNumber);
                hr = -1;
=======
                DebugPrintOut(L"VIDEODEVICE %i: Number of devices more than corrent number of the device \n", vd_CurrentNumber);
                hr = E_INVALIDARG;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
            }
            for(UINT32 i = 0; i < count; i++)
            {
                SafeRelease(&ppDevices[i]);
            }
            SafeRelease(ppDevices);
        }
        else
<<<<<<< HEAD
            hr = -1;
    }
    else
    {
        DPO->printOut(L"VIDEODEVICE %i: List of DeviceSources cannot be enumerated \n", vd_CurrentNumber);
    }
    return hr;
}

long videoDevice::initDevice()
{
    HRESULT hr = -1;
    ComPtr<IMFAttributes> pAttributes = NULL;
    IMFActivate *vd_pActivate = NULL;
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    CoInitialize(NULL);
=======
            hr = E_FAIL;
    }
    else
    {
        DebugPrintOut(L"VIDEODEVICE %i: List of DeviceSources cannot be enumerated \n", vd_CurrentNumber);
    }
    return hr;
}
#endif

long videoDevice::initDevice()
{
    HRESULT hr = S_OK;
    CoInitialize(NULL);
#ifdef HAVE_WINRT
#ifdef HAVE_CONCURRENCY
    SAVE_CURRENT_CONTEXT(context);
    auto func = [context, this]()->DEFINE_RET_FORMAL(void) {
        HRESULT hr;
        DEFINE_TASK<void> pTask;
        MAKE_WRL_OBJ(_IDeviceInformation) pDevInfo;
        hr = checkDevice(WRL_ENUM_GET(_DeviceClass, DeviceClass, VideoCapture), &pTask, REF_WRL_OBJ(pDevInfo));
        if (SUCCEEDED(hr)) pTask.wait();
        if (SUCCEEDED(hr)) {
            DEFINE_TASK<void> _task;
            BEGIN_CALL_IN_CONTEXT(hr, context, pDevInfo, &_task, context, this)
                HRESULT hr;
            ACTIVATE_OBJ(RuntimeClass_Windows_Media_Capture_MediaCapture, _MediaCapture, pIMedCap, hr)
                if (SUCCEEDED(hr)) {
                RELEASE_WRL(vd_pMedCap);
                vd_pMedCap = PREPARE_TRANSFER_WRL_OBJ(pIMedCap);
                ACTIVATE_OBJ(RuntimeClass_Windows_Media_Capture_MediaCaptureInitializationSettings, _MediaCaptureInitializationSettings, pCapInitSet, hr)
                    _StringObj str;
                if (SUCCEEDED(hr)) {
                    WRL_PROP_GET(pDevInfo, Id, *REF_WRL_OBJ(str), hr)
                        if (SUCCEEDED(hr)) {
                        WRL_PROP_PUT(pCapInitSet, VideoDeviceId, DEREF_WRL_OBJ(str), hr)
                        }
                }
                if (SUCCEEDED(hr))
                    WRL_PROP_PUT(pCapInitSet, StreamingCaptureMode, WRL_ENUM_GET(_StreamingCaptureMode, StreamingCaptureMode, Video), hr)
                    if (SUCCEEDED(hr)) reinterpret_cast<ABI::Windows::Media::Capture::IMediaCapture*>(DEREF_AGILE_WRL_OBJ(vd_pMedCap))->add_Failed(Microsoft::WRL::Callback<ABI::Windows::Media::Capture::IMediaCaptureFailedEventHandler>([this, context](ABI::Windows::Media::Capture::IMediaCapture*, ABI::Windows::Media::Capture::IMediaCaptureFailedEventArgs*) -> HRESULT {
                    HRESULT hr;
                    BEGIN_CALL_IN_CONTEXT(hr, context, this)
                        closeDevice();
                    END_CALL_IN_CONTEXT_BASE
                        return hr;
                    }).Get(), &vd_cookie);
                MAKE_WRL_OBJ(_AsyncAction) pAction;
                if (SUCCEEDED(hr)) WRL_METHOD(vd_pMedCap, _InitializeWithSettingsAsync, *REF_WRL_OBJ(pAction), hr, DEREF_WRL_OBJ(pCapInitSet))
                    if (SUCCEEDED(hr)) _task = CREATE_TASK DEFINE_RET_TYPE(void)(DEREF_WRL_OBJ(pAction));
                }
            END_CALL_IN_CONTEXT(hr)
                _task.wait();
        }
        RET_VAL_BASE
    };
    CREATE_OR_CONTINUE_TASK(vd_pAction, void, func);
#endif
#else
    _ComPtr<IMFAttributes> pAttributes = NULL;
    IMFActivate *vd_pActivate = NULL;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    hr = MFCreateAttributes(pAttributes.GetAddressOf(), 1);
    if (SUCCEEDED(hr))
    {
        hr = pAttributes->SetGUID(
            MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE,
            MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID
            );
    }
    if (SUCCEEDED(hr))
    {
        hr = checkDevice(pAttributes.Get(), &vd_pActivate);
        if (SUCCEEDED(hr) && vd_pActivate)
        {
            SafeRelease(&vd_pSource);
            hr = vd_pActivate->ActivateObject(
                __uuidof(IMFMediaSource),
                (void**)&vd_pSource
                );
            if (SUCCEEDED(hr))
            {
            }
            SafeRelease(&vd_pActivate);
        }
        else
        {
<<<<<<< HEAD
            DPO->printOut(L"VIDEODEVICE %i: Device there is not \n", vd_CurrentNumber);
=======
            DebugPrintOut(L"VIDEODEVICE %i: Device there is not \n", vd_CurrentNumber);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        }
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"VIDEODEVICE %i: The attribute of video cameras cannot be getting \n", vd_CurrentNumber);
    }

=======
        DebugPrintOut(L"VIDEODEVICE %i: The attribute of video cameras cannot be getting \n", vd_CurrentNumber);
    }
#endif
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    return hr;
}

MediaType videoDevice::getFormat(unsigned int id)
{
    if(id < vd_CurrentFormats.size())
    {
        return vd_CurrentFormats[id];
    }
    else return MediaType();
}
int videoDevice::getCountFormats()
{
<<<<<<< HEAD
    return vd_CurrentFormats.size();
=======
    return (int)vd_CurrentFormats.size();
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
}
void videoDevice::setEmergencyStopEvent(void *userData, void(*func)(int, void *))
{
    vd_func = func;
    vd_userData = userData;
}
void videoDevice::closeDevice()
{
    if(vd_IsSetuped)
    {
        vd_IsSetuped = false;
<<<<<<< HEAD
        vd_pSource->Stop();
=======

#ifdef HAVE_WINRT
#ifdef HAVE_CONCURRENCY
        if (DEREF_AGILE_WRL_OBJ(vd_pMedCap)) {
            MAKE_WRL_REF(_AsyncAction) action;
            vd_pImGr->stopGrabbing(&action);
            reinterpret_cast<ABI::Windows::Media::Capture::IMediaCapture*>(DEREF_AGILE_WRL_OBJ(vd_pMedCap))->remove_Failed(vd_cookie);
            vd_cookie.value = 0;
            DEFINE_TASK<void> task = CREATE_TASK DEFINE_RET_TYPE(void)(action);
            auto func = [task]() { task.wait(); RET_VAL_BASE };
            CREATE_OR_CONTINUE_TASK(vd_pAction, void, func);
            vd_pAction = vd_pAction.then([this]()->DEFINE_RET_FORMAL(void) {
                RELEASE_WRL(vd_pMedCap)
                    if (vd_LockOut == RawDataLock) {
                    delete vd_pImGr;
                    }
                vd_pImGr = NULL;
                vd_LockOut = OpenLock;
                RET_VAL_BASE
            });
            return;
        }
#endif
#endif

        vd_pSource->Shutdown();
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        SafeRelease(&vd_pSource);
        if(vd_LockOut == RawDataLock)
        {
            vd_pImGrTh->stop();
            Sleep(500);
            delete vd_pImGrTh;
        }
        vd_pImGrTh = NULL;
        vd_LockOut = OpenLock;
<<<<<<< HEAD
        DebugPrintOut *DPO = &DebugPrintOut::getInstance();
        DPO->printOut(L"VIDEODEVICE %i: Device is stopped \n", vd_CurrentNumber);
=======
        DebugPrintOut(L"VIDEODEVICE %i: Device is stopped \n", vd_CurrentNumber);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
}
unsigned int videoDevice::getWidth()
{
    if(vd_IsSetuped)
        return vd_Width;
    else
        return 0;
}
unsigned int videoDevice::getHeight()
{
    if(vd_IsSetuped)
        return vd_Height;
    else
        return 0;
}
<<<<<<< HEAD
=======

unsigned int videoDevice::getFrameRate() const
{
    if(vd_IsSetuped)
        return vd_FrameRate;
    else
        return 0;
}

>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
IMFMediaSource *videoDevice::getMediaSource()
{
    IMFMediaSource *out = NULL;
    if(vd_LockOut == OpenLock)
    {
        vd_LockOut = MediaSourceLock;
        out = vd_pSource;
    }
    return out;
}
int videoDevice::findType(unsigned int size, unsigned int frameRate)
{
<<<<<<< HEAD
    if(vd_CaptureFormats.size() == 0)
        return 0;
    FrameRateMap FRM = vd_CaptureFormats[size];
    if(FRM.size() == 0)
        return 0;
=======
    // For required frame size look for the suitable video format.
    // If not found, get the format for the largest available frame size.
    FrameRateMap FRM;
    std::map<UINT64, FrameRateMap>::const_iterator fmt;
    fmt = vd_CaptureFormats.find(size);
    if( fmt != vd_CaptureFormats.end() )
        FRM = fmt->second;
    else if(!vd_CaptureFormats.empty())
        FRM = vd_CaptureFormats.rbegin()->second;

    if (FRM.empty())
        return -1;

>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    UINT64 frameRateMax = 0;  SUBTYPEMap STMMax;
    if(frameRate == 0)
    {
        std::map<UINT64, SUBTYPEMap>::iterator f = FRM.begin();
        for(; f != FRM.end(); f++)
        {
<<<<<<< HEAD
=======
            // Looking for highest possible frame rate.
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
             if((*f).first >= frameRateMax)
             {
                 frameRateMax = (*f).first;
                 STMMax = (*f).second;
             }
        }
    }
    else
    {
        std::map<UINT64, SUBTYPEMap>::iterator f = FRM.begin();
        for(; f != FRM.end(); f++)
        {
<<<<<<< HEAD
             if((*f).first >= frameRateMax)
             {
                 if(frameRate > (*f).first)
                 {
                     frameRateMax = (*f).first;
                     STMMax = (*f).second;
                 }
             }
        }
    }
    if(STMMax.size() == 0)
        return 0;
    std::map<String, vectorNum>::iterator S = STMMax.begin();
    vectorNum VN = (*S).second;
    if(VN.size() == 0)
        return 0;
=======
            // Looking for frame rate higher that recently found but not higher then demanded.
            if( (*f).first >= frameRateMax && (*f).first <= frameRate )
            {
                frameRateMax = (*f).first;
                STMMax = (*f).second;
            }
        }
    }
    // Get first (default) item from the list if no suitable frame rate found.
    if( STMMax.empty() )
        STMMax = FRM.begin()->second;

    // Check if there are any format types on the list.
    if( STMMax.empty() )
        return -1;

    vectorNum VN = STMMax.begin()->second;
    if( VN.empty() )
        return -1;

>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    return VN[0];
}

void videoDevice::buildLibraryofTypes()
{
    unsigned int size;
    unsigned int framerate;
    std::vector<MediaType>::iterator i = vd_CurrentFormats.begin();
    int count = 0;
    for(; i != vd_CurrentFormats.end(); i++)
    {
<<<<<<< HEAD
        size = (*i).MF_MT_FRAME_SIZE;
        framerate = (*i).MF_MT_FRAME_RATE_NUMERATOR;
        FrameRateMap FRM = vd_CaptureFormats[size];
        SUBTYPEMap STM = FRM[framerate];
        String subType((*i).pMF_MT_SUBTYPEName);
        vectorNum VN = STM[subType];
        VN.push_back(count);
        STM[subType] = VN;
        FRM[framerate] = STM;
        vd_CaptureFormats[size] = FRM;
=======
        // Count only supported video formats.
        if( (*i).MF_MT_SUBTYPE == MFVideoFormat_RGB24 )
        {
            size = (*i).MF_MT_FRAME_SIZE;
            framerate = (*i).MF_MT_FRAME_RATE_NUMERATOR / (*i).MF_MT_FRAME_RATE_DENOMINATOR;
            FrameRateMap FRM = vd_CaptureFormats[size];
            SUBTYPEMap STM = FRM[framerate];
            String subType((*i).pMF_MT_SUBTYPEName);
            vectorNum VN = STM[subType];
            VN.push_back(count);
            STM[subType] = VN;
            FRM[framerate] = STM;
            vd_CaptureFormats[size] = FRM;
        }
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        count++;
    }
}

<<<<<<< HEAD
long videoDevice::setDeviceFormat(IMFMediaSource *pSource, unsigned long  dwFormatIndex)
{
    ComPtr<IMFPresentationDescriptor> pPD = NULL;
    ComPtr<IMFStreamDescriptor> pSD = NULL;
    ComPtr<IMFMediaTypeHandler> pHandler = NULL;
    ComPtr<IMFMediaType> pType = NULL;
=======
#ifdef HAVE_WINRT
long videoDevice::setDeviceFormat(MAKE_WRL_REF(_MediaCapture) pSource, unsigned long  dwFormatIndex, MAKE_WRL_REF(_AsyncAction)* pAction)
{
    HRESULT hr;
    MAKE_WRL_OBJ(_VideoDeviceController) pDevCont;
    WRL_PROP_GET(pSource, VideoDeviceController, pDevCont, hr)
    if (FAILED(hr)) return hr;
    GET_WRL_OBJ_FROM_OBJ(_MediaDeviceController, pMedDevCont, pDevCont, hr)
    if (FAILED(hr)) return hr;
    MAKE_WRL_OBJ(_VectorView<MAKE_WRL_REF(_MediaEncodingProperties)>) pVector;
    WRL_METHOD(pMedDevCont, GetAvailableMediaStreamProperties, pVector, hr, WRL_ENUM_GET(_MediaStreamType, MediaStreamType, VideoPreview))
    if (FAILED(hr)) return hr;
    MAKE_WRL_OBJ(_MediaEncodingProperties) pMedEncProps;
    WRL_METHOD(pVector, GetAt, pMedEncProps, hr, dwFormatIndex)
    if (FAILED(hr)) return hr;
    WRL_METHOD(pMedDevCont, SetMediaStreamPropertiesAsync, *pAction, hr, WRL_ENUM_GET(_MediaStreamType, MediaStreamType, VideoPreview), DEREF_WRL_OBJ(pMedEncProps))
    return hr;
}
#endif

long videoDevice::setDeviceFormat(IMFMediaSource *pSource, unsigned long  dwFormatIndex)
{
    _ComPtr<IMFPresentationDescriptor> pPD = NULL;
    _ComPtr<IMFStreamDescriptor> pSD = NULL;
    _ComPtr<IMFMediaTypeHandler> pHandler = NULL;
    _ComPtr<IMFMediaType> pType = NULL;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    HRESULT hr = pSource->CreatePresentationDescriptor(pPD.GetAddressOf());
    if (FAILED(hr))
    {
        goto done;
    }
    BOOL fSelected;
    hr = pPD->GetStreamDescriptorByIndex(0, &fSelected, pSD.GetAddressOf());
    if (FAILED(hr))
    {
        goto done;
    }
    hr = pSD->GetMediaTypeHandler(pHandler.GetAddressOf());
    if (FAILED(hr))
    {
        goto done;
    }
    hr = pHandler->GetMediaTypeByIndex((DWORD)dwFormatIndex, pType.GetAddressOf());
    if (FAILED(hr))
    {
        goto done;
    }
    hr = pHandler->SetCurrentMediaType(pType.Get());

done:
    return hr;
}

bool videoDevice::isDeviceSetup()
{
    return vd_IsSetuped;
}

RawImage * videoDevice::getRawImageOut()
{
    if(!vd_IsSetuped) return NULL;
<<<<<<< HEAD
=======
#ifdef HAVE_WINRT
    if(vd_pImGr) return vd_pImGr->getRawImage();
#endif
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    if(vd_pImGrTh)
            return vd_pImGrTh->getImageGrabber()->getRawImage();
    else
    {
<<<<<<< HEAD
        DebugPrintOut *DPO = &DebugPrintOut::getInstance();
        DPO->printOut(L"VIDEODEVICE %i: The instance of ImageGrabberThread class does not exist  \n", vd_CurrentNumber);
=======
        DebugPrintOut(L"VIDEODEVICE %i: The instance of ImageGrabberThread class does not exist  \n", vd_CurrentNumber);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
    return NULL;
}

bool videoDevice::isFrameNew()
{
    if(!vd_IsSetuped) return false;
    if(vd_LockOut == RawDataLock || vd_LockOut == OpenLock)
    {
        if(vd_LockOut == OpenLock)
        {
            vd_LockOut = RawDataLock;
<<<<<<< HEAD
            HRESULT hr = ImageGrabberThread::CreateInstance(&vd_pImGrTh, vd_pSource, vd_CurrentNumber);
            if(FAILED(hr))
            {
                DebugPrintOut *DPO = &DebugPrintOut::getInstance();
                DPO->printOut(L"VIDEODEVICE %i: The instance of ImageGrabberThread class cannot be created.\n", vd_CurrentNumber);
=======

            //must already be closed
#ifdef HAVE_WINRT
            if (DEREF_AGILE_WRL_OBJ(vd_pMedCap)) {
                MAKE_WRL_REF(_AsyncAction) action;
                if (FAILED(ImageGrabberWinRT::CreateInstance(&vd_pImGr))) return false;
                if (FAILED(vd_pImGr->initImageGrabber(DEREF_AGILE_WRL_OBJ(vd_pMedCap), MFVideoFormat_RGB24)) || FAILED(vd_pImGr->startGrabbing(&action))) {
                    delete vd_pImGr;
                    return false;
                }
#ifdef HAVE_CONCURRENCY
                DEFINE_TASK<void> task = CREATE_TASK DEFINE_RET_TYPE(void)(action);
                auto func = [task]() { task.wait(); RET_VAL_BASE };
                CREATE_OR_CONTINUE_TASK(vd_pAction, void, func);
#endif
                return true;
            }
#endif
            HRESULT hr = ImageGrabberThread::CreateInstance(&vd_pImGrTh, vd_pSource, vd_CurrentNumber);
            if(FAILED(hr))
            {
                DebugPrintOut(L"VIDEODEVICE %i: The instance of ImageGrabberThread class cannot be created.\n", vd_CurrentNumber);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
                return false;
            }
            vd_pImGrTh->setEmergencyStopEvent(vd_userData, vd_func);
            vd_pImGrTh->start();
            return true;
        }
<<<<<<< HEAD
=======
#ifdef HAVE_WINRT
        if(vd_pImGr)
            return vd_pImGr->getRawImage()->isNew();
#endif
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        if(vd_pImGrTh)
            return vd_pImGrTh->getImageGrabber()->getRawImage()->isNew();
    }
    return false;
}

bool videoDevice::isDeviceMediaSource()
{
    if(vd_LockOut == MediaSourceLock) return true;
    return false;
}

bool videoDevice::isDeviceRawDataSource()
{
    if(vd_LockOut == RawDataLock) return true;
    return false;
}

bool videoDevice::setupDevice(unsigned int id)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    if(!vd_IsSetuped)
    {
        HRESULT hr = -1;
        hr = initDevice();
        if(SUCCEEDED(hr))
        {
            vd_Width = vd_CurrentFormats[id].width;
            vd_Height = vd_CurrentFormats[id].height;
            hr = setDeviceFormat(vd_pSource, (DWORD) id);
            vd_IsSetuped = (SUCCEEDED(hr));
            if(vd_IsSetuped)
                DPO->printOut(L"\n\nVIDEODEVICE %i: Device is setuped \n", vd_CurrentNumber);
            vd_PrevParametrs = getParametrs();
            return vd_IsSetuped;
        }
        else
        {
            DPO->printOut(L"VIDEODEVICE %i: Interface IMFMediaSource cannot be got \n", vd_CurrentNumber);
=======
    if(!vd_IsSetuped)
    {
        HRESULT hr = initDevice();
        if(SUCCEEDED(hr))
        {
#ifdef HAVE_WINRT
#ifdef HAVE_CONCURRENCY
            SAVE_CURRENT_CONTEXT(context);
            auto func = [context, id, this]()->DEFINE_RET_FORMAL(void) {
                HRESULT hr;
#endif
#endif
                vd_Width = vd_CurrentFormats[id].width;
                vd_Height = vd_CurrentFormats[id].height;
                vd_FrameRate = vd_CurrentFormats[id].MF_MT_FRAME_RATE_NUMERATOR /
                    vd_CurrentFormats[id].MF_MT_FRAME_RATE_DENOMINATOR;
#ifdef HAVE_WINRT
#ifdef HAVE_CONCURRENCY
                if (DEREF_AGILE_WRL_OBJ(vd_pMedCap)) {
                    DEFINE_TASK<void> _task;
                    BEGIN_CALL_IN_CONTEXT(hr, context, id, &_task, this)
                        MAKE_WRL_REF(_AsyncAction) pAction;
                    HRESULT hr = setDeviceFormat(DEREF_AGILE_WRL_OBJ(vd_pMedCap), (DWORD)id, &pAction);
                    if (SUCCEEDED(hr)) _task = CREATE_TASK DEFINE_RET_TYPE(void)(pAction);
                    END_CALL_IN_CONTEXT(hr)
                        if (SUCCEEDED(hr)) _task.wait();
                }
                else
#endif
#endif
                    hr = setDeviceFormat(vd_pSource, (DWORD)id);
                vd_IsSetuped = (SUCCEEDED(hr));
                if (vd_IsSetuped)
                    DebugPrintOut(L"\n\nVIDEODEVICE %i: Device is setuped \n", vd_CurrentNumber);
                vd_PrevParametrs = getParametrs();
#ifdef HAVE_WINRT
#ifdef HAVE_CONCURRENCY
                RET_VAL_BASE
            };
            CREATE_OR_CONTINUE_TASK(vd_pAction, void, func);
#endif
            return true;
#else
            return vd_IsSetuped;
#endif
        }
        else
        {
            DebugPrintOut(L"VIDEODEVICE %i: Interface IMFMediaSource cannot be got \n", vd_CurrentNumber);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
            return false;
        }
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"VIDEODEVICE %i: Device is setuped already \n", vd_CurrentNumber);
=======
        DebugPrintOut(L"VIDEODEVICE %i: Device is setuped already \n", vd_CurrentNumber);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        return false;
    }
}

bool videoDevice::setupDevice(unsigned int w, unsigned int h, unsigned int idealFramerate)
{
<<<<<<< HEAD
    unsigned int id = findType(w * h, idealFramerate);
    return setupDevice(id);
=======
#ifdef HAVE_WINRT
#ifdef HAVE_CONCURRENCY
    SAVE_CURRENT_CONTEXT(context);
    auto func = [context, w, h, idealFramerate, this]()->DEFINE_RET_FORMAL(void) {
        HRESULT hr;
        BEGIN_CALL_IN_CONTEXT(hr, context, w, h, idealFramerate, this)
#endif
#endif
            int id = findType(w * h, idealFramerate);
        if (id < 0)
#ifdef HAVE_WINRT
        {} else
#else
            return false;
        return
#endif
            setupDevice(id);
#ifdef HAVE_WINRT
#ifdef HAVE_CONCURRENCY
        END_CALL_IN_CONTEXT_BASE
        RET_VAL_BASE
    };
    CREATE_OR_CONTINUE_TASK(vd_pAction, void, func);
    return true;
#endif
#endif
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
}

wchar_t *videoDevice::getName()
{
    return vd_pFriendlyName;
}

videoDevice::~videoDevice(void)
{
    closeDevice();
<<<<<<< HEAD
=======
#ifdef HAVE_WINRT
    RELEASE_WRL(vd_pMedCap)
#endif
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    SafeRelease(&vd_pSource);
    if(vd_pFriendlyName)
        CoTaskMemFree(vd_pFriendlyName);
}

<<<<<<< HEAD
HRESULT videoDevice::enumerateCaptureFormats(IMFMediaSource *pSource)
{
    ComPtr<IMFPresentationDescriptor> pPD = NULL;
    ComPtr<IMFStreamDescriptor> pSD = NULL;
    ComPtr<IMFMediaTypeHandler> pHandler = NULL;
    ComPtr<IMFMediaType> pType = NULL;
=======
#ifdef HAVE_WINRT
HRESULT videoDevice::enumerateCaptureFormats(MAKE_WRL_REF(_MediaCapture) pSource)
{
    HRESULT hr;
    MAKE_WRL_OBJ(_VideoDeviceController) pDevCont;
    WRL_PROP_GET(pSource, VideoDeviceController, pDevCont, hr)
    if (FAILED(hr)) return hr;
    GET_WRL_OBJ_FROM_OBJ(_MediaDeviceController, pMedDevCont, pDevCont, hr)
    if (FAILED(hr)) return hr;
    MAKE_WRL_OBJ(_VectorView<MAKE_WRL_REF(_MediaEncodingProperties)>) pVector;
    WRL_METHOD(pMedDevCont, GetAvailableMediaStreamProperties, pVector, hr, WRL_ENUM_GET(_MediaStreamType, MediaStreamType, VideoPreview))
    if (FAILED(hr)) return hr;
    UINT32 count;
    WRL_PROP_GET(pVector, Size, count, hr)
    if (FAILED(hr)) return hr;
    for (UINT32 i = 0; i < count; i++) {
        MAKE_WRL_OBJ(_MediaEncodingProperties) pMedEncProps;
        WRL_METHOD(pVector, GetAt, pMedEncProps, hr, i)
        if (FAILED(hr)) return hr;
        _ComPtr<IMFMediaType> pType = NULL;
        hr = MediaSink::ConvertPropertiesToMediaType(DEREF_AS_NATIVE_WRL_OBJ(ABI::Windows::Media::MediaProperties::IMediaEncodingProperties, pMedEncProps), &pType);
        if (FAILED(hr)) return hr;
        MediaType MT = FormatReader::Read(pType.Get());
        vd_CurrentFormats.push_back(MT);
    }
    return hr;
}
#endif

HRESULT videoDevice::enumerateCaptureFormats(IMFMediaSource *pSource)
{
    _ComPtr<IMFPresentationDescriptor> pPD = NULL;
    _ComPtr<IMFStreamDescriptor> pSD = NULL;
    _ComPtr<IMFMediaTypeHandler> pHandler = NULL;
    _ComPtr<IMFMediaType> pType = NULL;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    HRESULT hr = pSource->CreatePresentationDescriptor(pPD.GetAddressOf());
    if (FAILED(hr))
    {
        goto done;
    }
    BOOL fSelected;
    hr = pPD->GetStreamDescriptorByIndex(0, &fSelected, pSD.GetAddressOf());
    if (FAILED(hr))
    {
        goto done;
    }
    hr = pSD->GetMediaTypeHandler(pHandler.GetAddressOf());
    if (FAILED(hr))
    {
        goto done;
    }
    DWORD cTypes = 0;
    hr = pHandler->GetMediaTypeCount(&cTypes);
    if (FAILED(hr))
    {
        goto done;
    }
    for (DWORD i = 0; i < cTypes; i++)
    {
        hr = pHandler->GetMediaTypeByIndex(i, pType.GetAddressOf());
        if (FAILED(hr))
        {
            goto done;
        }
        MediaType MT = FormatReader::Read(pType.Get());
        vd_CurrentFormats.push_back(MT);
    }

done:
    return hr;
}

videoDevices::videoDevices(void): count(0)
<<<<<<< HEAD
{}
=======
{
}
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d

void videoDevices::clearDevices()
{
    std::vector<videoDevice *>::iterator i = vds_Devices.begin();
    for(; i != vds_Devices.end(); ++i)
        delete (*i);
    vds_Devices.clear();
}

videoDevices::~videoDevices(void)
{
    clearDevices();
}

videoDevice * videoDevices::getDevice(unsigned int i)
{
    if(i >= vds_Devices.size())
    {
        return NULL;
    }
    if(i < 0)
    {
        return NULL;
    }
    return vds_Devices[i];
}

<<<<<<< HEAD
long videoDevices::initDevices(IMFAttributes *pAttributes)
{
    HRESULT hr = S_OK;
    IMFActivate **ppDevices = NULL;
    clearDevices();
    hr = MFEnumDeviceSources(pAttributes, &ppDevices, &count);
=======
#ifdef HAVE_WINRT
long videoDevices::initDevices(_DeviceClass devClass)
{
    HRESULT hr = S_OK;
    ACTIVATE_STATIC_OBJ(RuntimeClass_Windows_Devices_Enumeration_DeviceInformation, MAKE_WRL_OBJ(_DeviceInformationStatics), pDevStat, hr)
    if (FAILED(hr)) return hr;
    MAKE_WRL_REF(_AsyncOperation<MAKE_WRL_REF(_DeviceInformationCollection)>) pAction;
    WRL_METHOD(pDevStat, _FindAllAsyncDeviceClass, pAction, hr, devClass)
    if (SUCCEEDED(hr)) {
#ifdef HAVE_CONCURRENCY
           SAVE_CURRENT_CONTEXT(context);
           vds_enumTask = CREATE_TASK DEFINE_RET_TYPE(void)([pAction, context, this]()->DEFINE_RET_FORMAL(void) {
               HRESULT hr = S_OK;
               MAKE_WRL_OBJ(_VectorView<MAKE_WRL_REF(_DeviceInformation)>) pVector =
                   CREATE_TASK DEFINE_RET_TYPE(MAKE_WRL_REF(_VectorView<MAKE_WRL_REF(_DeviceInformation)>))(pAction).get();
               if (SUCCEEDED(hr)) WRL_PROP_GET(pVector, Size, count, hr)
                   if (SUCCEEDED(hr) && count > 0) {
                   for (UINT32 i = 0; i < count; i++) {
                       videoDevice *vd = new videoDevice;
                       MAKE_WRL_OBJ(_IDeviceInformation) pDevice;
                       WRL_METHOD(pVector, GetAt, pDevice, hr, i)
                           if (SUCCEEDED(hr)) {
                           BEGIN_CALL_IN_CONTEXT(hr, context, vd, pDevice, i)
                               vd->readInfoOfDevice(DEREF_WRL_OBJ(pDevice), i);
                           END_CALL_IN_CONTEXT_BASE
                               vds_Devices.push_back(vd);
                           }
                   }
                }
                RET_VAL_BASE
           });
#endif
    }
    return hr;
}
#else
long videoDevices::initDevices(IMFAttributes *pAttributes)
{
    clearDevices();
    IMFActivate **ppDevices = NULL;
    HRESULT hr = MFEnumDeviceSources(pAttributes, &ppDevices, &count);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    if (SUCCEEDED(hr))
    {
        if(count > 0)
        {
            for(UINT32 i = 0; i < count; i++)
            {
                videoDevice *vd = new videoDevice;
                vd->readInfoOfDevice(ppDevices[i], i);
                vds_Devices.push_back(vd);
                SafeRelease(&ppDevices[i]);
            }
            SafeRelease(ppDevices);
        }
        else
<<<<<<< HEAD
            hr = -1;
    }
    else
    {
        DebugPrintOut *DPO = &DebugPrintOut::getInstance();
        DPO->printOut(L"VIDEODEVICES: The instances of the videoDevice class cannot be created\n");
    }
    return hr;
}

unsigned int videoDevices::getCount()
{
    return vds_Devices.size();
=======
            hr = E_INVALIDARG;
    }
    else
    {
        DebugPrintOut(L"VIDEODEVICES: The instances of the videoDevice class cannot be created\n");
    }
    return hr;
}
#endif

unsigned int videoDevices::getCount()
{
    return (unsigned int)vds_Devices.size();
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
}

videoDevices& videoDevices::getInstance()
{
    static videoDevices instance;
    return instance;
}

Parametr::Parametr()
{
    CurrentValue = 0;
    Min = 0;
    Max = 0;
    Step = 0;
    Default = 0;
    Flag = 0;
}

MediaType::MediaType()
{
    pMF_MT_AM_FORMAT_TYPEName = NULL;
    pMF_MT_MAJOR_TYPEName = NULL;
    pMF_MT_SUBTYPEName = NULL;
    Clear();
}

MediaType::~MediaType()
{
    Clear();
}

void MediaType::Clear()
{
    MF_MT_FRAME_SIZE = 0;
    height = 0;
    width = 0;
    MF_MT_YUV_MATRIX = 0;
    MF_MT_VIDEO_LIGHTING = 0;
    MF_MT_DEFAULT_STRIDE = 0;
    MF_MT_VIDEO_CHROMA_SITING = 0;
    MF_MT_FIXED_SIZE_SAMPLES = 0;
    MF_MT_VIDEO_NOMINAL_RANGE = 0;
    MF_MT_FRAME_RATE_NUMERATOR = 0;
    MF_MT_FRAME_RATE_DENOMINATOR = 0;
    MF_MT_PIXEL_ASPECT_RATIO = 0;
    MF_MT_PIXEL_ASPECT_RATIO_low = 0;
    MF_MT_ALL_SAMPLES_INDEPENDENT = 0;
    MF_MT_FRAME_RATE_RANGE_MIN = 0;
    MF_MT_FRAME_RATE_RANGE_MIN_low = 0;
    MF_MT_SAMPLE_SIZE = 0;
    MF_MT_VIDEO_PRIMARIES = 0;
    MF_MT_INTERLACE_MODE = 0;
    MF_MT_FRAME_RATE_RANGE_MAX = 0;
    MF_MT_FRAME_RATE_RANGE_MAX_low = 0;
    memset(&MF_MT_MAJOR_TYPE, 0, sizeof(GUID));
    memset(&MF_MT_AM_FORMAT_TYPE, 0, sizeof(GUID));
    memset(&MF_MT_SUBTYPE, 0, sizeof(GUID));
}

videoInput::videoInput(void): accessToDevices(false)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    DPO->printOut(L"\n***** VIDEOINPUT LIBRARY - 2013 (Author: Evgeny Pereguda) *****\n\n");
    updateListOfDevices();
    if(!accessToDevices)
        DPO->printOut(L"INITIALIZATION: Ther is not any suitable video device\n");
=======
    DebugPrintOut(L"\n***** VIDEOINPUT LIBRARY - 2013 (Author: Evgeny Pereguda) *****\n\n");
    updateListOfDevices();
    if(!accessToDevices)
        DebugPrintOut(L"INITIALIZATION: There is not any suitable video device\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
}

void videoInput::updateListOfDevices()
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    Media_Foundation *MF = &Media_Foundation::getInstance();
    accessToDevices = MF->buildListOfDevices();
    if(!accessToDevices)
        DPO->printOut(L"UPDATING: Ther is not any suitable video device\n");
=======
    Media_Foundation *MF = &Media_Foundation::getInstance();
    accessToDevices = MF->buildListOfDevices();
    if(!accessToDevices)
        DebugPrintOut(L"UPDATING: There is not any suitable video device\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
}

videoInput::~videoInput(void)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    DPO->printOut(L"\n***** CLOSE VIDEOINPUT LIBRARY - 2013 *****\n\n");
=======
    DebugPrintOut(L"\n***** CLOSE VIDEOINPUT LIBRARY - 2013 *****\n\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
}

IMFMediaSource *videoInput::getMediaSource(int deviceID)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    if(accessToDevices)
    {
        videoDevices *VDS = &videoDevices::getInstance();
        videoDevice * VD = VDS->getDevice(deviceID);
=======
    if(accessToDevices)
    {
        videoDevice * VD = videoDevices::getInstance().getDevice(deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        if(VD)
        {
            IMFMediaSource *out = VD->getMediaSource();
            if(!out)
<<<<<<< HEAD
                DPO->printOut(L"VideoDevice %i: There is not any suitable IMFMediaSource interface\n", deviceID);
=======
                DebugPrintOut(L"VideoDevice %i: There is not any suitable IMFMediaSource interface\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
            return out;
        }
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
=======
        DebugPrintOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
    return NULL;
}

bool videoInput::setupDevice(int deviceID, unsigned int id)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    if (deviceID < 0 )
    {
        DPO->printOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
=======
    if (deviceID < 0 )
    {
        DebugPrintOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        return false;
    }
    if(accessToDevices)
    {
        videoDevices *VDS = &videoDevices::getInstance();
        videoDevice * VD = VDS->getDevice(deviceID);
        if(VD)
        {
            bool out = VD->setupDevice(id);
            if(!out)
<<<<<<< HEAD
                DPO->printOut(L"VIDEODEVICE %i: This device cannot be started\n", deviceID);
=======
                DebugPrintOut(L"VIDEODEVICE %i: This device cannot be started\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
            return out;
        }
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
=======
        DebugPrintOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
    return false;
}

bool videoInput::setupDevice(int deviceID, unsigned int w, unsigned int h, unsigned int idealFramerate)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    if (deviceID < 0 )
    {
        DPO->printOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
=======
    if (deviceID < 0 )
    {
        DebugPrintOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        return false;
    }
    if(accessToDevices)
    {
        videoDevices *VDS = &videoDevices::getInstance();
        videoDevice * VD = VDS->getDevice(deviceID);
        if(VD)
        {
            bool out = VD->setupDevice(w, h, idealFramerate);
            if(!out)
<<<<<<< HEAD
                DPO->printOut(L"VIDEODEVICE %i: this device cannot be started\n", deviceID);
=======
                DebugPrintOut(L"VIDEODEVICE %i: this device cannot be started\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
            return out;
        }
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"VIDEODEVICE(s): There is not any suitable video device\n", deviceID);
=======
        DebugPrintOut(L"VIDEODEVICE(s): There is not any suitable video device\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
    return false;
}

MediaType videoInput::getFormat(int deviceID, unsigned int id)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    if (deviceID < 0)
    {
        DPO->printOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
=======
    if (deviceID < 0)
    {
        DebugPrintOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        return MediaType();
    }
    if(accessToDevices)
    {
        videoDevices *VDS = &videoDevices::getInstance();
        videoDevice * VD = VDS->getDevice(deviceID);
        if(VD)
            return VD->getFormat(id);
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
=======
        DebugPrintOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
    return MediaType();
}

bool videoInput::isDeviceSetup(int deviceID)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    if (deviceID < 0)
    {
        DPO->printOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
=======
    if (deviceID < 0)
    {
        DebugPrintOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        return false;
    }
    if(accessToDevices)
    {
        videoDevices *VDS = &videoDevices::getInstance();
        videoDevice * VD = VDS->getDevice(deviceID);
        if(VD)
            return VD->isDeviceSetup();
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
=======
        DebugPrintOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
    return false;
}

bool videoInput::isDeviceMediaSource(int deviceID)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    if (deviceID < 0)
    {
        DPO->printOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
=======
    if (deviceID < 0)
    {
        DebugPrintOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        return false;
    }
    if(accessToDevices)
    {
        videoDevices *VDS = &videoDevices::getInstance();
        videoDevice * VD = VDS->getDevice(deviceID);
        if(VD)
            return VD->isDeviceMediaSource();
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"Device(s): There is not any suitable video device\n");
=======
        DebugPrintOut(L"Device(s): There is not any suitable video device\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
    return false;
}

bool videoInput::isDeviceRawDataSource(int deviceID)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    if (deviceID < 0)
    {
        DPO->printOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
=======
    if (deviceID < 0)
    {
        DebugPrintOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        return false;
    }
    if(accessToDevices)
    {
        videoDevices *VDS = &videoDevices::getInstance();
        videoDevice * VD = VDS->getDevice(deviceID);
        if(VD)
        {
            bool isRaw = VD->isDeviceRawDataSource();
            return isRaw;
        }
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
=======
        DebugPrintOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
    return false;
}

bool videoInput::isFrameNew(int deviceID)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    if (deviceID < 0)
    {
        DPO->printOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
=======
    if (deviceID < 0)
    {
        DebugPrintOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        return false;
    }
    if(accessToDevices)
    {
        if(!isDeviceSetup(deviceID))
        {
            if(isDeviceMediaSource(deviceID))
                return false;
        }
        videoDevices *VDS = &videoDevices::getInstance();
        videoDevice * VD = VDS->getDevice(deviceID);
        if(VD)
        {
            return VD->isFrameNew();
        }
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
=======
        DebugPrintOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
    return false;
}

<<<<<<< HEAD
unsigned int videoInput::getCountFormats(int deviceID)
{
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    if (deviceID < 0)
    {
        DPO->printOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
=======
#ifdef HAVE_WINRT
void videoInput::waitForDevice(int deviceID)
{
    if (deviceID < 0)
    {
        DebugPrintOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
        return;
    }
    if(accessToDevices)
    {
        if(!isDeviceSetup(deviceID))
        {
            if(isDeviceMediaSource(deviceID))
                return;
        }
        videoDevices *VDS = &videoDevices::getInstance();
        videoDevice * VD = VDS->getDevice(deviceID);
        if(VD)
        {
            VD->waitForDevice();
        }
    }
    else
    {
        DebugPrintOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
    }
    return;
}
#endif

unsigned int videoInput::getCountFormats(int deviceID)
{
    if (deviceID < 0)
    {
        DebugPrintOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        return 0;
    }
    if(accessToDevices)
    {
        videoDevices *VDS = &videoDevices::getInstance();
        videoDevice * VD = VDS->getDevice(deviceID);
        if(VD)
            return VD->getCountFormats();
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
=======
        DebugPrintOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
    return 0;
}

void videoInput::closeAllDevices()
{
    videoDevices *VDS = &videoDevices::getInstance();
    for(unsigned int i = 0; i < VDS->getCount(); i++)
        closeDevice(i);
}

void videoInput::setParametrs(int deviceID, CamParametrs parametrs)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    if (deviceID < 0)
    {
        DPO->printOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
=======
    if (deviceID < 0)
    {
        DebugPrintOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        return;
    }
    if(accessToDevices)
    {
        videoDevices *VDS = &videoDevices::getInstance();
        videoDevice *VD = VDS->getDevice(deviceID);
        if(VD)
            VD->setParametrs(parametrs);
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
=======
        DebugPrintOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
}

CamParametrs videoInput::getParametrs(int deviceID)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    CamParametrs out;
    if (deviceID < 0)
    {
        DPO->printOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
=======
    CamParametrs out;
    if (deviceID < 0)
    {
        DebugPrintOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        return out;
    }
    if(accessToDevices)
    {
        videoDevices *VDS = &videoDevices::getInstance();
        videoDevice *VD = VDS->getDevice(deviceID);
        if(VD)
            out = VD->getParametrs();
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
=======
        DebugPrintOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
    return out;
}

void videoInput::closeDevice(int deviceID)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    if (deviceID < 0)
    {
        DPO->printOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
=======
    if (deviceID < 0)
    {
        DebugPrintOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        return;
    }
    if(accessToDevices)
    {
        videoDevices *VDS = &videoDevices::getInstance();
        videoDevice *VD = VDS->getDevice(deviceID);
        if(VD)
            VD->closeDevice();
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
=======
        DebugPrintOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
}

unsigned int videoInput::getWidth(int deviceID)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    if (deviceID < 0)
    {
        DPO->printOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
=======
    if (deviceID < 0)
    {
        DebugPrintOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        return 0;
    }
    if(accessToDevices)
    {
        videoDevices *VDS = &videoDevices::getInstance();
        videoDevice * VD = VDS->getDevice(deviceID);
        if(VD)
            return VD->getWidth();
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
=======
        DebugPrintOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
    return 0;
}

unsigned int videoInput::getHeight(int deviceID)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    if (deviceID < 0)
    {
        DPO->printOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
=======
    if (deviceID < 0)
    {
        DebugPrintOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        return 0;
    }
    if(accessToDevices)
    {
        videoDevices *VDS = &videoDevices::getInstance();
        videoDevice * VD = VDS->getDevice(deviceID);
        if(VD)
            return VD->getHeight();
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
=======
        DebugPrintOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
    }
    return 0;
}

unsigned int videoInput::getFrameRate(int deviceID) const
{
    if (deviceID < 0)
    {
        DebugPrintOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
        return 0;
    }
    if(accessToDevices)
    {
        videoDevice * VD = videoDevices::getInstance().getDevice(deviceID);
        if(VD)
            return VD->getFrameRate();
    }
    else
    {
        DebugPrintOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
    return 0;
}

wchar_t *videoInput::getNameVideoDevice(int deviceID)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    if (deviceID < 0)
    {
        DPO->printOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
=======
    if (deviceID < 0)
    {
        DebugPrintOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        return NULL;
    }
    if(accessToDevices)
    {
        videoDevices *VDS = &videoDevices::getInstance();
        videoDevice * VD = VDS->getDevice(deviceID);
        if(VD)
            return VD->getName();
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
=======
        DebugPrintOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
    return L"Empty";
}

unsigned int videoInput::listDevices(bool silent)
{
<<<<<<< HEAD
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
=======
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    int out = 0;
    if(accessToDevices)
    {
        videoDevices *VDS = &videoDevices::getInstance();
<<<<<<< HEAD
        out = VDS->getCount();
        DebugPrintOut *DPO = &DebugPrintOut::getInstance();
        if(!silent)DPO->printOut(L"\nVIDEOINPUT SPY MODE!\n\n");
        if(!silent)DPO->printOut(L"SETUP: Looking For Capture Devices\n");
        for(int i = 0; i < out; i++)
        {
            if(!silent)DPO->printOut(L"SETUP: %i) %s \n",i, getNameVideoDevice(i));
        }
        if(!silent)DPO->printOut(L"SETUP: %i Device(s) found\n\n", out);
    }
    else
    {
        DPO->printOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
=======
#ifdef HAVE_WINRT
        VDS->waitInit();
#endif
        out = VDS->getCount();
        if(!silent) DebugPrintOut(L"\nVIDEOINPUT SPY MODE!\n\n");
        if(!silent) DebugPrintOut(L"SETUP: Looking For Capture Devices\n");
        for(int i = 0; i < out; i++)
        {
            if(!silent) DebugPrintOut(L"SETUP: %i) %s \n",i, getNameVideoDevice(i));
        }
        if(!silent) DebugPrintOut(L"SETUP: %i Device(s) found\n\n", out);
    }
    else
    {
        DebugPrintOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
    return out;
}

videoInput& videoInput::getInstance()
{
    static videoInput instance;
    return instance;
}

bool videoInput::isDevicesAcceable()
{
    return accessToDevices;
}

<<<<<<< HEAD
void videoInput::setVerbose(bool state)
{
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    DPO->setVerbose(state);
}

void videoInput::setEmergencyStopEvent(int deviceID, void *userData, void(*func)(int, void *))
{
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    if (deviceID < 0)
    {
        DPO->printOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
=======
#ifdef _DEBUG
void videoInput::setVerbose(bool state)
{
    DPO *dpo = &DPO::getInstance();
    dpo->setVerbose(state);
}
#endif

void videoInput::setEmergencyStopEvent(int deviceID, void *userData, void(*func)(int, void *))
{
    if (deviceID < 0)
    {
        DebugPrintOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        return;
    }
    if(accessToDevices)
    {
        if(func)
        {
            videoDevices *VDS = &videoDevices::getInstance();
            videoDevice * VD = VDS->getDevice(deviceID);
            if(VD)
                VD->setEmergencyStopEvent(userData, func);
        }
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
=======
        DebugPrintOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
}

bool videoInput::getPixels(int deviceID, unsigned char * dstBuffer, bool flipRedAndBlue, bool flipImage)
{
    bool success = false;
<<<<<<< HEAD
    unsigned int bytes = 3;
    DebugPrintOut *DPO = &DebugPrintOut::getInstance();
    if (deviceID < 0)
    {
        DPO->printOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
=======
    if (deviceID < 0)
    {
        DebugPrintOut(L"VIDEODEVICE %i: Invalid device ID\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        return success;
    }
    if(accessToDevices)
    {
        bool isRaw = isDeviceRawDataSource(deviceID);
        if(isRaw)
        {
<<<<<<< HEAD
            videoDevices *VDS = &videoDevices::getInstance();
            DebugPrintOut *DPO = &DebugPrintOut::getInstance();
            RawImage *RIOut = VDS->getDevice(deviceID)->getRawImageOut();
            if(RIOut)
            {
                unsigned int height = VDS->getDevice(deviceID)->getHeight();
                unsigned int width  = VDS->getDevice(deviceID)->getWidth();
                unsigned int size = bytes * width * height;
=======
            videoDevice *VD = videoDevices::getInstance().getDevice(deviceID);
            RawImage *RIOut = VD->getRawImageOut();
            if(RIOut)
            {
                const unsigned int bytes = 3;
                const unsigned int height = VD->getHeight();
                const unsigned int width  = VD->getWidth();
                const unsigned int size = bytes * width * height;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
                if(size == RIOut->getSize())
                {
                    processPixels(RIOut->getpPixels(), dstBuffer, width, height, bytes, flipRedAndBlue, flipImage);
                    success = true;
                }
                else
                {
<<<<<<< HEAD
                    DPO->printOut(L"ERROR: GetPixels() - bufferSizes do not match!\n");
=======
                    DebugPrintOut(L"ERROR: GetPixels() - bufferSizes do not match!\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
                }
            }
            else
            {
<<<<<<< HEAD
                DPO->printOut(L"ERROR: GetPixels() - Unable to grab frame for device %i\n", deviceID);
=======
                DebugPrintOut(L"ERROR: GetPixels() - Unable to grab frame for device %i\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
            }
        }
        else
        {
<<<<<<< HEAD
            DPO->printOut(L"ERROR: GetPixels() - Not raw data source device %i\n", deviceID);
=======
            DebugPrintOut(L"ERROR: GetPixels() - Not raw data source device %i\n", deviceID);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        }
    }
    else
    {
<<<<<<< HEAD
        DPO->printOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
=======
        DebugPrintOut(L"VIDEODEVICE(s): There is not any suitable video device\n");
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }
    return success;
}

void videoInput::processPixels(unsigned char * src, unsigned char * dst, unsigned int width,
                                unsigned int height, unsigned int bpp, bool bRGB, bool bFlip)
{
    unsigned int widthInBytes = width * bpp;
    unsigned int numBytes = widthInBytes * height;
    int *dstInt, *srcInt;
    if(!bRGB)
    {
        if(bFlip)
        {
            for(unsigned int y = 0; y < height; y++)
            {
                dstInt = (int *)(dst + (y * widthInBytes));
                srcInt = (int *)(src + ( (height -y -1) * widthInBytes));
                memcpy(dstInt, srcInt, widthInBytes);
            }
        }
        else
        {
            memcpy(dst, src, numBytes);
        }
    }
    else
    {
        if(bFlip)
        {
            unsigned int x = 0;
            unsigned int y = (height - 1) * widthInBytes;
            src += y;
            for(unsigned int i = 0; i < numBytes; i+=3)
            {
                if(x >= width)
                {
                    x = 0;
                    src -= widthInBytes*2;
                }
                *dst = *(src+2);
                dst++;
                *dst = *(src+1);
                dst++;
                *dst = *src;
                dst++;
                src+=3;
                x++;
            }
        }
        else
        {
            for(unsigned int i = 0; i < numBytes; i+=3)
            {
                *dst = *(src+2);
                dst++;
                *dst = *(src+1);
                dst++;
                *dst = *src;
                dst++;
                src+=3;
            }
        }
    }
}
}

/******* Capturing video from camera via Microsoft Media Foundation **********/
class CvCaptureCAM_MSMF : public CvCapture
{
public:
    CvCaptureCAM_MSMF();
    virtual ~CvCaptureCAM_MSMF();
    virtual bool open( int index );
    virtual void close();
    virtual double getProperty(int);
    virtual bool setProperty(int, double);
    virtual bool grabFrame();
    virtual IplImage* retrieveFrame(int);
    virtual int getCaptureDomain() { return CV_CAP_MSMF; } // Return the type of the capture object: CV_CAP_VFW, etc...
protected:
    void init();
    int index, width, height, fourcc;
    IplImage* frame;
    videoInput VI;
<<<<<<< HEAD
};

=======
#ifdef HAVE_WINRT
#ifdef HAVE_CONCURRENCY
    DEFINE_TASK<bool> openTask;
    Concurrency::critical_section lock;
#endif
#endif
};

#ifdef _DEBUG
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
struct SuppressVideoInputMessages
{
    SuppressVideoInputMessages() { videoInput::setVerbose(true); }
};

static SuppressVideoInputMessages do_it;
<<<<<<< HEAD
=======
#endif
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d

CvCaptureCAM_MSMF::CvCaptureCAM_MSMF():
    index(-1),
    width(-1),
    height(-1),
    fourcc(-1),
    frame(NULL),
    VI(videoInput::getInstance())
{
    CoInitialize(0);
}

CvCaptureCAM_MSMF::~CvCaptureCAM_MSMF()
{
    close();
    CoUninitialize();
}

void CvCaptureCAM_MSMF::close()
{
    if( index >= 0 )
    {
        VI.closeDevice(index);
        index = -1;
        cvReleaseImage(&frame);
    }
    width = height = -1;
}

// Initialize camera input
bool CvCaptureCAM_MSMF::open( int _index )
{
<<<<<<< HEAD
=======
#ifdef HAVE_WINRT
#ifdef HAVE_CONCURRENCY
    SAVE_CURRENT_CONTEXT(context);
    auto func = [_index, context, this](DEFINE_RET_VAL(bool)) -> DEFINE_RET_FORMAL(bool) {
#endif
#endif
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    int try_index = _index;
    int devices = 0;
    close();
    devices = VI.listDevices(true);
    if (devices == 0)
        return false;
    try_index = try_index < 0 ? 0 : (try_index > devices-1 ? devices-1 : try_index);
<<<<<<< HEAD
    VI.setupDevice(try_index);
    if( !VI.isFrameNew(try_index) )
        return false;
    index = try_index;
=======
#ifdef HAVE_WINRT
    HRESULT hr;
#ifdef HAVE_CONCURRENCY
    BEGIN_CALL_IN_CONTEXT(hr, context, this, try_index)
#endif
#endif
    VI.setupDevice(try_index, 0, 0, 0); // With maximum frame size.
#ifdef HAVE_WINRT
#ifdef HAVE_CONCURRENCY
    END_CALL_IN_CONTEXT_BASE
    VI.waitForDevice(try_index);
    BEGIN_CALL_IN_CONTEXT(hr, context, this, try_index)
    HRESULT hr = S_OK;
#endif
#endif
    if( !VI.isFrameNew(try_index) )
#ifdef HAVE_WINRT
        hr = E_FAIL;
#else
        return false;
#endif
    index = try_index;
#ifdef HAVE_WINRT
#ifdef HAVE_CONCURRENCY
    END_CALL_IN_CONTEXT_BASE
    RET_VAL(true)
    };
    CREATE_OR_CONTINUE_TASK_RET(openTask, bool, func)
#endif
#endif
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    return true;
}

bool CvCaptureCAM_MSMF::grabFrame()
{
    while (VI.isDeviceSetup(index) && !VI.isFrameNew(index))
        Sleep(1);
    return VI.isDeviceSetup(index);
}

IplImage* CvCaptureCAM_MSMF::retrieveFrame(int)
{
<<<<<<< HEAD
    if( !frame || (int)VI.getWidth(index) != frame->width || (int)VI.getHeight(index) != frame->height )
    {
        if (frame)
            cvReleaseImage( &frame );
        unsigned int w = VI.getWidth(index), h = VI.getHeight(index);
=======
    const int w = (int)VI.getWidth(index);
    const int h = (int)VI.getHeight(index);
    if( !frame || w != frame->width || h != frame->height )
    {
        if (frame)
            cvReleaseImage( &frame );
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        frame = cvCreateImage( cvSize(w,h), 8, 3 );
    }
    VI.getPixels( index, (uchar*)frame->imageData, false, true );
    return frame;
}

double CvCaptureCAM_MSMF::getProperty( int property_id )
{
    // image format proprrties
    switch( property_id )
    {
    case CV_CAP_PROP_FRAME_WIDTH:
        return VI.getWidth(index);
    case CV_CAP_PROP_FRAME_HEIGHT:
        return VI.getHeight(index);
<<<<<<< HEAD
    }
    return -1;
=======
    case CV_CAP_PROP_FPS:
        return VI.getFrameRate(index);
    default:
        break;
    }
    return 0;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
}
bool CvCaptureCAM_MSMF::setProperty( int property_id, double value )
{
    // image capture properties
<<<<<<< HEAD
=======
    unsigned int fps = 0;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    bool handled = false;
    switch( property_id )
    {
    case CV_CAP_PROP_FRAME_WIDTH:
        width = cvRound(value);
<<<<<<< HEAD
=======
        fps = VI.getFrameRate(index);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        handled = true;
        break;
    case CV_CAP_PROP_FRAME_HEIGHT:
        height = cvRound(value);
<<<<<<< HEAD
        handled = true;
        break;
=======
        fps = VI.getFrameRate(index);
        handled = true;
        break;
    case CV_CAP_PROP_FPS:
        width = (int)VI.getHeight(index);
        height = (int)VI.getWidth(index);
        fps = cvRound(value);
        break;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }

    if ( handled ) {
        if( width > 0 && height > 0 )
        {
<<<<<<< HEAD
            if( width != (int)VI.getWidth(index) || height != (int)VI.getHeight(index)  && VI.isDeviceSetup(index))//|| fourcc != VI.getFourcc(index) )
            {
                VI.closeDevice(index);
                VI.setupDevice(index, width, height);
            }
=======
            if( (width != (int)VI.getWidth(index) || height != (int)VI.getHeight(index) || fps != VI.getFrameRate(index))
                && VI.isDeviceSetup(index))//|| fourcc != VI.getFourcc(index) )
            {
                VI.closeDevice(index);
                VI.setupDevice(index, width, height, fps);
            }
            width = height = -1;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
            return VI.isDeviceSetup(index);
        }
        return true;
    }

    return false;
}

class CvCaptureFile_MSMF : public CvCapture
{
public:
    CvCaptureFile_MSMF();
    virtual ~CvCaptureFile_MSMF();

    virtual bool open( const char* filename );
    virtual void close();

    virtual double getProperty(int);
    virtual bool setProperty(int, double);
    virtual bool grabFrame();
    virtual IplImage* retrieveFrame(int);
    virtual int getCaptureDomain() { return CV_CAP_MSMF; }
protected:
    ImageGrabberThread* grabberThread;
    IMFMediaSource* videoFileSource;
    std::vector<MediaType> captureFormats;
    int captureFormatIndex;
    IplImage* frame;
    bool isOpened;

    HRESULT enumerateCaptureFormats(IMFMediaSource *pSource);
    HRESULT getSourceDuration(IMFMediaSource *pSource, MFTIME *pDuration);
};

CvCaptureFile_MSMF::CvCaptureFile_MSMF():
    grabberThread(NULL),
    videoFileSource(NULL),
    captureFormatIndex(0),
    frame(NULL),
    isOpened(false)
{
    MFStartup(MF_VERSION);
}

CvCaptureFile_MSMF::~CvCaptureFile_MSMF()
{
    close();
    MFShutdown();
}

bool CvCaptureFile_MSMF::open(const char* filename)
{
    if (!filename)
        return false;

    wchar_t* unicodeFileName = new wchar_t[strlen(filename)+1];
<<<<<<< HEAD
    MultiByteToWideChar(CP_ACP, 0, filename, -1, unicodeFileName, strlen(filename)+1);

    HRESULT hr = S_OK;

    MF_OBJECT_TYPE ObjectType = MF_OBJECT_INVALID;

    ComPtr<IMFSourceResolver> pSourceResolver = NULL;
    IUnknown* pUnkSource = NULL;

    hr = MFCreateSourceResolver(pSourceResolver.GetAddressOf());
=======
    MultiByteToWideChar(CP_ACP, 0, filename, -1, unicodeFileName, (int)strlen(filename)+1);

    MF_OBJECT_TYPE ObjectType = MF_OBJECT_INVALID;

    _ComPtr<IMFSourceResolver> pSourceResolver = NULL;
    IUnknown* pUnkSource = NULL;

    HRESULT hr = MFCreateSourceResolver(pSourceResolver.GetAddressOf());
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d

    if (SUCCEEDED(hr))
    {
        hr = pSourceResolver->CreateObjectFromURL(
            unicodeFileName,
            MF_RESOLUTION_MEDIASOURCE,
            NULL, // Optional property store.
            &ObjectType,
            &pUnkSource
            );
    }

    // Get the IMFMediaSource from the IUnknown pointer.
    if (SUCCEEDED(hr))
    {
        hr = pUnkSource->QueryInterface(IID_PPV_ARGS(&videoFileSource));
    }

    SafeRelease(&pUnkSource);

    if (SUCCEEDED(hr))
    {
        hr = enumerateCaptureFormats(videoFileSource);
    }

<<<<<<< HEAD
    if (SUCCEEDED(hr))
    {
        hr = ImageGrabberThread::CreateInstance(&grabberThread, videoFileSource, (unsigned int)-2, true);
    }

    if (SUCCEEDED(hr))
=======
    if( captureFormats.empty() )
    {
        isOpened = false;
    }
    else
    {
        if (SUCCEEDED(hr))
        {
            hr = ImageGrabberThread::CreateInstance(&grabberThread, videoFileSource, (unsigned int)-2, true);
        }

        isOpened = SUCCEEDED(hr);
    }

    if (isOpened)
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    {
        grabberThread->start();
    }

<<<<<<< HEAD
    isOpened = SUCCEEDED(hr);

=======
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    return isOpened;
}

void CvCaptureFile_MSMF::close()
{
    if (grabberThread)
    {
        isOpened = false;
        SetEvent(grabberThread->getImageGrabber()->ig_hFinish);
        grabberThread->stop();
        delete grabberThread;
    }

    if (videoFileSource)
    {
        videoFileSource->Shutdown();
    }
}

bool CvCaptureFile_MSMF::setProperty(int property_id, double value)
{
    // image capture properties
    // FIXME: implement method in VideoInput back end
    (void) property_id;
    (void) value;
    return false;
}

double CvCaptureFile_MSMF::getProperty(int property_id)
{
    // image format proprrties
    switch( property_id )
    {
    case CV_CAP_PROP_FRAME_WIDTH:
        return captureFormats[captureFormatIndex].width;
    case CV_CAP_PROP_FRAME_HEIGHT:
        return captureFormats[captureFormatIndex].height;
    case CV_CAP_PROP_FRAME_COUNT:
        {
            MFTIME duration;
            getSourceDuration(this->videoFileSource, &duration);
            double fps = ((double)captureFormats[captureFormatIndex].MF_MT_FRAME_RATE_NUMERATOR) /
            ((double)captureFormats[captureFormatIndex].MF_MT_FRAME_RATE_DENOMINATOR);
            return (double)floor(((double)duration/1e7)*fps+0.5);
        }
    case CV_CAP_PROP_FOURCC:
        return captureFormats[captureFormatIndex].MF_MT_SUBTYPE.Data1;
    case CV_CAP_PROP_FPS:
        return ((double)captureFormats[captureFormatIndex].MF_MT_FRAME_RATE_NUMERATOR) /
            ((double)captureFormats[captureFormatIndex].MF_MT_FRAME_RATE_DENOMINATOR);
    }

    return -1;
}

bool CvCaptureFile_MSMF::grabFrame()
{
    DWORD waitResult = (DWORD)-1;
    if (isOpened)
    {
        SetEvent(grabberThread->getImageGrabber()->ig_hFrameGrabbed);
        HANDLE tmp[] = {grabberThread->getImageGrabber()->ig_hFrameReady, grabberThread->getImageGrabber()->ig_hFinish, 0};
        waitResult = WaitForMultipleObjects(2, tmp, FALSE, INFINITE);
    }

    return isOpened && grabberThread->getImageGrabber()->getRawImage()->isNew() && (waitResult == WAIT_OBJECT_0);
}

IplImage* CvCaptureFile_MSMF::retrieveFrame(int)
{
    unsigned int width = captureFormats[captureFormatIndex].width;
    unsigned int height = captureFormats[captureFormatIndex].height;
    unsigned int bytes = 3;
    if( !frame || (int)width != frame->width || (int)height != frame->height )
    {
        if (frame)
            cvReleaseImage( &frame );
        frame = cvCreateImage( cvSize(width,height), 8, 3 );
    }

    RawImage *RIOut = grabberThread->getImageGrabber()->getRawImage();
    unsigned int size = bytes * width * height;

    bool verticalFlip = captureFormats[captureFormatIndex].MF_MT_DEFAULT_STRIDE < 0;

    if(RIOut && size == RIOut->getSize())
    {
         videoInput::processPixels(RIOut->getpPixels(), (unsigned char*)frame->imageData, width,
             height, bytes, false, verticalFlip);
    }

    return frame;
}

HRESULT CvCaptureFile_MSMF::enumerateCaptureFormats(IMFMediaSource *pSource)
{
<<<<<<< HEAD
    ComPtr<IMFPresentationDescriptor> pPD = NULL;
    ComPtr<IMFStreamDescriptor> pSD = NULL;
    ComPtr<IMFMediaTypeHandler> pHandler = NULL;
    ComPtr<IMFMediaType> pType = NULL;
=======
    _ComPtr<IMFPresentationDescriptor> pPD = NULL;
    _ComPtr<IMFStreamDescriptor> pSD = NULL;
    _ComPtr<IMFMediaTypeHandler> pHandler = NULL;
    _ComPtr<IMFMediaType> pType = NULL;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    HRESULT hr = pSource->CreatePresentationDescriptor(pPD.GetAddressOf());
    if (FAILED(hr))
    {
        goto done;
    }

    BOOL fSelected;
    hr = pPD->GetStreamDescriptorByIndex(0, &fSelected, pSD.GetAddressOf());
    if (FAILED(hr))
    {
        goto done;
    }
    hr = pSD->GetMediaTypeHandler(pHandler.GetAddressOf());
    if (FAILED(hr))
    {
        goto done;
    }
    DWORD cTypes = 0;
    hr = pHandler->GetMediaTypeCount(&cTypes);
    if (FAILED(hr))
    {
        goto done;
    }
    for (DWORD i = 0; i < cTypes; i++)
    {
        hr = pHandler->GetMediaTypeByIndex(i, pType.GetAddressOf());
        if (FAILED(hr))
        {
            goto done;
        }
        MediaType MT = FormatReader::Read(pType.Get());
<<<<<<< HEAD
        captureFormats.push_back(MT);
=======
        // We can capture only RGB video.
        if( MT.MF_MT_SUBTYPE == MFVideoFormat_RGB24 )
            captureFormats.push_back(MT);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    }

done:
    return hr;
}

HRESULT CvCaptureFile_MSMF::getSourceDuration(IMFMediaSource *pSource, MFTIME *pDuration)
{
    *pDuration = 0;

    IMFPresentationDescriptor *pPD = NULL;

    HRESULT hr = pSource->CreatePresentationDescriptor(&pPD);
    if (SUCCEEDED(hr))
    {
        hr = pPD->GetUINT64(MF_PD_DURATION, (UINT64*)pDuration);
        pPD->Release();
    }
    return hr;
}

CvCapture* cvCreateCameraCapture_MSMF( int index )
{
    CvCaptureCAM_MSMF* capture = new CvCaptureCAM_MSMF;
    try
    {
        if( capture->open( index ))
            return capture;
    }
    catch(...)
    {
        delete capture;
        throw;
    }
    delete capture;
    return 0;
}

CvCapture* cvCreateFileCapture_MSMF (const char* filename)
{
    CvCaptureFile_MSMF* capture = new CvCaptureFile_MSMF;
    try
    {
        if( capture->open(filename) )
            return capture;
        else
        {
            delete capture;
            return NULL;
        }
    }
    catch(...)
    {
        delete capture;
        throw;
    }
}

//
//
// Media Foundation-based Video Writer
//
//

class CvVideoWriter_MSMF : public CvVideoWriter
{
public:
    CvVideoWriter_MSMF();
    virtual ~CvVideoWriter_MSMF();
    virtual bool open(const char* filename, int fourcc,
                       double fps, CvSize frameSize, bool isColor);
    virtual void close();
    virtual bool writeFrame(const IplImage* img);

private:
    UINT32 videoWidth;
    UINT32 videoHeight;
    double fps;
    UINT32 bitRate;
    UINT32 frameSize;
    GUID   encodingFormat;
    GUID   inputFormat;

    DWORD  streamIndex;
<<<<<<< HEAD
    ComPtr<IMFSinkWriter> sinkWriter;
=======
    _ComPtr<IMFSinkWriter> sinkWriter;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d

    bool   initiated;

    LONGLONG rtStart;
    UINT64 rtDuration;

    HRESULT InitializeSinkWriter(const char* filename);
    static const GUID FourCC2GUID(int fourcc);
    HRESULT WriteFrame(DWORD *videoFrameBuffer, const LONGLONG& rtStart, const LONGLONG& rtDuration);
};

CvVideoWriter_MSMF::CvVideoWriter_MSMF():
    initiated(false)
{
}

CvVideoWriter_MSMF::~CvVideoWriter_MSMF()
{
    close();
}

const GUID CvVideoWriter_MSMF::FourCC2GUID(int fourcc)
{
    switch(fourcc)
    {
        case CV_FOURCC_MACRO('d', 'v', '2', '5'):
            return MFVideoFormat_DV25; break;
        case CV_FOURCC_MACRO('d', 'v', '5', '0'):
            return MFVideoFormat_DV50; break;
        case CV_FOURCC_MACRO('d', 'v', 'c', ' '):
            return MFVideoFormat_DVC; break;
        case CV_FOURCC_MACRO('d', 'v', 'h', '1'):
            return MFVideoFormat_DVH1; break;
        case CV_FOURCC_MACRO('d', 'v', 'h', 'd'):
            return MFVideoFormat_DVHD; break;
        case CV_FOURCC_MACRO('d', 'v', 's', 'd'):
            return MFVideoFormat_DVSD; break;
        case CV_FOURCC_MACRO('d', 'v', 's', 'l'):
                return MFVideoFormat_DVSL; break;
<<<<<<< HEAD
        case CV_FOURCC_MACRO('H', '2', '6', '3'):
                return MFVideoFormat_H263; break;
=======
#if (WINVER >= 0x0602)
        case CV_FOURCC_MACRO('H', '2', '6', '3'):   // Available only for Win 8 target.
                return MFVideoFormat_H263; break;
#endif
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        case CV_FOURCC_MACRO('H', '2', '6', '4'):
                return MFVideoFormat_H264; break;
        case CV_FOURCC_MACRO('M', '4', 'S', '2'):
                return MFVideoFormat_M4S2; break;
        case CV_FOURCC_MACRO('M', 'J', 'P', 'G'):
                return MFVideoFormat_MJPG; break;
        case CV_FOURCC_MACRO('M', 'P', '4', '3'):
                return MFVideoFormat_MP43; break;
        case CV_FOURCC_MACRO('M', 'P', '4', 'S'):
                return MFVideoFormat_MP4S; break;
        case CV_FOURCC_MACRO('M', 'P', '4', 'V'):
                return MFVideoFormat_MP4V; break;
        case CV_FOURCC_MACRO('M', 'P', 'G', '1'):
                return MFVideoFormat_MPG1; break;
        case CV_FOURCC_MACRO('M', 'S', 'S', '1'):
                return MFVideoFormat_MSS1; break;
        case CV_FOURCC_MACRO('M', 'S', 'S', '2'):
                return MFVideoFormat_MSS2; break;
        case CV_FOURCC_MACRO('W', 'M', 'V', '1'):
                return MFVideoFormat_WMV1; break;
        case CV_FOURCC_MACRO('W', 'M', 'V', '2'):
                return MFVideoFormat_WMV2; break;
        case CV_FOURCC_MACRO('W', 'M', 'V', '3'):
                return MFVideoFormat_WMV3; break;
        case CV_FOURCC_MACRO('W', 'V', 'C', '1'):
                return MFVideoFormat_WVC1; break;
        default:
            return MFVideoFormat_H264;
    }
}

bool CvVideoWriter_MSMF::open( const char* filename, int fourcc,
                       double _fps, CvSize frameSize, bool /*isColor*/ )
{
    videoWidth = frameSize.width;
    videoHeight = frameSize.height;
    fps = _fps;
    bitRate = (UINT32)fps*videoWidth*videoHeight; // 1-bit per pixel
    encodingFormat = FourCC2GUID(fourcc);
    inputFormat = MFVideoFormat_RGB32;

    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    if (SUCCEEDED(hr))
    {
        hr = MFStartup(MF_VERSION);
        if (SUCCEEDED(hr))
        {
            hr = InitializeSinkWriter(filename);
            if (SUCCEEDED(hr))
            {
                initiated = true;
                rtStart = 0;
                MFFrameRateToAverageTimePerFrame((UINT32)fps, 1, &rtDuration);
            }
        }
    }

    return SUCCEEDED(hr);
}

void CvVideoWriter_MSMF::close()
{
    if (!initiated)
    {
        return;
    }

    initiated = false;
    sinkWriter->Finalize();
    MFShutdown();
}

bool CvVideoWriter_MSMF::writeFrame(const IplImage* img)
{
    if (!img)
        return false;

    int length = img->width * img->height * 4;
    DWORD* target = new DWORD[length];

    for (int rowIdx = 0; rowIdx < img->height; rowIdx++)
    {
        char* rowStart = img->imageData + rowIdx*img->widthStep;
        for (int colIdx = 0; colIdx < img->width; colIdx++)
        {
            BYTE b = rowStart[colIdx * img->nChannels + 0];
            BYTE g = rowStart[colIdx * img->nChannels + 1];
            BYTE r = rowStart[colIdx * img->nChannels + 2];

            target[rowIdx*img->width+colIdx] = (r << 16) + (g << 8) + b;
        }
    }

    // Send frame to the sink writer.
    HRESULT hr = WriteFrame(target, rtStart, rtDuration);
    if (FAILED(hr))
    {
        delete[] target;
        return false;
    }
    rtStart += rtDuration;

    delete[] target;

    return true;
}

HRESULT CvVideoWriter_MSMF::InitializeSinkWriter(const char* filename)
{
<<<<<<< HEAD
    ComPtr<IMFAttributes> spAttr;
    ComPtr<IMFMediaType>  mediaTypeOut;
    ComPtr<IMFMediaType>  mediaTypeIn;
    ComPtr<IMFByteStream> spByteStream;
=======
    _ComPtr<IMFAttributes> spAttr;
    _ComPtr<IMFMediaType>  mediaTypeOut;
    _ComPtr<IMFMediaType>  mediaTypeIn;
    _ComPtr<IMFByteStream> spByteStream;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d

    MFCreateAttributes(&spAttr, 10);
    spAttr->SetUINT32(MF_READWRITE_ENABLE_HARDWARE_TRANSFORMS, true);

    wchar_t* unicodeFileName = new wchar_t[strlen(filename)+1];
<<<<<<< HEAD
    MultiByteToWideChar(CP_ACP, 0, filename, -1, unicodeFileName, strlen(filename)+1);
=======
    MultiByteToWideChar(CP_ACP, 0, filename, -1, unicodeFileName, (int)strlen(filename)+1);
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d

    HRESULT hr = MFCreateSinkWriterFromURL(unicodeFileName, NULL, spAttr.Get(), &sinkWriter);

    delete[] unicodeFileName;

    // Set the output media type.
    if (SUCCEEDED(hr))
    {
        hr = MFCreateMediaType(&mediaTypeOut);
    }
    if (SUCCEEDED(hr))
    {
        hr = mediaTypeOut->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Video);
    }
    if (SUCCEEDED(hr))
    {
        hr = mediaTypeOut->SetGUID(MF_MT_SUBTYPE, encodingFormat);
    }
    if (SUCCEEDED(hr))
    {
        hr = mediaTypeOut->SetUINT32(MF_MT_AVG_BITRATE, bitRate);
    }
    if (SUCCEEDED(hr))
    {
        hr = mediaTypeOut->SetUINT32(MF_MT_INTERLACE_MODE, MFVideoInterlace_Progressive);
    }
    if (SUCCEEDED(hr))
    {
        hr = MFSetAttributeSize(mediaTypeOut.Get(), MF_MT_FRAME_SIZE, videoWidth, videoHeight);
    }
    if (SUCCEEDED(hr))
    {
        hr = MFSetAttributeRatio(mediaTypeOut.Get(), MF_MT_FRAME_RATE, (UINT32)fps, 1);
    }
    if (SUCCEEDED(hr))
    {
        hr = MFSetAttributeRatio(mediaTypeOut.Get(), MF_MT_PIXEL_ASPECT_RATIO, 1, 1);
    }

    if (SUCCEEDED(hr))
    {
        hr = sinkWriter->AddStream(mediaTypeOut.Get(), &streamIndex);
    }

    // Set the input media type.
    if (SUCCEEDED(hr))
    {
        hr = MFCreateMediaType(&mediaTypeIn);
    }
    if (SUCCEEDED(hr))
    {
        hr = mediaTypeIn->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Video);
    }
    if (SUCCEEDED(hr))
    {
        hr = mediaTypeIn->SetGUID(MF_MT_SUBTYPE, inputFormat);
    }
    if (SUCCEEDED(hr))
    {
        hr = mediaTypeIn->SetUINT32(MF_MT_INTERLACE_MODE, MFVideoInterlace_Progressive);
    }
    if (SUCCEEDED(hr))
    {
        hr = MFSetAttributeSize(mediaTypeIn.Get(), MF_MT_FRAME_SIZE, videoWidth, videoHeight);
    }
    if (SUCCEEDED(hr))
    {
        hr = MFSetAttributeRatio(mediaTypeIn.Get(), MF_MT_FRAME_RATE, (UINT32)fps, 1);
    }
    if (SUCCEEDED(hr))
    {
        hr = MFSetAttributeRatio(mediaTypeIn.Get(), MF_MT_PIXEL_ASPECT_RATIO, 1, 1);
    }

    if (SUCCEEDED(hr))
    {
        hr = sinkWriter->SetInputMediaType(streamIndex, mediaTypeIn.Get(), NULL);
    }

    // Tell the sink writer to start accepting data.
    if (SUCCEEDED(hr))
    {
        hr = sinkWriter->BeginWriting();
    }

    return hr;
}

HRESULT CvVideoWriter_MSMF::WriteFrame(DWORD *videoFrameBuffer, const LONGLONG& Start, const LONGLONG& Duration)
{
<<<<<<< HEAD
    ComPtr<IMFSample> sample;
    ComPtr<IMFMediaBuffer> buffer;
=======
    _ComPtr<IMFSample> sample;
    _ComPtr<IMFMediaBuffer> buffer;
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d

    const LONG cbWidth = 4 * videoWidth;
    const DWORD cbBuffer = cbWidth * videoHeight;

    BYTE *pData = NULL;

    // Create a new memory buffer.
    HRESULT hr = MFCreateMemoryBuffer(cbBuffer, &buffer);

    // Lock the buffer and copy the video frame to the buffer.
    if (SUCCEEDED(hr))
    {
        hr = buffer->Lock(&pData, NULL, NULL);
    }

    if (SUCCEEDED(hr))
    {
#if defined(_M_ARM)
        hr = MFCopyImage(
            pData,                      // Destination buffer.
            -cbWidth,                   // Destination stride.
            (BYTE*)videoFrameBuffer,    // First row in source image.
            cbWidth,                    // Source stride.
            cbWidth,                    // Image width in bytes.
            videoHeight                 // Image height in pixels.
            );
#else
        hr = MFCopyImage(
            pData,                      // Destination buffer.
            cbWidth,                    // Destination stride.
            (BYTE*)videoFrameBuffer,    // First row in source image.
            cbWidth,                    // Source stride.
            cbWidth,                    // Image width in bytes.
            videoHeight                 // Image height in pixels.
            );
#endif
    }

    if (buffer)
    {
        buffer->Unlock();
    }

    // Set the data length of the buffer.
    if (SUCCEEDED(hr))
    {
        hr = buffer->SetCurrentLength(cbBuffer);
    }

    // Create a media sample and add the buffer to the sample.
    if (SUCCEEDED(hr))
    {
        hr = MFCreateSample(&sample);
    }
    if (SUCCEEDED(hr))
    {
        hr = sample->AddBuffer(buffer.Get());
    }

    // Set the time stamp and the duration.
    if (SUCCEEDED(hr))
    {
        hr = sample->SetSampleTime(Start);
    }
    if (SUCCEEDED(hr))
    {
        hr = sample->SetSampleDuration(Duration);
    }

    // Send the sample to the Sink Writer.
    if (SUCCEEDED(hr))
    {
        hr = sinkWriter->WriteSample(streamIndex, sample.Get());
    }

    return hr;
}

CvVideoWriter* cvCreateVideoWriter_MSMF( const char* filename, int fourcc,
                                        double fps, CvSize frameSize, int isColor )
{
    CvVideoWriter_MSMF* writer = new CvVideoWriter_MSMF;
    if( writer->open( filename, fourcc, fps, frameSize, isColor != 0 ))
        return writer;
    delete writer;
    return NULL;
}

#endif
