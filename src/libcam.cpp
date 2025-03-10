/*
 *    This file is part of MotionPlus.
 *
 *    MotionPlus is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    MotionPlus is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with MotionPlus.  If not, see <https://www.gnu.org/licenses/>.
 *
 *
 */

#include "motionplus.hpp"
#include "util.hpp"
#include "camera.hpp"
#include "conf.hpp"
#include "logger.hpp"
#include "rotate.hpp"
#include "libcam.hpp"

#ifdef HAVE_LIBCAM

using namespace libcamera;

void cls_libcam::log_orientation()
{
    #if (LIBCAMVER >= 2000)
        MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "Libcamera Orientation Options:");
        MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  Rotate0");
        MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  Rotate0Mirror");
        MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  Rotate180");
        MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  Rotate180Mirror");
        MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  Rotate90");
        MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  Rotate90Mirror");
        MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  Rotate270");
        MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  Rotate270Mirror");
    #else
        MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO, "Orientation Not available");
    #endif

}

void cls_libcam::log_controls()
{
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "Libcamera Controls:");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AeEnable(bool)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AeLocked(bool)");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AeMeteringMode(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    MeteringCentreWeighted = 0");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    MeteringSpot = 1");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    MeteringMatrix = 2");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    MeteringCustom = 3");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AeConstraintMode(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    ConstraintNormal = 0");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    ConstraintHighlight = 1");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    ConstraintShadows = 2");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    ConstraintCustom = 3");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AeExposureMode(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    ExposureNormal = 0");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    ExposureShort = 1");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    ExposureLong = 2");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    ExposureCustom = 3");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  ExposureValue(float)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  ExposureTime(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AnalogueGain(float)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  Brightness(float)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  Contrast(float)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  Lux(float)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AwbEnable(bool)");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AwbMode(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AwbAuto = 0");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AwbIncandescent = 1");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AwbTungsten = 2");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AwbFluorescent = 3");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AwbIndoor = 4");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AwbDaylight = 5");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AwbCloudy = 6");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AwbCustom = 7");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AwbLocked(bool)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  ColourGains(Pipe delimited)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "     Red | Blue");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  ColourTemperature(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  Saturation(float)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  SensorBlackLevels(Pipe delimited)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "     var1|var2|var3|var4");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  Sharpness(float)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  FocusFoM(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  ColourCorrectionMatrix(Pipe delimited)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "     var1|var2|...|var8|var9");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  ScalerCrop(Pipe delimited)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "     x | y | h | w");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  DigitalGain(float)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  FrameDuration(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  FrameDurationLimits(Pipe delimited)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "     min | max");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  SensorTemperature(float)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  SensorTimestamp(int)");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AfMode(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfModeManual = 0");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfModeAuto = 1");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfModeContinuous = 2");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AfRange(0-2)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfRangeNormal = 0");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfRangeMacro = 1");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfRangeFull = 2");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AfSpeed(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfSpeedNormal = 0");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfSpeedFast = 1");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AfMetering(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfMeteringAuto = 0");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfMeteringWindows = 1");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AfWindows(Pipe delimited)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "     x | y | h | w");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AfTrigger(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfTriggerStart = 0");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfTriggerCancel = 1");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AfPause(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfPauseImmediate = 0");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfPauseDeferred = 1");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfPauseResume = 2");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  LensPosition(float)");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AfState(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfStateIdle = 0");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfStateScanning = 1");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfStateFocused = 2");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfStateFailed = 3");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AfPauseState(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfPauseStateRunning = 0");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfPauseStatePausing = 1");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AfPauseStatePaused = 2");

}

