/*
 * Copyright (C) 2016 Apple Inc. All rights reserved.
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

#pragma once

#include "CryptoKeyUsage.h"
#include "RsaOtherPrimesInfo.h"
#include <wtf/Vector.h>

namespace WebCore {

struct JsonWebKey {
    JsonWebKey isolatedCopy() && {
        return {
            crossThreadCopy(WTFMove(kty)),
            crossThreadCopy(WTFMove(use)),
            key_ops,
            usages,
            crossThreadCopy(WTFMove(alg)),
            ext,
            crossThreadCopy(WTFMove(crv)),
            crossThreadCopy(WTFMove(x)),
            crossThreadCopy(WTFMove(y)),
            crossThreadCopy(WTFMove(d)),
            crossThreadCopy(WTFMove(n)),
            crossThreadCopy(WTFMove(e)),
            crossThreadCopy(WTFMove(p)),
            crossThreadCopy(WTFMove(q)),
            crossThreadCopy(WTFMove(dp)),
            crossThreadCopy(WTFMove(dq)),
            crossThreadCopy(WTFMove(qi)),
            crossThreadCopy(WTFMove(oth)),
            crossThreadCopy(WTFMove(k))
        };
    }

    String kty;
    String use;
    // FIXME: Consider merging key_ops and usages.
    std::optional<Vector<CryptoKeyUsage>> key_ops;
    CryptoKeyUsageBitmap usages;
    String alg;

    std::optional<bool> ext;

    String crv;
    String x;
    String y;
    String d;
    String n;
    String e;
    String p;
    String q;
    String dp;
    String dq;
    String qi;
    std::optional<Vector<RsaOtherPrimesInfo>> oth;
    String k;
};

} // namespace WebCore
