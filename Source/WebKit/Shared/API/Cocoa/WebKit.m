/*
 * Copyright (C) 2014-2024 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#import "config.h"
#import "WebKitSwiftOverlayMacros.h"

#if PLATFORM(MAC) || PLATFORM(MACCATALYST) || PLATFORM(IOS) || PLATFORM(VISION)

#define DEFINE_MIGRATED_SYMBOL(Symbol, macOSVersion, iOSVersion, visionOSVersion) \
    const char migrated_symbol_##Symbol = 0
FOR_EACH_MIGRATED_SWIFT_OVERLAY_SYMBOL(DEFINE_MIGRATED_SYMBOL);

char _swift_FORCE_LOAD_$_swiftWebKit = 0;

#endif // PLATFORM(MAC) || PLATFORM(MACCATALYST) || PLATFORM(IOS) || PLATFORM(VISION)

#if PLATFORM(IOS) || PLATFORM(IOS_SIMULATOR)

#define DEFINE_INSTALL_NAME(major, minor) \
    extern __attribute__((visibility ("default"))) const char install_name_ ##major## _ ##minor __asm("$ld$install_name$os" #major "." #minor "$/System/Library/PrivateFrameworks/WebKit.framework/WebKit"); \
    const char install_name_ ##major## _ ##minor = 0;

DEFINE_INSTALL_NAME(4, 3);
DEFINE_INSTALL_NAME(5, 0);
DEFINE_INSTALL_NAME(5, 1);
DEFINE_INSTALL_NAME(6, 0);
DEFINE_INSTALL_NAME(6, 1);
DEFINE_INSTALL_NAME(7, 0);
DEFINE_INSTALL_NAME(7, 1);

#endif