void cls_libcam:: log_draft()
{
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "Libcamera Controls Draft:");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AePrecaptureTrigger(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AePrecaptureTriggerIdle = 0");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AePrecaptureTriggerStart = 1");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AePrecaptureTriggerCancel = 2");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  NoiseReductionMode(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    NoiseReductionModeOff = 0");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    NoiseReductionModeFast = 1");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    NoiseReductionModeHighQuality = 2");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    NoiseReductionModeMinimal = 3");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    NoiseReductionModeZSL = 4");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  ColorCorrectionAberrationMode(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    ColorCorrectionAberrationOff = 0");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    ColorCorrectionAberrationFast = 1");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    ColorCorrectionAberrationHighQuality = 2");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AeState(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AeStateSearching = 1");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AeStateConverged = 2");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AeStateLocked = 3");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AeStateFlashRequired = 4");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AeStatePrecapture = 5");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  AwbState(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AwbStateInactive = 0");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AwbStateSearching = 1");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AwbConverged = 2");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    AwbLocked = 3");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  SensorRollingShutterSkew(int)");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  LensShadingMapMode(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    LensShadingMapModeOff = 0");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    LensShadingMapModeOn = 1");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  PipelineDepth(int)");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  MaxLatency(int)");

    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "  TestPatternMode(int)");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    TestPatternModeOff = 0");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    TestPatternModeSolidColor = 1");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    TestPatternModeColorBars = 2");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    TestPatternModeColorBarsFadeToGray = 3");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    TestPatternModePn9 = 4");
    MOTPLS_SHT(DBG, TYPE_VIDEO, NO_ERRNO, "    TestPatternModeCustom1 = 256");

}

void cls_libcam::start_params()
{
    ctx_params_item *itm;
    int indx;

    params = new ctx_params;
    util_parms_parse(params,"libcam_params", cam->cfg->libcam_params);

    for (indx=0;indx<params->params_cnt;indx++) {
        itm = &params->params_array[indx];
        MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO, "%s : %s"
            ,itm->param_name.c_str(), itm->param_value.c_str());
    }
}

int cls_libcam::start_mgr()
{
    int retcd;
    std::string camid;

    MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO, "Starting.");

    cam_mgr = std::make_unique<CameraManager>();
    retcd = cam_mgr->start();
    if (retcd != 0) {
        MOTPLS_LOG(ERR, TYPE_VIDEO, NO_ERRNO
            , "Error starting camera manager.  Return code: %d",retcd);
        return retcd;
    }
    started_mgr = true;

    MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO, "cam_mgr started.");

    if (cam->cfg->libcam_device == "camera0"){
        if (cam_mgr->cameras().size() == 0) {
            MOTPLS_LOG(ERR, TYPE_VIDEO, NO_ERRNO
                , "No camera devices found");
            return -1;
        }
        camid = cam_mgr->cameras()[0]->id();
    } else {
        MOTPLS_LOG(ERR, TYPE_VIDEO, NO_ERRNO
            , "Invalid libcam_device '%s'.  The only name supported is 'camera0' "
            ,cam->cfg->libcam_device.c_str());
        return -1;
    }
    camera = cam_mgr->get(camid);
    camera->acquire();
    started_aqr = true;

    MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO, "Finished.");

    return 0;
}

