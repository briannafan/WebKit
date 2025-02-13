/*
 * Copyright (C) 2024 Apple Inc. All rights reserved.
 */

#pragma once

#if ENABLE(MODEL_PROCESS)

#import <QuartzCore/QuartzCore.h>
#import <wtf/WeakPtr.h>

namespace WebKit {
class ModelProcessModelPlayerProxy;
}

@interface WKModelProcessModelLayer : CALayer

@property (direct) WeakPtr<WebKit::ModelProcessModelPlayerProxy> player;

@end

#endif // MODEL_PROCESS
