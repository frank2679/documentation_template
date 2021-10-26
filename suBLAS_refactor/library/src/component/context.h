// Copyright 2020, Biren Technologies Inc.
// All rights reserved.

#ifndef _CONTEXT_API_H_
#define _CONTEXT_API_H_

#include "base/base.h"
#include "handle.h"

SUBLAS_API sublasStatus_t sublasCreate(sublasHandle_t *handle);

SUBLAS_API sublasStatus_t sublasDestroy(sublasHandle_t handle);

#endif