void cls_libcam::config_control_item(std::string pname, std::string pvalue)
{
    if (pname == "AeEnable") {
        controls.set(controls::AeEnable, mtob(pvalue));
    }
    if (pname == "AeLocked") {
        controls.set(controls::AeLocked, mtob(pvalue));
    }
    if (pname == "AeMeteringMode") {
       controls.set(controls::AeMeteringMode, mtoi(pvalue));
    }
    if (pname == "AeConstraintMode") {
        controls.set(controls::AeConstraintMode, mtoi(pvalue));
    }
    if (pname == "AeExposureMode") {
        controls.set(controls::AeExposureMode, mtoi(pvalue));
    }
    if (pname == "ExposureValue") {
        controls.set(controls::ExposureValue, mtof(pvalue));
    }
    if (pname == "ExposureTime") {
        controls.set(controls::ExposureTime, mtoi(pvalue));
    }
    if (pname == "AnalogueGain") {
        controls.set(controls::AnalogueGain, mtof(pvalue));
    }
    if (pname == "Brightness") {
        controls.set(controls::Brightness, mtof(pvalue));
    }
    if (pname == "Contrast") {
        controls.set(controls::Contrast, mtof(pvalue));
    }
    if (pname == "Lux") {
        controls.set(controls::Lux, mtof(pvalue));
    }
    if (pname == "AwbEnable") {
        controls.set(controls::AwbEnable, mtob(pvalue));
    }
    if (pname == "AwbMode") {
        controls.set(controls::AwbMode, mtoi(pvalue));
    }
    if (pname == "AwbLocked") {
        controls.set(controls::AwbLocked, mtob(pvalue));
    }
    if (pname == "ColourGains") {
        float cg[2];
        cg[0] = mtof(mtok(pvalue,"|"));
        cg[1] = mtof(mtok(pvalue,"|"));
        controls.set(controls::ColourGains, cg);
    }
    if (pname == "ColourTemperature") {
        controls.set(controls::ColourTemperature, mtoi(pvalue));
    }
    if (pname == "Saturation") {
        controls.set(controls::Saturation, mtof(pvalue));
    }
    if (pname == "SensorBlackLevels") {
        int32_t sbl[4];
        sbl[0] = mtoi(mtok(pvalue,"|"));
        sbl[1] = mtoi(mtok(pvalue,"|"));
        sbl[2] = mtoi(mtok(pvalue,"|"));
        sbl[3] = mtoi(mtok(pvalue,"|"));
        controls.set(controls::SensorBlackLevels, sbl);
    }
    if (pname == "Sharpness") {
        controls.set(controls::Sharpness, mtof(pvalue));
    }
    if (pname == "FocusFoM") {
        controls.set(controls::FocusFoM, mtoi(pvalue));
    }
    if (pname == "ColourCorrectionMatrix") {
        float ccm[9];
        ccm[0] = mtof(mtok(pvalue,"|"));
        ccm[1] = mtof(mtok(pvalue,"|"));
        ccm[2] = mtof(mtok(pvalue,"|"));
        ccm[3] = mtof(mtok(pvalue,"|"));
        ccm[4] = mtof(mtok(pvalue,"|"));
        ccm[5] = mtof(mtok(pvalue,"|"));
        ccm[6] = mtof(mtok(pvalue,"|"));
        ccm[7] = mtof(mtok(pvalue,"|"));
        ccm[8] = mtof(mtok(pvalue,"|"));
        controls.set(controls::ColourCorrectionMatrix, ccm);
    }
    if (pname == "ScalerCrop") {
        Rectangle crop;
        crop.x = mtoi(mtok(pvalue,"|"));
        crop.y = mtoi(mtok(pvalue,"|"));
        crop.width =(uint)mtoi(mtok(pvalue,"|"));
        crop.height =(uint)mtoi(mtok(pvalue,"|"));
        controls.set(controls::ScalerCrop, crop);
    }
    if (pname == "DigitalGain") {
        controls.set(controls::DigitalGain, mtof(pvalue));
    }
    if (pname == "FrameDuration") {
        controls.set(controls::FrameDuration, mtoi(pvalue));
    }
    if (pname == "FrameDurationLimits") {
        int64_t fdl[2];
        fdl[0] = mtol(mtok(pvalue,"|"));
        fdl[1] = mtol(mtok(pvalue,"|"));
        controls.set(controls::FrameDurationLimits, fdl);
    }
    if (pname == "SensorTemperature") {
        controls.set(controls::SensorTemperature, mtof(pvalue));
    }
    if (pname == "SensorTimestamp") {
        controls.set(controls::SensorTimestamp, mtoi(pvalue));
    }
    if (pname == "AfMode") {
        controls.set(controls::AfMode, mtoi(pvalue));
    }
    if (pname == "AfRange") {
        controls.set(controls::AfRange, mtoi(pvalue));
    }
    if (pname == "AfSpeed") {
        controls.set(controls::AfSpeed, mtoi(pvalue));
    }
    if (pname == "AfMetering") {
        controls.set(controls::AfMetering, mtoi(pvalue));
    }
    if (pname == "AfWindows") {
        Rectangle afwin[1];
        afwin[0].x = mtoi(mtok(pvalue,"|"));
        afwin[0].y = mtoi(mtok(pvalue,"|"));
        afwin[0].width = (uint)mtoi(mtok(pvalue,"|"));
        afwin[0].height = (uint)mtoi(mtok(pvalue,"|"));
        controls.set(controls::AfWindows, afwin);
    }
    if (pname == "AfTrigger") {
        controls.set(controls::AfTrigger, mtoi(pvalue));
    }
    if (pname == "AfPause") {
        controls.set(controls::AfPause, mtoi(pvalue));
    }
    if (pname == "LensPosition") {
        controls.set(controls::LensPosition, mtof(pvalue));
    }
    if (pname == "AfState") {
        controls.set(controls::AfState, mtoi(pvalue));
    }
    if (pname == "AfPauseState") {
        controls.set(controls::AfPauseState, mtoi(pvalue));
    }

    /* DRAFT*/
    if (pname == "AePrecaptureTrigger") {
        controls.set(controls::draft::AePrecaptureTrigger, mtoi(pvalue));
    }
    if (pname == "NoiseReductionMode") {
        controls.set(controls::draft::NoiseReductionMode, mtoi(pvalue));
    }
    if (pname == "ColorCorrectionAberrationMode") {
        controls.set(controls::draft::ColorCorrectionAberrationMode, mtoi(pvalue));
    }
    if (pname == "AeState") {
        controls.set(controls::draft::AeState, mtoi(pvalue));
    }
    if (pname == "AwbState") {
        controls.set(controls::draft::AwbState, mtoi(pvalue));
    }
    if (pname == "SensorRollingShutterSkew") {
        controls.set(controls::draft::SensorRollingShutterSkew, mtoi(pvalue));
    }
    if (pname == "LensShadingMapMode") {
        controls.set(controls::draft::LensShadingMapMode, mtoi(pvalue));
    }
    if (pname == "PipelineDepth") {
        controls.set(controls::draft::PipelineDepth, mtoi(pvalue));
    }
    if (pname == "MaxLatency") {
        controls.set(controls::draft::MaxLatency, mtoi(pvalue));
    }
    if (pname == "TestPatternMode") {
        controls.set(controls::draft::TestPatternMode, mtoi(pvalue));
    }

}

