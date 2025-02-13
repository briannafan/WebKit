/*
 * Copyright (C) 2010-2024 Apple Inc. All rights reserved.
 * Copyright (C) 2012 Samsung Electronics. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include "DeviceClient.h"
#include <wtf/Noncopyable.h>

namespace WebCore {

class DeviceMotionController;
class DeviceMotionData;
class Page;

class DeviceMotionClient : public DeviceClient {
    WTF_MAKE_TZONE_ALLOCATED(DeviceMotionClient);
    WTF_MAKE_NONCOPYABLE(DeviceMotionClient);
public:
    DeviceMotionClient() = default;
    virtual ~DeviceMotionClient() = default;
    virtual void setController(DeviceMotionController*) = 0;
    virtual DeviceMotionData* lastMotion() const = 0;
    virtual void deviceMotionControllerDestroyed() = 0;

    bool isDeviceMotionClient() const override { return true; }
};

} // namespace WebCore

SPECIALIZE_TYPE_TRAITS_BEGIN(WebCore::DeviceMotionClient)
static bool isType(const WebCore::DeviceClient& DeviceClient) { return DeviceClient.isDeviceMotionClient(); }
SPECIALIZE_TYPE_TRAITS_END()

