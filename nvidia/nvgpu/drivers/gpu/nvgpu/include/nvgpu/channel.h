/*
 * Copyright (c) 2018, NVIDIA CORPORATION.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <nvgpu/types.h>

#include "gk20a/gk20a.h"

struct nvgpu_channel_fence;
struct gk20a_fence;
struct fifo_profile_gk20a;

int nvgpu_submit_channel_gpfifo_user(struct channel_gk20a *c,
				struct nvgpu_gpfifo_userdata userdata,
				u32 num_entries,
				u32 flags,
				struct nvgpu_channel_fence *fence,
				struct gk20a_fence **fence_out,
				struct fifo_profile_gk20a *profile);

int nvgpu_submit_channel_gpfifo_kernel(struct channel_gk20a *c,
				struct nvgpu_gpfifo_entry *gpfifo,
				u32 num_entries,
				u32 flags,
				struct nvgpu_channel_fence *fence,
				struct gk20a_fence **fence_out);

#ifdef CONFIG_DEBUG_FS
void trace_write_pushbuffers(struct channel_gk20a *c, int count);
#else
static inline void trace_write_pushbuffers(struct channel_gk20a *c, int count)
{
}
#endif