void cls_libcam::config_controls()
{
    int retcd, indx;

    for (indx=0;indx<params->params_cnt;indx++) {
        config_control_item(
            params->params_array[indx].param_name
            ,params->params_array[indx].param_value);
    }

    retcd = config->validate();
    if (retcd == CameraConfiguration::Adjusted) {
        MOTPLS_LOG(INF, TYPE_VIDEO, NO_ERRNO
            , "Configuration controls adjusted.");
    } else if (retcd == CameraConfiguration::Valid) {
         MOTPLS_LOG(DBG, TYPE_VIDEO, NO_ERRNO
            , "Configuration controls valid");
    } else if (retcd == CameraConfiguration::Invalid) {
         MOTPLS_LOG(ERR, TYPE_VIDEO, NO_ERRNO
            , "Configuration controls error");
    }

}

void cls_libcam:: config_orientation()
{
    #if (LIBCAMVER >= 2000)
        int retcd, indx;
        std::string adjdesc;
        ctx_params_item *itm;

        for (indx=0;indx<params->params_cnt;indx++) {
            itm = &params->params_array[indx];
            if (itm->param_name == "orientation") {
                if (itm->param_value == "Rotate0") {
                    config->orientation = Orientation::Rotate0;
                } else if (itm->param_value == "Rotate0Mirror") {
                    config->orientation = Orientation::Rotate0Mirror;
                } else if (itm->param_value == "Rotate180") {
                    config->orientation = Orientation::Rotate180;
                } else if (itm->param_value == "Rotate180Mirror") {
                    config->orientation = Orientation::Rotate180Mirror;
                } else if (itm->param_value == "Rotate90") {
                    config->orientation = Orientation::Rotate90;
                } else if (itm->param_value == "Rotate90Mirror") {
                    config->orientation = Orientation::Rotate90Mirror;
                } else if (itm->param_value == "Rotate270") {
                    config->orientation = Orientation::Rotate270;
                } else if (itm->param_value == "Rotate270Mirror") {
                    config->orientation = Orientation::Rotate270Mirror;
                } else {
                    MOTPLS_LOG(ERR, TYPE_VIDEO, NO_ERRNO
                        , "Invalid Orientation option: %s."
                        , itm->param_value.c_str());
                }
            }
        }

        retcd = config->validate();
        if (retcd == CameraConfiguration::Adjusted) {
            if (config->orientation == Orientation::Rotate0) {
                adjdesc = "Rotate0";
            } else if (config->orientation == Orientation::Rotate0Mirror) {
                adjdesc = "Rotate0Mirror";
            } else if (config->orientation == Orientation::Rotate90) {
                adjdesc = "Rotate90";
            } else if (config->orientation == Orientation::Rotate90Mirror) {
            adjdesc = "Rotate90Mirror";
            } else if (config->orientation == Orientation::Rotate180) {
                adjdesc = "Rotate180";
            } else if (config->orientation == Orientation::Rotate180Mirror) {
                adjdesc = "Rotate180Mirror";
            } else if (config->orientation == Orientation::Rotate270) {
                adjdesc = "Rotate270";
            } else if (config->orientation == Orientation::Rotate270Mirror) {
                adjdesc = "Rotate270Mirror";
            } else {
                adjdesc = "unknown";
            }
            MOTPLS_LOG(INF, TYPE_VIDEO, NO_ERRNO
                , "Configuration orientation adjusted to %s."
                , adjdesc.c_str());
        } else if (retcd == CameraConfiguration::Valid) {
            MOTPLS_LOG(DBG, TYPE_VIDEO, NO_ERRNO
                , "Configuration orientation valid");
        } else if (retcd == CameraConfiguration::Invalid) {
            MOTPLS_LOG(ERR, TYPE_VIDEO, NO_ERRNO
                , "Configuration orientation error");
        }
    #else
        MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO, "Orientation Not available");
    #endif

}

