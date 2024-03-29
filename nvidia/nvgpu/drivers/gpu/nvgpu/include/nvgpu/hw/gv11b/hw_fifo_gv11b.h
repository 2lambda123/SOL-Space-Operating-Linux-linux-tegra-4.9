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
#ifndef _hw_fifo_gv11b_h_
#define _hw_fifo_gv11b_h_

static inline u32 fifo_bar1_base_r(void)
{
	return 0x00002254U;
}
static inline u32 fifo_bar1_base_ptr_f(u32 v)
{
	return (v & 0xfffffffU) << 0U;
}
static inline u32 fifo_bar1_base_ptr_align_shift_v(void)
{
	return 0x0000000cU;
}
static inline u32 fifo_bar1_base_valid_false_f(void)
{
	return 0x0U;
}
static inline u32 fifo_bar1_base_valid_true_f(void)
{
	return 0x10000000U;
}
static inline u32 fifo_userd_writeback_r(void)
{
	return 0x0000225cU;
}
static inline u32 fifo_userd_writeback_timer_f(u32 v)
{
	return (v & 0xffU) << 0U;
}
static inline u32 fifo_userd_writeback_timer_disabled_v(void)
{
	return 0x00000000U;
}
static inline u32 fifo_userd_writeback_timer_shorter_v(void)
{
	return 0x00000003U;
}
static inline u32 fifo_userd_writeback_timer_100us_v(void)
{
	return 0x00000064U;
}
static inline u32 fifo_userd_writeback_timescale_f(u32 v)
{
	return (v & 0xfU) << 12U;
}
static inline u32 fifo_userd_writeback_timescale_0_v(void)
{
	return 0x00000000U;
}
static inline u32 fifo_runlist_base_r(void)
{
	return 0x00002270U;
}
static inline u32 fifo_runlist_base_ptr_f(u32 v)
{
	return (v & 0xfffffffU) << 0U;
}
static inline u32 fifo_runlist_base_target_vid_mem_f(void)
{
	return 0x0U;
}
static inline u32 fifo_runlist_base_target_sys_mem_coh_f(void)
{
	return 0x20000000U;
}
static inline u32 fifo_runlist_base_target_sys_mem_ncoh_f(void)
{
	return 0x30000000U;
}
static inline u32 fifo_runlist_r(void)
{
	return 0x00002274U;
}
static inline u32 fifo_runlist_engine_f(u32 v)
{
	return (v & 0xfU) << 20U;
}
static inline u32 fifo_eng_runlist_base_r(u32 i)
{
	return 0x00002280U + i*8U;
}
static inline u32 fifo_eng_runlist_base__size_1_v(void)
{
	return 0x00000002U;
}
static inline u32 fifo_eng_runlist_r(u32 i)
{
	return 0x00002284U + i*8U;
}
static inline u32 fifo_eng_runlist__size_1_v(void)
{
	return 0x00000002U;
}
static inline u32 fifo_eng_runlist_length_f(u32 v)
{
	return (v & 0xffffU) << 0U;
}
static inline u32 fifo_eng_runlist_length_max_v(void)
{
	return 0x0000ffffU;
}
static inline u32 fifo_eng_runlist_pending_true_f(void)
{
	return 0x100000U;
}
static inline u32 fifo_pb_timeslice_r(u32 i)
{
	return 0x00002350U + i*4U;
}
static inline u32 fifo_pb_timeslice_timeout_16_f(void)
{
	return 0x10U;
}
static inline u32 fifo_pb_timeslice_timescale_0_f(void)
{
	return 0x0U;
}
static inline u32 fifo_pb_timeslice_enable_true_f(void)
{
	return 0x10000000U;
}
static inline u32 fifo_pbdma_map_r(u32 i)
{
	return 0x00002390U + i*4U;
}
static inline u32 fifo_intr_0_r(void)
{
	return 0x00002100U;
}
static inline u32 fifo_intr_0_bind_error_pending_f(void)
{
	return 0x1U;
}
static inline u32 fifo_intr_0_bind_error_reset_f(void)
{
	return 0x1U;
}
static inline u32 fifo_intr_0_sched_error_pending_f(void)
{
	return 0x100U;
}
static inline u32 fifo_intr_0_sched_error_reset_f(void)
{
	return 0x100U;
}
static inline u32 fifo_intr_0_chsw_error_pending_f(void)
{
	return 0x10000U;
}
static inline u32 fifo_intr_0_chsw_error_reset_f(void)
{
	return 0x10000U;
}
static inline u32 fifo_intr_0_memop_timeout_pending_f(void)
{
	return 0x800000U;
}
static inline u32 fifo_intr_0_memop_timeout_reset_f(void)
{
	return 0x800000U;
}
static inline u32 fifo_intr_0_lb_error_pending_f(void)
{
	return 0x1000000U;
}
static inline u32 fifo_intr_0_lb_error_reset_f(void)
{
	return 0x1000000U;
}
static inline u32 fifo_intr_0_pbdma_intr_pending_f(void)
{
	return 0x20000000U;
}
static inline u32 fifo_intr_0_runlist_event_pending_f(void)
{
	return 0x40000000U;
}
static inline u32 fifo_intr_0_channel_intr_pending_f(void)
{
	return 0x80000000U;
}
static inline u32 fifo_intr_0_ctxsw_timeout_pending_f(void)
{
	return 0x2U;
}
static inline u32 fifo_intr_en_0_r(void)
{
	return 0x00002140U;
}
static inline u32 fifo_intr_en_0_sched_error_f(u32 v)
{
	return (v & 0x1U) << 8U;
}
static inline u32 fifo_intr_en_0_sched_error_m(void)
{
	return 0x1U << 8U;
}
static inline u32 fifo_intr_en_0_ctxsw_timeout_pending_f(void)
{
	return 0x2U;
}
static inline u32 fifo_intr_en_1_r(void)
{
	return 0x00002528U;
}
static inline u32 fifo_intr_bind_error_r(void)
{
	return 0x0000252cU;
}
static inline u32 fifo_intr_sched_error_r(void)
{
	return 0x0000254cU;
}
static inline u32 fifo_intr_sched_error_code_f(u32 v)
{
	return (v & 0xffU) << 0U;
}
static inline u32 fifo_intr_chsw_error_r(void)
{
	return 0x0000256cU;
}
static inline u32 fifo_intr_ctxsw_timeout_r(void)
{
	return 0x00002a30U;
}
static inline u32 fifo_intr_ctxsw_timeout_engine_f(u32 v, u32 i)
{
	return (v & 0x1U) << (0U + i*1U);
}
static inline u32 fifo_intr_ctxsw_timeout_engine_v(u32 r, u32 i)
{
	return (r >> (0U + i*1U)) & 0x1U;
}
static inline u32 fifo_intr_ctxsw_timeout_engine__size_1_v(void)
{
	return 0x00000020U;
}
static inline u32 fifo_intr_ctxsw_timeout_engine_pending_v(void)
{
	return 0x00000001U;
}
static inline u32 fifo_intr_ctxsw_timeout_engine_pending_f(u32 i)
{
	return 0x1U << (0U + i*1U);
}
static inline u32 fifo_intr_ctxsw_timeout_info_r(u32 i)
{
	return 0x00003200U + i*4U;
}
static inline u32 fifo_intr_ctxsw_timeout_info__size_1_v(void)
{
	return 0x00000004U;
}
static inline u32 fifo_intr_ctxsw_timeout_info_ctxsw_state_v(u32 r)
{
	return (r >> 14U) & 0x3U;
}
static inline u32 fifo_intr_ctxsw_timeout_info_ctxsw_state_load_v(void)
{
	return 0x00000001U;
}
static inline u32 fifo_intr_ctxsw_timeout_info_ctxsw_state_save_v(void)
{
	return 0x00000002U;
}
static inline u32 fifo_intr_ctxsw_timeout_info_ctxsw_state_switch_v(void)
{
	return 0x00000003U;
}
static inline u32 fifo_intr_ctxsw_timeout_info_prev_tsgid_v(u32 r)
{
	return (r >> 0U) & 0x3fffU;
}
static inline u32 fifo_intr_ctxsw_timeout_info_next_tsgid_v(u32 r)
{
	return (r >> 16U) & 0x3fffU;
}
static inline u32 fifo_intr_ctxsw_timeout_info_status_v(u32 r)
{
	return (r >> 30U) & 0x3U;
}
static inline u32 fifo_intr_ctxsw_timeout_info_status_awaiting_ack_v(void)
{
	return 0x00000000U;
}
static inline u32 fifo_intr_ctxsw_timeout_info_status_eng_was_reset_v(void)
{
	return 0x00000001U;
}
static inline u32 fifo_intr_ctxsw_timeout_info_status_ack_received_v(void)
{
	return 0x00000002U;
}
static inline u32 fifo_intr_ctxsw_timeout_info_status_dropped_timeout_v(void)
{
	return 0x00000003U;
}
static inline u32 fifo_intr_pbdma_id_r(void)
{
	return 0x000025a0U;
}
static inline u32 fifo_intr_pbdma_id_status_f(u32 v, u32 i)
{
	return (v & 0x1U) << (0U + i*1U);
}
static inline u32 fifo_intr_pbdma_id_status_v(u32 r, u32 i)
{
	return (r >> (0U + i*1U)) & 0x1U;
}
static inline u32 fifo_intr_pbdma_id_status__size_1_v(void)
{
	return 0x00000003U;
}
static inline u32 fifo_intr_runlist_r(void)
{
	return 0x00002a00U;
}
static inline u32 fifo_fb_timeout_r(void)
{
	return 0x00002a04U;
}
static inline u32 fifo_fb_timeout_period_m(void)
{
	return 0x3fffffffU << 0U;
}
static inline u32 fifo_fb_timeout_period_max_f(void)
{
	return 0x3fffffffU;
}
static inline u32 fifo_fb_timeout_period_init_f(void)
{
	return 0x3c00U;
}
static inline u32 fifo_fb_timeout_detection_m(void)
{
	return 0x1U << 31U;
}
static inline u32 fifo_fb_timeout_detection_enabled_f(void)
{
	return 0x80000000U;
}
static inline u32 fifo_fb_timeout_detection_disabled_f(void)
{
	return 0x0U;
}
static inline u32 fifo_sched_disable_r(void)
{
	return 0x00002630U;
}
static inline u32 fifo_sched_disable_runlist_f(u32 v, u32 i)
{
	return (v & 0x1U) << (0U + i*1U);
}
static inline u32 fifo_sched_disable_runlist_m(u32 i)
{
	return 0x1U << (0U + i*1U);
}
static inline u32 fifo_sched_disable_true_v(void)
{
	return 0x00000001U;
}
static inline u32 fifo_runlist_preempt_r(void)
{
	return 0x00002638U;
}
static inline u32 fifo_runlist_preempt_runlist_f(u32 v, u32 i)
{
	return (v & 0x1U) << (0U + i*1U);
}
static inline u32 fifo_runlist_preempt_runlist_m(u32 i)
{
	return 0x1U << (0U + i*1U);
}
static inline u32 fifo_runlist_preempt_runlist_pending_v(void)
{
	return 0x00000001U;
}
static inline u32 fifo_preempt_r(void)
{
	return 0x00002634U;
}
static inline u32 fifo_preempt_pending_true_f(void)
{
	return 0x100000U;
}
static inline u32 fifo_preempt_type_channel_f(void)
{
	return 0x0U;
}
static inline u32 fifo_preempt_type_tsg_f(void)
{
	return 0x1000000U;
}
static inline u32 fifo_preempt_chid_f(u32 v)
{
	return (v & 0xfffU) << 0U;
}
static inline u32 fifo_preempt_id_f(u32 v)
{
	return (v & 0xfffU) << 0U;
}
static inline u32 fifo_engine_status_r(u32 i)
{
	return 0x00002640U + i*8U;
}
static inline u32 fifo_engine_status__size_1_v(void)
{
	return 0x00000004U;
}
static inline u32 fifo_engine_status_id_v(u32 r)
{
	return (r >> 0U) & 0xfffU;
}
static inline u32 fifo_engine_status_id_type_v(u32 r)
{
	return (r >> 12U) & 0x1U;
}
static inline u32 fifo_engine_status_id_type_chid_v(void)
{
	return 0x00000000U;
}
static inline u32 fifo_engine_status_id_type_tsgid_v(void)
{
	return 0x00000001U;
}
static inline u32 fifo_engine_status_ctx_status_v(u32 r)
{
	return (r >> 13U) & 0x7U;
}
static inline u32 fifo_engine_status_ctx_status_valid_v(void)
{
	return 0x00000001U;
}
static inline u32 fifo_engine_status_ctx_status_ctxsw_load_v(void)
{
	return 0x00000005U;
}
static inline u32 fifo_engine_status_ctx_status_ctxsw_save_v(void)
{
	return 0x00000006U;
}
static inline u32 fifo_engine_status_ctx_status_ctxsw_switch_v(void)
{
	return 0x00000007U;
}
static inline u32 fifo_engine_status_next_id_v(u32 r)
{
	return (r >> 16U) & 0xfffU;
}
static inline u32 fifo_engine_status_next_id_type_v(u32 r)
{
	return (r >> 28U) & 0x1U;
}
static inline u32 fifo_engine_status_next_id_type_chid_v(void)
{
	return 0x00000000U;
}
static inline u32 fifo_engine_status_eng_reload_v(u32 r)
{
	return (r >> 29U) & 0x1U;
}
static inline u32 fifo_engine_status_faulted_v(u32 r)
{
	return (r >> 30U) & 0x1U;
}
static inline u32 fifo_engine_status_faulted_true_v(void)
{
	return 0x00000001U;
}
static inline u32 fifo_engine_status_engine_v(u32 r)
{
	return (r >> 31U) & 0x1U;
}
static inline u32 fifo_engine_status_engine_idle_v(void)
{
	return 0x00000000U;
}
static inline u32 fifo_engine_status_engine_busy_v(void)
{
	return 0x00000001U;
}
static inline u32 fifo_engine_status_ctxsw_v(u32 r)
{
	return (r >> 15U) & 0x1U;
}
static inline u32 fifo_engine_status_ctxsw_in_progress_v(void)
{
	return 0x00000001U;
}
static inline u32 fifo_engine_status_ctxsw_in_progress_f(void)
{
	return 0x8000U;
}
static inline u32 fifo_eng_ctxsw_timeout_r(void)
{
	return 0x00002a0cU;
}
static inline u32 fifo_eng_ctxsw_timeout_period_f(u32 v)
{
	return (v & 0x7fffffffU) << 0U;
}
static inline u32 fifo_eng_ctxsw_timeout_period_m(void)
{
	return 0x7fffffffU << 0U;
}
static inline u32 fifo_eng_ctxsw_timeout_period_v(u32 r)
{
	return (r >> 0U) & 0x7fffffffU;
}
static inline u32 fifo_eng_ctxsw_timeout_period_init_f(void)
{
	return 0x3fffffU;
}
static inline u32 fifo_eng_ctxsw_timeout_period_max_f(void)
{
	return 0x7fffffffU;
}
static inline u32 fifo_eng_ctxsw_timeout_detection_f(u32 v)
{
	return (v & 0x1U) << 31U;
}
static inline u32 fifo_eng_ctxsw_timeout_detection_m(void)
{
	return 0x1U << 31U;
}
static inline u32 fifo_eng_ctxsw_timeout_detection_enabled_f(void)
{
	return 0x80000000U;
}
static inline u32 fifo_eng_ctxsw_timeout_detection_disabled_f(void)
{
	return 0x0U;
}
static inline u32 fifo_pbdma_status_r(u32 i)
{
	return 0x00003080U + i*4U;
}
static inline u32 fifo_pbdma_status__size_1_v(void)
{
	return 0x00000003U;
}
static inline u32 fifo_pbdma_status_id_v(u32 r)
{
	return (r >> 0U) & 0xfffU;
}
static inline u32 fifo_pbdma_status_id_type_v(u32 r)
{
	return (r >> 12U) & 0x1U;
}
static inline u32 fifo_pbdma_status_id_type_chid_v(void)
{
	return 0x00000000U;
}
static inline u32 fifo_pbdma_status_id_type_tsgid_v(void)
{
	return 0x00000001U;
}
static inline u32 fifo_pbdma_status_chan_status_v(u32 r)
{
	return (r >> 13U) & 0x7U;
}
static inline u32 fifo_pbdma_status_chan_status_valid_v(void)
{
	return 0x00000001U;
}
static inline u32 fifo_pbdma_status_chan_status_chsw_load_v(void)
{
	return 0x00000005U;
}
static inline u32 fifo_pbdma_status_chan_status_chsw_save_v(void)
{
	return 0x00000006U;
}
static inline u32 fifo_pbdma_status_chan_status_chsw_switch_v(void)
{
	return 0x00000007U;
}
static inline u32 fifo_pbdma_status_next_id_v(u32 r)
{
	return (r >> 16U) & 0xfffU;
}
static inline u32 fifo_pbdma_status_next_id_type_v(u32 r)
{
	return (r >> 28U) & 0x1U;
}
static inline u32 fifo_pbdma_status_next_id_type_chid_v(void)
{
	return 0x00000000U;
}
static inline u32 fifo_pbdma_status_chsw_v(u32 r)
{
	return (r >> 15U) & 0x1U;
}
static inline u32 fifo_pbdma_status_chsw_in_progress_v(void)
{
	return 0x00000001U;
}
static inline u32 fifo_cfg0_r(void)
{
	return 0x00002004U;
}
static inline u32 fifo_cfg0_num_pbdma_v(u32 r)
{
	return (r >> 0U) & 0xffU;
}
static inline u32 fifo_cfg0_pbdma_fault_id_v(u32 r)
{
	return (r >> 16U) & 0xffU;
}
static inline u32 fifo_fb_iface_r(void)
{
	return 0x000026f0U;
}
static inline u32 fifo_fb_iface_control_v(u32 r)
{
	return (r >> 0U) & 0x1U;
}
static inline u32 fifo_fb_iface_control_enable_f(void)
{
	return 0x1U;
}
static inline u32 fifo_fb_iface_status_v(u32 r)
{
	return (r >> 4U) & 0x1U;
}
static inline u32 fifo_fb_iface_status_enabled_f(void)
{
	return 0x10U;
}
#endif
