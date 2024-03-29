/*
 * Copyright (c) 2016-2018, NVIDIA CORPORATION.  All rights reserved.
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
/*
 * Function naming determines intended use:
 *
 *     <x>_r(void) : Returns the offset for register <x>.
 *
 *     <x>_o(void) : Returns the offset for element <x>.
 *
 *     <x>_w(void) : Returns the word offset for word (4 byte) element <x>.
 *
 *     <x>_<y>_s(void) : Returns size of field <y> of register <x> in bits.
 *
 *     <x>_<y>_f(u32 v) : Returns a value based on 'v' which has been shifted
 *         and masked to place it at field <y> of register <x>.  This value
 *         can be |'d with others to produce a full register value for
 *         register <x>.
 *
 *     <x>_<y>_m(void) : Returns a mask for field <y> of register <x>.  This
 *         value can be ~'d and then &'d to clear the value of field <y> for
 *         register <x>.
 *
 *     <x>_<y>_<z>_f(void) : Returns the constant value <z> after being shifted
 *         to place it at field <y> of register <x>.  This value can be |'d
 *         with others to produce a full register value for <x>.
 *
 *     <x>_<y>_v(u32 r) : Returns the value of field <y> from a full register
 *         <x> value 'r' after being shifted to place its LSB at bit 0.
 *         This value is suitable for direct comparison with other unshifted
 *         values appropriate for use in field <y> of register <x>.
 *
 *     <x>_<y>_<z>_v(void) : Returns the constant value for <z> defined for
 *         field <y> of register <x>.  This value is suitable for direct
 *         comparison with unshifted values appropriate for use in field <y>
 *         of register <x>.
 */
#ifndef _hw_gr_gv11b_h_
#define _hw_gr_gv11b_h_