int cls_libcam::start_config()
{
    int retcd;

    MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO, "Starting.");

    config = camera->generateConfiguration({ StreamRole::Viewfinder });

    config->at(0).pixelFormat = PixelFormat::fromString("YUV420");

    config->at(0).size.width = (uint)cam->cfg->width;
    config->at(0).size.height = (uint)cam->cfg->height;
    config->at(0).bufferCount = 1;
    config->at(0).stride = 0;

    retcd = config->validate();
    if (retcd == CameraConfiguration::Adjusted) {
        if (config->at(0).pixelFormat != PixelFormat::fromString("YUV420")) {
            MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO
                , "Pixel format was adjusted to %s."
                , config->at(0).pixelFormat.toString().c_str());
            return -1;
        } else {
            MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO
                , "Configuration adjusted.");
        }
    } else if (retcd == CameraConfiguration::Valid) {
         MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO
            , "Configuration is valid");
    } else if (retcd == CameraConfiguration::Invalid) {
         MOTPLS_LOG(ERR, TYPE_VIDEO, NO_ERRNO
            , "Error setting configuration");
        return -1;
    }

    if ((config->at(0).size.width != (uint)cam->cfg->width) ||
        (config->at(0).size.height != (uint)cam->cfg->height)) {
        MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO
            , "Image size adjusted from %d x %d to %d x %d"
            , cam->cfg->width, cam->cfg->height
            , config->at(0).size.width, config->at(0).size.height);
    }

    cam->imgs.width = (int)config->at(0).size.width;
    cam->imgs.height = (int)config->at(0).size.height;
    cam->imgs.size_norm = (cam->imgs.width * cam->imgs.height * 3) / 2;
    cam->imgs.motionsize = cam->imgs.width * cam->imgs.height;

    log_orientation();
    log_controls();
    log_draft();

    config_orientation();
    config_controls();

    camera->configure(config.get());

    MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO, "Finished.");

    return 0;
}

int cls_libcam::req_add(Request *request)
{
    int retcd;
    retcd = camera->queueRequest(request);
    return retcd;
}

