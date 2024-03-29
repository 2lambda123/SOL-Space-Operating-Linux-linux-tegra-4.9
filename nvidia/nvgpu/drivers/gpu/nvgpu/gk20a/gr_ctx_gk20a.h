/*
 * GK20A Graphics Context
 *
 * Copyright (c) 2011-2017, NVIDIA CORPORATION.  All rights reserved.
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
#ifndef __GR_CTX_GK20A_H__
#define __GR_CTX_GK20A_H__

#include <nvgpu/kmem.h>

struct gr_gk20a;

/* emulation netlists, match majorV with HW */
#define GK20A_NETLIST_IMAGE_A	"NETA_img.bin"
#define GK20A_NETLIST_IMAGE_B	"NETB_img.bin"
#define GK20A_NETLIST_IMAGE_C	"NETC_img.bin"
#define GK20A_NETLIST_IMAGE_D   "NETD_img.bin"

/*
 * Need to support multiple ARCH in same GPU family
 * then need to provide path like ARCH/NETIMAGE to
 * point to correct netimage within GPU family,
 * Example, gm20x can support gm204 or gm206,so path
 * for netimage is gm204/NETC_img.bin, and '/' char
 * will inserted at null terminator char of "GAxxx"
 * to get complete path like gm204/NETC_img.bin
 */
#define GPU_ARCH "GAxxx"

union __max_name {
#ifdef GK20A_NETLIST_IMAGE_A
	char __name_a[sizeof(GK20A_NETLIST_IMAGE_A)];
#endif
#ifdef GK20A_NETLIST_IMAGE_B
	char __name_b[sizeof(GK20A_NETLIST_IMAGE_B)];
#endif
#ifdef GK20A_NETLIST_IMAGE_C
	char __name_c[sizeof(GK20A_NETLIST_IMAGE_C)];
#endif
#ifdef GK20A_NETLIST_IMAGE_D
	char __name_d[sizeof(GK20A_NETLIST_IMAGE_D)];
#endif
};

#define MAX_NETLIST_NAME (sizeof(GPU_ARCH) + sizeof(union __max_name))

/* index for emulation netlists */
#define NETLIST_FINAL		-1
#define NETLIST_SLOT_A		0
#define NETLIST_SLOT_B		1
#define NETLIST_SLOT_C		2
#define NETLIST_SLOT_D		3
#define MAX_NETLIST		4

/* netlist regions */
#define NETLIST_REGIONID_FECS_UCODE_DATA	0
#define NETLIST_REGIONID_FECS_UCODE_INST	1
#define NETLIST_REGIONID_GPCCS_UCODE_DATA	2
#define NETLIST_REGIONID_GPCCS_UCODE_INST	3
#define NETLIST_REGIONID_SW_BUNDLE_INIT		4
#define NETLIST_REGIONID_SW_CTX_LOAD		5
#define NETLIST_REGIONID_SW_NON_CTX_LOAD	6
#define NETLIST_REGIONID_SW_METHOD_INIT		7
#define NETLIST_REGIONID_CTXREG_SYS		8
#define NETLIST_REGIONID_CTXREG_GPC		9
#define NETLIST_REGIONID_CTXREG_TPC		10
#define NETLIST_REGIONID_CTXREG_ZCULL_GPC	11
#define NETLIST_REGIONID_CTXREG_PM_SYS		12
#define NETLIST_REGIONID_CTXREG_PM_GPC		13
#define NETLIST_REGIONID_CTXREG_PM_TPC		14
#define NETLIST_REGIONID_MAJORV			15
#define NETLIST_REGIONID_BUFFER_SIZE		16
#define NETLIST_REGIONID_CTXSW_REG_BASE_INDEX	17
#define NETLIST_REGIONID_NETLIST_NUM		18
#define NETLIST_REGIONID_CTXREG_PPC		19
#define NETLIST_REGIONID_CTXREG_PMPPC		20
#define NETLIST_REGIONID_NVPERF_CTXREG_SYS	21
#define NETLIST_REGIONID_NVPERF_FBP_CTXREGS	22
#define NETLIST_REGIONID_NVPERF_CTXREG_GPC	23
#define NETLIST_REGIONID_NVPERF_FBP_ROUTER	24
#define NETLIST_REGIONID_NVPERF_GPC_ROUTER	25
#define NETLIST_REGIONID_CTXREG_PMLTC		26
#define NETLIST_REGIONID_CTXREG_PMFBPA		27
#define NETLIST_REGIONID_SWVEIDBUNDLEINIT       28
#define NETLIST_REGIONID_NVPERF_SYS_ROUTER      29
#define NETLIST_REGIONID_NVPERF_PMA             30
#define NETLIST_REGIONID_CTXREG_PMROP           31
#define NETLIST_REGIONID_CTXREG_PMUCGPC         32
#define NETLIST_REGIONID_CTXREG_ETPC            33
#define NETLIST_REGIONID_SW_BUNDLE64_INIT	34
#define NETLIST_REGIONID_NVPERF_PMCAU		35

struct netlist_region {
	u32 region_id;
	u32 data_size;
	u32 data_offset;
};

struct netlist_image_header {
	u32 version;
	u32 regions;
};

struct netlist_image {
	struct netlist_image_header header;
	struct netlist_region regions[1];
};

struct av_gk20a {
	u32 addr;
	u32 value;
};
struct av64_gk20a {
	u32 addr;
	u32 value_lo;
	u32 value_hi;
};
struct aiv_gk20a {
	u32 addr;
	u32 index;
	u32 value;
};
struct aiv_list_gk20a {
	struct aiv_gk20a *l;
	u32 count;
};
struct av_list_gk20a {
	struct av_gk20a *l;
	u32 count;
};
struct av64_list_gk20a {
	struct av64_gk20a *l;
	u32 count;
};
struct u32_list_gk20a {
	u32 *l;
	u32 count;
};

struct ctxsw_buf_offset_map_entry {
	u32 addr;	/* Register address */
	u32 offset;	/* Offset in ctxt switch buffer */
};

static inline
struct av_gk20a *alloc_av_list_gk20a(struct gk20a *g, struct av_list_gk20a *avl)
{
	avl->l = nvgpu_kzalloc(g, avl->count * sizeof(*avl->l));
	return avl->l;
}

static inline
struct av64_gk20a *alloc_av64_list_gk20a(struct gk20a *g, struct av64_list_gk20a *avl)
{
	avl->l = nvgpu_kzalloc(g, avl->count * sizeof(*avl->l));
	return avl->l;
}

static inline
struct aiv_gk20a *alloc_aiv_list_gk20a(struct gk20a *g,
				       struct aiv_list_gk20a *aivl)
{
	aivl->l = nvgpu_kzalloc(g, aivl->count * sizeof(*aivl->l));
	return aivl->l;
}

static inline
u32 *alloc_u32_list_gk20a(struct gk20a *g, struct u32_list_gk20a *u32l)
{
	u32l->l = nvgpu_kzalloc(g, u32l->count * sizeof(*u32l->l));
	return u32l->l;
}

struct gr_ucode_gk20a {
	struct {
		struct u32_list_gk20a inst;
		struct u32_list_gk20a data;
	} gpccs, fecs;
};

/* main entry for grctx loading */
int gr_gk20a_init_ctx_vars(struct gk20a *g, struct gr_gk20a *gr);
int gr_gk20a_init_ctx_vars_sim(struct gk20a *g, struct gr_gk20a *gr);

struct gpu_ops;
void gk20a_init_gr_ctx(struct gpu_ops *gops);

#endif /*__GR_CTX_GK20A_H__*/