static inline u32 gr_intr_r(void)
{
	return 0x00400100U;
}
static inline u32 gr_intr_notify_pending_f(void)
{
	return 0x1U;
}
static inline u32 gr_intr_notify_reset_f(void)
{
	return 0x1U;
}
static inline u32 gr_intr_semaphore_pending_f(void)
{
	return 0x2U;
}
static inline u32 gr_intr_semaphore_reset_f(void)
{
	return 0x2U;
}
static inline u32 gr_intr_illegal_method_pending_f(void)
{
	return 0x10U;
}
static inline u32 gr_intr_illegal_method_reset_f(void)
{
	return 0x10U;
}
static inline u32 gr_intr_illegal_notify_pending_f(void)
{
	return 0x40U;
}
static inline u32 gr_intr_illegal_notify_reset_f(void)
{
	return 0x40U;
}
static inline u32 gr_intr_firmware_method_f(u32 v)
{
	return (v & 0x1U) << 8U;
}
static inline u32 gr_intr_firmware_method_pending_f(void)
{
	return 0x100U;
}
static inline u32 gr_intr_firmware_method_reset_f(void)
{
	return 0x100U;
}
static inline u32 gr_intr_illegal_class_pending_f(void)
{
	return 0x20U;
}
static inline u32 gr_intr_illegal_class_reset_f(void)
{
	return 0x20U;
}
static inline u32 gr_intr_fecs_error_pending_f(void)
{
	return 0x80000U;
}
static inline u32 gr_intr_fecs_error_reset_f(void)
{
	return 0x80000U;
}
static inline u32 gr_intr_class_error_pending_f(void)
{
	return 0x100000U;
}
static inline u32 gr_intr_class_error_reset_f(void)
{
	return 0x100000U;
}
static inline u32 gr_intr_exception_pending_f(void)
{
	return 0x200000U;
}
static inline u32 gr_intr_exception_reset_f(void)
{
	return 0x200000U;
}
static inline u32 gr_fecs_intr_r(void)
{
	return 0x00400144U;
}
static inline u32 gr_class_error_r(void)
{
	return 0x00400110U;
}
static inline u32 gr_class_error_code_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_intr_nonstall_r(void)
{
	return 0x00400120U;
}
static inline u32 gr_intr_nonstall_trap_pending_f(void)
{
	return 0x2U;
}
static inline u32 gr_intr_en_r(void)
{
	return 0x0040013cU;
}
static inline u32 gr_exception_r(void)
{
	return 0x00400108U;
}
static inline u32 gr_exception_fe_m(void)
{
	return 0x1U << 0U;
}
static inline u32 gr_exception_gpc_m(void)
{
	return 0x1U << 24U;
}
static inline u32 gr_exception_memfmt_m(void)
{
	return 0x1U << 1U;
}
static inline u32 gr_exception_ds_m(void)
{
	return 0x1U << 4U;
}
static inline u32 gr_exception_sked_m(void)
{
	return 0x1U << 8U;
}
static inline u32 gr_exception_pd_m(void)
{
	return 0x1U << 2U;
}
static inline u32 gr_exception_scc_m(void)
{
	return 0x1U << 3U;
}
static inline u32 gr_exception_ssync_m(void)
{
	return 0x1U << 5U;
}
static inline u32 gr_exception_mme_m(void)
{
	return 0x1U << 7U;
}
static inline u32 gr_exception1_r(void)
{
	return 0x00400118U;
}
static inline u32 gr_exception1_gpc_0_pending_f(void)
{
	return 0x1U;
}
static inline u32 gr_exception2_r(void)
{
	return 0x0040011cU;
}
static inline u32 gr_exception_en_r(void)
{
	return 0x00400138U;
}
static inline u32 gr_exception_en_fe_m(void)
{
	return 0x1U << 0U;
}
static inline u32 gr_exception_en_fe_enabled_f(void)
{
	return 0x1U;
}
static inline u32 gr_exception_en_gpc_m(void)
{
	return 0x1U << 24U;
}
static inline u32 gr_exception_en_gpc_enabled_f(void)
{
	return 0x1000000U;
}
static inline u32 gr_exception_en_memfmt_m(void)
{
	return 0x1U << 1U;
}
static inline u32 gr_exception_en_memfmt_enabled_f(void)
{
	return 0x2U;
}
static inline u32 gr_exception_en_ds_m(void)
{
	return 0x1U << 4U;
}
static inline u32 gr_exception_en_ds_enabled_f(void)
{
	return 0x10U;
}
static inline u32 gr_exception_en_pd_m(void)
{
	return 0x1U << 2U;
}
static inline u32 gr_exception_en_pd_enabled_f(void)
{
	return 0x4U;
}
static inline u32 gr_exception_en_scc_m(void)
{
	return 0x1U << 3U;
}
static inline u32 gr_exception_en_scc_enabled_f(void)
{
	return 0x8U;
}
static inline u32 gr_exception_en_ssync_m(void)
{
	return 0x1U << 5U;
}
static inline u32 gr_exception_en_ssync_enabled_f(void)
{
	return 0x20U;
}
static inline u32 gr_exception_en_mme_m(void)
{
	return 0x1U << 7U;
}
static inline u32 gr_exception_en_mme_enabled_f(void)
{
	return 0x80U;
}
static inline u32 gr_exception_en_sked_m(void)
{
	return 0x1U << 8U;
}
static inline u32 gr_exception_en_sked_enabled_f(void)
{
	return 0x100U;
}
static inline u32 gr_exception1_en_r(void)
{
	return 0x00400130U;
}
static inline u32 gr_exception2_en_r(void)
{
	return 0x00400134U;
}
static inline u32 gr_gpfifo_ctl_r(void)
{
	return 0x00400500U;
}
static inline u32 gr_gpfifo_ctl_access_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_gpfifo_ctl_access_disabled_f(void)
{
	return 0x0U;
}
static inline u32 gr_gpfifo_ctl_access_enabled_f(void)
{
	return 0x1U;
}
static inline u32 gr_gpfifo_ctl_semaphore_access_f(u32 v)
{
	return (v & 0x1U) << 16U;
}
static inline u32 gr_gpfifo_ctl_semaphore_access_enabled_v(void)
{
	return 0x00000001U;
}
static inline u32 gr_gpfifo_ctl_semaphore_access_enabled_f(void)
{
	return 0x10000U;
}
static inline u32 gr_gpfifo_status_r(void)
{
	return 0x00400504U;
}
static inline u32 gr_trapped_addr_r(void)
{
	return 0x00400704U;
}
static inline u32 gr_trapped_addr_mthd_v(u32 r)
{
	return (r >> 2U) & 0xfffU;
}
static inline u32 gr_trapped_addr_subch_v(u32 r)
{
	return (r >> 16U) & 0x7U;
}
static inline u32 gr_trapped_addr_mme_generated_v(u32 r)
{
	return (r >> 20U) & 0x1U;
}
static inline u32 gr_trapped_addr_datahigh_v(u32 r)
{
	return (r >> 24U) & 0x1U;
}
static inline u32 gr_trapped_addr_priv_v(u32 r)
{
	return (r >> 28U) & 0x1U;
}
static inline u32 gr_trapped_addr_status_v(u32 r)
{
	return (r >> 31U) & 0x1U;
}
static inline u32 gr_trapped_data_lo_r(void)
{
	return 0x00400708U;
}
static inline u32 gr_trapped_data_hi_r(void)
{
	return 0x0040070cU;
}
static inline u32 gr_trapped_data_mme_r(void)
{
	return 0x00400710U;
}
static inline u32 gr_trapped_data_mme_pc_v(u32 r)
{
	return (r >> 0U) & 0xfffU;
}
static inline u32 gr_status_r(void)
{
	return 0x00400700U;
}
static inline u32 gr_status_fe_method_upper_v(u32 r)
{
	return (r >> 1U) & 0x1U;
}
static inline u32 gr_status_fe_method_lower_v(u32 r)
{
	return (r >> 2U) & 0x1U;
}
static inline u32 gr_status_fe_method_lower_idle_v(void)
{
	return 0x00000000U;
}
static inline u32 gr_status_fe_gi_v(u32 r)
{
	return (r >> 21U) & 0x1U;
}
static inline u32 gr_status_mask_r(void)
{
	return 0x00400610U;
}
static inline u32 gr_status_1_r(void)
{
	return 0x00400604U;
}
static inline u32 gr_status_2_r(void)
{
	return 0x00400608U;
}
static inline u32 gr_engine_status_r(void)
{
	return 0x0040060cU;
}
static inline u32 gr_engine_status_value_busy_f(void)
{
	return 0x1U;
}
static inline u32 gr_pri_be0_becs_be_exception_r(void)
{
	return 0x00410204U;
}
static inline u32 gr_pri_be0_becs_be_exception_en_r(void)
{
	return 0x00410208U;
}
static inline u32 gr_pri_gpc0_gpccs_gpc_exception_r(void)
{
	return 0x00502c90U;
}
static inline u32 gr_pri_gpc0_gpccs_gpc_exception_en_r(void)
{
	return 0x00502c94U;
}
static inline u32 gr_pri_gpc0_tpc0_tpccs_tpc_exception_r(void)
{
	return 0x00504508U;
}
static inline u32 gr_pri_gpc0_tpc0_tpccs_tpc_exception_en_r(void)
{
	return 0x0050450cU;
}
static inline u32 gr_activity_0_r(void)
{
	return 0x00400380U;
}
static inline u32 gr_activity_1_r(void)
{
	return 0x00400384U;
}
static inline u32 gr_activity_2_r(void)
{
	return 0x00400388U;
}
static inline u32 gr_activity_4_r(void)
{
	return 0x00400390U;
}
static inline u32 gr_activity_4_gpc0_s(void)
{
	return 3U;
}
static inline u32 gr_activity_4_gpc0_f(u32 v)
{
	return (v & 0x7U) << 0U;
}
static inline u32 gr_activity_4_gpc0_m(void)
{
	return 0x7U << 0U;
}
static inline u32 gr_activity_4_gpc0_v(u32 r)
{
	return (r >> 0U) & 0x7U;
}
static inline u32 gr_activity_4_gpc0_empty_v(void)
{
	return 0x00000000U;
}
static inline u32 gr_activity_4_gpc0_preempted_v(void)
{
	return 0x00000004U;
}
static inline u32 gr_pri_gpc0_gcc_dbg_r(void)
{
	return 0x00501000U;
}
static inline u32 gr_pri_gpcs_gcc_dbg_r(void)
{
	return 0x00419000U;
}
static inline u32 gr_pri_gpcs_gcc_dbg_invalidate_m(void)
{
	return 0x1U << 1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cache_control_r(void)
{
	return 0x0050433cU;
}
static inline u32 gr_pri_gpcs_tpcs_sm_cache_control_r(void)
{
	return 0x00419b3cU;
}
static inline u32 gr_pri_gpcs_tpcs_sm_cache_control_invalidate_cache_m(void)
{
	return 0x1U << 0U;
}
static inline u32 gr_pri_sked_activity_r(void)
{
	return 0x00407054U;
}
static inline u32 gr_pri_gpc0_gpccs_gpc_activity0_r(void)
{
	return 0x00502c80U;
}
static inline u32 gr_pri_gpc0_gpccs_gpc_activity1_r(void)
{
	return 0x00502c84U;
}
static inline u32 gr_pri_gpc0_gpccs_gpc_activity2_r(void)
{
	return 0x00502c88U;
}
static inline u32 gr_pri_gpc0_gpccs_gpc_activity3_r(void)
{
	return 0x00502c8cU;
}
static inline u32 gr_pri_gpc0_tpc0_tpccs_tpc_activity_0_r(void)
{
	return 0x00504500U;
}
static inline u32 gr_pri_gpc0_tpc1_tpccs_tpc_activity_0_r(void)
{
	return 0x00504d00U;
}
static inline u32 gr_pri_gpc0_tpcs_tpccs_tpc_activity_0_r(void)
{
	return 0x00501d00U;
}
static inline u32 gr_pri_gpcs_gpccs_gpc_activity_0_r(void)
{
	return 0x0041ac80U;
}
static inline u32 gr_pri_gpcs_gpccs_gpc_activity_1_r(void)
{
	return 0x0041ac84U;
}
static inline u32 gr_pri_gpcs_gpccs_gpc_activity_2_r(void)
{
	return 0x0041ac88U;
}
static inline u32 gr_pri_gpcs_gpccs_gpc_activity_3_r(void)
{
	return 0x0041ac8cU;
}
static inline u32 gr_pri_gpcs_tpc0_tpccs_tpc_activity_0_r(void)
{
	return 0x0041c500U;
}
static inline u32 gr_pri_gpcs_tpc1_tpccs_tpc_activity_0_r(void)
{
	return 0x0041cd00U;
}
static inline u32 gr_pri_gpcs_tpcs_tpccs_tpc_activity_0_r(void)
{
	return 0x00419d00U;
}
static inline u32 gr_pri_be0_becs_be_activity0_r(void)
{
	return 0x00410200U;
}
static inline u32 gr_pri_be1_becs_be_activity0_r(void)
{
	return 0x00410600U;
}
static inline u32 gr_pri_bes_becs_be_activity0_r(void)
{
	return 0x00408a00U;
}
static inline u32 gr_pri_ds_mpipe_status_r(void)
{
	return 0x00405858U;
}
static inline u32 gr_pri_fe_go_idle_info_r(void)
{
	return 0x00404194U;
}
static inline u32 gr_pri_fe_chip_def_info_r(void)
{
	return 0x00404030U;
}
static inline u32 gr_pri_fe_chip_def_info_max_veid_count_v(u32 r)
{
	return (r >> 0U) & 0xfffU;
}
static inline u32 gr_pri_fe_chip_def_info_max_veid_count_init_v(void)
{
	return 0x00000040U;
}
static inline u32 gr_pri_gpc0_tpc0_tex_m_tex_subunits_status_r(void)
{
	return 0x00504238U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_r(void)
{
	return 0x00504358U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_corrected_err_qrfdp0_m(void)
{
	return 0x1U << 0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_corrected_err_qrfdp1_m(void)
{
	return 0x1U << 1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_corrected_err_qrfdp2_m(void)
{
	return 0x1U << 2U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_corrected_err_qrfdp3_m(void)
{
	return 0x1U << 3U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_corrected_err_qrfdp4_m(void)
{
	return 0x1U << 4U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_corrected_err_qrfdp5_m(void)
{
	return 0x1U << 5U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_corrected_err_qrfdp6_m(void)
{
	return 0x1U << 6U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_corrected_err_qrfdp7_m(void)
{
	return 0x1U << 7U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_uncorrected_err_qrfdp0_m(void)
{
	return 0x1U << 8U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_uncorrected_err_qrfdp1_m(void)
{
	return 0x1U << 9U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_uncorrected_err_qrfdp2_m(void)
{
	return 0x1U << 10U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_uncorrected_err_qrfdp3_m(void)
{
	return 0x1U << 11U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_uncorrected_err_qrfdp4_m(void)
{
	return 0x1U << 12U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_uncorrected_err_qrfdp5_m(void)
{
	return 0x1U << 13U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_uncorrected_err_qrfdp6_m(void)
{
	return 0x1U << 14U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_uncorrected_err_qrfdp7_m(void)
{
	return 0x1U << 15U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_corrected_err_total_counter_overflow_v(u32 r)
{
	return (r >> 24U) & 0x1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_uncorrected_err_total_counter_overflow_v(u32 r)
{
	return (r >> 26U) & 0x1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_status_reset_task_f(void)
{
	return 0x40000000U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_corrected_err_count_r(void)
{
	return 0x0050435cU;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_corrected_err_count_total_s(void)
{
	return 16U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_corrected_err_count_total_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_uncorrected_err_count_r(void)
{
	return 0x00504360U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_uncorrected_err_count_total_s(void)
{
	return 16U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_uncorrected_err_count_total_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_data_ecc_status_r(void)
{
	return 0x0050436cU;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_data_ecc_status_corrected_err_el1_0_m(void)
{
	return 0x1U << 0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_data_ecc_status_corrected_err_el1_1_m(void)
{
	return 0x1U << 1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_data_ecc_status_uncorrected_err_el1_0_m(void)
{
	return 0x1U << 2U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_data_ecc_status_uncorrected_err_el1_1_m(void)
{
	return 0x1U << 3U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_data_ecc_status_corrected_err_total_counter_overflow_v(u32 r)
{
	return (r >> 8U) & 0x1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_data_ecc_status_uncorrected_err_total_counter_overflow_v(u32 r)
{
	return (r >> 10U) & 0x1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_data_ecc_status_reset_task_f(void)
{
	return 0x40000000U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_data_ecc_corrected_err_count_r(void)
{
	return 0x00504370U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_data_ecc_corrected_err_count_total_s(void)
{
	return 16U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_data_ecc_corrected_err_count_total_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_data_ecc_uncorrected_err_count_r(void)
{
	return 0x00504374U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_data_ecc_uncorrected_err_count_total_s(void)
{
	return 16U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_data_ecc_uncorrected_err_count_total_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_status_r(void)
{
	return 0x0050464cU;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_status_corrected_err_l0_data_m(void)
{
	return 0x1U << 0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_status_corrected_err_l0_predecode_m(void)
{
	return 0x1U << 1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_status_corrected_err_l1_data_m(void)
{
	return 0x1U << 2U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_status_corrected_err_l1_predecode_m(void)
{
	return 0x1U << 3U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_status_uncorrected_err_l0_data_m(void)
{
	return 0x1U << 4U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_status_uncorrected_err_l0_predecode_m(void)
{
	return 0x1U << 5U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_status_uncorrected_err_l1_data_m(void)
{
	return 0x1U << 6U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_status_uncorrected_err_l1_predecode_m(void)
{
	return 0x1U << 7U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_status_corrected_err_total_counter_overflow_v(u32 r)
{
	return (r >> 16U) & 0x1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_status_uncorrected_err_total_counter_overflow_v(u32 r)
{
	return (r >> 18U) & 0x1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_status_reset_task_f(void)
{
	return 0x40000000U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_corrected_err_count_r(void)
{
	return 0x00504650U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_corrected_err_count_total_s(void)
{
	return 16U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_corrected_err_count_total_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_uncorrected_err_count_r(void)
{
	return 0x00504654U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_uncorrected_err_count_total_s(void)
{
	return 16U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_uncorrected_err_count_total_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_r(void)
{
	return 0x00504624U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_corrected_err_el1_0_m(void)
{
	return 0x1U << 0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_corrected_err_el1_1_m(void)
{
	return 0x1U << 1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_uncorrected_err_el1_0_m(void)
{
	return 0x1U << 2U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_uncorrected_err_el1_1_m(void)
{
	return 0x1U << 3U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_corrected_err_pixrpf_m(void)
{
	return 0x1U << 4U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_corrected_err_miss_fifo_m(void)
{
	return 0x1U << 5U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_uncorrected_err_pixrpf_m(void)
{
	return 0x1U << 6U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_uncorrected_err_miss_fifo_m(void)
{
	return 0x1U << 7U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_corrected_err_total_counter_overflow_v(u32 r)
{
	return (r >> 8U) & 0x1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_uncorrected_err_total_counter_overflow_v(u32 r)
{
	return (r >> 10U) & 0x1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_reset_task_f(void)
{
	return 0x40000000U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_corrected_err_count_r(void)
{
	return 0x00504628U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_corrected_err_count_total_s(void)
{
	return 16U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_corrected_err_count_total_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_uncorrected_err_count_r(void)
{
	return 0x0050462cU;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_uncorrected_err_count_total_s(void)
{
	return 16U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_uncorrected_err_count_total_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_status_r(void)
{
	return 0x00504638U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_status_corrected_err_warp_sm0_m(void)
{
	return 0x1U << 0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_status_corrected_err_warp_sm1_m(void)
{
	return 0x1U << 1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_status_corrected_err_barrier_sm0_m(void)
{
	return 0x1U << 2U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_status_corrected_err_barrier_sm1_m(void)
{
	return 0x1U << 3U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_status_uncorrected_err_warp_sm0_m(void)
{
	return 0x1U << 4U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_status_uncorrected_err_warp_sm1_m(void)
{
	return 0x1U << 5U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_status_uncorrected_err_barrier_sm0_m(void)
{
	return 0x1U << 6U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_status_uncorrected_err_barrier_sm1_m(void)
{
	return 0x1U << 7U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_status_corrected_err_total_counter_overflow_v(u32 r)
{
	return (r >> 16U) & 0x1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_status_uncorrected_err_total_counter_overflow_v(u32 r)
{
	return (r >> 18U) & 0x1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_status_reset_task_f(void)
{
	return 0x40000000U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_corrected_err_count_r(void)
{
	return 0x0050463cU;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_corrected_err_count_total_s(void)
{
	return 16U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_corrected_err_count_total_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_uncorrected_err_count_r(void)
{
	return 0x00504640U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_uncorrected_err_count_total_s(void)
{
	return 16U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_uncorrected_err_count_total_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_pri_gpcs_tpcs_sm_lrf_ecc_control_r(void)
{
	return 0x00419b54U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp0_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp0_task_f(void)
{
	return 0x1U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp1_f(u32 v)
{
	return (v & 0x1U) << 1U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp1_task_f(void)
{
	return 0x2U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp2_f(u32 v)
{
	return (v & 0x1U) << 2U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp2_task_f(void)
{
	return 0x4U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp3_f(u32 v)
{
	return (v & 0x1U) << 3U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp3_task_f(void)
{
	return 0x8U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp4_f(u32 v)
{
	return (v & 0x1U) << 4U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp4_task_f(void)
{
	return 0x10U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp5_f(u32 v)
{
	return (v & 0x1U) << 5U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp5_task_f(void)
{
	return 0x20U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp6_f(u32 v)
{
	return (v & 0x1U) << 6U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp6_task_f(void)
{
	return 0x40U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp7_f(u32 v)
{
	return (v & 0x1U) << 7U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp7_task_f(void)
{
	return 0x80U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_control_r(void)
{
	return 0x00504354U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp0_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp0_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp1_f(u32 v)
{
	return (v & 0x1U) << 1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp1_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp2_f(u32 v)
{
	return (v & 0x1U) << 2U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp2_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp3_f(u32 v)
{
	return (v & 0x1U) << 3U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp3_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp4_f(u32 v)
{
	return (v & 0x1U) << 4U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp4_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp5_f(u32 v)
{
	return (v & 0x1U) << 5U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp5_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp6_f(u32 v)
{
	return (v & 0x1U) << 6U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp6_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp7_f(u32 v)
{
	return (v & 0x1U) << 7U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp7_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_l1_data_ecc_control_r(void)
{
	return 0x00419b68U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_l1_data_ecc_control_scrub_el1_0_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_l1_data_ecc_control_scrub_el1_0_task_f(void)
{
	return 0x1U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_l1_data_ecc_control_scrub_el1_1_f(u32 v)
{
	return (v & 0x1U) << 1U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_l1_data_ecc_control_scrub_el1_1_task_f(void)
{
	return 0x2U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_data_ecc_control_r(void)
{
	return 0x00504368U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_data_ecc_control_scrub_el1_0_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_data_ecc_control_scrub_el1_0_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_data_ecc_control_scrub_el1_1_f(u32 v)
{
	return (v & 0x1U) << 1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_data_ecc_control_scrub_el1_1_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_l1_tag_ecc_control_r(void)
{
	return 0x00419e20U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_l1_tag_ecc_control_scrub_el1_0_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_l1_tag_ecc_control_scrub_el1_0_task_f(void)
{
	return 0x1U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_l1_tag_ecc_control_scrub_el1_1_f(u32 v)
{
	return (v & 0x1U) << 1U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_l1_tag_ecc_control_scrub_el1_1_task_f(void)
{
	return 0x2U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_l1_tag_ecc_control_scrub_pixprf_f(u32 v)
{
	return (v & 0x1U) << 4U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_l1_tag_ecc_control_scrub_pixprf_task_f(void)
{
	return 0x10U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_l1_tag_ecc_control_scrub_miss_fifo_f(u32 v)
{
	return (v & 0x1U) << 5U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_l1_tag_ecc_control_scrub_miss_fifo_task_f(void)
{
	return 0x20U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_r(void)
{
	return 0x00504620U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_scrub_el1_0_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_scrub_el1_0_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_scrub_el1_1_f(u32 v)
{
	return (v & 0x1U) << 1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_scrub_el1_1_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_scrub_pixprf_f(u32 v)
{
	return (v & 0x1U) << 4U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_scrub_pixprf_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_scrub_miss_fifo_f(u32 v)
{
	return (v & 0x1U) << 5U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_scrub_miss_fifo_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_cbu_ecc_control_r(void)
{
	return 0x00419e34U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_cbu_ecc_control_scrub_warp_sm0_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_cbu_ecc_control_scrub_warp_sm0_task_f(void)
{
	return 0x1U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_cbu_ecc_control_scrub_warp_sm1_f(u32 v)
{
	return (v & 0x1U) << 1U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_cbu_ecc_control_scrub_warp_sm1_task_f(void)
{
	return 0x2U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_cbu_ecc_control_scrub_barrier_sm0_f(u32 v)
{
	return (v & 0x1U) << 2U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_cbu_ecc_control_scrub_barrier_sm0_task_f(void)
{
	return 0x4U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_cbu_ecc_control_scrub_barrier_sm1_f(u32 v)
{
	return (v & 0x1U) << 3U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_cbu_ecc_control_scrub_barrier_sm1_task_f(void)
{
	return 0x8U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_control_r(void)
{
	return 0x00504634U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_control_scrub_warp_sm0_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_control_scrub_warp_sm0_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_control_scrub_warp_sm1_f(u32 v)
{
	return (v & 0x1U) << 1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_control_scrub_warp_sm1_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_control_scrub_barrier_sm0_f(u32 v)
{
	return (v & 0x1U) << 2U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_control_scrub_barrier_sm0_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_control_scrub_barrier_sm1_f(u32 v)
{
	return (v & 0x1U) << 3U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_cbu_ecc_control_scrub_barrier_sm1_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_icache_ecc_control_r(void)
{
	return 0x00419e48U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_icache_ecc_control_scrub_l0_data_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_icache_ecc_control_scrub_l0_data_task_f(void)
{
	return 0x1U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_icache_ecc_control_scrub_l0_predecode_f(u32 v)
{
	return (v & 0x1U) << 1U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_icache_ecc_control_scrub_l0_predecode_task_f(void)
{
	return 0x2U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_icache_ecc_control_scrub_l1_data_f(u32 v)
{
	return (v & 0x1U) << 2U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_icache_ecc_control_scrub_l1_data_task_f(void)
{
	return 0x4U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_icache_ecc_control_scrub_l1_predecode_f(u32 v)
{
	return (v & 0x1U) << 3U;
}
static inline u32 gr_pri_gpcs_tpcs_sm_icache_ecc_control_scrub_l1_predecode_task_f(void)
{
	return 0x8U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_control_r(void)
{
	return 0x00504648U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_control_scrub_l0_data_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_control_scrub_l0_data_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_control_scrub_l0_predecode_f(u32 v)
{
	return (v & 0x1U) << 1U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_control_scrub_l0_predecode_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_control_scrub_l1_data_f(u32 v)
{
	return (v & 0x1U) << 2U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_control_scrub_l1_data_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_control_scrub_l1_predecode_f(u32 v)
{
	return (v & 0x1U) << 3U;
}
static inline u32 gr_pri_gpc0_tpc0_sm_icache_ecc_control_scrub_l1_predecode_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpc0_tpc0_tex_m_routing_r(void)
{
	return 0x005042c4U;
}
static inline u32 gr_pri_gpc0_tpc0_tex_m_routing_sel_default_f(void)
{
	return 0x0U;
}
static inline u32 gr_pri_gpc0_tpc0_tex_m_routing_sel_pipe0_f(void)
{
	return 0x1U;
}
static inline u32 gr_pri_gpc0_tpc0_tex_m_routing_sel_pipe1_f(void)
{
	return 0x2U;
}
static inline u32 gr_gpc0_tpc0_mpc_hww_esr_r(void)
{
	return 0x00504430U;
}
static inline u32 gr_gpc0_tpc0_mpc_hww_esr_reset_trigger_f(void)
{
	return 0x40000000U;
}
static inline u32 gr_gpc0_tpc0_mpc_hww_esr_info_r(void)
{
	return 0x00504434U;
}
static inline u32 gr_gpc0_tpc0_mpc_hww_esr_info_veid_v(u32 r)
{
	return (r >> 0U) & 0x3fU;
}
static inline u32 gr_pri_be0_crop_status1_r(void)
{
	return 0x00410134U;
}
static inline u32 gr_pri_bes_crop_status1_r(void)
{
	return 0x00408934U;
}
static inline u32 gr_pri_be0_zrop_status_r(void)
{
	return 0x00410048U;
}
static inline u32 gr_pri_be0_zrop_status2_r(void)
{
	return 0x0041004cU;
}
static inline u32 gr_pri_bes_zrop_status_r(void)
{
	return 0x00408848U;
}
static inline u32 gr_pri_bes_zrop_status2_r(void)
{
	return 0x0040884cU;
}
static inline u32 gr_pipe_bundle_address_r(void)
{
	return 0x00400200U;
}
static inline u32 gr_pipe_bundle_address_value_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_pipe_bundle_address_veid_f(u32 v)
{
	return (v & 0x3fU) << 20U;
}
static inline u32 gr_pipe_bundle_address_veid_w(void)
{
	return 0U;
}
static inline u32 gr_pipe_bundle_data_r(void)
{
	return 0x00400204U;
}
static inline u32 gr_pipe_bundle_config_r(void)
{
	return 0x00400208U;
}
static inline u32 gr_pipe_bundle_config_override_pipe_mode_disabled_f(void)
{
	return 0x0U;
}
static inline u32 gr_pipe_bundle_config_override_pipe_mode_enabled_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_fe_hww_esr_r(void)
{
	return 0x00404000U;
}
static inline u32 gr_fe_hww_esr_reset_active_f(void)
{
	return 0x40000000U;
}
static inline u32 gr_fe_hww_esr_en_enable_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_fe_hww_esr_info_r(void)
{
	return 0x004041b0U;
}
static inline u32 gr_gpcs_tpcs_sms_hww_global_esr_report_mask_r(void)
{
	return 0x00419eacU;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_global_esr_report_mask_r(void)
{
	return 0x0050472cU;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_global_esr_report_mask_multiple_warp_errors_report_f(void)
{
	return 0x4U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_global_esr_report_mask_bpt_int_report_f(void)
{
	return 0x10U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_global_esr_report_mask_bpt_pause_report_f(void)
{
	return 0x20U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_global_esr_report_mask_single_step_complete_report_f(void)
{
	return 0x40U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_global_esr_report_mask_error_in_trap_report_f(void)
{
	return 0x100U;
}
static inline u32 gr_gpcs_tpcs_sms_hww_global_esr_r(void)
{
	return 0x00419eb4U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_global_esr_r(void)
{
	return 0x00504734U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_global_esr_bpt_int_m(void)
{
	return 0x1U << 4U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_global_esr_bpt_int_pending_f(void)
{
	return 0x10U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_global_esr_bpt_pause_m(void)
{
	return 0x1U << 5U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_global_esr_bpt_pause_pending_f(void)
{
	return 0x20U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_global_esr_single_step_complete_m(void)
{
	return 0x1U << 6U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_global_esr_single_step_complete_pending_f(void)
{
	return 0x40U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_global_esr_multiple_warp_errors_m(void)
{
	return 0x1U << 2U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_global_esr_multiple_warp_errors_pending_f(void)
{
	return 0x4U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_global_esr_error_in_trap_m(void)
{
	return 0x1U << 8U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_global_esr_error_in_trap_pending_f(void)
{
	return 0x100U;
}
static inline u32 gr_fe_go_idle_timeout_r(void)
{
	return 0x00404154U;
}
static inline u32 gr_fe_go_idle_timeout_count_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_fe_go_idle_timeout_count_disabled_f(void)
{
	return 0x0U;
}
static inline u32 gr_fe_go_idle_timeout_count_prod_f(void)
{
	return 0x1800U;
}
static inline u32 gr_fe_object_table_r(u32 i)
{
	return 0x00404200U + i*4U;
}
static inline u32 gr_fe_object_table_nvclass_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_fe_tpc_fs_r(u32 i)
{
	return 0x0040a200U + i*4U;
}
static inline u32 gr_fe_tpc_pesmask_r(void)
{
	return 0x0040a260U;
}
static inline u32 gr_fe_tpc_pesmask_pesid_f(u32 v)
{
	return (v & 0x3fU) << 24U;
}
static inline u32 gr_fe_tpc_pesmask_gpcid_f(u32 v)
{
	return (v & 0xffU) << 16U;
}
static inline u32 gr_fe_tpc_pesmask_action_m(void)
{
	return 0x1U << 30U;
}
static inline u32 gr_fe_tpc_pesmask_action_write_f(void)
{
	return 0x40000000U;
}
static inline u32 gr_fe_tpc_pesmask_action_read_f(void)
{
	return 0x0U;
}
static inline u32 gr_fe_tpc_pesmask_req_m(void)
{
	return 0x1U << 31U;
}
static inline u32 gr_fe_tpc_pesmask_req_send_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_fe_tpc_pesmask_mask_m(void)
{
	return 0xffffU << 0U;
}
static inline u32 gr_pri_mme_shadow_raw_index_r(void)
{
	return 0x00404488U;
}
static inline u32 gr_pri_mme_shadow_raw_index_write_trigger_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_pri_mme_shadow_raw_data_r(void)
{
	return 0x0040448cU;
}
static inline u32 gr_mme_hww_esr_r(void)
{
	return 0x00404490U;
}
static inline u32 gr_mme_hww_esr_reset_active_f(void)
{
	return 0x40000000U;
}
static inline u32 gr_mme_hww_esr_en_enable_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_mme_hww_esr_info_r(void)
{
	return 0x00404494U;
}
static inline u32 gr_memfmt_hww_esr_r(void)
{
	return 0x00404600U;
}
static inline u32 gr_memfmt_hww_esr_reset_active_f(void)
{
	return 0x40000000U;
}
static inline u32 gr_memfmt_hww_esr_en_enable_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_fecs_cpuctl_r(void)
{
	return 0x00409100U;
}
static inline u32 gr_fecs_cpuctl_startcpu_f(u32 v)
{
	return (v & 0x1U) << 1U;
}
static inline u32 gr_fecs_cpuctl_alias_r(void)
{
	return 0x00409130U;
}
static inline u32 gr_fecs_cpuctl_alias_startcpu_f(u32 v)
{
	return (v & 0x1U) << 1U;
}
static inline u32 gr_fecs_dmactl_r(void)
{
	return 0x0040910cU;
}
static inline u32 gr_fecs_dmactl_require_ctx_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_fecs_dmactl_dmem_scrubbing_m(void)
{
	return 0x1U << 1U;
}
static inline u32 gr_fecs_dmactl_imem_scrubbing_m(void)
{
	return 0x1U << 2U;
}
static inline u32 gr_fecs_os_r(void)
{
	return 0x00409080U;
}
static inline u32 gr_fecs_idlestate_r(void)
{
	return 0x0040904cU;
}
static inline u32 gr_fecs_mailbox0_r(void)
{
	return 0x00409040U;
}
static inline u32 gr_fecs_mailbox1_r(void)
{
	return 0x00409044U;
}
static inline u32 gr_fecs_irqstat_r(void)
{
	return 0x00409008U;
}
static inline u32 gr_fecs_irqmode_r(void)
{
	return 0x0040900cU;
}
static inline u32 gr_fecs_irqmask_r(void)
{
	return 0x00409018U;
}
static inline u32 gr_fecs_irqdest_r(void)
{
	return 0x0040901cU;
}
static inline u32 gr_fecs_curctx_r(void)
{
	return 0x00409050U;
}
static inline u32 gr_fecs_nxtctx_r(void)
{
	return 0x00409054U;
}
static inline u32 gr_fecs_engctl_r(void)
{
	return 0x004090a4U;
}
static inline u32 gr_fecs_debug1_r(void)
{
	return 0x00409090U;
}
static inline u32 gr_fecs_debuginfo_r(void)
{
	return 0x00409094U;
}
static inline u32 gr_fecs_icd_cmd_r(void)
{
	return 0x00409200U;
}
static inline u32 gr_fecs_icd_cmd_opc_s(void)
{
	return 4U;
}
static inline u32 gr_fecs_icd_cmd_opc_f(u32 v)
{
	return (v & 0xfU) << 0U;
}
static inline u32 gr_fecs_icd_cmd_opc_m(void)
{
	return 0xfU << 0U;
}
static inline u32 gr_fecs_icd_cmd_opc_v(u32 r)
{
	return (r >> 0U) & 0xfU;
}
static inline u32 gr_fecs_icd_cmd_opc_rreg_f(void)
{
	return 0x8U;
}
static inline u32 gr_fecs_icd_cmd_opc_rstat_f(void)
{
	return 0xeU;
}
static inline u32 gr_fecs_icd_cmd_idx_f(u32 v)
{
	return (v & 0x1fU) << 8U;
}
static inline u32 gr_fecs_icd_rdata_r(void)
{
	return 0x0040920cU;
}
static inline u32 gr_fecs_imemc_r(u32 i)
{
	return 0x00409180U + i*16U;
}
static inline u32 gr_fecs_imemc_offs_f(u32 v)
{
	return (v & 0x3fU) << 2U;
}
static inline u32 gr_fecs_imemc_blk_f(u32 v)
{
	return (v & 0xffU) << 8U;
}
static inline u32 gr_fecs_imemc_aincw_f(u32 v)
{
	return (v & 0x1U) << 24U;
}
static inline u32 gr_fecs_imemd_r(u32 i)
{
	return 0x00409184U + i*16U;
}
static inline u32 gr_fecs_imemt_r(u32 i)
{
	return 0x00409188U + i*16U;
}
static inline u32 gr_fecs_imemt_tag_f(u32 v)
{
	return (v & 0xffffU) << 0U;
}
static inline u32 gr_fecs_dmemc_r(u32 i)
{
	return 0x004091c0U + i*8U;
}
static inline u32 gr_fecs_dmemc_offs_s(void)
{
	return 6U;
}
static inline u32 gr_fecs_dmemc_offs_f(u32 v)
{
	return (v & 0x3fU) << 2U;
}
static inline u32 gr_fecs_dmemc_offs_m(void)
{
	return 0x3fU << 2U;
}
static inline u32 gr_fecs_dmemc_offs_v(u32 r)
{
	return (r >> 2U) & 0x3fU;
}
static inline u32 gr_fecs_dmemc_blk_f(u32 v)
{
	return (v & 0xffU) << 8U;
}
static inline u32 gr_fecs_dmemc_aincw_f(u32 v)
{
	return (v & 0x1U) << 24U;
}
static inline u32 gr_fecs_dmemd_r(u32 i)
{
	return 0x004091c4U + i*8U;
}
static inline u32 gr_fecs_dmatrfbase_r(void)
{
	return 0x00409110U;
}
static inline u32 gr_fecs_dmatrfmoffs_r(void)
{
	return 0x00409114U;
}
static inline u32 gr_fecs_dmatrffboffs_r(void)
{
	return 0x0040911cU;
}
static inline u32 gr_fecs_dmatrfcmd_r(void)
{
	return 0x00409118U;
}
static inline u32 gr_fecs_dmatrfcmd_imem_f(u32 v)
{
	return (v & 0x1U) << 4U;
}
static inline u32 gr_fecs_dmatrfcmd_write_f(u32 v)
{
	return (v & 0x1U) << 5U;
}
static inline u32 gr_fecs_dmatrfcmd_size_f(u32 v)
{
	return (v & 0x7U) << 8U;
}
static inline u32 gr_fecs_dmatrfcmd_ctxdma_f(u32 v)
{
	return (v & 0x7U) << 12U;
}
static inline u32 gr_fecs_bootvec_r(void)
{
	return 0x00409104U;
}
static inline u32 gr_fecs_bootvec_vec_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_fecs_falcon_hwcfg_r(void)
{
	return 0x00409108U;
}
static inline u32 gr_gpcs_gpccs_falcon_hwcfg_r(void)
{
	return 0x0041a108U;
}
static inline u32 gr_fecs_falcon_rm_r(void)
{
	return 0x00409084U;
}
static inline u32 gr_fecs_current_ctx_r(void)
{
	return 0x00409b00U;
}
static inline u32 gr_fecs_current_ctx_ptr_f(u32 v)
{
	return (v & 0xfffffffU) << 0U;
}
static inline u32 gr_fecs_current_ctx_ptr_v(u32 r)
{
	return (r >> 0U) & 0xfffffffU;
}
static inline u32 gr_fecs_current_ctx_target_s(void)
{
	return 2U;
}
static inline u32 gr_fecs_current_ctx_target_f(u32 v)
{
	return (v & 0x3U) << 28U;
}
static inline u32 gr_fecs_current_ctx_target_m(void)
{
	return 0x3U << 28U;
}
static inline u32 gr_fecs_current_ctx_target_v(u32 r)
{
	return (r >> 28U) & 0x3U;
}
static inline u32 gr_fecs_current_ctx_target_vid_mem_f(void)
{
	return 0x0U;
}
static inline u32 gr_fecs_current_ctx_target_sys_mem_coh_f(void)
{
	return 0x20000000U;
}
static inline u32 gr_fecs_current_ctx_target_sys_mem_ncoh_f(void)
{
	return 0x30000000U;
}
static inline u32 gr_fecs_current_ctx_valid_s(void)
{
	return 1U;
}
static inline u32 gr_fecs_current_ctx_valid_f(u32 v)
{
	return (v & 0x1U) << 31U;
}
static inline u32 gr_fecs_current_ctx_valid_m(void)
{
	return 0x1U << 31U;
}
static inline u32 gr_fecs_current_ctx_valid_v(u32 r)
{
	return (r >> 31U) & 0x1U;
}
static inline u32 gr_fecs_current_ctx_valid_false_f(void)
{
	return 0x0U;
}
static inline u32 gr_fecs_method_data_r(void)
{
	return 0x00409500U;
}
static inline u32 gr_fecs_method_push_r(void)
{
	return 0x00409504U;
}
static inline u32 gr_fecs_method_push_adr_f(u32 v)
{
	return (v & 0xfffU) << 0U;
}
static inline u32 gr_fecs_method_push_adr_bind_pointer_v(void)
{
	return 0x00000003U;
}
static inline u32 gr_fecs_method_push_adr_bind_pointer_f(void)
{
	return 0x3U;
}
static inline u32 gr_fecs_method_push_adr_discover_image_size_v(void)
{
	return 0x00000010U;
}
static inline u32 gr_fecs_method_push_adr_wfi_golden_save_v(void)
{
	return 0x00000009U;
}
static inline u32 gr_fecs_method_push_adr_restore_golden_v(void)
{
	return 0x00000015U;
}
static inline u32 gr_fecs_method_push_adr_discover_zcull_image_size_v(void)
{
	return 0x00000016U;
}
static inline u32 gr_fecs_method_push_adr_discover_pm_image_size_v(void)
{
	return 0x00000025U;
}
static inline u32 gr_fecs_method_push_adr_discover_reglist_image_size_v(void)
{
	return 0x00000030U;
}
static inline u32 gr_fecs_method_push_adr_set_reglist_bind_instance_v(void)
{
	return 0x00000031U;
}
static inline u32 gr_fecs_method_push_adr_set_reglist_virtual_address_v(void)
{
	return 0x00000032U;
}
static inline u32 gr_fecs_method_push_adr_stop_ctxsw_v(void)
{
	return 0x00000038U;
}
static inline u32 gr_fecs_method_push_adr_start_ctxsw_v(void)
{
	return 0x00000039U;
}
static inline u32 gr_fecs_method_push_adr_set_watchdog_timeout_f(void)
{
	return 0x21U;
}
static inline u32 gr_fecs_method_push_adr_discover_preemption_image_size_v(void)
{
	return 0x0000001aU;
}
static inline u32 gr_fecs_method_push_adr_halt_pipeline_v(void)
{
	return 0x00000004U;
}
static inline u32 gr_fecs_method_push_adr_configure_interrupt_completion_option_v(void)
{
	return 0x0000003aU;
}
static inline u32 gr_fecs_host_int_status_r(void)
{
	return 0x00409c18U;
}
static inline u32 gr_fecs_host_int_status_fault_during_ctxsw_f(u32 v)
{
	return (v & 0x1U) << 16U;
}
static inline u32 gr_fecs_host_int_status_umimp_firmware_method_f(u32 v)
{
	return (v & 0x1U) << 17U;
}
static inline u32 gr_fecs_host_int_status_umimp_illegal_method_f(u32 v)
{
	return (v & 0x1U) << 18U;
}
static inline u32 gr_fecs_host_int_status_ctxsw_intr_f(u32 v)
{
	return (v & 0xffffU) << 0U;
}
static inline u32 gr_fecs_host_int_status_ecc_corrected_f(u32 v)
{
	return (v & 0x1U) << 21U;
}
static inline u32 gr_fecs_host_int_status_ecc_corrected_m(void)
{
	return 0x1U << 21U;
}
static inline u32 gr_fecs_host_int_status_ecc_uncorrected_f(u32 v)
{
	return (v & 0x1U) << 22U;
}
static inline u32 gr_fecs_host_int_status_ecc_uncorrected_m(void)
{
	return 0x1U << 22U;
}
static inline u32 gr_fecs_host_int_clear_r(void)
{
	return 0x00409c20U;
}
static inline u32 gr_fecs_host_int_clear_ctxsw_intr1_f(u32 v)
{
	return (v & 0x1U) << 1U;
}
static inline u32 gr_fecs_host_int_clear_ctxsw_intr1_clear_f(void)
{
	return 0x2U;
}
static inline u32 gr_fecs_host_int_enable_r(void)
{
	return 0x00409c24U;
}
static inline u32 gr_fecs_host_int_enable_ctxsw_intr1_enable_f(void)
{
	return 0x2U;
}
static inline u32 gr_fecs_host_int_enable_fault_during_ctxsw_enable_f(void)
{
	return 0x10000U;
}
static inline u32 gr_fecs_host_int_enable_umimp_firmware_method_enable_f(void)
{
	return 0x20000U;
}
static inline u32 gr_fecs_host_int_enable_umimp_illegal_method_enable_f(void)
{
	return 0x40000U;
}
static inline u32 gr_fecs_host_int_enable_watchdog_enable_f(void)
{
	return 0x80000U;
}
static inline u32 gr_fecs_host_int_enable_flush_when_busy_enable_f(void)
{
	return 0x100000U;
}
static inline u32 gr_fecs_host_int_enable_ecc_corrected_enable_f(void)
{
	return 0x200000U;
}
static inline u32 gr_fecs_host_int_enable_ecc_uncorrected_enable_f(void)
{
	return 0x400000U;
}
static inline u32 gr_fecs_ctxsw_reset_ctl_r(void)
{
	return 0x00409614U;
}
static inline u32 gr_fecs_ctxsw_reset_ctl_sys_halt_disabled_f(void)
{
	return 0x0U;
}
static inline u32 gr_fecs_ctxsw_reset_ctl_gpc_halt_disabled_f(void)
{
	return 0x0U;
}
static inline u32 gr_fecs_ctxsw_reset_ctl_be_halt_disabled_f(void)
{
	return 0x0U;
}
static inline u32 gr_fecs_ctxsw_reset_ctl_sys_engine_reset_disabled_f(void)
{
	return 0x10U;
}
static inline u32 gr_fecs_ctxsw_reset_ctl_gpc_engine_reset_disabled_f(void)
{
	return 0x20U;
}
static inline u32 gr_fecs_ctxsw_reset_ctl_be_engine_reset_disabled_f(void)
{
	return 0x40U;
}
static inline u32 gr_fecs_ctxsw_reset_ctl_sys_context_reset_enabled_f(void)
{
	return 0x0U;
}
static inline u32 gr_fecs_ctxsw_reset_ctl_sys_context_reset_disabled_f(void)
{
	return 0x100U;
}
static inline u32 gr_fecs_ctxsw_reset_ctl_gpc_context_reset_enabled_f(void)
{
	return 0x0U;
}
static inline u32 gr_fecs_ctxsw_reset_ctl_gpc_context_reset_disabled_f(void)
{
	return 0x200U;
}
static inline u32 gr_fecs_ctxsw_reset_ctl_be_context_reset_s(void)
{
	return 1U;
}
static inline u32 gr_fecs_ctxsw_reset_ctl_be_context_reset_f(u32 v)
{
	return (v & 0x1U) << 10U;
}
static inline u32 gr_fecs_ctxsw_reset_ctl_be_context_reset_m(void)
{
	return 0x1U << 10U;
}
static inline u32 gr_fecs_ctxsw_reset_ctl_be_context_reset_v(u32 r)
{
	return (r >> 10U) & 0x1U;
}
static inline u32 gr_fecs_ctxsw_reset_ctl_be_context_reset_enabled_f(void)
{
	return 0x0U;
}
static inline u32 gr_fecs_ctxsw_reset_ctl_be_context_reset_disabled_f(void)
{
	return 0x400U;
}
static inline u32 gr_fecs_ctx_state_store_major_rev_id_r(void)
{
	return 0x0040960cU;
}
static inline u32 gr_fecs_ctxsw_mailbox_r(u32 i)
{
	return 0x00409800U + i*4U;
}
static inline u32 gr_fecs_ctxsw_mailbox__size_1_v(void)
{
	return 0x00000010U;
}
static inline u32 gr_fecs_ctxsw_mailbox_value_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_fecs_ctxsw_mailbox_value_pass_v(void)
{
	return 0x00000001U;
}
static inline u32 gr_fecs_ctxsw_mailbox_value_fail_v(void)
{
	return 0x00000002U;
}
static inline u32 gr_fecs_ctxsw_mailbox_set_r(u32 i)
{
	return 0x004098c0U + i*4U;
}
static inline u32 gr_fecs_ctxsw_mailbox_set_value_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_fecs_ctxsw_mailbox_clear_r(u32 i)
{
	return 0x00409840U + i*4U;
}
static inline u32 gr_fecs_ctxsw_mailbox_clear_value_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_fecs_fs_r(void)
{
	return 0x00409604U;
}
static inline u32 gr_fecs_fs_num_available_gpcs_s(void)
{
	return 5U;
}
static inline u32 gr_fecs_fs_num_available_gpcs_f(u32 v)
{
	return (v & 0x1fU) << 0U;
}
static inline u32 gr_fecs_fs_num_available_gpcs_m(void)
{
	return 0x1fU << 0U;
}
static inline u32 gr_fecs_fs_num_available_gpcs_v(u32 r)
{
	return (r >> 0U) & 0x1fU;
}
static inline u32 gr_fecs_fs_num_available_fbps_s(void)
{
	return 5U;
}
static inline u32 gr_fecs_fs_num_available_fbps_f(u32 v)
{
	return (v & 0x1fU) << 16U;
}
static inline u32 gr_fecs_fs_num_available_fbps_m(void)
{
	return 0x1fU << 16U;
}
static inline u32 gr_fecs_fs_num_available_fbps_v(u32 r)
{
	return (r >> 16U) & 0x1fU;
}
static inline u32 gr_fecs_cfg_r(void)
{
	return 0x00409620U;
}
static inline u32 gr_fecs_cfg_imem_sz_v(u32 r)
{
	return (r >> 0U) & 0xffU;
}
static inline u32 gr_fecs_rc_lanes_r(void)
{
	return 0x00409880U;
}
static inline u32 gr_fecs_rc_lanes_num_chains_s(void)
{
	return 6U;
}
static inline u32 gr_fecs_rc_lanes_num_chains_f(u32 v)
{
	return (v & 0x3fU) << 0U;
}
static inline u32 gr_fecs_rc_lanes_num_chains_m(void)
{
	return 0x3fU << 0U;
}
static inline u32 gr_fecs_rc_lanes_num_chains_v(u32 r)
{
	return (r >> 0U) & 0x3fU;
}
static inline u32 gr_fecs_ctxsw_status_1_r(void)
{
	return 0x00409400U;
}
static inline u32 gr_fecs_ctxsw_status_1_arb_busy_s(void)
{
	return 1U;
}
static inline u32 gr_fecs_ctxsw_status_1_arb_busy_f(u32 v)
{
	return (v & 0x1U) << 12U;
}
static inline u32 gr_fecs_ctxsw_status_1_arb_busy_m(void)
{
	return 0x1U << 12U;
}
static inline u32 gr_fecs_ctxsw_status_1_arb_busy_v(u32 r)
{
	return (r >> 12U) & 0x1U;
}
static inline u32 gr_fecs_arb_ctx_adr_r(void)
{
	return 0x00409a24U;
}
static inline u32 gr_fecs_new_ctx_r(void)
{
	return 0x00409b04U;
}
static inline u32 gr_fecs_new_ctx_ptr_s(void)
{
	return 28U;
}
static inline u32 gr_fecs_new_ctx_ptr_f(u32 v)
{
	return (v & 0xfffffffU) << 0U;
}
static inline u32 gr_fecs_new_ctx_ptr_m(void)
{
	return 0xfffffffU << 0U;
}
static inline u32 gr_fecs_new_ctx_ptr_v(u32 r)
{
	return (r >> 0U) & 0xfffffffU;
}
static inline u32 gr_fecs_new_ctx_target_s(void)
{
	return 2U;
}
static inline u32 gr_fecs_new_ctx_target_f(u32 v)
{
	return (v & 0x3U) << 28U;
}
static inline u32 gr_fecs_new_ctx_target_m(void)
{
	return 0x3U << 28U;
}
static inline u32 gr_fecs_new_ctx_target_v(u32 r)
{
	return (r >> 28U) & 0x3U;
}
static inline u32 gr_fecs_new_ctx_valid_s(void)
{
	return 1U;
}
static inline u32 gr_fecs_new_ctx_valid_f(u32 v)
{
	return (v & 0x1U) << 31U;
}
static inline u32 gr_fecs_new_ctx_valid_m(void)
{
	return 0x1U << 31U;
}
static inline u32 gr_fecs_new_ctx_valid_v(u32 r)
{
	return (r >> 31U) & 0x1U;
}
static inline u32 gr_fecs_arb_ctx_ptr_r(void)
{
	return 0x00409a0cU;
}
static inline u32 gr_fecs_arb_ctx_ptr_ptr_s(void)
{
	return 28U;
}
static inline u32 gr_fecs_arb_ctx_ptr_ptr_f(u32 v)
{
	return (v & 0xfffffffU) << 0U;
}
static inline u32 gr_fecs_arb_ctx_ptr_ptr_m(void)
{
	return 0xfffffffU << 0U;
}
static inline u32 gr_fecs_arb_ctx_ptr_ptr_v(u32 r)
{
	return (r >> 0U) & 0xfffffffU;
}
static inline u32 gr_fecs_arb_ctx_ptr_target_s(void)
{
	return 2U;
}
static inline u32 gr_fecs_arb_ctx_ptr_target_f(u32 v)
{
	return (v & 0x3U) << 28U;
}
static inline u32 gr_fecs_arb_ctx_ptr_target_m(void)
{
	return 0x3U << 28U;
}
static inline u32 gr_fecs_arb_ctx_ptr_target_v(u32 r)
{
	return (r >> 28U) & 0x3U;
}
static inline u32 gr_fecs_arb_ctx_cmd_r(void)
{
	return 0x00409a10U;
}
static inline u32 gr_fecs_arb_ctx_cmd_cmd_s(void)
{
	return 5U;
}
static inline u32 gr_fecs_arb_ctx_cmd_cmd_f(u32 v)
{
	return (v & 0x1fU) << 0U;
}
static inline u32 gr_fecs_arb_ctx_cmd_cmd_m(void)
{
	return 0x1fU << 0U;
}
static inline u32 gr_fecs_arb_ctx_cmd_cmd_v(u32 r)
{
	return (r >> 0U) & 0x1fU;
}
static inline u32 gr_fecs_ctxsw_status_fe_0_r(void)
{
	return 0x00409c00U;
}
static inline u32 gr_gpc0_gpccs_ctxsw_status_gpc_0_r(void)
{
	return 0x00502c04U;
}
static inline u32 gr_gpc0_gpccs_ctxsw_status_1_r(void)
{
	return 0x00502400U;
}
static inline u32 gr_fecs_ctxsw_idlestate_r(void)
{
	return 0x00409420U;
}
static inline u32 gr_fecs_feature_override_ecc_r(void)
{
	return 0x00409658U;
}
static inline u32 gr_fecs_feature_override_ecc_sm_lrf_v(u32 r)
{
	return (r >> 0U) & 0x1U;
}
static inline u32 gr_fecs_feature_override_ecc_sm_lrf_override_v(u32 r)
{
	return (r >> 3U) & 0x1U;
}
static inline u32 gr_fecs_feature_override_ecc_sm_l1_data_v(u32 r)
{
	return (r >> 4U) & 0x1U;
}
static inline u32 gr_fecs_feature_override_ecc_sm_l1_data_override_v(u32 r)
{
	return (r >> 7U) & 0x1U;
}
static inline u32 gr_fecs_feature_override_ecc_sm_l1_tag_v(u32 r)
{
	return (r >> 8U) & 0x1U;
}
static inline u32 gr_fecs_feature_override_ecc_sm_l1_tag_override_v(u32 r)
{
	return (r >> 11U) & 0x1U;
}
static inline u32 gr_fecs_feature_override_ecc_ltc_v(u32 r)
{
	return (r >> 12U) & 0x1U;
}
static inline u32 gr_fecs_feature_override_ecc_ltc_override_v(u32 r)
{
	return (r >> 15U) & 0x1U;
}
static inline u32 gr_fecs_feature_override_ecc_sm_cbu_v(u32 r)
{
	return (r >> 20U) & 0x1U;
}
static inline u32 gr_fecs_feature_override_ecc_sm_cbu_override_v(u32 r)
{
	return (r >> 23U) & 0x1U;
}
static inline u32 gr_fecs_feature_override_ecc_1_r(void)
{
	return 0x0040965cU;
}
static inline u32 gr_fecs_feature_override_ecc_1_sm_l0_icache_v(u32 r)
{
	return (r >> 0U) & 0x1U;
}
static inline u32 gr_fecs_feature_override_ecc_1_sm_l0_icache_override_v(u32 r)
{
	return (r >> 1U) & 0x1U;
}
static inline u32 gr_fecs_feature_override_ecc_1_sm_l1_icache_v(u32 r)
{
	return (r >> 2U) & 0x1U;
}
static inline u32 gr_fecs_feature_override_ecc_1_sm_l1_icache_override_v(u32 r)
{
	return (r >> 3U) & 0x1U;
}
static inline u32 gr_gpc0_gpccs_ctxsw_idlestate_r(void)
{
	return 0x00502420U;
}
static inline u32 gr_rstr2d_gpc_map_r(u32 i)
{
	return 0x0040780cU + i*4U;
}
static inline u32 gr_rstr2d_map_table_cfg_r(void)
{
	return 0x004078bcU;
}
static inline u32 gr_rstr2d_map_table_cfg_row_offset_f(u32 v)
{
	return (v & 0xffU) << 0U;
}
static inline u32 gr_rstr2d_map_table_cfg_num_entries_f(u32 v)
{
	return (v & 0xffU) << 8U;
}
static inline u32 gr_pd_hww_esr_r(void)
{
	return 0x00406018U;
}
static inline u32 gr_pd_hww_esr_reset_active_f(void)
{
	return 0x40000000U;
}
static inline u32 gr_pd_hww_esr_en_enable_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_pd_num_tpc_per_gpc_r(u32 i)
{
	return 0x00406028U + i*4U;
}
static inline u32 gr_pd_num_tpc_per_gpc__size_1_v(void)
{
	return 0x00000004U;
}
static inline u32 gr_pd_num_tpc_per_gpc_count0_f(u32 v)
{
	return (v & 0xfU) << 0U;
}
static inline u32 gr_pd_num_tpc_per_gpc_count1_f(u32 v)
{
	return (v & 0xfU) << 4U;
}
static inline u32 gr_pd_num_tpc_per_gpc_count2_f(u32 v)
{
	return (v & 0xfU) << 8U;
}
static inline u32 gr_pd_num_tpc_per_gpc_count3_f(u32 v)
{
	return (v & 0xfU) << 12U;
}
static inline u32 gr_pd_num_tpc_per_gpc_count4_f(u32 v)
{
	return (v & 0xfU) << 16U;
}
static inline u32 gr_pd_num_tpc_per_gpc_count5_f(u32 v)
{
	return (v & 0xfU) << 20U;
}
static inline u32 gr_pd_num_tpc_per_gpc_count6_f(u32 v)
{
	return (v & 0xfU) << 24U;
}
static inline u32 gr_pd_num_tpc_per_gpc_count7_f(u32 v)
{
	return (v & 0xfU) << 28U;
}
static inline u32 gr_pd_ab_dist_cfg0_r(void)
{
	return 0x004064c0U;
}
static inline u32 gr_pd_ab_dist_cfg0_timeslice_enable_en_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_pd_ab_dist_cfg0_timeslice_enable_dis_f(void)
{
	return 0x0U;
}
static inline u32 gr_pd_ab_dist_cfg1_r(void)
{
	return 0x004064c4U;
}
static inline u32 gr_pd_ab_dist_cfg1_max_batches_init_f(void)
{
	return 0xffffU;
}
static inline u32 gr_pd_ab_dist_cfg1_max_output_f(u32 v)
{
	return (v & 0xffffU) << 16U;
}
static inline u32 gr_pd_ab_dist_cfg1_max_output_granularity_v(void)
{
	return 0x00000080U;
}
static inline u32 gr_pd_ab_dist_cfg2_r(void)
{
	return 0x004064c8U;
}
static inline u32 gr_pd_ab_dist_cfg2_token_limit_f(u32 v)
{
	return (v & 0x1fffU) << 0U;
}
static inline u32 gr_pd_ab_dist_cfg2_token_limit_init_v(void)
{
	return 0x00000380U;
}
static inline u32 gr_pd_ab_dist_cfg2_state_limit_f(u32 v)
{
	return (v & 0x1fffU) << 16U;
}
static inline u32 gr_pd_ab_dist_cfg2_state_limit_scc_bundle_granularity_v(void)
{
	return 0x00000020U;
}
static inline u32 gr_pd_ab_dist_cfg2_state_limit_min_gpm_fifo_depths_v(void)
{
	return 0x00000302U;
}
static inline u32 gr_pd_dist_skip_table_r(u32 i)
{
	return 0x004064d0U + i*4U;
}
static inline u32 gr_pd_dist_skip_table__size_1_v(void)
{
	return 0x00000008U;
}
static inline u32 gr_pd_dist_skip_table_gpc_4n0_mask_f(u32 v)
{
	return (v & 0xffU) << 0U;
}
static inline u32 gr_pd_dist_skip_table_gpc_4n1_mask_f(u32 v)
{
	return (v & 0xffU) << 8U;
}
static inline u32 gr_pd_dist_skip_table_gpc_4n2_mask_f(u32 v)
{
	return (v & 0xffU) << 16U;
}
static inline u32 gr_pd_dist_skip_table_gpc_4n3_mask_f(u32 v)
{
	return (v & 0xffU) << 24U;
}
static inline u32 gr_ds_debug_r(void)
{
	return 0x00405800U;
}
static inline u32 gr_ds_debug_timeslice_mode_disable_f(void)
{
	return 0x0U;
}
static inline u32 gr_ds_debug_timeslice_mode_enable_f(void)
{
	return 0x8000000U;
}
static inline u32 gr_ds_zbc_color_r_r(void)
{
	return 0x00405804U;
}
static inline u32 gr_ds_zbc_color_r_val_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_ds_zbc_color_g_r(void)
{
	return 0x00405808U;
}
static inline u32 gr_ds_zbc_color_g_val_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_ds_zbc_color_b_r(void)
{
	return 0x0040580cU;
}
static inline u32 gr_ds_zbc_color_b_val_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_ds_zbc_color_a_r(void)
{
	return 0x00405810U;
}
static inline u32 gr_ds_zbc_color_a_val_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_ds_zbc_color_fmt_r(void)
{
	return 0x00405814U;
}
static inline u32 gr_ds_zbc_color_fmt_val_f(u32 v)
{
	return (v & 0x7fU) << 0U;
}
static inline u32 gr_ds_zbc_color_fmt_val_invalid_f(void)
{
	return 0x0U;
}
static inline u32 gr_ds_zbc_color_fmt_val_zero_v(void)
{
	return 0x00000001U;
}
static inline u32 gr_ds_zbc_color_fmt_val_unorm_one_v(void)
{
	return 0x00000002U;
}
static inline u32 gr_ds_zbc_color_fmt_val_rf32_gf32_bf32_af32_v(void)
{
	return 0x00000004U;
}
static inline u32 gr_ds_zbc_color_fmt_val_a8_b8_g8_r8_v(void)
{
	return 0x00000028U;
}
static inline u32 gr_ds_zbc_z_r(void)
{
	return 0x00405818U;
}
static inline u32 gr_ds_zbc_z_val_s(void)
{
	return 32U;
}
static inline u32 gr_ds_zbc_z_val_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_ds_zbc_z_val_m(void)
{
	return 0xffffffffU << 0U;
}
static inline u32 gr_ds_zbc_z_val_v(u32 r)
{
	return (r >> 0U) & 0xffffffffU;
}
static inline u32 gr_ds_zbc_z_val__init_v(void)
{
	return 0x00000000U;
}
static inline u32 gr_ds_zbc_z_val__init_f(void)
{
	return 0x0U;
}
static inline u32 gr_ds_zbc_z_fmt_r(void)
{
	return 0x0040581cU;
}
static inline u32 gr_ds_zbc_z_fmt_val_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_ds_zbc_z_fmt_val_invalid_f(void)
{
	return 0x0U;
}
static inline u32 gr_ds_zbc_z_fmt_val_fp32_v(void)
{
	return 0x00000001U;
}
static inline u32 gr_ds_zbc_tbl_index_r(void)
{
	return 0x00405820U;
}
static inline u32 gr_ds_zbc_tbl_index_val_f(u32 v)
{
	return (v & 0xfU) << 0U;
}
static inline u32 gr_ds_zbc_tbl_ld_r(void)
{
	return 0x00405824U;
}
static inline u32 gr_ds_zbc_tbl_ld_select_c_f(void)
{
	return 0x0U;
}
static inline u32 gr_ds_zbc_tbl_ld_select_z_f(void)
{
	return 0x1U;
}
static inline u32 gr_ds_zbc_tbl_ld_action_write_f(void)
{
	return 0x0U;
}
static inline u32 gr_ds_zbc_tbl_ld_trigger_active_f(void)
{
	return 0x4U;
}
static inline u32 gr_ds_tga_constraintlogic_beta_r(void)
{
	return 0x00405830U;
}
static inline u32 gr_ds_tga_constraintlogic_beta_cbsize_f(u32 v)
{
	return (v & 0x3fffffU) << 0U;
}
static inline u32 gr_ds_tga_constraintlogic_alpha_r(void)
{
	return 0x0040585cU;
}
static inline u32 gr_ds_tga_constraintlogic_alpha_cbsize_f(u32 v)
{
	return (v & 0xffffU) << 0U;
}
static inline u32 gr_ds_hww_esr_r(void)
{
	return 0x00405840U;
}
static inline u32 gr_ds_hww_esr_reset_s(void)
{
	return 1U;
}
static inline u32 gr_ds_hww_esr_reset_f(u32 v)
{
	return (v & 0x1U) << 30U;
}
static inline u32 gr_ds_hww_esr_reset_m(void)
{
	return 0x1U << 30U;
}
static inline u32 gr_ds_hww_esr_reset_v(u32 r)
{
	return (r >> 30U) & 0x1U;
}
static inline u32 gr_ds_hww_esr_reset_task_v(void)
{
	return 0x00000001U;
}
static inline u32 gr_ds_hww_esr_reset_task_f(void)
{
	return 0x40000000U;
}
static inline u32 gr_ds_hww_esr_en_enabled_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_ds_hww_esr_2_r(void)
{
	return 0x00405848U;
}
static inline u32 gr_ds_hww_esr_2_reset_s(void)
{
	return 1U;
}
static inline u32 gr_ds_hww_esr_2_reset_f(u32 v)
{
	return (v & 0x1U) << 30U;
}
static inline u32 gr_ds_hww_esr_2_reset_m(void)
{
	return 0x1U << 30U;
}
static inline u32 gr_ds_hww_esr_2_reset_v(u32 r)
{
	return (r >> 30U) & 0x1U;
}
static inline u32 gr_ds_hww_esr_2_reset_task_v(void)
{
	return 0x00000001U;
}
static inline u32 gr_ds_hww_esr_2_reset_task_f(void)
{
	return 0x40000000U;
}
static inline u32 gr_ds_hww_esr_2_en_enabled_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_ds_hww_report_mask_r(void)
{
	return 0x00405844U;
}
static inline u32 gr_ds_hww_report_mask_sph0_err_report_f(void)
{
	return 0x1U;
}
static inline u32 gr_ds_hww_report_mask_sph1_err_report_f(void)
{
	return 0x2U;
}
static inline u32 gr_ds_hww_report_mask_sph2_err_report_f(void)
{
	return 0x4U;
}
static inline u32 gr_ds_hww_report_mask_sph3_err_report_f(void)
{
	return 0x8U;
}
static inline u32 gr_ds_hww_report_mask_sph4_err_report_f(void)
{
	return 0x10U;
}
static inline u32 gr_ds_hww_report_mask_sph5_err_report_f(void)
{
	return 0x20U;
}
static inline u32 gr_ds_hww_report_mask_sph6_err_report_f(void)
{
	return 0x40U;
}
static inline u32 gr_ds_hww_report_mask_sph7_err_report_f(void)
{
	return 0x80U;
}
static inline u32 gr_ds_hww_report_mask_sph8_err_report_f(void)
{
	return 0x100U;
}
static inline u32 gr_ds_hww_report_mask_sph9_err_report_f(void)
{
	return 0x200U;
}
static inline u32 gr_ds_hww_report_mask_sph10_err_report_f(void)
{
	return 0x400U;
}
static inline u32 gr_ds_hww_report_mask_sph11_err_report_f(void)
{
	return 0x800U;
}
static inline u32 gr_ds_hww_report_mask_sph12_err_report_f(void)
{
	return 0x1000U;
}
static inline u32 gr_ds_hww_report_mask_sph13_err_report_f(void)
{
	return 0x2000U;
}
static inline u32 gr_ds_hww_report_mask_sph14_err_report_f(void)
{
	return 0x4000U;
}
static inline u32 gr_ds_hww_report_mask_sph15_err_report_f(void)
{
	return 0x8000U;
}
static inline u32 gr_ds_hww_report_mask_sph16_err_report_f(void)
{
	return 0x10000U;
}
static inline u32 gr_ds_hww_report_mask_sph17_err_report_f(void)
{
	return 0x20000U;
}
static inline u32 gr_ds_hww_report_mask_sph18_err_report_f(void)
{
	return 0x40000U;
}
static inline u32 gr_ds_hww_report_mask_sph19_err_report_f(void)
{
	return 0x80000U;
}
static inline u32 gr_ds_hww_report_mask_sph20_err_report_f(void)
{
	return 0x100000U;
}
static inline u32 gr_ds_hww_report_mask_sph21_err_report_f(void)
{
	return 0x200000U;
}
static inline u32 gr_ds_hww_report_mask_sph22_err_report_f(void)
{
	return 0x400000U;
}
static inline u32 gr_ds_hww_report_mask_sph23_err_report_f(void)
{
	return 0x800000U;
}
static inline u32 gr_ds_hww_report_mask_2_r(void)
{
	return 0x0040584cU;
}
static inline u32 gr_ds_hww_report_mask_2_sph24_err_report_f(void)
{
	return 0x1U;
}
static inline u32 gr_ds_num_tpc_per_gpc_r(u32 i)
{
	return 0x00405870U + i*4U;
}
static inline u32 gr_scc_debug_r(void)
{
	return 0x00408000U;
}
static inline u32 gr_scc_debug_pagepool_invalidates_m(void)
{
	return 0x1U << 9U;
}
static inline u32 gr_scc_debug_pagepool_invalidates_disable_f(void)
{
	return 0x200U;
}
static inline u32 gr_scc_debug_pagepool_invalidates_enable_f(void)
{
	return 0x0U;
}
static inline u32 gr_scc_bundle_cb_base_r(void)
{
	return 0x00408004U;
}
static inline u32 gr_scc_bundle_cb_base_addr_39_8_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_scc_bundle_cb_base_addr_39_8_align_bits_v(void)
{
	return 0x00000008U;
}
static inline u32 gr_scc_bundle_cb_size_r(void)
{
	return 0x00408008U;
}
static inline u32 gr_scc_bundle_cb_size_div_256b_f(u32 v)
{
	return (v & 0x7ffU) << 0U;
}
static inline u32 gr_scc_bundle_cb_size_div_256b__prod_v(void)
{
	return 0x00000030U;
}
static inline u32 gr_scc_bundle_cb_size_div_256b_byte_granularity_v(void)
{
	return 0x00000100U;
}
static inline u32 gr_scc_bundle_cb_size_valid_false_v(void)
{
	return 0x00000000U;
}
static inline u32 gr_scc_bundle_cb_size_valid_false_f(void)
{
	return 0x0U;
}
static inline u32 gr_scc_bundle_cb_size_valid_true_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_scc_pagepool_base_r(void)
{
	return 0x0040800cU;
}
static inline u32 gr_scc_pagepool_base_addr_39_8_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_scc_pagepool_base_addr_39_8_align_bits_v(void)
{
	return 0x00000008U;
}
static inline u32 gr_scc_pagepool_r(void)
{
	return 0x00408010U;
}
static inline u32 gr_scc_pagepool_total_pages_f(u32 v)
{
	return (v & 0x3ffU) << 0U;
}
static inline u32 gr_scc_pagepool_total_pages_hwmax_v(void)
{
	return 0x00000000U;
}
static inline u32 gr_scc_pagepool_total_pages_hwmax_value_v(void)
{
	return 0x00000200U;
}
static inline u32 gr_scc_pagepool_total_pages_byte_granularity_v(void)
{
	return 0x00000100U;
}
static inline u32 gr_scc_pagepool_max_valid_pages_s(void)
{
	return 10U;
}
static inline u32 gr_scc_pagepool_max_valid_pages_f(u32 v)
{
	return (v & 0x3ffU) << 10U;
}
static inline u32 gr_scc_pagepool_max_valid_pages_m(void)
{
	return 0x3ffU << 10U;
}
static inline u32 gr_scc_pagepool_max_valid_pages_v(u32 r)
{
	return (r >> 10U) & 0x3ffU;
}
static inline u32 gr_scc_pagepool_valid_true_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_scc_init_r(void)
{
	return 0x0040802cU;
}
static inline u32 gr_scc_init_ram_trigger_f(void)
{
	return 0x1U;
}
static inline u32 gr_scc_hww_esr_r(void)
{
	return 0x00408030U;
}
static inline u32 gr_scc_hww_esr_reset_active_f(void)
{
	return 0x40000000U;
}
static inline u32 gr_scc_hww_esr_en_enable_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_ssync_hww_esr_r(void)
{
	return 0x00405a14U;
}
static inline u32 gr_ssync_hww_esr_reset_active_f(void)
{
	return 0x40000000U;
}
static inline u32 gr_ssync_hww_esr_en_enable_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_sked_hww_esr_r(void)
{
	return 0x00407020U;
}
static inline u32 gr_sked_hww_esr_reset_active_f(void)
{
	return 0x40000000U;
}
static inline u32 gr_sked_hww_esr_en_r(void)
{
	return 0x00407024U;
}
static inline u32 gr_sked_hww_esr_en_skedcheck18_l1_config_too_small_m(void)
{
	return 0x1U << 25U;
}
static inline u32 gr_sked_hww_esr_en_skedcheck18_l1_config_too_small_disabled_f(void)
{
	return 0x0U;
}
static inline u32 gr_sked_hww_esr_en_skedcheck18_l1_config_too_small_enabled_f(void)
{
	return 0x2000000U;
}
static inline u32 gr_cwd_fs_r(void)
{
	return 0x00405b00U;
}
static inline u32 gr_cwd_fs_num_gpcs_f(u32 v)
{
	return (v & 0xffU) << 0U;
}
static inline u32 gr_cwd_fs_num_tpcs_f(u32 v)
{
	return (v & 0xffU) << 8U;
}
static inline u32 gr_cwd_gpc_tpc_id_r(u32 i)
{
	return 0x00405b60U + i*4U;
}
static inline u32 gr_cwd_gpc_tpc_id_tpc0_s(void)
{
	return 4U;
}
static inline u32 gr_cwd_gpc_tpc_id_tpc0_f(u32 v)
{
	return (v & 0xfU) << 0U;
}
static inline u32 gr_cwd_gpc_tpc_id_gpc0_s(void)
{
	return 4U;
}
static inline u32 gr_cwd_gpc_tpc_id_gpc0_f(u32 v)
{
	return (v & 0xfU) << 4U;
}
static inline u32 gr_cwd_gpc_tpc_id_tpc1_f(u32 v)
{
	return (v & 0xfU) << 8U;
}
static inline u32 gr_cwd_sm_id_r(u32 i)
{
	return 0x00405ba0U + i*4U;
}
static inline u32 gr_cwd_sm_id__size_1_v(void)
{
	return 0x00000010U;
}
static inline u32 gr_cwd_sm_id_tpc0_f(u32 v)
{
	return (v & 0xffU) << 0U;
}
static inline u32 gr_cwd_sm_id_tpc1_f(u32 v)
{
	return (v & 0xffU) << 8U;
}
static inline u32 gr_gpc0_fs_gpc_r(void)
{
	return 0x00502608U;
}
static inline u32 gr_gpc0_fs_gpc_num_available_tpcs_v(u32 r)
{
	return (r >> 0U) & 0x1fU;
}
static inline u32 gr_gpc0_fs_gpc_num_available_zculls_v(u32 r)
{
	return (r >> 16U) & 0x1fU;
}
static inline u32 gr_gpc0_cfg_r(void)
{
	return 0x00502620U;
}
static inline u32 gr_gpc0_cfg_imem_sz_v(u32 r)
{
	return (r >> 0U) & 0xffU;
}
static inline u32 gr_gpccs_rc_lanes_r(void)
{
	return 0x00502880U;
}
static inline u32 gr_gpccs_rc_lanes_num_chains_s(void)
{
	return 6U;
}
static inline u32 gr_gpccs_rc_lanes_num_chains_f(u32 v)
{
	return (v & 0x3fU) << 0U;
}
static inline u32 gr_gpccs_rc_lanes_num_chains_m(void)
{
	return 0x3fU << 0U;
}
static inline u32 gr_gpccs_rc_lanes_num_chains_v(u32 r)
{
	return (r >> 0U) & 0x3fU;
}
static inline u32 gr_gpccs_rc_lane_size_r(void)
{
	return 0x00502910U;
}
static inline u32 gr_gpccs_rc_lane_size_v_s(void)
{
	return 24U;
}
static inline u32 gr_gpccs_rc_lane_size_v_f(u32 v)
{
	return (v & 0xffffffU) << 0U;
}
static inline u32 gr_gpccs_rc_lane_size_v_m(void)
{
	return 0xffffffU << 0U;
}
static inline u32 gr_gpccs_rc_lane_size_v_v(u32 r)
{
	return (r >> 0U) & 0xffffffU;
}
static inline u32 gr_gpccs_rc_lane_size_v_0_v(void)
{
	return 0x00000000U;
}
static inline u32 gr_gpccs_rc_lane_size_v_0_f(void)
{
	return 0x0U;
}
static inline u32 gr_gpc0_zcull_fs_r(void)
{
	return 0x00500910U;
}
static inline u32 gr_gpc0_zcull_fs_num_sms_f(u32 v)
{
	return (v & 0x1ffU) << 0U;
}
static inline u32 gr_gpc0_zcull_fs_num_active_banks_f(u32 v)
{
	return (v & 0xfU) << 16U;
}
static inline u32 gr_gpc0_zcull_ram_addr_r(void)
{
	return 0x00500914U;
}
static inline u32 gr_gpc0_zcull_ram_addr_tiles_per_hypertile_row_per_gpc_f(u32 v)
{
	return (v & 0xfU) << 0U;
}
static inline u32 gr_gpc0_zcull_ram_addr_row_offset_f(u32 v)
{
	return (v & 0xfU) << 8U;
}
static inline u32 gr_gpc0_zcull_sm_num_rcp_r(void)
{
	return 0x00500918U;
}
static inline u32 gr_gpc0_zcull_sm_num_rcp_conservative_f(u32 v)
{
	return (v & 0xffffffU) << 0U;
}
static inline u32 gr_gpc0_zcull_sm_num_rcp_conservative__max_v(void)
{
	return 0x00800000U;
}
static inline u32 gr_gpc0_zcull_total_ram_size_r(void)
{
	return 0x00500920U;
}
static inline u32 gr_gpc0_zcull_total_ram_size_num_aliquots_f(u32 v)
{
	return (v & 0xffffU) << 0U;
}
static inline u32 gr_gpc0_zcull_zcsize_r(u32 i)
{
	return 0x00500a04U + i*32U;
}
static inline u32 gr_gpc0_zcull_zcsize_height_subregion__multiple_v(void)
{
	return 0x00000040U;
}
static inline u32 gr_gpc0_zcull_zcsize_width_subregion__multiple_v(void)
{
	return 0x00000010U;
}
static inline u32 gr_gpc0_gpm_pd_sm_id_r(u32 i)
{
	return 0x00500c10U + i*4U;
}
static inline u32 gr_gpc0_gpm_pd_sm_id_id_f(u32 v)
{
	return (v & 0xffU) << 0U;
}
static inline u32 gr_gpc0_gpm_pd_pes_tpc_id_mask_r(u32 i)
{
	return 0x00500c30U + i*4U;
}
static inline u32 gr_gpc0_gpm_pd_pes_tpc_id_mask_mask_v(u32 r)
{
	return (r >> 0U) & 0xffU;
}
static inline u32 gr_gpc0_tpc0_pe_cfg_smid_r(void)
{
	return 0x00504088U;
}
static inline u32 gr_gpc0_tpc0_pe_cfg_smid_value_f(u32 v)
{
	return (v & 0xffffU) << 0U;
}
static inline u32 gr_gpc0_tpc0_sm_cfg_r(void)
{
	return 0x00504608U;
}
static inline u32 gr_gpc0_tpc0_sm_cfg_tpc_id_f(u32 v)
{
	return (v & 0xffffU) << 0U;
}
static inline u32 gr_gpc0_tpc0_sm_cfg_tpc_id_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_gpc0_tpc0_sm_arch_r(void)
{
	return 0x00504330U;
}
static inline u32 gr_gpc0_tpc0_sm_arch_warp_count_v(u32 r)
{
	return (r >> 0U) & 0xffU;
}
static inline u32 gr_gpc0_tpc0_sm_arch_spa_version_v(u32 r)
{
	return (r >> 8U) & 0xfffU;
}
static inline u32 gr_gpc0_tpc0_sm_arch_sm_version_v(u32 r)
{
	return (r >> 20U) & 0xfffU;
}
static inline u32 gr_gpc0_ppc0_pes_vsc_strem_r(void)
{
	return 0x00503018U;
}
static inline u32 gr_gpc0_ppc0_pes_vsc_strem_master_pe_m(void)
{
	return 0x1U << 0U;
}
static inline u32 gr_gpc0_ppc0_pes_vsc_strem_master_pe_true_f(void)
{
	return 0x1U;
}
static inline u32 gr_gpc0_ppc0_cbm_beta_cb_size_r(void)
{
	return 0x005030c0U;
}
static inline u32 gr_gpc0_ppc0_cbm_beta_cb_size_v_f(u32 v)
{
	return (v & 0x3fffffU) << 0U;
}
static inline u32 gr_gpc0_ppc0_cbm_beta_cb_size_v_m(void)
{
	return 0x3fffffU << 0U;
}
static inline u32 gr_gpc0_ppc0_cbm_beta_cb_size_v_default_v(void)
{
	return 0x00000800U;
}
static inline u32 gr_gpc0_ppc0_cbm_beta_cb_size_v_gfxp_v(void)
{
	return 0x00001100U;
}
static inline u32 gr_gpc0_ppc0_cbm_beta_cb_size_v_granularity_v(void)
{
	return 0x00000020U;
}
static inline u32 gr_gpc0_ppc0_cbm_beta_cb_offset_r(void)
{
	return 0x005030f4U;
}
static inline u32 gr_gpc0_ppc0_cbm_alpha_cb_size_r(void)
{
	return 0x005030e4U;
}
static inline u32 gr_gpc0_ppc0_cbm_alpha_cb_size_v_f(u32 v)
{
	return (v & 0xffffU) << 0U;
}
static inline u32 gr_gpc0_ppc0_cbm_alpha_cb_size_v_m(void)
{
	return 0xffffU << 0U;
}
static inline u32 gr_gpc0_ppc0_cbm_alpha_cb_size_v_default_v(void)
{
	return 0x00000800U;
}
static inline u32 gr_gpc0_ppc0_cbm_alpha_cb_size_v_granularity_v(void)
{
	return 0x00000020U;
}
static inline u32 gr_gpc0_ppc0_cbm_alpha_cb_offset_r(void)
{
	return 0x005030f8U;
}
static inline u32 gr_gpc0_ppc0_cbm_beta_steady_state_cb_size_r(void)
{
	return 0x005030f0U;
}
static inline u32 gr_gpc0_ppc0_cbm_beta_steady_state_cb_size_v_f(u32 v)
{
	return (v & 0x3fffffU) << 0U;
}
static inline u32 gr_gpc0_ppc0_cbm_beta_steady_state_cb_size_v_default_v(void)
{
	return 0x00000800U;
}
static inline u32 gr_gpcs_tpcs_tex_rm_cb_0_r(void)
{
	return 0x00419e00U;
}
static inline u32 gr_gpcs_tpcs_tex_rm_cb_0_base_addr_43_12_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_gpcs_tpcs_tex_rm_cb_1_r(void)
{
	return 0x00419e04U;
}
static inline u32 gr_gpcs_tpcs_tex_rm_cb_1_size_div_128b_s(void)
{
	return 21U;
}
static inline u32 gr_gpcs_tpcs_tex_rm_cb_1_size_div_128b_f(u32 v)
{
	return (v & 0x1fffffU) << 0U;
}
static inline u32 gr_gpcs_tpcs_tex_rm_cb_1_size_div_128b_m(void)
{
	return 0x1fffffU << 0U;
}
static inline u32 gr_gpcs_tpcs_tex_rm_cb_1_size_div_128b_v(u32 r)
{
	return (r >> 0U) & 0x1fffffU;
}
static inline u32 gr_gpcs_tpcs_tex_rm_cb_1_size_div_128b_granularity_f(void)
{
	return 0x80U;
}
static inline u32 gr_gpcs_tpcs_tex_rm_cb_1_valid_s(void)
{
	return 1U;
}
static inline u32 gr_gpcs_tpcs_tex_rm_cb_1_valid_f(u32 v)
{
	return (v & 0x1U) << 31U;
}
static inline u32 gr_gpcs_tpcs_tex_rm_cb_1_valid_m(void)
{
	return 0x1U << 31U;
}
static inline u32 gr_gpcs_tpcs_tex_rm_cb_1_valid_v(u32 r)
{
	return (r >> 31U) & 0x1U;
}
static inline u32 gr_gpcs_tpcs_tex_rm_cb_1_valid_true_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_gpccs_falcon_addr_r(void)
{
	return 0x0041a0acU;
}
static inline u32 gr_gpccs_falcon_addr_lsb_s(void)
{
	return 6U;
}
static inline u32 gr_gpccs_falcon_addr_lsb_f(u32 v)
{
	return (v & 0x3fU) << 0U;
}
static inline u32 gr_gpccs_falcon_addr_lsb_m(void)
{
	return 0x3fU << 0U;
}
static inline u32 gr_gpccs_falcon_addr_lsb_v(u32 r)
{
	return (r >> 0U) & 0x3fU;
}
static inline u32 gr_gpccs_falcon_addr_lsb_init_v(void)
{
	return 0x00000000U;
}
static inline u32 gr_gpccs_falcon_addr_lsb_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_gpccs_falcon_addr_msb_s(void)
{
	return 6U;
}
static inline u32 gr_gpccs_falcon_addr_msb_f(u32 v)
{
	return (v & 0x3fU) << 6U;
}
static inline u32 gr_gpccs_falcon_addr_msb_m(void)
{
	return 0x3fU << 6U;
}
static inline u32 gr_gpccs_falcon_addr_msb_v(u32 r)
{
	return (r >> 6U) & 0x3fU;
}
static inline u32 gr_gpccs_falcon_addr_msb_init_v(void)
{
	return 0x00000000U;
}
static inline u32 gr_gpccs_falcon_addr_msb_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_gpccs_falcon_addr_ext_s(void)
{
	return 12U;
}
static inline u32 gr_gpccs_falcon_addr_ext_f(u32 v)
{
	return (v & 0xfffU) << 0U;
}
static inline u32 gr_gpccs_falcon_addr_ext_m(void)
{
	return 0xfffU << 0U;
}
static inline u32 gr_gpccs_falcon_addr_ext_v(u32 r)
{
	return (r >> 0U) & 0xfffU;
}
static inline u32 gr_gpccs_cpuctl_r(void)
{
	return 0x0041a100U;
}
static inline u32 gr_gpccs_cpuctl_startcpu_f(u32 v)
{
	return (v & 0x1U) << 1U;
}
static inline u32 gr_gpccs_dmactl_r(void)
{
	return 0x0041a10cU;
}
static inline u32 gr_gpccs_dmactl_require_ctx_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_gpccs_dmactl_dmem_scrubbing_m(void)
{
	return 0x1U << 1U;
}
static inline u32 gr_gpccs_dmactl_imem_scrubbing_m(void)
{
	return 0x1U << 2U;
}
static inline u32 gr_gpccs_imemc_r(u32 i)
{
	return 0x0041a180U + i*16U;
}
static inline u32 gr_gpccs_imemc_offs_f(u32 v)
{
	return (v & 0x3fU) << 2U;
}
static inline u32 gr_gpccs_imemc_blk_f(u32 v)
{
	return (v & 0xffU) << 8U;
}
static inline u32 gr_gpccs_imemc_aincw_f(u32 v)
{
	return (v & 0x1U) << 24U;
}
static inline u32 gr_gpccs_imemd_r(u32 i)
{
	return 0x0041a184U + i*16U;
}
static inline u32 gr_gpccs_imemt_r(u32 i)
{
	return 0x0041a188U + i*16U;
}
static inline u32 gr_gpccs_imemt__size_1_v(void)
{
	return 0x00000004U;
}
static inline u32 gr_gpccs_imemt_tag_f(u32 v)
{
	return (v & 0xffffU) << 0U;
}
static inline u32 gr_gpccs_dmemc_r(u32 i)
{
	return 0x0041a1c0U + i*8U;
}
static inline u32 gr_gpccs_dmemc_offs_f(u32 v)
{
	return (v & 0x3fU) << 2U;
}
static inline u32 gr_gpccs_dmemc_blk_f(u32 v)
{
	return (v & 0xffU) << 8U;
}
static inline u32 gr_gpccs_dmemc_aincw_f(u32 v)
{
	return (v & 0x1U) << 24U;
}
static inline u32 gr_gpccs_dmemd_r(u32 i)
{
	return 0x0041a1c4U + i*8U;
}
static inline u32 gr_gpccs_ctxsw_mailbox_r(u32 i)
{
	return 0x0041a800U + i*4U;
}
static inline u32 gr_gpccs_ctxsw_mailbox_value_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_base_r(void)
{
	return 0x00418e24U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_base_addr_39_8_s(void)
{
	return 32U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_base_addr_39_8_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_base_addr_39_8_m(void)
{
	return 0xffffffffU << 0U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_base_addr_39_8_v(u32 r)
{
	return (r >> 0U) & 0xffffffffU;
}
static inline u32 gr_gpcs_swdx_bundle_cb_base_addr_39_8_init_v(void)
{
	return 0x00000000U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_base_addr_39_8_init_f(void)
{
	return 0x0U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_size_r(void)
{
	return 0x00418e28U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_size_div_256b_s(void)
{
	return 11U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_size_div_256b_f(u32 v)
{
	return (v & 0x7ffU) << 0U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_size_div_256b_m(void)
{
	return 0x7ffU << 0U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_size_div_256b_v(u32 r)
{
	return (r >> 0U) & 0x7ffU;
}
static inline u32 gr_gpcs_swdx_bundle_cb_size_div_256b_init_v(void)
{
	return 0x00000030U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_size_div_256b_init_f(void)
{
	return 0x30U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_size_valid_s(void)
{
	return 1U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_size_valid_f(u32 v)
{
	return (v & 0x1U) << 31U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_size_valid_m(void)
{
	return 0x1U << 31U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_size_valid_v(u32 r)
{
	return (r >> 31U) & 0x1U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_size_valid_false_v(void)
{
	return 0x00000000U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_size_valid_false_f(void)
{
	return 0x0U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_size_valid_true_v(void)
{
	return 0x00000001U;
}
static inline u32 gr_gpcs_swdx_bundle_cb_size_valid_true_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_gpc0_swdx_rm_spill_buffer_size_r(void)
{
	return 0x005001dcU;
}
static inline u32 gr_gpc0_swdx_rm_spill_buffer_size_256b_f(u32 v)
{
	return (v & 0xffffU) << 0U;
}
static inline u32 gr_gpc0_swdx_rm_spill_buffer_size_256b_default_v(void)
{
	return 0x00000170U;
}
static inline u32 gr_gpc0_swdx_rm_spill_buffer_size_256b_byte_granularity_v(void)
{
	return 0x00000100U;
}
static inline u32 gr_gpc0_swdx_rm_spill_buffer_addr_r(void)
{
	return 0x005001d8U;
}
static inline u32 gr_gpc0_swdx_rm_spill_buffer_addr_39_8_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_gpc0_swdx_rm_spill_buffer_addr_39_8_align_bits_v(void)
{
	return 0x00000008U;
}
static inline u32 gr_gpcs_swdx_beta_cb_ctrl_r(void)
{
	return 0x004181e4U;
}
static inline u32 gr_gpcs_swdx_beta_cb_ctrl_cbes_reserve_f(u32 v)
{
	return (v & 0xfffU) << 0U;
}
static inline u32 gr_gpcs_swdx_beta_cb_ctrl_cbes_reserve_gfxp_v(void)
{
	return 0x00000100U;
}
static inline u32 gr_gpcs_ppcs_cbm_beta_cb_ctrl_r(void)
{
	return 0x0041befcU;
}
static inline u32 gr_gpcs_ppcs_cbm_beta_cb_ctrl_cbes_reserve_f(u32 v)
{
	return (v & 0xfffU) << 0U;
}
static inline u32 gr_gpcs_ppcs_cbm_debug_r(void)
{
	return 0x0041bec4U;
}
static inline u32 gr_gpcs_ppcs_cbm_debug_invalidate_alpha_m(void)
{
	return 0x1U << 0U;
}
static inline u32 gr_gpcs_ppcs_cbm_debug_invalidate_alpha_disable_f(void)
{
	return 0x0U;
}
static inline u32 gr_gpcs_ppcs_cbm_debug_invalidate_alpha_enable_f(void)
{
	return 0x1U;
}
static inline u32 gr_gpcs_ppcs_cbm_debug_invalidate_beta_m(void)
{
	return 0x1U << 1U;
}
static inline u32 gr_gpcs_ppcs_cbm_debug_invalidate_beta_disable_f(void)
{
	return 0x0U;
}
static inline u32 gr_gpcs_ppcs_cbm_debug_invalidate_beta_enable_f(void)
{
	return 0x2U;
}
static inline u32 gr_gpcs_swdx_tc_beta_cb_size_r(u32 i)
{
	return 0x00418ea0U + i*4U;
}
static inline u32 gr_gpcs_swdx_tc_beta_cb_size_v_f(u32 v)
{
	return (v & 0x3fffffU) << 0U;
}
static inline u32 gr_gpcs_swdx_tc_beta_cb_size_v_m(void)
{
	return 0x3fffffU << 0U;
}
static inline u32 gr_gpcs_swdx_dss_zbc_color_r_r(u32 i)
{
	return 0x00418010U + i*4U;
}
static inline u32 gr_gpcs_swdx_dss_zbc_color_r_val_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_gpcs_swdx_dss_zbc_color_g_r(u32 i)
{
	return 0x0041804cU + i*4U;
}
static inline u32 gr_gpcs_swdx_dss_zbc_color_g_val_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_gpcs_swdx_dss_zbc_color_b_r(u32 i)
{
	return 0x00418088U + i*4U;
}
static inline u32 gr_gpcs_swdx_dss_zbc_color_b_val_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_gpcs_swdx_dss_zbc_color_a_r(u32 i)
{
	return 0x004180c4U + i*4U;
}
static inline u32 gr_gpcs_swdx_dss_zbc_color_a_val_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_gpcs_swdx_dss_zbc_c_01_to_04_format_r(void)
{
	return 0x00418100U;
}
static inline u32 gr_gpcs_swdx_dss_zbc_z_r(u32 i)
{
	return 0x00418110U + i*4U;
}
static inline u32 gr_gpcs_swdx_dss_zbc_z_val_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_gpcs_swdx_dss_zbc_z_01_to_04_format_r(void)
{
	return 0x0041814cU;
}
static inline u32 gr_gpcs_swdx_dss_zbc_s_r(u32 i)
{
	return 0x0041815cU + i*4U;
}
static inline u32 gr_gpcs_swdx_dss_zbc_s_val_f(u32 v)
{
	return (v & 0xffU) << 0U;
}
static inline u32 gr_gpcs_swdx_dss_zbc_s_01_to_04_format_r(void)
{
	return 0x00418198U;
}
static inline u32 gr_gpcs_swdx_spill_unit_r(void)
{
	return 0x00418e9cU;
}
static inline u32 gr_gpcs_swdx_spill_unit_spill_buffer_cache_mgmt_mode_m(void)
{
	return 0x1U << 16U;
}
static inline u32 gr_gpcs_swdx_spill_unit_spill_buffer_cache_mgmt_mode_disabled_f(void)
{
	return 0x0U;
}
static inline u32 gr_gpcs_swdx_spill_unit_spill_buffer_cache_mgmt_mode_enabled_f(void)
{
	return 0x10000U;
}
static inline u32 gr_gpcs_setup_attrib_cb_base_r(void)
{
	return 0x00418810U;
}
static inline u32 gr_gpcs_setup_attrib_cb_base_addr_39_12_f(u32 v)
{
	return (v & 0xfffffffU) << 0U;
}
static inline u32 gr_gpcs_setup_attrib_cb_base_addr_39_12_align_bits_v(void)
{
	return 0x0000000cU;
}
static inline u32 gr_gpcs_setup_attrib_cb_base_valid_true_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_crstr_gpc_map_r(u32 i)
{
	return 0x00418b08U + i*4U;
}
static inline u32 gr_crstr_gpc_map_tile0_f(u32 v)
{
	return (v & 0x1fU) << 0U;
}
static inline u32 gr_crstr_gpc_map_tile1_f(u32 v)
{
	return (v & 0x1fU) << 5U;
}
static inline u32 gr_crstr_gpc_map_tile2_f(u32 v)
{
	return (v & 0x1fU) << 10U;
}
static inline u32 gr_crstr_gpc_map_tile3_f(u32 v)
{
	return (v & 0x1fU) << 15U;
}
static inline u32 gr_crstr_gpc_map_tile4_f(u32 v)
{
	return (v & 0x1fU) << 20U;
}
static inline u32 gr_crstr_gpc_map_tile5_f(u32 v)
{
	return (v & 0x1fU) << 25U;
}
static inline u32 gr_crstr_map_table_cfg_r(void)
{
	return 0x00418bb8U;
}
static inline u32 gr_crstr_map_table_cfg_row_offset_f(u32 v)
{
	return (v & 0xffU) << 0U;
}
static inline u32 gr_crstr_map_table_cfg_num_entries_f(u32 v)
{
	return (v & 0xffU) << 8U;
}
static inline u32 gr_gpcs_zcull_sm_in_gpc_number_map_r(u32 i)
{
	return 0x00418980U + i*4U;
}
static inline u32 gr_gpcs_zcull_sm_in_gpc_number_map_tile_0_f(u32 v)
{
	return (v & 0x7U) << 0U;
}
static inline u32 gr_gpcs_zcull_sm_in_gpc_number_map_tile_1_f(u32 v)
{
	return (v & 0x7U) << 4U;
}
static inline u32 gr_gpcs_zcull_sm_in_gpc_number_map_tile_2_f(u32 v)
{
	return (v & 0x7U) << 8U;
}
static inline u32 gr_gpcs_zcull_sm_in_gpc_number_map_tile_3_f(u32 v)
{
	return (v & 0x7U) << 12U;
}
static inline u32 gr_gpcs_zcull_sm_in_gpc_number_map_tile_4_f(u32 v)
{
	return (v & 0x7U) << 16U;
}
static inline u32 gr_gpcs_zcull_sm_in_gpc_number_map_tile_5_f(u32 v)
{
	return (v & 0x7U) << 20U;
}
static inline u32 gr_gpcs_zcull_sm_in_gpc_number_map_tile_6_f(u32 v)
{
	return (v & 0x7U) << 24U;
}
static inline u32 gr_gpcs_zcull_sm_in_gpc_number_map_tile_7_f(u32 v)
{
	return (v & 0x7U) << 28U;
}
static inline u32 gr_gpcs_gpm_pd_cfg_r(void)
{
	return 0x00418c6cU;
}
static inline u32 gr_gpcs_gcc_pagepool_base_r(void)
{
	return 0x00419004U;
}
static inline u32 gr_gpcs_gcc_pagepool_base_addr_39_8_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_gpcs_gcc_pagepool_r(void)
{
	return 0x00419008U;
}
static inline u32 gr_gpcs_gcc_pagepool_total_pages_f(u32 v)
{
	return (v & 0x3ffU) << 0U;
}
static inline u32 gr_gpcs_tpcs_pe_vaf_r(void)
{
	return 0x0041980cU;
}
static inline u32 gr_gpcs_tpcs_pe_vaf_fast_mode_switch_true_f(void)
{
	return 0x10U;
}
static inline u32 gr_gpcs_tpcs_pe_pin_cb_global_base_addr_r(void)
{
	return 0x00419848U;
}
static inline u32 gr_gpcs_tpcs_pe_pin_cb_global_base_addr_v_f(u32 v)
{
	return (v & 0xfffffffU) << 0U;
}
static inline u32 gr_gpcs_tpcs_pe_pin_cb_global_base_addr_valid_f(u32 v)
{
	return (v & 0x1U) << 28U;
}
static inline u32 gr_gpcs_tpcs_pe_pin_cb_global_base_addr_valid_true_f(void)
{
	return 0x10000000U;
}
static inline u32 gr_gpcs_tpcs_mpc_vtg_debug_r(void)
{
	return 0x00419c00U;
}
static inline u32 gr_gpcs_tpcs_mpc_vtg_debug_timeslice_mode_disabled_f(void)
{
	return 0x0U;
}
static inline u32 gr_gpcs_tpcs_mpc_vtg_debug_timeslice_mode_enabled_f(void)
{
	return 0x8U;
}
static inline u32 gr_gpcs_tpcs_mpc_vtg_cb_global_base_addr_r(void)
{
	return 0x00419c2cU;
}
static inline u32 gr_gpcs_tpcs_mpc_vtg_cb_global_base_addr_v_f(u32 v)
{
	return (v & 0xfffffffU) << 0U;
}
static inline u32 gr_gpcs_tpcs_mpc_vtg_cb_global_base_addr_valid_f(u32 v)
{
	return (v & 0x1U) << 28U;
}
static inline u32 gr_gpcs_tpcs_mpc_vtg_cb_global_base_addr_valid_true_f(void)
{
	return 0x10000000U;
}
static inline u32 gr_gpcs_tpcs_sms_hww_warp_esr_report_mask_r(void)
{
	return 0x00419ea8U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_r(void)
{
	return 0x00504728U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_stack_error_report_f(void)
{
	return 0x2U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_api_stack_error_report_f(void)
{
	return 0x4U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_pc_wrap_report_f(void)
{
	return 0x10U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_misaligned_pc_report_f(void)
{
	return 0x20U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_pc_overflow_report_f(void)
{
	return 0x40U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_misaligned_reg_report_f(void)
{
	return 0x100U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_illegal_instr_encoding_report_f(void)
{
	return 0x200U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_illegal_instr_param_report_f(void)
{
	return 0x800U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_oor_reg_report_f(void)
{
	return 0x2000U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_oor_addr_report_f(void)
{
	return 0x4000U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_misaligned_addr_report_f(void)
{
	return 0x8000U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_invalid_addr_space_report_f(void)
{
	return 0x10000U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_invalid_const_addr_ldc_report_f(void)
{
	return 0x40000U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_mmu_fault_report_f(void)
{
	return 0x800000U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_stack_overflow_report_f(void)
{
	return 0x400000U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_mmu_nack_report_f(void)
{
	return 0x4000000U;
}
static inline u32 gr_gpcs_tpcs_tpccs_tpc_exception_en_r(void)
{
	return 0x00419d0cU;
}
static inline u32 gr_gpcs_tpcs_tpccs_tpc_exception_en_sm_enabled_f(void)
{
	return 0x2U;
}
static inline u32 gr_gpcs_tpcs_tpccs_tpc_exception_en_tex_enabled_f(void)
{
	return 0x1U;
}
static inline u32 gr_gpcs_tpcs_tpccs_tpc_exception_en_mpc_enabled_f(void)
{
	return 0x10U;
}
static inline u32 gr_gpc0_tpc0_tpccs_tpc_exception_en_r(void)
{
	return 0x0050450cU;
}
static inline u32 gr_gpc0_tpc0_tpccs_tpc_exception_en_sm_v(u32 r)
{
	return (r >> 1U) & 0x1U;
}
static inline u32 gr_gpc0_tpc0_tpccs_tpc_exception_en_sm_enabled_f(void)
{
	return 0x2U;
}
static inline u32 gr_gpc0_tpc0_tpccs_tpc_exception_en_mpc_enabled_f(void)
{
	return 0x10U;
}
static inline u32 gr_gpcs_gpccs_gpc_exception_en_r(void)
{
	return 0x0041ac94U;
}
static inline u32 gr_gpcs_gpccs_gpc_exception_en_gcc_f(u32 v)
{
	return (v & 0x1U) << 2U;
}
static inline u32 gr_gpcs_gpccs_gpc_exception_en_tpc_f(u32 v)
{
	return (v & 0xffU) << 16U;
}
static inline u32 gr_gpcs_gpccs_gpc_exception_en_gpccs_f(u32 v)
{
	return (v & 0x1U) << 14U;
}
static inline u32 gr_gpcs_gpccs_gpc_exception_en_gpcmmu_f(u32 v)
{
	return (v & 0x1U) << 15U;
}
static inline u32 gr_gpc0_gpccs_gpc_exception_r(void)
{
	return 0x00502c90U;
}
static inline u32 gr_gpc0_gpccs_gpc_exception_gcc_v(u32 r)
{
	return (r >> 2U) & 0x1U;
}
static inline u32 gr_gpc0_gpccs_gpc_exception_tpc_v(u32 r)
{
	return (r >> 16U) & 0xffU;
}
static inline u32 gr_gpc0_gpccs_gpc_exception_tpc_0_pending_v(void)
{
	return 0x00000001U;
}
static inline u32 gr_gpc0_gpccs_gpc_exception_gpccs_f(u32 v)
{
	return (v & 0x1U) << 14U;
}
static inline u32 gr_gpc0_gpccs_gpc_exception_gpccs_m(void)
{
	return 0x1U << 14U;
}
static inline u32 gr_gpc0_gpccs_gpc_exception_gpccs_pending_f(void)
{
	return 0x4000U;
}
static inline u32 gr_gpc0_gpccs_gpc_exception_gpcmmu_f(u32 v)
{
	return (v & 0x1U) << 15U;
}
static inline u32 gr_gpc0_gpccs_gpc_exception_gpcmmu_m(void)
{
	return 0x1U << 15U;
}
static inline u32 gr_gpc0_gpccs_gpc_exception_gpcmmu_pending_f(void)
{
	return 0x8000U;
}
static inline u32 gr_pri_gpc0_gcc_l15_ecc_status_r(void)
{
	return 0x00501048U;
}
static inline u32 gr_pri_gpc0_gcc_l15_ecc_status_corrected_err_bank0_m(void)
{
	return 0x1U << 0U;
}
static inline u32 gr_pri_gpc0_gcc_l15_ecc_status_corrected_err_bank1_m(void)
{
	return 0x1U << 1U;
}
static inline u32 gr_pri_gpc0_gcc_l15_ecc_status_uncorrected_err_bank0_m(void)
{
	return 0x1U << 4U;
}
static inline u32 gr_pri_gpc0_gcc_l15_ecc_status_uncorrected_err_bank1_m(void)
{
	return 0x1U << 5U;
}
static inline u32 gr_pri_gpc0_gcc_l15_ecc_status_corrected_err_total_counter_overflow_v(u32 r)
{
	return (r >> 8U) & 0x1U;
}
static inline u32 gr_pri_gpc0_gcc_l15_ecc_status_uncorrected_err_total_counter_overflow_v(u32 r)
{
	return (r >> 10U) & 0x1U;
}
static inline u32 gr_pri_gpc0_gcc_l15_ecc_status_reset_task_f(void)
{
	return 0x40000000U;
}
static inline u32 gr_pri_gpc0_gcc_l15_ecc_corrected_err_count_r(void)
{
	return 0x0050104cU;
}
static inline u32 gr_pri_gpc0_gcc_l15_ecc_corrected_err_count_total_s(void)
{
	return 16U;
}
static inline u32 gr_pri_gpc0_gcc_l15_ecc_corrected_err_count_total_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_pri_gpc0_gcc_l15_ecc_uncorrected_err_count_r(void)
{
	return 0x00501054U;
}
static inline u32 gr_pri_gpc0_gcc_l15_ecc_uncorrected_err_count_total_s(void)
{
	return 16U;
}
static inline u32 gr_pri_gpc0_gcc_l15_ecc_uncorrected_err_count_total_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_gpc0_tpc0_tpccs_tpc_exception_r(void)
{
	return 0x00504508U;
}
static inline u32 gr_gpc0_tpc0_tpccs_tpc_exception_tex_v(u32 r)
{
	return (r >> 0U) & 0x1U;
}
static inline u32 gr_gpc0_tpc0_tpccs_tpc_exception_tex_pending_v(void)
{
	return 0x00000001U;
}
static inline u32 gr_gpc0_tpc0_tpccs_tpc_exception_sm_v(u32 r)
{
	return (r >> 1U) & 0x1U;
}
static inline u32 gr_gpc0_tpc0_tpccs_tpc_exception_sm_pending_v(void)
{
	return 0x00000001U;
}
static inline u32 gr_gpc0_tpc0_tpccs_tpc_exception_mpc_m(void)
{
	return 0x1U << 4U;
}
static inline u32 gr_gpc0_tpc0_tpccs_tpc_exception_mpc_pending_f(void)
{
	return 0x10U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_control0_r(void)
{
	return 0x00504704U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_control0_debugger_mode_m(void)
{
	return 0x1U << 0U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_control0_debugger_mode_v(u32 r)
{
	return (r >> 0U) & 0x1U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_control0_debugger_mode_on_v(void)
{
	return 0x00000001U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_control0_debugger_mode_on_f(void)
{
	return 0x1U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_control0_debugger_mode_off_v(void)
{
	return 0x00000000U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_control0_debugger_mode_off_f(void)
{
	return 0x0U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_control0_stop_trigger_m(void)
{
	return 0x1U << 31U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_control0_stop_trigger_enable_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_control0_stop_trigger_disable_f(void)
{
	return 0x0U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_control0_single_step_mode_m(void)
{
	return 0x1U << 3U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_control0_single_step_mode_enable_f(void)
{
	return 0x8U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_control0_single_step_mode_disable_f(void)
{
	return 0x0U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_control0_run_trigger_task_f(void)
{
	return 0x40000000U;
}
static inline u32 gr_gpc0_tpc0_sm0_warp_valid_mask_0_r(void)
{
	return 0x00504708U;
}
static inline u32 gr_gpc0_tpc0_sm0_warp_valid_mask_1_r(void)
{
	return 0x0050470cU;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_bpt_pause_mask_0_r(void)
{
	return 0x00504710U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_bpt_pause_mask_1_r(void)
{
	return 0x00504714U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_bpt_trap_mask_0_r(void)
{
	return 0x00504718U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_bpt_trap_mask_1_r(void)
{
	return 0x0050471cU;
}
static inline u32 gr_gpcs_tpcs_sms_dbgr_bpt_pause_mask_0_r(void)
{
	return 0x00419e90U;
}
static inline u32 gr_gpcs_tpcs_sms_dbgr_bpt_pause_mask_1_r(void)
{
	return 0x00419e94U;
}
static inline u32 gr_gpcs_tpcs_sms_dbgr_status0_r(void)
{
	return 0x00419e80U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_status0_r(void)
{
	return 0x00504700U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_status0_sm_in_trap_mode_v(u32 r)
{
	return (r >> 0U) & 0x1U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_status0_locked_down_v(u32 r)
{
	return (r >> 4U) & 0x1U;
}
static inline u32 gr_gpc0_tpc0_sm0_dbgr_status0_locked_down_true_v(void)
{
	return 0x00000001U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_r(void)
{
	return 0x00504730U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_none_v(void)
{
	return 0x00000000U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_none_f(void)
{
	return 0x0U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_stack_error_f(void)
{
	return 0x1U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_api_stack_error_f(void)
{
	return 0x2U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_pc_wrap_f(void)
{
	return 0x4U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_misaligned_pc_f(void)
{
	return 0x5U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_pc_overflow_f(void)
{
	return 0x6U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_misaligned_reg_f(void)
{
	return 0x8U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_illegal_instr_encoding_f(void)
{
	return 0x9U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_illegal_instr_param_f(void)
{
	return 0xbU;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_oor_reg_f(void)
{
	return 0xdU;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_oor_addr_f(void)
{
	return 0xeU;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_misaligned_addr_f(void)
{
	return 0xfU;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_invalid_addr_space_f(void)
{
	return 0x10U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_invalid_const_addr_ldc_f(void)
{
	return 0x12U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_stack_overflow_f(void)
{
	return 0x16U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_mmu_fault_f(void)
{
	return 0x17U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_tex_format_f(void)
{
	return 0x18U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_tex_layout_f(void)
{
	return 0x19U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_error_mmu_nack_f(void)
{
	return 0x20U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_wrap_id_m(void)
{
	return 0xffU << 16U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_addr_error_type_m(void)
{
	return 0xfU << 24U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_addr_error_type_none_f(void)
{
	return 0x0U;
}
static inline u32 gr_gpc0_tpc0_sm_tpc_esr_sm_sel_r(void)
{
	return 0x0050460cU;
}
static inline u32 gr_gpc0_tpc0_sm_tpc_esr_sm_sel_sm0_error_v(u32 r)
{
	return (r >> 0U) & 0x1U;
}
static inline u32 gr_gpc0_tpc0_sm_tpc_esr_sm_sel_sm1_error_v(u32 r)
{
	return (r >> 1U) & 0x1U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_pc_r(void)
{
	return 0x00504738U;
}
static inline u32 gr_gpc0_tpc0_sm0_hww_warp_esr_pc_hi_r(void)
{
	return 0x0050473cU;
}
static inline u32 gr_gpc0_tpc0_sm_halfctl_ctrl_r(void)
{
	return 0x005043a0U;
}
static inline u32 gr_gpcs_tpcs_sm_halfctl_ctrl_r(void)
{
	return 0x00419ba0U;
}
static inline u32 gr_gpcs_tpcs_sm_halfctl_ctrl_sctl_read_quad_ctl_m(void)
{
	return 0x1U << 4U;
}
static inline u32 gr_gpcs_tpcs_sm_halfctl_ctrl_sctl_read_quad_ctl_f(u32 v)
{
	return (v & 0x1U) << 4U;
}
static inline u32 gr_gpc0_tpc0_sm_debug_sfe_control_r(void)
{
	return 0x005043b0U;
}
static inline u32 gr_gpcs_tpcs_sm_debug_sfe_control_r(void)
{
	return 0x00419bb0U;
}
static inline u32 gr_gpcs_tpcs_sm_debug_sfe_control_read_half_ctl_m(void)
{
	return 0x1U << 0U;
}
static inline u32 gr_gpcs_tpcs_sm_debug_sfe_control_read_half_ctl_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_gpcs_tpcs_pes_vsc_vpc_r(void)
{
	return 0x0041be08U;
}
static inline u32 gr_gpcs_tpcs_pes_vsc_vpc_fast_mode_switch_true_f(void)
{
	return 0x4U;
}
static inline u32 gr_ppcs_wwdx_map_gpc_map_r(u32 i)
{
	return 0x0041bf00U + i*4U;
}
static inline u32 gr_ppcs_wwdx_map_table_cfg_r(void)
{
	return 0x0041bfd0U;
}
static inline u32 gr_ppcs_wwdx_map_table_cfg_row_offset_f(u32 v)
{
	return (v & 0xffU) << 0U;
}
static inline u32 gr_ppcs_wwdx_map_table_cfg_num_entries_f(u32 v)
{
	return (v & 0xffU) << 8U;
}
static inline u32 gr_ppcs_wwdx_map_table_cfg_normalized_num_entries_f(u32 v)
{
	return (v & 0x1fU) << 16U;
}
static inline u32 gr_ppcs_wwdx_map_table_cfg_normalized_shift_value_f(u32 v)
{
	return (v & 0x7U) << 21U;
}
static inline u32 gr_gpcs_ppcs_wwdx_sm_num_rcp_r(void)
{
	return 0x0041bfd4U;
}
static inline u32 gr_gpcs_ppcs_wwdx_sm_num_rcp_conservative_f(u32 v)
{
	return (v & 0xffffffU) << 0U;
}
static inline u32 gr_ppcs_wwdx_map_table_cfg_coeff_r(u32 i)
{
	return 0x0041bfb0U + i*4U;
}
static inline u32 gr_ppcs_wwdx_map_table_cfg_coeff__size_1_v(void)
{
	return 0x00000005U;
}
static inline u32 gr_ppcs_wwdx_map_table_cfg_coeff_0_mod_value_f(u32 v)
{
	return (v & 0xffU) << 0U;
}
static inline u32 gr_ppcs_wwdx_map_table_cfg_coeff_1_mod_value_f(u32 v)
{
	return (v & 0xffU) << 8U;
}
static inline u32 gr_ppcs_wwdx_map_table_cfg_coeff_2_mod_value_f(u32 v)
{
	return (v & 0xffU) << 16U;
}
static inline u32 gr_ppcs_wwdx_map_table_cfg_coeff_3_mod_value_f(u32 v)
{
	return (v & 0xffU) << 24U;
}
static inline u32 gr_bes_zrop_settings_r(void)
{
	return 0x00408850U;
}
static inline u32 gr_bes_zrop_settings_num_active_ltcs_f(u32 v)
{
	return (v & 0xfU) << 0U;
}
static inline u32 gr_be0_crop_debug3_r(void)
{
	return 0x00410108U;
}
static inline u32 gr_bes_crop_debug3_r(void)
{
	return 0x00408908U;
}
static inline u32 gr_bes_crop_debug3_comp_vdc_4to2_disable_m(void)
{
	return 0x1U << 31U;
}
static inline u32 gr_bes_crop_debug3_blendopt_read_suppress_m(void)
{
	return 0x1U << 1U;
}
static inline u32 gr_bes_crop_debug3_blendopt_read_suppress_disabled_f(void)
{
	return 0x0U;
}
static inline u32 gr_bes_crop_debug3_blendopt_read_suppress_enabled_f(void)
{
	return 0x2U;
}
static inline u32 gr_bes_crop_debug3_blendopt_fill_override_m(void)
{
	return 0x1U << 2U;
}
static inline u32 gr_bes_crop_debug3_blendopt_fill_override_disabled_f(void)
{
	return 0x0U;
}
static inline u32 gr_bes_crop_debug3_blendopt_fill_override_enabled_f(void)
{
	return 0x4U;
}
static inline u32 gr_bes_crop_debug4_r(void)
{
	return 0x0040894cU;
}
static inline u32 gr_bes_crop_debug4_clamp_fp_blend_m(void)
{
	return 0x1U << 18U;
}
static inline u32 gr_bes_crop_debug4_clamp_fp_blend_to_inf_f(void)
{
	return 0x0U;
}
static inline u32 gr_bes_crop_debug4_clamp_fp_blend_to_maxval_f(void)
{
	return 0x40000U;
}
static inline u32 gr_bes_crop_settings_r(void)
{
	return 0x00408958U;
}
static inline u32 gr_bes_crop_settings_num_active_ltcs_f(u32 v)
{
	return (v & 0xfU) << 0U;
}
static inline u32 gr_zcull_bytes_per_aliquot_per_gpu_v(void)
{
	return 0x00000020U;
}
static inline u32 gr_zcull_save_restore_header_bytes_per_gpc_v(void)
{
	return 0x00000020U;
}
static inline u32 gr_zcull_save_restore_subregion_header_bytes_per_gpc_v(void)
{
	return 0x000000c0U;
}
static inline u32 gr_zcull_subregion_qty_v(void)
{
	return 0x00000010U;
}
static inline u32 gr_gpcs_tpcs_tex_in_dbg_r(void)
{
	return 0x00419a00U;
}
static inline u32 gr_gpcs_tpcs_tex_in_dbg_tsl1_rvch_invalidate_f(u32 v)
{
	return (v & 0x1U) << 19U;
}
static inline u32 gr_gpcs_tpcs_tex_in_dbg_tsl1_rvch_invalidate_m(void)
{
	return 0x1U << 19U;
}
static inline u32 gr_gpcs_tpcs_sm_l1tag_ctrl_r(void)
{
	return 0x00419bf0U;
}
static inline u32 gr_gpcs_tpcs_sm_l1tag_ctrl_cache_surface_ld_f(u32 v)
{
	return (v & 0x1U) << 5U;
}
static inline u32 gr_gpcs_tpcs_sm_l1tag_ctrl_cache_surface_ld_m(void)
{
	return 0x1U << 5U;
}
static inline u32 gr_gpcs_tpcs_sm_l1tag_ctrl_cache_surface_st_f(u32 v)
{
	return (v & 0x1U) << 10U;
}
static inline u32 gr_gpcs_tpcs_sm_l1tag_ctrl_cache_surface_st_m(void)
{
	return 0x1U << 10U;
}
static inline u32 gr_gpcs_tpcs_sm_l1tag_ctrl_always_cut_collector_m(void)
{
	return 0x1U << 28U;
}
static inline u32 gr_gpcs_tpcs_sm_l1tag_ctrl_always_cut_collector_disable_f(void)
{
	return 0x0U;
}
static inline u32 gr_gpcs_tpcs_sm_l1tag_ctrl_always_cut_collector_enable_f(void)
{
	return 0x10000000U;
}
static inline u32 gr_egpc0_etpc0_sm_dsm_perf_counter_control_sel0_r(void)
{
	return 0x00584200U;
}
static inline u32 gr_egpc0_etpc0_sm_dsm_perf_counter_control_sel1_r(void)
{
	return 0x00584204U;
}
static inline u32 gr_egpc0_etpc0_sm_dsm_perf_counter_control0_r(void)
{
	return 0x00584208U;
}
static inline u32 gr_egpc0_etpc0_sm_dsm_perf_counter_control1_r(void)
{
	return 0x00584210U;
}
static inline u32 gr_egpc0_etpc0_sm_dsm_perf_counter_control2_r(void)
{
	return 0x00584214U;
}
static inline u32 gr_egpc0_etpc0_sm_dsm_perf_counter_control3_r(void)
{
	return 0x00584218U;
}
static inline u32 gr_egpc0_etpc0_sm_dsm_perf_counter_control4_r(void)
{
	return 0x0058421cU;
}
static inline u32 gr_egpc0_etpc0_sm_dsm_perf_counter_control5_r(void)
{
	return 0x0058420cU;
}
static inline u32 gr_egpc0_etpc0_sm_dsm_perf_counter0_control_r(void)
{
	return 0x00584220U;
}
static inline u32 gr_egpc0_etpc0_sm_dsm_perf_counter1_control_r(void)
{
	return 0x00584224U;
}
static inline u32 gr_egpc0_etpc0_sm_dsm_perf_counter2_control_r(void)
{
	return 0x00584228U;
}
static inline u32 gr_egpc0_etpc0_sm_dsm_perf_counter3_control_r(void)
{
	return 0x0058422cU;
}
static inline u32 gr_egpc0_etpc0_sm_dsm_perf_counter4_control_r(void)
{
	return 0x00584230U;
}
static inline u32 gr_egpc0_etpc0_sm_dsm_perf_counter5_control_r(void)
{
	return 0x00584234U;
}
static inline u32 gr_egpc0_etpc0_sm_dsm_perf_counter6_control_r(void)
{
	return 0x00584238U;
}
static inline u32 gr_egpc0_etpc0_sm_dsm_perf_counter7_control_r(void)
{
	return 0x0058423cU;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter_status_s0_r(void)
{
	return 0x00584600U;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter_status_s1_r(void)
{
	return 0x00584604U;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter0_s0_r(void)
{
	return 0x00584624U;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter1_s0_r(void)
{
	return 0x00584628U;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter2_s0_r(void)
{
	return 0x0058462cU;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter3_s0_r(void)
{
	return 0x00584630U;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter0_s1_r(void)
{
	return 0x00584634U;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter1_s1_r(void)
{
	return 0x00584638U;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter2_s1_r(void)
{
	return 0x0058463cU;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter3_s1_r(void)
{
	return 0x00584640U;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter0_s2_r(void)
{
	return 0x00584644U;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter1_s2_r(void)
{
	return 0x00584648U;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter2_s2_r(void)
{
	return 0x0058464cU;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter3_s2_r(void)
{
	return 0x00584650U;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter0_s3_r(void)
{
	return 0x00584654U;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter1_s3_r(void)
{
	return 0x00584658U;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter2_s3_r(void)
{
	return 0x0058465cU;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter3_s3_r(void)
{
	return 0x00584660U;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter4_r(void)
{
	return 0x00584614U;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter5_r(void)
{
	return 0x00584618U;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter6_r(void)
{
	return 0x0058461cU;
}
static inline u32 gr_egpc0_etpc0_sm0_dsm_perf_counter7_r(void)
{
	return 0x00584620U;
}
static inline u32 gr_fe_pwr_mode_r(void)
{
	return 0x00404170U;
}
static inline u32 gr_fe_pwr_mode_mode_auto_f(void)
{
	return 0x0U;
}
static inline u32 gr_fe_pwr_mode_mode_force_on_f(void)
{
	return 0x2U;
}
static inline u32 gr_fe_pwr_mode_req_v(u32 r)
{
	return (r >> 4U) & 0x1U;
}
static inline u32 gr_fe_pwr_mode_req_send_f(void)
{
	return 0x10U;
}
static inline u32 gr_fe_pwr_mode_req_done_v(void)
{
	return 0x00000000U;
}
static inline u32 gr_gpcs_pri_mmu_ctrl_r(void)
{
	return 0x00418880U;
}
static inline u32 gr_gpcs_pri_mmu_ctrl_vm_pg_size_m(void)
{
	return 0x1U << 0U;
}
static inline u32 gr_gpcs_pri_mmu_ctrl_use_pdb_big_page_size_m(void)
{
	return 0x1U << 11U;
}
static inline u32 gr_gpcs_pri_mmu_ctrl_vol_fault_m(void)
{
	return 0x1U << 1U;
}
static inline u32 gr_gpcs_pri_mmu_ctrl_comp_fault_m(void)
{
	return 0x1U << 2U;
}
static inline u32 gr_gpcs_pri_mmu_ctrl_miss_gran_m(void)
{
	return 0x3U << 3U;
}
static inline u32 gr_gpcs_pri_mmu_ctrl_cache_mode_m(void)
{
	return 0x3U << 5U;
}
static inline u32 gr_gpcs_pri_mmu_ctrl_mmu_aperture_m(void)
{
	return 0x3U << 28U;
}
static inline u32 gr_gpcs_pri_mmu_ctrl_mmu_vol_m(void)
{
	return 0x1U << 30U;
}
static inline u32 gr_gpcs_pri_mmu_ctrl_mmu_disable_m(void)
{
	return 0x1U << 31U;
}
static inline u32 gr_gpcs_pri_mmu_pm_unit_mask_r(void)
{
	return 0x00418890U;
}
static inline u32 gr_gpcs_pri_mmu_pm_req_mask_r(void)
{
	return 0x00418894U;
}
static inline u32 gr_gpcs_pri_mmu_debug_ctrl_r(void)
{
	return 0x004188b0U;
}
static inline u32 gr_gpcs_pri_mmu_debug_ctrl_debug_v(u32 r)
{
	return (r >> 16U) & 0x1U;
}
static inline u32 gr_gpcs_pri_mmu_debug_ctrl_debug_enabled_v(void)
{
	return 0x00000001U;
}
static inline u32 gr_gpcs_pri_mmu_debug_wr_r(void)
{
	return 0x004188b4U;
}
static inline u32 gr_gpcs_pri_mmu_debug_rd_r(void)
{
	return 0x004188b8U;
}
static inline u32 gr_gpcs_mmu_num_active_ltcs_r(void)
{
	return 0x004188acU;
}
static inline u32 gr_gpcs_tpcs_sms_dbgr_control0_r(void)
{
	return 0x00419e84U;
}
static inline u32 gr_fe_gfxp_wfi_timeout_r(void)
{
	return 0x004041c0U;
}
static inline u32 gr_fe_gfxp_wfi_timeout_count_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_fe_gfxp_wfi_timeout_count_disabled_f(void)
{
	return 0x0U;
}
static inline u32 gr_fe_gfxp_wfi_timeout_count_init_f(void)
{
	return 0x800U;
}
static inline u32 gr_gpcs_tpcs_sm_texio_control_r(void)
{
	return 0x00419bd8U;
}
static inline u32 gr_gpcs_tpcs_sm_texio_control_oor_addr_check_mode_f(u32 v)
{
	return (v & 0x7U) << 8U;
}
static inline u32 gr_gpcs_tpcs_sm_texio_control_oor_addr_check_mode_m(void)
{
	return 0x7U << 8U;
}
static inline u32 gr_gpcs_tpcs_sm_texio_control_oor_addr_check_mode_arm_63_48_match_f(void)
{
	return 0x100U;
}
static inline u32 gr_gpcs_tpcs_sm_disp_ctrl_r(void)
{
	return 0x00419ba4U;
}
static inline u32 gr_gpcs_tpcs_sm_disp_ctrl_re_suppress_m(void)
{
	return 0x3U << 11U;
}
static inline u32 gr_gpcs_tpcs_sm_disp_ctrl_re_suppress_disable_f(void)
{
	return 0x1000U;
}
static inline u32 gr_gpcs_tc_debug0_r(void)
{
	return 0x00418708U;
}
static inline u32 gr_gpcs_tc_debug0_limit_coalesce_buffer_size_f(u32 v)
{
	return (v & 0x1ffU) << 0U;
}
static inline u32 gr_gpcs_tc_debug0_limit_coalesce_buffer_size_m(void)
{
	return 0x1ffU << 0U;
}
static inline u32 gr_gpc0_mmu_gpcmmu_global_esr_r(void)
{
	return 0x00500324U;
}
static inline u32 gr_gpc0_mmu_gpcmmu_global_esr_ecc_corrected_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_gpc0_mmu_gpcmmu_global_esr_ecc_corrected_m(void)
{
	return 0x1U << 0U;
}
static inline u32 gr_gpc0_mmu_gpcmmu_global_esr_ecc_uncorrected_f(u32 v)
{
	return (v & 0x1U) << 1U;
}
static inline u32 gr_gpc0_mmu_gpcmmu_global_esr_ecc_uncorrected_m(void)
{
	return 0x1U << 1U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_status_r(void)
{
	return 0x00500314U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_status_corrected_err_l1tlb_sa_data_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_status_corrected_err_l1tlb_sa_data_m(void)
{
	return 0x1U << 0U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_status_corrected_err_l1tlb_fa_data_f(u32 v)
{
	return (v & 0x1U) << 2U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_status_corrected_err_l1tlb_fa_data_m(void)
{
	return 0x1U << 2U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_status_uncorrected_err_l1tlb_sa_data_f(u32 v)
{
	return (v & 0x1U) << 1U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_status_uncorrected_err_l1tlb_sa_data_m(void)
{
	return 0x1U << 1U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_status_uncorrected_err_l1tlb_fa_data_f(u32 v)
{
	return (v & 0x1U) << 3U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_status_uncorrected_err_l1tlb_fa_data_m(void)
{
	return 0x1U << 3U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_status_uncorrected_err_total_counter_overflow_f(u32 v)
{
	return (v & 0x1U) << 18U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_status_uncorrected_err_total_counter_overflow_m(void)
{
	return 0x1U << 18U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_status_corrected_err_total_counter_overflow_f(u32 v)
{
	return (v & 0x1U) << 16U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_status_corrected_err_total_counter_overflow_m(void)
{
	return 0x1U << 16U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_status_uncorrected_err_unique_counter_overflow_f(u32 v)
{
	return (v & 0x1U) << 19U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_status_uncorrected_err_unique_counter_overflow_m(void)
{
	return 0x1U << 19U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_status_corrected_err_unique_counter_overflow_f(u32 v)
{
	return (v & 0x1U) << 17U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_status_corrected_err_unique_counter_overflow_m(void)
{
	return 0x1U << 17U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_status_reset_f(u32 v)
{
	return (v & 0x1U) << 30U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_status_reset_task_f(void)
{
	return 0x40000000U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_address_r(void)
{
	return 0x00500320U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_address_index_f(u32 v)
{
	return (v & 0xffffffffU) << 0U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_corrected_err_count_r(void)
{
	return 0x00500318U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_corrected_err_count_total_s(void)
{
	return 16U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_corrected_err_count_total_f(u32 v)
{
	return (v & 0xffffU) << 0U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_corrected_err_count_total_m(void)
{
	return 0xffffU << 0U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_corrected_err_count_total_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_corrected_err_count_unique_total_s(void)
{
	return 16U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_corrected_err_count_unique_total_f(u32 v)
{
	return (v & 0xffffU) << 16U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_corrected_err_count_unique_total_m(void)
{
	return 0xffffU << 16U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_corrected_err_count_unique_total_v(u32 r)
{
	return (r >> 16U) & 0xffffU;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_uncorrected_err_count_r(void)
{
	return 0x0050031cU;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_uncorrected_err_count_total_s(void)
{
	return 16U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_uncorrected_err_count_total_f(u32 v)
{
	return (v & 0xffffU) << 0U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_uncorrected_err_count_total_m(void)
{
	return 0xffffU << 0U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_uncorrected_err_count_total_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_uncorrected_err_count_unique_total_s(void)
{
	return 16U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_uncorrected_err_count_unique_total_f(u32 v)
{
	return (v & 0xffffU) << 16U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_uncorrected_err_count_unique_total_m(void)
{
	return 0xffffU << 16U;
}
static inline u32 gr_gpc0_mmu_l1tlb_ecc_uncorrected_err_count_unique_total_v(u32 r)
{
	return (r >> 16U) & 0xffffU;
}
static inline u32 gr_gpc0_gpccs_hww_esr_r(void)
{
	return 0x00502c98U;
}
static inline u32 gr_gpc0_gpccs_hww_esr_ecc_corrected_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_gpc0_gpccs_hww_esr_ecc_corrected_m(void)
{
	return 0x1U << 0U;
}
static inline u32 gr_gpc0_gpccs_hww_esr_ecc_corrected_pending_f(void)
{
	return 0x1U;
}
static inline u32 gr_gpc0_gpccs_hww_esr_ecc_uncorrected_f(u32 v)
{
	return (v & 0x1U) << 1U;
}
static inline u32 gr_gpc0_gpccs_hww_esr_ecc_uncorrected_m(void)
{
	return 0x1U << 1U;
}
static inline u32 gr_gpc0_gpccs_hww_esr_ecc_uncorrected_pending_f(void)
{
	return 0x2U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_r(void)
{
	return 0x00502678U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_corrected_err_imem_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_corrected_err_imem_m(void)
{
	return 0x1U << 0U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_corrected_err_imem_pending_f(void)
{
	return 0x1U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_corrected_err_dmem_f(u32 v)
{
	return (v & 0x1U) << 1U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_corrected_err_dmem_m(void)
{
	return 0x1U << 1U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_corrected_err_dmem_pending_f(void)
{
	return 0x2U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_imem_f(u32 v)
{
	return (v & 0x1U) << 4U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_imem_m(void)
{
	return 0x1U << 4U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_imem_pending_f(void)
{
	return 0x10U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_dmem_f(u32 v)
{
	return (v & 0x1U) << 5U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_dmem_m(void)
{
	return 0x1U << 5U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_dmem_pending_f(void)
{
	return 0x20U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_total_counter_overflow_f(u32 v)
{
	return (v & 0x1U) << 10U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_total_counter_overflow_m(void)
{
	return 0x1U << 10U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_total_counter_overflow_pending_f(void)
{
	return 0x400U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_corrected_err_total_counter_overflow_f(u32 v)
{
	return (v & 0x1U) << 8U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_corrected_err_total_counter_overflow_m(void)
{
	return 0x1U << 8U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_corrected_err_total_counter_overflow_pending_f(void)
{
	return 0x100U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_unique_counter_overflow_f(u32 v)
{
	return (v & 0x1U) << 11U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_unique_counter_overflow_m(void)
{
	return 0x1U << 11U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_unique_counter_overflow_pending_f(void)
{
	return 0x800U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_corrected_err_unique_counter_overflow_f(u32 v)
{
	return (v & 0x1U) << 9U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_corrected_err_unique_counter_overflow_m(void)
{
	return 0x1U << 9U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_corrected_err_unique_counter_overflow_pending_f(void)
{
	return 0x200U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_reset_f(u32 v)
{
	return (v & 0x1U) << 31U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_status_reset_task_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_address_r(void)
{
	return 0x00502684U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_address_index_f(u32 v)
{
	return (v & 0x7fffffU) << 0U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_address_row_address_s(void)
{
	return 20U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_address_row_address_f(u32 v)
{
	return (v & 0xfffffU) << 0U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_address_row_address_m(void)
{
	return 0xfffffU << 0U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_address_row_address_v(u32 r)
{
	return (r >> 0U) & 0xfffffU;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_corrected_err_count_r(void)
{
	return 0x0050267cU;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_corrected_err_count_total_s(void)
{
	return 16U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_corrected_err_count_total_f(u32 v)
{
	return (v & 0xffffU) << 0U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_corrected_err_count_total_m(void)
{
	return 0xffffU << 0U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_corrected_err_count_total_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_corrected_err_count_unique_total_s(void)
{
	return 16U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_corrected_err_count_unique_total_f(u32 v)
{
	return (v & 0xffffU) << 16U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_corrected_err_count_unique_total_m(void)
{
	return 0xffffU << 16U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_corrected_err_count_unique_total_v(u32 r)
{
	return (r >> 16U) & 0xffffU;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_uncorrected_err_count_r(void)
{
	return 0x00502680U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_uncorrected_err_count_total_f(u32 v)
{
	return (v & 0xffffU) << 0U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_uncorrected_err_count_total_m(void)
{
	return 0xffffU << 0U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_uncorrected_err_count_total_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_uncorrected_err_count_unique_total_s(void)
{
	return 16U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_uncorrected_err_count_unique_total_f(u32 v)
{
	return (v & 0xffffU) << 16U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_uncorrected_err_count_unique_total_m(void)
{
	return 0xffffU << 16U;
}
static inline u32 gr_gpc0_gpccs_falcon_ecc_uncorrected_err_count_unique_total_v(u32 r)
{
	return (r >> 16U) & 0xffffU;
}
static inline u32 gr_fecs_falcon_ecc_status_r(void)
{
	return 0x00409678U;
}
static inline u32 gr_fecs_falcon_ecc_status_corrected_err_imem_f(u32 v)
{
	return (v & 0x1U) << 0U;
}
static inline u32 gr_fecs_falcon_ecc_status_corrected_err_imem_m(void)
{
	return 0x1U << 0U;
}
static inline u32 gr_fecs_falcon_ecc_status_corrected_err_imem_pending_f(void)
{
	return 0x1U;
}
static inline u32 gr_fecs_falcon_ecc_status_corrected_err_dmem_f(u32 v)
{
	return (v & 0x1U) << 1U;
}
static inline u32 gr_fecs_falcon_ecc_status_corrected_err_dmem_m(void)
{
	return 0x1U << 1U;
}
static inline u32 gr_fecs_falcon_ecc_status_corrected_err_dmem_pending_f(void)
{
	return 0x2U;
}
static inline u32 gr_fecs_falcon_ecc_status_uncorrected_err_imem_f(u32 v)
{
	return (v & 0x1U) << 4U;
}
static inline u32 gr_fecs_falcon_ecc_status_uncorrected_err_imem_m(void)
{
	return 0x1U << 4U;
}
static inline u32 gr_fecs_falcon_ecc_status_uncorrected_err_imem_pending_f(void)
{
	return 0x10U;
}
static inline u32 gr_fecs_falcon_ecc_status_uncorrected_err_dmem_f(u32 v)
{
	return (v & 0x1U) << 5U;
}
static inline u32 gr_fecs_falcon_ecc_status_uncorrected_err_dmem_m(void)
{
	return 0x1U << 5U;
}
static inline u32 gr_fecs_falcon_ecc_status_uncorrected_err_dmem_pending_f(void)
{
	return 0x20U;
}
static inline u32 gr_fecs_falcon_ecc_status_uncorrected_err_total_counter_overflow_f(u32 v)
{
	return (v & 0x1U) << 10U;
}
static inline u32 gr_fecs_falcon_ecc_status_uncorrected_err_total_counter_overflow_m(void)
{
	return 0x1U << 10U;
}
static inline u32 gr_fecs_falcon_ecc_status_uncorrected_err_total_counter_overflow_pending_f(void)
{
	return 0x400U;
}
static inline u32 gr_fecs_falcon_ecc_status_corrected_err_total_counter_overflow_f(u32 v)
{
	return (v & 0x1U) << 8U;
}
static inline u32 gr_fecs_falcon_ecc_status_corrected_err_total_counter_overflow_m(void)
{
	return 0x1U << 8U;
}
static inline u32 gr_fecs_falcon_ecc_status_corrected_err_total_counter_overflow_pending_f(void)
{
	return 0x100U;
}
static inline u32 gr_fecs_falcon_ecc_status_uncorrected_err_unique_counter_overflow_f(u32 v)
{
	return (v & 0x1U) << 11U;
}
static inline u32 gr_fecs_falcon_ecc_status_uncorrected_err_unique_counter_overflow_m(void)
{
	return 0x1U << 11U;
}
static inline u32 gr_fecs_falcon_ecc_status_uncorrected_err_unique_counter_overflow_pending_f(void)
{
	return 0x800U;
}
static inline u32 gr_fecs_falcon_ecc_status_corrected_err_unique_counter_overflow_f(u32 v)
{
	return (v & 0x1U) << 9U;
}
static inline u32 gr_fecs_falcon_ecc_status_corrected_err_unique_counter_overflow_m(void)
{
	return 0x1U << 9U;
}
static inline u32 gr_fecs_falcon_ecc_status_corrected_err_unique_counter_overflow_pending_f(void)
{
	return 0x200U;
}
static inline u32 gr_fecs_falcon_ecc_status_reset_f(u32 v)
{
	return (v & 0x1U) << 31U;
}
static inline u32 gr_fecs_falcon_ecc_status_reset_task_f(void)
{
	return 0x80000000U;
}
static inline u32 gr_fecs_falcon_ecc_address_r(void)
{
	return 0x00409684U;
}
static inline u32 gr_fecs_falcon_ecc_address_index_f(u32 v)
{
	return (v & 0x7fffffU) << 0U;
}
static inline u32 gr_fecs_falcon_ecc_address_row_address_s(void)
{
	return 20U;
}
static inline u32 gr_fecs_falcon_ecc_address_row_address_f(u32 v)
{
	return (v & 0xfffffU) << 0U;
}
static inline u32 gr_fecs_falcon_ecc_address_row_address_m(void)
{
	return 0xfffffU << 0U;
}
static inline u32 gr_fecs_falcon_ecc_address_row_address_v(u32 r)
{
	return (r >> 0U) & 0xfffffU;
}
static inline u32 gr_fecs_falcon_ecc_corrected_err_count_r(void)
{
	return 0x0040967cU;
}
static inline u32 gr_fecs_falcon_ecc_corrected_err_count_total_s(void)
{
	return 16U;
}
static inline u32 gr_fecs_falcon_ecc_corrected_err_count_total_f(u32 v)
{
	return (v & 0xffffU) << 0U;
}
static inline u32 gr_fecs_falcon_ecc_corrected_err_count_total_m(void)
{
	return 0xffffU << 0U;
}
static inline u32 gr_fecs_falcon_ecc_corrected_err_count_total_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_fecs_falcon_ecc_corrected_err_count_unique_total_s(void)
{
	return 16U;
}
static inline u32 gr_fecs_falcon_ecc_corrected_err_count_unique_total_f(u32 v)
{
	return (v & 0xffffU) << 16U;
}
static inline u32 gr_fecs_falcon_ecc_corrected_err_count_unique_total_m(void)
{
	return 0xffffU << 16U;
}
static inline u32 gr_fecs_falcon_ecc_corrected_err_count_unique_total_v(u32 r)
{
	return (r >> 16U) & 0xffffU;
}
static inline u32 gr_fecs_falcon_ecc_uncorrected_err_count_r(void)
{
	return 0x00409680U;
}
static inline u32 gr_fecs_falcon_ecc_uncorrected_err_count_total_f(u32 v)
{
	return (v & 0xffffU) << 0U;
}
static inline u32 gr_fecs_falcon_ecc_uncorrected_err_count_total_m(void)
{
	return 0xffffU << 0U;
}
static inline u32 gr_fecs_falcon_ecc_uncorrected_err_count_total_v(u32 r)
{
	return (r >> 0U) & 0xffffU;
}
static inline u32 gr_fecs_falcon_ecc_uncorrected_err_count_unique_total_s(void)
{
	return 16U;
}
static inline u32 gr_fecs_falcon_ecc_uncorrected_err_count_unique_total_f(u32 v)
{
	return (v & 0xffffU) << 16U;
}
static inline u32 gr_fecs_falcon_ecc_uncorrected_err_count_unique_total_m(void)
{
	return 0xffffU << 16U;
}
static inline u32 gr_fecs_falcon_ecc_uncorrected_err_count_unique_total_v(u32 r)
{
	return (r >> 16U) & 0xffffU;
}
static inline u32 gr_debug_2_r(void)
{
	return 0x00400088U;
}
static inline u32 gr_debug_2_gfxp_wfi_timeout_unit_m(void)
{
	return 0x1U << 27U;
}
static inline u32 gr_debug_2_gfxp_wfi_timeout_unit_usec_f(void)
{
	return 0x0U;
}
static inline u32 gr_debug_2_gfxp_wfi_timeout_unit_sysclk_f(void)
{
	return 0x8000000U;
}
#endif