int cls_libcam::start_req()
{
    int retcd, bytes, indx, width;

    MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO, "Starting.");

    camera->requestCompleted.connect(this, &cls_libcam::req_complete);
    frmbuf = std::make_unique<FrameBufferAllocator>(camera);

    retcd = frmbuf->allocate(config->at(0).stream());
    if (retcd < 0) {
        MOTPLS_LOG(ERR, TYPE_VIDEO, NO_ERRNO
            , "Buffer allocation error.");
        return -1;
    }

    std::unique_ptr<Request> request = camera->createRequest();
    if (!request) {
        MOTPLS_LOG(ERR, TYPE_VIDEO, NO_ERRNO
            , "Create request error.");
        return -1;
    }

    Stream *stream = config->at(0).stream();
    const std::vector<std::unique_ptr<FrameBuffer>> &buffers =
        frmbuf->buffers(stream);
    const std::unique_ptr<FrameBuffer> &buffer = buffers[0];

    retcd = request->addBuffer(stream, buffer.get());
    if (retcd < 0) {
        MOTPLS_LOG(ERR, TYPE_VIDEO, NO_ERRNO
            , "Add buffer for request error.");
        return -1;
    }

    started_req = true;

    const FrameBuffer::Plane &plane0 = buffer->planes()[0];

    bytes = 0;
    for (indx=0; indx<(int)buffer->planes().size(); indx++){
        bytes += buffer->planes()[(uint)indx].length;
        MOTPLS_LOG(DBG, TYPE_VIDEO, NO_ERRNO, "Plane %d of %d length %d"
            , indx, buffer->planes().size()
            , buffer->planes()[(uint)indx].length);
    }

    if (bytes > cam->imgs.size_norm) {
        width = ((int)buffer->planes()[0].length / cam->imgs.height);
        if (((int)buffer->planes()[0].length != (width * cam->imgs.height)) ||
            (bytes > ((width * cam->imgs.height * 3)/2))) {
            MOTPLS_LOG(ERR, TYPE_VIDEO, NO_ERRNO
                , "Error setting image size.  Plane 0 length %d, total bytes %d"
                , buffer->planes()[0].length, bytes);
        }
        MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO
            , "Image size adjusted from %d x %d to %d x %d"
            , cam->imgs.width,cam->imgs.height
            , width,cam->imgs.height);
        cam->imgs.width = width;
        cam->imgs.size_norm = (cam->imgs.width * cam->imgs.height * 3) / 2;
        cam->imgs.motionsize = cam->imgs.width * cam->imgs.height;
    }

    membuf.buf = (uint8_t *)mmap(NULL, (uint)bytes, PROT_READ
        , MAP_SHARED, plane0.fd.get(), 0);
    membuf.bufsz = bytes;

    requests.push_back(std::move(request));

    MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO, "Finished.");

    return 0;
}

int cls_libcam::start_capture()
{
    int retcd;

    MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO, "Starting.");

    retcd = camera->start(&this->controls);
    if (retcd) {
        MOTPLS_LOG(ERR, TYPE_VIDEO, NO_ERRNO
            , "Failed to start capture.");
        return -1;
    }
    controls.clear();

    for (std::unique_ptr<Request> &request : requests) {
        retcd = req_add(request.get());
        if (retcd < 0) {
            MOTPLS_LOG(ERR, TYPE_VIDEO, NO_ERRNO
                , "Failed to queue request.");
            if (started_cam) {
                camera->stop();
            }
            return -1;
        }
    }
    MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO, "Finished.");

    return 0;
}

void cls_libcam::req_complete(Request *request)
{
    if (request->status() == Request::RequestCancelled) {
        return;
    }
    req_queue.push(request);
}

int cls_libcam::libcam_start()
{
    started_cam = false;
    started_mgr = false;
    started_aqr = false;
    started_req = false;

    start_params();

    if (start_mgr() != 0) {
        return -1;
    }
    if (start_config() != 0) {
        return -1;
    }
    if (start_req() != 0) {
        return -1;
    }
    if (start_capture() != 0) {
        return -1;
    }

    cam->watchdog = cam->cfg->watchdog_tmo;
    SLEEP(1,0);

    started_cam = true;

    MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO, "Camera started");

    return 0;
}

void cls_libcam::libcam_stop()
{
    mydelete(params);

    if (started_aqr) {
        camera->stop();
    }

    if (started_req) {
        camera->requestCompleted.disconnect(this, &cls_libcam::req_complete);
        while (req_queue.empty() == false) {
            req_queue.pop();
        }
        requests.clear();

        frmbuf->free(config->at(0).stream());
        frmbuf.reset();
    }

    controls.clear();

    if (started_aqr){
        camera->release();
        camera.reset();
    }
    if (started_mgr) {
        cam_mgr->stop();
        cam_mgr.reset();
    }
    cam->device_status = STATUS_CLOSED;
    MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO, "Camera stopped.");
}

#endif

void cls_libcam::noimage()
{
    #ifdef HAVE_LIBCAM
        int slp_dur;

        if (reconnect_count < 100) {
            reconnect_count++;
        } else {
            if (reconnect_count >= 500) {
                MOTPLS_LOG(NTC, TYPE_NETCAM, NO_ERRNO,_("Camera did not reconnect."));
                MOTPLS_LOG(NTC, TYPE_NETCAM, NO_ERRNO,_("Checking for camera every 2 hours."));
                slp_dur = 7200;
            } else if (reconnect_count >= 200) {
                MOTPLS_LOG(NTC, TYPE_NETCAM, NO_ERRNO,_("Camera did not reconnect."));
                MOTPLS_LOG(NTC, TYPE_NETCAM, NO_ERRNO,_("Checking for camera every 10 minutes."));
                reconnect_count++;
                slp_dur = 600;
            } else {
                MOTPLS_LOG(NTC, TYPE_NETCAM, NO_ERRNO,_("Camera did not reconnect."));
                MOTPLS_LOG(NTC, TYPE_NETCAM, NO_ERRNO,_("Checking for camera every 30 seconds."));
                reconnect_count++;
                slp_dur = 30;
            }
            cam->watchdog = slp_dur + (cam->cfg->watchdog_tmo * 3);
            SLEEP(slp_dur,0);
            libcam_stop();
            if (libcam_start() < 0) {
                MOTPLS_LOG(ERR, TYPE_VIDEO, NO_ERRNO,_("libcam failed to open"));
                libcam_stop();
            } else {
                cam->device_status = STATUS_OPENED;
            }
        }
    #endif
}

int cls_libcam::next(ctx_image_data *img_data)
{
    #ifdef HAVE_LIBCAM
        int indx;

        if (started_cam == false) {
            return CAPTURE_FAILURE;
        }

        cam->watchdog = cam->cfg->watchdog_tmo;
        /* Allow time for request to finish.*/
        indx=0;
        while ((req_queue.empty() == true) && (indx < 50)) {
            SLEEP(0,2000)
            indx++;
        }

        cam->watchdog = cam->cfg->watchdog_tmo;
        if (req_queue.empty() == false) {
            Request *request = this->req_queue.front();

            memcpy(img_data->image_norm, membuf.buf, (uint)membuf.bufsz);

            this->req_queue.pop();
            request->reuse(Request::ReuseBuffers);
            req_add(request);

            cam->rotate->process(img_data);
            reconnect_count = 0;

            return CAPTURE_SUCCESS;

        } else {
            return CAPTURE_FAILURE;
        }
    #else
        (void)img_data;
        return CAPTURE_FAILURE;
    #endif
}

cls_libcam::cls_libcam(cls_camera *p_cam)
{
    cam = p_cam;
    #ifdef HAVE_LIBCAM
        MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO,_("Opening libcam"));
        params = nullptr;
        reconnect_count = 0;
        cam->watchdog = cam->cfg->watchdog_tmo * 3; /* 3 is arbitrary multiplier to give startup more time*/
        if (libcam_start() < 0) {
            MOTPLS_LOG(ERR, TYPE_VIDEO, NO_ERRNO,_("libcam failed to open"));
            libcam_stop();
        } else {
            cam->device_status = STATUS_OPENED;
        }
    #else
        MOTPLS_LOG(NTC, TYPE_VIDEO, NO_ERRNO,_("libcam not available"));
        cam->device_status = STATUS_CLOSED;
    #endif
}

cls_libcam::~cls_libcam()
{
    #ifdef HAVE_LIBCAM
        libcam_stop();
    #endif
    cam->device_status = STATUS_CLOSED;
}

