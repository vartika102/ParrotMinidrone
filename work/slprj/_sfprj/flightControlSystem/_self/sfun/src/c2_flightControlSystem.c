/* Include files */

#include "flightControlSystem_sfun.h"
#include "c2_flightControlSystem.h"
#include <math.h>
#include <string.h>
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "flightControlSystem_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[22] = { "BW3", "BW", "BW4", "centers",
  "H", "theta", "rho", "P", "lines", "angle", "r", "sig", "ang", "nargin",
  "nargout", "u", "data", "angle_", "y", "number", "data1", "angelina" };

static emlrtRTEInfo c2_emlrtRTEI = { 7,/* lineNo */
  2,                                   /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2262"          /* pName */
};

static emlrtRTEInfo c2_b_emlrtRTEI = { 9,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2262"          /* pName */
};

static emlrtRTEInfo c2_c_emlrtRTEI = { 10,/* lineNo */
  33,                                  /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2262"          /* pName */
};

static emlrtRTEInfo c2_d_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2262"          /* pName */
};

static emlrtRTEInfo c2_e_emlrtRTEI = { 10,/* lineNo */
  9,                                   /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2262"          /* pName */
};

static emlrtRTEInfo c2_f_emlrtRTEI = { 9,/* lineNo */
  5,                                   /* colNo */
  "Image Processing System/MATLAB Function",/* fName */
  "#flightControlSystem:2262"          /* pName */
};

static emlrtRTEInfo c2_g_emlrtRTEI = { 153,/* lineNo */
  13,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_h_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_i_emlrtRTEI = { 690,/* lineNo */
  5,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c2_j_emlrtRTEI = { 696,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c2_k_emlrtRTEI = { 697,/* lineNo */
  37,                                  /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c2_l_emlrtRTEI = { 52,/* lineNo */
  5,                                   /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo c2_m_emlrtRTEI = { 697,/* lineNo */
  9,                                   /* colNo */
  "edge",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\edge.m"/* pName */
};

static emlrtRTEInfo c2_n_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_o_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_p_emlrtRTEI = { 27,/* lineNo */
  9,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_q_emlrtRTEI = { 27,/* lineNo */
  5,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_r_emlrtRTEI = { 28,/* lineNo */
  9,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_s_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_t_emlrtRTEI = { 60,/* lineNo */
  16,                                  /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_u_emlrtRTEI = { 60,/* lineNo */
  26,                                  /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_v_emlrtRTEI = { 60,/* lineNo */
  15,                                  /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_w_emlrtRTEI = { 61,/* lineNo */
  16,                                  /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_x_emlrtRTEI = { 61,/* lineNo */
  26,                                  /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_y_emlrtRTEI = { 60,/* lineNo */
  1,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_ab_emlrtRTEI = { 397,/* lineNo */
  11,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_bb_emlrtRTEI = { 65,/* lineNo */
  7,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_cb_emlrtRTEI = { 70,/* lineNo */
  34,                                  /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_db_emlrtRTEI = { 41,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_eb_emlrtRTEI = { 70,/* lineNo */
  40,                                  /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_fb_emlrtRTEI = { 66,/* lineNo */
  7,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_gb_emlrtRTEI = { 41,/* lineNo */
  30,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_hb_emlrtRTEI = { 46,/* lineNo */
  1,                                   /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_ib_emlrtRTEI = { 48,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_jb_emlrtRTEI = { 48,/* lineNo */
  17,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_kb_emlrtRTEI = { 48,/* lineNo */
  5,                                   /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_lb_emlrtRTEI = { 16,/* lineNo */
  1,                                   /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_mb_emlrtRTEI = { 70,/* lineNo */
  1,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_nb_emlrtRTEI = { 33,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_ob_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_pb_emlrtRTEI = { 17,/* lineNo */
  5,                                   /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_qb_emlrtRTEI = { 70,/* lineNo */
  16,                                  /* colNo */
  "bwselect",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwselect.m"/* pName */
};

static emlrtRTEInfo c2_rb_emlrtRTEI = { 16,/* lineNo */
  14,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c2_sb_emlrtRTEI = { 110,/* lineNo */
  17,                                  /* colNo */
  "imfilter",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfilter.m"/* pName */
};

static emlrtRTEInfo c2_tb_emlrtRTEI = { 820,/* lineNo */
  21,                                  /* colNo */
  "imfilter",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfilter.m"/* pName */
};

static emlrtRTEInfo c2_ub_emlrtRTEI = { 147,/* lineNo */
  9,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_vb_emlrtRTEI = { 250,/* lineNo */
  11,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_wb_emlrtRTEI = { 250,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_xb_emlrtRTEI = { 251,/* lineNo */
  11,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_yb_emlrtRTEI = { 251,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_ac_emlrtRTEI = { 252,/* lineNo */
  11,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_bc_emlrtRTEI = { 47,/* lineNo */
  20,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c2_cc_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "round",                             /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elfun\\round.m"/* pName */
};

static emlrtRTEInfo c2_dc_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_ec_emlrtRTEI = { 257,/* lineNo */
  1,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_fc_emlrtRTEI = { 90,/* lineNo */
  40,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_gc_emlrtRTEI = { 94,/* lineNo */
  47,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_hc_emlrtRTEI = { 202,/* lineNo */
  12,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_ic_emlrtRTEI = { 202,/* lineNo */
  25,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_jc_emlrtRTEI = { 30,/* lineNo */
  9,                                   /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_kc_emlrtRTEI = { 1,/* lineNo */
  27,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_lc_emlrtRTEI = { 214,/* lineNo */
  20,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_mc_emlrtRTEI = { 243,/* lineNo */
  18,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_nc_emlrtRTEI = { 238,/* lineNo */
  20,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_oc_emlrtRTEI = { 243,/* lineNo */
  36,                                  /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_pc_emlrtRTEI = { 238,/* lineNo */
  5,                                   /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_qc_emlrtRTEI = { 243,/* lineNo */
  5,                                   /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_rc_emlrtRTEI = { 254,/* lineNo */
  8,                                   /* colNo */
  "imfill",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfill.m"/* pName */
};

static emlrtRTEInfo c2_sc_emlrtRTEI = { 38,/* lineNo */
  2,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c2_tc_emlrtRTEI = { 38,/* lineNo */
  11,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c2_uc_emlrtRTEI = { 46,/* lineNo */
  17,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c2_vc_emlrtRTEI = { 46,/* lineNo */
  1,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c2_wc_emlrtRTEI = { 47,/* lineNo */
  1,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c2_xc_emlrtRTEI = { 48,/* lineNo */
  1,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c2_yc_emlrtRTEI = { 72,/* lineNo */
  30,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c2_ad_emlrtRTEI = { 73,/* lineNo */
  9,                                   /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c2_bd_emlrtRTEI = { 14,/* lineNo */
  56,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c2_cd_emlrtRTEI = { 14,/* lineNo */
  76,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c2_dd_emlrtRTEI = { 14,/* lineNo */
  18,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c2_ed_emlrtRTEI = { 9,/* lineNo */
  5,                                   /* colNo */
  "angle",                             /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elfun\\angle.m"/* pName */
};

static emlrtRTEInfo c2_fd_emlrtRTEI = { 16,/* lineNo */
  20,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c2_gd_emlrtRTEI = { 16,/* lineNo */
  19,                                  /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtRTEInfo c2_hd_emlrtRTEI = { 64,/* lineNo */
  17,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c2_id_emlrtRTEI = { 1,/* lineNo */
  43,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo c2_jd_emlrtRTEI = { 32,/* lineNo */
  35,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c2_kd_emlrtRTEI = { 32,/* lineNo */
  39,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c2_ld_emlrtRTEI = { 32,/* lineNo */
  1,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c2_md_emlrtRTEI = { 76,/* lineNo */
  23,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c2_nd_emlrtRTEI = { 1,/* lineNo */
  39,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c2_od_emlrtRTEI = { 98,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c2_pd_emlrtRTEI = { 98,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo c2_qd_emlrtRTEI = { 77,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c2_rd_emlrtRTEI = { 78,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c2_sd_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c2_td_emlrtRTEI = { 91,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c2_ud_emlrtRTEI = { 92,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c2_vd_emlrtRTEI = { 94,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c2_wd_emlrtRTEI = { 95,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c2_xd_emlrtRTEI = { 120,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c2_yd_emlrtRTEI = { 121,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c2_ae_emlrtRTEI = { 122,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c2_be_emlrtRTEI = { 32,/* lineNo */
  8,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo c2_ce_emlrtRTEI = { 82,/* lineNo */
  13,                                  /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_de_emlrtRTEI = { 95,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_ee_emlrtRTEI = { 528,/* lineNo */
  28,                                  /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_fe_emlrtRTEI = { 528,/* lineNo */
  1,                                   /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_ge_emlrtRTEI = { 129,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_he_emlrtRTEI = { 145,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_ie_emlrtRTEI = { 15,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_je_emlrtRTEI = { 1,/* lineNo */
  29,                                  /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_ke_emlrtRTEI = { 179,/* lineNo */
  36,                                  /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_le_emlrtRTEI = { 225,/* lineNo */
  15,                                  /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_me_emlrtRTEI = { 225,/* lineNo */
  17,                                  /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_ne_emlrtRTEI = { 138,/* lineNo */
  9,                                   /* colNo */
  "im2uint8",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\im2uint8.m"/* pName */
};

static emlrtRTEInfo c2_oe_emlrtRTEI = { 44,/* lineNo */
  13,                                  /* colNo */
  "unique",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pName */
};

static emlrtRTEInfo c2_pe_emlrtRTEI = { 164,/* lineNo */
  50,                                  /* colNo */
  "unique",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pName */
};

static emlrtRTEInfo c2_qe_emlrtRTEI = { 228,/* lineNo */
  7,                                   /* colNo */
  "unique",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pName */
};

static emlrtRTEInfo c2_re_emlrtRTEI = { 44,/* lineNo */
  9,                                   /* colNo */
  "unique",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pName */
};

static emlrtRTEInfo c2_se_emlrtRTEI = { 537,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_te_emlrtRTEI = { 542,/* lineNo */
  16,                                  /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_ue_emlrtRTEI = { 542,/* lineNo */
  36,                                  /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_ve_emlrtRTEI = { 537,/* lineNo */
  18,                                  /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_we_emlrtRTEI = { 534,/* lineNo */
  39,                                  /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_xe_emlrtRTEI = { 618,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_ye_emlrtRTEI = { 667,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_af_emlrtRTEI = { 634,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_bf_emlrtRTEI = { 662,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_cf_emlrtRTEI = { 643,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_df_emlrtRTEI = { 25,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo c2_ef_emlrtRTEI = { 644,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_ff_emlrtRTEI = { 95,/* lineNo */
  20,                                  /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo c2_gf_emlrtRTEI = { 631,/* lineNo */
  9,                                   /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_hf_emlrtRTEI = { 650,/* lineNo */
  24,                                  /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_if_emlrtRTEI = { 650,/* lineNo */
  20,                                  /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo c2_jf_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "abs",                               /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m"/* pName */
};

static emlrtRTEInfo c2_kf_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo c2_lf_emlrtRTEI = { 572,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_mf_emlrtRTEI = { 482,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_nf_emlrtRTEI = { 520,/* lineNo */
  32,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_of_emlrtRTEI = { 1,/* lineNo */
  30,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c2_pf_emlrtRTEI = { 42,/* lineNo */
  21,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c2_qf_emlrtRTEI = { 53,/* lineNo */
  38,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c2_rf_emlrtRTEI = { 48,/* lineNo */
  13,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c2_sf_emlrtRTEI = { 53,/* lineNo */
  58,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c2_tf_emlrtRTEI = { 297,/* lineNo */
  5,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_uf_emlrtRTEI = { 25,/* lineNo */
  13,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_vf_emlrtRTEI = { 53,/* lineNo */
  18,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c2_wf_emlrtRTEI = { 53,/* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c2_xf_emlrtRTEI = { 55,/* lineNo */
  33,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c2_yf_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pName */
};

static emlrtRTEInfo c2_ag_emlrtRTEI = { 55,/* lineNo */
  10,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c2_bg_emlrtRTEI = { 56,/* lineNo */
  27,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c2_cg_emlrtRTEI = { 56,/* lineNo */
  19,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c2_dg_emlrtRTEI = { 56,/* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c2_eg_emlrtRTEI = { 36,/* lineNo */
  1,                                   /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c2_fg_emlrtRTEI = { 53,/* lineNo */
  21,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo c2_gg_emlrtRTEI = { 132,/* lineNo */
  5,                                   /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c2_hg_emlrtRTEI = { 133,/* lineNo */
  5,                                   /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c2_ig_emlrtRTEI = { 134,/* lineNo */
  27,                                  /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c2_jg_emlrtRTEI = { 36,/* lineNo */
  21,                                  /* colNo */
  "medfilt2",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\medfilt2.m"/* pName */
};

static emlrtRTEInfo c2_kg_emlrtRTEI = { 134,/* lineNo */
  43,                                  /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c2_lg_emlrtRTEI = { 153,/* lineNo */
  25,                                  /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c2_mg_emlrtRTEI = { 153,/* lineNo */
  9,                                   /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c2_ng_emlrtRTEI = { 137,/* lineNo */
  5,                                   /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c2_og_emlrtRTEI = { 134,/* lineNo */
  23,                                  /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo c2_pg_emlrtRTEI = { 72,/* lineNo */
  13,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\padarray.m"/* pName */
};

static emlrtRTEInfo c2_qg_emlrtRTEI = { 30,/* lineNo */
  1,                                   /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRTEInfo c2_rg_emlrtRTEI = { 1281,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_sg_emlrtRTEI = { 1826,/* lineNo */
  1,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_tg_emlrtRTEI = { 291,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_ug_emlrtRTEI = { 292,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_vg_emlrtRTEI = { 767,/* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_wg_emlrtRTEI = { 295,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_xg_emlrtRTEI = { 768,/* lineNo */
  41,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_yg_emlrtRTEI = { 1118,/* lineNo */
  57,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_ah_emlrtRTEI = { 30,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_bh_emlrtRTEI = { 1140,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_ch_emlrtRTEI = { 38,/* lineNo */
  26,                                  /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_dh_emlrtRTEI = { 1136,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_eh_emlrtRTEI = { 1141,/* lineNo */
  28,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_fh_emlrtRTEI = { 1119,/* lineNo */
  33,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_gh_emlrtRTEI = { 40,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_hh_emlrtRTEI = { 298,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_ih_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_jh_emlrtRTEI = { 43,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_kh_emlrtRTEI = { 1150,/* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_lh_emlrtRTEI = { 44,/* lineNo */
  15,                                  /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_mh_emlrtRTEI = { 44,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_nh_emlrtRTEI = { 46,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_oh_emlrtRTEI = { 21,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo c2_ph_emlrtRTEI = { 1120,/* lineNo */
  27,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_qh_emlrtRTEI = { 109,/* lineNo */
  9,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c2_rh_emlrtRTEI = { 116,/* lineNo */
  30,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c2_sh_emlrtRTEI = { 770,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_th_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_uh_emlrtRTEI = { 75,/* lineNo */
  2,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_vh_emlrtRTEI = { 1711,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_wh_emlrtRTEI = { 220,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_xh_emlrtRTEI = { 233,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_yh_emlrtRTEI = { 234,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_ai_emlrtRTEI = { 1,/* lineNo */
  23,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_bi_emlrtRTEI = { 104,/* lineNo */
  1,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c2_ci_emlrtRTEI = { 768,/* lineNo */
  17,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo c2_di_emlrtRTEI = { 9,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_ei_emlrtRTEI = { 1,/* lineNo */
  15,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_fi_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c2_gi_emlrtRTEI = { 19,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_hi_emlrtRTEI = { 41,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_ii_emlrtRTEI = { 56,/* lineNo */
  46,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_ji_emlrtRTEI = { 56,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_ki_emlrtRTEI = { 75,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_li_emlrtRTEI = { 76,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_mi_emlrtRTEI = { 25,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_ni_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo c2_oi_emlrtRTEI = { 51,/* lineNo */
  48,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c2_pi_emlrtRTEI = { 51,/* lineNo */
  57,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c2_qi_emlrtRTEI = { 51,/* lineNo */
  64,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c2_ri_emlrtRTEI = { 181,/* lineNo */
  5,                                   /* colNo */
  "houghpeaks",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghpeaks.m"/* pName */
};

static emlrtRTEInfo c2_si_emlrtRTEI = { 11,/* lineNo */
  40,                                  /* colNo */
  "validatepositive",                  /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatepositive.m"/* pName */
};

static emlrtRTEInfo c2_ti_emlrtRTEI = { 74,/* lineNo */
  15,                                  /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_ui_emlrtRTEI = { 76,/* lineNo */
  17,                                  /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_vi_emlrtRTEI = { 108,/* lineNo */
  5,                                   /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_wi_emlrtRTEI = { 137,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_xi_emlrtRTEI = { 115,/* lineNo */
  15,                                  /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_yi_emlrtRTEI = { 286,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_aj_emlrtRTEI = { 120,/* lineNo */
  9,                                   /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_bj_emlrtRTEI = { 121,/* lineNo */
  9,                                   /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_cj_emlrtRTEI = { 128,/* lineNo */
  27,                                  /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_dj_emlrtRTEI = { 128,/* lineNo */
  13,                                  /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_ej_emlrtRTEI = { 129,/* lineNo */
  27,                                  /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_fj_emlrtRTEI = { 129,/* lineNo */
  13,                                  /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_gj_emlrtRTEI = { 130,/* lineNo */
  27,                                  /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_hj_emlrtRTEI = { 130,/* lineNo */
  13,                                  /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_ij_emlrtRTEI = { 131,/* lineNo */
  27,                                  /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_jj_emlrtRTEI = { 131,/* lineNo */
  13,                                  /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_kj_emlrtRTEI = { 76,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_lj_emlrtRTEI = { 84,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_mj_emlrtRTEI = { 87,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_nj_emlrtRTEI = { 90,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_oj_emlrtRTEI = { 93,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_pj_emlrtRTEI = { 115,/* lineNo */
  5,                                   /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_qj_emlrtRTEI = { 1,/* lineNo */
  18,                                  /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_rj_emlrtRTEI = { 108,/* lineNo */
  18,                                  /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_sj_emlrtRTEI = { 213,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_tj_emlrtRTEI = { 203,/* lineNo */
  23,                                  /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_uj_emlrtRTEI = { 302,/* lineNo */
  1,                                   /* colNo */
  "houghlines",                        /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\images\\images\\eml\\houghlines.m"/* pName */
};

static emlrtRTEInfo c2_vj_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sortrows",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m"/* pName */
};

static emlrtRTEInfo c2_wj_emlrtRTEI = { 12,/* lineNo */
  21,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_xj_emlrtRTEI = { 12,/* lineNo */
  23,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_yj_emlrtRTEI = { 166,/* lineNo */
  32,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_ak_emlrtRTEI = { 168,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_bk_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo c2_ck_emlrtRTEI = { 56,/* lineNo */
  5,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_dk_emlrtRTEI = { 385,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_ek_emlrtRTEI = { 308,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_fk_emlrtRTEI = { 386,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_gk_emlrtRTEI = { 387,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_hk_emlrtRTEI = { 388,/* lineNo */
  1,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_ik_emlrtRTEI = { 105,/* lineNo */
  40,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_jk_emlrtRTEI = { 308,/* lineNo */
  14,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_kk_emlrtRTEI = { 308,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_lk_emlrtRTEI = { 61,/* lineNo */
  5,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_mk_emlrtRTEI = { 27,/* lineNo */
  1,                                   /* colNo */
  "sortrows",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m"/* pName */
};

static emlrtRTEInfo c2_nk_emlrtRTEI = { 52,/* lineNo */
  9,                                   /* colNo */
  "mergesort",                         /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\mergesort.m"/* pName */
};

static emlrtRTEInfo c2_ok_emlrtRTEI = { 86,/* lineNo */
  15,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo c2_pk_emlrtRTEI = { 1,/* lineNo */
  34,                                  /* colNo */
  "mergesort",                         /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\mergesort.m"/* pName */
};

static emlrtRTEInfo c2_qk_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "sortrows",                          /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\lib\\matlab\\datafun\\sortrows.m"/* pName */
};

static emlrtRTEInfo c2_rk_emlrtRTEI = { 52,/* lineNo */
  1,                                   /* colNo */
  "mergesort",                         /* fName */
  "C:\\Program Files\\Polyspace\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\mergesort.m"/* pName */
};

static const char_T c2_cv0[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
  'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'F',
  'i', 'n', 'i', 't', 'e' };

static const char_T c2_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i',
  'l', 't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
  'a', 'i', 'l', 'e', 'd' };

static const char_T c2_cv2[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
  'b', '2', 'i', 'n', 'd', ':', 'I', 'n', 'd', 'e', 'x', 'O', 'u', 't', 'O', 'f',
  'R', 'a', 'n', 'g', 'e' };

static const char_T c2_cv3[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
  'b', '2', 'i', 'n', 'd', ':', 'S', 'u', 'b', 's', 'c', 'r', 'i', 'p', 't', 'V',
  'e', 'c', 't', 'o', 'r', 'S', 'i', 'z', 'e' };

static const real_T c2_dv0[13] = { 3.4813359214923066E-5, 0.00054457256285105169,
  0.0051667606200595231, 0.029732654490475546, 0.10377716120747749,
  0.219696252000246, 0.28209557151935094, 0.219696252000246, 0.10377716120747749,
  0.029732654490475546, 0.0051667606200595231, 0.00054457256285105169,
  3.4813359214923066E-5 };

static const char_T c2_cv4[25] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
  'b', 's', 'd', 'e', 'l', 'd', 'i', 'm', 'm', 'i', 's', 'm', 'a', 't', 'c', 'h'
};

static const char_T c2_cv5[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
  'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'P',
  'o', 's', 'i', 't', 'i', 'v', 'e' };

static const char_T c2_cv6[47] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
  'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I',
  'n', 't', 'e', 'g', 'e', 'r' };

static const char_T c2_cv7[51] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'a', 'l', 'l', '_', 'o', 'r', '_',
  'a', 'n', 'y', '_', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm',
  'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

static const char_T c2_cv8[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
  'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'N',
  'o', 'n', 'N', 'a', 'N' };

static const char_T c2_cv9[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
  'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
  'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

static const char_T c2_cv10[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
  'a', 'x', 's', 'i', 'z', 'e' };

static const char_T c2_cv11[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o',
  'u', 'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
  'd', 'F', 'i', 'n', 'i', 't', 'e' };

static const char_T c2_cv12[33] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o',
  'u', 'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
  'd', 'I', 'n', 't', 'e', 'g', 'e', 'r' };

/* Function Declarations */
static void initialize_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static void enable_c2_flightControlSystem(SFc2_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance, const mxArray *c2_st);
static void finalize_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static void c2_chartstep_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static void initSimStructsc2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_e_u, const emlrtMsgIdentifier *c2_parentId,
  boolean_T c2_c_y[19200]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid,
  c2_emxArray_real_T *c2_inData);
static void c2_b_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_e_u, const emlrtMsgIdentifier *c2_parentId,
  c2_emxArray_real_T *c2_c_y);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, c2_emxArray_real_T *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_e_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_c_y[71820]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid,
  c2_emxArray_real_T *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_e_u, const emlrtMsgIdentifier *c2_parentId,
  c2_emxArray_real_T *c2_c_y);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, c2_emxArray_real_T *c2_outData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid,
  c2_emxArray_skoeQIuVNKJRHNtBIlOCZh *c2_inData);
static void c2_e_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_e_u, const emlrtMsgIdentifier *c2_parentId,
  c2_emxArray_skoeQIuVNKJRHNtBIlOCZh *c2_c_y);
static void c2_f_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_e_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_c_y[2]);
static real_T c2_g_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_e_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName,
  c2_emxArray_skoeQIuVNKJRHNtBIlOCZh *c2_outData);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_h_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_angle, const char_T *c2_identifier);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_imhist(SFc2_flightControlSystemInstanceStruct *chartInstance,
                      uint8_T c2_h_varargin_1[19200], real_T c2_yout[256]);
static void c2_validateattributes(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real_T c2_l_a[256]);
static boolean_T c2_isfinite(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real_T c2_d_x);
static void c2_edge(SFc2_flightControlSystemInstanceStruct *chartInstance,
                    boolean_T c2_h_varargin_1[19200], boolean_T c2_varargout_1
                    [19200]);
static void c2_imfilter(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_h_varargin_1[19200], real32_T c2_b[19200]);
static void c2_padImage(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_a_tmp[19200], real_T c2_boundary_pos, int8_T c2_boundaryEnum,
  real_T c2_boundaryStr_pos, real32_T c2_l_a[21120]);
static void c2_b_imfilter(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_h_varargin_1[19200], real_T c2_varargin_2[13], real32_T c2_b[19200]);
static void c2_b_padImage(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_a_tmp[19200], real_T c2_boundary_pos, int8_T c2_boundaryEnum,
  real_T c2_boundaryStr_pos, real32_T c2_l_a[20640]);
static void c2_c_imfilter(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_h_varargin_1[19200], real32_T c2_b[19200]);
static void c2_d_imfilter(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_h_varargin_1[19200], real_T c2_varargin_2[13], real32_T c2_b[19200]);
static void c2_hypot(SFc2_flightControlSystemInstanceStruct *chartInstance,
                     real32_T c2_d_x[19200], real32_T c2_c_y[19200], real32_T
                     c2_r[19200]);
static void c2_check_forloop_overflow_error
  (SFc2_flightControlSystemInstanceStruct *chartInstance, boolean_T c2_overflow);
static void c2_warning(SFc2_flightControlSystemInstanceStruct *chartInstance);
static void c2_eml_find(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_d_x[19200], c2_emxArray_int32_T *c2_i, c2_emxArray_int32_T *c2_j);
static void c2_indexShapeCheck(SFc2_flightControlSystemInstanceStruct
  *chartInstance, int32_T c2_matrixSize, int32_T c2_indexSize[2]);
static void c2_round(SFc2_flightControlSystemInstanceStruct *chartInstance,
                     c2_emxArray_real_T *c2_d_x, c2_emxArray_real_T *c2_e_x);
static void c2_b_warning(SFc2_flightControlSystemInstanceStruct *chartInstance);
static void c2_nullAssignment(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_d_x, c2_emxArray_int32_T *c2_b_idx,
  c2_emxArray_real_T *c2_e_x);
static void c2_validate_inputs(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_d_x, c2_emxArray_int32_T *c2_b_idx);
static void c2_make_bitarray(SFc2_flightControlSystemInstanceStruct
  *chartInstance, int32_T c2_n, c2_emxArray_int32_T *c2_b_idx, boolean_T
  c2_b_data[], int32_T c2_b_size[2]);
static int32_T c2_num_true(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_b_data[], int32_T c2_b_size[2]);
static boolean_T c2_allinrange(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_d_x, real_T c2_lo, int32_T c2_hi);
static void c2_imfill(SFc2_flightControlSystemInstanceStruct *chartInstance,
                      boolean_T c2_h_varargin_1[19200], c2_emxArray_real_T
                      *c2_varargin_2, boolean_T c2_I2[19200]);
static boolean_T c2_isequal(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_h_varargin_1, real_T c2_varargin_2);
static void c2_checkLocations(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_locations, c2_emxArray_real_T
  *c2_locationsVar);
static void c2_b_validateattributes(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_l_a);
static boolean_T c2_any(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_x_data[], int32_T c2_x_size[1]);
static void c2_c_warning(SFc2_flightControlSystemInstanceStruct *chartInstance);
static void c2_b_nullAssignment(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_d_x, int32_T c2_b_idx,
  c2_emxArray_real_T *c2_e_x);
static boolean_T c2_b_isequal(SFc2_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c2_h_varargin_1[19200], boolean_T c2_varargin_2
  [19200]);
static boolean_T c2_all(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real_T c2_l_a[2]);
static boolean_T c2_b_all(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_d_x[19200]);
static void c2_c_padImage(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_a_tmp[19200], real_T c2_boundary_pos, int8_T c2_boundaryEnum,
  real_T c2_boundaryStr_pos, real32_T c2_l_a[20336]);
static void c2_e_imfilter(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_h_varargin_1[19200], real32_T c2_b[19200]);
static void c2_d_padImage(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_a_tmp[19200], real_T c2_boundary_pos, int8_T c2_boundaryEnum,
  real_T c2_boundaryStr_pos, real32_T c2_l_a[19764]);
static void c2_f_imfilter(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_h_varargin_1[19200], real32_T c2_b[19200]);
static boolean_T c2_b_isfinite(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real32_T c2_d_x);
static void c2_imfindcircles(SFc2_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c2_h_varargin_1[19200], c2_emxArray_real_T
  *c2_centers, c2_emxArray_real_T *c2_r_estimated, c2_emxArray_real_T *c2_metric);
static void c2_chaccum(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_h_varargin_1[19200], creal_T c2_c_accumMatrix[19200], real32_T
  c2_b_gradientImg[19200]);
static real32_T c2_multithresh(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real32_T c2_h_varargin_1[19200]);
static void c2_getpdf(SFc2_flightControlSystemInstanceStruct *chartInstance,
                      real32_T c2_g_A[19200], real_T c2_p[256], real32_T
                      *c2_minA, real32_T *c2_maxA, boolean_T *c2_emptyp);
static void c2_im2uint8(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_img, uint8_T c2_u_data[], int32_T c2_u_size[1]);
static void c2_b_imhist(SFc2_flightControlSystemInstanceStruct *chartInstance,
  uint8_T c2_varargin_1_data[], int32_T c2_varargin_1_size[1], real_T c2_yout
  [256]);
static real_T c2_sum(SFc2_flightControlSystemInstanceStruct *chartInstance,
                     real_T c2_d_x[256]);
static void c2_d_warning(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real_T c2_h_varargin_1);
static void c2_calcFullObjCriteriaMatrix(SFc2_flightControlSystemInstanceStruct *
  chartInstance, real_T c2_omega[256], real_T c2_mu[256], real_T c2_mu_t, real_T
  c2_sigma_b_squared[256]);
static void c2_sortIdx(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_d_x[19200], int32_T c2_b_idx[19200]);
static boolean_T c2_sortLE(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_v[19200], int32_T c2_idx1, int32_T c2_idx2);
static void c2_count_nonfinites(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_b, int32_T c2_nb, int32_T *c2_nMInf,
  int32_T *c2_nFinite, int32_T *c2_nPInf, int32_T *c2_nNaN);
static void c2_checkForDegenerateInput(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real32_T c2_g_A[19200], real_T c2_N, boolean_T
  *c2_isDegenerate, c2_emxArray_real32_T *c2_uniqueVals);
static void c2_c_nullAssignment(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_d_x, boolean_T c2_idx_data[], int32_T
  c2_idx_size[2], c2_emxArray_real32_T *c2_e_x);
static void c2_e_warning(SFc2_flightControlSystemInstanceStruct *chartInstance);
static void c2_getDegenerateThresholds(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_uniqueVals, c2_emxArray_real32_T
  *c2_thresh);
static void c2_abs(SFc2_flightControlSystemInstanceStruct *chartInstance,
                   c2_emxArray_real_T *c2_d_x, c2_emxArray_real_T *c2_c_y);
static real_T c2_eps(SFc2_flightControlSystemInstanceStruct *chartInstance,
                     real_T c2_d_x);
static void c2_sort(SFc2_flightControlSystemInstanceStruct *chartInstance,
                    c2_emxArray_real32_T *c2_d_x, c2_emxArray_real32_T *c2_e_x);
static void c2_merge_pow2_block(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T *c2_d_x,
  int32_T c2_offset, c2_emxArray_int32_T *c2_c_idx, c2_emxArray_real32_T *c2_e_x);
static void c2_merge_block(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T *c2_d_x, int32_T c2_offset,
  int32_T c2_n, int32_T c2_preSortLevel, c2_emxArray_int32_T *c2_b_iwork,
  c2_emxArray_real32_T *c2_xwork, c2_emxArray_int32_T *c2_c_idx,
  c2_emxArray_real32_T *c2_e_x, c2_emxArray_int32_T *c2_c_iwork,
  c2_emxArray_real32_T *c2_b_xwork);
static void c2_merge(SFc2_flightControlSystemInstanceStruct *chartInstance,
                     c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T *c2_d_x,
                     int32_T c2_offset, int32_T c2_np, int32_T c2_nq,
                     c2_emxArray_int32_T *c2_b_iwork, c2_emxArray_real32_T
                     *c2_xwork, c2_emxArray_int32_T *c2_c_idx,
                     c2_emxArray_real32_T *c2_e_x, c2_emxArray_int32_T
                     *c2_c_iwork, c2_emxArray_real32_T *c2_b_xwork);
static void c2_toLogicalCheck(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real_T c2_d_x[25]);
static void c2_chcenters(SFc2_flightControlSystemInstanceStruct *chartInstance,
  creal_T c2_h_varargin_1[19200], c2_emxArray_real_T *c2_centers,
  c2_emxArray_real_T *c2_metric);
static void c2_medfilt2(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real_T c2_h_varargin_1[19200], real_T c2_b[19200]);
static void c2_padarray(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real_T c2_h_varargin_1[19200], real_T c2_varargin_2[2], c2_emxArray_real_T
  *c2_b);
static void c2_regionprops(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_h_varargin_1[19200], real_T c2_varargin_2[19200],
  c2_emxArray_sBO2RC5RVZVTbundPSRqHn *c2_outstats);
static void c2_bwconncomp(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_h_varargin_1[19200], c2_scIvRXQeSh8yxCxSmtD63bE *c2_CC);
static void c2_assertValidSizeArg(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real_T c2_h_varargin_1);
static boolean_T c2_b_allinrange(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_d_x, real_T c2_lo, int32_T c2_hi);
static real_T c2_b_sum(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_real_T *c2_d_x);
static void c2_b_sort(SFc2_flightControlSystemInstanceStruct *chartInstance,
                      c2_emxArray_real_T *c2_d_x, c2_emxArray_real_T *c2_e_x,
                      c2_emxArray_int32_T *c2_b_idx);
static void c2_b_merge_block(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real_T *c2_d_x,
  int32_T c2_offset, int32_T c2_n, int32_T c2_preSortLevel, c2_emxArray_int32_T *
  c2_b_iwork, c2_emxArray_real_T *c2_xwork, c2_emxArray_int32_T *c2_c_idx,
  c2_emxArray_real_T *c2_e_x, c2_emxArray_int32_T *c2_c_iwork,
  c2_emxArray_real_T *c2_b_xwork);
static void c2_b_merge(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real_T *c2_d_x, int32_T c2_offset,
  int32_T c2_np, int32_T c2_nq, c2_emxArray_int32_T *c2_b_iwork,
  c2_emxArray_real_T *c2_xwork, c2_emxArray_int32_T *c2_c_idx,
  c2_emxArray_real_T *c2_e_x, c2_emxArray_int32_T *c2_c_iwork,
  c2_emxArray_real_T *c2_b_xwork);
static boolean_T c2_c_all(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_boolean_T *c2_d_x);
static void c2_houghpeaks(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real_T c2_h_varargin_1[71820], real_T c2_varargin_4, c2_emxArray_real_T
  *c2_peaks);
static void c2_c_validateattributes(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real_T c2_l_a[71820]);
static void c2_diff(SFc2_flightControlSystemInstanceStruct *chartInstance,
                    real_T c2_d_x[179], real_T c2_c_y[178]);
static void c2_houghlines(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_h_varargin_1[19200], c2_emxArray_real_T *c2_varargin_4,
  c2_emxArray_skoeQIuVNKJRHNtBIlOCZh *c2_lines);
static void c2_sortrows(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_int32_T *c2_c_y, real_T c2_h_varargin_1[2], c2_emxArray_int32_T
  *c2_d_y);
static boolean_T c2_b_sortLE(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_v, int32_T c2_dir[2], int32_T c2_idx1,
  int32_T c2_idx2);
static const mxArray *c2_emlrt_marshallOut
  (SFc2_flightControlSystemInstanceStruct *chartInstance, const char_T c2_e_u[30]);
static const mxArray *c2_b_emlrt_marshallOut
  (SFc2_flightControlSystemInstanceStruct *chartInstance, const char_T c2_e_u[36]);
static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_i_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_e_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_j_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_flightControlSystem, const
  char_T *c2_identifier);
static uint8_T c2_k_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_e_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_round(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_real_T *c2_d_x);
static void c2_d_nullAssignment(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_d_x, c2_emxArray_int32_T *c2_b_idx);
static void c2_e_nullAssignment(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_d_x, int32_T c2_b_idx);
static void c2_f_nullAssignment(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_d_x, boolean_T c2_idx_data[], int32_T
  c2_idx_size[2]);
static void c2_c_sort(SFc2_flightControlSystemInstanceStruct *chartInstance,
                      c2_emxArray_real32_T *c2_d_x);
static void c2_b_merge_pow2_block(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T *c2_d_x,
  int32_T c2_offset);
static void c2_c_merge_block(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T *c2_d_x,
  int32_T c2_offset, int32_T c2_n, int32_T c2_preSortLevel, c2_emxArray_int32_T *
  c2_b_iwork, c2_emxArray_real32_T *c2_xwork);
static void c2_c_merge(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T *c2_d_x, int32_T c2_offset,
  int32_T c2_np, int32_T c2_nq, c2_emxArray_int32_T *c2_b_iwork,
  c2_emxArray_real32_T *c2_xwork);
static void c2_d_sort(SFc2_flightControlSystemInstanceStruct *chartInstance,
                      c2_emxArray_real_T *c2_d_x, c2_emxArray_int32_T *c2_b_idx);
static void c2_d_merge_block(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real_T *c2_d_x,
  int32_T c2_offset, int32_T c2_n, int32_T c2_preSortLevel, c2_emxArray_int32_T *
  c2_b_iwork, c2_emxArray_real_T *c2_xwork);
static void c2_d_merge(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real_T *c2_d_x, int32_T c2_offset,
  int32_T c2_np, int32_T c2_nq, c2_emxArray_int32_T *c2_b_iwork,
  c2_emxArray_real_T *c2_xwork);
static void c2_b_sortrows(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_int32_T *c2_c_y, real_T c2_h_varargin_1[2]);
static void c2_emxEnsureCapacity_real_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_skoeQIuVNKJRH
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_skoeQIuVNKJRHNtBIlOCZh *c2_emxArray, int32_T c2_oldNumel, const
   emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_real_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_skoeQIuVNKJRHNtBIlOCZhD
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_skoeQIuVNKJRHNtBIlOCZh **c2_pEmxArray, int32_T c2_numDimensions,
   const emlrtRTEInfo *c2_srcLocation);
static void c2_emxFree_real_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T **c2_pEmxArray);
static void c2_emxFree_skoeQIuVNKJRHNtBIlOCZhD
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_skoeQIuVNKJRHNtBIlOCZh **c2_pEmxArray);
static void c2_emxEnsureCapacity_real_T1(SFc2_flightControlSystemInstanceStruct *
  chartInstance, c2_emxArray_real_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_int32_T(SFc2_flightControlSystemInstanceStruct *
  chartInstance, c2_emxArray_int32_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_int32_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_real_T1(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxFree_int32_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T **c2_pEmxArray);
static void c2_emxEnsureCapacity_boolean_T
  (SFc2_flightControlSystemInstanceStruct *chartInstance, c2_emxArray_boolean_T *
   c2_emxArray, int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_boolean_T1
  (SFc2_flightControlSystemInstanceStruct *chartInstance, c2_emxArray_boolean_T *
   c2_emxArray, int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_creal_T(SFc2_flightControlSystemInstanceStruct *
  chartInstance, c2_emxArray_creal_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_boolean_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_boolean_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_creal_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_creal_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_boolean_T1(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_boolean_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxFree_boolean_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_boolean_T **c2_pEmxArray);
static void c2_emxFree_creal_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_creal_T **c2_pEmxArray);
static void c2_emxEnsureCapacity_real32_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_creal_T1(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_creal_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_real32_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real32_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_creal_T1(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_creal_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxFree_real32_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real32_T **c2_pEmxArray);
static void c2_emxEnsureCapacity_real32_T1
  (SFc2_flightControlSystemInstanceStruct *chartInstance, c2_emxArray_real32_T
   *c2_emxArray, int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_real32_T1(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real32_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_int32_T1(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_sBO2RC5RVZVTbundPSRqHnH
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_sBO2RC5RVZVTbundPSRqHn **c2_pEmxArray, int32_T c2_numDimensions,
   const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_int32_T1(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation);
static void c2_emxFree_sBO2RC5RVZVTbundPSRqHnH
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_sBO2RC5RVZVTbundPSRqHn **c2_pEmxArray);
static void c2_emxEnsureCapacity_sBO2RC5RVZVTb
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_sBO2RC5RVZVTbundPSRqHn *c2_emxArray, int32_T c2_oldNumel, const
   emlrtRTEInfo *c2_srcLocation);
static void c2_emxFreeStruct_s9uuw2Xu7QLvohu1q
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_s9uuw2Xu7QLvohu1q5iD2hG *c2_pStruct);
static void c2_emxTrim_s9uuw2Xu7QLvohu1q5iD2hG
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c2_emxArray, int32_T c2_fromIndex,
   int32_T c2_toIndex);
static void c2_emxInitStruct_s9uuw2Xu7QLvohu1q
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_s9uuw2Xu7QLvohu1q5iD2hG *c2_pStruct, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxExpand_s9uuw2Xu7QLvohu1q5iD2
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c2_emxArray, int32_T c2_fromIndex,
   int32_T c2_toIndex, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxEnsureCapacity_s9uuw2Xu7QLvo
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c2_emxArray, int32_T c2_oldNumel, const
   emlrtRTEInfo *c2_srcLocation);
static void c2_emxCopyStruct_s9uuw2Xu7QLvohu1q
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_s9uuw2Xu7QLvohu1q5iD2hG *c2_dst, const c2_s9uuw2Xu7QLvohu1q5iD2hG *c2_src,
   const emlrtRTEInfo *c2_srcLocation);
static void c2_emxCopyMatrix_real_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real_T c2_dst[2], const real_T c2_src[2], const emlrtRTEInfo
  *c2_srcLocation);
static void c2_emxCopyMatrix_real_T1(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real_T c2_dst[4], const real_T c2_src[4], const emlrtRTEInfo
  *c2_srcLocation);
static void c2_emxCopy_boolean_T_0x0(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_boolean_T_0x0 *c2_dst, const
  c2_emxArray_boolean_T_0x0 *c2_src, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxCopyMatrix_real_T2(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real_T c2_dst[16], const real_T c2_src[16], const emlrtRTEInfo
  *c2_srcLocation);
static void c2_emxCopy_real_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T **c2_dst, c2_emxArray_real_T * const
  *c2_src, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxCopy_real_T1(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T **c2_dst, c2_emxArray_real_T * const
  *c2_src, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxCopy_real_T_1x0(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T_1x0 *c2_dst, const c2_emxArray_real_T_1x0
  *c2_src, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInitStruct_scIvRXQeSh8yxCxSm
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_scIvRXQeSh8yxCxSmtD63bE *c2_pStruct, const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInit_s9uuw2Xu7QLvohu1q5iD2hG
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_s9uuw2Xu7QLvohu1q5iD2h **c2_pEmxArray, int32_T c2_numDimensions,
   const emlrtRTEInfo *c2_srcLocation);
static void c2_emxInitMatrix_cell_wrap_49(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_cell_wrap_49 c2_pMatrix[2], const emlrtRTEInfo
  *c2_srcLocation);
static void c2_emxInitStruct_cell_wrap_49(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_cell_wrap_49 *c2_pStruct, const emlrtRTEInfo
  *c2_srcLocation);
static void c2_emxFreeStruct_scIvRXQeSh8yxCxSm
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_scIvRXQeSh8yxCxSmtD63bE *c2_pStruct);
static void c2_emxFree_s9uuw2Xu7QLvohu1q5iD2hG
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_s9uuw2Xu7QLvohu1q5iD2h **c2_pEmxArray);
static void c2_emxFreeMatrix_cell_wrap_49(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_cell_wrap_49 c2_pMatrix[2]);
static void c2_emxFreeStruct_cell_wrap_49(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_cell_wrap_49 *c2_pStruct);
static int32_T c2_div_nzp_s32(SFc2_flightControlSystemInstanceStruct
  *chartInstance, int32_T c2_numerator, int32_T c2_denominator, int32_T
  c2_EMLOvCount_src_loc, uint32_T c2_ssid_src_loc, int32_T c2_offset_src_loc,
  int32_T c2_length_src_loc);
static void init_dsm_address_info(SFc2_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtLicenseCheckR2012b(chartInstance->c2_fEmlrtCtx, "Image_Toolbox", 2);
  setLegacyDebuggerFlag(chartInstance->S, true);
  setDebuggerFlag(chartInstance->S, true);
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_flightControlSystem(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  sim_mode_is_external(chartInstance->S);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_flightControlSystem = 0U;
}

static void initialize_params_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_flightControlSystem(SFc2_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void ext_mode_exec_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_c_y = NULL;
  real_T c2_hoistedGlobal;
  const mxArray *c2_d_y = NULL;
  real_T c2_b_hoistedGlobal;
  const mxArray *c2_e_y = NULL;
  real_T c2_c_hoistedGlobal;
  const mxArray *c2_f_y = NULL;
  real_T c2_d_hoistedGlobal;
  const mxArray *c2_g_y = NULL;
  uint8_T c2_e_hoistedGlobal;
  const mxArray *c2_h_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_createcellmatrix(5, 1), false);
  c2_hoistedGlobal = *chartInstance->c2_angelina;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c2_c_y, 0, c2_d_y);
  c2_b_hoistedGlobal = *chartInstance->c2_data1;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_b_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_c_y, 1, c2_e_y);
  c2_c_hoistedGlobal = *chartInstance->c2_number;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_c_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_c_y, 2, c2_f_y);
  c2_d_hoistedGlobal = *chartInstance->c2_b_y;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_d_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_c_y, 3, c2_g_y);
  c2_e_hoistedGlobal = chartInstance->c2_is_active_c2_flightControlSystem;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_e_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_c_y, 4, c2_h_y);
  sf_mex_assign(&c2_st, c2_c_y, false);
  return c2_st;
}

static void set_sim_state_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_e_u;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_e_u = sf_mex_dup(c2_st);
  *chartInstance->c2_angelina = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_e_u, 0)), "angelina");
  *chartInstance->c2_data1 = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_e_u, 1)), "data1");
  *chartInstance->c2_number = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_e_u, 2)), "number");
  *chartInstance->c2_b_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_e_u, 3)), "y");
  chartInstance->c2_is_active_c2_flightControlSystem = c2_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_e_u, 4)),
     "is_active_c2_flightControlSystem");
  sf_mex_destroy(&c2_e_u);
  c2_update_debugger_state_c2_flightControlSystem(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c2_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c2_covrtInstance);
}

static void sf_gateway_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  int32_T c2_i0;
  int32_T c2_c_i1;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_angle_, 2U);
  covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 2U,
                    *chartInstance->c2_angle_);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_data, 1U);
  covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 1U, *chartInstance->c2_data);
  for (c2_i0 = 0; c2_i0 < 19200; c2_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_d_u)[c2_i0], 0U);
  }

  for (c2_c_i1 = 0; c2_c_i1 < 19200; c2_c_i1++) {
    covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 0U,
                      (*chartInstance->c2_d_u)[c2_c_i1]);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_flightControlSystem(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_b_y, 3U);
  covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 3U, *chartInstance->c2_b_y);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_number, 4U);
  covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 4U,
                    *chartInstance->c2_number);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_data1, 5U);
  covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 5U,
                    *chartInstance->c2_data1);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_angelina, 6U);
  covrtSigUpdateFcn(chartInstance->c2_covrtInstance, 6U,
                    *chartInstance->c2_angelina);
}

static void mdl_start_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  static const uint32_T c2_decisionTxtStartIdx = 0U;
  static const uint32_T c2_decisionTxtEndIdx = 0U;
  static const int32_T c2_condTxtStartIdx[2] = { 494, 527 };

  static const int32_T c2_condTxtEndIdx[2] = { 521, 554 };

  static const int32_T c2_postfixPredicateTree[3] = { 0, 1, -2 };

  static const int32_T c2_b_condTxtStartIdx[2] = { 1018, 1031 };

  static const int32_T c2_b_condTxtEndIdx[2] = { 1027, 1037 };

  static const int32_T c2_b_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c2_c_condTxtStartIdx[2] = { 1070, 1083 };

  static const int32_T c2_c_condTxtEndIdx[2] = { 1079, 1090 };

  static const int32_T c2_c_postfixPredicateTree[3] = { 0, 1, -3 };

  chartInstance->c2_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c2_covrtInstance, 1U, 0U, 1U,
    39U);
  covrtChartInitFcn(chartInstance->c2_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c2_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c2_decisionTxtStartIdx, &c2_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c2_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c2_covrtInstance, "", 4U, 0U, 1U, 0U, 8U, 0U,
                  0U, 0U, 1U, 0U, 6U, 3U);
  covrtEmlFcnInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 1179);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U, 408, 429, 962,
                    1014);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 1U, 490, 555, 945,
                    948);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 2U, 568, 630, 696,
                    769);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 3U, 820, 832, -1,
                    909);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 4U, 971, 983, -1,
                    1010);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 5U, 1015, 1037,
                    1063, 1090);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 6U, 1063, 1090, -1,
                    1090);
  covrtEmlIfInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 7U, 1120, 1143, -1,
                    1167);
  covrtEmlForInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U, 468, 482, 948);
  covrtEmlMCDCInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U, 493, 555, 2U,
                      0U, c2_condTxtStartIdx, c2_condTxtEndIdx, 3U,
                      c2_postfixPredicateTree);
  covrtEmlMCDCInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 1U, 1018, 1037,
                      2U, 2U, c2_b_condTxtStartIdx, c2_b_condTxtEndIdx, 3U,
                      c2_b_postfixPredicateTree);
  covrtEmlMCDCInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 2U, 1070, 1090,
                      2U, 4U, c2_c_condTxtStartIdx, c2_c_condTxtEndIdx, 3U,
                      c2_c_postfixPredicateTree);
  covrtEmlRelationalInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 0U, 411,
    429, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 1U, 494,
    521, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 2U, 527,
    554, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 3U, 571,
    630, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 4U, 823,
    832, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 5U, 974,
    983, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 6U, 1018,
    1027, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 7U, 1031,
    1037, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 8U, 1070,
    1079, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 9U, 1083,
    1090, -1, 0U);
  covrtEmlRelationalInitFcn(chartInstance->c2_covrtInstance, 4U, 0U, 10U, 1123,
    1143, -1, 0U);
}

static void c2_chartstep_c2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  c2_emxArray_real_T *c2_centers;
  c2_emxArray_real_T *c2_P;
  c2_emxArray_skoeQIuVNKJRHNtBIlOCZh *c2_lines;
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  int32_T c2_c_i2;
  real_T c2_b_data;
  real_T c2_b_angle_;
  uint32_T c2_debug_family_var_map[22];
  real_T c2_theta[180];
  real_T c2_rho[399];
  real_T c2_angle;
  real_T c2_r;
  real_T c2_sig;
  real_T c2_ang;
  real_T c2_nargin = 3.0;
  real_T c2_nargout = 4.0;
  real_T c2_c_y;
  real_T c2_b_number;
  real_T c2_b_data1;
  real_T c2_b_angelina;
  int32_T c2_i3;
  real_T c2_sigma_b_squared[256];
  int32_T c2_i4;
  real_T c2_b_sigma_b_squared[256];
  real_T c2_num_elems;
  int32_T c2_k;
  real_T c2_omega[256];
  real_T c2_b_k;
  real_T c2_mu[256];
  int32_T c2_c_k;
  real_T c2_mu_t;
  real_T c2_maxval;
  real_T c2_p;
  int32_T c2_d_k;
  boolean_T c2_isfinite_maxval;
  real_T c2_l_a;
  real_T c2_t;
  real_T c2_b_idx;
  real_T c2_m_a;
  real_T c2_num_maxval;
  real_T c2_n_a;
  real_T c2_T;
  int32_T c2_e_k;
  real_T c2_d_x;
  int32_T c2_i5;
  real_T c2_o_a;
  real_T c2_c;
  int32_T c2_i6;
  real_T c2_h_varargin_1;
  real_T c2_varargin_2;
  real_T c2_e_x;
  int32_T c2_i7;
  real_T c2_i_varargin_1;
  real_T c2_f_x;
  real_T c2_d_y;
  int32_T c2_i8;
  real_T c2_g_x;
  real_T c2_e_y;
  int32_T c2_i9;
  real_T c2_h_x;
  real_T c2_f_y;
  real_T c2_i_x;
  int32_T c2_i10;
  real_T c2_g_y;
  real_T c2_j_x;
  int32_T c2_i11;
  real_T c2_h_y;
  int32_T c2_i12;
  real_T c2_dv1[2];
  static boolean_T c2_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, false, true, true, false, false, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, false,
    false, true, true, false, false, true, true, false, false, true, true, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, false, false, false, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, true, true, true, true, true,
    true, true, false, false, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, false, false, false, true, false, false, true, true, false, false,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, false, false, false, true, false, false, true, true, true, true,
    true, true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true };

  int32_T c2_i13;
  real_T c2_dv2[2];
  static boolean_T c2_b_lut[512] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, true, true, true, false, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, false, true, false, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, true, false, false, true, false, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, true, true,
    true, false, true, true, true, false, false, true, true, false, true, true,
    true, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true, true, true, true, true, true,
    true, true, false, false, true, false, true, true, true, true, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, true, true, true, false, true, true, true, false,
    false, true, true, false, true, true, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, false, true, true, true, true, true, true, true, true,
    true, true, true, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, true, true, true, true, true, true, true, true, false, false,
    true, false, true, true, true, true, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, true, true, true, false, true, true, true, false, false, true, true,
    false, true, true, true, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, true,
    true, true, true, true, true, true, false, false, true, false, true, true,
    true, true, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, true, true,
    false, true, true, true, false, false, true, true, false, true, true, true };

  int32_T c2_i14;
  int32_T c2_i15;
  c2_emxArray_real_T *c2_b_centers;
  c2_emxArray_real_T *c2_unusedU0;
  c2_emxArray_real_T *c2_unusedU1;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_loop_ub;
  int32_T c2_i19;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i;
  int32_T c2_n;
  int32_T c2_b_i;
  real_T c2_k_x;
  int32_T c2_i22;
  real_T c2_b_n;
  real_T c2_l_x;
  int32_T c2_m;
  int32_T c2_i23;
  real_T c2_cost[180];
  real_T c2_b_m;
  real_T c2_m_x;
  int32_T c2_i24;
  real_T c2_n_x;
  int32_T c2_thetaIdx;
  real_T c2_sint[180];
  int32_T c2_i25;
  int32_T c2_b_thetaIdx;
  real_T c2_myRho;
  int32_T c2_i26;
  real_T c2_o_x;
  int32_T c2_i_y;
  int32_T c2_i27;
  int32_T c2_rhoIdx;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i30;
  real_T c2_p_x;
  real_T c2_q_x;
  boolean_T c2_b;
  boolean_T c2_b_p;
  int32_T c2_c_idx;
  int32_T c2_f_k;
  int32_T c2_i31;
  real_T c2_b_maxval;
  real_T c2_r_x;
  real_T c2_s_x;
  int32_T c2_first;
  real_T c2_t_x;
  boolean_T c2_b_b;
  real_T c2_ex;
  real_T c2_u_x;
  boolean_T c2_c_p;
  int32_T c2_i32;
  int32_T c2_g_k;
  int32_T c2_i33;
  c2_emxArray_real_T *c2_r0;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_b_loop_ub;
  int32_T c2_i37;
  int32_T c2_i38;
  c2_emxArray_real_T *c2_b_P;
  int32_T c2_i39;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_c_loop_ub;
  int32_T c2_i42;
  c2_emxArray_skoeQIuVNKJRHNtBIlOCZh *c2_r1;
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_d_loop_ub;
  int32_T c2_i46;
  int32_T c2_b_varargin_2;
  int32_T c2_c_varargin_2;
  real_T c2_c_n;
  int32_T c2_d_varargin_2;
  int32_T c2_e_varargin_2;
  real_T c2_d_n;
  int32_T c2_b_ang;
  real_T c2_d0;
  int32_T c2_j_varargin_1;
  int32_T c2_f_varargin_2;
  real_T c2_d1;
  int32_T c2_k_varargin_1;
  int32_T c2_g_varargin_2;
  real_T c2_v_x;
  int32_T c2_e_n;
  real_T c2_w_x;
  real_T c2_x_x;
  real_T c2_f_n;
  real_T c2_d2;
  int32_T c2_l_varargin_1;
  real_T c2_y_x;
  int32_T c2_h_varargin_2;
  real_T c2_ab_x;
  int32_T c2_m_varargin_1;
  real_T c2_bb_x;
  int32_T c2_i_varargin_2;
  real_T c2_d3;
  int32_T c2_g_n;
  real_T c2_cb_x;
  real_T c2_db_x;
  real_T c2_h_n;
  real_T c2_eb_x;
  real_T c2_fb_x;
  real_T c2_gb_x;
  real_T c2_hb_x;
  real_T c2_ib_x;
  real_T c2_jb_x;
  boolean_T guard1 = false;
  boolean_T exitg1;
  int32_T exitg2;
  c2_emxInit_real_T(chartInstance, &c2_centers, 2, &c2_emlrtRTEI);
  c2_emxInit_real_T(chartInstance, &c2_P, 2, &c2_b_emlrtRTEI);
  c2_emxInit_skoeQIuVNKJRHNtBIlOCZhD(chartInstance, &c2_lines, 2,
    &c2_d_emlrtRTEI);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *chartInstance->c2_data;
  c2_b_hoistedGlobal = *chartInstance->c2_angle_;
  for (c2_c_i2 = 0; c2_c_i2 < 19200; c2_c_i2++) {
    chartInstance->c2_u[c2_c_i2] = (*chartInstance->c2_d_u)[c2_c_i2];
  }

  c2_b_data = c2_hoistedGlobal;
  c2_b_angle_ = c2_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_BW3, 0U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_BW, 1U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_BW4, 2U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE(c2_centers->data, (const int32_T *)
    c2_centers->size, NULL, 0, 3, (void *)c2_b_sf_marshallOut, (void *)
    c2_b_sf_marshallIn, c2_centers, true);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_H, 4U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_theta, 5U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_rho, 6U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE(c2_P->data, (const int32_T *)
    c2_P->size, NULL, 0, 7, (void *)c2_f_sf_marshallOut, (void *)
    c2_d_sf_marshallIn, c2_P, true);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE(c2_lines->data, (const int32_T *)
    c2_lines->size, NULL, 0, 8, (void *)c2_g_sf_marshallOut, (void *)
    c2_e_sf_marshallIn, c2_lines, true);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_angle, 9U, c2_h_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_r, 10U, c2_h_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_sig, 11U, c2_h_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_ang, 12U, c2_h_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 13U, c2_h_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 14U, c2_h_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c2_u, 15U, c2_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_data, 16U, c2_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_angle_, 17U, c2_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_y, 18U, c2_h_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_number, 19U, c2_h_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_data1, 20U, c2_h_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_angelina, 21U, c2_h_sf_marshallOut,
    c2_f_sf_marshallIn);
  covrtEmlFcnEval(chartInstance->c2_covrtInstance, 4U, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 2);
  c2_b_angelina = c2_b_angle_;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_b_data1 = c2_b_data;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  for (c2_i3 = 0; c2_i3 < 19200; c2_i3++) {
    chartInstance->c2_I[c2_i3] = chartInstance->c2_u[c2_i3];
  }

  grayto8_real64(chartInstance->c2_I, chartInstance->c2_b_u, 19200.0);
  c2_imhist(chartInstance, chartInstance->c2_b_u, c2_sigma_b_squared);
  for (c2_i4 = 0; c2_i4 < 256; c2_i4++) {
    c2_b_sigma_b_squared[c2_i4] = c2_sigma_b_squared[c2_i4];
  }

  c2_validateattributes(chartInstance, c2_b_sigma_b_squared);
  c2_num_elems = 0.0;
  for (c2_k = 0; c2_k < 256; c2_k++) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_num_elems += c2_sigma_b_squared[(int32_T)c2_b_k - 1];
  }

  c2_omega[0] = c2_sigma_b_squared[0] / c2_num_elems;
  c2_mu[0] = c2_omega[0];
  for (c2_c_k = 0; c2_c_k < 255; c2_c_k++) {
    c2_b_k = 2.0 + (real_T)c2_c_k;
    c2_p = c2_sigma_b_squared[(int32_T)c2_b_k - 1] / c2_num_elems;
    c2_omega[(int32_T)c2_b_k - 1] = c2_omega[(int32_T)(c2_b_k - 1.0) - 1] + c2_p;
    c2_mu[(int32_T)c2_b_k - 1] = c2_mu[(int32_T)(c2_b_k - 1.0) - 1] + c2_p *
      c2_b_k;
  }

  c2_mu_t = c2_mu[255];
  c2_maxval = rtMinusInf;
  for (c2_d_k = 0; c2_d_k < 256; c2_d_k++) {
    c2_b_k = 1.0 + (real_T)c2_d_k;
    c2_l_a = c2_mu_t * c2_omega[(int32_T)c2_b_k - 1] - c2_mu[(int32_T)c2_b_k - 1];
    c2_m_a = c2_l_a;
    c2_n_a = c2_m_a;
    c2_d_x = c2_n_a;
    c2_o_a = c2_d_x;
    c2_c = c2_o_a * c2_o_a;
    c2_sigma_b_squared[(int32_T)c2_b_k - 1] = c2_c / (c2_omega[(int32_T)c2_b_k -
      1] * (1.0 - c2_omega[(int32_T)c2_b_k - 1]));
    c2_h_varargin_1 = c2_maxval;
    c2_varargin_2 = c2_sigma_b_squared[(int32_T)c2_b_k - 1];
    c2_e_x = c2_h_varargin_1;
    c2_i_varargin_1 = c2_varargin_2;
    c2_f_x = c2_e_x;
    c2_d_y = c2_i_varargin_1;
    c2_g_x = c2_f_x;
    c2_e_y = c2_d_y;
    c2_h_x = c2_g_x;
    c2_f_y = c2_e_y;
    c2_i_x = c2_h_x;
    c2_g_y = c2_f_y;
    c2_j_x = c2_i_x;
    c2_h_y = c2_g_y;
    c2_maxval = muDoubleScalarMax(c2_j_x, c2_h_y);
  }

  c2_isfinite_maxval = c2_isfinite(chartInstance, c2_maxval);
  if (c2_isfinite_maxval) {
    c2_b_idx = 0.0;
    c2_num_maxval = 0.0;
    for (c2_e_k = 0; c2_e_k < 256; c2_e_k++) {
      c2_b_k = 1.0 + (real_T)c2_e_k;
      c2_b_idx += c2_b_k * (real_T)(c2_sigma_b_squared[(int32_T)c2_b_k - 1] ==
        c2_maxval);
      c2_num_maxval += (real_T)(c2_sigma_b_squared[(int32_T)c2_b_k - 1] ==
        c2_maxval);
    }

    c2_b_idx /= c2_num_maxval;
    c2_t = (c2_b_idx - 1.0) / 255.0;
  } else {
    c2_t = 0.0;
  }

  c2_T = c2_t;
  for (c2_i5 = 0; c2_i5 < 19200; c2_i5++) {
    chartInstance->c2_BW3[c2_i5] = (chartInstance->c2_I[c2_i5] > c2_T);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  for (c2_i6 = 0; c2_i6 < 19200; c2_i6++) {
    chartInstance->c2_b_BW3[c2_i6] = chartInstance->c2_BW3[c2_i6];
  }

  c2_edge(chartInstance, chartInstance->c2_b_BW3, chartInstance->c2_bv0);
  for (c2_i7 = 0; c2_i7 < 19200; c2_i7++) {
    chartInstance->c2_BW[c2_i7] = chartInstance->c2_bv0[c2_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i8 = 0; c2_i8 < 19200; c2_i8++) {
    chartInstance->c2_last_aout[c2_i8] = chartInstance->c2_BW[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 19200; c2_i9++) {
    chartInstance->c2_BW4[c2_i9] = chartInstance->c2_last_aout[c2_i9];
  }

  do {
    for (c2_i10 = 0; c2_i10 < 19200; c2_i10++) {
      chartInstance->c2_last_aout[c2_i10] = chartInstance->c2_BW4[c2_i10];
    }

    for (c2_i11 = 0; c2_i11 < 19200; c2_i11++) {
      chartInstance->c2_bw[c2_i11] = chartInstance->c2_BW4[c2_i11];
    }

    for (c2_i12 = 0; c2_i12 < 2; c2_i12++) {
      c2_dv1[c2_i12] = 120.0 + 40.0 * (real_T)c2_i12;
    }

    bwlookup_tbb_boolean(chartInstance->c2_bw, c2_dv1, 2.0, c2_lut, 512.0,
                         chartInstance->c2_image_iter1);
    for (c2_i13 = 0; c2_i13 < 2; c2_i13++) {
      c2_dv2[c2_i13] = 120.0 + 40.0 * (real_T)c2_i13;
    }

    bwlookup_tbb_boolean(chartInstance->c2_image_iter1, c2_dv2, 2.0, c2_b_lut,
                         512.0, chartInstance->c2_bw);
    for (c2_i14 = 0; c2_i14 < 19200; c2_i14++) {
      chartInstance->c2_BW4[c2_i14] = chartInstance->c2_bw[c2_i14];
    }
  } while (!c2_b_isequal(chartInstance, chartInstance->c2_last_aout,
                         chartInstance->c2_bw));

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  for (c2_i15 = 0; c2_i15 < 19200; c2_i15++) {
    chartInstance->c2_c_BW3[c2_i15] = chartInstance->c2_BW3[c2_i15];
  }

  c2_emxInit_real_T(chartInstance, &c2_b_centers, 2, (emlrtRTEInfo *)NULL);
  c2_emxInit_real_T(chartInstance, &c2_unusedU0, 2, (emlrtRTEInfo *)NULL);
  c2_emxInit_real_T(chartInstance, &c2_unusedU1, 2, (emlrtRTEInfo *)NULL);
  c2_imfindcircles(chartInstance, chartInstance->c2_c_BW3, c2_b_centers,
                   c2_unusedU0, c2_unusedU1);
  c2_i16 = c2_centers->size[0] * c2_centers->size[1];
  c2_centers->size[0] = c2_b_centers->size[0];
  c2_centers->size[1] = c2_b_centers->size[1];
  c2_emxEnsureCapacity_real_T(chartInstance, c2_centers, c2_i16, &c2_emlrtRTEI);
  c2_i17 = c2_centers->size[0];
  c2_i18 = c2_centers->size[1];
  c2_loop_ub = c2_b_centers->size[0] * c2_b_centers->size[1] - 1;
  c2_emxFree_real_T(chartInstance, &c2_unusedU1);
  c2_emxFree_real_T(chartInstance, &c2_unusedU0);
  for (c2_i19 = 0; c2_i19 <= c2_loop_ub; c2_i19++) {
    c2_centers->data[c2_i19] = c2_b_centers->data[c2_i19];
  }

  c2_emxFree_real_T(chartInstance, &c2_b_centers);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  for (c2_i20 = 0; c2_i20 < 19200; c2_i20++) {
    chartInstance->c2_last_aout[c2_i20] = chartInstance->c2_BW4[c2_i20];
  }

  for (c2_i21 = 0; c2_i21 < 71820; c2_i21++) {
    chartInstance->c2_b_H[c2_i21] = 0.0;
  }

  for (c2_i = 0; c2_i < 180; c2_i++) {
    c2_b_i = c2_i;
    c2_k_x = (-90.0 + (real_T)c2_b_i) * 3.1415926535897931 / 180.0;
    c2_l_x = c2_k_x;
    c2_l_x = muDoubleScalarCos(c2_l_x);
    c2_cost[c2_b_i] = c2_l_x;
    c2_m_x = (-90.0 + (real_T)c2_b_i) * 3.1415926535897931 / 180.0;
    c2_n_x = c2_m_x;
    c2_n_x = muDoubleScalarSin(c2_n_x);
    c2_sint[c2_b_i] = c2_n_x;
  }

  for (c2_n = 0; c2_n < 160; c2_n++) {
    c2_b_n = 1.0 + (real_T)c2_n;
    for (c2_m = 0; c2_m < 120; c2_m++) {
      c2_b_m = 1.0 + (real_T)c2_m;
      if (chartInstance->c2_last_aout[((int32_T)c2_b_m + 120 * ((int32_T)c2_b_n
            - 1)) - 1]) {
        for (c2_thetaIdx = 0; c2_thetaIdx < 180; c2_thetaIdx++) {
          c2_b_thetaIdx = c2_thetaIdx;
          c2_myRho = (c2_b_n - 1.0) * c2_cost[c2_b_thetaIdx] + (c2_b_m - 1.0) *
            c2_sint[c2_b_thetaIdx];
          c2_o_x = c2_myRho - -199.0;
          c2_i_y = (int32_T)(c2_o_x + 0.5) + 1;
          c2_rhoIdx = c2_i_y;
          chartInstance->c2_b_H[(sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 217, 43,
             MAX_uint32_T, c2_rhoIdx, 1, 399) + 399 * c2_b_thetaIdx) - 1] =
            chartInstance->c2_b_H[(sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 217, 43,
             MAX_uint32_T, c2_rhoIdx, 1, 399) + 399 * c2_b_thetaIdx) - 1] + 1.0;
        }
      }
    }
  }

  for (c2_i22 = 0; c2_i22 < 71820; c2_i22++) {
    chartInstance->c2_H[c2_i22] = chartInstance->c2_b_H[c2_i22];
  }

  for (c2_i23 = 0; c2_i23 < 180; c2_i23++) {
    c2_theta[c2_i23] = -90.0 + (real_T)c2_i23;
  }

  for (c2_i24 = 0; c2_i24 < 399; c2_i24++) {
    c2_rho[c2_i24] = -199.0 + (real_T)c2_i24;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i25 = 0; c2_i25 < 71820; c2_i25++) {
    chartInstance->c2_b_H[c2_i25] = chartInstance->c2_H[c2_i25];
  }

  for (c2_i26 = 0; c2_i26 < 71820; c2_i26++) {
    chartInstance->c2_b_H[c2_i26];
  }

  for (c2_i27 = 0; c2_i27 < 71820; c2_i27++) {
    chartInstance->c2_b_H[c2_i27];
  }

  for (c2_i28 = 0; c2_i28 < 71820; c2_i28++) {
    chartInstance->c2_b_H[c2_i28];
  }

  for (c2_i29 = 0; c2_i29 < 71820; c2_i29++) {
    chartInstance->c2_b_H[c2_i29];
  }

  for (c2_i30 = 0; c2_i30 < 71820; c2_i30++) {
    chartInstance->c2_b_H[c2_i30];
  }

  c2_p_x = chartInstance->c2_b_H[0];
  c2_q_x = c2_p_x;
  c2_b = muDoubleScalarIsNaN(c2_q_x);
  c2_b_p = !c2_b;
  if (c2_b_p) {
    c2_c_idx = 1;
  } else {
    c2_c_idx = 0;
    c2_f_k = 2;
    exitg1 = false;
    while ((!exitg1) && (c2_f_k < 71821)) {
      c2_r_x = chartInstance->c2_b_H[c2_f_k - 1];
      c2_s_x = c2_r_x;
      c2_b_b = muDoubleScalarIsNaN(c2_s_x);
      c2_c_p = !c2_b_b;
      if (c2_c_p) {
        c2_c_idx = c2_f_k;
        exitg1 = true;
      } else {
        c2_f_k++;
      }
    }
  }

  if (c2_c_idx == 0) {
    c2_b_maxval = chartInstance->c2_b_H[0];
  } else {
    for (c2_i31 = 0; c2_i31 < 71820; c2_i31++) {
      chartInstance->c2_b_H[c2_i31];
    }

    c2_first = c2_c_idx - 1;
    c2_ex = chartInstance->c2_b_H[c2_first];
    c2_i32 = c2_first;
    for (c2_g_k = c2_i32 + 1; c2_g_k + 1 < 71821; c2_g_k++) {
      if (c2_ex < chartInstance->c2_b_H[c2_g_k]) {
        c2_ex = chartInstance->c2_b_H[c2_g_k];
      }
    }

    c2_b_maxval = c2_ex;
  }

  c2_t_x = 0.3 * c2_b_maxval;
  c2_u_x = c2_t_x;
  c2_u_x = muDoubleScalarCeil(c2_u_x);
  for (c2_i33 = 0; c2_i33 < 71820; c2_i33++) {
    chartInstance->c2_c_H[c2_i33] = chartInstance->c2_H[c2_i33];
  }

  c2_emxInit_real_T(chartInstance, &c2_r0, 2, &c2_f_emlrtRTEI);
  c2_houghpeaks(chartInstance, chartInstance->c2_c_H, c2_u_x, c2_r0);
  c2_i34 = c2_P->size[0] * c2_P->size[1];
  c2_P->size[0] = c2_r0->size[0];
  c2_P->size[1] = c2_r0->size[1];
  c2_emxEnsureCapacity_real_T(chartInstance, c2_P, c2_i34, &c2_b_emlrtRTEI);
  c2_i35 = c2_P->size[0];
  c2_i36 = c2_P->size[1];
  c2_b_loop_ub = c2_r0->size[0] * c2_r0->size[1] - 1;
  for (c2_i37 = 0; c2_i37 <= c2_b_loop_ub; c2_i37++) {
    c2_P->data[c2_i37] = c2_r0->data[c2_i37];
  }

  c2_emxFree_real_T(chartInstance, &c2_r0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i38 = 0; c2_i38 < 19200; c2_i38++) {
    chartInstance->c2_b_BW[c2_i38] = chartInstance->c2_BW[c2_i38];
  }

  c2_emxInit_real_T(chartInstance, &c2_b_P, 2, &c2_c_emlrtRTEI);
  c2_i39 = c2_b_P->size[0] * c2_b_P->size[1];
  c2_b_P->size[0] = c2_P->size[0];
  c2_b_P->size[1] = c2_P->size[1];
  c2_emxEnsureCapacity_real_T(chartInstance, c2_b_P, c2_i39, &c2_c_emlrtRTEI);
  c2_i40 = c2_b_P->size[0];
  c2_i41 = c2_b_P->size[1];
  c2_c_loop_ub = c2_P->size[0] * c2_P->size[1] - 1;
  for (c2_i42 = 0; c2_i42 <= c2_c_loop_ub; c2_i42++) {
    c2_b_P->data[c2_i42] = c2_P->data[c2_i42];
  }

  c2_emxInit_skoeQIuVNKJRHNtBIlOCZhD(chartInstance, &c2_r1, 2, &c2_e_emlrtRTEI);
  c2_houghlines(chartInstance, chartInstance->c2_b_BW, c2_b_P, c2_r1);
  c2_i43 = c2_lines->size[0] * c2_lines->size[1];
  c2_lines->size[0] = 1;
  c2_lines->size[1] = c2_r1->size[1];
  c2_emxEnsureCapacity_skoeQIuVNKJRH(chartInstance, c2_lines, c2_i43,
    &c2_d_emlrtRTEI);
  c2_i44 = c2_lines->size[0];
  c2_i45 = c2_lines->size[1];
  c2_d_loop_ub = c2_r1->size[0] * c2_r1->size[1] - 1;
  c2_emxFree_real_T(chartInstance, &c2_b_P);
  for (c2_i46 = 0; c2_i46 <= c2_d_loop_ub; c2_i46++) {
    c2_lines->data[c2_i46] = c2_r1->data[c2_i46];
  }

  c2_emxFree_skoeQIuVNKJRHNtBIlOCZhD(chartInstance, &c2_r1);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_angle = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  c2_r = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  c2_b_number = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  c2_b_varargin_2 = c2_lines->size[1];
  c2_c_varargin_2 = c2_b_varargin_2;
  c2_c_n = (real_T)c2_c_varargin_2;
  c2_d_varargin_2 = c2_lines->size[1];
  c2_e_varargin_2 = c2_d_varargin_2;
  c2_d_n = (real_T)c2_e_varargin_2;
  if (covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 0,
                     covrtRelationalopUpdateFcn(chartInstance->c2_covrtInstance,
        4U, 0U, 0U, c2_c_n, 4.0, -1, 0U, c2_d_n == 4.0))) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
    c2_b_number = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
    c2_sig = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
    c2_ang = 1.0;
    c2_b_ang = 0;
    guard1 = false;
    do {
      exitg2 = 0;
      if (c2_b_ang < 4) {
        c2_ang = 1.0 + (real_T)c2_b_ang;
        covrtEmlForEval(chartInstance->c2_covrtInstance, 4U, 0, 0, 1);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
        c2_d0 = c2_lines->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 494, 10,
           MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U, 494U,
            10U, c2_ang), 1, c2_lines->size[1]) - 1].theta;
        if (covrtEmlCondEval(chartInstance->c2_covrtInstance, 4U, 0, 0,
                             covrtRelationalopUpdateFcn
                             (chartInstance->c2_covrtInstance, 4U, 0U, 1U, c2_d0,
                              c2_b_angle_ + 5.0, -1, 4U, c2_d0 > c2_b_angle_ +
                              5.0))) {
          guard1 = true;
          exitg2 = 1;
        } else {
          c2_d1 = c2_lines->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 527, 10,
             MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U, 527U,
              10U, c2_ang), 1, c2_lines->size[1]) - 1].theta;
          if (covrtEmlCondEval(chartInstance->c2_covrtInstance, 4U, 0, 1,
                               covrtRelationalopUpdateFcn
                               (chartInstance->c2_covrtInstance, 4U, 0U, 2U,
                                c2_d1, c2_b_angle_ - 5.0, -1, 2U, c2_d1 <
                                c2_b_angle_ - 5.0))) {
            guard1 = true;
            exitg2 = 1;
          } else {
            covrtEmlMcdcEval(chartInstance->c2_covrtInstance, 4U, 0, 0, false);
            covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 1, false);
            c2_b_ang++;
            _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
            guard1 = false;
          }
        }
      } else {
        covrtEmlForEval(chartInstance->c2_covrtInstance, 4U, 0, 0, 0);
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if (guard1) {
      covrtEmlMcdcEval(chartInstance->c2_covrtInstance, 4U, 0, 0, true);
      covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 1, true);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
      c2_v_x = c2_lines->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 575, 20,
         MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U, 575U, 20U,
          c2_ang), 1, c2_lines->size[1]) - 1].point1[0] - 90.0;
      c2_w_x = c2_v_x;
      c2_x_x = c2_w_x;
      c2_d2 = muDoubleScalarAbs(c2_x_x);
      c2_y_x = c2_lines->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 606, 20,
         MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U, 606U, 20U,
          c2_ang), 1, c2_lines->size[1]) - 1].point2[0] - 90.0;
      c2_ab_x = c2_y_x;
      c2_bb_x = c2_ab_x;
      c2_d3 = muDoubleScalarAbs(c2_bb_x);
      if (covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 2,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c2_covrtInstance, 4U, 0U, 3U, c2_d2,
                          c2_d3, -1, 4U, c2_d2 > c2_d3))) {
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
        c2_db_x = c2_lines->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 658, 20,
           MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U, 658U,
            20U, c2_ang), 1, c2_lines->size[1]) - 1].point1[0] - 90.0;
        c2_sig = c2_db_x;
        c2_fb_x = c2_sig;
        c2_sig = c2_fb_x;
        c2_hb_x = c2_sig;
        c2_sig = c2_hb_x;
        c2_jb_x = c2_sig;
        c2_sig = c2_jb_x;
        c2_sig = muDoubleScalarSign(c2_sig);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
        c2_cb_x = c2_lines->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 728, 20,
           MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U, 728U,
            20U, c2_ang), 1, c2_lines->size[1]) - 1].point2[0] - 90.0;
        c2_sig = c2_cb_x;
        c2_eb_x = c2_sig;
        c2_sig = c2_eb_x;
        c2_gb_x = c2_sig;
        c2_sig = c2_gb_x;
        c2_ib_x = c2_sig;
        c2_sig = c2_ib_x;
        c2_sig = muDoubleScalarSign(c2_sig);
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
      c2_angle = c2_lines->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 790, 10,
         MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U, 790U, 10U,
          c2_ang), 1, c2_lines->size[1]) - 1].theta;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
      if (covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 3,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c2_covrtInstance, 4U, 0U, 4U, c2_b_data,
                          0.0, -1, 0U, c2_b_data == 0.0))) {
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
        c2_b_data1 = 1.0;
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
        c2_b_angelina = c2_angle;
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
    c2_r = c2_sig;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
    if (covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 4,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c2_covrtInstance, 4U, 0U, 5U, c2_b_data,
                        1.0, -1, 0U, c2_b_data == 1.0))) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
      c2_b_data1 = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
  if (covrtEmlCondEval(chartInstance->c2_covrtInstance, 4U, 0, 2,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c2_covrtInstance, 4U, 0U, 6U, c2_angle,
                        0.0, -1, 2U, c2_angle < 0.0)) && covrtEmlCondEval
      (chartInstance->c2_covrtInstance, 4U, 0, 3, covrtRelationalopUpdateFcn
       (chartInstance->c2_covrtInstance, 4U, 0U, 7U, c2_r, 1.0, -1, 0U, c2_r ==
        1.0))) {
    covrtEmlMcdcEval(chartInstance->c2_covrtInstance, 4U, 0, 1, true);
    covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 5, true);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 40);
    c2_angle += 180.0;
  } else {
    covrtEmlMcdcEval(chartInstance->c2_covrtInstance, 4U, 0, 1, false);
    covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 5, false);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 41);
    if (covrtEmlCondEval(chartInstance->c2_covrtInstance, 4U, 0, 4,
                         covrtRelationalopUpdateFcn
                         (chartInstance->c2_covrtInstance, 4U, 0U, 8U, c2_angle,
                          0.0, -1, 4U, c2_angle > 0.0)) && covrtEmlCondEval
        (chartInstance->c2_covrtInstance, 4U, 0, 5, covrtRelationalopUpdateFcn
         (chartInstance->c2_covrtInstance, 4U, 0U, 9U, c2_r, -1.0, -1, 0U, c2_r ==
          -1.0))) {
      covrtEmlMcdcEval(chartInstance->c2_covrtInstance, 4U, 0, 2, true);
      covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 6, true);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 42);
      c2_angle -= 180.0;
    } else {
      covrtEmlMcdcEval(chartInstance->c2_covrtInstance, 4U, 0, 2, false);
      covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 6, false);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 44);
  c2_j_varargin_1 = c2_centers->size[0];
  c2_f_varargin_2 = c2_centers->size[1];
  c2_k_varargin_1 = c2_j_varargin_1;
  c2_g_varargin_2 = c2_f_varargin_2;
  if ((c2_k_varargin_1 == 0) || (c2_g_varargin_2 == 0)) {
    c2_e_n = 0;
  } else if (c2_k_varargin_1 > c2_g_varargin_2) {
    c2_e_n = c2_k_varargin_1;
  } else {
    c2_e_n = c2_g_varargin_2;
  }

  c2_f_n = (real_T)c2_e_n;
  c2_l_varargin_1 = c2_centers->size[0];
  c2_h_varargin_2 = c2_centers->size[1];
  c2_m_varargin_1 = c2_l_varargin_1;
  c2_i_varargin_2 = c2_h_varargin_2;
  if ((c2_m_varargin_1 == 0) || (c2_i_varargin_2 == 0)) {
    c2_g_n = 0;
  } else if (c2_m_varargin_1 > c2_i_varargin_2) {
    c2_g_n = c2_m_varargin_1;
  } else {
    c2_g_n = c2_i_varargin_2;
  }

  c2_h_n = (real_T)c2_g_n;
  if (covrtEmlIfEval(chartInstance->c2_covrtInstance, 4U, 0, 7,
                     covrtRelationalopUpdateFcn(chartInstance->c2_covrtInstance,
        4U, 0U, 10U, c2_f_n, 2.0, -1, 0U, c2_h_n == 2.0))) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
    c2_b_number = 2.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 47);
  c2_c_y = c2_angle;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -47);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c2_b_y = c2_c_y;
  *chartInstance->c2_number = c2_b_number;
  *chartInstance->c2_data1 = c2_b_data1;
  *chartInstance->c2_angelina = c2_b_angelina;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_emxFree_skoeQIuVNKJRHNtBIlOCZhD(chartInstance, &c2_lines);
  c2_emxFree_real_T(chartInstance, &c2_P);
  c2_emxFree_real_T(chartInstance, &c2_centers);
}

static void initSimStructsc2_flightControlSystem
  (SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)(c2_machineNumber);
  (void)(c2_chartNumber);
  (void)(c2_instanceNumber);
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i47;
  int32_T c2_i48;
  const mxArray *c2_c_y = NULL;
  int32_T c2_i49;
  boolean_T c2_e_u[19200];
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i47 = 0;
  for (c2_i48 = 0; c2_i48 < 160; c2_i48++) {
    for (c2_i49 = 0; c2_i49 < 120; c2_i49++) {
      c2_e_u[c2_i49 + c2_i47] = (*(boolean_T (*)[19200])c2_inData)[c2_i49 +
        c2_i47];
    }

    c2_i47 += 120;
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_e_u, 11, 0U, 1U, 0U, 2, 120, 160),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_c_y, false);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_e_u, const emlrtMsgIdentifier *c2_parentId,
  boolean_T c2_c_y[19200])
{
  boolean_T c2_bv1[19200];
  int32_T c2_i50;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_e_u), c2_bv1, 1, 11, 0U, 1, 0U, 2,
                120, 160);
  for (c2_i50 = 0; c2_i50 < 19200; c2_i50++) {
    c2_c_y[c2_i50] = c2_bv1[c2_i50];
  }

  sf_mex_destroy(&c2_e_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_d_BW3;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  boolean_T c2_c_y[19200];
  int32_T c2_i51;
  int32_T c2_i52;
  int32_T c2_i53;
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_d_BW3 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_d_BW3), &c2_thisId, c2_c_y);
  sf_mex_destroy(&c2_d_BW3);
  c2_i51 = 0;
  for (c2_i52 = 0; c2_i52 < 160; c2_i52++) {
    for (c2_i53 = 0; c2_i53 < 120; c2_i53++) {
      (*(boolean_T (*)[19200])c2_outData)[c2_i53 + c2_i51] = c2_c_y[c2_i53 +
        c2_i51];
    }

    c2_i51 += 120;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid,
  c2_emxArray_real_T *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_emxArray_real_T *c2_e_u;
  int32_T c2_i54;
  int32_T c2_i55;
  int32_T c2_i56;
  int32_T c2_loop_ub;
  int32_T c2_i57;
  const mxArray *c2_c_y = NULL;
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_emxInit_real_T(chartInstance, &c2_e_u, 2, (emlrtRTEInfo *)NULL);
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i54 = c2_e_u->size[0] * c2_e_u->size[1];
  c2_e_u->size[0] = c2_inData->size[0];
  c2_e_u->size[1] = c2_inData->size[1];
  c2_emxEnsureCapacity_real_T(chartInstance, c2_e_u, c2_i54, (emlrtRTEInfo *)
    NULL);
  c2_i55 = c2_e_u->size[0];
  c2_i56 = c2_e_u->size[1];
  c2_loop_ub = c2_inData->size[0] * c2_inData->size[1] - 1;
  for (c2_i57 = 0; c2_i57 <= c2_loop_ub; c2_i57++) {
    c2_e_u->data[c2_i57] = c2_inData->data[c2_i57];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_e_u->data, 0, 0U, 1U, 0U, 2,
    c2_e_u->size[0], c2_e_u->size[1]), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_c_y, false);
  c2_emxFree_real_T(chartInstance, &c2_e_u);
  return c2_mxArrayOutData;
}

static void c2_b_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_e_u, const emlrtMsgIdentifier *c2_parentId,
  c2_emxArray_real_T *c2_c_y)
{
  c2_emxArray_real_T *c2_r2;
  int32_T c2_i58;
  int32_T c2_i59;
  uint32_T c2_uv0[2];
  static uint32_T c2_uv1[2] = { MAX_uint32_T, 2U };

  int32_T c2_i60;
  boolean_T c2_bv2[2];
  int32_T c2_i61;
  int32_T c2_i62;
  int32_T c2_i63;
  int32_T c2_loop_ub;
  int32_T c2_i64;
  c2_emxInit_real_T(chartInstance, &c2_r2, 2, (emlrtRTEInfo *)NULL);
  for (c2_i58 = 0; c2_i58 < 2; c2_i58++) {
    c2_uv0[c2_i58] = c2_uv1[c2_i58];
  }

  c2_i59 = c2_r2->size[0] * c2_r2->size[1];
  c2_r2->size[0] = sf_mex_get_dimension(c2_e_u, 0);
  c2_r2->size[1] = sf_mex_get_dimension(c2_e_u, 1);
  c2_emxEnsureCapacity_real_T(chartInstance, c2_r2, c2_i59, (emlrtRTEInfo *)NULL);
  for (c2_i60 = 0; c2_i60 < 2; c2_i60++) {
    c2_bv2[c2_i60] = true;
  }

  sf_mex_import_vs(c2_parentId, sf_mex_dup(c2_e_u), c2_r2->data, 1, 0, 0U, 1, 0U,
                   2, c2_bv2, c2_uv0, c2_r2->size);
  c2_i61 = c2_c_y->size[0] * c2_c_y->size[1];
  c2_c_y->size[0] = c2_r2->size[0];
  c2_c_y->size[1] = c2_r2->size[1];
  c2_emxEnsureCapacity_real_T(chartInstance, c2_c_y, c2_i61, (emlrtRTEInfo *)
    NULL);
  c2_i62 = c2_c_y->size[0];
  c2_i63 = c2_c_y->size[1];
  c2_loop_ub = c2_r2->size[0] * c2_r2->size[1] - 1;
  for (c2_i64 = 0; c2_i64 <= c2_loop_ub; c2_i64++) {
    c2_c_y->data[c2_i64] = c2_r2->data[c2_i64];
  }

  sf_mex_destroy(&c2_e_u);
  c2_emxFree_real_T(chartInstance, &c2_r2);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, c2_emxArray_real_T *c2_outData)
{
  c2_emxArray_real_T *c2_c_y;
  const mxArray *c2_centers;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_i65;
  int32_T c2_loop_ub;
  int32_T c2_i66;
  int32_T c2_b_loop_ub;
  int32_T c2_i67;
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_emxInit_real_T(chartInstance, &c2_c_y, 2, (emlrtRTEInfo *)NULL);
  c2_centers = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_centers), &c2_thisId,
                        c2_c_y);
  sf_mex_destroy(&c2_centers);
  c2_i65 = c2_outData->size[0] * c2_outData->size[1];
  c2_outData->size[0] = c2_c_y->size[0];
  c2_outData->size[1] = c2_c_y->size[1];
  c2_emxEnsureCapacity_real_T(chartInstance, c2_outData, c2_i65, (emlrtRTEInfo *)
    NULL);
  c2_loop_ub = c2_c_y->size[1] - 1;
  for (c2_i66 = 0; c2_i66 <= c2_loop_ub; c2_i66++) {
    c2_b_loop_ub = c2_c_y->size[0] - 1;
    for (c2_i67 = 0; c2_i67 <= c2_b_loop_ub; c2_i67++) {
      c2_outData->data[c2_i67 + c2_outData->size[0] * c2_i66] = c2_c_y->
        data[c2_i67 + c2_c_y->size[0] * c2_i66];
    }
  }

  c2_emxFree_real_T(chartInstance, &c2_c_y);
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i68;
  int32_T c2_i69;
  const mxArray *c2_c_y = NULL;
  int32_T c2_i70;
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i68 = 0;
  for (c2_i69 = 0; c2_i69 < 180; c2_i69++) {
    for (c2_i70 = 0; c2_i70 < 399; c2_i70++) {
      chartInstance->c2_c_u[c2_i70 + c2_i68] = (*(real_T (*)[71820])c2_inData)
        [c2_i70 + c2_i68];
    }

    c2_i68 += 399;
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", chartInstance->c2_c_u, 0, 0U, 1U, 0U,
    2, 399, 180), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_c_y, false);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_e_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_c_y[71820])
{
  int32_T c2_i71;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_e_u), chartInstance->c2_dv3, 1, 0, 0U,
                1, 0U, 2, 399, 180);
  for (c2_i71 = 0; c2_i71 < 71820; c2_i71++) {
    c2_c_y[c2_i71] = chartInstance->c2_dv3[c2_i71];
  }

  sf_mex_destroy(&c2_e_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_d_H;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_i72;
  int32_T c2_i73;
  int32_T c2_i74;
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_d_H = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_d_H), &c2_thisId,
                        chartInstance->c2_y);
  sf_mex_destroy(&c2_d_H);
  c2_i72 = 0;
  for (c2_i73 = 0; c2_i73 < 180; c2_i73++) {
    for (c2_i74 = 0; c2_i74 < 399; c2_i74++) {
      (*(real_T (*)[71820])c2_outData)[c2_i74 + c2_i72] = chartInstance->
        c2_y[c2_i74 + c2_i72];
    }

    c2_i72 += 399;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i75;
  const mxArray *c2_c_y = NULL;
  real_T c2_e_u[180];
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i75 = 0; c2_i75 < 180; c2_i75++) {
    c2_e_u[c2_i75] = (*(real_T (*)[180])c2_inData)[c2_i75];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_e_u, 0, 0U, 1U, 0U, 2, 1, 180),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_c_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i76;
  const mxArray *c2_c_y = NULL;
  real_T c2_e_u[399];
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i76 = 0; c2_i76 < 399; c2_i76++) {
    c2_e_u[c2_i76] = (*(real_T (*)[399])c2_inData)[c2_i76];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_e_u, 0, 0U, 1U, 0U, 2, 1, 399),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_c_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid,
  c2_emxArray_real_T *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_emxArray_real_T *c2_e_u;
  int32_T c2_i77;
  int32_T c2_i78;
  int32_T c2_i79;
  int32_T c2_loop_ub;
  int32_T c2_i80;
  const mxArray *c2_c_y = NULL;
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_emxInit_real_T(chartInstance, &c2_e_u, 2, (emlrtRTEInfo *)NULL);
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i77 = c2_e_u->size[0] * c2_e_u->size[1];
  c2_e_u->size[0] = c2_inData->size[0];
  c2_e_u->size[1] = c2_inData->size[1];
  c2_emxEnsureCapacity_real_T(chartInstance, c2_e_u, c2_i77, (emlrtRTEInfo *)
    NULL);
  c2_i78 = c2_e_u->size[0];
  c2_i79 = c2_e_u->size[1];
  c2_loop_ub = c2_inData->size[0] * c2_inData->size[1] - 1;
  for (c2_i80 = 0; c2_i80 <= c2_loop_ub; c2_i80++) {
    c2_e_u->data[c2_i80] = c2_inData->data[c2_i80];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_e_u->data, 0, 0U, 1U, 0U, 2,
    c2_e_u->size[0], c2_e_u->size[1]), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_c_y, false);
  c2_emxFree_real_T(chartInstance, &c2_e_u);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_e_u, const emlrtMsgIdentifier *c2_parentId,
  c2_emxArray_real_T *c2_c_y)
{
  c2_emxArray_real_T *c2_r3;
  int32_T c2_i81;
  int32_T c2_i82;
  uint32_T c2_uv2[2];
  int32_T c2_i83;
  boolean_T c2_bv3[2];
  int32_T c2_i84;
  int32_T c2_i85;
  int32_T c2_i86;
  int32_T c2_loop_ub;
  int32_T c2_i87;
  c2_emxInit_real_T(chartInstance, &c2_r3, 2, (emlrtRTEInfo *)NULL);
  for (c2_i81 = 0; c2_i81 < 2; c2_i81++) {
    c2_uv2[c2_i81] = 71820U + (uint32_T)(-71818 * c2_i81);
  }

  c2_i82 = c2_r3->size[0] * c2_r3->size[1];
  c2_r3->size[0] = sf_mex_get_dimension(c2_e_u, 0);
  c2_r3->size[1] = sf_mex_get_dimension(c2_e_u, 1);
  c2_emxEnsureCapacity_real_T(chartInstance, c2_r3, c2_i82, (emlrtRTEInfo *)NULL);
  for (c2_i83 = 0; c2_i83 < 2; c2_i83++) {
    c2_bv3[c2_i83] = true;
  }

  sf_mex_import_vs(c2_parentId, sf_mex_dup(c2_e_u), c2_r3->data, 1, 0, 0U, 1, 0U,
                   2, c2_bv3, c2_uv2, c2_r3->size);
  c2_i84 = c2_c_y->size[0] * c2_c_y->size[1];
  c2_c_y->size[0] = c2_r3->size[0];
  c2_c_y->size[1] = c2_r3->size[1];
  c2_emxEnsureCapacity_real_T(chartInstance, c2_c_y, c2_i84, (emlrtRTEInfo *)
    NULL);
  c2_i85 = c2_c_y->size[0];
  c2_i86 = c2_c_y->size[1];
  c2_loop_ub = c2_r3->size[0] * c2_r3->size[1] - 1;
  for (c2_i87 = 0; c2_i87 <= c2_loop_ub; c2_i87++) {
    c2_c_y->data[c2_i87] = c2_r3->data[c2_i87];
  }

  sf_mex_destroy(&c2_e_u);
  c2_emxFree_real_T(chartInstance, &c2_r3);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, c2_emxArray_real_T *c2_outData)
{
  c2_emxArray_real_T *c2_c_y;
  const mxArray *c2_P;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_i88;
  int32_T c2_loop_ub;
  int32_T c2_i89;
  int32_T c2_b_loop_ub;
  int32_T c2_i90;
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_emxInit_real_T(chartInstance, &c2_c_y, 2, (emlrtRTEInfo *)NULL);
  c2_P = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_P), &c2_thisId, c2_c_y);
  sf_mex_destroy(&c2_P);
  c2_i88 = c2_outData->size[0] * c2_outData->size[1];
  c2_outData->size[0] = c2_c_y->size[0];
  c2_outData->size[1] = c2_c_y->size[1];
  c2_emxEnsureCapacity_real_T(chartInstance, c2_outData, c2_i88, (emlrtRTEInfo *)
    NULL);
  c2_loop_ub = c2_c_y->size[1] - 1;
  for (c2_i89 = 0; c2_i89 <= c2_loop_ub; c2_i89++) {
    c2_b_loop_ub = c2_c_y->size[0] - 1;
    for (c2_i90 = 0; c2_i90 <= c2_b_loop_ub; c2_i90++) {
      c2_outData->data[c2_i90 + c2_outData->size[0] * c2_i89] = c2_c_y->
        data[c2_i90 + c2_c_y->size[0] * c2_i89];
    }
  }

  c2_emxFree_real_T(chartInstance, &c2_c_y);
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid,
  c2_emxArray_skoeQIuVNKJRHNtBIlOCZh *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  c2_emxArray_skoeQIuVNKJRHNtBIlOCZh *c2_e_u;
  int32_T c2_i91;
  int32_T c2_i92;
  int32_T c2_i93;
  int32_T c2_loop_ub;
  int32_T c2_i94;
  const mxArray *c2_c_y = NULL;
  int32_T c2_i95;
  int32_T c2_iv0[2];
  static const char * c2_sv0[4] = { "point1", "point2", "theta", "rho" };

  int32_T c2_i;
  int32_T c2_j1;
  int32_T c2_i96;
  const mxArray *c2_d_y = NULL;
  real_T c2_f_u[2];
  int32_T c2_i97;
  const mxArray *c2_e_y = NULL;
  real_T c2_g_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_h_u;
  const mxArray *c2_g_y = NULL;
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_emxInit_skoeQIuVNKJRHNtBIlOCZhD(chartInstance, &c2_e_u, 2, (emlrtRTEInfo *)
    NULL);
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i91 = c2_e_u->size[0] * c2_e_u->size[1];
  c2_e_u->size[0] = 1;
  c2_e_u->size[1] = c2_inData->size[1];
  c2_emxEnsureCapacity_skoeQIuVNKJRH(chartInstance, c2_e_u, c2_i91,
    (emlrtRTEInfo *)NULL);
  c2_i92 = c2_e_u->size[0];
  c2_i93 = c2_e_u->size[1];
  c2_loop_ub = c2_inData->size[0] * c2_inData->size[1] - 1;
  for (c2_i94 = 0; c2_i94 <= c2_loop_ub; c2_i94++) {
    c2_e_u->data[c2_i94] = c2_inData->data[c2_i94];
  }

  c2_c_y = NULL;
  for (c2_i95 = 0; c2_i95 < 2; c2_i95++) {
    c2_iv0[c2_i95] = c2_e_u->size[c2_i95];
  }

  sf_mex_assign(&c2_c_y, sf_mex_createstructarray("structure", 2, c2_iv0, 4,
    c2_sv0), false);
  sf_mex_createfield(c2_c_y, "point1", "point1");
  sf_mex_createfield(c2_c_y, "point2", "point2");
  sf_mex_createfield(c2_c_y, "theta", "theta");
  sf_mex_createfield(c2_c_y, "rho", "rho");
  c2_i = 0;
  for (c2_j1 = 0; c2_j1 < c2_e_u->size[1U]; c2_j1++) {
    for (c2_i96 = 0; c2_i96 < 2; c2_i96++) {
      c2_f_u[c2_i96] = c2_e_u->data[c2_j1].point1[c2_i96];
    }

    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_f_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  false);
    sf_mex_setfieldbynum(c2_c_y, c2_i, "point1", c2_d_y, 0);
    for (c2_i97 = 0; c2_i97 < 2; c2_i97++) {
      c2_f_u[c2_i97] = c2_e_u->data[c2_j1].point2[c2_i97];
    }

    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_f_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  false);
    sf_mex_setfieldbynum(c2_c_y, c2_i, "point2", c2_e_y, 1);
    c2_g_u = c2_e_u->data[c2_j1].theta;
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0), false);
    sf_mex_setfieldbynum(c2_c_y, c2_i, "theta", c2_f_y, 2);
    c2_h_u = c2_e_u->data[c2_j1].rho;
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_h_u, 0, 0U, 0U, 0U, 0), false);
    sf_mex_setfieldbynum(c2_c_y, c2_i, "rho", c2_g_y, 3);
    c2_i++;
  }

  c2_emxFree_skoeQIuVNKJRHNtBIlOCZhD(chartInstance, &c2_e_u);
  sf_mex_assign(&c2_mxArrayOutData, c2_c_y, false);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_e_u, const emlrtMsgIdentifier *c2_parentId,
  c2_emxArray_skoeQIuVNKJRHNtBIlOCZh *c2_c_y)
{
  int32_T c2_i98;
  int32_T c2_i99;
  uint32_T c2_uv3[2];
  emlrtMsgIdentifier c2_thisId;
  uint32_T c2_uv4[2];
  int32_T c2_i100;
  static const char * c2_fieldNames[4] = { "point1", "point2", "theta", "rho" };

  boolean_T c2_bv4[2];
  static boolean_T c2_bv5[2] = { false, true };

  int32_T c2_i101;
  int32_T c2_n;
  int32_T c2_i102;
  int32_T c2_b_n[1];
  int32_T c2_c_n[1];
  for (c2_i98 = 0; c2_i98 < 2; c2_i98++) {
    c2_uv3[c2_i98] = 1U + 4294967294U * (uint32_T)c2_i98;
  }

  for (c2_i99 = 0; c2_i99 < 2; c2_i99++) {
    c2_uv4[c2_i99] = 1U + 4294967294U * (uint32_T)c2_i99;
  }

  c2_thisId.fParent = c2_parentId;
  c2_thisId.bParentIsCell = false;
  for (c2_i100 = 0; c2_i100 < 2; c2_i100++) {
    c2_bv4[c2_i100] = c2_bv5[c2_i100];
  }

  sf_mex_check_struct_vs(c2_parentId, c2_e_u, 4, c2_fieldNames, 2U, c2_bv4,
    c2_uv3, c2_uv4);
  c2_i101 = c2_c_y->size[0] * c2_c_y->size[1];
  c2_c_y->size[0] = (int32_T)c2_uv4[0];
  c2_c_y->size[1] = (int32_T)c2_uv4[1];
  c2_emxEnsureCapacity_skoeQIuVNKJRH(chartInstance, c2_c_y, c2_i101,
    (emlrtRTEInfo *)NULL);
  c2_n = c2_c_y->size[1];
  for (c2_i102 = 0; c2_i102 < c2_n; c2_i102++) {
    c2_thisId.fIdentifier = "point1";
    c2_b_n[0] = c2_n;
    c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_e_u,
      "point1", "point1", c2_i102)), &c2_thisId, c2_c_y->data[c2_i102].point1);
    c2_thisId.fIdentifier = "point2";
    c2_c_n[0] = c2_n;
    c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_e_u,
      "point2", "point2", c2_i102)), &c2_thisId, c2_c_y->data[c2_i102].point2);
    c2_thisId.fIdentifier = "theta";
    c2_c_y->data[c2_i102].theta = c2_g_emlrt_marshallIn(chartInstance,
      sf_mex_dup(sf_mex_getfield(c2_e_u, "theta", "theta", c2_i102)), &c2_thisId);
    c2_thisId.fIdentifier = "rho";
    c2_c_y->data[c2_i102].rho = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c2_e_u, "rho", "rho", c2_i102)), &c2_thisId);
  }

  sf_mex_destroy(&c2_e_u);
}

static void c2_f_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_e_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_c_y[2])
{
  real_T c2_dv4[2];
  int32_T c2_i103;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_e_u), c2_dv4, 1, 0, 0U, 1, 0U, 2, 1,
                2);
  for (c2_i103 = 0; c2_i103 < 2; c2_i103++) {
    c2_c_y[c2_i103] = c2_dv4[c2_i103];
  }

  sf_mex_destroy(&c2_e_u);
}

static real_T c2_g_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_e_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_c_y;
  real_T c2_d4;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_e_u), &c2_d4, 1, 0, 0U, 0, 0U, 0);
  c2_c_y = c2_d4;
  sf_mex_destroy(&c2_e_u);
  return c2_c_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName,
  c2_emxArray_skoeQIuVNKJRHNtBIlOCZh *c2_outData)
{
  c2_emxArray_skoeQIuVNKJRHNtBIlOCZh *c2_c_y;
  const mxArray *c2_lines;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_i104;
  int32_T c2_loop_ub;
  int32_T c2_i105;
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_emxInit_skoeQIuVNKJRHNtBIlOCZhD(chartInstance, &c2_c_y, 2, (emlrtRTEInfo *)
    NULL);
  c2_lines = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_lines), &c2_thisId, c2_c_y);
  sf_mex_destroy(&c2_lines);
  c2_i104 = c2_outData->size[0] * c2_outData->size[1];
  c2_outData->size[0] = 1;
  c2_outData->size[1] = c2_c_y->size[1];
  c2_emxEnsureCapacity_skoeQIuVNKJRH(chartInstance, c2_outData, c2_i104,
    (emlrtRTEInfo *)NULL);
  c2_loop_ub = c2_c_y->size[1] - 1;
  for (c2_i105 = 0; c2_i105 <= c2_loop_ub; c2_i105++) {
    c2_outData->data[c2_i105] = c2_c_y->data[c2_i105];
  }

  c2_emxFree_skoeQIuVNKJRHNtBIlOCZhD(chartInstance, &c2_c_y);
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  real_T c2_e_u;
  const mxArray *c2_c_y = NULL;
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_e_u = *(real_T *)c2_inData;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_c_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_h_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_angle, const char_T *c2_identifier)
{
  real_T c2_c_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_c_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_angle), &c2_thisId);
  sf_mex_destroy(&c2_angle);
  return c2_c_y;
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_angle;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_c_y;
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_angle = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_c_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_angle), &c2_thisId);
  sf_mex_destroy(&c2_angle);
  *(real_T *)c2_outData = c2_c_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i106;
  int32_T c2_i107;
  const mxArray *c2_c_y = NULL;
  int32_T c2_i108;
  real_T c2_e_u[19200];
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i106 = 0;
  for (c2_i107 = 0; c2_i107 < 160; c2_i107++) {
    for (c2_i108 = 0; c2_i108 < 120; c2_i108++) {
      c2_e_u[c2_i108 + c2_i106] = (*(real_T (*)[19200])c2_inData)[c2_i108 +
        c2_i106];
    }

    c2_i106 += 120;
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_e_u, 0, 0U, 1U, 0U, 2, 120, 160),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_c_y, false);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static void c2_imhist(SFc2_flightControlSystemInstanceStruct *chartInstance,
                      uint8_T c2_h_varargin_1[19200], real_T c2_yout[256])
{
  real_T c2_b_out;
  int32_T c2_i109;
  int32_T c2_i110;
  int32_T c2_i111;
  real_T c2_localBins1[256];
  int32_T c2_i112;
  real_T c2_localBins2[256];
  int32_T c2_i;
  real_T c2_localBins3[256];
  int32_T c2_idx1;
  int32_T c2_idx2;
  int32_T c2_b_i;
  int32_T c2_b_idx;
  int32_T c2_idx3;
  int32_T c2_l_a;
  int32_T c2_idx4;
  real_T c2_c_i;
  int32_T c2_c;
  int32_T c2_m_a;
  int32_T c2_n_a;
  int32_T c2_b_c;
  int32_T c2_c_c;
  int32_T c2_o_a;
  int32_T c2_d_c;
  int32_T c2_p_a;
  int32_T c2_e_c;
  int32_T c2_q_a;
  int32_T c2_f_c;
  int32_T c2_r_a;
  int32_T c2_g_c;
  int32_T c2_s_a;
  int32_T c2_h_c;
  int32_T c2_t_a;
  int32_T c2_i_c;
  int32_T c2_u_a;
  int32_T c2_j_c;
  c2_b_out = 1.0;
  getnumcores(&c2_b_out);
  for (c2_i109 = 0; c2_i109 < 256; c2_i109++) {
    c2_yout[c2_i109] = 0.0;
  }

  for (c2_i110 = 0; c2_i110 < 256; c2_i110++) {
    c2_localBins1[c2_i110] = 0.0;
  }

  for (c2_i111 = 0; c2_i111 < 256; c2_i111++) {
    c2_localBins2[c2_i111] = 0.0;
  }

  for (c2_i112 = 0; c2_i112 < 256; c2_i112++) {
    c2_localBins3[c2_i112] = 0.0;
  }

  for (c2_i = 4; c2_i <= 19200; c2_i += 4) {
    c2_idx1 = c2_h_varargin_1[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       c2_i - 3, 1, 19200) - 1];
    c2_idx2 = c2_h_varargin_1[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       c2_i - 2, 1, 19200) - 1];
    c2_idx3 = c2_h_varargin_1[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       c2_i - 1, 1, 19200) - 1];
    c2_idx4 = c2_h_varargin_1[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       c2_i, 1, 19200) - 1];
    c2_m_a = c2_idx1;
    c2_b_c = c2_m_a;
    c2_o_a = c2_idx1;
    c2_d_c = c2_o_a;
    c2_localBins1[c2_b_c] = c2_localBins1[c2_d_c] + 1.0;
    c2_p_a = c2_idx2;
    c2_e_c = c2_p_a;
    c2_q_a = c2_idx2;
    c2_f_c = c2_q_a;
    c2_localBins2[c2_e_c] = c2_localBins2[c2_f_c] + 1.0;
    c2_r_a = c2_idx3;
    c2_g_c = c2_r_a;
    c2_s_a = c2_idx3;
    c2_h_c = c2_s_a;
    c2_localBins3[c2_g_c] = c2_localBins3[c2_h_c] + 1.0;
    c2_t_a = c2_idx4;
    c2_i_c = c2_t_a;
    c2_u_a = c2_idx4;
    c2_j_c = c2_u_a;
    c2_yout[c2_i_c] = c2_yout[c2_j_c] + 1.0;
  }

  while (c2_i - 3 <= 19200) {
    c2_b_idx = c2_h_varargin_1[c2_i - 4];
    c2_l_a = c2_b_idx;
    c2_c = c2_l_a;
    c2_n_a = c2_b_idx;
    c2_c_c = c2_n_a;
    c2_yout[c2_c] = c2_yout[c2_c_c] + 1.0;
    c2_i++;
  }

  for (c2_b_i = 0; c2_b_i < 256; c2_b_i++) {
    c2_c_i = 1.0 + (real_T)c2_b_i;
    c2_yout[(int32_T)c2_c_i - 1] = ((c2_yout[(int32_T)c2_c_i - 1] +
      c2_localBins1[(int32_T)c2_c_i - 1]) + c2_localBins2[(int32_T)c2_c_i - 1])
      + c2_localBins3[(int32_T)c2_c_i - 1];
  }
}

static void c2_validateattributes(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real_T c2_l_a[256])
{
  boolean_T c2_p;
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_d_x;
  boolean_T c2_b0;
  real_T c2_e_x;
  boolean_T c2_b;
  boolean_T c2_b1;
  const mxArray *c2_c_y = NULL;
  real_T c2_f_x;
  static char_T c2_cv13[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'o', 't', 's',
    'u', 't', 'h', 'r', 'e', 's', 'h', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'F', 'i', 'n', 'i', 't', 'e' };

  boolean_T c2_b_b;
  const mxArray *c2_d_y = NULL;
  boolean_T c2_b2;
  boolean_T c2_c_b;
  const mxArray *c2_e_y = NULL;
  static char_T c2_cv14[6] = { 'C', 'O', 'U', 'N', 'T', 'S' };

  boolean_T exitg1;
  (void)chartInstance;
  c2_p = true;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k < 256)) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_d_x = c2_l_a[(int32_T)c2_b_k - 1];
    c2_e_x = c2_d_x;
    c2_b = muDoubleScalarIsInf(c2_e_x);
    c2_b1 = !c2_b;
    c2_f_x = c2_d_x;
    c2_b_b = muDoubleScalarIsNaN(c2_f_x);
    c2_b2 = !c2_b_b;
    c2_c_b = (c2_b1 && c2_b2);
    if (c2_c_b) {
      c2_k++;
    } else {
      c2_p = false;
      exitg1 = true;
    }
  }

  if (c2_p) {
    c2_b0 = true;
  } else {
    c2_b0 = false;
  }

  if (c2_b0) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv13, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv14, 10, 0U, 1U, 0U, 2, 1, 6),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c2_d_y, 14, c2_e_y)));
  }
}

static boolean_T c2_isfinite(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real_T c2_d_x)
{
  real_T c2_e_x;
  boolean_T c2_b_b;
  boolean_T c2_b3;
  real_T c2_f_x;
  boolean_T c2_c_b;
  boolean_T c2_b4;
  (void)chartInstance;
  c2_e_x = c2_d_x;
  c2_b_b = muDoubleScalarIsInf(c2_e_x);
  c2_b3 = !c2_b_b;
  c2_f_x = c2_d_x;
  c2_c_b = muDoubleScalarIsNaN(c2_f_x);
  c2_b4 = !c2_c_b;
  return c2_b3 && c2_b4;
}

static void c2_edge(SFc2_flightControlSystemInstanceStruct *chartInstance,
                    boolean_T c2_h_varargin_1[19200], boolean_T c2_varargout_1
                    [19200])
{
  int32_T c2_i113;
  int32_T c2_i114;
  int32_T c2_i115;
  real_T c2_derivGaussKernel[13];
  static real_T c2_dv5[13] = { 0.00050975920363612861, 0.0025659736304223,
    0.014594040963812248, 0.049305200293708981, 0.09498179875488523,
    0.089159205155936727, 0.0, -0.089159205155936727, -0.09498179875488523,
    -0.049305200293708981, -0.014594040963812248, -0.0025659736304223,
    -0.00050975920363612861 };

  int32_T c2_i116;
  static real_T c2_dv6[6] = { 0.0020299751839417141, 0.010218281014351701,
    0.058116735860084041, 0.19634433732941295, 0.37823877042972093,
    0.35505190018248872 };

  real_T c2_c_y;
  real_T c2_d_x[6];
  int32_T c2_k;
  real_T c2_e_x;
  int32_T c2_xoffset;
  real_T c2_f_x;
  int32_T c2_ix;
  real_T c2_g_x;
  real_T c2_d_y;
  int32_T c2_i117;
  int32_T c2_i118;
  real_T c2_b_derivGaussKernel[6];
  int32_T c2_i119;
  int32_T c2_i120;
  int32_T c2_i121;
  real_T c2_c_derivGaussKernel[13];
  int32_T c2_i122;
  int32_T c2_b_k;
  int32_T c2_i123;
  int32_T c2_c_k;
  real32_T c2_h_x;
  real32_T c2_i_x;
  real32_T c2_e_y;
  real32_T c2_j_x;
  real32_T c2_x1;
  boolean_T c2_b;
  real32_T c2_x2;
  boolean_T c2_p;
  real32_T c2_z;
  int32_T c2_b_idx;
  int32_T c2_d_k;
  int32_T c2_first;
  real32_T c2_magmax;
  real32_T c2_k_x;
  real32_T c2_ex;
  real32_T c2_l_x;
  int32_T c2_i124;
  boolean_T c2_b_b;
  int32_T c2_e_k;
  real32_T c2_f_y;
  boolean_T c2_b_p;
  real_T c2_b_out;
  real32_T c2_g_y;
  int32_T c2_i125;
  int32_T c2_i126;
  boolean_T c2_nanFlag;
  real_T c2_counts[64];
  int32_T c2_i;
  real_T c2_b_i;
  real32_T c2_m_x;
  int32_T c2_f_k;
  boolean_T c2_c_b;
  int32_T c2_i127;
  int32_T c2_g_k;
  real32_T c2_c_idx;
  int32_T c2_d_idx;
  boolean_T c2_n_x[64];
  int32_T c2_ii_size[1];
  real32_T c2_o_x;
  int32_T c2_ii;
  boolean_T c2_d_b;
  real32_T c2_l_a;
  int32_T c2_b_ii;
  int32_T c2_c;
  real32_T c2_m_a;
  int32_T c2_i128;
  int32_T c2_b_c;
  int32_T c2_highThreshTemp_size[1];
  int32_T c2_ii_data[1];
  int32_T c2_loop_ub;
  int32_T c2_i129;
  real_T c2_highThreshTemp_data[1];
  int32_T c2_b_loop_ub;
  int32_T c2_i130;
  real_T c2_d5;
  int32_T c2_i131;
  int32_T c2_i132;
  int32_T c2_lowThresh_size[1];
  int32_T c2_b_size[1];
  int32_T c2_c_loop_ub;
  int32_T c2_i133;
  real_T c2_lowThresh;
  real_T c2_lowThresh_data[1];
  real_T c2_b_data[1];
  real_T c2_b_lowThresh;
  int32_T c2_i134;
  int32_T c2_i135;
  real_T c2_szT[2];
  real_T c2_highThreshTemp;
  int32_T c2_i136;
  int32_T c2_i137;
  boolean_T c2_p_x[19200];
  c2_emxArray_int32_T *c2_c_ii;
  c2_emxArray_int32_T *c2_jj;
  c2_emxArray_real_T *c2_c_c;
  int32_T c2_i138;
  int32_T c2_d_loop_ub;
  int32_T c2_i139;
  c2_emxArray_real_T *c2_badPix;
  int32_T c2_i140;
  int32_T c2_e_loop_ub;
  int32_T c2_i141;
  int32_T c2_i142;
  c2_emxArray_real_T *c2_ndx;
  int32_T c2_i143;
  int32_T c2_f_loop_ub;
  int32_T c2_i144;
  c2_emxArray_real_T *c2_r;
  int32_T c2_i145;
  int32_T c2_g_loop_ub;
  int32_T c2_i146;
  int32_T c2_i147;
  int32_T c2_h_loop_ub;
  int32_T c2_i148;
  int32_T c2_i149;
  int32_T c2_i_loop_ub;
  int32_T c2_i150;
  int32_T c2_x_size[1];
  int32_T c2_j_loop_ub;
  int32_T c2_i151;
  int32_T c2_tmp_size[1];
  boolean_T c2_x_data[19200];
  int32_T c2_k_loop_ub;
  int32_T c2_i152;
  boolean_T c2_tmp_data[19200];
  int32_T c2_l_loop_ub;
  int32_T c2_i153;
  int32_T c2_m_loop_ub;
  int32_T c2_i154;
  int32_T c2_n_loop_ub;
  int32_T c2_i155;
  int32_T c2_o_loop_ub;
  int32_T c2_i156;
  int32_T c2_p_loop_ub;
  int32_T c2_i157;
  int32_T c2_nx;
  int32_T c2_h_k;
  int32_T c2_b_nx;
  int32_T c2_e_idx;
  int32_T c2_i158;
  int32_T c2_e_b;
  int32_T c2_f_b;
  boolean_T c2_overflow;
  int32_T c2_d_ii;
  int32_T c2_e_ii;
  boolean_T c2_b5;
  int32_T c2_i159;
  int32_T c2_i160;
  int32_T c2_i161;
  int32_T c2_i162;
  int32_T c2_q_loop_ub;
  int32_T c2_r_loop_ub;
  int32_T c2_i163;
  int32_T c2_i164;
  int32_T c2_iv1[2];
  c2_emxArray_int32_T *c2_b_badPix;
  int32_T c2_i165;
  int32_T c2_i166;
  int32_T c2_i167;
  int32_T c2_s_loop_ub;
  int32_T c2_i168;
  int32_T c2_t_loop_ub;
  int32_T c2_i169;
  c2_emxArray_real_T *c2_varargin_2;
  c2_emxArray_int32_T *c2_c_badPix;
  int32_T c2_i170;
  int32_T c2_i171;
  int32_T c2_u_loop_ub;
  int32_T c2_i172;
  int32_T c2_v_loop_ub;
  c2_emxArray_int32_T *c2_f_idx;
  int32_T c2_i173;
  c2_emxArray_real_T *c2_b_ndx;
  int32_T c2_i174;
  int32_T c2_w_loop_ub;
  int32_T c2_i175;
  const mxArray *c2_h_y = NULL;
  const mxArray *c2_i_y = NULL;
  real_T c2_b_varargin_2[2];
  int32_T c2_i176;
  int32_T c2_i177;
  int32_T c2_i178;
  boolean_T c2_c_p;
  int32_T c2_i179;
  boolean_T c2_d_p;
  int32_T c2_i_k;
  real_T c2_j_k;
  real_T c2_b_x1;
  real_T c2_b_x2;
  boolean_T c2_e_p;
  const mxArray *c2_j_y = NULL;
  c2_emxArray_real_T *c2_c_varargin_2;
  const mxArray *c2_k_y = NULL;
  int32_T c2_i180;
  int32_T c2_x_loop_ub;
  int32_T c2_i181;
  const mxArray *c2_l_y = NULL;
  const mxArray *c2_m_y = NULL;
  int32_T c2_i182;
  int32_T c2_y_loop_ub;
  int32_T c2_i183;
  c2_emxArray_int32_T *c2_g_b;
  int32_T c2_i184;
  int32_T c2_ab_loop_ub;
  int32_T c2_i185;
  int32_T c2_i186;
  int32_T c2_bb_loop_ub;
  int32_T c2_i187;
  int32_T c2_i188;
  int32_T c2_cb_loop_ub;
  int32_T c2_i189;
  int32_T c2_i190;
  int32_T c2_db_loop_ub;
  int32_T c2_i191;
  int32_T c2_i192;
  int32_T c2_eb_loop_ub;
  int32_T c2_i193;
  int32_T c2_i194;
  boolean_T c2_b_E[19200];
  int32_T c2_i195;
  int32_T c2_g_idx;
  int32_T c2_f_ii;
  int32_T c2_g_ii;
  boolean_T c2_b6;
  int32_T c2_i196;
  int32_T c2_i197;
  int32_T c2_fb_loop_ub;
  int32_T c2_i198;
  int32_T c2_iv2[2];
  boolean_T exitg1;
  for (c2_i113 = 0; c2_i113 < 19200; c2_i113++) {
    chartInstance->c2_e_a[c2_i113] = (real32_T)c2_h_varargin_1[c2_i113];
  }

  for (c2_i114 = 0; c2_i114 < 13; c2_i114++) {
    c2_derivGaussKernel[c2_i114] = c2_dv5[c2_i114];
  }

  for (c2_i115 = 0; c2_i115 < 6; c2_i115++) {
    c2_derivGaussKernel[c2_i115] = c2_dv6[c2_i115];
  }

  for (c2_i116 = 0; c2_i116 < 6; c2_i116++) {
    c2_d_x[c2_i116] = c2_derivGaussKernel[c2_i116 + 7];
  }

  c2_c_y = c2_d_x[0];
  for (c2_k = 0; c2_k < 5; c2_k++) {
    c2_xoffset = c2_k;
    c2_ix = c2_xoffset + 1;
    c2_c_y += c2_d_x[c2_ix];
  }

  c2_e_x = c2_c_y;
  c2_f_x = c2_e_x;
  c2_g_x = c2_f_x;
  c2_d_y = muDoubleScalarAbs(c2_g_x);
  for (c2_i117 = 0; c2_i117 < 6; c2_i117++) {
    c2_b_derivGaussKernel[c2_i117] = c2_derivGaussKernel[c2_i117 + 7] / c2_d_y;
  }

  for (c2_i118 = 0; c2_i118 < 6; c2_i118++) {
    c2_derivGaussKernel[c2_i118 + 7] = c2_b_derivGaussKernel[c2_i118];
  }

  for (c2_i119 = 0; c2_i119 < 19200; c2_i119++) {
    chartInstance->c2_f_a[c2_i119] = chartInstance->c2_e_a[c2_i119];
  }

  c2_imfilter(chartInstance, chartInstance->c2_f_a, chartInstance->c2_i1);
  for (c2_i120 = 0; c2_i120 < 19200; c2_i120++) {
    chartInstance->c2_b_i1[c2_i120] = chartInstance->c2_i1[c2_i120];
  }

  for (c2_i121 = 0; c2_i121 < 13; c2_i121++) {
    c2_c_derivGaussKernel[c2_i121] = c2_derivGaussKernel[c2_i121];
  }

  c2_b_imfilter(chartInstance, chartInstance->c2_b_i1, c2_c_derivGaussKernel,
                chartInstance->c2_i1);
  c2_c_imfilter(chartInstance, chartInstance->c2_e_a, chartInstance->c2_i2);
  for (c2_i122 = 0; c2_i122 < 19200; c2_i122++) {
    chartInstance->c2_b_i2[c2_i122] = chartInstance->c2_i2[c2_i122];
  }

  c2_d_imfilter(chartInstance, chartInstance->c2_b_i2, c2_derivGaussKernel,
                chartInstance->c2_i2);
  for (c2_b_k = 0; c2_b_k < 19200; c2_b_k++) {
    c2_c_k = c2_b_k;
    c2_h_x = chartInstance->c2_i1[c2_c_k];
    c2_e_y = chartInstance->c2_i2[c2_c_k];
    c2_x1 = c2_h_x;
    c2_x2 = c2_e_y;
    c2_z = muSingleScalarHypot(c2_x1, c2_x2);
    chartInstance->c2_e_a[c2_c_k] = c2_z;
  }

  for (c2_i123 = 0; c2_i123 < 19200; c2_i123++) {
    chartInstance->c2_c_varargin_1[c2_i123] = chartInstance->c2_e_a[c2_i123];
  }

  c2_i_x = chartInstance->c2_c_varargin_1[0];
  c2_j_x = c2_i_x;
  c2_b = muSingleScalarIsNaN(c2_j_x);
  c2_p = !c2_b;
  if (c2_p) {
    c2_b_idx = 1;
  } else {
    c2_b_idx = 0;
    c2_d_k = 2;
    exitg1 = false;
    while ((!exitg1) && (c2_d_k < 19201)) {
      c2_k_x = chartInstance->c2_c_varargin_1[c2_d_k - 1];
      c2_l_x = c2_k_x;
      c2_b_b = muSingleScalarIsNaN(c2_l_x);
      c2_b_p = !c2_b_b;
      if (c2_b_p) {
        c2_b_idx = c2_d_k;
        exitg1 = true;
      } else {
        c2_d_k++;
      }
    }
  }

  if (c2_b_idx == 0) {
    c2_magmax = chartInstance->c2_c_varargin_1[0];
  } else {
    c2_first = c2_b_idx;
    c2_ex = chartInstance->c2_c_varargin_1[c2_first - 1];
    c2_i124 = c2_first;
    for (c2_e_k = c2_i124; c2_e_k + 1 < 19201; c2_e_k++) {
      if (c2_ex < chartInstance->c2_c_varargin_1[c2_e_k]) {
        c2_ex = chartInstance->c2_c_varargin_1[c2_e_k];
      }
    }

    c2_magmax = c2_ex;
  }

  if (c2_magmax > 0.0F) {
    c2_f_y = c2_magmax;
    c2_g_y = c2_f_y;
    for (c2_i125 = 0; c2_i125 < 19200; c2_i125++) {
      chartInstance->c2_e_a[c2_i125] /= c2_g_y;
    }
  }

  c2_b_out = 1.0;
  getnumcores(&c2_b_out);
  for (c2_i126 = 0; c2_i126 < 64; c2_i126++) {
    c2_counts[c2_i126] = 0.0;
  }

  c2_nanFlag = false;
  for (c2_i = 0; c2_i < 19200; c2_i++) {
    c2_b_i = 1.0 + (real_T)c2_i;
    c2_m_x = chartInstance->c2_e_a[(int32_T)c2_b_i - 1];
    c2_c_b = muSingleScalarIsNaN(c2_m_x);
    if (c2_c_b) {
      c2_nanFlag = true;
      c2_c_idx = 0.0F;
    } else {
      c2_c_idx = chartInstance->c2_e_a[(int32_T)c2_b_i - 1] * 63.0F + 0.5F;
    }

    if (c2_c_idx > 63.0F) {
      c2_counts[63]++;
    } else {
      c2_o_x = chartInstance->c2_e_a[(int32_T)c2_b_i - 1];
      c2_d_b = muSingleScalarIsInf(c2_o_x);
      if (c2_d_b) {
        c2_counts[63]++;
      } else {
        c2_l_a = c2_c_idx;
        c2_c = (int32_T)c2_l_a;
        c2_m_a = c2_c_idx;
        c2_b_c = (int32_T)c2_m_a;
        c2_counts[c2_c] = c2_counts[c2_b_c] + 1.0;
      }
    }
  }

  if (c2_nanFlag) {
    c2_warning(chartInstance);
  }

  for (c2_f_k = 0; c2_f_k < 63; c2_f_k++) {
    c2_g_k = c2_f_k;
    c2_counts[c2_g_k + 1] += c2_counts[c2_g_k];
  }

  for (c2_i127 = 0; c2_i127 < 64; c2_i127++) {
    c2_n_x[c2_i127] = (c2_counts[c2_i127] > 13440.0);
  }

  c2_d_idx = 0;
  c2_ii_size[0] = 1;
  c2_ii = 1;
  exitg1 = false;
  while ((!exitg1) && (c2_ii - 1 < 64)) {
    c2_b_ii = c2_ii;
    if (c2_n_x[c2_b_ii - 1]) {
      c2_d_idx = 1;
      c2_ii_data[0] = c2_b_ii;
      exitg1 = true;
    } else {
      c2_ii++;
    }
  }

  if (c2_d_idx == 0) {
    c2_i128 = c2_ii_size[0];
    c2_ii_size[0] = 0;
  }

  c2_highThreshTemp_size[0] = c2_ii_size[0];
  c2_loop_ub = c2_ii_size[0] - 1;
  for (c2_i129 = 0; c2_i129 <= c2_loop_ub; c2_i129++) {
    c2_highThreshTemp_data[c2_i129] = (real_T)c2_ii_data[c2_i129];
  }

  c2_highThreshTemp_size[0];
  c2_b_loop_ub = c2_highThreshTemp_size[0] - 1;
  for (c2_i130 = 0; c2_i130 <= c2_b_loop_ub; c2_i130++) {
    c2_highThreshTemp_data[c2_i130] /= 64.0;
  }

  if (c2_highThreshTemp_size[0] == 0) {
    c2_i131 = c2_highThreshTemp_size[0];
    c2_highThreshTemp_size[0] = 0;
    c2_i132 = c2_lowThresh_size[0];
    c2_lowThresh_size[0] = 0;
  } else {
    c2_d5 = c2_highThreshTemp_data[0];
    c2_highThreshTemp_size[0] = 1;
    c2_highThreshTemp_data[0] = c2_d5;
    c2_b_size[0] = c2_highThreshTemp_size[0];
    c2_c_loop_ub = c2_highThreshTemp_size[0] - 1;
    for (c2_i133 = 0; c2_i133 <= c2_c_loop_ub; c2_i133++) {
      c2_b_data[c2_i133] = c2_highThreshTemp_data[c2_i133];
    }

    c2_b_size[0] = 1;
    c2_b_data[0] *= 0.4;
    c2_lowThresh_size[0] = 1;
    c2_lowThresh_data[0] = c2_b_data[0];
  }

  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_lowThresh_size[0]);
  c2_lowThresh = c2_lowThresh_data[0];
  c2_b_lowThresh = c2_lowThresh;
  for (c2_i134 = 0; c2_i134 < 19200; c2_i134++) {
    chartInstance->c2_E[c2_i134] = false;
  }

  for (c2_i135 = 0; c2_i135 < 2; c2_i135++) {
    c2_szT[c2_i135] = 120.0 + 40.0 * (real_T)c2_i135;
  }

  cannythresholding_real32_tbb(chartInstance->c2_i1, chartInstance->c2_i2,
    chartInstance->c2_e_a, c2_szT, c2_b_lowThresh, chartInstance->c2_E);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_highThreshTemp_size[0]);
  c2_highThreshTemp = c2_highThreshTemp_data[0];
  for (c2_i136 = 0; c2_i136 < 19200; c2_i136++) {
    c2_p_x[c2_i136] = ((real_T)chartInstance->c2_e_a[c2_i136] >
                       c2_highThreshTemp);
  }

  for (c2_i137 = 0; c2_i137 < 19200; c2_i137++) {
    c2_p_x[c2_i137] = (c2_p_x[c2_i137] && chartInstance->c2_E[c2_i137]);
  }

  c2_emxInit_int32_T(chartInstance, &c2_c_ii, 1, &c2_nb_emlrtRTEI);
  c2_emxInit_int32_T(chartInstance, &c2_jj, 1, &c2_ab_emlrtRTEI);
  c2_emxInit_real_T1(chartInstance, &c2_c_c, 1, &c2_pb_emlrtRTEI);
  c2_eml_find(chartInstance, c2_p_x, c2_c_ii, c2_jj);
  c2_i138 = c2_c_c->size[0];
  c2_c_c->size[0] = c2_c_ii->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_c_c, c2_i138, &c2_n_emlrtRTEI);
  c2_d_loop_ub = c2_c_ii->size[0] - 1;
  for (c2_i139 = 0; c2_i139 <= c2_d_loop_ub; c2_i139++) {
    c2_c_c->data[c2_i139] = (real_T)c2_c_ii->data[c2_i139];
  }

  c2_emxInit_real_T1(chartInstance, &c2_badPix, 1, &c2_y_emlrtRTEI);
  c2_i140 = c2_badPix->size[0];
  c2_badPix->size[0] = c2_jj->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_badPix, c2_i140,
    &c2_o_emlrtRTEI);
  c2_e_loop_ub = c2_jj->size[0] - 1;
  for (c2_i141 = 0; c2_i141 <= c2_e_loop_ub; c2_i141++) {
    c2_badPix->data[c2_i141] = (real_T)c2_jj->data[c2_i141];
  }

  if (c2_badPix->size[0] != 0) {
    c2_emxInit_real_T1(chartInstance, &c2_ndx, 1, &c2_qb_emlrtRTEI);
    c2_i143 = c2_ndx->size[0];
    c2_ndx->size[0] = c2_c_c->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_ndx, c2_i143, &c2_p_emlrtRTEI);
    c2_f_loop_ub = c2_c_c->size[0] - 1;
    for (c2_i144 = 0; c2_i144 <= c2_f_loop_ub; c2_i144++) {
      c2_ndx->data[c2_i144] = c2_c_c->data[c2_i144];
    }

    c2_emxInit_real_T1(chartInstance, &c2_r, 1, &c2_ob_emlrtRTEI);
    c2_b_round(chartInstance, c2_ndx);
    c2_i145 = c2_r->size[0];
    c2_r->size[0] = c2_ndx->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_r, c2_i145, &c2_q_emlrtRTEI);
    c2_g_loop_ub = c2_ndx->size[0] - 1;
    for (c2_i146 = 0; c2_i146 <= c2_g_loop_ub; c2_i146++) {
      c2_r->data[c2_i146] = c2_ndx->data[c2_i146];
    }

    c2_i147 = c2_ndx->size[0];
    c2_ndx->size[0] = c2_badPix->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_ndx, c2_i147, &c2_r_emlrtRTEI);
    c2_h_loop_ub = c2_badPix->size[0] - 1;
    for (c2_i148 = 0; c2_i148 <= c2_h_loop_ub; c2_i148++) {
      c2_ndx->data[c2_i148] = c2_badPix->data[c2_i148];
    }

    c2_b_round(chartInstance, c2_ndx);
    c2_i149 = c2_c_c->size[0];
    c2_c_c->size[0] = c2_ndx->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_c_c, c2_i149, &c2_s_emlrtRTEI);
    c2_i_loop_ub = c2_ndx->size[0] - 1;
    for (c2_i150 = 0; c2_i150 <= c2_i_loop_ub; c2_i150++) {
      c2_c_c->data[c2_i150] = c2_ndx->data[c2_i150];
    }

    c2_x_size[0] = c2_r->size[0];
    c2_j_loop_ub = c2_r->size[0] - 1;
    for (c2_i151 = 0; c2_i151 <= c2_j_loop_ub; c2_i151++) {
      c2_x_data[c2_i151] = (c2_r->data[c2_i151] < 1.0);
    }

    c2_tmp_size[0] = c2_r->size[0];
    c2_k_loop_ub = c2_r->size[0] - 1;
    for (c2_i152 = 0; c2_i152 <= c2_k_loop_ub; c2_i152++) {
      c2_tmp_data[c2_i152] = (c2_r->data[c2_i152] > 120.0);
    }

    _SFD_SIZE_EQ_CHECK_1D(c2_x_size[0], c2_tmp_size[0]);
    c2_x_size[0];
    c2_l_loop_ub = c2_x_size[0] - 1;
    for (c2_i153 = 0; c2_i153 <= c2_l_loop_ub; c2_i153++) {
      c2_x_data[c2_i153] = (c2_x_data[c2_i153] || c2_tmp_data[c2_i153]);
    }

    c2_tmp_size[0] = c2_c_c->size[0];
    c2_m_loop_ub = c2_c_c->size[0] - 1;
    for (c2_i154 = 0; c2_i154 <= c2_m_loop_ub; c2_i154++) {
      c2_tmp_data[c2_i154] = (c2_c_c->data[c2_i154] < 1.0);
    }

    _SFD_SIZE_EQ_CHECK_1D(c2_x_size[0], c2_tmp_size[0]);
    c2_x_size[0];
    c2_n_loop_ub = c2_x_size[0] - 1;
    for (c2_i155 = 0; c2_i155 <= c2_n_loop_ub; c2_i155++) {
      c2_x_data[c2_i155] = (c2_x_data[c2_i155] || c2_tmp_data[c2_i155]);
    }

    c2_tmp_size[0] = c2_c_c->size[0];
    c2_o_loop_ub = c2_c_c->size[0] - 1;
    for (c2_i156 = 0; c2_i156 <= c2_o_loop_ub; c2_i156++) {
      c2_tmp_data[c2_i156] = (c2_c_c->data[c2_i156] > 160.0);
    }

    _SFD_SIZE_EQ_CHECK_1D(c2_x_size[0], c2_tmp_size[0]);
    c2_x_size[0];
    c2_p_loop_ub = c2_x_size[0] - 1;
    for (c2_i157 = 0; c2_i157 <= c2_p_loop_ub; c2_i157++) {
      c2_x_data[c2_i157] = (c2_x_data[c2_i157] || c2_tmp_data[c2_i157]);
    }

    c2_nx = c2_x_size[0];
    c2_h_k = c2_nx;
    c2_b_nx = c2_nx;
    c2_e_idx = 0;
    c2_i158 = c2_c_ii->size[0];
    c2_c_ii->size[0] = c2_h_k;
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_c_ii, c2_i158,
      &c2_g_emlrtRTEI);
    c2_e_b = c2_b_nx;
    c2_f_b = c2_e_b;
    if (1 > c2_f_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_f_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }

    c2_d_ii = 1;
    exitg1 = false;
    while ((!exitg1) && (c2_d_ii - 1 <= c2_b_nx - 1)) {
      c2_e_ii = c2_d_ii;
      if (c2_x_data[c2_e_ii - 1]) {
        c2_e_idx++;
        c2_c_ii->data[c2_e_idx - 1] = c2_e_ii;
        if (c2_e_idx >= c2_h_k) {
          exitg1 = true;
        } else {
          c2_d_ii++;
        }
      } else {
        c2_d_ii++;
      }
    }

    if (c2_e_idx <= c2_h_k) {
    } else {
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                        c2_emlrt_marshallOut(chartInstance, c2_cv1), 14,
                        sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "message", 1U, 1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv1))));
    }

    if (c2_h_k == 1) {
      if (c2_e_idx == 0) {
        c2_i159 = c2_c_ii->size[0];
        c2_c_ii->size[0] = 0;
      }
    } else {
      c2_b5 = (1 > c2_e_idx);
      if (c2_b5) {
        c2_i160 = 0;
      } else {
        c2_i160 = c2_e_idx;
      }

      c2_i162 = c2_jj->size[0];
      c2_jj->size[0] = c2_i160;
      c2_emxEnsureCapacity_int32_T(chartInstance, c2_jj, c2_i162,
        &c2_ab_emlrtRTEI);
      c2_r_loop_ub = c2_i160 - 1;
      for (c2_i164 = 0; c2_i164 <= c2_r_loop_ub; c2_i164++) {
        c2_jj->data[c2_i164] = 1 + c2_i164;
      }

      c2_iv1[0] = 1;
      c2_iv1[1] = c2_jj->size[0];
      c2_indexShapeCheck(chartInstance, c2_c_ii->size[0], c2_iv1);
      c2_i167 = c2_c_ii->size[0];
      c2_c_ii->size[0] = c2_i160;
      c2_emxEnsureCapacity_int32_T(chartInstance, c2_c_ii, c2_i167,
        &c2_db_emlrtRTEI);
    }

    c2_i161 = c2_badPix->size[0];
    c2_badPix->size[0] = c2_c_ii->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_badPix, c2_i161,
      &c2_y_emlrtRTEI);
    c2_q_loop_ub = c2_c_ii->size[0] - 1;
    for (c2_i163 = 0; c2_i163 <= c2_q_loop_ub; c2_i163++) {
      c2_badPix->data[c2_i163] = (real_T)c2_c_ii->data[c2_i163];
    }

    if (c2_badPix->size[0] != 0) {
      c2_emxInit_int32_T(chartInstance, &c2_b_badPix, 1, &c2_bb_emlrtRTEI);
      c2_b_warning(chartInstance);
      c2_i166 = c2_b_badPix->size[0];
      c2_b_badPix->size[0] = c2_badPix->size[0];
      c2_emxEnsureCapacity_int32_T(chartInstance, c2_b_badPix, c2_i166,
        &c2_bb_emlrtRTEI);
      c2_t_loop_ub = c2_badPix->size[0] - 1;
      for (c2_i169 = 0; c2_i169 <= c2_t_loop_ub; c2_i169++) {
        c2_b_badPix->data[c2_i169] = (int32_T)c2_badPix->data[c2_i169];
      }

      c2_emxInit_int32_T(chartInstance, &c2_c_badPix, 1, &c2_fb_emlrtRTEI);
      c2_d_nullAssignment(chartInstance, c2_r, c2_b_badPix);
      c2_i171 = c2_c_badPix->size[0];
      c2_c_badPix->size[0] = c2_badPix->size[0];
      c2_emxEnsureCapacity_int32_T(chartInstance, c2_c_badPix, c2_i171,
        &c2_fb_emlrtRTEI);
      c2_v_loop_ub = c2_badPix->size[0] - 1;
      c2_emxFree_int32_T(chartInstance, &c2_b_badPix);
      for (c2_i173 = 0; c2_i173 <= c2_v_loop_ub; c2_i173++) {
        c2_c_badPix->data[c2_i173] = (int32_T)c2_badPix->data[c2_i173];
      }

      c2_d_nullAssignment(chartInstance, c2_c_c, c2_c_badPix);
      c2_emxFree_int32_T(chartInstance, &c2_c_badPix);
    }

    c2_i165 = c2_ndx->size[0];
    c2_ndx->size[0] = c2_r->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_ndx, c2_i165,
      &c2_cb_emlrtRTEI);
    c2_s_loop_ub = c2_r->size[0] - 1;
    for (c2_i168 = 0; c2_i168 <= c2_s_loop_ub; c2_i168++) {
      c2_ndx->data[c2_i168] = c2_r->data[c2_i168];
    }

    c2_emxFree_real_T(chartInstance, &c2_r);
    c2_emxInit_real_T1(chartInstance, &c2_varargin_2, 1, &c2_eb_emlrtRTEI);
    c2_i170 = c2_varargin_2->size[0];
    c2_varargin_2->size[0] = c2_c_c->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_varargin_2, c2_i170,
      &c2_eb_emlrtRTEI);
    c2_u_loop_ub = c2_c_c->size[0] - 1;
    for (c2_i172 = 0; c2_i172 <= c2_u_loop_ub; c2_i172++) {
      c2_varargin_2->data[c2_i172] = c2_c_c->data[c2_i172];
    }

    c2_emxInit_int32_T(chartInstance, &c2_f_idx, 1, &c2_rb_emlrtRTEI);
    c2_emxInit_real_T1(chartInstance, &c2_b_ndx, 1, &c2_gb_emlrtRTEI);
    c2_i174 = c2_b_ndx->size[0];
    c2_b_ndx->size[0] = c2_ndx->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_b_ndx, c2_i174,
      &c2_gb_emlrtRTEI);
    c2_w_loop_ub = c2_ndx->size[0] - 1;
    for (c2_i175 = 0; c2_i175 <= c2_w_loop_ub; c2_i175++) {
      c2_b_ndx->data[c2_i175] = c2_ndx->data[c2_i175];
    }

    if (c2_allinrange(chartInstance, c2_b_ndx, 1.0, 120)) {
    } else {
      c2_h_y = NULL;
      sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      c2_i_y = NULL;
      sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_h_y,
                        14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "message", 1U, 1U, 14, c2_i_y)));
    }

    c2_emxFree_real_T(chartInstance, &c2_b_ndx);
    c2_szT[0] = (real_T)c2_ndx->size[0];
    c2_szT[1] = 1.0;
    c2_b_varargin_2[0] = (real_T)c2_varargin_2->size[0];
    c2_b_varargin_2[1] = 1.0;
    for (c2_i176 = 0; c2_i176 < 2; c2_i176++) {
      c2_szT[c2_i176];
    }

    for (c2_i177 = 0; c2_i177 < 2; c2_i177++) {
      c2_b_varargin_2[c2_i177];
    }

    for (c2_i178 = 0; c2_i178 < 2; c2_i178++) {
      c2_b_varargin_2[c2_i178];
    }

    c2_c_p = false;
    for (c2_i179 = 0; c2_i179 < 2; c2_i179++) {
      c2_b_varargin_2[c2_i179];
    }

    c2_d_p = true;
    c2_i_k = 0;
    exitg1 = false;
    while ((!exitg1) && (c2_i_k < 2)) {
      c2_j_k = 1.0 + (real_T)c2_i_k;
      c2_b_x1 = c2_szT[(int32_T)c2_j_k - 1];
      c2_b_x2 = c2_b_varargin_2[(int32_T)c2_j_k - 1];
      c2_e_p = (c2_b_x1 == c2_b_x2);
      if (!c2_e_p) {
        c2_d_p = false;
        exitg1 = true;
      } else {
        c2_i_k++;
      }
    }

    if (!c2_d_p) {
    } else {
      c2_c_p = true;
    }

    if (c2_c_p) {
    } else {
      c2_j_y = NULL;
      sf_mex_assign(&c2_j_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 34),
                    false);
      c2_k_y = NULL;
      sf_mex_assign(&c2_k_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 34),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_j_y,
                        14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "message", 1U, 1U, 14, c2_k_y)));
    }

    c2_emxInit_real_T1(chartInstance, &c2_c_varargin_2, 1, &c2_gb_emlrtRTEI);
    c2_i180 = c2_c_varargin_2->size[0];
    c2_c_varargin_2->size[0] = c2_varargin_2->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_c_varargin_2, c2_i180,
      &c2_gb_emlrtRTEI);
    c2_x_loop_ub = c2_varargin_2->size[0] - 1;
    for (c2_i181 = 0; c2_i181 <= c2_x_loop_ub; c2_i181++) {
      c2_c_varargin_2->data[c2_i181] = c2_varargin_2->data[c2_i181];
    }

    if (c2_allinrange(chartInstance, c2_c_varargin_2, 1.0, 160)) {
    } else {
      c2_l_y = NULL;
      sf_mex_assign(&c2_l_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      c2_m_y = NULL;
      sf_mex_assign(&c2_m_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_l_y,
                        14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "message", 1U, 1U, 14, c2_m_y)));
    }

    c2_emxFree_real_T(chartInstance, &c2_c_varargin_2);
    c2_i182 = c2_f_idx->size[0];
    c2_f_idx->size[0] = c2_ndx->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_f_idx, c2_i182,
      &c2_hb_emlrtRTEI);
    c2_y_loop_ub = c2_ndx->size[0] - 1;
    for (c2_i183 = 0; c2_i183 <= c2_y_loop_ub; c2_i183++) {
      c2_f_idx->data[c2_i183] = (int32_T)c2_ndx->data[c2_i183];
    }

    c2_emxInit_int32_T(chartInstance, &c2_g_b, 1, &c2_ib_emlrtRTEI);
    c2_i184 = c2_g_b->size[0];
    c2_g_b->size[0] = c2_varargin_2->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_g_b, c2_i184,
      &c2_ib_emlrtRTEI);
    c2_ab_loop_ub = c2_varargin_2->size[0] - 1;
    for (c2_i185 = 0; c2_i185 <= c2_ab_loop_ub; c2_i185++) {
      c2_g_b->data[c2_i185] = (int32_T)c2_varargin_2->data[c2_i185] - 1;
    }

    c2_emxFree_real_T(chartInstance, &c2_varargin_2);
    c2_i186 = c2_g_b->size[0];
    c2_g_b->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_g_b, c2_i186,
      &c2_jb_emlrtRTEI);
    c2_bb_loop_ub = c2_g_b->size[0] - 1;
    for (c2_i187 = 0; c2_i187 <= c2_bb_loop_ub; c2_i187++) {
      c2_g_b->data[c2_i187] *= 120;
    }

    c2_i188 = c2_f_idx->size[0];
    c2_f_idx->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_f_idx, c2_i188,
      &c2_kb_emlrtRTEI);
    c2_cb_loop_ub = c2_f_idx->size[0] - 1;
    for (c2_i189 = 0; c2_i189 <= c2_cb_loop_ub; c2_i189++) {
      c2_f_idx->data[c2_i189] += c2_g_b->data[c2_i189];
    }

    c2_emxFree_int32_T(chartInstance, &c2_g_b);
    c2_i190 = c2_ndx->size[0];
    c2_ndx->size[0] = c2_f_idx->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_ndx, c2_i190,
      &c2_lb_emlrtRTEI);
    c2_db_loop_ub = c2_f_idx->size[0] - 1;
    for (c2_i191 = 0; c2_i191 <= c2_db_loop_ub; c2_i191++) {
      c2_ndx->data[c2_i191] = (real_T)c2_f_idx->data[c2_i191];
    }

    c2_emxFree_int32_T(chartInstance, &c2_f_idx);
    c2_i192 = c2_c_c->size[0];
    c2_c_c->size[0] = c2_ndx->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_c_c, c2_i192,
      &c2_mb_emlrtRTEI);
    c2_eb_loop_ub = c2_ndx->size[0] - 1;
    for (c2_i193 = 0; c2_i193 <= c2_eb_loop_ub; c2_i193++) {
      c2_c_c->data[c2_i193] = c2_ndx->data[c2_i193];
    }

    c2_emxFree_real_T(chartInstance, &c2_ndx);
    for (c2_i194 = 0; c2_i194 < 19200; c2_i194++) {
      c2_b_E[c2_i194] = !chartInstance->c2_E[c2_i194];
    }

    c2_imfill(chartInstance, c2_b_E, c2_c_c, c2_varargout_1);
    for (c2_i195 = 0; c2_i195 < 19200; c2_i195++) {
      c2_varargout_1[c2_i195] = (c2_varargout_1[c2_i195] && chartInstance->
        c2_E[c2_i195]);
    }

    c2_g_idx = 0;
    c2_f_ii = 1;
    exitg1 = false;
    while ((!exitg1) && (c2_f_ii - 1 < 19200)) {
      c2_g_ii = c2_f_ii - 1;
      if (c2_varargout_1[c2_g_ii]) {
        c2_g_idx++;
        if (c2_g_idx >= 19200) {
          exitg1 = true;
        } else {
          c2_f_ii++;
        }
      } else {
        c2_f_ii++;
      }
    }

    c2_b6 = (1 > c2_g_idx);
    if (c2_b6) {
      c2_i196 = 0;
    } else {
      c2_i196 = c2_g_idx;
    }

    c2_i197 = c2_jj->size[0];
    c2_jj->size[0] = c2_i196;
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_jj, c2_i197, &c2_ab_emlrtRTEI);
    c2_fb_loop_ub = c2_i196 - 1;
    for (c2_i198 = 0; c2_i198 <= c2_fb_loop_ub; c2_i198++) {
      c2_jj->data[c2_i198] = 1 + c2_i198;
    }

    c2_iv2[0] = 1;
    c2_iv2[1] = c2_jj->size[0];
    c2_indexShapeCheck(chartInstance, 19200, c2_iv2);
  } else {
    for (c2_i142 = 0; c2_i142 < 19200; c2_i142++) {
      c2_varargout_1[c2_i142] = false;
    }
  }

  c2_emxFree_real_T(chartInstance, &c2_badPix);
  c2_emxFree_real_T(chartInstance, &c2_c_c);
  c2_emxFree_int32_T(chartInstance, &c2_jj);
  c2_emxFree_int32_T(chartInstance, &c2_c_ii);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_lowThresh_size[0]);
  (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
    chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_highThreshTemp_size[0]);
}

static void c2_imfilter(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_h_varargin_1[19200], real32_T c2_b[19200])
{
  int32_T c2_i199;
  boolean_T c2_tooBig;
  int32_T c2_i;
  boolean_T c2_modeFlag;
  boolean_T c2_b_modeFlag;
  boolean_T c2_c_modeFlag;
  int32_T c2_i200;
  int32_T c2_i201;
  int32_T c2_i202;
  boolean_T c2_conn[13];
  int32_T c2_i203;
  real_T c2_padSizeT[2];
  int32_T c2_i204;
  int32_T c2_i205;
  real_T c2_outSizeT[2];
  int32_T c2_i206;
  real_T c2_connDimsT[2];
  int32_T c2_i207;
  real_T c2_startT[2];
  for (c2_i199 = 0; c2_i199 < 19200; c2_i199++) {
    chartInstance->c2_e_varargin_1[c2_i199] = c2_h_varargin_1[c2_i199];
  }

  c2_padImage(chartInstance, chartInstance->c2_e_varargin_1, 0.0, 3, 4.0,
              chartInstance->c2_g_a);
  c2_tooBig = true;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_tooBig = false;
  }

  if (!c2_tooBig) {
    c2_modeFlag = true;
  } else {
    c2_modeFlag = false;
  }

  if (c2_modeFlag) {
    c2_b_modeFlag = true;
  } else {
    c2_b_modeFlag = false;
  }

  c2_c_modeFlag = c2_b_modeFlag;
  if (c2_c_modeFlag) {
    for (c2_i201 = 0; c2_i201 < 2; c2_i201++) {
      c2_padSizeT[c2_i201] = 132.0 + 28.0 * (real_T)c2_i201;
    }

    for (c2_i203 = 0; c2_i203 < 2; c2_i203++) {
      c2_outSizeT[c2_i203] = 120.0 + 40.0 * (real_T)c2_i203;
    }

    for (c2_i205 = 0; c2_i205 < 2; c2_i205++) {
      c2_connDimsT[c2_i205] = 13.0 + -12.0 * (real_T)c2_i205;
    }

    ippfilter_real32(chartInstance->c2_g_a, c2_b, c2_outSizeT, 2.0, c2_padSizeT,
                     c2_dv0, c2_connDimsT, true);
  } else {
    for (c2_i200 = 0; c2_i200 < 13; c2_i200++) {
      c2_conn[c2_i200] = true;
    }

    for (c2_i202 = 0; c2_i202 < 2; c2_i202++) {
      c2_padSizeT[c2_i202] = 132.0 + 28.0 * (real_T)c2_i202;
    }

    for (c2_i204 = 0; c2_i204 < 2; c2_i204++) {
      c2_outSizeT[c2_i204] = 120.0 + 40.0 * (real_T)c2_i204;
    }

    for (c2_i206 = 0; c2_i206 < 2; c2_i206++) {
      c2_connDimsT[c2_i206] = 13.0 + -12.0 * (real_T)c2_i206;
    }

    for (c2_i207 = 0; c2_i207 < 2; c2_i207++) {
      c2_startT[c2_i207] = 6.0 + -6.0 * (real_T)c2_i207;
    }

    imfilter_real32(chartInstance->c2_g_a, c2_b, 2.0, c2_outSizeT, 2.0,
                    c2_padSizeT, c2_dv0, 13.0, c2_conn, 2.0, c2_connDimsT,
                    c2_startT, 2.0, true, true);
  }
}

static void c2_padImage(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_a_tmp[19200], real_T c2_boundary_pos, int8_T c2_boundaryEnum,
  real_T c2_boundaryStr_pos, real32_T c2_l_a[21120])
{
  int32_T c2_j;
  real_T c2_b_j;
  int32_T c2_i;
  real_T c2_b_i;
  static int32_T c2_idxA[320] = { 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
    29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66,
    67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85,
    86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103,
    104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118,
    119, 120, 120, 120, 120, 120, 120, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
    29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66,
    67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85,
    86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103,
    104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118,
    119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133,
    134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148,
    149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160 };

  (void)c2_boundary_pos;
  (void)c2_boundaryEnum;
  (void)c2_boundaryStr_pos;
  for (c2_j = 0; c2_j < 160; c2_j++) {
    c2_b_j = 1.0 + (real_T)c2_j;
    for (c2_i = 0; c2_i < 132; c2_i++) {
      c2_b_i = 1.0 + (real_T)c2_i;
      c2_l_a[((int32_T)c2_b_i + 132 * ((int32_T)c2_b_j - 1)) - 1] = c2_a_tmp
        [(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
           chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_idxA[(int32_T)c2_b_i - 1],
           1, 120) + 120 * (sf_eml_array_bounds_check
                            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U,
            0, 0, MAX_uint32_T, c2_idxA[(int32_T)c2_b_j + 159], 1, 160) - 1)) -
        1];
    }
  }
}

static void c2_b_imfilter(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_h_varargin_1[19200], real_T c2_varargin_2[13], real32_T c2_b[19200])
{
  int32_T c2_i208;
  int32_T c2_trueCount;
  int32_T c2_i;
  int32_T c2_tmp_size[1];
  int32_T c2_partialTrueCount;
  int32_T c2_b_i;
  int32_T c2_nonzero_h_size[1];
  int32_T c2_loop_ub;
  int32_T c2_tmp_data[13];
  int32_T c2_i209;
  int32_T c2_i210;
  real_T c2_nonzero_h_data[13];
  boolean_T c2_densityFlag;
  boolean_T c2_connb[13];
  boolean_T c2_tooBig;
  int32_T c2_c_i;
  boolean_T c2_modeFlag;
  boolean_T c2_b_modeFlag;
  boolean_T c2_c_modeFlag;
  real_T c2_numKernElem;
  int32_T c2_i211;
  int32_T c2_i212;
  int32_T c2_i213;
  real_T c2_padSizeT[2];
  int32_T c2_i214;
  int32_T c2_i215;
  real_T c2_outSizeT[2];
  int32_T c2_i216;
  real_T c2_connDimsT[2];
  int32_T c2_i217;
  real_T c2_startT[2];
  for (c2_i208 = 0; c2_i208 < 19200; c2_i208++) {
    chartInstance->c2_g_varargin_1[c2_i208] = c2_h_varargin_1[c2_i208];
  }

  c2_b_padImage(chartInstance, chartInstance->c2_g_varargin_1, 0.0, 3, 4.0,
                chartInstance->c2_i_a);
  c2_trueCount = 0;
  for (c2_i = 0; c2_i < 13; c2_i++) {
    if (c2_varargin_2[c2_i] != 0.0) {
      c2_trueCount++;
    }
  }

  c2_tmp_size[0] = c2_trueCount;
  c2_partialTrueCount = 0;
  for (c2_b_i = 0; c2_b_i < 13; c2_b_i++) {
    if (c2_varargin_2[c2_b_i] != 0.0) {
      c2_tmp_data[c2_partialTrueCount] = c2_b_i + 1;
      c2_partialTrueCount++;
    }
  }

  c2_nonzero_h_size[0] = c2_tmp_size[0];
  c2_loop_ub = c2_tmp_size[0] - 1;
  for (c2_i209 = 0; c2_i209 <= c2_loop_ub; c2_i209++) {
    c2_nonzero_h_data[c2_i209] = c2_varargin_2[c2_tmp_data[c2_i209] - 1];
  }

  for (c2_i210 = 0; c2_i210 < 13; c2_i210++) {
    c2_connb[c2_i210] = (c2_varargin_2[c2_i210] != 0.0);
  }

  c2_densityFlag = false;
  if ((real_T)c2_nonzero_h_size[0] / 13.0 > 0.05) {
    c2_densityFlag = true;
  }

  c2_tooBig = true;
  for (c2_c_i = 0; c2_c_i < 2; c2_c_i++) {
    c2_tooBig = false;
  }

  if (c2_densityFlag && (!c2_tooBig)) {
    c2_modeFlag = true;
  } else {
    c2_modeFlag = false;
  }

  if (c2_modeFlag) {
    c2_b_modeFlag = true;
  } else {
    c2_b_modeFlag = false;
  }

  c2_c_modeFlag = c2_b_modeFlag;
  if (c2_c_modeFlag) {
    for (c2_i211 = 0; c2_i211 < 2; c2_i211++) {
      c2_padSizeT[c2_i211] = 120.0 + 52.0 * (real_T)c2_i211;
    }

    for (c2_i213 = 0; c2_i213 < 2; c2_i213++) {
      c2_outSizeT[c2_i213] = 120.0 + 40.0 * (real_T)c2_i213;
    }

    for (c2_i215 = 0; c2_i215 < 2; c2_i215++) {
      c2_connDimsT[c2_i215] = 1.0 + 12.0 * (real_T)c2_i215;
    }

    ippfilter_real32(chartInstance->c2_i_a, c2_b, c2_outSizeT, 2.0, c2_padSizeT,
                     c2_varargin_2, c2_connDimsT, true);
  } else {
    c2_numKernElem = (real_T)c2_nonzero_h_size[0];
    for (c2_i212 = 0; c2_i212 < 2; c2_i212++) {
      c2_padSizeT[c2_i212] = 120.0 + 52.0 * (real_T)c2_i212;
    }

    for (c2_i214 = 0; c2_i214 < 2; c2_i214++) {
      c2_outSizeT[c2_i214] = 120.0 + 40.0 * (real_T)c2_i214;
    }

    for (c2_i216 = 0; c2_i216 < 2; c2_i216++) {
      c2_connDimsT[c2_i216] = 1.0 + 12.0 * (real_T)c2_i216;
    }

    for (c2_i217 = 0; c2_i217 < 2; c2_i217++) {
      c2_startT[c2_i217] = 6.0 * (real_T)c2_i217;
    }

    imfilter_real32(chartInstance->c2_i_a, c2_b, 2.0, c2_outSizeT, 2.0,
                    c2_padSizeT, &c2_nonzero_h_data[0], c2_numKernElem, c2_connb,
                    2.0, c2_connDimsT, c2_startT, 2.0, true, true);
  }
}

static void c2_b_padImage(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_a_tmp[19200], real_T c2_boundary_pos, int8_T c2_boundaryEnum,
  real_T c2_boundaryStr_pos, real32_T c2_l_a[20640])
{
  int32_T c2_j;
  real_T c2_b_j;
  int32_T c2_i;
  real_T c2_b_i;
  static int32_T c2_idxA[344] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
    34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52,
    53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71,
    72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
    91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107,
    108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
    40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58,
    59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
    78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96,
    97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112,
    113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127,
    128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142,
    143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157,
    158, 159, 160, 160, 160, 160, 160, 160, 160 };

  (void)c2_boundary_pos;
  (void)c2_boundaryEnum;
  (void)c2_boundaryStr_pos;
  for (c2_j = 0; c2_j < 172; c2_j++) {
    c2_b_j = 1.0 + (real_T)c2_j;
    for (c2_i = 0; c2_i < 120; c2_i++) {
      c2_b_i = 1.0 + (real_T)c2_i;
      c2_l_a[((int32_T)c2_b_i + 120 * ((int32_T)c2_b_j - 1)) - 1] = c2_a_tmp
        [(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
           chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_idxA[(int32_T)c2_b_i - 1],
           1, 120) + 120 * (sf_eml_array_bounds_check
                            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U,
            0, 0, MAX_uint32_T, c2_idxA[(int32_T)c2_b_j + 171], 1, 160) - 1)) -
        1];
    }
  }
}

static void c2_c_imfilter(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_h_varargin_1[19200], real32_T c2_b[19200])
{
  int32_T c2_i218;
  int32_T c2_trueCount;
  int32_T c2_i;
  int32_T c2_tmp_size[1];
  int32_T c2_partialTrueCount;
  int32_T c2_b_i;
  int32_T c2_nonzero_h_size[1];
  int32_T c2_loop_ub;
  int32_T c2_tmp_data[13];
  int32_T c2_i219;
  boolean_T c2_densityFlag;
  real_T c2_nonzero_h_data[13];
  boolean_T c2_tooBig;
  int32_T c2_c_i;
  boolean_T c2_modeFlag;
  boolean_T c2_b_modeFlag;
  boolean_T c2_c_modeFlag;
  real_T c2_numKernElem;
  int32_T c2_i220;
  int32_T c2_i221;
  int32_T c2_i222;
  real_T c2_padSizeT[2];
  int32_T c2_i223;
  boolean_T c2_conn[13];
  int32_T c2_i224;
  real_T c2_outSizeT[2];
  int32_T c2_i225;
  real_T c2_connDimsT[2];
  int32_T c2_i226;
  int32_T c2_i227;
  real_T c2_startT[2];
  for (c2_i218 = 0; c2_i218 < 19200; c2_i218++) {
    chartInstance->c2_f_varargin_1[c2_i218] = c2_h_varargin_1[c2_i218];
  }

  c2_b_padImage(chartInstance, chartInstance->c2_f_varargin_1, 0.0, 3, 4.0,
                chartInstance->c2_h_a);
  c2_trueCount = 0;
  for (c2_i = 0; c2_i < 13; c2_i++) {
    if (c2_dv0[c2_i] != 0.0) {
      c2_trueCount++;
    }
  }

  c2_tmp_size[0] = c2_trueCount;
  c2_partialTrueCount = 0;
  for (c2_b_i = 0; c2_b_i < 13; c2_b_i++) {
    if (c2_dv0[c2_b_i] != 0.0) {
      c2_tmp_data[c2_partialTrueCount] = c2_b_i + 1;
      c2_partialTrueCount++;
    }
  }

  c2_nonzero_h_size[0] = c2_tmp_size[0];
  c2_loop_ub = c2_tmp_size[0] - 1;
  for (c2_i219 = 0; c2_i219 <= c2_loop_ub; c2_i219++) {
    c2_nonzero_h_data[c2_i219] = c2_dv0[c2_tmp_data[c2_i219] - 1];
  }

  c2_densityFlag = false;
  if ((real_T)c2_nonzero_h_size[0] / 13.0 > 0.05) {
    c2_densityFlag = true;
  }

  c2_tooBig = true;
  for (c2_c_i = 0; c2_c_i < 2; c2_c_i++) {
    c2_tooBig = false;
  }

  if (c2_densityFlag && (!c2_tooBig)) {
    c2_modeFlag = true;
  } else {
    c2_modeFlag = false;
  }

  if (c2_modeFlag) {
    c2_b_modeFlag = true;
  } else {
    c2_b_modeFlag = false;
  }

  c2_c_modeFlag = c2_b_modeFlag;
  if (c2_c_modeFlag) {
    for (c2_i220 = 0; c2_i220 < 2; c2_i220++) {
      c2_padSizeT[c2_i220] = 120.0 + 52.0 * (real_T)c2_i220;
    }

    for (c2_i222 = 0; c2_i222 < 2; c2_i222++) {
      c2_outSizeT[c2_i222] = 120.0 + 40.0 * (real_T)c2_i222;
    }

    for (c2_i224 = 0; c2_i224 < 2; c2_i224++) {
      c2_connDimsT[c2_i224] = 1.0 + 12.0 * (real_T)c2_i224;
    }

    ippfilter_real32(chartInstance->c2_h_a, c2_b, c2_outSizeT, 2.0, c2_padSizeT,
                     c2_dv0, c2_connDimsT, true);
  } else {
    c2_numKernElem = (real_T)c2_nonzero_h_size[0];
    for (c2_i221 = 0; c2_i221 < 13; c2_i221++) {
      c2_conn[c2_i221] = true;
    }

    for (c2_i223 = 0; c2_i223 < 2; c2_i223++) {
      c2_padSizeT[c2_i223] = 120.0 + 52.0 * (real_T)c2_i223;
    }

    for (c2_i225 = 0; c2_i225 < 2; c2_i225++) {
      c2_outSizeT[c2_i225] = 120.0 + 40.0 * (real_T)c2_i225;
    }

    for (c2_i226 = 0; c2_i226 < 2; c2_i226++) {
      c2_connDimsT[c2_i226] = 1.0 + 12.0 * (real_T)c2_i226;
    }

    for (c2_i227 = 0; c2_i227 < 2; c2_i227++) {
      c2_startT[c2_i227] = 6.0 * (real_T)c2_i227;
    }

    imfilter_real32(chartInstance->c2_h_a, c2_b, 2.0, c2_outSizeT, 2.0,
                    c2_padSizeT, &c2_nonzero_h_data[0], c2_numKernElem, c2_conn,
                    2.0, c2_connDimsT, c2_startT, 2.0, true, true);
  }
}

static void c2_d_imfilter(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_h_varargin_1[19200], real_T c2_varargin_2[13], real32_T c2_b[19200])
{
  int32_T c2_i228;
  int32_T c2_trueCount;
  int32_T c2_i;
  int32_T c2_tmp_size[1];
  int32_T c2_partialTrueCount;
  int32_T c2_b_i;
  int32_T c2_nonzero_h_size[1];
  int32_T c2_loop_ub;
  int32_T c2_tmp_data[13];
  int32_T c2_i229;
  int32_T c2_i230;
  real_T c2_nonzero_h_data[13];
  boolean_T c2_densityFlag;
  boolean_T c2_connb[13];
  boolean_T c2_tooBig;
  int32_T c2_c_i;
  boolean_T c2_modeFlag;
  boolean_T c2_b_modeFlag;
  boolean_T c2_c_modeFlag;
  real_T c2_numKernElem;
  int32_T c2_i231;
  int32_T c2_i232;
  int32_T c2_i233;
  real_T c2_padSizeT[2];
  int32_T c2_i234;
  int32_T c2_i235;
  real_T c2_outSizeT[2];
  int32_T c2_i236;
  real_T c2_connDimsT[2];
  int32_T c2_i237;
  real_T c2_startT[2];
  for (c2_i228 = 0; c2_i228 < 19200; c2_i228++) {
    chartInstance->c2_d_varargin_1[c2_i228] = c2_h_varargin_1[c2_i228];
  }

  c2_padImage(chartInstance, chartInstance->c2_d_varargin_1, 0.0, 3, 4.0,
              chartInstance->c2_d_a);
  c2_trueCount = 0;
  for (c2_i = 0; c2_i < 13; c2_i++) {
    if (c2_varargin_2[c2_i] != 0.0) {
      c2_trueCount++;
    }
  }

  c2_tmp_size[0] = c2_trueCount;
  c2_partialTrueCount = 0;
  for (c2_b_i = 0; c2_b_i < 13; c2_b_i++) {
    if (c2_varargin_2[c2_b_i] != 0.0) {
      c2_tmp_data[c2_partialTrueCount] = c2_b_i + 1;
      c2_partialTrueCount++;
    }
  }

  c2_nonzero_h_size[0] = c2_tmp_size[0];
  c2_loop_ub = c2_tmp_size[0] - 1;
  for (c2_i229 = 0; c2_i229 <= c2_loop_ub; c2_i229++) {
    c2_nonzero_h_data[c2_i229] = c2_varargin_2[c2_tmp_data[c2_i229] - 1];
  }

  for (c2_i230 = 0; c2_i230 < 13; c2_i230++) {
    c2_connb[c2_i230] = (c2_varargin_2[c2_i230] != 0.0);
  }

  c2_densityFlag = false;
  if ((real_T)c2_nonzero_h_size[0] / 13.0 > 0.05) {
    c2_densityFlag = true;
  }

  c2_tooBig = true;
  for (c2_c_i = 0; c2_c_i < 2; c2_c_i++) {
    c2_tooBig = false;
  }

  if (c2_densityFlag && (!c2_tooBig)) {
    c2_modeFlag = true;
  } else {
    c2_modeFlag = false;
  }

  if (c2_modeFlag) {
    c2_b_modeFlag = true;
  } else {
    c2_b_modeFlag = false;
  }

  c2_c_modeFlag = c2_b_modeFlag;
  if (c2_c_modeFlag) {
    for (c2_i231 = 0; c2_i231 < 2; c2_i231++) {
      c2_padSizeT[c2_i231] = 132.0 + 28.0 * (real_T)c2_i231;
    }

    for (c2_i233 = 0; c2_i233 < 2; c2_i233++) {
      c2_outSizeT[c2_i233] = 120.0 + 40.0 * (real_T)c2_i233;
    }

    for (c2_i235 = 0; c2_i235 < 2; c2_i235++) {
      c2_connDimsT[c2_i235] = 13.0 + -12.0 * (real_T)c2_i235;
    }

    ippfilter_real32(chartInstance->c2_d_a, c2_b, c2_outSizeT, 2.0, c2_padSizeT,
                     c2_varargin_2, c2_connDimsT, true);
  } else {
    c2_numKernElem = (real_T)c2_nonzero_h_size[0];
    for (c2_i232 = 0; c2_i232 < 2; c2_i232++) {
      c2_padSizeT[c2_i232] = 132.0 + 28.0 * (real_T)c2_i232;
    }

    for (c2_i234 = 0; c2_i234 < 2; c2_i234++) {
      c2_outSizeT[c2_i234] = 120.0 + 40.0 * (real_T)c2_i234;
    }

    for (c2_i236 = 0; c2_i236 < 2; c2_i236++) {
      c2_connDimsT[c2_i236] = 13.0 + -12.0 * (real_T)c2_i236;
    }

    for (c2_i237 = 0; c2_i237 < 2; c2_i237++) {
      c2_startT[c2_i237] = 6.0 + -6.0 * (real_T)c2_i237;
    }

    imfilter_real32(chartInstance->c2_d_a, c2_b, 2.0, c2_outSizeT, 2.0,
                    c2_padSizeT, &c2_nonzero_h_data[0], c2_numKernElem, c2_connb,
                    2.0, c2_connDimsT, c2_startT, 2.0, true, true);
  }
}

static void c2_hypot(SFc2_flightControlSystemInstanceStruct *chartInstance,
                     real32_T c2_d_x[19200], real32_T c2_c_y[19200], real32_T
                     c2_r[19200])
{
  int32_T c2_k;
  int32_T c2_b_k;
  real32_T c2_e_x;
  real32_T c2_d_y;
  real32_T c2_x1;
  real32_T c2_x2;
  real32_T c2_z;
  (void)chartInstance;
  for (c2_k = 0; c2_k < 19200; c2_k++) {
    c2_b_k = c2_k;
    c2_e_x = c2_d_x[c2_b_k];
    c2_d_y = c2_c_y[c2_b_k];
    c2_x1 = c2_e_x;
    c2_x2 = c2_d_y;
    c2_z = muSingleScalarHypot(c2_x1, c2_x2);
    c2_r[c2_b_k] = c2_z;
  }
}

static void c2_check_forloop_overflow_error
  (SFc2_flightControlSystemInstanceStruct *chartInstance, boolean_T c2_overflow)
{
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv15[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  static char_T c2_cv16[5] = { 'i', 'n', 't', '3', '2' };

  (void)chartInstance;
  (void)c2_overflow;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv15, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv15, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv16, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
    1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U, 2U,
    14, c2_d_y, 14, c2_e_y)));
}

static void c2_warning(SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv17[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c2_d_y = NULL;
  static char_T c2_cv18[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c2_e_y = NULL;
  static char_T c2_msgID[27] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm',
    'h', 'i', 's', 't', 'c', ':', 'i', 'n', 'p', 'u', 't', 'H', 'a', 's', 'N',
    'a', 'N', 's' };

  (void)chartInstance;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv17, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv18, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_msgID, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c2_c_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c2_d_y, 14, c2_e_y));
}

static void c2_eml_find(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_d_x[19200], c2_emxArray_int32_T *c2_i, c2_emxArray_int32_T *c2_j)
{
  c2_emxArray_int32_T *c2_r4;
  int32_T c2_b_idx;
  int32_T c2_i238;
  int32_T c2_i239;
  int32_T c2_i240;
  int32_T c2_i241;
  int32_T c2_i242;
  int32_T c2_i243;
  int32_T c2_ii;
  int32_T c2_jj;
  boolean_T c2_b7;
  int32_T c2_i244;
  c2_emxArray_int32_T *c2_r5;
  int32_T c2_i245;
  int32_T c2_loop_ub;
  int32_T c2_i246;
  int32_T c2_iv3[2];
  int32_T c2_i247;
  boolean_T c2_b8;
  int32_T c2_i248;
  int32_T c2_i249;
  int32_T c2_b_loop_ub;
  int32_T c2_i250;
  int32_T c2_iv4[2];
  int32_T c2_i251;
  boolean_T c2_b9;
  int32_T c2_i252;
  int32_T c2_i253;
  int32_T c2_c_loop_ub;
  int32_T c2_i254;
  int32_T c2_iv5[2];
  boolean_T exitg1;
  boolean_T guard1 = false;
  c2_emxInit_int32_T(chartInstance, &c2_r4, 1, &c2_bc_emlrtRTEI);
  c2_b_idx = 0;
  c2_i238 = c2_r4->size[0];
  c2_r4->size[0] = 19200;
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_r4, c2_i238, &c2_ub_emlrtRTEI);
  for (c2_i239 = 0; c2_i239 < 19200; c2_i239++) {
    c2_r4->data[c2_i239] = 0;
  }

  c2_i240 = c2_i->size[0];
  c2_i->size[0] = c2_r4->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_i, c2_i240, &c2_ub_emlrtRTEI);
  c2_i241 = c2_r4->size[0];
  c2_r4->size[0] = 19200;
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_r4, c2_i241, &c2_ub_emlrtRTEI);
  for (c2_i242 = 0; c2_i242 < 19200; c2_i242++) {
    c2_r4->data[c2_i242] = 0;
  }

  c2_i243 = c2_j->size[0];
  c2_j->size[0] = c2_r4->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_j, c2_i243, &c2_ub_emlrtRTEI);
  c2_ii = 1;
  c2_jj = 1;
  c2_emxFree_int32_T(chartInstance, &c2_r4);
  exitg1 = false;
  while ((!exitg1) && (c2_jj <= 160)) {
    guard1 = false;
    if (c2_d_x[(c2_ii + 120 * (c2_jj - 1)) - 1]) {
      c2_b_idx++;
      c2_i->data[c2_b_idx - 1] = c2_ii;
      c2_j->data[c2_b_idx - 1] = c2_jj;
      if (c2_b_idx >= 19200) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      c2_ii++;
      if (c2_ii > 120) {
        c2_ii = 1;
        c2_jj++;
      }
    }
  }

  c2_b7 = (1 > c2_b_idx);
  if (c2_b7) {
    c2_i244 = 0;
  } else {
    c2_i244 = c2_b_idx;
  }

  c2_emxInit_int32_T(chartInstance, &c2_r5, 1, &c2_vb_emlrtRTEI);
  c2_i245 = c2_r5->size[0];
  c2_r5->size[0] = c2_i244;
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_r5, c2_i245, &c2_vb_emlrtRTEI);
  c2_loop_ub = c2_i244 - 1;
  for (c2_i246 = 0; c2_i246 <= c2_loop_ub; c2_i246++) {
    c2_r5->data[c2_i246] = 1 + c2_i246;
  }

  c2_iv3[0] = 1;
  c2_iv3[1] = c2_r5->size[0];
  c2_indexShapeCheck(chartInstance, 19200, c2_iv3);
  c2_i247 = c2_i->size[0];
  c2_i->size[0] = c2_i244;
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_i, c2_i247, &c2_wb_emlrtRTEI);
  c2_b8 = (1 > c2_b_idx);
  if (c2_b8) {
    c2_i248 = 0;
  } else {
    c2_i248 = c2_b_idx;
  }

  c2_i249 = c2_r5->size[0];
  c2_r5->size[0] = c2_i248;
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_r5, c2_i249, &c2_xb_emlrtRTEI);
  c2_b_loop_ub = c2_i248 - 1;
  for (c2_i250 = 0; c2_i250 <= c2_b_loop_ub; c2_i250++) {
    c2_r5->data[c2_i250] = 1 + c2_i250;
  }

  c2_iv4[0] = 1;
  c2_iv4[1] = c2_r5->size[0];
  c2_indexShapeCheck(chartInstance, 19200, c2_iv4);
  c2_i251 = c2_j->size[0];
  c2_j->size[0] = c2_i248;
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_j, c2_i251, &c2_yb_emlrtRTEI);
  c2_b9 = (1 > c2_b_idx);
  if (c2_b9) {
    c2_i252 = 0;
  } else {
    c2_i252 = c2_b_idx;
  }

  c2_i253 = c2_r5->size[0];
  c2_r5->size[0] = c2_i252;
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_r5, c2_i253, &c2_ac_emlrtRTEI);
  c2_c_loop_ub = c2_i252 - 1;
  for (c2_i254 = 0; c2_i254 <= c2_c_loop_ub; c2_i254++) {
    c2_r5->data[c2_i254] = 1 + c2_i254;
  }

  c2_iv5[0] = 1;
  c2_iv5[1] = c2_r5->size[0];
  c2_indexShapeCheck(chartInstance, 19200, c2_iv5);
  c2_emxFree_int32_T(chartInstance, &c2_r5);
}

static void c2_indexShapeCheck(SFc2_flightControlSystemInstanceStruct
  *chartInstance, int32_T c2_matrixSize, int32_T c2_indexSize[2])
{
  int32_T c2_size1;
  boolean_T c2_b;
  boolean_T c2_nonSingletonDimFound;
  boolean_T c2_c;
  boolean_T c2_b_c;
  boolean_T c2_b_b;
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv19[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V',
    'e', 'c', 't', 'o', 'r' };

  const mxArray *c2_d_y = NULL;
  (void)chartInstance;
  c2_size1 = c2_matrixSize;
  if (c2_size1 != 1) {
    c2_b = false;
  } else {
    c2_b = true;
  }

  if (c2_b) {
    c2_nonSingletonDimFound = false;
    if (c2_indexSize[1] != 1) {
      c2_nonSingletonDimFound = true;
    }

    c2_b_b = c2_nonSingletonDimFound;
    if (c2_b_b) {
      c2_c = true;
    } else {
      c2_c = false;
    }
  } else {
    c2_c = false;
  }

  c2_b_c = c2_c;
  if (!c2_b_c) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv19, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv19, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_d_y)));
  }
}

static void c2_round(SFc2_flightControlSystemInstanceStruct *chartInstance,
                     c2_emxArray_real_T *c2_d_x, c2_emxArray_real_T *c2_e_x)
{
  int32_T c2_i255;
  int32_T c2_loop_ub;
  int32_T c2_i256;
  c2_i255 = c2_e_x->size[0];
  c2_e_x->size[0] = c2_d_x->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_e_x, c2_i255, &c2_cc_emlrtRTEI);
  c2_loop_ub = c2_d_x->size[0] - 1;
  for (c2_i256 = 0; c2_i256 <= c2_loop_ub; c2_i256++) {
    c2_e_x->data[c2_i256] = c2_d_x->data[c2_i256];
  }

  c2_b_round(chartInstance, c2_e_x);
}

static void c2_b_warning(SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv20[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c2_d_y = NULL;
  static char_T c2_cv21[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c2_e_y = NULL;
  static char_T c2_msgID[26] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'b', 'w',
    's', 'e', 'l', 'e', 'c', 't', ':', 'o', 'u', 't', 'O', 'f', 'R', 'a', 'n',
    'g', 'e' };

  (void)chartInstance;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv20, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv21, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_msgID, 10, 0U, 1U, 0U, 2, 1, 26),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c2_c_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c2_d_y, 14, c2_e_y));
}

static void c2_nullAssignment(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_d_x, c2_emxArray_int32_T *c2_b_idx,
  c2_emxArray_real_T *c2_e_x)
{
  int32_T c2_i257;
  int32_T c2_loop_ub;
  int32_T c2_i258;
  c2_emxArray_int32_T *c2_c_idx;
  int32_T c2_i259;
  int32_T c2_b_loop_ub;
  int32_T c2_i260;
  c2_i257 = c2_e_x->size[0];
  c2_e_x->size[0] = c2_d_x->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_e_x, c2_i257, &c2_dc_emlrtRTEI);
  c2_loop_ub = c2_d_x->size[0] - 1;
  for (c2_i258 = 0; c2_i258 <= c2_loop_ub; c2_i258++) {
    c2_e_x->data[c2_i258] = c2_d_x->data[c2_i258];
  }

  c2_emxInit_int32_T(chartInstance, &c2_c_idx, 1, &c2_dc_emlrtRTEI);
  c2_i259 = c2_c_idx->size[0];
  c2_c_idx->size[0] = c2_b_idx->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_c_idx, c2_i259,
    &c2_dc_emlrtRTEI);
  c2_b_loop_ub = c2_b_idx->size[0] - 1;
  for (c2_i260 = 0; c2_i260 <= c2_b_loop_ub; c2_i260++) {
    c2_c_idx->data[c2_i260] = c2_b_idx->data[c2_i260];
  }

  c2_d_nullAssignment(chartInstance, c2_e_x, c2_c_idx);
  c2_emxFree_int32_T(chartInstance, &c2_c_idx);
}

static void c2_validate_inputs(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_d_x, c2_emxArray_int32_T *c2_b_idx)
{
  int32_T c2_n;
  boolean_T c2_p;
  real_T c2_d6;
  int32_T c2_i261;
  int32_T c2_k;
  real_T c2_b_k;
  const mxArray *c2_c_y = NULL;
  int32_T c2_e_x;
  const mxArray *c2_d_y = NULL;
  int32_T c2_f_x;
  boolean_T exitg1;
  (void)chartInstance;
  c2_n = c2_d_x->size[0];
  c2_p = true;
  c2_d6 = (real_T)c2_b_idx->size[0];
  c2_i261 = (int32_T)c2_d6 - 1;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k <= c2_i261)) {
    c2_b_k = 1.0 + (real_T)c2_k;
    if ((c2_b_idx->data[(int32_T)c2_b_k - 1] < 1) || (c2_b_idx->data[(int32_T)
         c2_b_k - 1] > c2_n)) {
      c2_p = false;
      exitg1 = true;
    } else {
      c2_e_x = c2_b_idx->data[(int32_T)c2_b_k - 1];
      c2_f_x = c2_e_x;
      if (c2_b_idx->data[(int32_T)c2_b_k - 1] != c2_f_x) {
        c2_p = false;
        exitg1 = true;
      } else {
        c2_k++;
      }
    }
  }

  if (c2_p) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_d_y)));
  }
}

static void c2_make_bitarray(SFc2_flightControlSystemInstanceStruct
  *chartInstance, int32_T c2_n, c2_emxArray_int32_T *c2_b_idx, boolean_T
  c2_b_data[], int32_T c2_b_size[2])
{
  int32_T c2_i262;
  int32_T c2_i263;
  int32_T c2_loop_ub;
  int32_T c2_i264;
  int32_T c2_i265;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  c2_b_size[0] = 1;
  c2_b_size[1] = c2_n;
  c2_i262 = c2_b_size[0];
  c2_i263 = c2_b_size[1];
  c2_loop_ub = c2_n - 1;
  for (c2_i264 = 0; c2_i264 <= c2_loop_ub; c2_i264++) {
    c2_b_data[c2_i264] = false;
  }

  c2_i265 = c2_b_idx->size[0];
  c2_b = c2_i265;
  c2_b_b = c2_b;
  if (1 > c2_b_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_check_forloop_overflow_error(chartInstance, true);
  }

  for (c2_k = 0; c2_k < c2_i265; c2_k++) {
    c2_b_k = c2_k;
    c2_b_data[c2_b_idx->data[c2_b_k] - 1] = true;
  }
}

static int32_T c2_num_true(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_b_data[], int32_T c2_b_size[2])
{
  int32_T c2_n;
  int32_T c2_i266;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_i267;
  int32_T c2_i268;
  c2_n = 0;
  c2_i266 = c2_b_size[1];
  c2_b = c2_i266;
  c2_b_b = c2_b;
  if (1 > c2_b_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_check_forloop_overflow_error(chartInstance, true);
  }

  for (c2_k = 0; c2_k < c2_i266; c2_k++) {
    c2_b_k = c2_k;
    c2_i267 = c2_b_size[1];
    c2_i268 = c2_i267;
    c2_n += (int32_T)c2_b_data[c2_b_k];
  }

  return c2_n;
}

static boolean_T c2_allinrange(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_d_x, real_T c2_lo, int32_T c2_hi)
{
  boolean_T c2_p;
  real_T c2_d7;
  int32_T c2_i269;
  int32_T c2_k;
  real_T c2_b_k;
  boolean_T c2_b10;
  int32_T exitg1;
  (void)chartInstance;
  (void)c2_lo;
  c2_d7 = (real_T)c2_d_x->size[0];
  c2_i269 = (int32_T)c2_d7 - 1;
  c2_k = 0;
  do {
    exitg1 = 0;
    if (c2_k <= c2_i269) {
      c2_b_k = 1.0 + (real_T)c2_k;
      if ((c2_d_x->data[(int32_T)c2_b_k - 1] >= 1.0) && (c2_d_x->data[(int32_T)
           c2_b_k - 1] <= (real_T)c2_hi)) {
        c2_b10 = true;
      } else {
        c2_b10 = false;
      }

      if (!c2_b10) {
        c2_p = false;
        exitg1 = 1;
      } else {
        c2_k++;
      }
    } else {
      c2_p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c2_p;
}

static void c2_imfill(SFc2_flightControlSystemInstanceStruct *chartInstance,
                      boolean_T c2_h_varargin_1[19200], c2_emxArray_real_T
                      *c2_varargin_2, boolean_T c2_I2[19200])
{
  c2_emxArray_real_T *c2_b_varargin_2;
  int32_T c2_i270;
  int32_T c2_loop_ub;
  int32_T c2_i271;
  static char_T c2_cv22[36] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm', 'f',
    'i', 'l', 'l', ':', 'n', 'o', 'I', 'n', 't', 'e', 'r', 'a', 'c', 't', 'i',
    'v', 'e', 'I', 'n', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  c2_emxArray_real_T *c2_c_varargin_2;
  int32_T c2_i272;
  int32_T c2_b_loop_ub;
  int32_T c2_i273;
  c2_emxArray_real_T *c2_locationsVar;
  int32_T c2_i274;
  int32_T c2_i275;
  boolean_T c2_b_mask[19200];
  int32_T c2_i276;
  c2_emxArray_int32_T *c2_r6;
  int32_T c2_i277;
  int32_T c2_c_loop_ub;
  int32_T c2_i278;
  int32_T c2_tmp_size[1];
  int32_T c2_d_loop_ub;
  int32_T c2_i279;
  boolean_T c2_tmp_data[19200];
  int32_T c2_e_loop_ub;
  int32_T c2_i280;
  int32_T c2_i281;
  real_T c2_imSizeT[2];
  int32_T c2_i282;
  c2_emxInit_real_T1(chartInstance, &c2_b_varargin_2, 1, &c2_fc_emlrtRTEI);
  c2_i270 = c2_b_varargin_2->size[0];
  c2_b_varargin_2->size[0] = c2_varargin_2->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_b_varargin_2, c2_i270,
    &c2_fc_emlrtRTEI);
  c2_loop_ub = c2_varargin_2->size[0] - 1;
  for (c2_i271 = 0; c2_i271 <= c2_loop_ub; c2_i271++) {
    c2_b_varargin_2->data[c2_i271] = c2_varargin_2->data[c2_i271];
  }

  if (!c2_isequal(chartInstance, c2_b_varargin_2, 0.0)) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                      c2_b_emlrt_marshallOut(chartInstance, c2_cv22), 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
      1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
      1U, 14, c2_b_emlrt_marshallOut(chartInstance, c2_cv22))));
  }

  c2_emxFree_real_T(chartInstance, &c2_b_varargin_2);
  c2_emxInit_real_T1(chartInstance, &c2_c_varargin_2, 1, &c2_gc_emlrtRTEI);
  c2_i272 = c2_c_varargin_2->size[0];
  c2_c_varargin_2->size[0] = c2_varargin_2->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_c_varargin_2, c2_i272,
    &c2_gc_emlrtRTEI);
  c2_b_loop_ub = c2_varargin_2->size[0] - 1;
  for (c2_i273 = 0; c2_i273 <= c2_b_loop_ub; c2_i273++) {
    c2_c_varargin_2->data[c2_i273] = c2_varargin_2->data[c2_i273];
  }

  c2_emxInit_real_T1(chartInstance, &c2_locationsVar, 1, &c2_jc_emlrtRTEI);
  c2_checkLocations(chartInstance, c2_c_varargin_2, c2_locationsVar);
  c2_emxFree_real_T(chartInstance, &c2_c_varargin_2);
  for (c2_i274 = 0; c2_i274 < 19200; c2_i274++) {
    c2_b_mask[c2_i274] = c2_h_varargin_1[c2_i274];
  }

  for (c2_i275 = 0; c2_i275 < 19200; c2_i275++) {
    c2_b_mask[c2_i275] = !c2_b_mask[c2_i275];
  }

  for (c2_i276 = 0; c2_i276 < 19200; c2_i276++) {
    c2_I2[c2_i276] = false;
  }

  c2_emxInit_int32_T(chartInstance, &c2_r6, 1, &c2_kc_emlrtRTEI);
  c2_i277 = c2_r6->size[0];
  c2_r6->size[0] = c2_locationsVar->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_r6, c2_i277, &c2_hc_emlrtRTEI);
  c2_c_loop_ub = c2_locationsVar->size[0] - 1;
  for (c2_i278 = 0; c2_i278 <= c2_c_loop_ub; c2_i278++) {
    c2_r6->data[c2_i278] = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_locationsVar->
      data[c2_i278], 1, 19200);
  }

  c2_tmp_size[0] = c2_locationsVar->size[0];
  c2_d_loop_ub = c2_locationsVar->size[0] - 1;
  for (c2_i279 = 0; c2_i279 <= c2_d_loop_ub; c2_i279++) {
    c2_tmp_data[c2_i279] = c2_b_mask[(int32_T)c2_locationsVar->data[c2_i279] - 1];
  }

  c2_emxFree_real_T(chartInstance, &c2_locationsVar);
  _SFD_SUB_ASSIGN_SIZE_CHECK_1D(c2_r6->size[0], c2_tmp_size[0]);
  c2_e_loop_ub = c2_tmp_size[0] - 1;
  for (c2_i280 = 0; c2_i280 <= c2_e_loop_ub; c2_i280++) {
    c2_I2[c2_r6->data[c2_i280] - 1] = c2_tmp_data[c2_i280];
  }

  c2_emxFree_int32_T(chartInstance, &c2_r6);
  for (c2_i281 = 0; c2_i281 < 2; c2_i281++) {
    c2_imSizeT[c2_i281] = 120.0 + 40.0 * (real_T)c2_i281;
  }

  ippreconstruct_uint8(c2_I2, c2_b_mask, c2_imSizeT, 2.0);
  for (c2_i282 = 0; c2_i282 < 19200; c2_i282++) {
    c2_I2[c2_i282] = (c2_h_varargin_1[c2_i282] || c2_I2[c2_i282]);
  }
}

static boolean_T c2_isequal(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_h_varargin_1, real_T c2_varargin_2)
{
  boolean_T c2_p;
  boolean_T c2_b_p;
  boolean_T c2_c_p;
  boolean_T c2_d_p;
  real_T c2_x1;
  boolean_T c2_e_p;
  (void)chartInstance;
  (void)c2_varargin_2;
  c2_p = false;
  c2_b_p = false;
  if ((real_T)c2_h_varargin_1->size[0] != 1.0) {
  } else {
    c2_b_p = true;
  }

  if (c2_b_p) {
    c2_c_p = true;
  } else {
    c2_c_p = false;
  }

  c2_d_p = c2_c_p;
  if (c2_c_p && (c2_h_varargin_1->size[0] != 0)) {
    c2_x1 = c2_h_varargin_1->data[0];
    c2_e_p = (c2_x1 == 0.0);
    if (!c2_e_p) {
      c2_d_p = false;
    }
  }

  if (!c2_d_p) {
  } else {
    c2_p = true;
  }

  return c2_p;
}

static void c2_checkLocations(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_locations, c2_emxArray_real_T
  *c2_locationsVar)
{
  c2_emxArray_real_T *c2_b_locations;
  int32_T c2_i283;
  int32_T c2_loop_ub;
  int32_T c2_i284;
  int32_T c2_i285;
  c2_emxArray_real_T *c2_c_locations;
  int32_T c2_badPixels_size[1];
  int32_T c2_i286;
  int32_T c2_b_loop_ub;
  int32_T c2_i287;
  int32_T c2_c_loop_ub;
  int32_T c2_tmp_size[1];
  boolean_T c2_badPixels_data[19200];
  int32_T c2_i288;
  int32_T c2_d_loop_ub;
  int32_T c2_i289;
  int32_T c2_e_loop_ub;
  int32_T c2_i290;
  boolean_T c2_tmp_data[19200];
  int32_T c2_i291;
  int32_T c2_f_loop_ub;
  int32_T c2_i292;
  int32_T c2_g_loop_ub;
  int32_T c2_b_badPixels_size[1];
  int32_T c2_i293;
  int32_T c2_h_loop_ub;
  int32_T c2_i294;
  boolean_T c2_b_badPixels_data[19200];
  real_T c2_numelBadPix;
  int32_T c2_i295;
  int32_T c2_s;
  real_T c2_b_s;
  c2_emxInit_real_T1(chartInstance, &c2_b_locations, 1, &c2_lc_emlrtRTEI);
  c2_i283 = c2_b_locations->size[0];
  c2_b_locations->size[0] = c2_locations->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_b_locations, c2_i283,
    &c2_lc_emlrtRTEI);
  c2_loop_ub = c2_locations->size[0] - 1;
  for (c2_i284 = 0; c2_i284 <= c2_loop_ub; c2_i284++) {
    c2_b_locations->data[c2_i284] = c2_locations->data[c2_i284];
  }

  c2_b_validateattributes(chartInstance, c2_b_locations);
  c2_i285 = c2_locationsVar->size[0];
  c2_locationsVar->size[0] = 0;
  c2_emxFree_real_T(chartInstance, &c2_b_locations);
  if (c2_locations->size[0] != 0) {
    c2_emxInit_real_T1(chartInstance, &c2_c_locations, 1, &c2_nc_emlrtRTEI);
    c2_i286 = c2_c_locations->size[0];
    c2_c_locations->size[0] = c2_locations->size[0] + c2_locationsVar->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_c_locations, c2_i286,
      &c2_nc_emlrtRTEI);
    c2_c_loop_ub = c2_locations->size[0] - 1;
    for (c2_i288 = 0; c2_i288 <= c2_c_loop_ub; c2_i288++) {
      c2_c_locations->data[c2_i288] = c2_locations->data[c2_i288];
    }

    c2_e_loop_ub = c2_locationsVar->size[0] - 1;
    for (c2_i290 = 0; c2_i290 <= c2_e_loop_ub; c2_i290++) {
      c2_c_locations->data[c2_i290 + c2_locations->size[0]] =
        c2_locationsVar->data[c2_i290];
    }

    c2_i291 = c2_locationsVar->size[0];
    c2_locationsVar->size[0] = c2_c_locations->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_locationsVar, c2_i291,
      &c2_pc_emlrtRTEI);
    c2_g_loop_ub = c2_c_locations->size[0] - 1;
    for (c2_i293 = 0; c2_i293 <= c2_g_loop_ub; c2_i293++) {
      c2_locationsVar->data[c2_i293] = c2_c_locations->data[c2_i293];
    }

    c2_emxFree_real_T(chartInstance, &c2_c_locations);
  }

  c2_badPixels_size[0] = c2_locations->size[0];
  c2_b_loop_ub = c2_locations->size[0] - 1;
  for (c2_i287 = 0; c2_i287 <= c2_b_loop_ub; c2_i287++) {
    c2_badPixels_data[c2_i287] = (c2_locations->data[c2_i287] < 1.0);
  }

  c2_tmp_size[0] = c2_locations->size[0];
  c2_d_loop_ub = c2_locations->size[0] - 1;
  for (c2_i289 = 0; c2_i289 <= c2_d_loop_ub; c2_i289++) {
    c2_tmp_data[c2_i289] = (c2_locations->data[c2_i289] > 19200.0);
  }

  _SFD_SIZE_EQ_CHECK_1D(c2_badPixels_size[0], c2_tmp_size[0]);
  c2_badPixels_size[0];
  c2_f_loop_ub = c2_badPixels_size[0] - 1;
  for (c2_i292 = 0; c2_i292 <= c2_f_loop_ub; c2_i292++) {
    c2_badPixels_data[c2_i292] = (c2_badPixels_data[c2_i292] ||
      c2_tmp_data[c2_i292]);
  }

  c2_b_badPixels_size[0] = c2_badPixels_size[0];
  c2_h_loop_ub = c2_badPixels_size[0] - 1;
  for (c2_i294 = 0; c2_i294 <= c2_h_loop_ub; c2_i294++) {
    c2_b_badPixels_data[c2_i294] = c2_badPixels_data[c2_i294];
  }

  if (c2_any(chartInstance, c2_b_badPixels_data, c2_b_badPixels_size)) {
    c2_numelBadPix = (real_T)c2_badPixels_size[0];
    c2_c_warning(chartInstance);
    c2_i295 = (int32_T)((1.0 + (-1.0 - c2_numelBadPix)) / -1.0);
    _SFD_FOR_LOOP_VECTOR_CHECK(c2_numelBadPix, -1.0, 1.0, mxDOUBLE_CLASS,
      c2_i295);
    for (c2_s = 0; c2_s < c2_i295; c2_s++) {
      c2_b_s = c2_numelBadPix + -(real_T)c2_s;
      if (c2_badPixels_data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           (int32_T)c2_b_s, 1, c2_badPixels_size[0]) - 1]) {
        c2_e_nullAssignment(chartInstance, c2_locationsVar, (int32_T)c2_b_s);
      }
    }
  }
}

static void c2_b_validateattributes(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_l_a)
{
  boolean_T c2_p;
  real_T c2_d8;
  int32_T c2_i296;
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_d_x;
  boolean_T c2_b11;
  boolean_T c2_b_p;
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv23[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'f',
    'i', 'l', 'l', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'P', 'o', 's',
    'i', 't', 'i', 'v', 'e' };

  boolean_T c2_c_p;
  const mxArray *c2_d_y = NULL;
  real_T c2_d9;
  int32_T c2_i297;
  const mxArray *c2_e_y = NULL;
  int32_T c2_c_k;
  static char_T c2_cv24[26] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '2', ',', ' ', 'L', 'O', 'C', 'A', 'T', 'I', 'O', 'N', 'S',
    ',' };

  real_T c2_d_k;
  real_T c2_e_x;
  boolean_T c2_b12;
  real_T c2_f_x;
  real_T c2_g_x;
  boolean_T c2_b;
  const mxArray *c2_f_y = NULL;
  boolean_T c2_b13;
  static char_T c2_cv25[29] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'f',
    'i', 'l', 'l', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I', 'n', 't',
    'e', 'g', 'e', 'r' };

  real_T c2_h_x;
  const mxArray *c2_g_y = NULL;
  boolean_T c2_b_b;
  boolean_T c2_b14;
  const mxArray *c2_h_y = NULL;
  boolean_T c2_c_b;
  static char_T c2_cv26[26] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '2', ',', ' ', 'L', 'O', 'C', 'A', 'T', 'I', 'O', 'N', 'S',
    ',' };

  real_T c2_i_x;
  boolean_T c2_d_p;
  real_T c2_j_x;
  boolean_T c2_e_p;
  boolean_T exitg1;
  (void)chartInstance;
  c2_p = true;
  c2_d8 = (real_T)c2_l_a->size[0];
  c2_i296 = (int32_T)c2_d8 - 1;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k <= c2_i296)) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_d_x = c2_l_a->data[(int32_T)c2_b_k - 1];
    c2_b_p = !(c2_d_x <= 0.0);
    if (c2_b_p) {
      c2_k++;
    } else {
      c2_p = false;
      exitg1 = true;
    }
  }

  if (c2_p) {
    c2_b11 = true;
  } else {
    c2_b11 = false;
  }

  if (c2_b11) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv23, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv5, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv24, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c2_d_y, 14, c2_e_y)));
  }

  c2_c_p = true;
  c2_d9 = (real_T)c2_l_a->size[0];
  c2_i297 = (int32_T)c2_d9 - 1;
  c2_c_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_c_k <= c2_i297)) {
    c2_d_k = 1.0 + (real_T)c2_c_k;
    c2_e_x = c2_l_a->data[(int32_T)c2_d_k - 1];
    c2_f_x = c2_e_x;
    c2_g_x = c2_f_x;
    c2_b = muDoubleScalarIsInf(c2_g_x);
    c2_b13 = !c2_b;
    c2_h_x = c2_f_x;
    c2_b_b = muDoubleScalarIsNaN(c2_h_x);
    c2_b14 = !c2_b_b;
    c2_c_b = (c2_b13 && c2_b14);
    if (c2_c_b) {
      c2_i_x = c2_e_x;
      c2_j_x = c2_i_x;
      c2_j_x = muDoubleScalarFloor(c2_j_x);
      if (c2_j_x == c2_e_x) {
        c2_d_p = true;
      } else {
        c2_d_p = false;
      }
    } else {
      c2_d_p = false;
    }

    c2_e_p = c2_d_p;
    if (c2_e_p) {
      c2_c_k++;
    } else {
      c2_c_p = false;
      exitg1 = true;
    }
  }

  if (c2_c_p) {
    c2_b12 = true;
  } else {
    c2_b12 = false;
  }

  if (c2_b12) {
  } else {
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv25, 10, 0U, 1U, 0U, 2, 1, 29),
                  false);
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_cv6, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c2_h_y = NULL;
    sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv26, 10, 0U, 1U, 0U, 2, 1, 26),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_f_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c2_g_y, 14, c2_h_y)));
  }
}

static boolean_T c2_any(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_x_data[], int32_T c2_x_size[1])
{
  boolean_T c2_c_y;
  boolean_T c2_b15;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  real_T c2_vlen;
  real_T c2_l_a;
  int32_T c2_c;
  int32_T c2_m_a;
  int32_T c2_vspread;
  int32_T c2_b;
  int32_T c2_c_i2;
  int32_T c2_n_a;
  int32_T c2_b_b;
  int32_T c2_c_b;
  boolean_T c2_overflow;
  int32_T c2_ix;
  boolean_T c2_b16;
  boolean_T exitg1;
  if ((c2_x_size[0] == 1) || ((real_T)c2_x_size[0] != 1.0)) {
    c2_b15 = true;
  } else {
    c2_b15 = false;
  }

  if (c2_b15) {
  } else {
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv7, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv7, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_d_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_e_y)));
  }

  c2_c_y = false;
  c2_vlen = (real_T)c2_x_size[0];
  c2_l_a = c2_vlen;
  c2_c = (int32_T)c2_l_a;
  c2_m_a = c2_c - 1;
  c2_vspread = c2_m_a;
  c2_b = c2_vspread;
  c2_c_i2 = c2_b;
  c2_n_a = c2_c_i2 + 1;
  c2_c_i2 = c2_n_a;
  c2_b_b = c2_c_i2;
  c2_c_b = c2_b_b;
  if (1 > c2_c_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_c_b > 2147483646);
  }

  if (c2_overflow) {
    c2_check_forloop_overflow_error(chartInstance, true);
  }

  c2_ix = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_ix + 1 <= c2_c_i2)) {
    if (!c2_x_data[c2_ix]) {
      c2_b16 = true;
    } else {
      c2_b16 = false;
    }

    if (!c2_b16) {
      c2_c_y = true;
      exitg1 = true;
    } else {
      c2_ix++;
    }
  }

  return c2_c_y;
}

static void c2_c_warning(SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv27[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c2_d_y = NULL;
  static char_T c2_cv28[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c2_e_y = NULL;
  static char_T c2_msgID[24] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm',
    'f', 'i', 'l', 'l', ':', 'o', 'u', 't', 'O', 'f', 'R', 'a', 'n', 'g', 'e' };

  (void)chartInstance;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv27, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv28, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_msgID, 10, 0U, 1U, 0U, 2, 1, 24),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c2_c_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c2_d_y, 14, c2_e_y));
}

static void c2_b_nullAssignment(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_d_x, int32_T c2_b_idx,
  c2_emxArray_real_T *c2_e_x)
{
  int32_T c2_i298;
  int32_T c2_loop_ub;
  int32_T c2_i299;
  c2_i298 = c2_e_x->size[0];
  c2_e_x->size[0] = c2_d_x->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_e_x, c2_i298, &c2_dc_emlrtRTEI);
  c2_loop_ub = c2_d_x->size[0] - 1;
  for (c2_i299 = 0; c2_i299 <= c2_loop_ub; c2_i299++) {
    c2_e_x->data[c2_i299] = c2_d_x->data[c2_i299];
  }

  c2_e_nullAssignment(chartInstance, c2_e_x, c2_b_idx);
}

static boolean_T c2_b_isequal(SFc2_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c2_h_varargin_1[19200], boolean_T c2_varargin_2
  [19200])
{
  boolean_T c2_p;
  boolean_T c2_b_p;
  int32_T c2_k;
  real_T c2_b_k;
  boolean_T c2_x1;
  boolean_T c2_x2;
  boolean_T c2_c_p;
  boolean_T exitg1;
  (void)chartInstance;
  c2_p = false;
  c2_b_p = true;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k < 19200)) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_x1 = c2_h_varargin_1[(int32_T)c2_b_k - 1];
    c2_x2 = c2_varargin_2[(int32_T)c2_b_k - 1];
    c2_c_p = ((int32_T)c2_x1 == (int32_T)c2_x2);
    if (!c2_c_p) {
      c2_b_p = false;
      exitg1 = true;
    } else {
      c2_k++;
    }
  }

  if (!c2_b_p) {
  } else {
    c2_p = true;
  }

  return c2_p;
}

static boolean_T c2_all(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real_T c2_l_a[2])
{
  boolean_T c2_p;
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  boolean_T c2_b;
  boolean_T c2_b17;
  real_T c2_g_x;
  boolean_T c2_b_b;
  boolean_T c2_b18;
  boolean_T c2_c_b;
  real_T c2_h_x;
  boolean_T c2_b_p;
  real_T c2_i_x;
  boolean_T c2_c_p;
  boolean_T exitg1;
  (void)chartInstance;
  c2_p = true;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k < 2)) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_d_x = c2_l_a[(int32_T)c2_b_k - 1];
    c2_e_x = c2_d_x;
    c2_f_x = c2_e_x;
    c2_b = muDoubleScalarIsInf(c2_f_x);
    c2_b17 = !c2_b;
    c2_g_x = c2_e_x;
    c2_b_b = muDoubleScalarIsNaN(c2_g_x);
    c2_b18 = !c2_b_b;
    c2_c_b = (c2_b17 && c2_b18);
    if (c2_c_b) {
      c2_h_x = c2_d_x;
      c2_i_x = c2_h_x;
      c2_i_x = muDoubleScalarFloor(c2_i_x);
      if (c2_i_x == c2_d_x) {
        c2_b_p = true;
      } else {
        c2_b_p = false;
      }
    } else {
      c2_b_p = false;
    }

    c2_c_p = c2_b_p;
    if (c2_c_p) {
      c2_k++;
    } else {
      c2_p = false;
      exitg1 = true;
    }
  }

  return c2_p;
}

static boolean_T c2_b_all(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_d_x[19200])
{
  boolean_T c2_c_y;
  int32_T c2_k;
  real_T c2_b_k;
  boolean_T exitg1;
  (void)chartInstance;
  c2_c_y = true;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k < 19200)) {
    c2_b_k = 1.0 + (real_T)c2_k;
    if (!c2_d_x[(int32_T)c2_b_k - 1]) {
      c2_c_y = false;
      exitg1 = true;
    } else {
      c2_k++;
    }
  }

  return c2_c_y;
}

static void c2_c_padImage(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_a_tmp[19200], real_T c2_boundary_pos, int8_T c2_boundaryEnum,
  real_T c2_boundaryStr_pos, real32_T c2_l_a[20336])
{
  int32_T c2_j;
  real_T c2_b_j;
  int32_T c2_i;
  real_T c2_b_i;
  static int32_T c2_idxA[328] = { 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88,
    89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105,
    106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
    120, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 3, 4, 5, 6,
    7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
    27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45,
    46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64,
    65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83,
    84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101,
    102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116,
    117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131,
    132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146,
    147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 160,
    160 };

  (void)c2_boundary_pos;
  (void)c2_boundaryEnum;
  (void)c2_boundaryStr_pos;
  for (c2_j = 0; c2_j < 164; c2_j++) {
    c2_b_j = 1.0 + (real_T)c2_j;
    for (c2_i = 0; c2_i < 124; c2_i++) {
      c2_b_i = 1.0 + (real_T)c2_i;
      c2_l_a[((int32_T)c2_b_i + 124 * ((int32_T)c2_b_j - 1)) - 1] = c2_a_tmp
        [(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
           chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_idxA[(int32_T)c2_b_i - 1],
           1, 120) + 120 * (sf_eml_array_bounds_check
                            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U,
            0, 0, MAX_uint32_T, c2_idxA[(int32_T)c2_b_j + 163], 1, 160) - 1)) -
        1];
    }
  }
}

static void c2_e_imfilter(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_h_varargin_1[19200], real32_T c2_b[19200])
{
  int32_T c2_i300;
  real32_T c2_i_varargin_1[19200];
  boolean_T c2_tooBig;
  int32_T c2_i;
  boolean_T c2_modeFlag;
  boolean_T c2_b_modeFlag;
  boolean_T c2_c_modeFlag;
  int32_T c2_i301;
  int32_T c2_i302;
  int32_T c2_i303;
  real_T c2_padSizeT[2];
  int32_T c2_i304;
  int32_T c2_i305;
  real_T c2_outSizeT[2];
  int32_T c2_i306;
  int32_T c2_i307;
  real_T c2_connDimsT[2];
  static real_T c2_kernel[9] = { -1.0, -2.0, -1.0, -0.0, -0.0, -0.0, 1.0, 2.0,
    1.0 };

  static real_T c2_nonZeroKernel[6] = { -1.0, -2.0, -1.0, 1.0, 2.0, 1.0 };

  static boolean_T c2_conn[9] = { true, true, true, false, false, false, true,
    true, true };

  real_T c2_startT[2];
  for (c2_i300 = 0; c2_i300 < 19200; c2_i300++) {
    c2_i_varargin_1[c2_i300] = c2_h_varargin_1[c2_i300];
  }

  c2_d_padImage(chartInstance, c2_i_varargin_1, 0.0, 3, 3.0,
                chartInstance->c2_k_a);
  c2_tooBig = true;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_tooBig = false;
  }

  if (!c2_tooBig) {
    c2_modeFlag = true;
  } else {
    c2_modeFlag = false;
  }

  if (c2_modeFlag) {
    c2_b_modeFlag = true;
  } else {
    c2_b_modeFlag = false;
  }

  c2_c_modeFlag = c2_b_modeFlag;
  if (c2_c_modeFlag) {
    for (c2_i302 = 0; c2_i302 < 2; c2_i302++) {
      c2_padSizeT[c2_i302] = 122.0 + 40.0 * (real_T)c2_i302;
    }

    for (c2_i304 = 0; c2_i304 < 2; c2_i304++) {
      c2_outSizeT[c2_i304] = 120.0 + 40.0 * (real_T)c2_i304;
    }

    for (c2_i306 = 0; c2_i306 < 2; c2_i306++) {
      c2_connDimsT[c2_i306] = 3.0;
    }

    ippfilter_real32(chartInstance->c2_k_a, c2_b, c2_outSizeT, 2.0, c2_padSizeT,
                     c2_kernel, c2_connDimsT, true);
  } else {
    for (c2_i301 = 0; c2_i301 < 2; c2_i301++) {
      c2_padSizeT[c2_i301] = 122.0 + 40.0 * (real_T)c2_i301;
    }

    for (c2_i303 = 0; c2_i303 < 2; c2_i303++) {
      c2_outSizeT[c2_i303] = 120.0 + 40.0 * (real_T)c2_i303;
    }

    for (c2_i305 = 0; c2_i305 < 2; c2_i305++) {
      c2_connDimsT[c2_i305] = 3.0;
    }

    for (c2_i307 = 0; c2_i307 < 2; c2_i307++) {
      c2_startT[c2_i307] = 1.0;
    }

    imfilter_real32(chartInstance->c2_k_a, c2_b, 2.0, c2_outSizeT, 2.0,
                    c2_padSizeT, c2_nonZeroKernel, 6.0, c2_conn, 2.0,
                    c2_connDimsT, c2_startT, 2.0, true, true);
  }
}

static void c2_d_padImage(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_a_tmp[19200], real_T c2_boundary_pos, int8_T c2_boundaryEnum,
  real_T c2_boundaryStr_pos, real32_T c2_l_a[19764])
{
  int32_T c2_j;
  real_T c2_b_j;
  int32_T c2_i;
  real_T c2_b_i;
  static int32_T c2_idxA[324] = { 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
    33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
    71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
    90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106,
    107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 120, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
    12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68,
    69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87,
    88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105,
    106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
    121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135,
    136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150,
    151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 160 };

  (void)c2_boundary_pos;
  (void)c2_boundaryEnum;
  (void)c2_boundaryStr_pos;
  for (c2_j = 0; c2_j < 162; c2_j++) {
    c2_b_j = 1.0 + (real_T)c2_j;
    for (c2_i = 0; c2_i < 122; c2_i++) {
      c2_b_i = 1.0 + (real_T)c2_i;
      c2_l_a[((int32_T)c2_b_i + 122 * ((int32_T)c2_b_j - 1)) - 1] = c2_a_tmp
        [(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
           chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_idxA[(int32_T)c2_b_i - 1],
           1, 120) + 120 * (sf_eml_array_bounds_check
                            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U,
            0, 0, MAX_uint32_T, c2_idxA[(int32_T)c2_b_j + 161], 1, 160) - 1)) -
        1];
    }
  }
}

static void c2_f_imfilter(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_h_varargin_1[19200], real32_T c2_b[19200])
{
  int32_T c2_i308;
  real32_T c2_i_varargin_1[19200];
  boolean_T c2_tooBig;
  int32_T c2_i;
  boolean_T c2_modeFlag;
  boolean_T c2_b_modeFlag;
  boolean_T c2_c_modeFlag;
  int32_T c2_i309;
  int32_T c2_i310;
  int32_T c2_i311;
  real_T c2_padSizeT[2];
  int32_T c2_i312;
  int32_T c2_i313;
  real_T c2_outSizeT[2];
  int32_T c2_i314;
  int32_T c2_i315;
  real_T c2_connDimsT[2];
  static real_T c2_kernel[9] = { -1.0, -0.0, 1.0, -2.0, -0.0, 2.0, -1.0, -0.0,
    1.0 };

  static real_T c2_nonZeroKernel[6] = { -1.0, 1.0, -2.0, 2.0, -1.0, 1.0 };

  static boolean_T c2_conn[9] = { true, false, true, true, false, true, true,
    false, true };

  real_T c2_startT[2];
  for (c2_i308 = 0; c2_i308 < 19200; c2_i308++) {
    c2_i_varargin_1[c2_i308] = c2_h_varargin_1[c2_i308];
  }

  c2_d_padImage(chartInstance, c2_i_varargin_1, 0.0, 3, 3.0,
                chartInstance->c2_j_a);
  c2_tooBig = true;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_tooBig = false;
  }

  if (!c2_tooBig) {
    c2_modeFlag = true;
  } else {
    c2_modeFlag = false;
  }

  if (c2_modeFlag) {
    c2_b_modeFlag = true;
  } else {
    c2_b_modeFlag = false;
  }

  c2_c_modeFlag = c2_b_modeFlag;
  if (c2_c_modeFlag) {
    for (c2_i310 = 0; c2_i310 < 2; c2_i310++) {
      c2_padSizeT[c2_i310] = 122.0 + 40.0 * (real_T)c2_i310;
    }

    for (c2_i312 = 0; c2_i312 < 2; c2_i312++) {
      c2_outSizeT[c2_i312] = 120.0 + 40.0 * (real_T)c2_i312;
    }

    for (c2_i314 = 0; c2_i314 < 2; c2_i314++) {
      c2_connDimsT[c2_i314] = 3.0;
    }

    ippfilter_real32(chartInstance->c2_j_a, c2_b, c2_outSizeT, 2.0, c2_padSizeT,
                     c2_kernel, c2_connDimsT, true);
  } else {
    for (c2_i309 = 0; c2_i309 < 2; c2_i309++) {
      c2_padSizeT[c2_i309] = 122.0 + 40.0 * (real_T)c2_i309;
    }

    for (c2_i311 = 0; c2_i311 < 2; c2_i311++) {
      c2_outSizeT[c2_i311] = 120.0 + 40.0 * (real_T)c2_i311;
    }

    for (c2_i313 = 0; c2_i313 < 2; c2_i313++) {
      c2_connDimsT[c2_i313] = 3.0;
    }

    for (c2_i315 = 0; c2_i315 < 2; c2_i315++) {
      c2_startT[c2_i315] = 1.0;
    }

    imfilter_real32(chartInstance->c2_j_a, c2_b, 2.0, c2_outSizeT, 2.0,
                    c2_padSizeT, c2_nonZeroKernel, 6.0, c2_conn, 2.0,
                    c2_connDimsT, c2_startT, 2.0, true, true);
  }
}

static boolean_T c2_b_isfinite(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real32_T c2_d_x)
{
  real32_T c2_e_x;
  boolean_T c2_b_b;
  boolean_T c2_b19;
  real32_T c2_f_x;
  boolean_T c2_c_b;
  boolean_T c2_b20;
  (void)chartInstance;
  c2_e_x = c2_d_x;
  c2_b_b = muSingleScalarIsInf(c2_e_x);
  c2_b19 = !c2_b_b;
  c2_f_x = c2_d_x;
  c2_c_b = muSingleScalarIsNaN(c2_f_x);
  c2_b20 = !c2_c_b;
  return c2_b19 && c2_b20;
}

static void c2_imfindcircles(SFc2_flightControlSystemInstanceStruct
  *chartInstance, boolean_T c2_h_varargin_1[19200], c2_emxArray_real_T
  *c2_centers, c2_emxArray_real_T *c2_r_estimated, c2_emxArray_real_T *c2_metric)
{
  int32_T c2_i316;
  int32_T c2_i317;
  int32_T c2_i318;
  int32_T c2_i319;
  int32_T c2_i320;
  int32_T c2_i321;
  int32_T c2_i322;
  int32_T c2_i323;
  int32_T c2_i324;
  int32_T c2_i325;
  boolean_T c2_i_varargin_1[19200];
  int32_T c2_i326;
  boolean_T c2_c_y;
  int32_T c2_k;
  real_T c2_b_k;
  boolean_T c2_d_x;
  static creal_T c2_dc0 = { 0.0,       /* re */
    0.0                                /* im */
  };

  int32_T c2_i327;
  creal_T c2_e_x;
  c2_emxArray_real_T *c2_b_centers;
  boolean_T c2_b21;
  boolean_T c2_b22;
  c2_emxArray_real_T *c2_b_metric;
  boolean_T c2_b23;
  boolean_T c2_b;
  int32_T c2_i328;
  int32_T c2_i329;
  int32_T c2_i330;
  int32_T c2_loop_ub;
  int32_T c2_i331;
  int32_T c2_i332;
  int32_T c2_i333;
  int32_T c2_i334;
  int32_T c2_b_loop_ub;
  int32_T c2_i335;
  boolean_T c2_b24;
  boolean_T c2_b25;
  c2_emxArray_boolean_T *c2_f_x;
  int32_T c2_i336;
  int32_T c2_i337;
  int32_T c2_i338;
  int32_T c2_c_loop_ub;
  int32_T c2_i339;
  c2_emxArray_int32_T *c2_ii;
  int32_T c2_nx;
  int32_T c2_c_k;
  int32_T c2_b_nx;
  int32_T c2_b_idx;
  int32_T c2_i340;
  int32_T c2_b_b;
  int32_T c2_c_b;
  boolean_T c2_overflow;
  int32_T c2_b_ii;
  int32_T c2_c_ii;
  const mxArray *c2_d_y = NULL;
  c2_emxArray_int32_T *c2_d_b;
  const mxArray *c2_e_y = NULL;
  boolean_T c2_b26;
  int32_T c2_i341;
  int32_T c2_i342;
  c2_emxArray_real_T *c2_idx2Keep;
  int32_T c2_i343;
  int32_T c2_i344;
  int32_T c2_d_loop_ub;
  int32_T c2_e_loop_ub;
  int32_T c2_i345;
  int32_T c2_i346;
  int32_T c2_iv6[2];
  int32_T c2_c_centers;
  int32_T c2_i347;
  int32_T c2_i348;
  int32_T c2_i349;
  int32_T c2_f_loop_ub;
  int32_T c2_i350;
  int32_T c2_c_metric;
  int32_T c2_g_loop_ub;
  int32_T c2_i351;
  int32_T c2_i352;
  int32_T c2_i353;
  int32_T c2_h_loop_ub;
  int32_T c2_i354;
  boolean_T c2_b27;
  int32_T c2_i_loop_ub;
  boolean_T c2_b28;
  int32_T c2_i355;
  boolean_T c2_p;
  int32_T c2_i356;
  real_T c2_d10;
  int32_T c2_i357;
  int32_T c2_d_k;
  int32_T c2_i358;
  int32_T c2_i359;
  int32_T c2_i360;
  real_T c2_e_k;
  real_T c2_g_x;
  boolean_T c2_b29;
  boolean_T c2_b_p;
  int32_T c2_i361;
  int32_T c2_i362;
  const mxArray *c2_f_y = NULL;
  static char_T c2_cv29[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h', 'r',
    'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  boolean_T c2_b30;
  const mxArray *c2_g_y = NULL;
  boolean_T c2_b31;
  const mxArray *c2_h_y = NULL;
  const mxArray *c2_i_y = NULL;
  static char_T c2_cv30[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '1', ',', ' ', 'c', 'e', 'n', 't', 'e', 'r', 's', ',' };

  static char_T c2_cv31[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h', 'r',
    'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'N', 'o', 'n', 'e', 'm', 'p', 't', 'y' };

  const mxArray *c2_j_y = NULL;
  const mxArray *c2_k_y = NULL;
  static char_T c2_cv32[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
    'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    'N', 'o', 'n', 'e', 'm', 'p', 't', 'y' };

  static char_T c2_cv33[37] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'h', 'r',
    'a', 'd', 'i', 'i', 'p', 'h', 'c', 'o', 'd', 'e', ':', 'i', 'n', 'c', 'o',
    'r', 'r', 'e', 'c', 't', 'N', 'u', 'm', 'c', 'o', 'l', 's' };

  c2_emxArray_boolean_T *c2_d_centers;
  const mxArray *c2_l_y = NULL;
  const mxArray *c2_m_y = NULL;
  static char_T c2_cv34[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '1', ',', ' ', 'c', 'e', 'n', 't', 'e', 'r', 's', ',' };

  static char_T c2_cv35[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
    'r', 'i', 'b', 'u', 't', 'e', 's', 'i', 'n', 'c', 'o', 'r', 'r', 'e', 'c',
    't', 'N', 'u', 'm', 'c', 'o', 'l', 's' };

  int32_T c2_i363;
  const mxArray *c2_n_y = NULL;
  int32_T c2_i364;
  static char_T c2_cv36[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '1', ',', ' ', 'c', 'e', 'n', 't', 'e', 'r', 's', ',' };

  real_T c2_e_u;
  const mxArray *c2_o_y = NULL;
  int32_T c2_j_loop_ub;
  int32_T c2_i365;
  c2_emxArray_boolean_T *c2_e_centers;
  boolean_T c2_b32;
  int32_T c2_i366;
  int32_T c2_i367;
  int32_T c2_k_loop_ub;
  const mxArray *c2_p_y = NULL;
  int32_T c2_i368;
  static char_T c2_cv37[38] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'i', 'm', 'f',
    'i', 'n', 'd', 'c', 'i', 'r', 'c', 'l', 'e', 's', ':', 'o', 'u', 't', 'O',
    'f', 'B', 'o', 'u', 'n', 'd', 'C', 'e', 'n', 't', 'e', 'r', 's' };

  const mxArray *c2_q_y = NULL;
  int32_T c2_i369;
  int32_T c2_i370;
  int32_T c2_l_loop_ub;
  int32_T c2_i371;
  c2_emxArray_real_T *c2_varargin_2;
  int32_T c2_i372;
  int32_T c2_i373;
  int32_T c2_m_loop_ub;
  int32_T c2_i374;
  c2_emxArray_real_T *c2_b_idx2Keep;
  int32_T c2_i375;
  int32_T c2_n_loop_ub;
  int32_T c2_i376;
  const mxArray *c2_r_y = NULL;
  const mxArray *c2_s_y = NULL;
  real_T c2_j_varargin_1[2];
  real_T c2_b_varargin_2[2];
  int32_T c2_i377;
  int32_T c2_i378;
  int32_T c2_i379;
  int32_T c2_i380;
  boolean_T c2_c_p;
  int32_T c2_i381;
  int32_T c2_i382;
  boolean_T c2_d_p;
  int32_T c2_f_k;
  real_T c2_g_k;
  real_T c2_x1;
  real_T c2_x2;
  boolean_T c2_e_p;
  const mxArray *c2_t_y = NULL;
  c2_emxArray_real_T *c2_c_varargin_2;
  const mxArray *c2_u_y = NULL;
  int32_T c2_i383;
  int32_T c2_o_loop_ub;
  int32_T c2_i384;
  const mxArray *c2_v_y = NULL;
  const mxArray *c2_w_y = NULL;
  int32_T c2_i385;
  int32_T c2_p_loop_ub;
  int32_T c2_i386;
  int32_T c2_i387;
  int32_T c2_q_loop_ub;
  int32_T c2_i388;
  int32_T c2_i389;
  int32_T c2_r_loop_ub;
  int32_T c2_i390;
  int32_T c2_i391;
  int32_T c2_s_loop_ub;
  int32_T c2_i392;
  int32_T c2_i393;
  int32_T c2_t_loop_ub;
  int32_T c2_i394;
  c2_emxArray_creal_T *c2_h_x;
  int32_T c2_i395;
  int32_T c2_u_loop_ub;
  int32_T c2_i396;
  int32_T c2_c_nx;
  int32_T c2_i397;
  int32_T c2_i398;
  int32_T c2_e_b;
  int32_T c2_f_b;
  boolean_T c2_b_overflow;
  int32_T c2_h_k;
  int32_T c2_i_k;
  int32_T c2_i399;
  real_T c2_x_y;
  real_T c2_i_x;
  int32_T c2_v_loop_ub;
  real_T c2_y_y;
  int32_T c2_i400;
  int32_T c2_i401;
  int32_T c2_w_loop_ub;
  int32_T c2_i402;
  int32_T c2_i403;
  int32_T c2_x_loop_ub;
  int32_T c2_i404;
  int32_T c2_d_nx;
  int32_T c2_g_b;
  int32_T c2_h_b;
  boolean_T c2_c_overflow;
  int32_T c2_j_k;
  int32_T c2_i405;
  int32_T c2_k_k;
  real_T c2_j_x;
  real_T c2_k_x;
  int32_T c2_i406;
  int32_T c2_i407;
  int32_T c2_y_loop_ub;
  int32_T c2_i408;
  boolean_T exitg1;
  c2_i316 = c2_centers->size[0] * c2_centers->size[1];
  c2_centers->size[0] = 0;
  c2_centers->size[1] = 0;
  c2_i317 = c2_centers->size[0];
  c2_i318 = c2_centers->size[1];
  c2_i319 = c2_r_estimated->size[0] * c2_r_estimated->size[1];
  c2_r_estimated->size[0] = 0;
  c2_r_estimated->size[1] = 0;
  c2_i320 = c2_r_estimated->size[0];
  c2_i321 = c2_r_estimated->size[1];
  c2_i322 = c2_metric->size[0] * c2_metric->size[1];
  c2_metric->size[0] = 0;
  c2_metric->size[1] = 0;
  c2_i323 = c2_metric->size[0];
  c2_i324 = c2_metric->size[1];
  for (c2_i325 = 0; c2_i325 < 19200; c2_i325++) {
    c2_i_varargin_1[c2_i325] = c2_h_varargin_1[c2_i325];
  }

  c2_chaccum(chartInstance, c2_i_varargin_1, chartInstance->c2_accumMatrix,
             chartInstance->c2_gradientImg);
  for (c2_i326 = 0; c2_i326 < 19200; c2_i326++) {
    chartInstance->c2_x[c2_i326] = chartInstance->c2_accumMatrix[c2_i326];
  }

  c2_c_y = false;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k < 19200)) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_d_x = ((chartInstance->c2_x[(int32_T)c2_b_k - 1].re == c2_dc0.re) &&
              (chartInstance->c2_x[(int32_T)c2_b_k - 1].im == c2_dc0.im));
    if (c2_d_x) {
      c2_b22 = true;
    } else {
      c2_e_x = chartInstance->c2_x[(int32_T)c2_b_k - 1];
      c2_b21 = muDoubleScalarIsNaN(c2_e_x.re);
      c2_b23 = muDoubleScalarIsNaN(c2_e_x.im);
      c2_b = (c2_b21 || c2_b23);
      if (c2_b) {
        c2_b22 = true;
      } else {
        c2_b22 = false;
      }
    }

    if (!c2_b22) {
      c2_c_y = true;
      exitg1 = true;
    } else {
      c2_k++;
    }
  }

  if (!c2_c_y) {
  } else {
    for (c2_i327 = 0; c2_i327 < 19200; c2_i327++) {
      chartInstance->c2_b_accumMatrix[c2_i327] = chartInstance->
        c2_accumMatrix[c2_i327];
    }

    c2_emxInit_real_T(chartInstance, &c2_b_centers, 2, &c2_id_emlrtRTEI);
    c2_emxInit_real_T(chartInstance, &c2_b_metric, 2, &c2_id_emlrtRTEI);
    c2_chcenters(chartInstance, chartInstance->c2_b_accumMatrix, c2_b_centers,
                 c2_b_metric);
    c2_i328 = c2_centers->size[0] * c2_centers->size[1];
    c2_centers->size[0] = c2_b_centers->size[0];
    c2_centers->size[1] = c2_b_centers->size[1];
    c2_emxEnsureCapacity_real_T(chartInstance, c2_centers, c2_i328,
      &c2_sc_emlrtRTEI);
    c2_i329 = c2_centers->size[0];
    c2_i330 = c2_centers->size[1];
    c2_loop_ub = c2_b_centers->size[0] * c2_b_centers->size[1] - 1;
    for (c2_i331 = 0; c2_i331 <= c2_loop_ub; c2_i331++) {
      c2_centers->data[c2_i331] = c2_b_centers->data[c2_i331];
    }

    c2_i332 = c2_metric->size[0] * c2_metric->size[1];
    c2_metric->size[0] = c2_b_metric->size[0];
    c2_metric->size[1] = c2_b_metric->size[1];
    c2_emxEnsureCapacity_real_T(chartInstance, c2_metric, c2_i332,
      &c2_tc_emlrtRTEI);
    c2_i333 = c2_metric->size[0];
    c2_i334 = c2_metric->size[1];
    c2_b_loop_ub = c2_b_metric->size[0] * c2_b_metric->size[1] - 1;
    for (c2_i335 = 0; c2_i335 <= c2_b_loop_ub; c2_i335++) {
      c2_metric->data[c2_i335] = c2_b_metric->data[c2_i335];
    }

    c2_b24 = (c2_b_centers->size[0] == 0);
    c2_b25 = (c2_b_centers->size[1] == 0);
    if (c2_b24 || c2_b25) {
    } else {
      c2_emxInit_boolean_T(chartInstance, &c2_f_x, 2, &c2_uc_emlrtRTEI);
      c2_i336 = c2_f_x->size[0] * c2_f_x->size[1];
      c2_f_x->size[0] = c2_b_metric->size[0];
      c2_f_x->size[1] = c2_b_metric->size[1];
      c2_emxEnsureCapacity_boolean_T(chartInstance, c2_f_x, c2_i336,
        &c2_uc_emlrtRTEI);
      c2_i337 = c2_f_x->size[0];
      c2_i338 = c2_f_x->size[1];
      c2_c_loop_ub = c2_b_metric->size[0] * c2_b_metric->size[1] - 1;
      for (c2_i339 = 0; c2_i339 <= c2_c_loop_ub; c2_i339++) {
        c2_f_x->data[c2_i339] = (c2_b_metric->data[c2_i339] >=
          0.15000000000000002);
      }

      c2_emxInit_int32_T(chartInstance, &c2_ii, 1, &c2_nb_emlrtRTEI);
      c2_nx = c2_f_x->size[0] * c2_f_x->size[1];
      c2_c_k = c2_nx;
      c2_b_nx = c2_nx;
      c2_b_idx = 0;
      c2_i340 = c2_ii->size[0];
      c2_ii->size[0] = c2_c_k;
      c2_emxEnsureCapacity_int32_T(chartInstance, c2_ii, c2_i340,
        &c2_g_emlrtRTEI);
      c2_b_b = c2_b_nx;
      c2_c_b = c2_b_b;
      if (1 > c2_c_b) {
        c2_overflow = false;
      } else {
        c2_overflow = (c2_c_b > 2147483646);
      }

      if (c2_overflow) {
        c2_check_forloop_overflow_error(chartInstance, true);
      }

      c2_b_ii = 0;
      exitg1 = false;
      while ((!exitg1) && (c2_b_ii <= c2_b_nx - 1)) {
        c2_c_ii = c2_b_ii;
        if (c2_f_x->data[c2_c_ii]) {
          c2_b_idx++;
          c2_ii->data[c2_b_idx - 1] = c2_c_ii + 1;
          if (c2_b_idx >= c2_c_k) {
            exitg1 = true;
          } else {
            c2_b_ii++;
          }
        } else {
          c2_b_ii++;
        }
      }

      c2_emxFree_boolean_T(chartInstance, &c2_f_x);
      if (c2_b_idx <= c2_c_k) {
      } else {
        c2_d_y = NULL;
        sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1,
          30), false);
        c2_e_y = NULL;
        sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1,
          30), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                          c2_d_y, 14, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "getString", 1U, 1U, 14,
                           sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 1U, 14, c2_e_y)));
      }

      c2_emxInit_int32_T(chartInstance, &c2_d_b, 1, &c2_ib_emlrtRTEI);
      if (c2_c_k == 1) {
        if (c2_b_idx == 0) {
          c2_i341 = c2_ii->size[0];
          c2_ii->size[0] = 0;
        }
      } else {
        c2_b26 = (1 > c2_b_idx);
        if (c2_b26) {
          c2_i342 = 0;
        } else {
          c2_i342 = c2_b_idx;
        }

        c2_i343 = c2_d_b->size[0];
        c2_d_b->size[0] = c2_i342;
        c2_emxEnsureCapacity_int32_T(chartInstance, c2_d_b, c2_i343,
          &c2_ab_emlrtRTEI);
        c2_d_loop_ub = c2_i342 - 1;
        for (c2_i345 = 0; c2_i345 <= c2_d_loop_ub; c2_i345++) {
          c2_d_b->data[c2_i345] = 1 + c2_i345;
        }

        c2_iv6[0] = 1;
        c2_iv6[1] = c2_d_b->size[0];
        c2_indexShapeCheck(chartInstance, c2_ii->size[0], c2_iv6);
        c2_i349 = c2_ii->size[0];
        c2_ii->size[0] = c2_i342;
        c2_emxEnsureCapacity_int32_T(chartInstance, c2_ii, c2_i349,
          &c2_db_emlrtRTEI);
      }

      c2_emxInit_real_T1(chartInstance, &c2_idx2Keep, 1, &c2_vc_emlrtRTEI);
      c2_i344 = c2_idx2Keep->size[0];
      c2_idx2Keep->size[0] = c2_ii->size[0];
      c2_emxEnsureCapacity_real_T1(chartInstance, c2_idx2Keep, c2_i344,
        &c2_vc_emlrtRTEI);
      c2_e_loop_ub = c2_ii->size[0] - 1;
      for (c2_i346 = 0; c2_i346 <= c2_e_loop_ub; c2_i346++) {
        c2_idx2Keep->data[c2_i346] = (real_T)c2_ii->data[c2_i346];
      }

      c2_c_centers = c2_b_centers->size[0];
      c2_i347 = c2_b_centers->size[1] - 1;
      c2_i348 = c2_centers->size[0] * c2_centers->size[1];
      c2_centers->size[0] = c2_idx2Keep->size[0];
      c2_centers->size[1] = c2_i347 + 1;
      c2_emxEnsureCapacity_real_T(chartInstance, c2_centers, c2_i348,
        &c2_wc_emlrtRTEI);
      c2_f_loop_ub = c2_i347;
      for (c2_i350 = 0; c2_i350 <= c2_f_loop_ub; c2_i350++) {
        c2_g_loop_ub = c2_idx2Keep->size[0] - 1;
        for (c2_i352 = 0; c2_i352 <= c2_g_loop_ub; c2_i352++) {
          c2_centers->data[c2_i352 + c2_centers->size[0] * c2_i350] =
            c2_b_centers->data[(sf_eml_array_bounds_check
                                (sfGlobalDebugInstanceStruct, chartInstance->S,
            1U, 0, 0, MAX_uint32_T, (int32_T)c2_idx2Keep->data[c2_i352], 1,
            c2_c_centers) + c2_b_centers->size[0] * c2_i350) - 1];
        }
      }

      c2_c_metric = c2_b_metric->size[0];
      c2_i351 = c2_b_metric->size[1] - 1;
      c2_i353 = c2_metric->size[0] * c2_metric->size[1];
      c2_metric->size[0] = c2_idx2Keep->size[0];
      c2_metric->size[1] = c2_i351 + 1;
      c2_emxEnsureCapacity_real_T(chartInstance, c2_metric, c2_i353,
        &c2_xc_emlrtRTEI);
      c2_h_loop_ub = c2_i351;
      for (c2_i354 = 0; c2_i354 <= c2_h_loop_ub; c2_i354++) {
        c2_i_loop_ub = c2_idx2Keep->size[0] - 1;
        for (c2_i355 = 0; c2_i355 <= c2_i_loop_ub; c2_i355++) {
          c2_metric->data[c2_i355 + c2_metric->size[0] * c2_i354] =
            c2_b_metric->data[(sf_eml_array_bounds_check
                               (sfGlobalDebugInstanceStruct, chartInstance->S,
                                1U, 0, 0, MAX_uint32_T, (int32_T)
                                c2_idx2Keep->data[c2_i355], 1, c2_c_metric) +
                               c2_b_metric->size[0] * c2_i354) - 1];
        }
      }

      c2_b27 = (c2_centers->size[0] == 0);
      c2_b28 = (c2_centers->size[1] == 0);
      if (c2_b27 || c2_b28) {
        c2_i356 = c2_centers->size[0] * c2_centers->size[1];
        c2_centers->size[0] = 0;
        c2_centers->size[1] = 0;
        c2_i358 = c2_centers->size[0];
        c2_i359 = c2_centers->size[1];
        c2_i360 = c2_metric->size[0] * c2_metric->size[1];
        c2_metric->size[0] = 0;
        c2_metric->size[1] = 0;
        c2_i361 = c2_metric->size[0];
        c2_i362 = c2_metric->size[1];
      } else {
        c2_p = true;
        c2_d10 = (real_T)(c2_centers->size[0] * c2_centers->size[1]);
        c2_i357 = (int32_T)c2_d10 - 1;
        c2_d_k = 0;
        exitg1 = false;
        while ((!exitg1) && (c2_d_k <= c2_i357)) {
          c2_e_k = 1.0 + (real_T)c2_d_k;
          c2_g_x = c2_centers->data[(int32_T)c2_e_k - 1];
          c2_b_p = !(c2_g_x <= 0.0);
          if (c2_b_p) {
            c2_d_k++;
          } else {
            c2_p = false;
            exitg1 = true;
          }
        }

        if (c2_p) {
          c2_b29 = true;
        } else {
          c2_b29 = false;
        }

        if (c2_b29) {
        } else {
          c2_f_y = NULL;
          sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv29, 10, 0U, 1U, 0U, 2,
            1, 37), false);
          c2_g_y = NULL;
          sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_cv5, 10, 0U, 1U, 0U, 2, 1,
            48), false);
          c2_h_y = NULL;
          sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv30, 10, 0U, 1U, 0U, 2,
            1, 24), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                            c2_f_y, 14, sf_mex_call_debug
                            (sfGlobalDebugInstanceStruct, "getString", 1U, 1U,
                             14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
            "message", 1U, 2U, 14, c2_g_y, 14, c2_h_y)));
        }

        c2_b30 = (c2_centers->size[0] == 0);
        c2_b31 = (c2_centers->size[1] == 0);
        if ((!c2_b30) && (!c2_b31)) {
        } else {
          c2_i_y = NULL;
          sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_cv31, 10, 0U, 1U, 0U, 2,
            1, 37), false);
          c2_j_y = NULL;
          sf_mex_assign(&c2_j_y, sf_mex_create("y", c2_cv32, 10, 0U, 1U, 0U, 2,
            1, 48), false);
          c2_l_y = NULL;
          sf_mex_assign(&c2_l_y, sf_mex_create("y", c2_cv34, 10, 0U, 1U, 0U, 2,
            1, 24), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                            c2_i_y, 14, sf_mex_call_debug
                            (sfGlobalDebugInstanceStruct, "getString", 1U, 1U,
                             14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
            "message", 1U, 2U, 14, c2_j_y, 14, c2_l_y)));
        }

        if ((real_T)c2_centers->size[1] == 2.0) {
        } else {
          c2_k_y = NULL;
          sf_mex_assign(&c2_k_y, sf_mex_create("y", c2_cv33, 10, 0U, 1U, 0U, 2,
            1, 37), false);
          c2_m_y = NULL;
          sf_mex_assign(&c2_m_y, sf_mex_create("y", c2_cv35, 10, 0U, 1U, 0U, 2,
            1, 48), false);
          c2_n_y = NULL;
          sf_mex_assign(&c2_n_y, sf_mex_create("y", c2_cv36, 10, 0U, 1U, 0U, 2,
            1, 24), false);
          c2_e_u = 2.0;
          c2_o_y = NULL;
          sf_mex_assign(&c2_o_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0),
                        false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                            c2_k_y, 14, sf_mex_call_debug
                            (sfGlobalDebugInstanceStruct, "getString", 1U, 1U,
                             14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
            "message", 1U, 3U, 14, c2_m_y, 14, c2_n_y, 14, c2_o_y)));
        }

        c2_emxInit_boolean_T1(chartInstance, &c2_d_centers, 1, &c2_yc_emlrtRTEI);
        (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_centers->size[1]);
        c2_i363 = c2_centers->size[0] - 1;
        c2_i364 = c2_d_centers->size[0];
        c2_d_centers->size[0] = c2_i363 + 1;
        c2_emxEnsureCapacity_boolean_T1(chartInstance, c2_d_centers, c2_i364,
          &c2_yc_emlrtRTEI);
        c2_j_loop_ub = c2_i363;
        for (c2_i365 = 0; c2_i365 <= c2_j_loop_ub; c2_i365++) {
          c2_d_centers->data[c2_i365] = (c2_centers->data[c2_i365] <= 160.0);
        }

        c2_emxInit_boolean_T1(chartInstance, &c2_e_centers, 1, &c2_ad_emlrtRTEI);
        if (c2_c_all(chartInstance, c2_d_centers)) {
          (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c2_centers->size[1]);
          c2_i366 = c2_centers->size[0] - 1;
          c2_i367 = c2_e_centers->size[0];
          c2_e_centers->size[0] = c2_i366 + 1;
          c2_emxEnsureCapacity_boolean_T1(chartInstance, c2_e_centers, c2_i367,
            &c2_ad_emlrtRTEI);
          c2_k_loop_ub = c2_i366;
          for (c2_i368 = 0; c2_i368 <= c2_k_loop_ub; c2_i368++) {
            c2_e_centers->data[c2_i368] = (c2_centers->data[c2_i368 +
              c2_centers->size[0]] <= 120.0);
          }

          if (c2_c_all(chartInstance, c2_e_centers)) {
            c2_b32 = true;
          } else {
            c2_b32 = false;
          }
        } else {
          c2_b32 = false;
        }

        c2_emxFree_boolean_T(chartInstance, &c2_d_centers);
        c2_emxFree_boolean_T(chartInstance, &c2_e_centers);
        if (c2_b32) {
        } else {
          c2_p_y = NULL;
          sf_mex_assign(&c2_p_y, sf_mex_create("y", c2_cv37, 10, 0U, 1U, 0U, 2,
            1, 38), false);
          c2_q_y = NULL;
          sf_mex_assign(&c2_q_y, sf_mex_create("y", c2_cv37, 10, 0U, 1U, 0U, 2,
            1, 38), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                            c2_p_y, 14, sf_mex_call_debug
                            (sfGlobalDebugInstanceStruct, "getString", 1U, 1U,
                             14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
            "message", 1U, 1U, 14, c2_q_y)));
        }

        (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c2_centers->size[1]);
        (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_centers->size[1]);
        c2_i369 = c2_centers->size[0] - 1;
        c2_i370 = c2_idx2Keep->size[0];
        c2_idx2Keep->size[0] = c2_i369 + 1;
        c2_emxEnsureCapacity_real_T1(chartInstance, c2_idx2Keep, c2_i370,
          &c2_bd_emlrtRTEI);
        c2_l_loop_ub = c2_i369;
        for (c2_i371 = 0; c2_i371 <= c2_l_loop_ub; c2_i371++) {
          c2_idx2Keep->data[c2_i371] = c2_centers->data[c2_i371 +
            c2_centers->size[0]];
        }

        c2_emxInit_real_T1(chartInstance, &c2_varargin_2, 1, &c2_cd_emlrtRTEI);
        c2_b_round(chartInstance, c2_idx2Keep);
        c2_i372 = c2_centers->size[0] - 1;
        c2_i373 = c2_varargin_2->size[0];
        c2_varargin_2->size[0] = c2_i372 + 1;
        c2_emxEnsureCapacity_real_T1(chartInstance, c2_varargin_2, c2_i373,
          &c2_cd_emlrtRTEI);
        c2_m_loop_ub = c2_i372;
        for (c2_i374 = 0; c2_i374 <= c2_m_loop_ub; c2_i374++) {
          c2_varargin_2->data[c2_i374] = c2_centers->data[c2_i374];
        }

        c2_emxInit_real_T1(chartInstance, &c2_b_idx2Keep, 1, &c2_gb_emlrtRTEI);
        c2_b_round(chartInstance, c2_varargin_2);
        c2_i375 = c2_b_idx2Keep->size[0];
        c2_b_idx2Keep->size[0] = c2_idx2Keep->size[0];
        c2_emxEnsureCapacity_real_T1(chartInstance, c2_b_idx2Keep, c2_i375,
          &c2_gb_emlrtRTEI);
        c2_n_loop_ub = c2_idx2Keep->size[0] - 1;
        for (c2_i376 = 0; c2_i376 <= c2_n_loop_ub; c2_i376++) {
          c2_b_idx2Keep->data[c2_i376] = c2_idx2Keep->data[c2_i376];
        }

        if (c2_allinrange(chartInstance, c2_b_idx2Keep, 1.0, 120)) {
        } else {
          c2_r_y = NULL;
          sf_mex_assign(&c2_r_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1,
            30), false);
          c2_s_y = NULL;
          sf_mex_assign(&c2_s_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1,
            30), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                            c2_r_y, 14, sf_mex_call_debug
                            (sfGlobalDebugInstanceStruct, "getString", 1U, 1U,
                             14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
            "message", 1U, 1U, 14, c2_s_y)));
        }

        c2_emxFree_real_T(chartInstance, &c2_b_idx2Keep);
        c2_j_varargin_1[0] = (real_T)c2_idx2Keep->size[0];
        c2_j_varargin_1[1] = 1.0;
        c2_b_varargin_2[0] = (real_T)c2_varargin_2->size[0];
        c2_b_varargin_2[1] = 1.0;
        for (c2_i377 = 0; c2_i377 < 2; c2_i377++) {
          c2_j_varargin_1[c2_i377];
        }

        for (c2_i378 = 0; c2_i378 < 2; c2_i378++) {
          c2_b_varargin_2[c2_i378];
        }

        for (c2_i379 = 0; c2_i379 < 2; c2_i379++) {
          c2_j_varargin_1[c2_i379];
        }

        for (c2_i380 = 0; c2_i380 < 2; c2_i380++) {
          c2_b_varargin_2[c2_i380];
        }

        c2_c_p = false;
        for (c2_i381 = 0; c2_i381 < 2; c2_i381++) {
          c2_j_varargin_1[c2_i381];
        }

        for (c2_i382 = 0; c2_i382 < 2; c2_i382++) {
          c2_b_varargin_2[c2_i382];
        }

        c2_d_p = true;
        c2_f_k = 0;
        exitg1 = false;
        while ((!exitg1) && (c2_f_k < 2)) {
          c2_g_k = 1.0 + (real_T)c2_f_k;
          c2_x1 = c2_j_varargin_1[(int32_T)c2_g_k - 1];
          c2_x2 = c2_b_varargin_2[(int32_T)c2_g_k - 1];
          c2_e_p = (c2_x1 == c2_x2);
          if (!c2_e_p) {
            c2_d_p = false;
            exitg1 = true;
          } else {
            c2_f_k++;
          }
        }

        if (!c2_d_p) {
        } else {
          c2_c_p = true;
        }

        if (c2_c_p) {
        } else {
          c2_t_y = NULL;
          sf_mex_assign(&c2_t_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1,
            34), false);
          c2_u_y = NULL;
          sf_mex_assign(&c2_u_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1,
            34), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                            c2_t_y, 14, sf_mex_call_debug
                            (sfGlobalDebugInstanceStruct, "getString", 1U, 1U,
                             14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
            "message", 1U, 1U, 14, c2_u_y)));
        }

        c2_emxInit_real_T1(chartInstance, &c2_c_varargin_2, 1, &c2_gb_emlrtRTEI);
        c2_i383 = c2_c_varargin_2->size[0];
        c2_c_varargin_2->size[0] = c2_varargin_2->size[0];
        c2_emxEnsureCapacity_real_T1(chartInstance, c2_c_varargin_2, c2_i383,
          &c2_gb_emlrtRTEI);
        c2_o_loop_ub = c2_varargin_2->size[0] - 1;
        for (c2_i384 = 0; c2_i384 <= c2_o_loop_ub; c2_i384++) {
          c2_c_varargin_2->data[c2_i384] = c2_varargin_2->data[c2_i384];
        }

        if (c2_allinrange(chartInstance, c2_c_varargin_2, 1.0, 160)) {
        } else {
          c2_v_y = NULL;
          sf_mex_assign(&c2_v_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1,
            30), false);
          c2_w_y = NULL;
          sf_mex_assign(&c2_w_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1,
            30), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                            c2_v_y, 14, sf_mex_call_debug
                            (sfGlobalDebugInstanceStruct, "getString", 1U, 1U,
                             14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
            "message", 1U, 1U, 14, c2_w_y)));
        }

        c2_emxFree_real_T(chartInstance, &c2_c_varargin_2);
        c2_i385 = c2_ii->size[0];
        c2_ii->size[0] = c2_idx2Keep->size[0];
        c2_emxEnsureCapacity_int32_T(chartInstance, c2_ii, c2_i385,
          &c2_hb_emlrtRTEI);
        c2_p_loop_ub = c2_idx2Keep->size[0] - 1;
        for (c2_i386 = 0; c2_i386 <= c2_p_loop_ub; c2_i386++) {
          c2_ii->data[c2_i386] = (int32_T)c2_idx2Keep->data[c2_i386];
        }

        c2_i387 = c2_d_b->size[0];
        c2_d_b->size[0] = c2_varargin_2->size[0];
        c2_emxEnsureCapacity_int32_T(chartInstance, c2_d_b, c2_i387,
          &c2_ib_emlrtRTEI);
        c2_q_loop_ub = c2_varargin_2->size[0] - 1;
        for (c2_i388 = 0; c2_i388 <= c2_q_loop_ub; c2_i388++) {
          c2_d_b->data[c2_i388] = (int32_T)c2_varargin_2->data[c2_i388] - 1;
        }

        c2_emxFree_real_T(chartInstance, &c2_varargin_2);
        c2_i389 = c2_d_b->size[0];
        c2_d_b->size[0];
        c2_emxEnsureCapacity_int32_T(chartInstance, c2_d_b, c2_i389,
          &c2_jb_emlrtRTEI);
        c2_r_loop_ub = c2_d_b->size[0] - 1;
        for (c2_i390 = 0; c2_i390 <= c2_r_loop_ub; c2_i390++) {
          c2_d_b->data[c2_i390] *= 120;
        }

        c2_i391 = c2_ii->size[0];
        c2_ii->size[0];
        c2_emxEnsureCapacity_int32_T(chartInstance, c2_ii, c2_i391,
          &c2_kb_emlrtRTEI);
        c2_s_loop_ub = c2_ii->size[0] - 1;
        for (c2_i392 = 0; c2_i392 <= c2_s_loop_ub; c2_i392++) {
          c2_ii->data[c2_i392] += c2_d_b->data[c2_i392];
        }

        c2_i393 = c2_idx2Keep->size[0];
        c2_idx2Keep->size[0] = c2_ii->size[0];
        c2_emxEnsureCapacity_real_T1(chartInstance, c2_idx2Keep, c2_i393,
          &c2_lb_emlrtRTEI);
        c2_t_loop_ub = c2_ii->size[0] - 1;
        for (c2_i394 = 0; c2_i394 <= c2_t_loop_ub; c2_i394++) {
          c2_idx2Keep->data[c2_i394] = (real_T)c2_ii->data[c2_i394];
        }

        c2_emxInit_creal_T(chartInstance, &c2_h_x, 1, &c2_dd_emlrtRTEI);
        c2_i395 = c2_h_x->size[0];
        c2_h_x->size[0] = c2_idx2Keep->size[0];
        c2_emxEnsureCapacity_creal_T(chartInstance, c2_h_x, c2_i395,
          &c2_dd_emlrtRTEI);
        c2_u_loop_ub = c2_idx2Keep->size[0] - 1;
        for (c2_i396 = 0; c2_i396 <= c2_u_loop_ub; c2_i396++) {
          c2_h_x->data[c2_i396].re = chartInstance->
            c2_accumMatrix[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_idx2Keep->
            data[c2_i396], 1, 19200) - 1].re;
          c2_h_x->data[c2_i396].im = chartInstance->
            c2_accumMatrix[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_idx2Keep->
            data[c2_i396], 1, 19200) - 1].im;
        }

        c2_c_nx = c2_h_x->size[0];
        c2_j_varargin_1[0] = (real_T)c2_h_x->size[0];
        c2_j_varargin_1[1] = 1.0;
        for (c2_i397 = 0; c2_i397 < 2; c2_i397++) {
          c2_j_varargin_1[c2_i397];
        }

        c2_i398 = c2_idx2Keep->size[0];
        c2_idx2Keep->size[0] = (int32_T)c2_j_varargin_1[0];
        c2_emxEnsureCapacity_real_T1(chartInstance, c2_idx2Keep, c2_i398,
          &c2_ed_emlrtRTEI);
        c2_e_b = c2_c_nx;
        c2_f_b = c2_e_b;
        if (1 > c2_f_b) {
          c2_b_overflow = false;
        } else {
          c2_b_overflow = (c2_f_b > 2147483646);
        }

        if (c2_b_overflow) {
          c2_check_forloop_overflow_error(chartInstance, true);
        }

        for (c2_h_k = 0; c2_h_k < c2_c_nx; c2_h_k++) {
          c2_i_k = c2_h_k;
          c2_e_x = c2_h_x->data[c2_i_k];
          c2_x_y = c2_e_x.im;
          c2_i_x = c2_e_x.re;
          c2_y_y = muDoubleScalarAtan2(c2_x_y, c2_i_x);
          c2_idx2Keep->data[c2_i_k] = c2_y_y;
        }

        c2_emxFree_creal_T(chartInstance, &c2_h_x);
        c2_i399 = c2_idx2Keep->size[0];
        c2_idx2Keep->size[0];
        c2_emxEnsureCapacity_real_T1(chartInstance, c2_idx2Keep, c2_i399,
          &c2_fd_emlrtRTEI);
        c2_v_loop_ub = c2_idx2Keep->size[0] - 1;
        for (c2_i400 = 0; c2_i400 <= c2_v_loop_ub; c2_i400++) {
          c2_idx2Keep->data[c2_i400] = (c2_idx2Keep->data[c2_i400] +
            3.1415926535897931) / 6.2831853071795862;
        }

        c2_i401 = c2_idx2Keep->size[0];
        c2_idx2Keep->size[0];
        c2_emxEnsureCapacity_real_T1(chartInstance, c2_idx2Keep, c2_i401,
          &c2_l_emlrtRTEI);
        c2_w_loop_ub = c2_idx2Keep->size[0] - 1;
        for (c2_i402 = 0; c2_i402 <= c2_w_loop_ub; c2_i402++) {
          c2_idx2Keep->data[c2_i402] *= 0.98082925301172619;
        }

        c2_i403 = c2_idx2Keep->size[0];
        c2_idx2Keep->size[0];
        c2_emxEnsureCapacity_real_T1(chartInstance, c2_idx2Keep, c2_i403,
          &c2_gd_emlrtRTEI);
        c2_x_loop_ub = c2_idx2Keep->size[0] - 1;
        for (c2_i404 = 0; c2_i404 <= c2_x_loop_ub; c2_i404++) {
          c2_idx2Keep->data[c2_i404] += 2.70805020110221;
        }

        c2_d_nx = c2_idx2Keep->size[0];
        c2_g_b = c2_d_nx;
        c2_h_b = c2_g_b;
        if (1 > c2_h_b) {
          c2_c_overflow = false;
        } else {
          c2_c_overflow = (c2_h_b > 2147483646);
        }

        if (c2_c_overflow) {
          c2_check_forloop_overflow_error(chartInstance, true);
        }

        for (c2_j_k = 0; c2_j_k < c2_d_nx; c2_j_k++) {
          c2_k_k = c2_j_k;
          c2_j_x = c2_idx2Keep->data[c2_k_k];
          c2_k_x = c2_j_x;
          c2_k_x = muDoubleScalarExp(c2_k_x);
          c2_idx2Keep->data[c2_k_k] = c2_k_x;
        }

        c2_i405 = c2_r_estimated->size[0] * c2_r_estimated->size[1];
        c2_r_estimated->size[0] = c2_idx2Keep->size[0];
        c2_r_estimated->size[1] = 1;
        c2_emxEnsureCapacity_real_T(chartInstance, c2_r_estimated, c2_i405,
          &c2_hd_emlrtRTEI);
        c2_i406 = c2_r_estimated->size[0];
        c2_i407 = c2_r_estimated->size[1];
        c2_y_loop_ub = c2_idx2Keep->size[0] - 1;
        for (c2_i408 = 0; c2_i408 <= c2_y_loop_ub; c2_i408++) {
          c2_r_estimated->data[c2_i408] = c2_idx2Keep->data[c2_i408];
        }
      }

      c2_emxFree_int32_T(chartInstance, &c2_d_b);
      c2_emxFree_int32_T(chartInstance, &c2_ii);
      c2_emxFree_real_T(chartInstance, &c2_idx2Keep);
    }

    c2_emxFree_real_T(chartInstance, &c2_b_metric);
    c2_emxFree_real_T(chartInstance, &c2_b_centers);
  }
}

static void c2_chaccum(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_h_varargin_1[19200], creal_T c2_c_accumMatrix[19200], real32_T
  c2_b_gradientImg[19200])
{
  boolean_T c2_i_varargin_1;
  int32_T c2_i409;
  boolean_T c2_flat;
  boolean_T c2_j_varargin_1[19200];
  int32_T c2_i410;
  int32_T c2_i411;
  int32_T c2_i412;
  boolean_T c2_tooBig;
  int32_T c2_i;
  boolean_T c2_modeFlag;
  boolean_T c2_b_modeFlag;
  boolean_T c2_c_modeFlag;
  int32_T c2_i413;
  int32_T c2_i414;
  int32_T c2_i415;
  boolean_T c2_conn[25];
  int32_T c2_i416;
  real_T c2_padSizeT[2];
  int32_T c2_i417;
  int32_T c2_i418;
  real_T c2_outSizeT[2];
  int32_T c2_i419;
  static real_T c2_kernel[25] = { 0.014418818362460822, 0.028084023356349175,
    0.0350727008055935, 0.028084023356349175, 0.014418818362460822,
    0.028084023356349175, 0.054700208300935887, 0.068312293270780214,
    0.054700208300935887, 0.028084023356349175, 0.0350727008055935,
    0.068312293270780214, 0.085311730190125085, 0.068312293270780214,
    0.0350727008055935, 0.028084023356349175, 0.054700208300935887,
    0.068312293270780214, 0.054700208300935887, 0.028084023356349175,
    0.014418818362460822, 0.028084023356349175, 0.0350727008055935,
    0.028084023356349175, 0.014418818362460822 };

  real_T c2_startT[2];
  int32_T c2_i420;
  real_T c2_connDimsT[2];
  int32_T c2_i421;
  static real_T c2_nonZeroKernel[25] = { 0.014418818362460822,
    0.028084023356349175, 0.0350727008055935, 0.028084023356349175,
    0.014418818362460822, 0.028084023356349175, 0.054700208300935887,
    0.068312293270780214, 0.054700208300935887, 0.028084023356349175,
    0.0350727008055935, 0.068312293270780214, 0.085311730190125085,
    0.068312293270780214, 0.0350727008055935, 0.028084023356349175,
    0.054700208300935887, 0.068312293270780214, 0.054700208300935887,
    0.028084023356349175, 0.014418818362460822, 0.028084023356349175,
    0.0350727008055935, 0.028084023356349175, 0.014418818362460822 };

  int32_T c2_i422;
  int32_T c2_i423;
  int32_T c2_i424;
  int32_T c2_i425;
  int32_T c2_i426;
  int32_T c2_i427;
  int32_T c2_i428;
  int32_T c2_i429;
  real32_T c2_d_x;
  real32_T c2_e_x;
  boolean_T c2_b;
  boolean_T c2_p;
  int32_T c2_b_idx;
  int32_T c2_k;
  int32_T c2_i430;
  real32_T c2_Gmax;
  real32_T c2_f_x;
  real32_T c2_g_x;
  int32_T c2_first;
  real32_T c2_c_y;
  boolean_T c2_b_b;
  real32_T c2_ex;
  real32_T c2_d_y;
  boolean_T c2_b_p;
  int32_T c2_i431;
  int32_T c2_i432;
  int32_T c2_b_k;
  real32_T c2_edgeThresh;
  real32_T c2_t;
  int32_T c2_i433;
  c2_emxArray_real_T *c2_Ey;
  boolean_T c2_h_x[19200];
  c2_emxArray_int32_T *c2_ii;
  c2_emxArray_int32_T *c2_jj;
  int32_T c2_i434;
  int32_T c2_loop_ub;
  int32_T c2_i435;
  c2_emxArray_real_T *c2_Ex;
  int32_T c2_i436;
  int32_T c2_b_loop_ub;
  int32_T c2_i437;
  c2_emxArray_real_T *c2_ndx;
  int32_T c2_i438;
  int32_T c2_c_loop_ub;
  int32_T c2_i439;
  c2_emxArray_real_T *c2_varargin_2;
  int32_T c2_i440;
  int32_T c2_d_loop_ub;
  int32_T c2_i441;
  c2_emxArray_int32_T *c2_c_idx;
  c2_emxArray_real_T *c2_b_ndx;
  int32_T c2_i442;
  int32_T c2_e_loop_ub;
  int32_T c2_i443;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  int32_T c2_i444;
  int32_T c2_i445;
  boolean_T c2_c_p;
  boolean_T c2_d_p;
  int32_T c2_c_k;
  real_T c2_d_k;
  real_T c2_x1;
  real_T c2_x2;
  boolean_T c2_e_p;
  const mxArray *c2_g_y = NULL;
  c2_emxArray_real_T *c2_b_varargin_2;
  const mxArray *c2_h_y = NULL;
  int32_T c2_i446;
  int32_T c2_f_loop_ub;
  int32_T c2_i447;
  const mxArray *c2_i_y = NULL;
  const mxArray *c2_j_y = NULL;
  int32_T c2_i448;
  int32_T c2_g_loop_ub;
  int32_T c2_i449;
  c2_emxArray_int32_T *c2_c_b;
  int32_T c2_i450;
  int32_T c2_h_loop_ub;
  int32_T c2_i451;
  int32_T c2_i452;
  int32_T c2_i_loop_ub;
  int32_T c2_i453;
  int32_T c2_i454;
  int32_T c2_j_loop_ub;
  int32_T c2_i455;
  int32_T c2_i456;
  int32_T c2_k_loop_ub;
  int32_T c2_i457;
  c2_emxArray_real_T *c2_idxE;
  int32_T c2_i458;
  int32_T c2_l_loop_ub;
  int32_T c2_i459;
  int32_T c2_i460;
  int32_T c2_c_varargin_2;
  real_T c2_ar;
  static creal_T c2_Opca[51] = { { -1.0,/* re */
      -1.2246467991473532E-16          /* im */
    }, { -0.97802020385900779,         /* re */
      -0.20851014566103235             /* im */
    }, { -0.91574686949728124,         /* re */
      -0.40175573549848592             /* im */
    }, { -0.81932918047886227,         /* re */
      -0.57332337647773957             /* im */
    }, { -0.6954184976738389,          /* re */
      -0.71860497708620208             /* im */
    }, { -0.5507880805072134,          /* re */
      -0.83464512840558736             /* im */
    }, { -0.39203783842097073,         /* re */
      -0.91994909274710024             /* im */
    }, { -0.22537515221469892,         /* re */
      -0.974272056852808               /* im */
    }, { -0.056461432538574136,        /* re */
      -0.99840478095594676             /* im */
    }, { 0.10968616958136543,          /* re */
      -0.99396626914728248             /* im */
    }, { 0.26874803229707556,          /* re */
      -0.96321051444450612             /* im */
    }, { 0.41711958165892082,          /* re */
      -0.90885161307921269             /* im */
    }, { 0.55190126013242324,          /* re */
      -0.833909466947248               /* im */
    }, { 0.67086800873377794,          /* re */
      -0.74157677610452155             /* im */
    }, { 0.77242420945745627,          /* re */
      -0.63510695213013046             /* im */
    }, { 0.85554899027289855,          /* re */
      -0.51772186088963223             /* im */
    }, { 0.91973585215372922,          /* re */
      -0.39253784819180626             /* im */
    }, { 0.96492974879251492,          /* re */
      -0.26250824728989758             /* im */
    }, { 0.99146403654932613,          /* re */
      -0.13038045953790983             /* im */
    }, { 0.9999991098166704,           /* re */
      0.0013343035137634166            /* im */
    }, { 0.99146403654932613,          /* re */
      0.13038045953790983              /* im */
    }, { 0.96700209948356886,          /* re */
      0.2547684038384076               /* im */
    }, { 0.92792081920064406,          /* re */
      0.37277735083291419              /* im */
    }, { 0.87564677449936246,          /* re */
      0.48295209525258576              /* im */
    }, { 0.81168533303058732,          /* re */
      0.584094958155799                /* im */
    }, { 0.73758525125122842,          /* re */
      0.675254024154364                /* im */
    }, { 0.65490798897553737,          /* re */
      0.75570862505069869              /* im */
    }, { 0.56520150271535452,          /* re */
      0.82495288430813141              /* im */
    }, { 0.46997822722670263,          /* re */
      0.88267800807137242              /* im */
    }, { 0.37069692079986849,          /* re */
      0.92875389254069673              /* im */
    }, { 0.26874803229707572,          /* re */
      0.963210514444506                /* im */
    }, { 0.16544224297915311,          /* re */
      0.98621948076380384              /* im */
    }, { 0.0620018406648306,           /* re */
      0.99807603505653464              /* im */
    }, { -0.040445404795224314,        /* re */
      0.99918174984882024              /* im */
    }, { -0.14087017941092603,         /* re */
      0.99002807664870474              /* im */
    }, { -0.23834367138338119,         /* re */
      0.97118087620766647              /* im */
    }, { -0.33203799934291556,         /* re */
      0.94326601072674832              /* im */
    }, { -0.42122527336382581,         /* re */
      0.90695604583660516              /* im */
    }, { -0.50527551678875027,         /* re */
      0.86295808248944594              /* im */
    }, { -0.58365365439243577,         /* re */
      0.81200271656833456              /* im */
    }, { -0.65591575066114749,         /* re */
      0.75483410630059855              /* im */
    }, { -0.72170466125252131,         /* re */
      0.69220111378585891              /* im */
    }, { -0.78074524122605593,         /* re */
      0.62484947651643885              /* im */
    }, { -0.83283923551494521,         /* re */
      0.55351495714829757              /* im */
    }, { -0.87785996040374592,         /* re */
      0.478917414508946                /* im */
    }, { -0.91574686949728124,         /* re */
      0.40175573549848592              /* im */
    }, { -0.94650008379301576,         /* re */
      0.32270356579965792              /* im */
    }, { -0.97017495295719258,         /* re */
      0.24240577685878117              /* im */
    }, { -0.98687670369103553,         /* re */
      0.16147560717308376              /* im */
    }, { -0.99675522108353054,         /* re */
      0.0804924172995329               /* im */
    }, { -1.0,                         /* re */
      1.2246467991473532E-16           /* im */
    } };

  int32_T c2_d_varargin_2;
  real_T c2_ai;
  real_T c2_lenE;
  real_T c2_br;
  static real_T c2_dv7[51] = { 94.247779607693786, 97.389372261283583,
    100.53096491487338, 103.67255756846318, 106.81415022205297,
    109.95574287564276, 113.09733552923255, 116.23892818282235,
    119.38052083641213, 122.52211349000193, 125.66370614359172,
    128.80529879718151, 131.94689145077132, 135.0884841043611,
    138.23007675795088, 141.37166941154069, 144.51326206513048,
    147.65485471872029, 150.79644737231007, 153.93804002589985,
    157.07963267948966, 160.22122533307945, 163.36281798666926,
    166.50441064025904, 169.64600329384882, 172.78759594743863,
    175.92918860102841, 179.0707812546182, 182.212373908208, 185.35396656179779,
    188.49555921538757, 191.63715186897738, 194.77874452256717,
    197.92033717615698, 201.06192982974676, 204.20352248333654,
    207.34511513692635, 210.48670779051614, 213.62830044410595,
    216.76989309769573, 219.91148575128551, 223.05307840487532,
    226.1946710584651, 229.33626371205489, 232.4778563656447, 235.61944901923448,
    238.76104167282426, 241.90263432641407, 245.04422698000386,
    248.18581963359367, 251.32741228718345 };

  int32_T c2_i461;
  real_T c2_bi;
  int32_T c2_i462;
  real_T c2_brm;
  creal_T c2_w0[51];
  int32_T c2_b_i;
  real_T c2_bim;
  c2_emxArray_real_T *c2_Ex_chunk;
  c2_emxArray_real_T *c2_Ey_chunk;
  real_T c2_s;
  c2_emxArray_real_T *c2_idxE_chunk;
  real_T c2_d;
  c2_emxArray_real32_T *c2_xc;
  real_T c2_sgnbr;
  real_T c2_nr;
  c2_emxArray_real32_T *c2_yc;
  real_T c2_ni;
  c2_emxArray_creal_T *c2_w;
  c2_emxArray_boolean_T *c2_inside;
  real_T c2_sgnbi;
  c2_emxArray_int32_T *c2_xckeep;
  c2_emxArray_int32_T *c2_yckeep;
  c2_emxArray_creal_T *c2_wkeep;
  c2_emxArray_real_T *c2_r7;
  real_T c2_c_i;
  real_T c2_e_varargin_2;
  real_T c2_k_varargin_1;
  real_T c2_k_y;
  real_T c2_l_y;
  real_T c2_m_y;
  real_T c2_n_y;
  real_T c2_o_y;
  real_T c2_minval;
  real_T c2_l_a;
  real_T c2_b_d;
  real_T c2_m_a;
  real_T c2_d_b;
  real_T c2_i_x;
  boolean_T c2_e_b;
  real_T c2_j_x;
  boolean_T c2_f_b;
  int32_T c2_i463;
  real_T c2_k_x;
  int32_T c2_i464;
  boolean_T c2_g_b;
  int32_T c2_i465;
  int32_T c2_i466;
  real_T c2_l_x;
  int32_T c2_i467;
  boolean_T c2_h_b;
  int32_T c2_i468;
  int32_T c2_i469;
  real_T c2_sizeChunk;
  real_T c2_m_x;
  int32_T c2_i470;
  real_T c2_n_x;
  int32_T c2_i471;
  int32_T c2_i472;
  real_T c2_n_a;
  int32_T c2_i473;
  int32_T c2_i474;
  real_T c2_i_b;
  real_T c2_o_a;
  int32_T c2_i475;
  real_T c2_j_b;
  real_T c2_anew;
  int32_T c2_m_loop_ub;
  real_T c2_o_x;
  int32_T c2_i476;
  int32_T c2_idxEdge;
  real_T c2_ndbl;
  int32_T c2_i477;
  int32_T c2_d_idx;
  real_T c2_apnd;
  real_T c2_cdiff;
  real_T c2_p_x;
  real_T c2_dim1;
  real_T c2_e_idx;
  real_T c2_q_x;
  int32_T c2_i478;
  real_T c2_r_x;
  real_T c2_p_y;
  real_T c2_p_a;
  real_T c2_k_b;
  int32_T c2_i479;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_u_x;
  real_T c2_absa;
  int32_T c2_i480;
  real_T c2_v_x;
  real_T c2_w_x;
  real_T c2_x_x;
  real_T c2_absb;
  int32_T c2_i481;
  real_T c2_c;
  int32_T c2_rows_to_keep_size[1];
  int32_T c2_n_loop_ub;
  real_T c2_bnew;
  int32_T c2_i482;
  int32_T c2_idx2;
  boolean_T c2_rows_to_keep_data[19200];
  int32_T c2_n;
  int32_T c2_i483;
  real_T c2_b_idx2;
  int32_T c2_i484;
  int32_T c2_i485;
  int32_T c2_idx1;
  int32_T c2_i486;
  real_T c2_b_idx1;
  int32_T c2_i487;
  real32_T c2_y_x;
  real32_T c2_q_y;
  real32_T c2_ab_x;
  int32_T c2_q_a;
  int32_T c2_idxkeep;
  real32_T c2_r_y;
  int32_T c2_nm1;
  int32_T c2_c_idx2;
  real32_T c2_z;
  int32_T c2_r_a;
  real_T c2_s_a;
  int32_T c2_nm1d2;
  int32_T c2_szxc;
  real32_T c2_l_b;
  int32_T c2_t_a;
  int32_T c2_i488;
  int32_T c2_i489;
  real32_T c2_s_y;
  int32_T c2_i490;
  int32_T c2_c_idx1;
  real32_T c2_bb_x;
  int32_T c2_m_b;
  int32_T c2_n_b;
  int32_T c2_o_b;
  int32_T c2_p_b;
  real32_T c2_t_y;
  boolean_T c2_overflow;
  boolean_T c2_b_overflow;
  real32_T c2_cb_x;
  real32_T c2_u_y;
  int32_T c2_b_xckeep[2];
  real32_T c2_db_x;
  int32_T c2_e_k;
  int32_T c2_f_idx;
  real32_T c2_v_y;
  real32_T c2_b_z;
  int32_T c2_b_yckeep[2];
  real_T c2_u_a;
  int32_T c2_q_b;
  int32_T c2_f_k;
  int32_T c2_i491;
  int32_T c2_g_idx;
  real32_T c2_r_b;
  int32_T c2_b_c;
  real_T c2_kd;
  real32_T c2_w_y;
  int32_T c2_v_a;
  int32_T c2_b_wkeep[2];
  real32_T c2_eb_x;
  int32_T c2_w_a;
  int32_T c2_c_c;
  int32_T c2_x_a;
  int32_T c2_d_c;
  real32_T c2_x_y;
  int32_T c2_e_c;
  int32_T c2_y_a;
  int32_T c2_s_b;
  int32_T c2_ab_a;
  int32_T c2_f_c;
  int32_T c2_g_c;
  boolean_T c2_b33;
  boolean_T c2_b34;
  boolean_T c2_b35;
  boolean_T c2_b36;
  boolean_T c2_b37;
  boolean_T c2_b38;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T exitg1;
  c2_i_varargin_1 = c2_h_varargin_1[0];
  for (c2_i409 = 0; c2_i409 < 19200; c2_i409++) {
    c2_j_varargin_1[c2_i409] = ((int32_T)c2_h_varargin_1[c2_i409] == (int32_T)
      c2_i_varargin_1);
  }

  c2_flat = c2_b_all(chartInstance, c2_j_varargin_1);
  if (c2_flat) {
    for (c2_i411 = 0; c2_i411 < 19200; c2_i411++) {
      c2_c_accumMatrix[c2_i411].re = 0.0;
      c2_c_accumMatrix[c2_i411].im = 0.0;
    }

    for (c2_i412 = 0; c2_i412 < 19200; c2_i412++) {
      c2_b_gradientImg[c2_i412] = 0.0F;
    }
  } else {
    for (c2_i410 = 0; c2_i410 < 19200; c2_i410++) {
      chartInstance->c2_A[c2_i410] = (real32_T)c2_h_varargin_1[c2_i410];
    }

    c2_c_padImage(chartInstance, chartInstance->c2_A, 0.0, 3, 3.0,
                  chartInstance->c2_a);
    c2_tooBig = true;
    for (c2_i = 0; c2_i < 2; c2_i++) {
      c2_tooBig = false;
    }

    if (!c2_tooBig) {
      c2_modeFlag = true;
    } else {
      c2_modeFlag = false;
    }

    if (c2_modeFlag) {
      c2_b_modeFlag = true;
    } else {
      c2_b_modeFlag = false;
    }

    c2_c_modeFlag = c2_b_modeFlag;
    if (c2_c_modeFlag) {
      for (c2_i414 = 0; c2_i414 < 2; c2_i414++) {
        c2_padSizeT[c2_i414] = 124.0 + 40.0 * (real_T)c2_i414;
      }

      for (c2_i416 = 0; c2_i416 < 2; c2_i416++) {
        c2_outSizeT[c2_i416] = 120.0 + 40.0 * (real_T)c2_i416;
      }

      for (c2_i418 = 0; c2_i418 < 2; c2_i418++) {
        c2_startT[c2_i418] = 5.0;
      }

      ippfilter_real32(chartInstance->c2_a, chartInstance->c2_A, c2_outSizeT,
                       2.0, c2_padSizeT, c2_kernel, c2_startT, false);
    } else {
      for (c2_i413 = 0; c2_i413 < 25; c2_i413++) {
        c2_conn[c2_i413] = true;
      }

      for (c2_i415 = 0; c2_i415 < 2; c2_i415++) {
        c2_padSizeT[c2_i415] = 124.0 + 40.0 * (real_T)c2_i415;
      }

      for (c2_i417 = 0; c2_i417 < 2; c2_i417++) {
        c2_outSizeT[c2_i417] = 120.0 + 40.0 * (real_T)c2_i417;
      }

      for (c2_i419 = 0; c2_i419 < 2; c2_i419++) {
        c2_connDimsT[c2_i419] = 5.0;
      }

      for (c2_i420 = 0; c2_i420 < 2; c2_i420++) {
        c2_startT[c2_i420] = 2.0;
      }

      imfilter_real32(chartInstance->c2_a, chartInstance->c2_A, 2.0, c2_outSizeT,
                      2.0, c2_padSizeT, c2_nonZeroKernel, 25.0, c2_conn, 2.0,
                      c2_connDimsT, c2_startT, 2.0, true, false);
    }

    for (c2_i421 = 0; c2_i421 < 19200; c2_i421++) {
      chartInstance->c2_b_A[c2_i421] = chartInstance->c2_A[c2_i421];
    }

    c2_e_imfilter(chartInstance, chartInstance->c2_b_A, chartInstance->c2_Gx);
    c2_f_imfilter(chartInstance, chartInstance->c2_A, chartInstance->c2_Gy);
    for (c2_i422 = 0; c2_i422 < 19200; c2_i422++) {
      chartInstance->c2_b_Gx[c2_i422] = chartInstance->c2_Gx[c2_i422];
    }

    for (c2_i423 = 0; c2_i423 < 19200; c2_i423++) {
      chartInstance->c2_b_Gy[c2_i423] = chartInstance->c2_Gy[c2_i423];
    }

    c2_hypot(chartInstance, chartInstance->c2_b_Gx, chartInstance->c2_b_Gy,
             c2_b_gradientImg);
    for (c2_i424 = 0; c2_i424 < 19200; c2_i424++) {
      chartInstance->c2_A[c2_i424] = c2_b_gradientImg[c2_i424];
    }

    for (c2_i425 = 0; c2_i425 < 19200; c2_i425++) {
      chartInstance->c2_A[c2_i425];
    }

    for (c2_i426 = 0; c2_i426 < 19200; c2_i426++) {
      chartInstance->c2_A[c2_i426];
    }

    for (c2_i427 = 0; c2_i427 < 19200; c2_i427++) {
      chartInstance->c2_A[c2_i427];
    }

    for (c2_i428 = 0; c2_i428 < 19200; c2_i428++) {
      chartInstance->c2_A[c2_i428];
    }

    for (c2_i429 = 0; c2_i429 < 19200; c2_i429++) {
      chartInstance->c2_A[c2_i429];
    }

    c2_d_x = chartInstance->c2_A[0];
    c2_e_x = c2_d_x;
    c2_b = muSingleScalarIsNaN(c2_e_x);
    c2_p = !c2_b;
    if (c2_p) {
      c2_b_idx = 1;
    } else {
      c2_b_idx = 0;
      c2_k = 2;
      exitg1 = false;
      while ((!exitg1) && (c2_k < 19201)) {
        c2_f_x = chartInstance->c2_A[c2_k - 1];
        c2_g_x = c2_f_x;
        c2_b_b = muSingleScalarIsNaN(c2_g_x);
        c2_b_p = !c2_b_b;
        if (c2_b_p) {
          c2_b_idx = c2_k;
          exitg1 = true;
        } else {
          c2_k++;
        }
      }
    }

    if (c2_b_idx == 0) {
      c2_Gmax = chartInstance->c2_A[0];
    } else {
      for (c2_i430 = 0; c2_i430 < 19200; c2_i430++) {
        chartInstance->c2_A[c2_i430];
      }

      c2_first = c2_b_idx - 1;
      c2_ex = chartInstance->c2_A[c2_first];
      c2_i431 = c2_first;
      for (c2_b_k = c2_i431 + 1; c2_b_k + 1 < 19201; c2_b_k++) {
        if (c2_ex < chartInstance->c2_A[c2_b_k]) {
          c2_ex = chartInstance->c2_A[c2_b_k];
        }
      }

      c2_Gmax = c2_ex;
    }

    c2_c_y = c2_Gmax;
    c2_d_y = c2_c_y;
    for (c2_i432 = 0; c2_i432 < 19200; c2_i432++) {
      chartInstance->c2_A[c2_i432] = c2_b_gradientImg[c2_i432] / c2_d_y;
    }

    c2_edgeThresh = c2_multithresh(chartInstance, chartInstance->c2_A);
    c2_t = c2_Gmax * c2_edgeThresh;
    for (c2_i433 = 0; c2_i433 < 19200; c2_i433++) {
      c2_h_x[c2_i433] = (c2_b_gradientImg[c2_i433] > c2_t);
    }

    c2_emxInit_real_T1(chartInstance, &c2_Ey, 1, &c2_nd_emlrtRTEI);
    c2_emxInit_int32_T(chartInstance, &c2_ii, 1, &c2_nd_emlrtRTEI);
    c2_emxInit_int32_T(chartInstance, &c2_jj, 1, &c2_nd_emlrtRTEI);
    c2_eml_find(chartInstance, c2_h_x, c2_ii, c2_jj);
    c2_i434 = c2_Ey->size[0];
    c2_Ey->size[0] = c2_ii->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_Ey, c2_i434, &c2_n_emlrtRTEI);
    c2_loop_ub = c2_ii->size[0] - 1;
    for (c2_i435 = 0; c2_i435 <= c2_loop_ub; c2_i435++) {
      c2_Ey->data[c2_i435] = (real_T)c2_ii->data[c2_i435];
    }

    c2_emxFree_int32_T(chartInstance, &c2_ii);
    c2_emxInit_real_T1(chartInstance, &c2_Ex, 1, &c2_nd_emlrtRTEI);
    c2_i436 = c2_Ex->size[0];
    c2_Ex->size[0] = c2_jj->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_Ex, c2_i436, &c2_o_emlrtRTEI);
    c2_b_loop_ub = c2_jj->size[0] - 1;
    for (c2_i437 = 0; c2_i437 <= c2_b_loop_ub; c2_i437++) {
      c2_Ex->data[c2_i437] = (real_T)c2_jj->data[c2_i437];
    }

    c2_emxFree_int32_T(chartInstance, &c2_jj);
    c2_emxInit_real_T1(chartInstance, &c2_ndx, 1, &c2_be_emlrtRTEI);
    c2_i438 = c2_ndx->size[0];
    c2_ndx->size[0] = c2_Ey->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_ndx, c2_i438,
      &c2_jd_emlrtRTEI);
    c2_c_loop_ub = c2_Ey->size[0] - 1;
    for (c2_i439 = 0; c2_i439 <= c2_c_loop_ub; c2_i439++) {
      c2_ndx->data[c2_i439] = c2_Ey->data[c2_i439];
    }

    c2_emxInit_real_T1(chartInstance, &c2_varargin_2, 1, &c2_kd_emlrtRTEI);
    c2_i440 = c2_varargin_2->size[0];
    c2_varargin_2->size[0] = c2_Ex->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_varargin_2, c2_i440,
      &c2_kd_emlrtRTEI);
    c2_d_loop_ub = c2_Ex->size[0] - 1;
    for (c2_i441 = 0; c2_i441 <= c2_d_loop_ub; c2_i441++) {
      c2_varargin_2->data[c2_i441] = c2_Ex->data[c2_i441];
    }

    c2_emxInit_int32_T(chartInstance, &c2_c_idx, 1, &c2_rb_emlrtRTEI);
    c2_emxInit_real_T1(chartInstance, &c2_b_ndx, 1, &c2_gb_emlrtRTEI);
    c2_i442 = c2_b_ndx->size[0];
    c2_b_ndx->size[0] = c2_ndx->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_b_ndx, c2_i442,
      &c2_gb_emlrtRTEI);
    c2_e_loop_ub = c2_ndx->size[0] - 1;
    for (c2_i443 = 0; c2_i443 <= c2_e_loop_ub; c2_i443++) {
      c2_b_ndx->data[c2_i443] = c2_ndx->data[c2_i443];
    }

    if (c2_allinrange(chartInstance, c2_b_ndx, 1.0, 120)) {
    } else {
      c2_e_y = NULL;
      sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      c2_f_y = NULL;
      sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_e_y,
                        14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "message", 1U, 1U, 14, c2_f_y)));
    }

    c2_emxFree_real_T(chartInstance, &c2_b_ndx);
    c2_startT[0] = (real_T)c2_ndx->size[0];
    c2_startT[1] = 1.0;
    c2_connDimsT[0] = (real_T)c2_varargin_2->size[0];
    c2_connDimsT[1] = 1.0;
    for (c2_i444 = 0; c2_i444 < 2; c2_i444++) {
      c2_startT[c2_i444];
    }

    for (c2_i445 = 0; c2_i445 < 2; c2_i445++) {
      c2_connDimsT[c2_i445];
    }

    c2_c_p = false;
    c2_d_p = true;
    c2_c_k = 0;
    exitg1 = false;
    while ((!exitg1) && (c2_c_k < 2)) {
      c2_d_k = 1.0 + (real_T)c2_c_k;
      c2_x1 = c2_startT[(int32_T)c2_d_k - 1];
      c2_x2 = c2_connDimsT[(int32_T)c2_d_k - 1];
      c2_e_p = (c2_x1 == c2_x2);
      if (!c2_e_p) {
        c2_d_p = false;
        exitg1 = true;
      } else {
        c2_c_k++;
      }
    }

    if (!c2_d_p) {
    } else {
      c2_c_p = true;
    }

    if (c2_c_p) {
    } else {
      c2_g_y = NULL;
      sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 34),
                    false);
      c2_h_y = NULL;
      sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1, 34),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_g_y,
                        14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "message", 1U, 1U, 14, c2_h_y)));
    }

    c2_emxInit_real_T1(chartInstance, &c2_b_varargin_2, 1, &c2_gb_emlrtRTEI);
    c2_i446 = c2_b_varargin_2->size[0];
    c2_b_varargin_2->size[0] = c2_varargin_2->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_b_varargin_2, c2_i446,
      &c2_gb_emlrtRTEI);
    c2_f_loop_ub = c2_varargin_2->size[0] - 1;
    for (c2_i447 = 0; c2_i447 <= c2_f_loop_ub; c2_i447++) {
      c2_b_varargin_2->data[c2_i447] = c2_varargin_2->data[c2_i447];
    }

    if (c2_allinrange(chartInstance, c2_b_varargin_2, 1.0, 160)) {
    } else {
      c2_i_y = NULL;
      sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      c2_j_y = NULL;
      sf_mex_assign(&c2_j_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 30),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_i_y,
                        14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "message", 1U, 1U, 14, c2_j_y)));
    }

    c2_emxFree_real_T(chartInstance, &c2_b_varargin_2);
    c2_i448 = c2_c_idx->size[0];
    c2_c_idx->size[0] = c2_ndx->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_c_idx, c2_i448,
      &c2_hb_emlrtRTEI);
    c2_g_loop_ub = c2_ndx->size[0] - 1;
    for (c2_i449 = 0; c2_i449 <= c2_g_loop_ub; c2_i449++) {
      c2_c_idx->data[c2_i449] = (int32_T)c2_ndx->data[c2_i449];
    }

    c2_emxInit_int32_T(chartInstance, &c2_c_b, 1, &c2_ib_emlrtRTEI);
    c2_i450 = c2_c_b->size[0];
    c2_c_b->size[0] = c2_varargin_2->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_c_b, c2_i450,
      &c2_ib_emlrtRTEI);
    c2_h_loop_ub = c2_varargin_2->size[0] - 1;
    for (c2_i451 = 0; c2_i451 <= c2_h_loop_ub; c2_i451++) {
      c2_c_b->data[c2_i451] = (int32_T)c2_varargin_2->data[c2_i451] - 1;
    }

    c2_emxFree_real_T(chartInstance, &c2_varargin_2);
    c2_i452 = c2_c_b->size[0];
    c2_c_b->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_c_b, c2_i452,
      &c2_jb_emlrtRTEI);
    c2_i_loop_ub = c2_c_b->size[0] - 1;
    for (c2_i453 = 0; c2_i453 <= c2_i_loop_ub; c2_i453++) {
      c2_c_b->data[c2_i453] *= 120;
    }

    c2_i454 = c2_c_idx->size[0];
    c2_c_idx->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_c_idx, c2_i454,
      &c2_kb_emlrtRTEI);
    c2_j_loop_ub = c2_c_idx->size[0] - 1;
    for (c2_i455 = 0; c2_i455 <= c2_j_loop_ub; c2_i455++) {
      c2_c_idx->data[c2_i455] += c2_c_b->data[c2_i455];
    }

    c2_emxFree_int32_T(chartInstance, &c2_c_b);
    c2_i456 = c2_ndx->size[0];
    c2_ndx->size[0] = c2_c_idx->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_ndx, c2_i456,
      &c2_lb_emlrtRTEI);
    c2_k_loop_ub = c2_c_idx->size[0] - 1;
    for (c2_i457 = 0; c2_i457 <= c2_k_loop_ub; c2_i457++) {
      c2_ndx->data[c2_i457] = (real_T)c2_c_idx->data[c2_i457];
    }

    c2_emxFree_int32_T(chartInstance, &c2_c_idx);
    c2_emxInit_real_T1(chartInstance, &c2_idxE, 1, &c2_ld_emlrtRTEI);
    c2_i458 = c2_idxE->size[0];
    c2_idxE->size[0] = c2_ndx->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_idxE, c2_i458,
      &c2_ld_emlrtRTEI);
    c2_l_loop_ub = c2_ndx->size[0] - 1;
    for (c2_i459 = 0; c2_i459 <= c2_l_loop_ub; c2_i459++) {
      c2_idxE->data[c2_i459] = c2_ndx->data[c2_i459];
    }

    c2_emxFree_real_T(chartInstance, &c2_ndx);
    for (c2_i460 = 0; c2_i460 < 51; c2_i460++) {
      c2_ar = c2_Opca[c2_i460].re;
      c2_ai = c2_Opca[c2_i460].im;
      c2_br = c2_dv7[c2_i460];
      c2_bi = 0.0;
      if (c2_bi == 0.0) {
        if (c2_ai == 0.0) {
          c2_w0[c2_i460].re = c2_ar / c2_br;
          c2_w0[c2_i460].im = 0.0;
        } else if (c2_ar == 0.0) {
          c2_w0[c2_i460].re = 0.0;
          c2_w0[c2_i460].im = c2_ai / c2_br;
        } else {
          c2_w0[c2_i460].re = c2_ar / c2_br;
          c2_w0[c2_i460].im = c2_ai / c2_br;
        }
      } else if (c2_br == 0.0) {
        if (c2_ar == 0.0) {
          c2_w0[c2_i460].re = c2_ai / c2_bi;
          c2_w0[c2_i460].im = 0.0;
        } else if (c2_ai == 0.0) {
          c2_w0[c2_i460].re = 0.0;
          c2_w0[c2_i460].im = -(c2_ar / c2_bi);
        } else {
          c2_w0[c2_i460].re = c2_ai / c2_bi;
          c2_w0[c2_i460].im = -(c2_ar / c2_bi);
        }
      } else {
        c2_brm = muDoubleScalarAbs(c2_br);
        c2_bim = muDoubleScalarAbs(c2_bi);
        if (c2_brm > c2_bim) {
          c2_s = c2_bi / c2_br;
          c2_d = c2_br + c2_s * c2_bi;
          c2_nr = c2_ar + c2_s * c2_ai;
          c2_ni = c2_ai - c2_s * c2_ar;
          c2_w0[c2_i460].re = c2_nr / c2_d;
          c2_w0[c2_i460].im = c2_ni / c2_d;
        } else if (c2_bim == c2_brm) {
          if (c2_br > 0.0) {
            c2_sgnbr = 0.5;
          } else {
            c2_sgnbr = -0.5;
          }

          if (c2_bi > 0.0) {
            c2_sgnbi = 0.5;
          } else {
            c2_sgnbi = -0.5;
          }

          c2_nr = c2_ar * c2_sgnbr + c2_ai * c2_sgnbi;
          c2_ni = c2_ai * c2_sgnbr - c2_ar * c2_sgnbi;
          c2_w0[c2_i460].re = c2_nr / c2_brm;
          c2_w0[c2_i460].im = c2_ni / c2_brm;
        } else {
          c2_s = c2_br / c2_bi;
          c2_d = c2_bi + c2_s * c2_br;
          c2_nr = c2_s * c2_ar + c2_ai;
          c2_ni = c2_s * c2_ai - c2_ar;
          c2_w0[c2_i460].re = c2_nr / c2_d;
          c2_w0[c2_i460].im = c2_ni / c2_d;
        }
      }
    }

    c2_c_varargin_2 = c2_Ex->size[0];
    c2_d_varargin_2 = c2_c_varargin_2;
    c2_lenE = (real_T)c2_d_varargin_2;
    for (c2_i461 = 0; c2_i461 < 19200; c2_i461++) {
      c2_c_accumMatrix[c2_i461].re = 0.0;
      c2_c_accumMatrix[c2_i461].im = 0.0;
    }

    c2_i462 = (int32_T)((c2_lenE + 19606.0) / 19607.0);
    _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 19607.0, c2_lenE, mxDOUBLE_CLASS, c2_i462);
    c2_b_i = 0;
    c2_emxInit_real_T1(chartInstance, &c2_Ex_chunk, 1, &c2_qd_emlrtRTEI);
    c2_emxInit_real_T1(chartInstance, &c2_Ey_chunk, 1, &c2_rd_emlrtRTEI);
    c2_emxInit_real_T1(chartInstance, &c2_idxE_chunk, 1, &c2_sd_emlrtRTEI);
    c2_emxInit_real32_T(chartInstance, &c2_xc, 2, &c2_td_emlrtRTEI);
    c2_emxInit_real32_T(chartInstance, &c2_yc, 2, &c2_ud_emlrtRTEI);
    c2_emxInit_creal_T1(chartInstance, &c2_w, 2, &c2_vd_emlrtRTEI);
    c2_emxInit_boolean_T(chartInstance, &c2_inside, 2, &c2_wd_emlrtRTEI);
    c2_emxInit_int32_T(chartInstance, &c2_xckeep, 1, &c2_xd_emlrtRTEI);
    c2_emxInit_int32_T(chartInstance, &c2_yckeep, 1, &c2_yd_emlrtRTEI);
    c2_emxInit_creal_T(chartInstance, &c2_wkeep, 1, &c2_ae_emlrtRTEI);
    c2_emxInit_real_T(chartInstance, &c2_r7, 2, &c2_nd_emlrtRTEI);
    while (c2_b_i <= c2_i462 - 1) {
      c2_c_i = 1.0 + (real_T)c2_b_i * 19607.0;
      c2_e_varargin_2 = c2_lenE;
      c2_k_varargin_1 = c2_e_varargin_2;
      c2_k_y = c2_k_varargin_1;
      c2_l_y = c2_k_y;
      c2_m_y = c2_l_y;
      c2_n_y = c2_m_y;
      c2_o_y = c2_n_y;
      c2_minval = c2_o_y;
      c2_l_a = c2_c_i;
      c2_b_d = c2_minval;
      c2_m_a = c2_l_a;
      c2_d_b = c2_b_d;
      c2_i_x = c2_m_a;
      c2_e_b = muDoubleScalarIsNaN(c2_i_x);
      guard1 = false;
      guard2 = false;
      guard3 = false;
      if (c2_e_b) {
        guard2 = true;
      } else {
        c2_j_x = c2_d_b;
        c2_f_b = muDoubleScalarIsNaN(c2_j_x);
        if (c2_f_b) {
          guard2 = true;
        } else if (c2_d_b < c2_m_a) {
          c2_i464 = c2_r7->size[0] * c2_r7->size[1];
          c2_r7->size[0] = 1;
          c2_r7->size[1] = 0;
          c2_i467 = c2_r7->size[0];
          c2_i468 = c2_r7->size[1];
        } else {
          c2_k_x = c2_m_a;
          c2_g_b = muDoubleScalarIsInf(c2_k_x);
          if (c2_g_b) {
            guard3 = true;
          } else {
            c2_l_x = c2_d_b;
            c2_h_b = muDoubleScalarIsInf(c2_l_x);
            if (c2_h_b) {
              guard3 = true;
            } else {
              guard1 = true;
            }
          }
        }
      }

      if (guard3) {
        if (c2_m_a == c2_d_b) {
          c2_i469 = c2_r7->size[0] * c2_r7->size[1];
          c2_r7->size[0] = 1;
          c2_r7->size[1] = 1;
          c2_emxEnsureCapacity_real_T(chartInstance, c2_r7, c2_i469,
            &c2_md_emlrtRTEI);
          c2_i471 = c2_r7->size[0];
          c2_i474 = c2_r7->size[1];
          c2_r7->data[0] = rtNaN;
        } else {
          guard1 = true;
        }
      }

      if (guard2) {
        c2_i463 = c2_r7->size[0] * c2_r7->size[1];
        c2_r7->size[0] = 1;
        c2_r7->size[1] = 1;
        c2_emxEnsureCapacity_real_T(chartInstance, c2_r7, c2_i463,
          &c2_md_emlrtRTEI);
        c2_i465 = c2_r7->size[0];
        c2_i466 = c2_r7->size[1];
        c2_r7->data[0] = rtNaN;
      }

      if (guard1) {
        c2_m_x = c2_m_a;
        c2_n_x = c2_m_x;
        c2_n_x = muDoubleScalarFloor(c2_n_x);
        if (c2_n_x == c2_m_a) {
          c2_i473 = c2_r7->size[0] * c2_r7->size[1];
          c2_r7->size[0] = 1;
          c2_r7->size[1] = (int32_T)muDoubleScalarFloor(c2_d_b - c2_m_a) + 1;
          c2_emxEnsureCapacity_real_T(chartInstance, c2_r7, c2_i473,
            &c2_md_emlrtRTEI);
          c2_m_loop_ub = (int32_T)muDoubleScalarFloor(c2_d_b - c2_m_a);
          for (c2_i476 = 0; c2_i476 <= c2_m_loop_ub; c2_i476++) {
            c2_r7->data[c2_i476] = c2_m_a + (real_T)c2_i476;
          }
        } else {
          c2_n_a = c2_m_a;
          c2_i_b = c2_d_b;
          c2_o_a = c2_n_a;
          c2_j_b = c2_i_b;
          c2_anew = c2_o_a;
          c2_o_x = (c2_j_b - c2_o_a) + 0.5;
          c2_ndbl = c2_o_x;
          c2_ndbl = muDoubleScalarFloor(c2_ndbl);
          c2_apnd = c2_o_a + c2_ndbl;
          c2_cdiff = c2_apnd - c2_j_b;
          c2_p_x = c2_cdiff;
          c2_q_x = c2_p_x;
          c2_r_x = c2_q_x;
          c2_p_y = muDoubleScalarAbs(c2_r_x);
          c2_p_a = c2_o_a;
          c2_k_b = c2_j_b;
          c2_s_x = c2_p_a;
          c2_t_x = c2_s_x;
          c2_u_x = c2_t_x;
          c2_absa = muDoubleScalarAbs(c2_u_x);
          c2_v_x = c2_k_b;
          c2_w_x = c2_v_x;
          c2_x_x = c2_w_x;
          c2_absb = muDoubleScalarAbs(c2_x_x);
          if (c2_absa > c2_absb) {
            c2_c = c2_absa;
          } else {
            c2_c = c2_absb;
          }

          if (c2_p_y < 4.4408920985006262E-16 * c2_c) {
            c2_ndbl++;
            c2_bnew = c2_j_b;
          } else if (c2_cdiff > 0.0) {
            c2_bnew = c2_o_a + (c2_ndbl - 1.0);
          } else {
            c2_ndbl++;
            c2_bnew = c2_apnd;
          }

          if (c2_ndbl >= 0.0) {
            c2_n = (int32_T)muDoubleScalarFloor(c2_ndbl);
          } else {
            c2_n = 0;
          }

          c2_i484 = c2_r7->size[0] * c2_r7->size[1];
          c2_r7->size[0] = 1;
          c2_r7->size[1] = c2_n;
          c2_emxEnsureCapacity_real_T(chartInstance, c2_r7, c2_i484,
            &c2_pd_emlrtRTEI);
          if (c2_n > 0) {
            c2_r7->data[0] = c2_anew;
            if (c2_n > 1) {
              c2_r7->data[c2_n - 1] = c2_bnew;
              c2_q_a = c2_n - 1;
              c2_nm1 = c2_q_a;
              c2_r_a = c2_nm1;
              c2_nm1d2 = c2_div_nzp_s32(chartInstance, c2_r_a, 2, 0, 1U, 0, 0);
              c2_t_a = c2_nm1d2 - 2;
              c2_i490 = c2_t_a;
              c2_m_b = c2_i490 + 1;
              c2_o_b = c2_m_b;
              if (1 > c2_o_b) {
                c2_overflow = false;
              } else {
                c2_overflow = (c2_o_b > 2147483646);
              }

              if (c2_overflow) {
                c2_check_forloop_overflow_error(chartInstance, true);
              }

              for (c2_e_k = 1; c2_e_k - 1 <= c2_i490; c2_e_k++) {
                c2_f_k = c2_e_k;
                c2_kd = (real_T)c2_f_k;
                c2_v_a = c2_f_k;
                c2_c_c = c2_v_a;
                c2_r7->data[c2_c_c] = c2_anew + c2_kd;
                c2_y_a = c2_n;
                c2_s_b = c2_f_k;
                c2_f_c = (c2_y_a - c2_s_b) - 1;
                c2_r7->data[c2_f_c] = c2_bnew - c2_kd;
              }

              c2_q_b = c2_nm1d2;
              c2_b_c = c2_q_b << 1;
              if (c2_b_c == c2_nm1) {
                c2_w_a = c2_nm1d2;
                c2_d_c = c2_w_a;
                c2_r7->data[c2_d_c] = (c2_anew + c2_bnew) / 2.0;
              } else {
                c2_kd = (real_T)c2_nm1d2;
                c2_x_a = c2_nm1d2;
                c2_e_c = c2_x_a;
                c2_r7->data[c2_e_c] = c2_anew + c2_kd;
                c2_ab_a = c2_nm1d2;
                c2_g_c = c2_ab_a;
                c2_r7->data[c2_g_c + 1] = c2_bnew - c2_kd;
              }
            }
          }
        }
      }

      c2_sizeChunk = (real_T)c2_r7->size[1];
      c2_i470 = c2_Ex_chunk->size[0];
      c2_Ex_chunk->size[0] = (int32_T)c2_sizeChunk;
      c2_emxEnsureCapacity_real_T1(chartInstance, c2_Ex_chunk, c2_i470,
        &c2_nd_emlrtRTEI);
      c2_i472 = c2_Ey_chunk->size[0];
      c2_Ey_chunk->size[0] = (int32_T)c2_sizeChunk;
      c2_emxEnsureCapacity_real_T1(chartInstance, c2_Ey_chunk, c2_i472,
        &c2_nd_emlrtRTEI);
      c2_i475 = c2_idxE_chunk->size[0];
      c2_idxE_chunk->size[0] = (int32_T)c2_sizeChunk;
      c2_emxEnsureCapacity_real_T1(chartInstance, c2_idxE_chunk, c2_i475,
        &c2_nd_emlrtRTEI);
      c2_idxEdge = (int32_T)c2_c_i;
      c2_i477 = (int32_T)c2_sizeChunk - 1;
      for (c2_d_idx = 0; c2_d_idx <= c2_i477; c2_d_idx++) {
        c2_e_idx = 1.0 + (real_T)c2_d_idx;
        c2_Ex_chunk->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_e_idx, 1,
          c2_Ex_chunk->size[0]) - 1] = c2_Ex->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c2_idxEdge, 1, c2_Ex->size[0]) - 1];
        c2_Ey_chunk->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_e_idx, 1,
          c2_Ey_chunk->size[0]) - 1] = c2_Ey->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c2_idxEdge, 1, c2_Ey->size[0]) - 1];
        c2_idxE_chunk->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           (int32_T)c2_e_idx, 1, c2_idxE_chunk->size[0]) - 1] = c2_idxE->
          data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_idxEdge, 1, c2_idxE->
          size[0]) - 1];
        c2_idxEdge++;
      }

      c2_dim1 = (real_T)c2_idxE_chunk->size[0];
      c2_i478 = c2_xc->size[0] * c2_xc->size[1];
      c2_xc->size[0] = (int32_T)c2_dim1;
      c2_xc->size[1] = 51;
      c2_emxEnsureCapacity_real32_T(chartInstance, c2_xc, c2_i478,
        &c2_nd_emlrtRTEI);
      c2_i479 = c2_yc->size[0] * c2_yc->size[1];
      c2_yc->size[0] = (int32_T)c2_dim1;
      c2_yc->size[1] = 51;
      c2_emxEnsureCapacity_real32_T(chartInstance, c2_yc, c2_i479,
        &c2_nd_emlrtRTEI);
      c2_i480 = c2_w->size[0] * c2_w->size[1];
      c2_w->size[0] = (int32_T)c2_dim1;
      c2_w->size[1] = 51;
      c2_emxEnsureCapacity_creal_T1(chartInstance, c2_w, c2_i480,
        &c2_nd_emlrtRTEI);
      c2_i481 = c2_inside->size[0] * c2_inside->size[1];
      c2_inside->size[0] = (int32_T)c2_dim1;
      c2_inside->size[1] = 51;
      c2_emxEnsureCapacity_boolean_T(chartInstance, c2_inside, c2_i481,
        &c2_nd_emlrtRTEI);
      c2_rows_to_keep_size[0] = (int32_T)c2_dim1;
      c2_n_loop_ub = (int32_T)c2_dim1 - 1;
      for (c2_i482 = 0; c2_i482 <= c2_n_loop_ub; c2_i482++) {
        c2_rows_to_keep_data[c2_i482] = false;
      }

      for (c2_idx2 = 0; c2_idx2 < 51; c2_idx2++) {
        c2_b_idx2 = 1.0 + (real_T)c2_idx2;
        c2_i485 = (int32_T)c2_dim1 - 1;
        for (c2_idx1 = 0; c2_idx1 <= c2_i485; c2_idx1++) {
          c2_b_idx1 = 1.0 + (real_T)c2_idx1;
          c2_y_x = chartInstance->c2_Gx[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, (int32_T)c2_idxE_chunk->
             data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_idx1, 1,
              c2_idxE_chunk->size[0]) - 1], 1, 19200) - 1];
          c2_q_y = c2_b_gradientImg[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, (int32_T)c2_idxE_chunk->
             data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_idx1, 1,
              c2_idxE_chunk->size[0]) - 1], 1, 19200) - 1];
          c2_ab_x = c2_y_x;
          c2_r_y = c2_q_y;
          c2_z = c2_ab_x / c2_r_y;
          c2_s_a = -(15.0 + 0.5 * (real_T)((int32_T)c2_b_idx2 - 1));
          c2_l_b = c2_z;
          c2_s_y = (real32_T)c2_s_a * c2_l_b;
          c2_bb_x = (real32_T)c2_Ex_chunk->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, (int32_T)c2_b_idx1, 1, c2_Ex_chunk->size[0]) - 1] +
            c2_s_y;
          if (c2_bb_x > 0.0F) {
            c2_t_y = c2_bb_x + 0.5F;
          } else if (c2_bb_x < 0.0F) {
            c2_t_y = c2_bb_x - 0.5F;
          } else {
            c2_t_y = 0.0F;
          }

          c2_xc->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_idx1, 1,
            c2_xc->size[0]) + c2_xc->size[0] * ((int32_T)c2_b_idx2 - 1)) - 1] =
            c2_t_y;
          c2_cb_x = chartInstance->c2_Gy[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, (int32_T)c2_idxE_chunk->
             data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_idx1, 1,
              c2_idxE_chunk->size[0]) - 1], 1, 19200) - 1];
          c2_u_y = c2_b_gradientImg[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, (int32_T)c2_idxE_chunk->
             data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_idx1, 1,
              c2_idxE_chunk->size[0]) - 1], 1, 19200) - 1];
          c2_db_x = c2_cb_x;
          c2_v_y = c2_u_y;
          c2_b_z = c2_db_x / c2_v_y;
          c2_u_a = -(15.0 + 0.5 * (real_T)((int32_T)c2_b_idx2 - 1));
          c2_r_b = c2_b_z;
          c2_w_y = (real32_T)c2_u_a * c2_r_b;
          c2_eb_x = (real32_T)c2_Ey_chunk->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, (int32_T)c2_b_idx1, 1, c2_Ey_chunk->size[0]) - 1] +
            c2_w_y;
          if (c2_eb_x > 0.0F) {
            c2_x_y = c2_eb_x + 0.5F;
          } else if (c2_eb_x < 0.0F) {
            c2_x_y = c2_eb_x - 0.5F;
          } else {
            c2_x_y = 0.0F;
          }

          c2_yc->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_idx1, 1,
            c2_yc->size[0]) + c2_yc->size[0] * ((int32_T)c2_b_idx2 - 1)) - 1] =
            c2_x_y;
          c2_w->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_idx1, 1,
            c2_w->size[0]) + c2_w->size[0] * ((int32_T)c2_b_idx2 - 1)) - 1].re =
            c2_w0[(int32_T)c2_b_idx2 - 1].re;
          c2_w->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_idx1, 1,
            c2_w->size[0]) + c2_w->size[0] * ((int32_T)c2_b_idx2 - 1)) - 1].im =
            c2_w0[(int32_T)c2_b_idx2 - 1].im;
          c2_b33 = (c2_xc->data[(sf_eml_array_bounds_check
                     (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                      MAX_uint32_T, (int32_T)c2_b_idx1, 1, c2_xc->size[0]) +
                     c2_xc->size[0] * ((int32_T)c2_b_idx2 - 1)) - 1] >= 1.0F);
          c2_b34 = (c2_xc->data[(sf_eml_array_bounds_check
                     (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                      MAX_uint32_T, (int32_T)c2_b_idx1, 1, c2_xc->size[0]) +
                     c2_xc->size[0] * ((int32_T)c2_b_idx2 - 1)) - 1] <= 160.0F);
          c2_b35 = (c2_b33 && c2_b34);
          c2_b36 = (c2_yc->data[(sf_eml_array_bounds_check
                     (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                      MAX_uint32_T, (int32_T)c2_b_idx1, 1, c2_yc->size[0]) +
                     c2_yc->size[0] * ((int32_T)c2_b_idx2 - 1)) - 1] >= 1.0F);
          c2_b37 = (c2_b35 && c2_b36);
          c2_b38 = (c2_yc->data[(sf_eml_array_bounds_check
                     (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                      MAX_uint32_T, (int32_T)c2_b_idx1, 1, c2_yc->size[0]) +
                     c2_yc->size[0] * ((int32_T)c2_b_idx2 - 1)) - 1] < 120.0F);
          c2_inside->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_idx1, 1,
            c2_inside->size[0]) + c2_inside->size[0] * ((int32_T)c2_b_idx2 - 1))
            - 1] = (c2_b37 && c2_b38);
          if (c2_inside->data[(sf_eml_array_bounds_check
                               (sfGlobalDebugInstanceStruct, chartInstance->S,
                                1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_idx1, 1,
                                c2_inside->size[0]) + c2_inside->size[0] *
                               ((int32_T)c2_b_idx2 - 1)) - 1]) {
            c2_rows_to_keep_data[sf_eml_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
               MAX_uint32_T, (int32_T)c2_b_idx1, 1, c2_rows_to_keep_size[0]) - 1]
              = true;
          }
        }
      }

      c2_i483 = c2_xckeep->size[0];
      c2_xckeep->size[0] = c2_xc->size[0] * 51;
      c2_emxEnsureCapacity_int32_T(chartInstance, c2_xckeep, c2_i483,
        &c2_nd_emlrtRTEI);
      c2_i486 = c2_yckeep->size[0];
      c2_yckeep->size[0] = c2_yc->size[0] * 51;
      c2_emxEnsureCapacity_int32_T(chartInstance, c2_yckeep, c2_i486,
        &c2_nd_emlrtRTEI);
      c2_i487 = c2_wkeep->size[0];
      c2_wkeep->size[0] = c2_w->size[0] * 51;
      c2_emxEnsureCapacity_creal_T(chartInstance, c2_wkeep, c2_i487,
        &c2_nd_emlrtRTEI);
      c2_idxkeep = 0;
      for (c2_c_idx2 = 0; c2_c_idx2 < 51; c2_c_idx2++) {
        c2_b_idx2 = 1.0 + (real_T)c2_c_idx2;
        c2_i489 = (int32_T)c2_dim1 - 1;
        for (c2_c_idx1 = 0; c2_c_idx1 <= c2_i489; c2_c_idx1++) {
          c2_b_idx1 = 1.0 + (real_T)c2_c_idx1;
          if (c2_rows_to_keep_data[sf_eml_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
               MAX_uint32_T, (int32_T)c2_b_idx1, 1, c2_rows_to_keep_size[0]) - 1]
              && c2_inside->data[(sf_eml_array_bounds_check
                                  (sfGlobalDebugInstanceStruct, chartInstance->S,
                1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_idx1, 1, c2_inside->size[0])
               + c2_inside->size[0] * ((int32_T)c2_b_idx2 - 1)) - 1]) {
            c2_idxkeep++;
            c2_b_xckeep[0] = c2_xckeep->size[0];
            c2_b_xckeep[1] = 1;
            c2_xckeep->data[sf_eml_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
               MAX_uint32_T, c2_idxkeep, 1, c2_xckeep->size[0]) - 1] = (int32_T)
              c2_xc->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_idx1, 1,
              c2_xc->size[0]) + c2_xc->size[0] * ((int32_T)c2_b_idx2 - 1)) - 1];
            c2_b_yckeep[0] = c2_yckeep->size[0];
            c2_b_yckeep[1] = 1;
            c2_yckeep->data[sf_eml_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
               MAX_uint32_T, c2_idxkeep, 1, c2_yckeep->size[0]) - 1] = (int32_T)
              c2_yc->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_idx1, 1,
              c2_yc->size[0]) + c2_yc->size[0] * ((int32_T)c2_b_idx2 - 1)) - 1];
            c2_b_wkeep[0] = c2_wkeep->size[0];
            c2_b_wkeep[1] = 1;
            c2_wkeep->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_idxkeep, 1,
              c2_wkeep->size[0]) - 1].re = c2_w->data[(sf_eml_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
               MAX_uint32_T, (int32_T)c2_b_idx1, 1, c2_w->size[0]) + c2_w->size
              [0] * ((int32_T)c2_b_idx2 - 1)) - 1].re;
            c2_wkeep->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_idxkeep, 1,
              c2_wkeep->size[0]) - 1].im = c2_w->data[(sf_eml_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
               MAX_uint32_T, (int32_T)c2_b_idx1, 1, c2_w->size[0]) + c2_w->size
              [0] * ((int32_T)c2_b_idx2 - 1)) - 1].im;
          }
        }
      }

      c2_szxc = c2_idxkeep;
      for (c2_i488 = 0; c2_i488 < 19200; c2_i488++) {
        chartInstance->c2_out[c2_i488].re = 0.0;
        chartInstance->c2_out[c2_i488].im = 0.0;
      }

      c2_n_b = c2_szxc;
      c2_p_b = c2_n_b;
      if (1 > c2_p_b) {
        c2_b_overflow = false;
      } else {
        c2_b_overflow = (c2_p_b > 2147483646);
      }

      if (c2_b_overflow) {
        c2_check_forloop_overflow_error(chartInstance, true);
      }

      for (c2_f_idx = 1; c2_f_idx - 1 < c2_szxc; c2_f_idx++) {
        c2_g_idx = c2_f_idx;
        chartInstance->c2_out[(sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c2_yckeep->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_g_idx, 1, c2_yckeep->
          size[0]) - 1], 1, 120) + 120 * (sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c2_xckeep->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_g_idx, 1, c2_xckeep->
          size[0]) - 1], 1, 160) - 1)) - 1].re = chartInstance->c2_out
          [(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
             chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_yckeep->
             data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_g_idx, 1,
              c2_yckeep->size[0]) - 1], 1, 120) + 120 *
            (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_xckeep->
              data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
               chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_g_idx, 1,
               c2_xckeep->size[0]) - 1], 1, 160) - 1)) - 1].re + c2_wkeep->
          data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_g_idx, 1, c2_wkeep->size
          [0]) - 1].re;
        chartInstance->c2_out[(sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c2_yckeep->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_g_idx, 1, c2_yckeep->
          size[0]) - 1], 1, 120) + 120 * (sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c2_xckeep->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_g_idx, 1, c2_xckeep->
          size[0]) - 1], 1, 160) - 1)) - 1].im = chartInstance->c2_out
          [(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
             chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_yckeep->
             data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_g_idx, 1,
              c2_yckeep->size[0]) - 1], 1, 120) + 120 *
            (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_xckeep->
              data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
               chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_g_idx, 1,
               c2_xckeep->size[0]) - 1], 1, 160) - 1)) - 1].im + c2_wkeep->
          data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_g_idx, 1, c2_wkeep->size
          [0]) - 1].im;
      }

      for (c2_i491 = 0; c2_i491 < 19200; c2_i491++) {
        c2_c_accumMatrix[c2_i491].re += chartInstance->c2_out[c2_i491].re;
        c2_c_accumMatrix[c2_i491].im += chartInstance->c2_out[c2_i491].im;
      }

      c2_b_i++;
    }

    c2_emxFree_real_T(chartInstance, &c2_Ex);
    c2_emxFree_real_T(chartInstance, &c2_Ey);
    c2_emxFree_real_T(chartInstance, &c2_r7);
    c2_emxFree_creal_T(chartInstance, &c2_wkeep);
    c2_emxFree_int32_T(chartInstance, &c2_yckeep);
    c2_emxFree_int32_T(chartInstance, &c2_xckeep);
    c2_emxFree_boolean_T(chartInstance, &c2_inside);
    c2_emxFree_creal_T(chartInstance, &c2_w);
    c2_emxFree_real32_T(chartInstance, &c2_yc);
    c2_emxFree_real32_T(chartInstance, &c2_xc);
    c2_emxFree_real_T(chartInstance, &c2_idxE_chunk);
    c2_emxFree_real_T(chartInstance, &c2_Ey_chunk);
    c2_emxFree_real_T(chartInstance, &c2_Ex_chunk);
    c2_emxFree_real_T(chartInstance, &c2_idxE);
  }
}

static real32_T c2_multithresh(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real32_T c2_h_varargin_1[19200])
{
  real32_T c2_thresh;
  int32_T c2_i492;
  int32_T c2_i493;
  real_T c2_mu[256];
  real32_T c2_minA;
  real32_T c2_maxA;
  boolean_T c2_emptyp;
  int32_T c2_i494;
  real32_T c2_b_minA;
  int32_T c2_k;
  real_T c2_omega[256];
  real32_T c2_d_x;
  boolean_T c2_b;
  int32_T c2_i495;
  int32_T c2_b_k;
  int32_T c2_c_k;
  real32_T c2_threshout;
  real_T c2_mu_t;
  int32_T c2_d_k;
  real_T c2_sigma_b_squared[256];
  real_T c2_e_x;
  real_T c2_f_x;
  boolean_T c2_b_b;
  boolean_T c2_p;
  int32_T c2_b_idx;
  int32_T c2_e_k;
  int32_T c2_first;
  real_T c2_maxval;
  real_T c2_g_x;
  real_T c2_ex;
  real_T c2_h_x;
  int32_T c2_i496;
  boolean_T c2_isvalid_maxval;
  boolean_T c2_c_b;
  int32_T c2_f_k;
  c2_emxArray_real32_T *c2_b_threshout;
  boolean_T c2_b_p;
  c2_emxArray_real_T *c2_threshRaw;
  c2_emxArray_real32_T *c2_uniqueVals;
  int32_T c2_i497;
  real_T c2_idxSum;
  real_T c2_idxNum;
  boolean_T c2_isDegenerate;
  int32_T c2_ind;
  int32_T c2_i498;
  real_T c2_b_ind;
  int32_T c2_i499;
  int32_T c2_i500;
  int32_T c2_i501;
  int32_T c2_i502;
  int32_T c2_i503;
  int32_T c2_loop_ub;
  boolean_T c2_b_isDegenerate;
  real32_T c2_c_minA;
  int32_T c2_i504;
  real32_T c2_b_maxA;
  int32_T c2_i505;
  real32_T c2_d_minA;
  int32_T c2_i506;
  real32_T c2_c_maxA;
  int32_T c2_i507;
  int32_T c2_i508;
  int32_T c2_i509;
  int32_T c2_i510;
  int32_T c2_i511;
  int32_T c2_i512;
  int32_T c2_b_loop_ub;
  int32_T c2_i513;
  int32_T c2_i514;
  int32_T c2_i515;
  int32_T c2_c_loop_ub;
  real_T c2_d_b;
  int32_T c2_i516;
  int32_T c2_i517;
  int32_T c2_i518;
  real_T c2_e_b;
  int32_T c2_i519;
  int32_T c2_i520;
  int32_T c2_i521;
  int32_T c2_i522;
  int32_T c2_i523;
  int32_T c2_i524;
  int32_T c2_d_loop_ub;
  int32_T c2_i525;
  int32_T c2_i526;
  int32_T c2_i527;
  int32_T c2_e_loop_ub;
  int32_T c2_i528;
  int32_T c2_i529;
  int32_T c2_i530;
  int32_T c2_i531;
  int32_T c2_i532;
  int32_T c2_i533;
  int32_T c2_i534;
  int32_T c2_i535;
  int32_T c2_i536;
  int32_T c2_f_loop_ub;
  int32_T c2_i537;
  int32_T c2_i538;
  int32_T c2_i539;
  int32_T c2_g_loop_ub;
  int32_T c2_i540;
  int32_T c2_i541;
  int32_T c2_i542;
  int32_T c2_i543;
  int32_T c2_i544;
  int32_T c2_h_loop_ub;
  int32_T c2_i545;
  int32_T c2_i546;
  int32_T c2_i547;
  int32_T c2_i_loop_ub;
  int32_T c2_i548;
  boolean_T exitg1;
  for (c2_i492 = 0; c2_i492 < 19200; c2_i492++) {
    chartInstance->c2_c_A[c2_i492] = c2_h_varargin_1[c2_i492];
  }

  for (c2_i493 = 0; c2_i493 < 19200; c2_i493++) {
    chartInstance->c2_d_A[c2_i493] = chartInstance->c2_c_A[c2_i493];
  }

  c2_getpdf(chartInstance, chartInstance->c2_d_A, c2_mu, &c2_minA, &c2_maxA,
            &c2_emptyp);
  if (c2_emptyp) {
    c2_d_warning(chartInstance, 1.0);
    c2_b_minA = c2_minA;
    c2_d_x = c2_b_minA;
    c2_b = muSingleScalarIsNaN(c2_d_x);
    if (c2_b) {
      c2_b_minA = 1.0F;
    }

    c2_threshout = c2_b_minA;
    c2_thresh = c2_threshout;
  } else {
    for (c2_i494 = 0; c2_i494 < 256; c2_i494++) {
      c2_omega[c2_i494] = c2_mu[c2_i494];
    }

    for (c2_k = 0; c2_k < 255; c2_k++) {
      c2_b_k = c2_k;
      c2_omega[c2_b_k + 1] += c2_omega[c2_b_k];
    }

    for (c2_i495 = 0; c2_i495 < 256; c2_i495++) {
      c2_mu[c2_i495] *= 1.0 + (real_T)c2_i495;
    }

    for (c2_c_k = 0; c2_c_k < 255; c2_c_k++) {
      c2_d_k = c2_c_k;
      c2_mu[c2_d_k + 1] += c2_mu[c2_d_k];
    }

    c2_mu_t = c2_mu[255];
    c2_calcFullObjCriteriaMatrix(chartInstance, c2_omega, c2_mu, c2_mu_t,
      c2_sigma_b_squared);
    c2_e_x = c2_sigma_b_squared[0];
    c2_f_x = c2_e_x;
    c2_b_b = muDoubleScalarIsNaN(c2_f_x);
    c2_p = !c2_b_b;
    if (c2_p) {
      c2_b_idx = 1;
    } else {
      c2_b_idx = 0;
      c2_e_k = 2;
      exitg1 = false;
      while ((!exitg1) && (c2_e_k < 257)) {
        c2_g_x = c2_sigma_b_squared[c2_e_k - 1];
        c2_h_x = c2_g_x;
        c2_c_b = muDoubleScalarIsNaN(c2_h_x);
        c2_b_p = !c2_c_b;
        if (c2_b_p) {
          c2_b_idx = c2_e_k;
          exitg1 = true;
        } else {
          c2_e_k++;
        }
      }
    }

    if (c2_b_idx == 0) {
      c2_maxval = c2_sigma_b_squared[0];
    } else {
      c2_first = c2_b_idx - 1;
      c2_ex = c2_sigma_b_squared[c2_first];
      c2_i496 = c2_first;
      for (c2_f_k = c2_i496 + 1; c2_f_k + 1 < 257; c2_f_k++) {
        if (c2_ex < c2_sigma_b_squared[c2_f_k]) {
          c2_ex = c2_sigma_b_squared[c2_f_k];
        }
      }

      c2_maxval = c2_ex;
    }

    c2_isvalid_maxval = c2_isfinite(chartInstance, c2_maxval);
    c2_emxInit_real32_T(chartInstance, &c2_b_threshout, 2, &c2_ie_emlrtRTEI);
    c2_emxInit_real_T(chartInstance, &c2_threshRaw, 2, &c2_ce_emlrtRTEI);
    c2_emxInit_real32_T(chartInstance, &c2_uniqueVals, 2, &c2_je_emlrtRTEI);
    if (c2_isvalid_maxval) {
      c2_idxSum = 0.0;
      c2_idxNum = 0.0;
      for (c2_ind = 0; c2_ind < 256; c2_ind++) {
        c2_b_ind = 1.0 + (real_T)c2_ind;
        if (c2_sigma_b_squared[(int32_T)c2_b_ind - 1] == c2_maxval) {
          c2_idxSum += c2_b_ind;
          c2_idxNum++;
        }
      }

      c2_i498 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
      c2_threshRaw->size[0] = 1;
      c2_threshRaw->size[1] = 1;
      c2_emxEnsureCapacity_real_T(chartInstance, c2_threshRaw, c2_i498,
        &c2_ce_emlrtRTEI);
      c2_i500 = c2_threshRaw->size[0];
      c2_i501 = c2_threshRaw->size[1];
      c2_threshRaw->data[0] = c2_idxSum / c2_idxNum - 1.0;
    } else {
      for (c2_i497 = 0; c2_i497 < 19200; c2_i497++) {
        chartInstance->c2_e_A[c2_i497] = chartInstance->c2_c_A[c2_i497];
      }

      c2_checkForDegenerateInput(chartInstance, chartInstance->c2_e_A, 1.0,
        &c2_isDegenerate, c2_uniqueVals);
      if (c2_isDegenerate) {
        c2_d_warning(chartInstance, 1.0);
      } else {
        c2_e_warning(chartInstance);
      }

      c2_getDegenerateThresholds(chartInstance, c2_uniqueVals, c2_b_threshout);
      c2_i499 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
      c2_threshRaw->size[0] = 1;
      c2_threshRaw->size[1] = c2_b_threshout->size[1];
      c2_emxEnsureCapacity_real_T(chartInstance, c2_threshRaw, c2_i499,
        &c2_de_emlrtRTEI);
      c2_i502 = c2_threshRaw->size[0];
      c2_i503 = c2_threshRaw->size[1];
      c2_loop_ub = c2_b_threshout->size[0] * c2_b_threshout->size[1] - 1;
      for (c2_i504 = 0; c2_i504 <= c2_loop_ub; c2_i504++) {
        c2_threshRaw->data[c2_i504] = c2_b_threshout->data[c2_i504];
      }
    }

    if (c2_isvalid_maxval) {
      c2_c_minA = c2_minA;
      c2_b_maxA = c2_maxA;
      c2_i505 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
      c2_i506 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
      c2_threshRaw->size[0] = 1;
      c2_threshRaw->size[1];
      c2_emxEnsureCapacity_real_T(chartInstance, c2_threshRaw, c2_i506,
        &c2_ee_emlrtRTEI);
      c2_i509 = c2_threshRaw->size[0];
      c2_i510 = c2_threshRaw->size[1];
      c2_i511 = c2_i505;
      c2_b_loop_ub = c2_i511 - 1;
      for (c2_i514 = 0; c2_i514 <= c2_b_loop_ub; c2_i514++) {
        c2_threshRaw->data[c2_i514] /= 255.0;
      }

      c2_d_b = (real_T)c2_b_maxA - (real_T)c2_c_minA;
      c2_i517 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
      c2_i518 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
      c2_threshRaw->size[0] = 1;
      c2_threshRaw->size[1];
      c2_emxEnsureCapacity_real_T(chartInstance, c2_threshRaw, c2_i518,
        &c2_l_emlrtRTEI);
      c2_i521 = c2_threshRaw->size[0];
      c2_i522 = c2_threshRaw->size[1];
      c2_i523 = c2_i517;
      c2_d_loop_ub = c2_i523 - 1;
      for (c2_i526 = 0; c2_i526 <= c2_d_loop_ub; c2_i526++) {
        c2_threshRaw->data[c2_i526] *= c2_d_b;
      }

      c2_i528 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
      c2_i530 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
      c2_threshRaw->size[0] = 1;
      c2_threshRaw->size[1];
      c2_emxEnsureCapacity_real_T(chartInstance, c2_threshRaw, c2_i530,
        &c2_fe_emlrtRTEI);
      c2_i533 = c2_threshRaw->size[0];
      c2_i534 = c2_threshRaw->size[1];
      c2_i535 = c2_i528;
      c2_f_loop_ub = c2_i535 - 1;
      for (c2_i538 = 0; c2_i538 <= c2_f_loop_ub; c2_i538++) {
        c2_threshRaw->data[c2_i538] += (real_T)c2_c_minA;
      }

      c2_i540 = c2_b_threshout->size[0] * c2_b_threshout->size[1];
      c2_b_threshout->size[0] = 1;
      c2_b_threshout->size[1] = c2_threshRaw->size[1];
      c2_emxEnsureCapacity_real32_T(chartInstance, c2_b_threshout, c2_i540,
        &c2_ge_emlrtRTEI);
      c2_i543 = c2_b_threshout->size[0];
      c2_i544 = c2_b_threshout->size[1];
      c2_h_loop_ub = c2_threshRaw->size[0] * c2_threshRaw->size[1] - 1;
      for (c2_i546 = 0; c2_i546 <= c2_h_loop_ub; c2_i546++) {
        c2_b_threshout->data[c2_i546] = (real32_T)c2_threshRaw->data[c2_i546];
      }
    } else {
      c2_checkForDegenerateInput(chartInstance, chartInstance->c2_c_A, 1.0,
        &c2_b_isDegenerate, c2_uniqueVals);
      if (c2_b_isDegenerate) {
        c2_d_warning(chartInstance, 1.0);
        c2_getDegenerateThresholds(chartInstance, c2_uniqueVals, c2_b_threshout);
      } else {
        c2_e_warning(chartInstance);
        c2_d_minA = c2_minA;
        c2_c_maxA = c2_maxA;
        c2_i507 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
        c2_i508 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
        c2_threshRaw->size[0] = 1;
        c2_threshRaw->size[1];
        c2_emxEnsureCapacity_real_T(chartInstance, c2_threshRaw, c2_i508,
          &c2_ee_emlrtRTEI);
        c2_i512 = c2_threshRaw->size[0];
        c2_i513 = c2_threshRaw->size[1];
        c2_i515 = c2_i507;
        c2_c_loop_ub = c2_i515 - 1;
        for (c2_i516 = 0; c2_i516 <= c2_c_loop_ub; c2_i516++) {
          c2_threshRaw->data[c2_i516] /= 255.0;
        }

        c2_e_b = (real_T)c2_c_maxA - (real_T)c2_d_minA;
        c2_i519 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
        c2_i520 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
        c2_threshRaw->size[0] = 1;
        c2_threshRaw->size[1];
        c2_emxEnsureCapacity_real_T(chartInstance, c2_threshRaw, c2_i520,
          &c2_l_emlrtRTEI);
        c2_i524 = c2_threshRaw->size[0];
        c2_i525 = c2_threshRaw->size[1];
        c2_i527 = c2_i519;
        c2_e_loop_ub = c2_i527 - 1;
        for (c2_i529 = 0; c2_i529 <= c2_e_loop_ub; c2_i529++) {
          c2_threshRaw->data[c2_i529] *= c2_e_b;
        }

        c2_i531 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
        c2_i532 = c2_threshRaw->size[0] * c2_threshRaw->size[1];
        c2_threshRaw->size[0] = 1;
        c2_threshRaw->size[1];
        c2_emxEnsureCapacity_real_T(chartInstance, c2_threshRaw, c2_i532,
          &c2_fe_emlrtRTEI);
        c2_i536 = c2_threshRaw->size[0];
        c2_i537 = c2_threshRaw->size[1];
        c2_i539 = c2_i531;
        c2_g_loop_ub = c2_i539 - 1;
        for (c2_i541 = 0; c2_i541 <= c2_g_loop_ub; c2_i541++) {
          c2_threshRaw->data[c2_i541] += (real_T)c2_d_minA;
        }

        c2_i542 = c2_b_threshout->size[0] * c2_b_threshout->size[1];
        c2_b_threshout->size[0] = 1;
        c2_b_threshout->size[1] = c2_threshRaw->size[1];
        c2_emxEnsureCapacity_real32_T(chartInstance, c2_b_threshout, c2_i542,
          &c2_he_emlrtRTEI);
        c2_i545 = c2_b_threshout->size[0];
        c2_i547 = c2_b_threshout->size[1];
        c2_i_loop_ub = c2_threshRaw->size[0] * c2_threshRaw->size[1] - 1;
        for (c2_i548 = 0; c2_i548 <= c2_i_loop_ub; c2_i548++) {
          c2_b_threshout->data[c2_i548] = (real32_T)c2_threshRaw->data[c2_i548];
        }
      }
    }

    c2_emxFree_real32_T(chartInstance, &c2_uniqueVals);
    c2_emxFree_real_T(chartInstance, &c2_threshRaw);
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_b_threshout->size[1]);
    c2_thresh = c2_b_threshout->data[0];
    c2_emxFree_real32_T(chartInstance, &c2_b_threshout);
  }

  return c2_thresh;
}

static void c2_getpdf(SFc2_flightControlSystemInstanceStruct *chartInstance,
                      real32_T c2_g_A[19200], real_T c2_p[256], real32_T
                      *c2_minA, real32_T *c2_maxA, boolean_T *c2_emptyp)
{
  int32_T c2_b_idx;
  int32_T c2_i549;
  real32_T c2_d_x;
  int32_T c2_i550;
  real32_T c2_e_x;
  int32_T c2_k;
  boolean_T c2_b;
  boolean_T c2_b_p;
  real32_T c2_l_a;
  int32_T c2_c_idx;
  int32_T c2_i551;
  int32_T c2_b_k;
  real32_T c2_c_y;
  int32_T c2_first;
  real32_T c2_d_y;
  real32_T c2_f_x;
  real32_T c2_ex;
  int32_T c2_i552;
  real32_T c2_g_x;
  int32_T c2_i553;
  int32_T c2_i554;
  boolean_T c2_b_b;
  int32_T c2_c_k;
  int32_T c2_i555;
  boolean_T c2_c_p;
  real32_T c2_h_x;
  real32_T c2_i_x;
  int32_T c2_i556;
  boolean_T c2_c_b;
  boolean_T c2_d_p;
  int32_T c2_trueCount;
  boolean_T c2_nans[19200];
  int32_T c2_i;
  int32_T c2_d_idx;
  int32_T c2_d_k;
  int32_T c2_b_first;
  int32_T c2_b_trueCount;
  real32_T c2_j_x;
  real32_T c2_b_ex;
  int32_T c2_b_i;
  real32_T c2_k_x;
  int32_T c2_i557;
  boolean_T c2_d_b;
  int32_T c2_e_k;
  boolean_T c2_e_p;
  c2_emxArray_int32_T *c2_r8;
  int32_T c2_i558;
  int32_T c2_partialTrueCount;
  int32_T c2_c_i;
  c2_emxArray_real32_T *c2_h_A;
  int32_T c2_i559;
  int32_T c2_loop_ub;
  int32_T c2_i560;
  uint8_T c2_Auint8_data[19200];
  int32_T c2_Auint8_size[1];
  real_T c2_counts[256];
  int32_T c2_i561;
  real_T c2_d11;
  real_T c2_b_counts[256];
  int32_T c2_i562;
  boolean_T exitg1;
  *c2_emptyp = true;
  c2_b_idx = 0;
  while ((c2_b_idx + 1 <= 19200) && (!c2_b_isfinite(chartInstance,
           c2_g_A[c2_b_idx]))) {
    c2_b_idx++;
  }

  if (c2_b_idx + 1 <= 19200) {
    *c2_minA = c2_g_A[c2_b_idx];
    *c2_maxA = c2_g_A[c2_b_idx];
    c2_i550 = c2_b_idx;
    for (c2_k = c2_i550 + 2; c2_k < 19201; c2_k++) {
      c2_l_a = c2_g_A[c2_k - 1];
      if ((c2_l_a < *c2_minA) && c2_b_isfinite(chartInstance, c2_l_a)) {
        *c2_minA = c2_l_a;
      } else {
        if ((c2_l_a > *c2_maxA) && c2_b_isfinite(chartInstance, c2_l_a)) {
          *c2_maxA = c2_l_a;
        }
      }
    }

    if (*c2_minA == *c2_maxA) {
    } else {
      for (c2_i551 = 0; c2_i551 < 19200; c2_i551++) {
        c2_g_A[c2_i551] -= *c2_minA;
      }

      c2_c_y = *c2_maxA - *c2_minA;
      c2_d_y = c2_c_y;
      for (c2_i552 = 0; c2_i552 < 19200; c2_i552++) {
        c2_g_A[c2_i552] /= c2_d_y;
      }

      for (c2_i555 = 0; c2_i555 < 19200; c2_i555++) {
        chartInstance->c2_f_A[c2_i555] = c2_g_A[c2_i555];
      }

      for (c2_i556 = 0; c2_i556 < 19200; c2_i556++) {
        c2_nans[c2_i556] = muSingleScalarIsNaN(chartInstance->c2_f_A[c2_i556]);
      }

      c2_trueCount = 0;
      for (c2_i = 0; c2_i < 19200; c2_i++) {
        if (!c2_nans[c2_i]) {
          c2_trueCount++;
        }
      }

      if (c2_trueCount != 0) {
        c2_b_trueCount = 0;
        for (c2_b_i = 0; c2_b_i < 19200; c2_b_i++) {
          if (!c2_nans[c2_b_i]) {
            c2_b_trueCount++;
          }
        }

        c2_emxInit_int32_T(chartInstance, &c2_r8, 1, &c2_me_emlrtRTEI);
        c2_i558 = c2_r8->size[0];
        c2_r8->size[0] = c2_b_trueCount;
        c2_emxEnsureCapacity_int32_T(chartInstance, c2_r8, c2_i558,
          &c2_ke_emlrtRTEI);
        c2_partialTrueCount = 0;
        for (c2_c_i = 0; c2_c_i < 19200; c2_c_i++) {
          if (!c2_nans[c2_c_i]) {
            c2_r8->data[c2_partialTrueCount] = c2_c_i + 1;
            c2_partialTrueCount++;
          }
        }

        c2_emxInit_real32_T1(chartInstance, &c2_h_A, 1, &c2_le_emlrtRTEI);
        c2_i559 = c2_h_A->size[0];
        c2_h_A->size[0] = c2_r8->size[0];
        c2_emxEnsureCapacity_real32_T1(chartInstance, c2_h_A, c2_i559,
          &c2_le_emlrtRTEI);
        c2_loop_ub = c2_r8->size[0] - 1;
        for (c2_i560 = 0; c2_i560 <= c2_loop_ub; c2_i560++) {
          c2_h_A->data[c2_i560] = chartInstance->c2_f_A[c2_r8->data[c2_i560] - 1];
        }

        c2_emxFree_int32_T(chartInstance, &c2_r8);
        c2_im2uint8(chartInstance, c2_h_A, c2_Auint8_data, c2_Auint8_size);
        c2_b_imhist(chartInstance, c2_Auint8_data, c2_Auint8_size, c2_counts);
        c2_emxFree_real32_T(chartInstance, &c2_h_A);
        for (c2_i561 = 0; c2_i561 < 256; c2_i561++) {
          c2_b_counts[c2_i561] = c2_counts[c2_i561];
        }

        c2_d11 = c2_sum(chartInstance, c2_b_counts);
        for (c2_i562 = 0; c2_i562 < 256; c2_i562++) {
          c2_p[c2_i562] = c2_counts[c2_i562] / c2_d11;
        }

        *c2_emptyp = false;
      }
    }
  } else {
    for (c2_i549 = 0; c2_i549 < 19200; c2_i549++) {
      chartInstance->c2_f_A[c2_i549] = c2_g_A[c2_i549];
    }

    c2_d_x = chartInstance->c2_f_A[0];
    c2_e_x = c2_d_x;
    c2_b = muSingleScalarIsNaN(c2_e_x);
    c2_b_p = !c2_b;
    if (c2_b_p) {
      c2_c_idx = 1;
    } else {
      c2_c_idx = 0;
      c2_b_k = 2;
      exitg1 = false;
      while ((!exitg1) && (c2_b_k < 19201)) {
        c2_f_x = chartInstance->c2_f_A[c2_b_k - 1];
        c2_g_x = c2_f_x;
        c2_b_b = muSingleScalarIsNaN(c2_g_x);
        c2_c_p = !c2_b_b;
        if (c2_c_p) {
          c2_c_idx = c2_b_k;
          exitg1 = true;
        } else {
          c2_b_k++;
        }
      }
    }

    if (c2_c_idx == 0) {
      *c2_minA = chartInstance->c2_f_A[0];
    } else {
      c2_first = c2_c_idx - 1;
      c2_ex = chartInstance->c2_f_A[c2_first];
      c2_i553 = c2_first;
      for (c2_c_k = c2_i553 + 1; c2_c_k + 1 < 19201; c2_c_k++) {
        if (c2_ex > chartInstance->c2_f_A[c2_c_k]) {
          c2_ex = chartInstance->c2_f_A[c2_c_k];
        }
      }

      *c2_minA = c2_ex;
    }

    for (c2_i554 = 0; c2_i554 < 19200; c2_i554++) {
      chartInstance->c2_f_A[c2_i554] = c2_g_A[c2_i554];
    }

    c2_h_x = chartInstance->c2_f_A[0];
    c2_i_x = c2_h_x;
    c2_c_b = muSingleScalarIsNaN(c2_i_x);
    c2_d_p = !c2_c_b;
    if (c2_d_p) {
      c2_d_idx = 1;
    } else {
      c2_d_idx = 0;
      c2_d_k = 2;
      exitg1 = false;
      while ((!exitg1) && (c2_d_k < 19201)) {
        c2_j_x = chartInstance->c2_f_A[c2_d_k - 1];
        c2_k_x = c2_j_x;
        c2_d_b = muSingleScalarIsNaN(c2_k_x);
        c2_e_p = !c2_d_b;
        if (c2_e_p) {
          c2_d_idx = c2_d_k;
          exitg1 = true;
        } else {
          c2_d_k++;
        }
      }
    }

    if (c2_d_idx == 0) {
      *c2_maxA = chartInstance->c2_f_A[0];
    } else {
      c2_b_first = c2_d_idx - 1;
      c2_b_ex = chartInstance->c2_f_A[c2_b_first];
      c2_i557 = c2_b_first;
      for (c2_e_k = c2_i557 + 1; c2_e_k + 1 < 19201; c2_e_k++) {
        if (c2_b_ex < chartInstance->c2_f_A[c2_e_k]) {
          c2_b_ex = chartInstance->c2_f_A[c2_e_k];
        }
      }

      *c2_maxA = c2_b_ex;
    }
  }
}

static void c2_im2uint8(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_real32_T *c2_img, uint8_T c2_u_data[], int32_T c2_u_size[1])
{
  real_T c2_numElems;
  real_T c2_b_numElems;
  (void)chartInstance;
  c2_u_size[0] = c2_img->size[0];
  c2_numElems = (real_T)c2_img->size[0];
  c2_b_numElems = c2_numElems;
  grayto8_real32(&c2_img->data[0], &c2_u_data[0], c2_b_numElems);
}

static void c2_b_imhist(SFc2_flightControlSystemInstanceStruct *chartInstance,
  uint8_T c2_varargin_1_data[], int32_T c2_varargin_1_size[1], real_T c2_yout
  [256])
{
  real_T c2_b_out;
  int32_T c2_i563;
  int32_T c2_i564;
  int32_T c2_i565;
  real_T c2_localBins1[256];
  int32_T c2_i566;
  real_T c2_localBins2[256];
  int32_T c2_i;
  real_T c2_localBins3[256];
  int32_T c2_idx1;
  int32_T c2_idx2;
  int32_T c2_b_i;
  int32_T c2_b_idx;
  int32_T c2_idx3;
  int32_T c2_l_a;
  int32_T c2_idx4;
  real_T c2_c_i;
  int32_T c2_c;
  int32_T c2_m_a;
  int32_T c2_n_a;
  int32_T c2_b_c;
  int32_T c2_c_c;
  int32_T c2_o_a;
  int32_T c2_d_c;
  int32_T c2_p_a;
  int32_T c2_e_c;
  int32_T c2_q_a;
  int32_T c2_f_c;
  int32_T c2_r_a;
  int32_T c2_g_c;
  int32_T c2_s_a;
  int32_T c2_h_c;
  int32_T c2_t_a;
  int32_T c2_i_c;
  int32_T c2_u_a;
  int32_T c2_j_c;
  c2_b_out = 1.0;
  getnumcores(&c2_b_out);
  for (c2_i563 = 0; c2_i563 < 256; c2_i563++) {
    c2_yout[c2_i563] = 0.0;
  }

  for (c2_i564 = 0; c2_i564 < 256; c2_i564++) {
    c2_localBins1[c2_i564] = 0.0;
  }

  for (c2_i565 = 0; c2_i565 < 256; c2_i565++) {
    c2_localBins2[c2_i565] = 0.0;
  }

  for (c2_i566 = 0; c2_i566 < 256; c2_i566++) {
    c2_localBins3[c2_i566] = 0.0;
  }

  for (c2_i = 1; c2_i + 3 <= c2_varargin_1_size[0]; c2_i += 4) {
    c2_idx1 = c2_varargin_1_data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       c2_i, 1, c2_varargin_1_size[0]) - 1];
    c2_idx2 = c2_varargin_1_data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       c2_i + 1, 1, c2_varargin_1_size[0]) - 1];
    c2_idx3 = c2_varargin_1_data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       c2_i + 2, 1, c2_varargin_1_size[0]) - 1];
    c2_idx4 = c2_varargin_1_data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       c2_i + 3, 1, c2_varargin_1_size[0]) - 1];
    c2_m_a = c2_idx1;
    c2_b_c = c2_m_a;
    c2_o_a = c2_idx1;
    c2_d_c = c2_o_a;
    c2_localBins1[c2_b_c] = c2_localBins1[c2_d_c] + 1.0;
    c2_p_a = c2_idx2;
    c2_e_c = c2_p_a;
    c2_q_a = c2_idx2;
    c2_f_c = c2_q_a;
    c2_localBins2[c2_e_c] = c2_localBins2[c2_f_c] + 1.0;
    c2_r_a = c2_idx3;
    c2_g_c = c2_r_a;
    c2_s_a = c2_idx3;
    c2_h_c = c2_s_a;
    c2_localBins3[c2_g_c] = c2_localBins3[c2_h_c] + 1.0;
    c2_t_a = c2_idx4;
    c2_i_c = c2_t_a;
    c2_u_a = c2_idx4;
    c2_j_c = c2_u_a;
    c2_yout[c2_i_c] = c2_yout[c2_j_c] + 1.0;
  }

  while (c2_i <= c2_varargin_1_size[0]) {
    c2_b_idx = c2_varargin_1_data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       c2_i, 1, c2_varargin_1_size[0]) - 1];
    c2_l_a = c2_b_idx;
    c2_c = c2_l_a;
    c2_n_a = c2_b_idx;
    c2_c_c = c2_n_a;
    c2_yout[c2_c] = c2_yout[c2_c_c] + 1.0;
    c2_i++;
  }

  for (c2_b_i = 0; c2_b_i < 256; c2_b_i++) {
    c2_c_i = 1.0 + (real_T)c2_b_i;
    c2_yout[(int32_T)c2_c_i - 1] = ((c2_yout[(int32_T)c2_c_i - 1] +
      c2_localBins1[(int32_T)c2_c_i - 1]) + c2_localBins2[(int32_T)c2_c_i - 1])
      + c2_localBins3[(int32_T)c2_c_i - 1];
  }
}

static real_T c2_sum(SFc2_flightControlSystemInstanceStruct *chartInstance,
                     real_T c2_d_x[256])
{
  real_T c2_c_y;
  int32_T c2_k;
  int32_T c2_xoffset;
  int32_T c2_ix;
  (void)chartInstance;
  c2_c_y = c2_d_x[0];
  for (c2_k = 0; c2_k < 255; c2_k++) {
    c2_xoffset = c2_k;
    c2_ix = c2_xoffset;
    c2_c_y += c2_d_x[c2_ix + 1];
  }

  return c2_c_y;
}

static void c2_d_warning(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real_T c2_h_varargin_1)
{
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv38[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c2_d_y = NULL;
  static char_T c2_cv39[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c2_e_y = NULL;
  static char_T c2_msgID[34] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'm', 'u',
    'l', 't', 'i', 't', 'h', 'r', 'e', 's', 'h', ':', 'd', 'e', 'g', 'e', 'n',
    'e', 'r', 'a', 't', 'e', 'I', 'n', 'p', 'u', 't' };

  real_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  (void)chartInstance;
  (void)c2_h_varargin_1;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv38, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv39, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_msgID, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c2_e_u = 1.0;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c2_c_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    3U, 14, c2_d_y, 14, c2_e_y, 14, c2_f_y));
}

static void c2_calcFullObjCriteriaMatrix(SFc2_flightControlSystemInstanceStruct *
  chartInstance, real_T c2_omega[256], real_T c2_mu[256], real_T c2_mu_t, real_T
  c2_sigma_b_squared[256])
{
  real_T c2_l_a;
  int32_T c2_i567;
  int32_T c2_i568;
  real_T c2_c_y[256];
  int32_T c2_k;
  int32_T c2_i569;
  int32_T c2_b_k;
  real_T c2_m_a;
  real_T c2_d_y;
  (void)chartInstance;
  c2_l_a = c2_mu_t;
  for (c2_i567 = 0; c2_i567 < 256; c2_i567++) {
    c2_c_y[c2_i567] = c2_l_a * c2_omega[c2_i567];
  }

  for (c2_i568 = 0; c2_i568 < 256; c2_i568++) {
    c2_c_y[c2_i568] -= c2_mu[c2_i568];
  }

  for (c2_k = 0; c2_k < 256; c2_k++) {
    c2_b_k = c2_k;
    c2_m_a = c2_c_y[c2_b_k];
    c2_d_y = c2_m_a * c2_m_a;
    c2_sigma_b_squared[c2_b_k] = c2_d_y;
  }

  for (c2_i569 = 0; c2_i569 < 256; c2_i569++) {
    c2_sigma_b_squared[c2_i569] /= c2_omega[c2_i569] * (1.0 - c2_omega[c2_i569]);
  }
}

static void c2_sortIdx(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_d_x[19200], int32_T c2_b_idx[19200])
{
  int32_T c2_i570;
  int32_T c2_k;
  int32_T c2_i;
  int32_T c2_i571;
  int32_T c2_l_a;
  int32_T c2_c_i2;
  int32_T c2_j;
  int32_T c2_pEnd;
  int32_T c2_p;
  int32_T c2_q;
  int32_T c2_qEnd;
  int32_T c2_b_k;
  int32_T c2_kEnd;
  int32_T c2_i572;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_c_k;
  for (c2_i570 = 0; c2_i570 < 19200; c2_i570++) {
    c2_b_idx[c2_i570] = 0;
  }

  for (c2_k = 0; c2_k <= 19199; c2_k += 2) {
    for (c2_i571 = 0; c2_i571 < 19200; c2_i571++) {
      chartInstance->c2_b_x[c2_i571] = c2_d_x[c2_i571];
    }

    if (c2_sortLE(chartInstance, chartInstance->c2_b_x, c2_k + 1, c2_k + 2)) {
      c2_b_idx[c2_k] = c2_k + 1;
      c2_b_idx[c2_k + 1] = c2_k + 2;
    } else {
      c2_b_idx[c2_k] = c2_k + 2;
      c2_b_idx[c2_k + 1] = c2_k + 1;
    }
  }

  c2_i = 2;
  while (c2_i < 19200) {
    c2_l_a = c2_i;
    c2_c_i2 = c2_l_a << 1;
    c2_j = 1;
    for (c2_pEnd = 1 + c2_i; c2_pEnd < 19201; c2_pEnd = c2_qEnd + c2_i) {
      c2_p = c2_j - 1;
      c2_q = c2_pEnd - 1;
      c2_qEnd = c2_j + c2_c_i2;
      if (c2_qEnd > 19201) {
        c2_qEnd = 19201;
      }

      c2_b_k = 0;
      c2_kEnd = c2_qEnd - c2_j;
      while (c2_b_k + 1 <= c2_kEnd) {
        for (c2_i572 = 0; c2_i572 < 19200; c2_i572++) {
          chartInstance->c2_c_x[c2_i572] = c2_d_x[c2_i572];
        }

        if (c2_sortLE(chartInstance, chartInstance->c2_c_x, c2_b_idx[c2_p],
                      c2_b_idx[c2_q])) {
          chartInstance->c2_iwork[c2_b_k] = c2_b_idx[c2_p];
          c2_p++;
          if (c2_p + 1 == c2_pEnd) {
            while (c2_q + 1 < c2_qEnd) {
              c2_b_k++;
              chartInstance->c2_iwork[c2_b_k] = c2_b_idx[c2_q];
              c2_q++;
            }
          }
        } else {
          chartInstance->c2_iwork[c2_b_k] = c2_b_idx[c2_q];
          c2_q++;
          if (c2_q + 1 == c2_qEnd) {
            while (c2_p + 1 < c2_pEnd) {
              c2_b_k++;
              chartInstance->c2_iwork[c2_b_k] = c2_b_idx[c2_p];
              c2_p++;
            }
          }
        }

        c2_b_k++;
      }

      c2_p = c2_j - 2;
      c2_b = c2_kEnd;
      c2_b_b = c2_b;
      if (1 > c2_b_b) {
        c2_overflow = false;
      } else {
        c2_overflow = (c2_b_b > 2147483646);
      }

      if (c2_overflow) {
        c2_check_forloop_overflow_error(chartInstance, true);
      }

      for (c2_c_k = 0; c2_c_k < c2_kEnd; c2_c_k++) {
        c2_b_k = c2_c_k;
        c2_b_idx[(c2_p + c2_b_k) + 1] = chartInstance->c2_iwork[c2_b_k];
      }

      c2_j = c2_qEnd;
    }

    c2_i = c2_c_i2;
  }
}

static boolean_T c2_sortLE(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real32_T c2_v[19200], int32_T c2_idx1, int32_T c2_idx2)
{
  real32_T c2_l_a;
  real32_T c2_b;
  real32_T c2_m_a;
  real32_T c2_b_b;
  real32_T c2_n_a;
  real32_T c2_c_b;
  boolean_T c2_b_p;
  real32_T c2_d_x;
  boolean_T c2_d_b;
  boolean_T c2_c_p;
  (void)chartInstance;
  c2_l_a = c2_v[c2_idx1 - 1];
  c2_b = c2_v[c2_idx2 - 1];
  c2_m_a = c2_l_a;
  c2_b_b = c2_b;
  c2_n_a = c2_m_a;
  c2_c_b = c2_b_b;
  c2_b_p = (c2_n_a <= c2_c_b);
  if (c2_b_p) {
    c2_c_p = true;
  } else {
    c2_d_x = c2_b_b;
    c2_d_b = muSingleScalarIsNaN(c2_d_x);
    if (c2_d_b) {
      c2_c_p = true;
    } else {
      c2_c_p = false;
    }
  }

  return c2_c_p;
}

static void c2_count_nonfinites(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_b, int32_T c2_nb, int32_T *c2_nMInf,
  int32_T *c2_nFinite, int32_T *c2_nPInf, int32_T *c2_nNaN)
{
  int32_T c2_k;
  real32_T c2_d_x;
  int32_T c2_b_b;
  boolean_T c2_c_b;
  int32_T c2_l_a;
  real32_T c2_e_x;
  boolean_T c2_d_b;
  int32_T c2_e_b;
  int32_T c2_c;
  int32_T c2_m_a;
  int32_T c2_n_a;
  int32_T c2_f_b;
  int32_T c2_o_a;
  int32_T c2_g_b;
  boolean_T exitg1;
  (void)chartInstance;
  (void)c2_nb;
  *c2_nMInf = 0;
  c2_k = 19200;
  exitg1 = false;
  while ((!exitg1) && (c2_k >= 1)) {
    c2_d_x = c2_b->data[c2_k - 1];
    c2_c_b = muSingleScalarIsNaN(c2_d_x);
    if (c2_c_b) {
      c2_l_a = c2_k - 1;
      c2_k = c2_l_a;
    } else {
      exitg1 = true;
    }
  }

  c2_b_b = c2_k;
  *c2_nNaN = 19200 - c2_b_b;
  exitg1 = false;
  while ((!exitg1) && (c2_k >= 1)) {
    c2_e_x = c2_b->data[c2_k - 1];
    c2_d_b = muSingleScalarIsInf(c2_e_x);
    if (c2_d_b && (c2_b->data[c2_k - 1] > 0.0F)) {
      c2_n_a = c2_k - 1;
      c2_k = c2_n_a;
    } else {
      exitg1 = true;
    }
  }

  c2_e_b = c2_k;
  c2_c = 19200 - c2_e_b;
  c2_m_a = c2_c;
  c2_f_b = *c2_nNaN;
  *c2_nPInf = c2_m_a - c2_f_b;
  c2_o_a = c2_k;
  c2_g_b = *c2_nMInf;
  *c2_nFinite = c2_o_a - c2_g_b;
}

static void c2_checkForDegenerateInput(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real32_T c2_g_A[19200], real_T c2_N, boolean_T
  *c2_isDegenerate, c2_emxArray_real32_T *c2_uniqueVals)
{
  c2_emxArray_real32_T *c2_b;
  int32_T c2_i573;
  int32_T c2_i574;
  c2_emxArray_real32_T *c2_r9;
  int32_T c2_i575;
  int32_T c2_i576;
  int32_T c2_i577;
  int32_T c2_k;
  c2_emxArray_real32_T *c2_b_b;
  int32_T c2_b_k;
  int32_T c2_i578;
  int32_T c2_loop_ub;
  int32_T c2_i579;
  int32_T c2_nMInf;
  int32_T c2_nFinite;
  int32_T c2_nInf;
  int32_T c2_nNaN;
  int32_T c2_nb;
  int32_T c2_l_a;
  int32_T c2_c_b;
  int32_T c2_d_b;
  int32_T c2_e_b;
  int32_T c2_khi;
  int32_T c2_m_a;
  boolean_T c2_overflow;
  real32_T c2_d_x;
  int32_T c2_n_a;
  int32_T c2_k0;
  int32_T c2_o_a;
  int32_T c2_f_b;
  int32_T c2_p_a;
  int32_T c2_q_a;
  int32_T c2_c;
  int32_T c2_g_b;
  int32_T c2_h_b;
  int32_T c2_i_b;
  real32_T c2_r_a;
  int32_T c2_j_b;
  real32_T c2_k_b;
  int32_T c2_s_a;
  boolean_T c2_b_overflow;
  real32_T c2_e_x;
  boolean_T c2_c_overflow;
  real32_T c2_f_x;
  real32_T c2_g_x;
  int32_T c2_t_a;
  real32_T c2_c_y;
  int32_T c2_i580;
  int32_T c2_j;
  real32_T c2_h_x;
  int32_T c2_u_a;
  real32_T c2_i_x;
  int32_T c2_l_b;
  real32_T c2_z;
  int32_T c2_v_a;
  boolean_T c2_b39;
  int32_T c2_b_j;
  real32_T c2_j_x;
  int32_T c2_m_b;
  int32_T c2_w_a;
  real32_T c2_k_x;
  int32_T c2_i581;
  real32_T c2_l_x;
  boolean_T c2_d_overflow;
  int32_T c2_x_a;
  real32_T c2_m_x;
  c2_emxArray_int32_T *c2_r10;
  int32_T c2_n_b;
  real32_T c2_absxk;
  int32_T c2_i582;
  int32_T c2_b_c;
  real32_T c2_n_x;
  real32_T c2_o_x;
  boolean_T c2_o_b;
  int32_T c2_b_loop_ub;
  boolean_T c2_b40;
  int32_T c2_i583;
  real32_T c2_p_x;
  boolean_T c2_p_b;
  int32_T c2_iv7[2];
  boolean_T c2_b41;
  boolean_T c2_q_b;
  int32_T c2_i584;
  real32_T c2_r;
  int32_T c2_exponent;
  int32_T c2_b_exponent;
  int32_T c2_r_b;
  real32_T c2_q_x;
  int32_T c2_s_b;
  boolean_T c2_t_b;
  boolean_T c2_p;
  real32_T c2_r_x;
  boolean_T c2_b_p;
  boolean_T c2_e_overflow;
  boolean_T c2_u_b;
  int32_T c2_i585;
  int32_T c2_c_loop_ub;
  int32_T c2_i586;
  int32_T c2_tmp_size[2];
  int32_T c2_i587;
  int32_T c2_i588;
  int32_T c2_d_loop_ub;
  int32_T c2_i589;
  int32_T c2_b_tmp_size[2];
  boolean_T c2_tmp_data[19200];
  int32_T c2_i590;
  int32_T c2_i591;
  int32_T c2_e_loop_ub;
  int32_T c2_i592;
  int32_T c2_i593;
  boolean_T c2_b_tmp_data[19200];
  int32_T c2_i594;
  int32_T c2_iv8[2];
  int32_T c2_iv9[2];
  int32_T c2_c_tmp_size[2];
  int32_T c2_i595;
  int32_T c2_i596;
  int32_T c2_f_loop_ub;
  int32_T c2_i597;
  boolean_T c2_c_tmp_data[19200];
  boolean_T c2_b_isDegenerate;
  int32_T exitg1;
  (void)c2_N;
  c2_emxInit_real32_T1(chartInstance, &c2_b, 1, &c2_ve_emlrtRTEI);
  for (c2_i573 = 0; c2_i573 < 19200; c2_i573++) {
    chartInstance->c2_b_a[c2_i573] = c2_g_A[c2_i573];
  }

  for (c2_i574 = 0; c2_i574 < 19200; c2_i574++) {
    chartInstance->c2_c_a[c2_i574] = chartInstance->c2_b_a[c2_i574];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_r9, 1, &c2_we_emlrtRTEI);
  c2_sortIdx(chartInstance, chartInstance->c2_c_a, chartInstance->c2_idx);
  c2_i575 = c2_r9->size[0];
  c2_r9->size[0] = 19200;
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_r9, c2_i575, &c2_oe_emlrtRTEI);
  for (c2_i576 = 0; c2_i576 < 19200; c2_i576++) {
    c2_r9->data[c2_i576] = 0.0F;
  }

  c2_i577 = c2_b->size[0];
  c2_b->size[0] = c2_r9->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_b, c2_i577, &c2_oe_emlrtRTEI);
  c2_emxFree_real32_T(chartInstance, &c2_r9);
  for (c2_k = 0; c2_k < 19200; c2_k++) {
    c2_b_k = c2_k;
    c2_b->data[c2_b_k] = chartInstance->c2_b_a[chartInstance->c2_idx[c2_b_k] - 1];
  }

  c2_emxInit_real32_T1(chartInstance, &c2_b_b, 1, &c2_pe_emlrtRTEI);
  c2_i578 = c2_b_b->size[0];
  c2_b_b->size[0] = c2_b->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_b_b, c2_i578,
    &c2_pe_emlrtRTEI);
  c2_loop_ub = c2_b->size[0] - 1;
  for (c2_i579 = 0; c2_i579 <= c2_loop_ub; c2_i579++) {
    c2_b_b->data[c2_i579] = c2_b->data[c2_i579];
  }

  c2_count_nonfinites(chartInstance, c2_b_b, 19200, &c2_nMInf, &c2_nFinite,
                      &c2_nInf, &c2_nNaN);
  c2_nb = -1;
  c2_emxFree_real32_T(chartInstance, &c2_b_b);
  if (c2_nMInf > 0) {
    c2_nb = 0;
    c2_c_b = c2_nMInf;
    c2_e_b = c2_c_b;
    if (1 > c2_e_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_e_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }
  }

  c2_l_a = c2_nMInf;
  c2_d_b = c2_nFinite;
  c2_khi = c2_l_a + c2_d_b;
  c2_m_a = c2_nMInf + 1;
  c2_b_k = c2_m_a;
  while (c2_b_k <= c2_khi) {
    c2_d_x = c2_b->data[c2_b_k - 1];
    c2_k0 = c2_b_k;
    do {
      exitg1 = 0;
      c2_q_a = c2_b_k + 1;
      c2_b_k = c2_q_a;
      if (c2_b_k > c2_khi) {
        exitg1 = 1;
      } else {
        c2_r_a = c2_b->data[c2_b_k - 1];
        c2_k_b = c2_d_x;
        c2_e_x = c2_k_b - c2_r_a;
        c2_f_x = c2_e_x;
        c2_g_x = c2_f_x;
        c2_c_y = muSingleScalarAbs(c2_g_x);
        c2_h_x = c2_k_b;
        c2_i_x = c2_h_x;
        c2_z = c2_i_x / 2.0F;
        c2_j_x = c2_z;
        c2_k_x = c2_j_x;
        c2_l_x = c2_k_x;
        c2_m_x = c2_l_x;
        c2_absxk = muSingleScalarAbs(c2_m_x);
        c2_n_x = c2_absxk;
        c2_o_x = c2_n_x;
        c2_o_b = muSingleScalarIsInf(c2_o_x);
        c2_b40 = !c2_o_b;
        c2_p_x = c2_n_x;
        c2_p_b = muSingleScalarIsNaN(c2_p_x);
        c2_b41 = !c2_p_b;
        c2_q_b = (c2_b40 && c2_b41);
        if (c2_q_b) {
          if (c2_absxk <= 1.17549435E-38F) {
            c2_r = 1.4013E-45F;
          } else {
            frexp((real_T)c2_absxk, &c2_exponent);
            c2_b_exponent = c2_exponent;
            c2_r = (real32_T)ldexp(1.0, c2_b_exponent - 24);
          }
        } else {
          c2_r = rtNaNF;
        }

        if (c2_c_y < c2_r) {
          c2_p = true;
        } else {
          c2_q_x = c2_r_a;
          c2_t_b = muSingleScalarIsInf(c2_q_x);
          if (c2_t_b) {
            c2_r_x = c2_k_b;
            c2_u_b = muSingleScalarIsInf(c2_r_x);
            if (c2_u_b && ((c2_r_a > 0.0F) == (c2_k_b > 0.0F))) {
              c2_p = true;
            } else {
              c2_p = false;
            }
          } else {
            c2_p = false;
          }
        }

        c2_b_p = c2_p;
        if (!c2_b_p) {
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);

    c2_s_a = c2_nb + 1;
    c2_nb = c2_s_a;
    c2_b->data[c2_nb] = c2_d_x;
    c2_t_a = c2_b_k;
    c2_i580 = c2_t_a;
    c2_u_a = c2_k0;
    c2_l_b = c2_i580 - 1;
    c2_v_a = c2_u_a;
    c2_m_b = c2_l_b;
    if (c2_v_a > c2_m_b) {
      c2_d_overflow = false;
    } else {
      c2_d_overflow = (c2_m_b > 2147483646);
    }

    if (c2_d_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }
  }

  if (c2_nInf > 0) {
    c2_n_a = c2_nb + 1;
    c2_nb = c2_n_a;
    c2_p_a = c2_khi;
    c2_c = c2_p_a;
    c2_b->data[c2_nb] = c2_b->data[c2_c];
    c2_i_b = c2_nInf;
    c2_j_b = c2_i_b;
    if (1 > c2_j_b) {
      c2_c_overflow = false;
    } else {
      c2_c_overflow = (c2_j_b > 2147483646);
    }

    if (c2_c_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }
  }

  c2_o_a = c2_khi;
  c2_f_b = c2_nInf;
  c2_b_k = c2_o_a + c2_f_b;
  c2_g_b = c2_nNaN;
  c2_h_b = c2_g_b;
  if (1 > c2_h_b) {
    c2_b_overflow = false;
  } else {
    c2_b_overflow = (c2_h_b > 2147483646);
  }

  if (c2_b_overflow) {
    c2_check_forloop_overflow_error(chartInstance, true);
  }

  for (c2_j = 0; c2_j < c2_nNaN; c2_j++) {
    c2_b_j = c2_j;
    c2_w_a = c2_nb + 1;
    c2_nb = c2_w_a;
    c2_x_a = c2_b_k;
    c2_n_b = c2_b_j + 1;
    c2_b_c = (c2_x_a + c2_n_b) - 1;
    c2_b->data[c2_nb] = c2_b->data[c2_b_c];
  }

  c2_b39 = (1 > c2_nb + 1);
  if (c2_b39) {
    c2_i581 = 0;
  } else {
    c2_i581 = c2_nb + 1;
  }

  c2_emxInit_int32_T(chartInstance, &c2_r10, 1, &c2_qe_emlrtRTEI);
  c2_i582 = c2_r10->size[0];
  c2_r10->size[0] = c2_i581;
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_r10, c2_i582, &c2_qe_emlrtRTEI);
  c2_b_loop_ub = c2_i581 - 1;
  for (c2_i583 = 0; c2_i583 <= c2_b_loop_ub; c2_i583++) {
    c2_r10->data[c2_i583] = 1 + c2_i583;
  }

  c2_iv7[0] = 1;
  c2_iv7[1] = c2_r10->size[0];
  c2_indexShapeCheck(chartInstance, 19200, c2_iv7);
  c2_i584 = c2_b->size[0];
  c2_b->size[0] = c2_i581;
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_b, c2_i584, &c2_re_emlrtRTEI);
  c2_r_b = c2_nb + 1;
  c2_s_b = c2_r_b;
  c2_emxFree_int32_T(chartInstance, &c2_r10);
  if (1 > c2_s_b) {
    c2_e_overflow = false;
  } else {
    c2_e_overflow = (c2_s_b > 2147483646);
  }

  if (c2_e_overflow) {
    c2_check_forloop_overflow_error(chartInstance, true);
  }

  c2_i585 = c2_uniqueVals->size[0] * c2_uniqueVals->size[1];
  c2_uniqueVals->size[0] = 1;
  c2_uniqueVals->size[1] = c2_b->size[0];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_uniqueVals, c2_i585,
    &c2_se_emlrtRTEI);
  c2_c_loop_ub = c2_b->size[0] - 1;
  for (c2_i586 = 0; c2_i586 <= c2_c_loop_ub; c2_i586++) {
    c2_uniqueVals->data[c2_i586] = c2_b->data[c2_i586];
  }

  c2_emxFree_real32_T(chartInstance, &c2_b);
  c2_tmp_size[0] = 1;
  c2_tmp_size[1] = c2_uniqueVals->size[1];
  c2_i587 = c2_tmp_size[0];
  c2_i588 = c2_tmp_size[1];
  c2_d_loop_ub = c2_uniqueVals->size[0] * c2_uniqueVals->size[1] - 1;
  for (c2_i589 = 0; c2_i589 <= c2_d_loop_ub; c2_i589++) {
    c2_tmp_data[c2_i589] = muSingleScalarIsInf(c2_uniqueVals->data[c2_i589]);
  }

  c2_b_tmp_size[0] = 1;
  c2_b_tmp_size[1] = c2_uniqueVals->size[1];
  c2_i590 = c2_b_tmp_size[0];
  c2_i591 = c2_b_tmp_size[1];
  c2_e_loop_ub = c2_uniqueVals->size[0] * c2_uniqueVals->size[1] - 1;
  for (c2_i592 = 0; c2_i592 <= c2_e_loop_ub; c2_i592++) {
    c2_b_tmp_data[c2_i592] = muSingleScalarIsNaN(c2_uniqueVals->data[c2_i592]);
  }

  for (c2_i593 = 0; c2_i593 < 2; c2_i593++) {
    c2_iv8[c2_i593] = c2_tmp_size[c2_i593];
  }

  for (c2_i594 = 0; c2_i594 < 2; c2_i594++) {
    c2_iv9[c2_i594] = c2_b_tmp_size[c2_i594];
  }

  _SFD_SIZE_EQ_CHECK_ND(c2_iv8, c2_iv9, 2);
  c2_c_tmp_size[0] = 1;
  c2_c_tmp_size[1] = c2_tmp_size[1];
  c2_i595 = c2_c_tmp_size[0];
  c2_i596 = c2_c_tmp_size[1];
  c2_f_loop_ub = c2_tmp_size[0] * c2_tmp_size[1] - 1;
  for (c2_i597 = 0; c2_i597 <= c2_f_loop_ub; c2_i597++) {
    c2_c_tmp_data[c2_i597] = (c2_tmp_data[c2_i597] || c2_b_tmp_data[c2_i597]);
  }

  c2_f_nullAssignment(chartInstance, c2_uniqueVals, c2_c_tmp_data, c2_c_tmp_size);
  c2_b_isDegenerate = ((real_T)c2_uniqueVals->size[1] <= 1.0);
  *c2_isDegenerate = c2_b_isDegenerate;
}

static void c2_c_nullAssignment(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_d_x, boolean_T c2_idx_data[], int32_T
  c2_idx_size[2], c2_emxArray_real32_T *c2_e_x)
{
  int32_T c2_i598;
  int32_T c2_i599;
  int32_T c2_i600;
  int32_T c2_loop_ub;
  int32_T c2_i601;
  int32_T c2_b_idx_size[2];
  int32_T c2_i602;
  int32_T c2_i603;
  int32_T c2_b_loop_ub;
  int32_T c2_i604;
  boolean_T c2_b_idx_data[19200];
  c2_i598 = c2_e_x->size[0] * c2_e_x->size[1];
  c2_e_x->size[0] = 1;
  c2_e_x->size[1] = c2_d_x->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_e_x, c2_i598, &c2_dc_emlrtRTEI);
  c2_i599 = c2_e_x->size[0];
  c2_i600 = c2_e_x->size[1];
  c2_loop_ub = c2_d_x->size[0] * c2_d_x->size[1] - 1;
  for (c2_i601 = 0; c2_i601 <= c2_loop_ub; c2_i601++) {
    c2_e_x->data[c2_i601] = c2_d_x->data[c2_i601];
  }

  c2_b_idx_size[0] = 1;
  c2_b_idx_size[1] = c2_idx_size[1];
  c2_i602 = c2_b_idx_size[0];
  c2_i603 = c2_b_idx_size[1];
  c2_b_loop_ub = c2_idx_size[0] * c2_idx_size[1] - 1;
  for (c2_i604 = 0; c2_i604 <= c2_b_loop_ub; c2_i604++) {
    c2_b_idx_data[c2_i604] = c2_idx_data[c2_i604];
  }

  c2_f_nullAssignment(chartInstance, c2_e_x, c2_b_idx_data, c2_b_idx_size);
}

static void c2_e_warning(SFc2_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv40[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c2_d_y = NULL;
  static char_T c2_cv41[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c2_e_y = NULL;
  static char_T c2_msgID[32] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'm', 'u',
    'l', 't', 'i', 't', 'h', 'r', 'e', 's', 'h', ':', 'n', 'o', 'C', 'o', 'n',
    'v', 'e', 'r', 'g', 'e', 'n', 'c', 'e' };

  (void)chartInstance;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv40, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv41, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_msgID, 10, 0U, 1U, 0U, 2, 1, 32),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c2_c_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c2_d_y, 14, c2_e_y));
}

static void c2_getDegenerateThresholds(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_uniqueVals, c2_emxArray_real32_T
  *c2_thresh)
{
  boolean_T c2_b42;
  real_T c2_thNeeded1;
  int32_T c2_i605;
  int32_T c2_i606;
  c2_emxArray_real32_T *c2_threshL;
  int32_T c2_i607;
  int32_T c2_i608;
  int32_T c2_i609;
  int32_T c2_i610;
  real32_T c2_d_x;
  int32_T c2_i611;
  real32_T c2_e_x;
  int32_T c2_loop_ub;
  int32_T c2_i612;
  int32_T c2_i613;
  real32_T c2_varargin_2;
  int32_T c2_i614;
  real32_T c2_h_varargin_1;
  int32_T c2_b_loop_ub;
  real32_T c2_c_y;
  int32_T c2_i615;
  real32_T c2_d_y;
  real32_T c2_e_y;
  real32_T c2_f_y;
  real_T c2_thNeeded2;
  real32_T c2_g_y;
  real32_T c2_minval;
  int32_T c2_i616;
  int32_T c2_b_varargin_2;
  real32_T c2_d;
  int32_T c2_c_varargin_2;
  real32_T c2_b;
  real_T c2_lenThreshOrig;
  real32_T c2_f_x;
  int32_T c2_i617;
  boolean_T c2_b_b;
  int32_T c2_i618;
  int32_T c2_i619;
  int32_T c2_y_size[2];
  int32_T c2_c_loop_ub;
  int32_T c2_tmp_size[1];
  int32_T c2_i620;
  int32_T c2_i621;
  int32_T c2_d_loop_ub;
  real_T c2_tmp_data[1];
  int32_T c2_i622;
  int32_T c2_i623;
  int32_T c2_i624;
  int32_T c2_i625;
  real32_T c2_y_data[1];
  c2_emxArray_real_T *c2_uniqueVals_d;
  int32_T c2_i626;
  int32_T c2_i627;
  int32_T c2_i628;
  int32_T c2_i629;
  int32_T c2_i630;
  int32_T c2_e_loop_ub;
  int32_T c2_i631;
  int32_T c2_i632;
  int32_T c2_i633;
  int32_T c2_f_loop_ub;
  int32_T c2_g_loop_ub;
  int32_T c2_i634;
  int32_T c2_i635;
  real32_T c2_g_x;
  real32_T c2_h_x;
  real32_T c2_i_varargin_1;
  real32_T c2_i_x;
  real32_T c2_j_x;
  real32_T c2_k_x;
  real32_T c2_l_x;
  real32_T c2_m_x;
  real32_T c2_n_x;
  real32_T c2_threshCandidate;
  real_T c2_q;
  c2_emxArray_real_T *c2_r11;
  c2_emxArray_real_T *c2_b_uniqueVals_d;
  real_T c2_threshCandidate_d;
  int32_T c2_i636;
  int32_T c2_h_loop_ub;
  int32_T c2_i637;
  real_T c2_d12;
  int32_T c2_b_tmp_size[1];
  int32_T c2_i_loop_ub;
  int32_T c2_i638;
  boolean_T c2_b_tmp_data[19200];
  c2_b42 = (c2_uniqueVals->size[1] == 0);
  if (c2_b42) {
    c2_i605 = c2_thresh->size[0] * c2_thresh->size[1];
    c2_thresh->size[0] = 1;
    c2_thresh->size[1] = 1;
    c2_emxEnsureCapacity_real32_T(chartInstance, c2_thresh, c2_i605,
      &c2_xe_emlrtRTEI);
    c2_i607 = c2_thresh->size[0];
    c2_i609 = c2_thresh->size[1];
    c2_thresh->data[0] = 1.0F;
  } else {
    c2_thNeeded1 = 1.0 - (real_T)c2_uniqueVals->size[1];
    if (c2_thNeeded1 > 0.0) {
      (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_uniqueVals->size[1]);
      c2_emxInit_real32_T(chartInstance, &c2_threshL, 2, &c2_gf_emlrtRTEI);
      if (c2_uniqueVals->data[0] > 1.0F) {
        (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_uniqueVals->size[1]);
        c2_d_x = c2_uniqueVals->data[0];
        c2_e_x = c2_d_x;
        c2_e_x = muSingleScalarCeil(c2_e_x);
        c2_varargin_2 = c2_e_x - 1.0F;
        c2_h_varargin_1 = c2_varargin_2;
        c2_c_y = c2_h_varargin_1;
        c2_d_y = c2_c_y;
        c2_e_y = c2_d_y;
        c2_f_y = c2_e_y;
        c2_g_y = c2_f_y;
        c2_minval = muSingleScalarMin(1.0F, c2_g_y);
        c2_d = c2_minval;
        c2_b = c2_d;
        c2_f_x = c2_b;
        c2_b_b = muSingleScalarIsNaN(c2_f_x);
        if (c2_b_b) {
          c2_y_size[0] = 1;
          c2_y_size[1] = 1;
          c2_i622 = c2_y_size[0];
          c2_i624 = c2_y_size[1];
          c2_y_data[0] = rtNaNF;
        } else if (c2_b < 1.0F) {
          c2_i620 = c2_y_size[0] * c2_y_size[1];
          c2_y_size[0] = 1;
          c2_y_size[1] = 0;
          c2_i625 = c2_y_size[0];
          c2_i627 = c2_y_size[1];
        } else {
          c2_tmp_size[0] = 1;
          c2_tmp_data[0] = 1.0;
          c2_y_size[0] = 1;
          c2_y_size[1] = 1;
          c2_i626 = c2_y_size[0];
          c2_i628 = c2_y_size[1];
          c2_y_data[0] = (real32_T)c2_tmp_data[0];
        }

        c2_i629 = c2_threshL->size[0] * c2_threshL->size[1];
        c2_threshL->size[0] = 1;
        c2_threshL->size[1] = c2_y_size[1] + c2_uniqueVals->size[1];
        c2_emxEnsureCapacity_real32_T(chartInstance, c2_threshL, c2_i629,
          &c2_gf_emlrtRTEI);
        c2_e_loop_ub = c2_y_size[1] - 1;
        for (c2_i632 = 0; c2_i632 <= c2_e_loop_ub; c2_i632++) {
          c2_threshL->data[c2_i632] = c2_y_data[c2_i632];
        }

        c2_g_loop_ub = c2_uniqueVals->size[1] - 1;
        for (c2_i635 = 0; c2_i635 <= c2_g_loop_ub; c2_i635++) {
          c2_threshL->data[c2_i635 + c2_y_size[1]] = c2_uniqueVals->data[c2_i635];
        }
      } else {
        c2_i608 = c2_threshL->size[0] * c2_threshL->size[1];
        c2_threshL->size[0] = 1;
        c2_threshL->size[1] = c2_uniqueVals->size[1];
        c2_emxEnsureCapacity_real32_T(chartInstance, c2_threshL, c2_i608,
          &c2_af_emlrtRTEI);
        c2_i613 = c2_threshL->size[0];
        c2_i614 = c2_threshL->size[1];
        c2_b_loop_ub = c2_uniqueVals->size[0] * c2_uniqueVals->size[1] - 1;
        for (c2_i615 = 0; c2_i615 <= c2_b_loop_ub; c2_i615++) {
          c2_threshL->data[c2_i615] = c2_uniqueVals->data[c2_i615];
        }
      }

      c2_thNeeded2 = 1.0 - (real_T)c2_threshL->size[1];
      if (c2_thNeeded2 > 0.0) {
        c2_b_varargin_2 = c2_threshL->size[1];
        c2_c_varargin_2 = c2_b_varargin_2;
        c2_lenThreshOrig = (real_T)c2_c_varargin_2;
        c2_i617 = c2_thresh->size[0] * c2_thresh->size[1];
        c2_thresh->size[0] = 1;
        c2_thresh->size[1] = c2_threshL->size[1] + 1;
        c2_emxEnsureCapacity_real32_T(chartInstance, c2_thresh, c2_i617,
          &c2_cf_emlrtRTEI);
        c2_d_loop_ub = c2_threshL->size[1] - 1;
        for (c2_i623 = 0; c2_i623 <= c2_d_loop_ub; c2_i623++) {
          c2_thresh->data[c2_i623] = c2_threshL->data[c2_i623];
        }

        c2_emxInit_real_T(chartInstance, &c2_uniqueVals_d, 2, &c2_ef_emlrtRTEI);
        c2_thresh->data[c2_threshL->size[1]] = 0.0F;
        c2_i630 = c2_uniqueVals_d->size[0] * c2_uniqueVals_d->size[1];
        c2_uniqueVals_d->size[0] = 1;
        c2_uniqueVals_d->size[1] = c2_uniqueVals->size[1];
        c2_emxEnsureCapacity_real_T(chartInstance, c2_uniqueVals_d, c2_i630,
          &c2_ef_emlrtRTEI);
        c2_i631 = c2_uniqueVals_d->size[0];
        c2_i633 = c2_uniqueVals_d->size[1];
        c2_f_loop_ub = c2_uniqueVals->size[0] * c2_uniqueVals->size[1] - 1;
        for (c2_i634 = 0; c2_i634 <= c2_f_loop_ub; c2_i634++) {
          c2_uniqueVals_d->data[c2_i634] = c2_uniqueVals->data[c2_i634];
        }

        (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_uniqueVals->size[1]);
        c2_g_x = c2_uniqueVals->data[0];
        c2_h_x = c2_g_x;
        c2_h_x = muSingleScalarFloor(c2_h_x);
        c2_i_varargin_1 = c2_h_x;
        c2_i_x = c2_i_varargin_1;
        c2_j_x = c2_i_x;
        c2_k_x = c2_j_x;
        c2_l_x = c2_k_x;
        c2_m_x = c2_l_x;
        c2_n_x = c2_m_x;
        c2_threshCandidate = muSingleScalarMax(c2_n_x, 0.0F);
        c2_q = 1.0;
        c2_emxInit_real_T1(chartInstance, &c2_r11, 1, &c2_if_emlrtRTEI);
        c2_emxInit_real_T1(chartInstance, &c2_b_uniqueVals_d, 1,
                           &c2_hf_emlrtRTEI);
        while (c2_q <= 1.0) {
          c2_threshCandidate++;
          c2_threshCandidate_d = c2_threshCandidate;
          c2_i636 = c2_b_uniqueVals_d->size[0];
          c2_b_uniqueVals_d->size[0] = c2_uniqueVals_d->size[1];
          c2_emxEnsureCapacity_real_T1(chartInstance, c2_b_uniqueVals_d, c2_i636,
            &c2_hf_emlrtRTEI);
          c2_h_loop_ub = c2_uniqueVals_d->size[1] - 1;
          for (c2_i637 = 0; c2_i637 <= c2_h_loop_ub; c2_i637++) {
            c2_b_uniqueVals_d->data[c2_i637] = c2_uniqueVals_d->data[c2_i637] -
              c2_threshCandidate_d;
          }

          c2_abs(chartInstance, c2_b_uniqueVals_d, c2_r11);
          c2_d12 = c2_eps(chartInstance, c2_threshCandidate_d);
          c2_b_tmp_size[0] = c2_r11->size[0];
          c2_i_loop_ub = c2_r11->size[0] - 1;
          for (c2_i638 = 0; c2_i638 <= c2_i_loop_ub; c2_i638++) {
            c2_b_tmp_data[c2_i638] = (c2_r11->data[c2_i638] < c2_d12);
          }

          if (c2_any(chartInstance, c2_b_tmp_data, c2_b_tmp_size)) {
          } else {
            c2_thresh->data[sf_eml_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
               MAX_uint32_T, (int32_T)(c2_lenThreshOrig + 1.0), 1,
               c2_thresh->size[1]) - 1] = c2_threshCandidate;
            c2_q = 2.0;
          }
        }

        c2_emxFree_real_T(chartInstance, &c2_b_uniqueVals_d);
        c2_emxFree_real_T(chartInstance, &c2_r11);
        c2_emxFree_real_T(chartInstance, &c2_uniqueVals_d);
        c2_c_sort(chartInstance, c2_thresh);
      } else {
        c2_i616 = c2_thresh->size[0] * c2_thresh->size[1];
        c2_thresh->size[0] = 1;
        c2_thresh->size[1] = c2_threshL->size[1];
        c2_emxEnsureCapacity_real32_T(chartInstance, c2_thresh, c2_i616,
          &c2_bf_emlrtRTEI);
        c2_i618 = c2_thresh->size[0];
        c2_i619 = c2_thresh->size[1];
        c2_c_loop_ub = c2_threshL->size[0] * c2_threshL->size[1] - 1;
        for (c2_i621 = 0; c2_i621 <= c2_c_loop_ub; c2_i621++) {
          c2_thresh->data[c2_i621] = c2_threshL->data[c2_i621];
        }
      }

      c2_emxFree_real32_T(chartInstance, &c2_threshL);
    } else {
      c2_i606 = c2_thresh->size[0] * c2_thresh->size[1];
      c2_thresh->size[0] = 1;
      c2_thresh->size[1] = c2_uniqueVals->size[1];
      c2_emxEnsureCapacity_real32_T(chartInstance, c2_thresh, c2_i606,
        &c2_ye_emlrtRTEI);
      c2_i610 = c2_thresh->size[0];
      c2_i611 = c2_thresh->size[1];
      c2_loop_ub = c2_uniqueVals->size[0] * c2_uniqueVals->size[1] - 1;
      for (c2_i612 = 0; c2_i612 <= c2_loop_ub; c2_i612++) {
        c2_thresh->data[c2_i612] = c2_uniqueVals->data[c2_i612];
      }
    }
  }
}

static void c2_abs(SFc2_flightControlSystemInstanceStruct *chartInstance,
                   c2_emxArray_real_T *c2_d_x, c2_emxArray_real_T *c2_c_y)
{
  int32_T c2_nx;
  real_T c2_e_x[2];
  int32_T c2_i639;
  int32_T c2_i640;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  real_T c2_f_x;
  real_T c2_d_y;
  c2_nx = c2_d_x->size[0];
  c2_e_x[0] = (real_T)c2_d_x->size[0];
  c2_e_x[1] = 1.0;
  for (c2_i639 = 0; c2_i639 < 2; c2_i639++) {
    c2_e_x[c2_i639];
  }

  c2_i640 = c2_c_y->size[0];
  c2_c_y->size[0] = (int32_T)c2_e_x[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_c_y, c2_i640, &c2_jf_emlrtRTEI);
  c2_b = c2_nx;
  c2_b_b = c2_b;
  if (1 > c2_b_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_check_forloop_overflow_error(chartInstance, true);
  }

  for (c2_k = 0; c2_k < c2_nx; c2_k++) {
    c2_b_k = c2_k;
    c2_f_x = c2_d_x->data[c2_b_k];
    c2_d_y = muDoubleScalarAbs(c2_f_x);
    c2_c_y->data[c2_b_k] = c2_d_y;
  }
}

static real_T c2_eps(SFc2_flightControlSystemInstanceStruct *chartInstance,
                     real_T c2_d_x)
{
  real_T c2_r;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_absxk;
  real_T c2_h_x;
  real_T c2_i_x;
  boolean_T c2_b;
  boolean_T c2_b43;
  real_T c2_j_x;
  boolean_T c2_b_b;
  boolean_T c2_b44;
  boolean_T c2_c_b;
  int32_T c2_exponent;
  int32_T c2_b_exponent;
  (void)chartInstance;
  c2_e_x = c2_d_x;
  c2_f_x = c2_e_x;
  c2_g_x = c2_f_x;
  c2_absxk = muDoubleScalarAbs(c2_g_x);
  c2_h_x = c2_absxk;
  c2_i_x = c2_h_x;
  c2_b = muDoubleScalarIsInf(c2_i_x);
  c2_b43 = !c2_b;
  c2_j_x = c2_h_x;
  c2_b_b = muDoubleScalarIsNaN(c2_j_x);
  c2_b44 = !c2_b_b;
  c2_c_b = (c2_b43 && c2_b44);
  if (c2_c_b) {
    if (c2_absxk <= 2.2250738585072014E-308) {
      c2_r = 4.94065645841247E-324;
    } else {
      frexp(c2_absxk, &c2_exponent);
      c2_b_exponent = c2_exponent;
      c2_r = ldexp(1.0, c2_b_exponent - 53);
    }
  } else {
    c2_r = rtNaN;
  }

  return c2_r;
}

static void c2_sort(SFc2_flightControlSystemInstanceStruct *chartInstance,
                    c2_emxArray_real32_T *c2_d_x, c2_emxArray_real32_T *c2_e_x)
{
  int32_T c2_i641;
  int32_T c2_i642;
  int32_T c2_i643;
  int32_T c2_loop_ub;
  int32_T c2_i644;
  c2_i641 = c2_e_x->size[0] * c2_e_x->size[1];
  c2_e_x->size[0] = 1;
  c2_e_x->size[1] = c2_d_x->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_e_x, c2_i641, &c2_kf_emlrtRTEI);
  c2_i642 = c2_e_x->size[0];
  c2_i643 = c2_e_x->size[1];
  c2_loop_ub = c2_d_x->size[0] * c2_d_x->size[1] - 1;
  for (c2_i644 = 0; c2_i644 <= c2_loop_ub; c2_i644++) {
    c2_e_x->data[c2_i644] = c2_d_x->data[c2_i644];
  }

  c2_c_sort(chartInstance, c2_e_x);
}

static void c2_merge_pow2_block(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T *c2_d_x,
  int32_T c2_offset, c2_emxArray_int32_T *c2_c_idx, c2_emxArray_real32_T *c2_e_x)
{
  int32_T c2_i645;
  int32_T c2_i646;
  int32_T c2_i647;
  int32_T c2_loop_ub;
  int32_T c2_i648;
  int32_T c2_i649;
  int32_T c2_i650;
  int32_T c2_i651;
  int32_T c2_b_loop_ub;
  int32_T c2_i652;
  c2_i645 = c2_c_idx->size[0] * c2_c_idx->size[1];
  c2_c_idx->size[0] = 1;
  c2_c_idx->size[1] = c2_b_idx->size[1];
  c2_emxEnsureCapacity_int32_T1(chartInstance, c2_c_idx, c2_i645,
    &c2_lf_emlrtRTEI);
  c2_i646 = c2_c_idx->size[0];
  c2_i647 = c2_c_idx->size[1];
  c2_loop_ub = c2_b_idx->size[0] * c2_b_idx->size[1] - 1;
  for (c2_i648 = 0; c2_i648 <= c2_loop_ub; c2_i648++) {
    c2_c_idx->data[c2_i648] = c2_b_idx->data[c2_i648];
  }

  c2_i649 = c2_e_x->size[0] * c2_e_x->size[1];
  c2_e_x->size[0] = 1;
  c2_e_x->size[1] = c2_d_x->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_e_x, c2_i649, &c2_lf_emlrtRTEI);
  c2_i650 = c2_e_x->size[0];
  c2_i651 = c2_e_x->size[1];
  c2_b_loop_ub = c2_d_x->size[0] * c2_d_x->size[1] - 1;
  for (c2_i652 = 0; c2_i652 <= c2_b_loop_ub; c2_i652++) {
    c2_e_x->data[c2_i652] = c2_d_x->data[c2_i652];
  }

  c2_b_merge_pow2_block(chartInstance, c2_c_idx, c2_e_x, c2_offset);
}

static void c2_merge_block(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T *c2_d_x, int32_T c2_offset,
  int32_T c2_n, int32_T c2_preSortLevel, c2_emxArray_int32_T *c2_b_iwork,
  c2_emxArray_real32_T *c2_xwork, c2_emxArray_int32_T *c2_c_idx,
  c2_emxArray_real32_T *c2_e_x, c2_emxArray_int32_T *c2_c_iwork,
  c2_emxArray_real32_T *c2_b_xwork)
{
  int32_T c2_i653;
  int32_T c2_i654;
  int32_T c2_i655;
  int32_T c2_loop_ub;
  int32_T c2_i656;
  int32_T c2_i657;
  int32_T c2_i658;
  int32_T c2_i659;
  int32_T c2_b_loop_ub;
  int32_T c2_i660;
  int32_T c2_i661;
  int32_T c2_c_loop_ub;
  int32_T c2_i662;
  int32_T c2_i663;
  int32_T c2_d_loop_ub;
  int32_T c2_i664;
  c2_i653 = c2_c_idx->size[0] * c2_c_idx->size[1];
  c2_c_idx->size[0] = 1;
  c2_c_idx->size[1] = c2_b_idx->size[1];
  c2_emxEnsureCapacity_int32_T1(chartInstance, c2_c_idx, c2_i653,
    &c2_mf_emlrtRTEI);
  c2_i654 = c2_c_idx->size[0];
  c2_i655 = c2_c_idx->size[1];
  c2_loop_ub = c2_b_idx->size[0] * c2_b_idx->size[1] - 1;
  for (c2_i656 = 0; c2_i656 <= c2_loop_ub; c2_i656++) {
    c2_c_idx->data[c2_i656] = c2_b_idx->data[c2_i656];
  }

  c2_i657 = c2_e_x->size[0] * c2_e_x->size[1];
  c2_e_x->size[0] = 1;
  c2_e_x->size[1] = c2_d_x->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_e_x, c2_i657, &c2_mf_emlrtRTEI);
  c2_i658 = c2_e_x->size[0];
  c2_i659 = c2_e_x->size[1];
  c2_b_loop_ub = c2_d_x->size[0] * c2_d_x->size[1] - 1;
  for (c2_i660 = 0; c2_i660 <= c2_b_loop_ub; c2_i660++) {
    c2_e_x->data[c2_i660] = c2_d_x->data[c2_i660];
  }

  c2_i661 = c2_c_iwork->size[0];
  c2_c_iwork->size[0] = c2_b_iwork->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_c_iwork, c2_i661,
    &c2_mf_emlrtRTEI);
  c2_c_loop_ub = c2_b_iwork->size[0] - 1;
  for (c2_i662 = 0; c2_i662 <= c2_c_loop_ub; c2_i662++) {
    c2_c_iwork->data[c2_i662] = c2_b_iwork->data[c2_i662];
  }

  c2_i663 = c2_b_xwork->size[0];
  c2_b_xwork->size[0] = c2_xwork->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_b_xwork, c2_i663,
    &c2_mf_emlrtRTEI);
  c2_d_loop_ub = c2_xwork->size[0] - 1;
  for (c2_i664 = 0; c2_i664 <= c2_d_loop_ub; c2_i664++) {
    c2_b_xwork->data[c2_i664] = c2_xwork->data[c2_i664];
  }

  c2_c_merge_block(chartInstance, c2_c_idx, c2_e_x, c2_offset, c2_n,
                   c2_preSortLevel, c2_c_iwork, c2_b_xwork);
}

static void c2_merge(SFc2_flightControlSystemInstanceStruct *chartInstance,
                     c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T *c2_d_x,
                     int32_T c2_offset, int32_T c2_np, int32_T c2_nq,
                     c2_emxArray_int32_T *c2_b_iwork, c2_emxArray_real32_T
                     *c2_xwork, c2_emxArray_int32_T *c2_c_idx,
                     c2_emxArray_real32_T *c2_e_x, c2_emxArray_int32_T
                     *c2_c_iwork, c2_emxArray_real32_T *c2_b_xwork)
{
  int32_T c2_i665;
  int32_T c2_i666;
  int32_T c2_i667;
  int32_T c2_loop_ub;
  int32_T c2_i668;
  int32_T c2_i669;
  int32_T c2_i670;
  int32_T c2_i671;
  int32_T c2_b_loop_ub;
  int32_T c2_i672;
  int32_T c2_i673;
  int32_T c2_c_loop_ub;
  int32_T c2_i674;
  int32_T c2_i675;
  int32_T c2_d_loop_ub;
  int32_T c2_i676;
  c2_i665 = c2_c_idx->size[0] * c2_c_idx->size[1];
  c2_c_idx->size[0] = 1;
  c2_c_idx->size[1] = c2_b_idx->size[1];
  c2_emxEnsureCapacity_int32_T1(chartInstance, c2_c_idx, c2_i665,
    &c2_nf_emlrtRTEI);
  c2_i666 = c2_c_idx->size[0];
  c2_i667 = c2_c_idx->size[1];
  c2_loop_ub = c2_b_idx->size[0] * c2_b_idx->size[1] - 1;
  for (c2_i668 = 0; c2_i668 <= c2_loop_ub; c2_i668++) {
    c2_c_idx->data[c2_i668] = c2_b_idx->data[c2_i668];
  }

  c2_i669 = c2_e_x->size[0] * c2_e_x->size[1];
  c2_e_x->size[0] = 1;
  c2_e_x->size[1] = c2_d_x->size[1];
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_e_x, c2_i669, &c2_nf_emlrtRTEI);
  c2_i670 = c2_e_x->size[0];
  c2_i671 = c2_e_x->size[1];
  c2_b_loop_ub = c2_d_x->size[0] * c2_d_x->size[1] - 1;
  for (c2_i672 = 0; c2_i672 <= c2_b_loop_ub; c2_i672++) {
    c2_e_x->data[c2_i672] = c2_d_x->data[c2_i672];
  }

  c2_i673 = c2_c_iwork->size[0];
  c2_c_iwork->size[0] = c2_b_iwork->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_c_iwork, c2_i673,
    &c2_nf_emlrtRTEI);
  c2_c_loop_ub = c2_b_iwork->size[0] - 1;
  for (c2_i674 = 0; c2_i674 <= c2_c_loop_ub; c2_i674++) {
    c2_c_iwork->data[c2_i674] = c2_b_iwork->data[c2_i674];
  }

  c2_i675 = c2_b_xwork->size[0];
  c2_b_xwork->size[0] = c2_xwork->size[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_b_xwork, c2_i675,
    &c2_nf_emlrtRTEI);
  c2_d_loop_ub = c2_xwork->size[0] - 1;
  for (c2_i676 = 0; c2_i676 <= c2_d_loop_ub; c2_i676++) {
    c2_b_xwork->data[c2_i676] = c2_xwork->data[c2_i676];
  }

  c2_c_merge(chartInstance, c2_c_idx, c2_e_x, c2_offset, c2_np, c2_nq,
             c2_c_iwork, c2_b_xwork);
}

static void c2_toLogicalCheck(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real_T c2_d_x[25])
{
  (void)chartInstance;
  (void)c2_d_x;
}

static void c2_chcenters(SFc2_flightControlSystemInstanceStruct *chartInstance,
  creal_T c2_h_varargin_1[19200], c2_emxArray_real_T *c2_centers,
  c2_emxArray_real_T *c2_metric)
{
  boolean_T c2_b45;
  int32_T c2_i677;
  int32_T c2_i678;
  int32_T c2_i679;
  int32_T c2_i680;
  int32_T c2_i681;
  int32_T c2_i682;
  int32_T c2_k;
  real_T c2_c_accumMatrixRe;
  int32_T c2_b_k;
  int32_T c2_i683;
  creal_T c2_d_x;
  real_T c2_x1;
  int32_T c2_i684;
  boolean_T c2_b_bw[19200];
  real_T c2_x2;
  real_T c2_c_y;
  boolean_T c2_flat;
  int32_T c2_c_k;
  real_T c2_d_k;
  int32_T c2_i685;
  int32_T c2_i686;
  boolean_T c2_p;
  int32_T c2_e_k;
  real_T c2_f_k;
  real_T c2_e_x;
  boolean_T c2_b46;
  real_T c2_f_x;
  boolean_T c2_b;
  boolean_T c2_b_p;
  const mxArray *c2_d_y = NULL;
  static char_T c2_cv42[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'r',
    'e', 'c', 'o', 'n', 's', 't', 'r', 'u', 'c', 't', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  boolean_T c2_c_p;
  const mxArray *c2_e_y = NULL;
  int32_T c2_g_k;
  const mxArray *c2_f_y = NULL;
  static char_T c2_cv43[5] = { 'i', 'n', 'p', 'u', 't' };

  real_T c2_h_k;
  real_T c2_g_x;
  boolean_T c2_b47;
  real_T c2_h_x;
  boolean_T c2_b_b;
  boolean_T c2_d_p;
  const mxArray *c2_g_y = NULL;
  static char_T c2_cv44[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'r',
    'e', 'c', 'o', 'n', 's', 't', 'r', 'u', 'c', 't', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  int32_T c2_i687;
  const mxArray *c2_h_y = NULL;
  int32_T c2_i688;
  const mxArray *c2_i_y = NULL;
  static char_T c2_cv45[5] = { 'i', 'n', 'p', 'u', 't' };

  int32_T c2_i689;
  real_T c2_imSizeT[2];
  boolean_T c2_e_p;
  int32_T c2_i_k;
  real_T c2_j_k;
  real_T c2_i_x;
  boolean_T c2_b48;
  real_T c2_j_x;
  boolean_T c2_c_b;
  boolean_T c2_f_p;
  const mxArray *c2_j_y = NULL;
  static char_T c2_cv46[35] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'm', 'r',
    'e', 'g', 'i', 'o', 'n', 'a', 'l', 'm', 'a', 'x', ':', 'e', 'x', 'p', 'e',
    'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  int32_T c2_k_k;
  const mxArray *c2_k_y = NULL;
  int32_T c2_i690;
  real_T c2_l_k;
  const mxArray *c2_l_y = NULL;
  real_T c2_k_x;
  static char_T c2_cv47[18] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '1', ',', ' ', 'I', ',' };

  int32_T c2_i691;
  boolean_T c2_conn[9];
  boolean_T c2_d_b;
  int32_T c2_i692;
  const mxArray *c2_m_y = NULL;
  static char_T c2_cv48[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  c2_emxArray_sBO2RC5RVZVTbundPSRqHn *c2_s;
  real_T c2_connSizeT[2];
  const mxArray *c2_n_y = NULL;
  int32_T c2_i693;
  real_T c2_d13;
  int32_T c2_i694;
  int32_T c2_b_idx;
  real_T c2_d14;
  real_T c2_c_idx;
  int32_T c2_i695;
  int32_T c2_i696;
  int32_T c2_tmp_size[1];
  int32_T c2_d_idx;
  int32_T c2_i697;
  c2_emxArray_real_T *c2_l_x;
  c2_emxArray_real_T *c2_m_x;
  int32_T c2_tmp_data[2];
  int32_T c2_i698;
  int32_T c2_iv10[2];
  int32_T c2_iv11[2];
  int32_T c2_i699;
  int32_T c2_i700;
  real_T c2_n_x;
  int32_T c2_i701;
  boolean_T c2_b49;
  boolean_T c2_e_b;
  c2_emxArray_real_T *c2_ndx;
  real_T c2_o_x;
  int32_T c2_i702;
  boolean_T c2_f_b;
  int32_T c2_i703;
  int32_T c2_i704;
  int32_T c2_loop_ub;
  int32_T c2_i705;
  int32_T c2_i706;
  int32_T c2_i707;
  int32_T c2_b_loop_ub;
  c2_emxArray_real_T *c2_varargin_2;
  int32_T c2_i708;
  int32_T c2_i709;
  int32_T c2_e_idx;
  int32_T c2_i710;
  int32_T c2_f_idx;
  int32_T c2_g_idx;
  real_T c2_d15;
  int32_T c2_c_loop_ub;
  int32_T c2_n;
  int32_T c2_i711;
  boolean_T c2_g_p;
  c2_emxArray_int32_T *c2_h_idx;
  int32_T c2_p_x;
  c2_emxArray_real_T *c2_b_ndx;
  int32_T c2_q_x;
  int32_T c2_i712;
  const mxArray *c2_o_y = NULL;
  int32_T c2_i_idx;
  int32_T c2_d_loop_ub;
  const mxArray *c2_p_y = NULL;
  int32_T c2_nrowx;
  int32_T c2_i713;
  int32_T c2_nrows;
  int32_T c2_j;
  const mxArray *c2_q_y = NULL;
  int32_T c2_b_j;
  const mxArray *c2_r_y = NULL;
  int32_T c2_l_a;
  const mxArray *c2_s_y = NULL;
  boolean_T c2_b50;
  int32_T c2_g_b;
  const mxArray *c2_t_y = NULL;
  int32_T c2_m_a;
  int32_T c2_i714;
  int32_T c2_h_b;
  int32_T c2_i715;
  int32_T c2_i716;
  boolean_T c2_overflow;
  int32_T c2_i717;
  boolean_T c2_h_p;
  int32_T c2_i718;
  int32_T c2_i;
  boolean_T c2_i_p;
  int32_T c2_m_k;
  int32_T c2_i719;
  int32_T c2_e_loop_ub;
  int32_T c2_i720;
  real_T c2_n_k;
  real_T c2_b_x1;
  int32_T c2_i721;
  real_T c2_b_x2;
  int32_T c2_i722;
  boolean_T c2_j_p;
  int32_T c2_f_loop_ub;
  const mxArray *c2_u_y = NULL;
  int32_T c2_i723;
  c2_emxArray_real_T *c2_b_varargin_2;
  const mxArray *c2_v_y = NULL;
  int32_T c2_i724;
  int32_T c2_i725;
  int32_T c2_g_loop_ub;
  int32_T c2_i726;
  int32_T c2_i727;
  int32_T c2_i728;
  int32_T c2_h_loop_ub;
  const mxArray *c2_w_y = NULL;
  int32_T c2_i729;
  const mxArray *c2_x_y = NULL;
  int32_T c2_i730;
  int32_T c2_i_loop_ub;
  int32_T c2_i731;
  c2_emxArray_int32_T *c2_i_b;
  int32_T c2_i732;
  int32_T c2_j_loop_ub;
  int32_T c2_i733;
  int32_T c2_i734;
  int32_T c2_k_loop_ub;
  int32_T c2_i735;
  int32_T c2_i736;
  int32_T c2_l_loop_ub;
  int32_T c2_i737;
  int32_T c2_i738;
  int32_T c2_m_loop_ub;
  int32_T c2_i739;
  int32_T c2_i740;
  int32_T c2_n_loop_ub;
  int32_T c2_i741;
  int32_T c2_i742;
  int32_T c2_i743;
  int32_T c2_i744;
  int32_T c2_o_loop_ub;
  int32_T c2_i745;
  c2_emxArray_real_T *c2_r_x;
  int32_T c2_i746;
  int32_T c2_i747;
  int32_T c2_i748;
  int32_T c2_p_loop_ub;
  int32_T c2_i749;
  c2_emxArray_real_T *c2_b_sortIdx;
  c2_emxArray_int32_T *c2_iidx;
  int32_T c2_i750;
  int32_T c2_i751;
  int32_T c2_i752;
  int32_T c2_q_loop_ub;
  int32_T c2_i753;
  int32_T c2_i754;
  int32_T c2_i755;
  int32_T c2_i756;
  int32_T c2_r_loop_ub;
  int32_T c2_i757;
  int32_T c2_i758;
  int32_T c2_b_centers;
  int32_T c2_i759;
  int32_T c2_i760;
  int32_T c2_s_loop_ub;
  int32_T c2_i761;
  c2_emxArray_real_T *c2_c_centers;
  int32_T c2_c_sortIdx[1];
  int32_T c2_i762;
  int32_T c2_i763;
  int32_T c2_t_loop_ub;
  int32_T c2_i764;
  int32_T c2_i765;
  int32_T c2_i766;
  int32_T c2_i767;
  int32_T c2_u_loop_ub;
  int32_T c2_i768;
  boolean_T guard1 = false;
  boolean_T exitg1;
  c2_b45 = false;
  c2_i677 = c2_centers->size[0] * c2_centers->size[1];
  c2_centers->size[0] = 0;
  c2_centers->size[1] = 0;
  c2_i678 = c2_centers->size[0];
  c2_i679 = c2_centers->size[1];
  c2_i680 = c2_metric->size[0] * c2_metric->size[1];
  c2_metric->size[0] = 0;
  c2_metric->size[1] = 0;
  c2_i681 = c2_metric->size[0];
  c2_i682 = c2_metric->size[1];
  for (c2_k = 0; c2_k < 19200; c2_k++) {
    c2_b_k = c2_k;
    c2_d_x = c2_h_varargin_1[c2_b_k];
    c2_x1 = c2_d_x.re;
    c2_x2 = c2_d_x.im;
    c2_c_y = muDoubleScalarHypot(c2_x1, c2_x2);
    chartInstance->c2_accumMatrixRe[c2_b_k] = c2_c_y;
  }

  c2_c_accumMatrixRe = chartInstance->c2_accumMatrixRe[0];
  for (c2_i683 = 0; c2_i683 < 19200; c2_i683++) {
    c2_b_bw[c2_i683] = (chartInstance->c2_accumMatrixRe[c2_i683] ==
                        c2_c_accumMatrixRe);
  }

  for (c2_i684 = 0; c2_i684 < 19200; c2_i684++) {
    c2_b_bw[c2_i684];
  }

  c2_flat = true;
  c2_c_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_c_k < 19200)) {
    c2_d_k = 1.0 + (real_T)c2_c_k;
    if (!c2_b_bw[(int32_T)c2_d_k - 1]) {
      c2_flat = false;
      exitg1 = true;
    } else {
      c2_c_k++;
    }
  }

  if (c2_flat) {
  } else {
    for (c2_i685 = 0; c2_i685 < 19200; c2_i685++) {
      chartInstance->c2_b_accumMatrixRe[c2_i685] =
        chartInstance->c2_accumMatrixRe[c2_i685];
    }

    c2_medfilt2(chartInstance, chartInstance->c2_b_accumMatrixRe,
                chartInstance->c2_Hd);
    for (c2_i686 = 0; c2_i686 < 19200; c2_i686++) {
      chartInstance->c2_marker[c2_i686] = chartInstance->c2_Hd[c2_i686] - 0.15;
    }

    c2_p = true;
    c2_e_k = 0;
    exitg1 = false;
    while ((!exitg1) && (c2_e_k < 19200)) {
      c2_f_k = 1.0 + (real_T)c2_e_k;
      c2_e_x = chartInstance->c2_marker[(int32_T)c2_f_k - 1];
      c2_f_x = c2_e_x;
      c2_b = muDoubleScalarIsNaN(c2_f_x);
      c2_b_p = !c2_b;
      if (c2_b_p) {
        c2_e_k++;
      } else {
        c2_p = false;
        exitg1 = true;
      }
    }

    if (c2_p) {
      c2_b46 = true;
    } else {
      c2_b46 = false;
    }

    if (c2_b46) {
    } else {
      c2_d_y = NULL;
      sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv42, 10, 0U, 1U, 0U, 2, 1,
        35), false);
      c2_e_y = NULL;
      sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv8, 10, 0U, 1U, 0U, 2, 1, 46),
                    false);
      c2_f_y = NULL;
      sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv43, 10, 0U, 1U, 0U, 2, 1, 5),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_d_y,
                        14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "message", 1U, 2U, 14, c2_e_y, 14, c2_f_y)));
    }

    c2_c_p = true;
    c2_g_k = 0;
    exitg1 = false;
    while ((!exitg1) && (c2_g_k < 19200)) {
      c2_h_k = 1.0 + (real_T)c2_g_k;
      c2_g_x = chartInstance->c2_Hd[(int32_T)c2_h_k - 1];
      c2_h_x = c2_g_x;
      c2_b_b = muDoubleScalarIsNaN(c2_h_x);
      c2_d_p = !c2_b_b;
      if (c2_d_p) {
        c2_g_k++;
      } else {
        c2_c_p = false;
        exitg1 = true;
      }
    }

    if (c2_c_p) {
      c2_b47 = true;
    } else {
      c2_b47 = false;
    }

    if (c2_b47) {
    } else {
      c2_g_y = NULL;
      sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_cv44, 10, 0U, 1U, 0U, 2, 1,
        35), false);
      c2_h_y = NULL;
      sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv8, 10, 0U, 1U, 0U, 2, 1, 46),
                    false);
      c2_i_y = NULL;
      sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_cv45, 10, 0U, 1U, 0U, 2, 1, 5),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_g_y,
                        14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "message", 1U, 2U, 14, c2_h_y, 14, c2_i_y)));
    }

    for (c2_i687 = 0; c2_i687 < 19200; c2_i687++) {
      chartInstance->c2_mask[c2_i687] = chartInstance->c2_Hd[c2_i687];
    }

    for (c2_i688 = 0; c2_i688 < 19200; c2_i688++) {
      chartInstance->c2_Hd[c2_i688] = chartInstance->c2_marker[c2_i688];
    }

    for (c2_i689 = 0; c2_i689 < 2; c2_i689++) {
      c2_imSizeT[c2_i689] = 120.0 + 40.0 * (real_T)c2_i689;
    }

    ippreconstruct_real64(chartInstance->c2_Hd, chartInstance->c2_mask,
                          c2_imSizeT, 2.0);
    c2_e_p = true;
    c2_i_k = 0;
    exitg1 = false;
    while ((!exitg1) && (c2_i_k < 19200)) {
      c2_j_k = 1.0 + (real_T)c2_i_k;
      c2_i_x = chartInstance->c2_Hd[(int32_T)c2_j_k - 1];
      c2_j_x = c2_i_x;
      c2_c_b = muDoubleScalarIsNaN(c2_j_x);
      c2_f_p = !c2_c_b;
      if (c2_f_p) {
        c2_i_k++;
      } else {
        c2_e_p = false;
        exitg1 = true;
      }
    }

    if (c2_e_p) {
      c2_b48 = true;
    } else {
      c2_b48 = false;
    }

    if (c2_b48) {
    } else {
      c2_j_y = NULL;
      sf_mex_assign(&c2_j_y, sf_mex_create("y", c2_cv46, 10, 0U, 1U, 0U, 2, 1,
        35), false);
      c2_k_y = NULL;
      sf_mex_assign(&c2_k_y, sf_mex_create("y", c2_cv8, 10, 0U, 1U, 0U, 2, 1, 46),
                    false);
      c2_l_y = NULL;
      sf_mex_assign(&c2_l_y, sf_mex_create("y", c2_cv47, 10, 0U, 1U, 0U, 2, 1,
        18), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_j_y,
                        14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "message", 1U, 2U, 14, c2_k_y, 14, c2_l_y)));
    }

    for (c2_k_k = 0; c2_k_k < 19200; c2_k_k++) {
      c2_l_k = 1.0 + (real_T)c2_k_k;
      c2_k_x = chartInstance->c2_Hd[(int32_T)c2_l_k - 1];
      c2_d_b = muDoubleScalarIsNaN(c2_k_x);
      if (c2_d_b) {
        c2_m_y = NULL;
        sf_mex_assign(&c2_m_y, sf_mex_create("y", c2_cv48, 10, 0U, 1U, 0U, 2, 1,
          19), false);
        c2_n_y = NULL;
        sf_mex_assign(&c2_n_y, sf_mex_create("y", c2_cv48, 10, 0U, 1U, 0U, 2, 1,
          19), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                          c2_m_y, 14, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "getString", 1U, 1U, 14,
                           sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 1U, 14, c2_n_y)));
      }
    }

    for (c2_i690 = 0; c2_i690 < 9; c2_i690++) {
      c2_conn[c2_i690] = true;
    }

    for (c2_i691 = 0; c2_i691 < 2; c2_i691++) {
      c2_imSizeT[c2_i691] = 120.0 + 40.0 * (real_T)c2_i691;
    }

    for (c2_i692 = 0; c2_i692 < 2; c2_i692++) {
      c2_connSizeT[c2_i692] = 3.0;
    }

    c2_emxInit_sBO2RC5RVZVTbundPSRqHnH(chartInstance, &c2_s, 1, &c2_eg_emlrtRTEI);
    imregionalmax_real64(chartInstance->c2_Hd, c2_b_bw, 2.0, c2_imSizeT, c2_conn,
                         2.0, c2_connSizeT);
    c2_regionprops(chartInstance, c2_b_bw, chartInstance->c2_accumMatrixRe, c2_s);
    if (c2_s->size[0] != 0) {
      c2_i693 = c2_centers->size[0] * c2_centers->size[1];
      c2_centers->size[0] = c2_s->size[0];
      c2_centers->size[1] = 2;
      c2_emxEnsureCapacity_real_T(chartInstance, c2_centers, c2_i693,
        &c2_of_emlrtRTEI);
      c2_d13 = (real_T)c2_s->size[0];
      c2_i694 = (int32_T)c2_d13 - 1;
      for (c2_b_idx = 0; c2_b_idx <= c2_i694; c2_b_idx++) {
        c2_c_idx = 1.0 + (real_T)c2_b_idx;
        c2_i696 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_c_idx, 1,
          c2_centers->size[0]);
        c2_tmp_size[0] = 2;
        for (c2_i697 = 0; c2_i697 < 2; c2_i697++) {
          c2_tmp_data[c2_i697] = c2_i697;
        }

        if (!c2_b45) {
          for (c2_i698 = 0; c2_i698 < 2; c2_i698++) {
            c2_iv10[c2_i698] = 1 + c2_i698;
          }

          for (c2_i700 = 0; c2_i700 < 2; c2_i700++) {
            c2_iv11[c2_i700] = 1 + c2_i700;
          }

          c2_b45 = true;
        }

        _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c2_iv10, 2, c2_iv11, 2);
        c2_i699 = c2_i696 - 1;
        for (c2_i701 = 0; c2_i701 < 2; c2_i701++) {
          c2_centers->data[c2_i699 + c2_centers->size[0] * c2_tmp_data[c2_i701]]
            = c2_s->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_c_idx, 1,
            c2_s->size[0]) - 1].WeightedCentroid[c2_i701];
        }
      }

      c2_d14 = (real_T)c2_centers->size[0];
      c2_i695 = (int32_T)((1.0 + (-1.0 - c2_d14)) / -1.0);
      _SFD_FOR_LOOP_VECTOR_CHECK(c2_d14, -1.0, 1.0, mxDOUBLE_CLASS, c2_i695);
      c2_d_idx = 0;
      c2_emxInit_real_T(chartInstance, &c2_l_x, 2, &c2_rf_emlrtRTEI);
      c2_emxInit_real_T(chartInstance, &c2_m_x, 2, &c2_tf_emlrtRTEI);
      while (c2_d_idx <= c2_i695 - 1) {
        c2_c_idx = c2_d14 + -(real_T)c2_d_idx;
        c2_n_x = c2_centers->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           (int32_T)c2_c_idx, 1, c2_centers->size[0]) - 1];
        c2_e_b = muDoubleScalarIsNaN(c2_n_x);
        guard1 = false;
        if (c2_e_b) {
          guard1 = true;
        } else {
          c2_o_x = c2_centers->data[(sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, (int32_T)c2_c_idx, 1, c2_centers->size[0]) +
            c2_centers->size[0]) - 1];
          c2_f_b = muDoubleScalarIsNaN(c2_o_x);
          if (c2_f_b) {
            guard1 = true;
          }
        }

        if (guard1) {
          c2_i703 = c2_l_x->size[0] * c2_l_x->size[1];
          c2_l_x->size[0] = c2_centers->size[0];
          c2_l_x->size[1] = c2_centers->size[1];
          c2_emxEnsureCapacity_real_T(chartInstance, c2_l_x, c2_i703,
            &c2_rf_emlrtRTEI);
          c2_i705 = c2_l_x->size[0];
          c2_i707 = c2_l_x->size[1];
          c2_b_loop_ub = c2_centers->size[0] * c2_centers->size[1] - 1;
          for (c2_i708 = 0; c2_i708 <= c2_b_loop_ub; c2_i708++) {
            c2_l_x->data[c2_i708] = c2_centers->data[c2_i708];
          }

          c2_e_idx = (int32_T)c2_c_idx;
          c2_f_idx = c2_e_idx;
          c2_g_idx = c2_f_idx;
          c2_d15 = (real_T)c2_l_x->size[0];
          c2_n = (int32_T)c2_d15;
          c2_g_p = true;
          if (c2_g_idx > c2_n) {
            c2_g_p = false;
          } else {
            c2_p_x = c2_g_idx;
            c2_q_x = c2_p_x;
            if (c2_g_idx != c2_q_x) {
              c2_g_p = false;
            }
          }

          if (c2_g_p) {
          } else {
            c2_o_y = NULL;
            sf_mex_assign(&c2_o_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2,
              1, 25), false);
            c2_p_y = NULL;
            sf_mex_assign(&c2_p_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2,
              1, 25), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                              c2_o_y, 14, sf_mex_call_debug
                              (sfGlobalDebugInstanceStruct, "getString", 1U, 1U,
                               14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
              "message", 1U, 1U, 14, c2_p_y)));
          }

          c2_i_idx = c2_e_idx;
          c2_nrowx = c2_l_x->size[0];
          c2_nrows = c2_nrowx - 1;
          for (c2_j = 0; c2_j < 2; c2_j++) {
            c2_b_j = c2_j;
            c2_l_a = c2_i_idx;
            c2_g_b = c2_nrows;
            c2_m_a = c2_l_a;
            c2_h_b = c2_g_b;
            if (c2_m_a > c2_h_b) {
              c2_overflow = false;
            } else {
              c2_overflow = (c2_h_b > 2147483646);
            }

            if (c2_overflow) {
              c2_check_forloop_overflow_error(chartInstance, true);
            }

            for (c2_i = c2_i_idx; c2_i <= c2_nrows; c2_i++) {
              c2_l_x->data[(c2_i + c2_l_x->size[0] * c2_b_j) - 1] = c2_l_x->
                data[c2_i + c2_l_x->size[0] * c2_b_j];
            }
          }

          if (c2_nrows <= c2_nrowx) {
          } else {
            c2_r_y = NULL;
            sf_mex_assign(&c2_r_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2,
              1, 30), false);
            c2_t_y = NULL;
            sf_mex_assign(&c2_t_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2,
              1, 30), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                              c2_r_y, 14, sf_mex_call_debug
                              (sfGlobalDebugInstanceStruct, "getString", 1U, 1U,
                               14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
              "message", 1U, 1U, 14, c2_t_y)));
          }

          c2_b50 = (1 > c2_nrows);
          if (c2_b50) {
            c2_i714 = -1;
          } else {
            c2_i714 = c2_nrows - 1;
          }

          c2_i716 = c2_m_x->size[0] * c2_m_x->size[1];
          c2_m_x->size[0] = c2_i714 + 1;
          c2_m_x->size[1] = 2;
          c2_emxEnsureCapacity_real_T(chartInstance, c2_m_x, c2_i716,
            &c2_tf_emlrtRTEI);
          for (c2_i718 = 0; c2_i718 < 2; c2_i718++) {
            c2_e_loop_ub = c2_i714;
            for (c2_i720 = 0; c2_i720 <= c2_e_loop_ub; c2_i720++) {
              c2_m_x->data[c2_i720 + c2_m_x->size[0] * c2_i718] = c2_l_x->
                data[c2_i720 + c2_l_x->size[0] * c2_i718];
            }
          }

          c2_i719 = c2_l_x->size[0] * c2_l_x->size[1];
          c2_l_x->size[0] = c2_m_x->size[0];
          c2_l_x->size[1] = 2;
          c2_emxEnsureCapacity_real_T(chartInstance, c2_l_x, c2_i719,
            &c2_uf_emlrtRTEI);
          c2_i721 = c2_l_x->size[0];
          c2_i722 = c2_l_x->size[1];
          c2_f_loop_ub = c2_m_x->size[0] * c2_m_x->size[1] - 1;
          for (c2_i723 = 0; c2_i723 <= c2_f_loop_ub; c2_i723++) {
            c2_l_x->data[c2_i723] = c2_m_x->data[c2_i723];
          }

          c2_i725 = c2_centers->size[0] * c2_centers->size[1];
          c2_centers->size[0] = c2_l_x->size[0];
          c2_centers->size[1] = 2;
          c2_emxEnsureCapacity_real_T(chartInstance, c2_centers, c2_i725,
            &c2_rf_emlrtRTEI);
          c2_i727 = c2_centers->size[0];
          c2_i728 = c2_centers->size[1];
          c2_h_loop_ub = c2_l_x->size[0] * c2_l_x->size[1] - 1;
          for (c2_i729 = 0; c2_i729 <= c2_h_loop_ub; c2_i729++) {
            c2_centers->data[c2_i729] = c2_l_x->data[c2_i729];
          }
        }

        c2_d_idx++;
      }

      c2_emxFree_real_T(chartInstance, &c2_m_x);
      c2_emxFree_real_T(chartInstance, &c2_l_x);
      c2_b49 = (c2_centers->size[0] == 0);
      if (!c2_b49) {
        c2_emxInit_real_T1(chartInstance, &c2_ndx, 1, &c2_fg_emlrtRTEI);
        c2_i702 = c2_centers->size[0] - 1;
        c2_i704 = c2_ndx->size[0];
        c2_ndx->size[0] = c2_i702 + 1;
        c2_emxEnsureCapacity_real_T1(chartInstance, c2_ndx, c2_i704,
          &c2_qf_emlrtRTEI);
        c2_loop_ub = c2_i702;
        for (c2_i706 = 0; c2_i706 <= c2_loop_ub; c2_i706++) {
          c2_ndx->data[c2_i706] = c2_centers->data[c2_i706 + c2_centers->size[0]];
        }

        c2_emxInit_real_T1(chartInstance, &c2_varargin_2, 1, &c2_sf_emlrtRTEI);
        c2_b_round(chartInstance, c2_ndx);
        c2_i709 = c2_centers->size[0] - 1;
        c2_i710 = c2_varargin_2->size[0];
        c2_varargin_2->size[0] = c2_i709 + 1;
        c2_emxEnsureCapacity_real_T1(chartInstance, c2_varargin_2, c2_i710,
          &c2_sf_emlrtRTEI);
        c2_c_loop_ub = c2_i709;
        for (c2_i711 = 0; c2_i711 <= c2_c_loop_ub; c2_i711++) {
          c2_varargin_2->data[c2_i711] = c2_centers->data[c2_i711];
        }

        c2_emxInit_int32_T(chartInstance, &c2_h_idx, 1, &c2_rb_emlrtRTEI);
        c2_emxInit_real_T1(chartInstance, &c2_b_ndx, 1, &c2_gb_emlrtRTEI);
        c2_b_round(chartInstance, c2_varargin_2);
        c2_i712 = c2_b_ndx->size[0];
        c2_b_ndx->size[0] = c2_ndx->size[0];
        c2_emxEnsureCapacity_real_T1(chartInstance, c2_b_ndx, c2_i712,
          &c2_gb_emlrtRTEI);
        c2_d_loop_ub = c2_ndx->size[0] - 1;
        for (c2_i713 = 0; c2_i713 <= c2_d_loop_ub; c2_i713++) {
          c2_b_ndx->data[c2_i713] = c2_ndx->data[c2_i713];
        }

        if (c2_allinrange(chartInstance, c2_b_ndx, 1.0, 120)) {
        } else {
          c2_q_y = NULL;
          sf_mex_assign(&c2_q_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1,
            30), false);
          c2_s_y = NULL;
          sf_mex_assign(&c2_s_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1,
            30), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                            c2_q_y, 14, sf_mex_call_debug
                            (sfGlobalDebugInstanceStruct, "getString", 1U, 1U,
                             14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
            "message", 1U, 1U, 14, c2_s_y)));
        }

        c2_emxFree_real_T(chartInstance, &c2_b_ndx);
        c2_imSizeT[0] = (real_T)c2_ndx->size[0];
        c2_imSizeT[1] = 1.0;
        c2_connSizeT[0] = (real_T)c2_varargin_2->size[0];
        c2_connSizeT[1] = 1.0;
        for (c2_i715 = 0; c2_i715 < 2; c2_i715++) {
          c2_imSizeT[c2_i715];
        }

        for (c2_i717 = 0; c2_i717 < 2; c2_i717++) {
          c2_connSizeT[c2_i717];
        }

        c2_h_p = false;
        c2_i_p = true;
        c2_m_k = 0;
        exitg1 = false;
        while ((!exitg1) && (c2_m_k < 2)) {
          c2_n_k = 1.0 + (real_T)c2_m_k;
          c2_b_x1 = c2_imSizeT[(int32_T)c2_n_k - 1];
          c2_b_x2 = c2_connSizeT[(int32_T)c2_n_k - 1];
          c2_j_p = (c2_b_x1 == c2_b_x2);
          if (!c2_j_p) {
            c2_i_p = false;
            exitg1 = true;
          } else {
            c2_m_k++;
          }
        }

        if (!c2_i_p) {
        } else {
          c2_h_p = true;
        }

        if (c2_h_p) {
        } else {
          c2_u_y = NULL;
          sf_mex_assign(&c2_u_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1,
            34), false);
          c2_v_y = NULL;
          sf_mex_assign(&c2_v_y, sf_mex_create("y", c2_cv3, 10, 0U, 1U, 0U, 2, 1,
            34), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                            c2_u_y, 14, sf_mex_call_debug
                            (sfGlobalDebugInstanceStruct, "getString", 1U, 1U,
                             14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
            "message", 1U, 1U, 14, c2_v_y)));
        }

        c2_emxInit_real_T1(chartInstance, &c2_b_varargin_2, 1, &c2_gb_emlrtRTEI);
        c2_i724 = c2_b_varargin_2->size[0];
        c2_b_varargin_2->size[0] = c2_varargin_2->size[0];
        c2_emxEnsureCapacity_real_T1(chartInstance, c2_b_varargin_2, c2_i724,
          &c2_gb_emlrtRTEI);
        c2_g_loop_ub = c2_varargin_2->size[0] - 1;
        for (c2_i726 = 0; c2_i726 <= c2_g_loop_ub; c2_i726++) {
          c2_b_varargin_2->data[c2_i726] = c2_varargin_2->data[c2_i726];
        }

        if (c2_allinrange(chartInstance, c2_b_varargin_2, 1.0, 160)) {
        } else {
          c2_w_y = NULL;
          sf_mex_assign(&c2_w_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1,
            30), false);
          c2_x_y = NULL;
          sf_mex_assign(&c2_x_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1,
            30), false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                            c2_w_y, 14, sf_mex_call_debug
                            (sfGlobalDebugInstanceStruct, "getString", 1U, 1U,
                             14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
            "message", 1U, 1U, 14, c2_x_y)));
        }

        c2_emxFree_real_T(chartInstance, &c2_b_varargin_2);
        c2_i730 = c2_h_idx->size[0];
        c2_h_idx->size[0] = c2_ndx->size[0];
        c2_emxEnsureCapacity_int32_T(chartInstance, c2_h_idx, c2_i730,
          &c2_hb_emlrtRTEI);
        c2_i_loop_ub = c2_ndx->size[0] - 1;
        for (c2_i731 = 0; c2_i731 <= c2_i_loop_ub; c2_i731++) {
          c2_h_idx->data[c2_i731] = (int32_T)c2_ndx->data[c2_i731];
        }

        c2_emxInit_int32_T(chartInstance, &c2_i_b, 1, &c2_ib_emlrtRTEI);
        c2_i732 = c2_i_b->size[0];
        c2_i_b->size[0] = c2_varargin_2->size[0];
        c2_emxEnsureCapacity_int32_T(chartInstance, c2_i_b, c2_i732,
          &c2_ib_emlrtRTEI);
        c2_j_loop_ub = c2_varargin_2->size[0] - 1;
        for (c2_i733 = 0; c2_i733 <= c2_j_loop_ub; c2_i733++) {
          c2_i_b->data[c2_i733] = (int32_T)c2_varargin_2->data[c2_i733] - 1;
        }

        c2_i734 = c2_i_b->size[0];
        c2_i_b->size[0];
        c2_emxEnsureCapacity_int32_T(chartInstance, c2_i_b, c2_i734,
          &c2_jb_emlrtRTEI);
        c2_k_loop_ub = c2_i_b->size[0] - 1;
        for (c2_i735 = 0; c2_i735 <= c2_k_loop_ub; c2_i735++) {
          c2_i_b->data[c2_i735] *= 120;
        }

        c2_i736 = c2_h_idx->size[0];
        c2_h_idx->size[0];
        c2_emxEnsureCapacity_int32_T(chartInstance, c2_h_idx, c2_i736,
          &c2_kb_emlrtRTEI);
        c2_l_loop_ub = c2_h_idx->size[0] - 1;
        for (c2_i737 = 0; c2_i737 <= c2_l_loop_ub; c2_i737++) {
          c2_h_idx->data[c2_i737] += c2_i_b->data[c2_i737];
        }

        c2_emxFree_int32_T(chartInstance, &c2_i_b);
        c2_i738 = c2_ndx->size[0];
        c2_ndx->size[0] = c2_h_idx->size[0];
        c2_emxEnsureCapacity_real_T1(chartInstance, c2_ndx, c2_i738,
          &c2_lb_emlrtRTEI);
        c2_m_loop_ub = c2_h_idx->size[0] - 1;
        for (c2_i739 = 0; c2_i739 <= c2_m_loop_ub; c2_i739++) {
          c2_ndx->data[c2_i739] = (real_T)c2_h_idx->data[c2_i739];
        }

        c2_emxFree_int32_T(chartInstance, &c2_h_idx);
        c2_i740 = c2_varargin_2->size[0];
        c2_varargin_2->size[0] = c2_ndx->size[0];
        c2_emxEnsureCapacity_real_T1(chartInstance, c2_varargin_2, c2_i740,
          &c2_vf_emlrtRTEI);
        c2_n_loop_ub = c2_ndx->size[0] - 1;
        for (c2_i741 = 0; c2_i741 <= c2_n_loop_ub; c2_i741++) {
          c2_varargin_2->data[c2_i741] = chartInstance->
            c2_Hd[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_ndx->
            data[c2_i741], 1, 19200) - 1];
        }

        c2_emxFree_real_T(chartInstance, &c2_ndx);
        c2_i742 = c2_metric->size[0] * c2_metric->size[1];
        c2_metric->size[0] = c2_varargin_2->size[0];
        c2_metric->size[1] = 1;
        c2_emxEnsureCapacity_real_T(chartInstance, c2_metric, c2_i742,
          &c2_wf_emlrtRTEI);
        c2_i743 = c2_metric->size[0];
        c2_i744 = c2_metric->size[1];
        c2_o_loop_ub = c2_varargin_2->size[0] - 1;
        for (c2_i745 = 0; c2_i745 <= c2_o_loop_ub; c2_i745++) {
          c2_metric->data[c2_i745] = c2_varargin_2->data[c2_i745];
        }

        c2_emxFree_real_T(chartInstance, &c2_varargin_2);
        c2_emxInit_real_T(chartInstance, &c2_r_x, 2, &c2_xf_emlrtRTEI);
        c2_i746 = c2_r_x->size[0] * c2_r_x->size[1];
        c2_r_x->size[0] = c2_metric->size[0];
        c2_r_x->size[1] = c2_metric->size[1];
        c2_emxEnsureCapacity_real_T(chartInstance, c2_r_x, c2_i746,
          &c2_xf_emlrtRTEI);
        c2_i747 = c2_r_x->size[0];
        c2_i748 = c2_r_x->size[1];
        c2_p_loop_ub = c2_metric->size[0] * c2_metric->size[1] - 1;
        for (c2_i749 = 0; c2_i749 <= c2_p_loop_ub; c2_i749++) {
          c2_r_x->data[c2_i749] = c2_metric->data[c2_i749];
        }

        c2_emxInit_real_T(chartInstance, &c2_b_sortIdx, 2, &c2_of_emlrtRTEI);
        c2_emxInit_int32_T1(chartInstance, &c2_iidx, 2, &c2_of_emlrtRTEI);
        c2_d_sort(chartInstance, c2_r_x, c2_iidx);
        c2_i750 = c2_b_sortIdx->size[0] * c2_b_sortIdx->size[1];
        c2_b_sortIdx->size[0] = c2_iidx->size[0];
        c2_b_sortIdx->size[1] = 1;
        c2_emxEnsureCapacity_real_T(chartInstance, c2_b_sortIdx, c2_i750,
          &c2_yf_emlrtRTEI);
        c2_i751 = c2_b_sortIdx->size[0];
        c2_i752 = c2_b_sortIdx->size[1];
        c2_q_loop_ub = c2_iidx->size[0] * c2_iidx->size[1] - 1;
        for (c2_i753 = 0; c2_i753 <= c2_q_loop_ub; c2_i753++) {
          c2_b_sortIdx->data[c2_i753] = (real_T)c2_iidx->data[c2_i753];
        }

        c2_emxFree_int32_T(chartInstance, &c2_iidx);
        c2_i754 = c2_metric->size[0] * c2_metric->size[1];
        c2_metric->size[0] = c2_r_x->size[0];
        c2_metric->size[1] = 1;
        c2_emxEnsureCapacity_real_T(chartInstance, c2_metric, c2_i754,
          &c2_ag_emlrtRTEI);
        c2_i755 = c2_metric->size[0];
        c2_i756 = c2_metric->size[1];
        c2_r_loop_ub = c2_r_x->size[0] * c2_r_x->size[1] - 1;
        for (c2_i757 = 0; c2_i757 <= c2_r_loop_ub; c2_i757++) {
          c2_metric->data[c2_i757] = c2_r_x->data[c2_i757];
        }

        c2_i758 = c2_r_x->size[0] * c2_r_x->size[1];
        c2_r_x->size[0] = c2_b_sortIdx->size[0];
        c2_r_x->size[1] = 1;
        c2_emxEnsureCapacity_real_T(chartInstance, c2_r_x, c2_i758,
          &c2_bg_emlrtRTEI);
        c2_b_centers = c2_centers->size[0];
        c2_i759 = c2_r_x->size[0];
        c2_i760 = c2_r_x->size[1];
        c2_s_loop_ub = c2_b_sortIdx->size[0] * c2_b_sortIdx->size[1] - 1;
        for (c2_i761 = 0; c2_i761 <= c2_s_loop_ub; c2_i761++) {
          c2_r_x->data[c2_i761] = (real_T)sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, (int32_T)c2_b_sortIdx->data[c2_i761], 1, c2_b_centers);
        }

        c2_emxInit_real_T(chartInstance, &c2_c_centers, 2, &c2_cg_emlrtRTEI);
        c2_c_sortIdx[0] = c2_b_sortIdx->size[0];
        c2_i762 = c2_c_centers->size[0] * c2_c_centers->size[1];
        c2_c_centers->size[0] = c2_c_sortIdx[0];
        c2_c_centers->size[1] = 2;
        c2_emxEnsureCapacity_real_T(chartInstance, c2_c_centers, c2_i762,
          &c2_cg_emlrtRTEI);
        c2_emxFree_real_T(chartInstance, &c2_b_sortIdx);
        for (c2_i763 = 0; c2_i763 < 2; c2_i763++) {
          c2_t_loop_ub = c2_c_sortIdx[0] - 1;
          for (c2_i765 = 0; c2_i765 <= c2_t_loop_ub; c2_i765++) {
            c2_c_centers->data[c2_i765 + c2_c_centers->size[0] * c2_i763] =
              c2_centers->data[((int32_T)c2_r_x->data[c2_i765] +
                                c2_centers->size[0] * c2_i763) - 1];
          }
        }

        c2_emxFree_real_T(chartInstance, &c2_r_x);
        c2_i764 = c2_centers->size[0] * c2_centers->size[1];
        c2_centers->size[0] = c2_c_centers->size[0];
        c2_centers->size[1] = c2_c_centers->size[1];
        c2_emxEnsureCapacity_real_T(chartInstance, c2_centers, c2_i764,
          &c2_dg_emlrtRTEI);
        c2_i766 = c2_centers->size[0];
        c2_i767 = c2_centers->size[1];
        c2_u_loop_ub = c2_c_centers->size[0] * c2_c_centers->size[1] - 1;
        for (c2_i768 = 0; c2_i768 <= c2_u_loop_ub; c2_i768++) {
          c2_centers->data[c2_i768] = c2_c_centers->data[c2_i768];
        }

        c2_emxFree_real_T(chartInstance, &c2_c_centers);
      }
    }

    c2_emxFree_sBO2RC5RVZVTbundPSRqHnH(chartInstance, &c2_s);
  }
}

static void c2_medfilt2(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real_T c2_h_varargin_1[19200], real_T c2_b[19200])
{
  int32_T c2_i769;
  real_T c2_dv8[25];
  int32_T c2_b_idx;
  int32_T c2_tmp_size[1];
  int32_T c2_i770;
  int32_T c2_indices_size[1];
  int32_T c2_tmp_data[25];
  int32_T c2_i771;
  int32_T c2_j_size[1];
  int32_T c2_ii;
  int32_T c2_jj;
  boolean_T c2_b51;
  int32_T c2_indices_data[25];
  int32_T c2_j_data[25];
  int32_T c2_i772;
  int32_T c2_b_tmp_size[1];
  int32_T c2_loop_ub;
  int32_T c2_i773;
  int32_T c2_iv12[2];
  int32_T c2_b_tmp_data[25];
  boolean_T c2_b52;
  int32_T c2_i774;
  int32_T c2_b_loop_ub;
  int32_T c2_i775;
  int32_T c2_iv13[2];
  boolean_T c2_b53;
  int32_T c2_i776;
  int32_T c2_c_loop_ub;
  int32_T c2_i777;
  int32_T c2_iv14[2];
  int32_T c2_rows_size[1];
  int32_T c2_d_loop_ub;
  int32_T c2_i778;
  int32_T c2_cols_size[1];
  real_T c2_rows_data[25];
  int32_T c2_e_loop_ub;
  int32_T c2_i779;
  real_T c2_cols_data[25];
  int32_T c2_f_loop_ub;
  int32_T c2_i780;
  int32_T c2_g_loop_ub;
  int32_T c2_i781;
  c2_emxArray_real_T *c2_rows;
  int32_T c2_i782;
  int32_T c2_h_loop_ub;
  int32_T c2_i783;
  c2_emxArray_real_T *c2_r12;
  int32_T c2_varargin_1_size[1];
  int32_T c2_i_loop_ub;
  int32_T c2_i784;
  real_T c2_varargin_1_data[25];
  boolean_T c2_b54;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  static char_T c2_cv49[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_',
    'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  int32_T c2_n;
  const mxArray *c2_f_y = NULL;
  int32_T c2_b_n;
  real_T c2_d_x;
  real_T c2_maxval;
  real_T c2_e_x;
  real_T c2_f_x;
  boolean_T c2_b_b;
  boolean_T c2_c_b;
  boolean_T c2_p;
  c2_emxArray_real_T *c2_cols;
  real_T c2_g_x;
  int32_T c2_i785;
  int32_T c2_c_idx;
  boolean_T c2_d_b;
  int32_T c2_e_b;
  int32_T c2_f_b;
  int32_T c2_j_loop_ub;
  int32_T c2_first;
  int32_T c2_i786;
  boolean_T c2_overflow;
  int32_T c2_last;
  real_T c2_ex;
  int32_T c2_i787;
  int32_T c2_l_a;
  int32_T c2_k_loop_ub;
  int32_T c2_k;
  int32_T c2_g_b;
  int32_T c2_m_a;
  int32_T c2_i788;
  int32_T c2_h_b;
  real_T c2_h_x;
  real_T c2_i_x;
  boolean_T c2_b_overflow;
  boolean_T c2_i_b;
  boolean_T c2_b_p;
  boolean_T c2_b55;
  int32_T c2_b_k;
  const mxArray *c2_g_y = NULL;
  const mxArray *c2_h_y = NULL;
  const mxArray *c2_i_y = NULL;
  static char_T c2_cv50[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_',
    'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };

  int32_T c2_c_n;
  const mxArray *c2_j_y = NULL;
  int32_T c2_d_n;
  real_T c2_j_x;
  real_T c2_b_maxval;
  real_T c2_k_x;
  real_T c2_l_x;
  boolean_T c2_j_b;
  boolean_T c2_k_b;
  boolean_T c2_c_p;
  real_T c2_i_varargin_1;
  real_T c2_m_x;
  real_T c2_varargin_2;
  int32_T c2_d_idx;
  boolean_T c2_l_b;
  real_T c2_n_x;
  int32_T c2_m_b;
  real_T c2_j_varargin_1;
  int32_T c2_n_b;
  real_T c2_o_x;
  int32_T c2_b_first;
  real_T c2_k_y;
  boolean_T c2_c_overflow;
  int32_T c2_b_last;
  real_T c2_p_x;
  real_T c2_b_ex;
  real_T c2_l_y;
  int32_T c2_i789;
  real_T c2_q_x;
  int32_T c2_n_a;
  real_T c2_m_y;
  int32_T c2_c_k;
  int32_T c2_o_b;
  real_T c2_r_x;
  int32_T c2_o_a;
  real_T c2_n_y;
  int32_T c2_p_b;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_o_y;
  real_T c2_u_x;
  boolean_T c2_d_overflow;
  real_T c2_padSize;
  boolean_T c2_q_b;
  real_T c2_p_a;
  boolean_T c2_d_p;
  int32_T c2_i790;
  int32_T c2_d_k;
  int32_T c2_i791;
  real_T c2_startIdx[2];
  c2_emxArray_real_T *c2_Apad;
  c2_emxArray_real_T *c2_q_a;
  real_T c2_Ma;
  int32_T c2_i792;
  int32_T c2_l_loop_ub;
  int32_T c2_i793;
  real_T c2_r_b;
  int32_T c2_i794;
  int32_T c2_m_loop_ub;
  int32_T c2_i795;
  int32_T c2_n_loop_ub;
  int32_T c2_i796;
  int32_T c2_o_loop_ub;
  int32_T c2_i797;
  real_T c2_d16;
  int32_T c2_i798;
  int32_T c2_i799;
  int32_T c2_i800;
  real_T c2_sizeA[2];
  int32_T c2_i801;
  int32_T c2_i802;
  real_T c2_domainSizeT[2];
  real_T c2_dv9[2];
  boolean_T exitg1;
  for (c2_i769 = 0; c2_i769 < 25; c2_i769++) {
    c2_dv8[c2_i769] = 1.0;
  }

  c2_toLogicalCheck(chartInstance, c2_dv8);
  c2_b_idx = 0;
  c2_tmp_size[0] = 25;
  for (c2_i770 = 0; c2_i770 < 25; c2_i770++) {
    c2_tmp_data[c2_i770] = 0;
  }

  c2_indices_size[0] = c2_tmp_size[0];
  c2_tmp_size[0] = 25;
  for (c2_i771 = 0; c2_i771 < 25; c2_i771++) {
    c2_tmp_data[c2_i771] = 0;
  }

  c2_j_size[0] = c2_tmp_size[0];
  c2_ii = 1;
  c2_jj = 1;
  exitg1 = false;
  while ((!exitg1) && (c2_jj <= 5)) {
    c2_b_idx++;
    c2_indices_data[c2_b_idx - 1] = c2_ii;
    c2_j_data[c2_b_idx - 1] = c2_jj;
    if (c2_b_idx >= 25) {
      exitg1 = true;
    } else {
      c2_ii++;
      if (c2_ii > 5) {
        c2_ii = 1;
        c2_jj++;
      }
    }
  }

  c2_b51 = (1 > c2_b_idx);
  if (c2_b51) {
    c2_i772 = 0;
  } else {
    c2_i772 = c2_b_idx;
  }

  c2_b_tmp_size[0] = c2_i772;
  c2_loop_ub = c2_i772 - 1;
  for (c2_i773 = 0; c2_i773 <= c2_loop_ub; c2_i773++) {
    c2_b_tmp_data[c2_i773] = 1 + c2_i773;
  }

  c2_iv12[0] = 1;
  c2_iv12[1] = c2_b_tmp_size[0];
  c2_indexShapeCheck(chartInstance, 25, c2_iv12);
  c2_indices_size[0] = c2_i772;
  c2_b52 = (1 > c2_b_idx);
  if (c2_b52) {
    c2_i774 = 0;
  } else {
    c2_i774 = c2_b_idx;
  }

  c2_b_tmp_size[0] = c2_i774;
  c2_b_loop_ub = c2_i774 - 1;
  for (c2_i775 = 0; c2_i775 <= c2_b_loop_ub; c2_i775++) {
    c2_b_tmp_data[c2_i775] = 1 + c2_i775;
  }

  c2_iv13[0] = 1;
  c2_iv13[1] = c2_b_tmp_size[0];
  c2_indexShapeCheck(chartInstance, 25, c2_iv13);
  c2_j_size[0] = c2_i774;
  c2_b53 = (1 > c2_b_idx);
  if (c2_b53) {
    c2_i776 = 0;
  } else {
    c2_i776 = c2_b_idx;
  }

  c2_b_tmp_size[0] = c2_i776;
  c2_c_loop_ub = c2_i776 - 1;
  for (c2_i777 = 0; c2_i777 <= c2_c_loop_ub; c2_i777++) {
    c2_b_tmp_data[c2_i777] = 1 + c2_i777;
  }

  c2_iv14[0] = 1;
  c2_iv14[1] = c2_b_tmp_size[0];
  c2_indexShapeCheck(chartInstance, 25, c2_iv14);
  c2_rows_size[0] = c2_indices_size[0];
  c2_d_loop_ub = c2_indices_size[0] - 1;
  for (c2_i778 = 0; c2_i778 <= c2_d_loop_ub; c2_i778++) {
    c2_rows_data[c2_i778] = (real_T)c2_indices_data[c2_i778];
  }

  c2_cols_size[0] = c2_j_size[0];
  c2_e_loop_ub = c2_j_size[0] - 1;
  for (c2_i779 = 0; c2_i779 <= c2_e_loop_ub; c2_i779++) {
    c2_cols_data[c2_i779] = (real_T)c2_j_data[c2_i779];
  }

  c2_rows_size[0];
  c2_f_loop_ub = c2_rows_size[0] - 1;
  for (c2_i780 = 0; c2_i780 <= c2_f_loop_ub; c2_i780++) {
    c2_rows_data[c2_i780] -= 3.0;
  }

  c2_cols_size[0];
  c2_g_loop_ub = c2_cols_size[0] - 1;
  for (c2_i781 = 0; c2_i781 <= c2_g_loop_ub; c2_i781++) {
    c2_cols_data[c2_i781] -= 3.0;
  }

  c2_emxInit_real_T1(chartInstance, &c2_rows, 1, &c2_ig_emlrtRTEI);
  c2_i782 = c2_rows->size[0];
  c2_rows->size[0] = c2_rows_size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_rows, c2_i782, &c2_ig_emlrtRTEI);
  c2_h_loop_ub = c2_rows_size[0] - 1;
  for (c2_i783 = 0; c2_i783 <= c2_h_loop_ub; c2_i783++) {
    c2_rows->data[c2_i783] = c2_rows_data[c2_i783];
  }

  c2_emxInit_real_T1(chartInstance, &c2_r12, 1, &c2_og_emlrtRTEI);
  c2_abs(chartInstance, c2_rows, c2_r12);
  c2_varargin_1_size[0] = c2_r12->size[0];
  c2_i_loop_ub = c2_r12->size[0] - 1;
  c2_emxFree_real_T(chartInstance, &c2_rows);
  for (c2_i784 = 0; c2_i784 <= c2_i_loop_ub; c2_i784++) {
    c2_varargin_1_data[c2_i784] = c2_r12->data[c2_i784];
  }

  if ((c2_varargin_1_size[0] == 1) || ((real_T)c2_varargin_1_size[0] != 1.0)) {
    c2_b54 = true;
  } else {
    c2_b54 = false;
  }

  if (c2_b54) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv9, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv9, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_d_y)));
  }

  if ((real_T)c2_varargin_1_size[0] >= 1.0) {
  } else {
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv49, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv49, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_e_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_f_y)));
  }

  c2_n = c2_varargin_1_size[0];
  if (c2_n <= 2) {
    if (c2_n == 1) {
      c2_maxval = c2_varargin_1_data[0];
    } else if (c2_varargin_1_data[0] < c2_varargin_1_data[1]) {
      c2_maxval = c2_varargin_1_data[1];
    } else {
      c2_f_x = c2_varargin_1_data[0];
      c2_c_b = muDoubleScalarIsNaN(c2_f_x);
      if (c2_c_b) {
        c2_g_x = c2_varargin_1_data[1];
        c2_d_b = muDoubleScalarIsNaN(c2_g_x);
        if (!c2_d_b) {
          c2_maxval = c2_varargin_1_data[1];
        } else {
          c2_maxval = c2_varargin_1_data[0];
        }
      } else {
        c2_maxval = c2_varargin_1_data[0];
      }
    }
  } else {
    c2_b_n = c2_varargin_1_size[0];
    c2_d_x = c2_varargin_1_data[0];
    c2_e_x = c2_d_x;
    c2_b_b = muDoubleScalarIsNaN(c2_e_x);
    c2_p = !c2_b_b;
    if (c2_p) {
      c2_c_idx = 1;
    } else {
      c2_c_idx = 0;
      c2_e_b = c2_b_n;
      c2_f_b = c2_e_b;
      if (2 > c2_f_b) {
        c2_overflow = false;
      } else {
        c2_overflow = (c2_f_b > 2147483646);
      }

      if (c2_overflow) {
        c2_check_forloop_overflow_error(chartInstance, true);
      }

      c2_k = 2;
      exitg1 = false;
      while ((!exitg1) && (c2_k <= c2_b_n)) {
        c2_h_x = c2_varargin_1_data[c2_k - 1];
        c2_i_x = c2_h_x;
        c2_i_b = muDoubleScalarIsNaN(c2_i_x);
        c2_b_p = !c2_i_b;
        if (c2_b_p) {
          c2_c_idx = c2_k;
          exitg1 = true;
        } else {
          c2_k++;
        }
      }
    }

    if (c2_c_idx == 0) {
      c2_maxval = c2_varargin_1_data[0];
    } else {
      c2_first = c2_c_idx - 1;
      c2_last = c2_n;
      c2_ex = c2_varargin_1_data[c2_first];
      c2_i787 = c2_first + 2;
      c2_l_a = c2_i787;
      c2_g_b = c2_last;
      c2_m_a = c2_l_a;
      c2_h_b = c2_g_b;
      if (c2_m_a > c2_h_b) {
        c2_b_overflow = false;
      } else {
        c2_b_overflow = (c2_h_b > 2147483646);
      }

      if (c2_b_overflow) {
        c2_check_forloop_overflow_error(chartInstance, true);
      }

      for (c2_b_k = c2_i787 - 1; c2_b_k < c2_last; c2_b_k++) {
        if (c2_ex < c2_varargin_1_data[c2_b_k]) {
          c2_ex = c2_varargin_1_data[c2_b_k];
        }
      }

      c2_maxval = c2_ex;
    }
  }

  c2_emxInit_real_T1(chartInstance, &c2_cols, 1, &c2_kg_emlrtRTEI);
  c2_i785 = c2_cols->size[0];
  c2_cols->size[0] = c2_cols_size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_cols, c2_i785, &c2_kg_emlrtRTEI);
  c2_j_loop_ub = c2_cols_size[0] - 1;
  for (c2_i786 = 0; c2_i786 <= c2_j_loop_ub; c2_i786++) {
    c2_cols->data[c2_i786] = c2_cols_data[c2_i786];
  }

  c2_abs(chartInstance, c2_cols, c2_r12);
  c2_varargin_1_size[0] = c2_r12->size[0];
  c2_k_loop_ub = c2_r12->size[0] - 1;
  c2_emxFree_real_T(chartInstance, &c2_cols);
  for (c2_i788 = 0; c2_i788 <= c2_k_loop_ub; c2_i788++) {
    c2_varargin_1_data[c2_i788] = c2_r12->data[c2_i788];
  }

  c2_emxFree_real_T(chartInstance, &c2_r12);
  if ((c2_varargin_1_size[0] == 1) || ((real_T)c2_varargin_1_size[0] != 1.0)) {
    c2_b55 = true;
  } else {
    c2_b55 = false;
  }

  if (c2_b55) {
  } else {
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_cv9, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c2_h_y = NULL;
    sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv9, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_g_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_h_y)));
  }

  if ((real_T)c2_varargin_1_size[0] >= 1.0) {
  } else {
    c2_i_y = NULL;
    sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_cv50, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    c2_j_y = NULL;
    sf_mex_assign(&c2_j_y, sf_mex_create("y", c2_cv50, 10, 0U, 1U, 0U, 2, 1, 39),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_i_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_j_y)));
  }

  c2_c_n = c2_varargin_1_size[0];
  if (c2_c_n <= 2) {
    if (c2_c_n == 1) {
      c2_b_maxval = c2_varargin_1_data[0];
    } else if (c2_varargin_1_data[0] < c2_varargin_1_data[1]) {
      c2_b_maxval = c2_varargin_1_data[1];
    } else {
      c2_l_x = c2_varargin_1_data[0];
      c2_k_b = muDoubleScalarIsNaN(c2_l_x);
      if (c2_k_b) {
        c2_m_x = c2_varargin_1_data[1];
        c2_l_b = muDoubleScalarIsNaN(c2_m_x);
        if (!c2_l_b) {
          c2_b_maxval = c2_varargin_1_data[1];
        } else {
          c2_b_maxval = c2_varargin_1_data[0];
        }
      } else {
        c2_b_maxval = c2_varargin_1_data[0];
      }
    }
  } else {
    c2_d_n = c2_varargin_1_size[0];
    c2_j_x = c2_varargin_1_data[0];
    c2_k_x = c2_j_x;
    c2_j_b = muDoubleScalarIsNaN(c2_k_x);
    c2_c_p = !c2_j_b;
    if (c2_c_p) {
      c2_d_idx = 1;
    } else {
      c2_d_idx = 0;
      c2_m_b = c2_d_n;
      c2_n_b = c2_m_b;
      if (2 > c2_n_b) {
        c2_c_overflow = false;
      } else {
        c2_c_overflow = (c2_n_b > 2147483646);
      }

      if (c2_c_overflow) {
        c2_check_forloop_overflow_error(chartInstance, true);
      }

      c2_c_k = 2;
      exitg1 = false;
      while ((!exitg1) && (c2_c_k <= c2_d_n)) {
        c2_t_x = c2_varargin_1_data[c2_c_k - 1];
        c2_u_x = c2_t_x;
        c2_q_b = muDoubleScalarIsNaN(c2_u_x);
        c2_d_p = !c2_q_b;
        if (c2_d_p) {
          c2_d_idx = c2_c_k;
          exitg1 = true;
        } else {
          c2_c_k++;
        }
      }
    }

    if (c2_d_idx == 0) {
      c2_b_maxval = c2_varargin_1_data[0];
    } else {
      c2_b_first = c2_d_idx - 1;
      c2_b_last = c2_c_n;
      c2_b_ex = c2_varargin_1_data[c2_b_first];
      c2_i789 = c2_b_first + 2;
      c2_n_a = c2_i789;
      c2_o_b = c2_b_last;
      c2_o_a = c2_n_a;
      c2_p_b = c2_o_b;
      if (c2_o_a > c2_p_b) {
        c2_d_overflow = false;
      } else {
        c2_d_overflow = (c2_p_b > 2147483646);
      }

      if (c2_d_overflow) {
        c2_check_forloop_overflow_error(chartInstance, true);
      }

      for (c2_d_k = c2_i789 - 1; c2_d_k < c2_b_last; c2_d_k++) {
        if (c2_b_ex < c2_varargin_1_data[c2_d_k]) {
          c2_b_ex = c2_varargin_1_data[c2_d_k];
        }
      }

      c2_b_maxval = c2_b_ex;
    }
  }

  c2_i_varargin_1 = c2_maxval;
  c2_varargin_2 = c2_b_maxval;
  c2_n_x = c2_i_varargin_1;
  c2_j_varargin_1 = c2_varargin_2;
  c2_o_x = c2_n_x;
  c2_k_y = c2_j_varargin_1;
  c2_p_x = c2_o_x;
  c2_l_y = c2_k_y;
  c2_q_x = c2_p_x;
  c2_m_y = c2_l_y;
  c2_r_x = c2_q_x;
  c2_n_y = c2_m_y;
  c2_s_x = c2_r_x;
  c2_o_y = c2_n_y;
  c2_padSize = muDoubleScalarMax(c2_s_x, c2_o_y);
  c2_p_a = c2_padSize;
  for (c2_i790 = 0; c2_i790 < 2; c2_i790++) {
    c2_startIdx[c2_i790] = c2_p_a;
  }

  for (c2_i791 = 0; c2_i791 < 19200; c2_i791++) {
    chartInstance->c2_b_varargin_1[c2_i791] = c2_h_varargin_1[c2_i791];
  }

  c2_emxInit_real_T(chartInstance, &c2_Apad, 2, &c2_ng_emlrtRTEI);
  c2_emxInit_real_T1(chartInstance, &c2_q_a, 1, &c2_lg_emlrtRTEI);
  c2_padarray(chartInstance, chartInstance->c2_b_varargin_1, c2_startIdx,
              c2_Apad);
  c2_Ma = (real_T)c2_Apad->size[0];
  c2_i792 = c2_q_a->size[0];
  c2_q_a->size[0] = c2_cols_size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_q_a, c2_i792, &c2_lg_emlrtRTEI);
  c2_l_loop_ub = c2_cols_size[0] - 1;
  for (c2_i793 = 0; c2_i793 <= c2_l_loop_ub; c2_i793++) {
    c2_q_a->data[c2_i793] = c2_cols_data[c2_i793];
  }

  c2_r_b = c2_Ma;
  c2_i794 = c2_q_a->size[0];
  c2_q_a->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_q_a, c2_i794, &c2_l_emlrtRTEI);
  c2_m_loop_ub = c2_q_a->size[0] - 1;
  for (c2_i795 = 0; c2_i795 <= c2_m_loop_ub; c2_i795++) {
    c2_q_a->data[c2_i795] *= c2_r_b;
  }

  c2_cols_size[0] = c2_q_a->size[0];
  c2_n_loop_ub = c2_q_a->size[0] - 1;
  for (c2_i796 = 0; c2_i796 <= c2_n_loop_ub; c2_i796++) {
    c2_cols_data[c2_i796] = c2_q_a->data[c2_i796];
  }

  c2_emxFree_real_T(chartInstance, &c2_q_a);
  _SFD_SIZE_EQ_CHECK_1D(c2_cols_size[0], c2_rows_size[0]);
  c2_indices_size[0] = c2_cols_size[0];
  c2_o_loop_ub = c2_cols_size[0] - 1;
  for (c2_i797 = 0; c2_i797 <= c2_o_loop_ub; c2_i797++) {
    c2_d16 = muDoubleScalarRound(c2_cols_data[c2_i797] + c2_rows_data[c2_i797]);
    if (c2_d16 < 2.147483648E+9) {
      if (c2_d16 >= -2.147483648E+9) {
        c2_i799 = (int32_T)c2_d16;
      } else {
        c2_i799 = MIN_int32_T;
        _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
      }
    } else if (c2_d16 >= 2.147483648E+9) {
      c2_i799 = MAX_int32_T;
      _SFD_OVERFLOW_DETECTION(SFDB_SATURATE, 1U, 0U, 0U);
    } else {
      c2_i799 = 0;
    }

    c2_indices_data[c2_i797] = c2_i799;
  }

  c2_startIdx[0] = c2_padSize;
  c2_startIdx[1] = c2_padSize;
  for (c2_i798 = 0; c2_i798 < 2; c2_i798++) {
    c2_sizeA[c2_i798] = (real_T)c2_Apad->size[c2_i798];
  }

  for (c2_i800 = 0; c2_i800 < 2; c2_i800++) {
    c2_sizeA[c2_i800];
  }

  for (c2_i801 = 0; c2_i801 < 2; c2_i801++) {
    c2_domainSizeT[c2_i801] = 5.0;
  }

  for (c2_i802 = 0; c2_i802 < 2; c2_i802++) {
    c2_dv9[c2_i802] = 120.0 + 40.0 * (real_T)c2_i802;
  }

  ordfilt2_real64(&c2_Apad->data[0], c2_sizeA[0], c2_startIdx, &c2_indices_data
                  [0], (real_T)c2_indices_size[0], c2_domainSizeT, 12.0, c2_b,
                  c2_dv9, true);
  c2_emxFree_real_T(chartInstance, &c2_Apad);
}

static void c2_padarray(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real_T c2_h_varargin_1[19200], real_T c2_varargin_2[2], c2_emxArray_real_T
  *c2_b)
{
  boolean_T c2_p;
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_d_x;
  boolean_T c2_b56;
  real_T c2_e_x;
  boolean_T c2_b_b;
  boolean_T c2_b_p;
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv51[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'a', 'd',
    'a', 'r', 'r', 'a', 'y', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'N',
    'o', 'n', 'N', 'a', 'N' };

  int32_T c2_i803;
  const mxArray *c2_d_y = NULL;
  real_T c2_b_varargin_2[2];
  const mxArray *c2_e_y = NULL;
  boolean_T c2_b57;
  static char_T c2_cv52[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '2', ',', ' ', 'P', 'A', 'D', 'S', 'I', 'Z', 'E', ',' };

  const mxArray *c2_f_y = NULL;
  static char_T c2_cv53[31] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'a', 'd',
    'a', 'r', 'r', 'a', 'y', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I',
    'n', 't', 'e', 'g', 'e', 'r' };

  int32_T c2_i804;
  const mxArray *c2_g_y = NULL;
  int32_T c2_i805;
  real_T c2_h_y[2];
  const mxArray *c2_i_y = NULL;
  static char_T c2_cv54[24] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '2', ',', ' ', 'P', 'A', 'D', 'S', 'I', 'Z', 'E', ',' };

  int32_T c2_i806;
  real_T c2_d17;
  int32_T c2_i807;
  int32_T c2_j;
  real_T c2_c_b;
  real_T c2_b_j;
  int32_T c2_c;
  real_T c2_d18;
  int32_T c2_l_a;
  int32_T c2_i808;
  int32_T c2_i809;
  int32_T c2_i;
  int32_T c2_i810;
  int32_T c2_m_a;
  int32_T c2_d_b;
  real_T c2_b_i;
  int32_T c2_n_a;
  int32_T c2_e_b;
  boolean_T c2_overflow;
  int32_T c2_c_j;
  int32_T c2_d_j;
  real_T c2_d19;
  int32_T c2_i811;
  int32_T c2_e_j;
  int32_T c2_c_i;
  real_T c2_d20;
  int32_T c2_f_j;
  int32_T c2_i812;
  real_T c2_o_a;
  int32_T c2_d_i;
  int32_T c2_b_c;
  int32_T c2_e_i;
  int32_T c2_p_a;
  int32_T c2_i813;
  int32_T c2_i814;
  real_T c2_q_a;
  real_T c2_r_a;
  int32_T c2_s_a;
  real_T c2_f_b;
  real_T c2_g_b;
  int32_T c2_h_b;
  int32_T c2_c_c;
  int32_T c2_d_c;
  int32_T c2_t_a;
  real_T c2_u_a;
  int32_T c2_i_b;
  real_T c2_j_b;
  int32_T c2_e_c;
  boolean_T c2_b_overflow;
  int32_T c2_f_i;
  real_T c2_v_a;
  real_T c2_k_b;
  int32_T c2_f_c;
  boolean_T exitg1;
  c2_p = true;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k < 2)) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_d_x = c2_varargin_2[(int32_T)c2_b_k - 1];
    c2_e_x = c2_d_x;
    c2_b_b = muDoubleScalarIsNaN(c2_e_x);
    c2_b_p = !c2_b_b;
    if (c2_b_p) {
      c2_k++;
    } else {
      c2_p = false;
      exitg1 = true;
    }
  }

  if (c2_p) {
    c2_b56 = true;
  } else {
    c2_b56 = false;
  }

  if (c2_b56) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv51, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv8, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv52, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c2_d_y, 14, c2_e_y)));
  }

  for (c2_i803 = 0; c2_i803 < 2; c2_i803++) {
    c2_b_varargin_2[c2_i803] = c2_varargin_2[c2_i803];
  }

  if (c2_all(chartInstance, c2_b_varargin_2)) {
    c2_b57 = true;
  } else {
    c2_b57 = false;
  }

  if (c2_b57) {
  } else {
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv53, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_cv6, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c2_i_y = NULL;
    sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_cv54, 10, 0U, 1U, 0U, 2, 1, 24),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_f_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c2_g_y, 14, c2_i_y)));
  }

  for (c2_i804 = 0; c2_i804 < 2; c2_i804++) {
    c2_h_y[c2_i804] = 2.0 * c2_varargin_2[c2_i804];
  }

  for (c2_i805 = 0; c2_i805 < 2; c2_i805++) {
    c2_h_y[c2_i805] += 120.0 + 40.0 * (real_T)c2_i805;
  }

  c2_i806 = c2_b->size[0] * c2_b->size[1];
  c2_b->size[0] = (int32_T)c2_h_y[0];
  c2_b->size[1] = (int32_T)c2_h_y[1];
  c2_emxEnsureCapacity_real_T(chartInstance, c2_b, c2_i806, &c2_pg_emlrtRTEI);
  c2_d17 = c2_varargin_2[1];
  c2_i807 = (int32_T)c2_d17 - 1;
  for (c2_j = 0; c2_j <= c2_i807; c2_j++) {
    c2_b_j = 1.0 + (real_T)c2_j;
    c2_d18 = (real_T)c2_b->size[0];
    c2_i808 = (int32_T)c2_d18 - 1;
    for (c2_i = 0; c2_i <= c2_i808; c2_i++) {
      c2_b_i = 1.0 + (real_T)c2_i;
      c2_b->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_i, 1, c2_b->
        size[0]) + c2_b->size[0] * ((int32_T)c2_b_j - 1)) - 1] = 0.0;
    }
  }

  c2_c_b = c2_varargin_2[1];
  c2_c = (int32_T)c2_c_b;
  c2_l_a = c2_c + 161;
  c2_i809 = c2_l_a;
  c2_i810 = c2_b->size[1];
  c2_m_a = c2_i809;
  c2_d_b = c2_i810;
  c2_n_a = c2_m_a;
  c2_e_b = c2_d_b;
  if (c2_n_a > c2_e_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_e_b > 2147483646);
  }

  if (c2_overflow) {
    c2_check_forloop_overflow_error(chartInstance, true);
  }

  for (c2_c_j = c2_i809; c2_c_j <= c2_i810; c2_c_j++) {
    c2_d19 = (real_T)c2_b->size[0];
    c2_i811 = (int32_T)c2_d19 - 1;
    for (c2_c_i = 0; c2_c_i <= c2_i811; c2_c_i++) {
      c2_b_i = 1.0 + (real_T)c2_c_i;
      c2_b->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_i, 1, c2_b->
        size[0]) + c2_b->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c2_c_j, 1, c2_b->size[1]) - 1)) - 1] = 0.0;
    }
  }

  for (c2_d_j = 0; c2_d_j < 160; c2_d_j++) {
    c2_b_j = 1.0 + (real_T)c2_d_j;
    c2_d20 = c2_varargin_2[0];
    c2_i812 = (int32_T)c2_d20 - 1;
    for (c2_d_i = 0; c2_d_i <= c2_i812; c2_d_i++) {
      c2_b_i = 1.0 + (real_T)c2_d_i;
      c2_q_a = c2_b_j;
      c2_f_b = c2_varargin_2[1];
      c2_c_c = (int32_T)c2_q_a + (int32_T)c2_f_b;
      c2_b->data[((int32_T)c2_b_i + c2_b->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c2_c_c, 1, c2_b->size[1]) - 1)) - 1] = 0.0;
    }
  }

  for (c2_e_j = 0; c2_e_j < 160; c2_e_j++) {
    c2_b_j = 1.0 + (real_T)c2_e_j;
    c2_o_a = c2_varargin_2[0];
    c2_b_c = (int32_T)c2_o_a;
    c2_p_a = c2_b_c + 121;
    c2_i813 = c2_p_a;
    c2_i814 = c2_b->size[0];
    c2_s_a = c2_i813;
    c2_h_b = c2_i814;
    c2_t_a = c2_s_a;
    c2_i_b = c2_h_b;
    if (c2_t_a > c2_i_b) {
      c2_b_overflow = false;
    } else {
      c2_b_overflow = (c2_i_b > 2147483646);
    }

    if (c2_b_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }

    for (c2_f_i = c2_i813; c2_f_i <= c2_i814; c2_f_i++) {
      c2_v_a = c2_b_j;
      c2_k_b = c2_varargin_2[1];
      c2_f_c = (int32_T)c2_v_a + (int32_T)c2_k_b;
      c2_b->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_f_i, 1, c2_b->size[0]) +
                  c2_b->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c2_f_c, 1, c2_b->size[1]) - 1)) - 1] = 0.0;
    }
  }

  for (c2_f_j = 0; c2_f_j < 160; c2_f_j++) {
    c2_b_j = 1.0 + (real_T)c2_f_j;
    for (c2_e_i = 0; c2_e_i < 120; c2_e_i++) {
      c2_b_i = 1.0 + (real_T)c2_e_i;
      c2_r_a = c2_b_i;
      c2_g_b = c2_varargin_2[0];
      c2_d_c = (int32_T)c2_r_a + (int32_T)c2_g_b;
      c2_u_a = c2_b_j;
      c2_j_b = c2_varargin_2[1];
      c2_e_c = (int32_T)c2_u_a + (int32_T)c2_j_b;
      c2_b->data[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_d_c, 1, c2_b->size[0]) +
                  c2_b->size[0] * (sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c2_e_c, 1, c2_b->size[1]) - 1)) - 1] = c2_h_varargin_1[((int32_T)c2_b_i
        + 120 * ((int32_T)c2_b_j - 1)) - 1];
    }
  }
}

static void c2_regionprops(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_h_varargin_1[19200], real_T c2_varargin_2[19200],
  c2_emxArray_sBO2RC5RVZVTbundPSRqHn *c2_outstats)
{
  int32_T c2_i815;
  c2_scIvRXQeSh8yxCxSmtD63bE c2_CC;
  boolean_T c2_i_varargin_1[19200];
  int32_T c2_i816;
  real_T c2_numObjs;
  real_T c2_imageSize[2];
  real_T c2_b_numObjs;
  boolean_T c2_p;
  boolean_T c2_b_p;
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_x1;
  real_T c2_x2;
  boolean_T c2_c_p;
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv55[31] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'r', 'e', 'g',
    'i', 'o', 'n', 'p', 'r', 'o', 'p', 's', ':', 's', 'i', 'z', 'e', 'M', 'i',
    's', 'm', 'a', 't', 'c', 'h' };

  real_T c2_c_numObjs;
  const mxArray *c2_d_y = NULL;
  int32_T c2_i817;
  c2_emxArray_boolean_T *c2_tile;
  c2_sBO2RC5RVZVTbundPSRqHnH c2_statsOneObj;
  real_T c2_j_varargin_1;
  int32_T c2_i818;
  int32_T c2_loop_ub;
  int32_T c2_i819;
  int32_T c2_outsize[2];
  const mxArray *c2_e_y = NULL;
  int32_T c2_i820;
  int32_T c2_b_loop_ub;
  int32_T c2_i821;
  c2_s9uuw2Xu7QLvohu1q5iD2hG c2_b_statsOneObj;
  real_T c2_d_numObjs;
  int32_T c2_i822;
  int32_T c2_i823;
  int32_T c2_i824;
  int32_T c2_i825;
  int32_T c2_i826;
  int32_T c2_i827;
  int32_T c2_i828;
  int32_T c2_i829;
  int32_T c2_i830;
  int32_T c2_i831;
  int32_T c2_i832;
  int32_T c2_i833;
  int32_T c2_i834;
  real_T c2_k_varargin_1;
  int32_T c2_i835;
  int32_T c2_c_loop_ub;
  int32_T c2_i836;
  int32_T c2_b_outsize[2];
  const mxArray *c2_f_y = NULL;
  c2_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c2_stats;
  int32_T c2_i837;
  int32_T c2_d_loop_ub;
  int32_T c2_i838;
  real_T c2_e_numObjs;
  c2_emxArray_int32_T *c2_regionLengths;
  c2_emxArray_real_T *c2_regionIndices;
  c2_emxArray_int32_T *c2_idxCount;
  int32_T c2_i839;
  int32_T c2_b_varargin_2;
  int32_T c2_c_varargin_2;
  int32_T c2_e_loop_ub;
  real_T c2_d21;
  int32_T c2_i840;
  int32_T c2_i841;
  int32_T c2_c_k;
  int32_T c2_i842;
  c2_emxArray_real_T *c2_r13;
  c2_cell_wrap_49 c2_reshapes[2];
  c2_emxArray_real_T *c2_c;
  int32_T c2_f_loop_ub;
  c2_emxArray_int32_T *c2_varargout_4;
  int32_T c2_i843;
  c2_emxArray_int32_T *c2_b_regionLengths;
  int32_T c2_dim;
  real_T c2_d_k;
  int32_T c2_i844;
  int32_T c2_varargin_3;
  int32_T c2_d_varargin_2;
  int32_T c2_e_varargin_2;
  real_T c2_d22;
  int32_T c2_g_loop_ub;
  int32_T c2_i845;
  int32_T c2_f_varargin_2;
  int32_T c2_i846;
  int32_T c2_i847;
  int32_T c2_g_varargin_2;
  int32_T c2_e_k;
  real_T c2_n;
  c2_emxArray_int32_T *c2_c_regionLengths;
  int32_T c2_nx;
  int32_T c2_i848;
  int32_T c2_i849;
  int32_T c2_h_loop_ub;
  int32_T c2_i850;
  int32_T c2_i851;
  int32_T c2_i852;
  real_T c2_f_k;
  int32_T c2_b;
  int32_T c2_i853;
  int32_T c2_i854;
  int32_T c2_i_loop_ub;
  real_T c2_d23;
  int32_T c2_b_b;
  int32_T c2_i855;
  int32_T c2_i856;
  int32_T c2_i857;
  int32_T c2_g_k;
  boolean_T c2_overflow;
  int32_T c2_j_loop_ub;
  int32_T c2_i858;
  int32_T c2_i859;
  int32_T c2_h_varargin_2;
  int32_T c2_i860;
  int32_T c2_i861;
  int32_T c2_i_varargin_2;
  int32_T c2_i862;
  real_T c2_h_k;
  real_T c2_d24;
  int32_T c2_i863;
  int32_T c2_k_loop_ub;
  int32_T c2_i864;
  int32_T c2_i_k;
  int32_T c2_i865;
  int32_T c2_i866;
  int32_T c2_i867;
  int32_T c2_j_k;
  int32_T c2_i868;
  boolean_T c2_b58;
  c2_emxArray_real_T *c2_r14;
  int32_T c2_i869;
  int32_T c2_k_k;
  c2_emxArray_real_T *c2_b_regionIndices;
  int32_T c2_i870;
  int32_T c2_i871;
  c2_emxArray_real_T *c2_r15;
  int32_T c2_i872;
  int32_T c2_i873;
  int32_T c2_i874;
  int32_T c2_l_loop_ub;
  int32_T c2_i875;
  int32_T c2_i876;
  real_T c2_l_k;
  int32_T c2_i877;
  int32_T c2_i878;
  int32_T c2_i879;
  int32_T c2_i880;
  const mxArray *c2_g_y = NULL;
  static char_T c2_cv56[36] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'i', 'n', 'd', '2', 's', 'u', 'b', '_', 'I', 'n', 'd', 'e',
    'x', 'O', 'u', 't', 'O', 'f', 'R', 'a', 'n', 'g', 'e' };

  int32_T c2_i881;
  int32_T c2_m_loop_ub;
  int32_T c2_n_loop_ub;
  const mxArray *c2_h_y = NULL;
  int32_T c2_o_loop_ub;
  int32_T c2_j_varargin_2;
  int32_T c2_i882;
  int32_T c2_i883;
  int32_T c2_i884;
  int32_T c2_k_varargin_2;
  int32_T c2_p_loop_ub;
  real_T c2_d25;
  int32_T c2_i885;
  int32_T c2_i886;
  int32_T c2_i887;
  int32_T c2_i888;
  int32_T c2_m_k;
  int32_T c2_i889;
  int32_T c2_q_loop_ub;
  int32_T c2_r_loop_ub;
  int32_T c2_i890;
  int32_T c2_i891;
  real_T c2_n_k;
  int32_T c2_s_loop_ub;
  real_T c2_sumIntensity;
  int32_T c2_i892;
  int32_T c2_i893;
  int32_T c2_vIdx;
  int32_T c2_b_n;
  int32_T c2_i894;
  int32_T c2_t_loop_ub;
  real_T c2_b_vIdx;
  int32_T c2_i895;
  real_T c2_c_n;
  int32_T c2_i896;
  int32_T c2_i897;
  int32_T c2_i898;
  int32_T c2_u_loop_ub;
  int32_T c2_i899;
  const mxArray *c2_i_y = NULL;
  static char_T c2_cv57[36] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'i', 'n', 'd', '2', 's', 'u', 'b', '_', 'I', 'n', 'd', 'e',
    'x', 'O', 'u', 't', 'O', 'f', 'R', 'a', 'n', 'g', 'e' };

  int32_T c2_i900;
  int32_T c2_i901;
  int32_T c2_i902;
  const mxArray *c2_j_y = NULL;
  int32_T c2_i903;
  int32_T c2_v_loop_ub;
  int32_T c2_w_loop_ub;
  int32_T c2_x_loop_ub;
  int32_T c2_i904;
  int32_T c2_i905;
  int32_T c2_i906;
  int32_T c2_i907;
  int32_T c2_i908;
  int32_T c2_i909;
  int32_T c2_d_n;
  int32_T c2_i910;
  int32_T c2_y_loop_ub;
  int32_T c2_ab_loop_ub;
  int32_T c2_i911;
  int32_T c2_i912;
  int32_T c2_bb_loop_ub;
  int32_T c2_i913;
  int32_T c2_i914;
  int32_T c2_i915;
  int32_T c2_i916;
  int32_T c2_cb_loop_ub;
  int32_T c2_db_loop_ub;
  int32_T c2_i917;
  int32_T c2_i918;
  int32_T c2_eb_loop_ub;
  int32_T c2_i919;
  int32_T c2_i920;
  int32_T c2_i921;
  real_T c2_M;
  int32_T c2_fb_loop_ub;
  int32_T c2_gb_loop_ub;
  int32_T c2_i922;
  int32_T c2_i923;
  int32_T c2_i924;
  int32_T c2_i925;
  int32_T c2_hb_loop_ub;
  int32_T c2_ib_loop_ub;
  int32_T c2_i926;
  int32_T c2_i927;
  int32_T c2_i928;
  int32_T c2_result;
  int32_T c2_sizes[2];
  int32_T c2_expected;
  int32_T c2_jb_loop_ub;
  int32_T c2_i929;
  boolean_T c2_b59;
  int32_T c2_i930;
  const mxArray *c2_k_y = NULL;
  static char_T c2_cv58[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 't',
    'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm',
    'e', 'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

  int32_T c2_kb_loop_ub;
  const mxArray *c2_l_y = NULL;
  int32_T c2_i931;
  int32_T c2_i932;
  const mxArray *c2_m_y = NULL;
  int32_T c2_i933;
  const mxArray *c2_n_y = NULL;
  int32_T c2_lb_loop_ub;
  int32_T c2_i934;
  int32_T c2_mb_loop_ub;
  int32_T c2_i935;
  int32_T c2_i936;
  int32_T c2_i937;
  int32_T c2_nb_loop_ub;
  int32_T c2_i938;
  int32_T c2_ob_loop_ub;
  int32_T c2_i939;
  real_T c2_d26;
  int32_T c2_i940;
  int32_T c2_i941;
  int32_T c2_b_idx;
  int32_T c2_pb_loop_ub;
  real_T c2_c_idx;
  int32_T c2_i942;
  int32_T c2_i943;
  int32_T c2_b_stats[2];
  int32_T c2_i944;
  int32_T c2_qb_loop_ub;
  int32_T c2_i945;
  int32_T c2_i946;
  int32_T c2_i947;
  int32_T c2_i948;
  int32_T c2_i949;
  int32_T c2_rb_loop_ub;
  int32_T c2_i950;
  int32_T c2_sb_loop_ub;
  int32_T c2_i951;
  boolean_T exitg1;
  for (c2_i815 = 0; c2_i815 < 19200; c2_i815++) {
    c2_i_varargin_1[c2_i815] = c2_h_varargin_1[c2_i815];
  }

  c2_emxInitStruct_scIvRXQeSh8yxCxSm(chartInstance, &c2_CC, &c2_th_emlrtRTEI);
  c2_bwconncomp(chartInstance, c2_i_varargin_1, &c2_CC);
  for (c2_i816 = 0; c2_i816 < 2; c2_i816++) {
    c2_imageSize[c2_i816] = c2_CC.ImageSize[c2_i816];
  }

  c2_numObjs = c2_CC.NumObjects;
  c2_b_numObjs = c2_numObjs;
  c2_p = false;
  c2_b_p = true;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k < 2)) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_x1 = c2_imageSize[(int32_T)c2_b_k - 1];
    c2_x2 = 120.0 + 40.0 * (real_T)((int32_T)c2_b_k - 1);
    c2_c_p = (c2_x1 == c2_x2);
    if (!c2_c_p) {
      c2_b_p = false;
      exitg1 = true;
    } else {
      c2_k++;
    }
  }

  if (!c2_b_p) {
  } else {
    c2_p = true;
  }

  if (c2_p) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv55, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv55, 10, 0U, 1U, 0U, 2, 1, 31),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_d_y)));
  }

  c2_c_numObjs = c2_b_numObjs;
  for (c2_i817 = 0; c2_i817 < 2; c2_i817++) {
    c2_statsOneObj.WeightedCentroid[c2_i817] = 0.0;
  }

  c2_emxInit_boolean_T1(chartInstance, &c2_tile, 1, &c2_qg_emlrtRTEI);
  c2_j_varargin_1 = c2_c_numObjs;
  c2_assertValidSizeArg(chartInstance, c2_j_varargin_1);
  c2_i818 = c2_tile->size[0];
  c2_tile->size[0] = (int32_T)c2_j_varargin_1;
  c2_emxEnsureCapacity_boolean_T1(chartInstance, c2_tile, c2_i818,
    &c2_qg_emlrtRTEI);
  c2_loop_ub = (int32_T)c2_j_varargin_1 - 1;
  for (c2_i819 = 0; c2_i819 <= c2_loop_ub; c2_i819++) {
    c2_tile->data[c2_i819] = false;
  }

  c2_outsize[0] = c2_tile->size[0];
  if ((real_T)c2_outsize[0] == (real_T)c2_tile->size[0]) {
  } else {
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv10, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14, c2_e_y);
  }

  c2_i820 = c2_outstats->size[0];
  c2_outstats->size[0] = c2_outsize[0];
  c2_emxEnsureCapacity_sBO2RC5RVZVTb(chartInstance, c2_outstats, c2_i820,
    &c2_rg_emlrtRTEI);
  c2_b_loop_ub = c2_outsize[0] - 1;
  for (c2_i821 = 0; c2_i821 <= c2_b_loop_ub; c2_i821++) {
    c2_outstats->data[c2_i821] = c2_statsOneObj;
  }

  c2_emxInitStruct_s9uuw2Xu7QLvohu1q(chartInstance, &c2_b_statsOneObj,
    &c2_vh_emlrtRTEI);
  c2_d_numObjs = c2_numObjs;
  c2_b_statsOneObj.Area = 0.0;
  for (c2_i822 = 0; c2_i822 < 2; c2_i822++) {
    c2_b_statsOneObj.Centroid[c2_i822] = 0.0;
  }

  for (c2_i823 = 0; c2_i823 < 4; c2_i823++) {
    c2_b_statsOneObj.BoundingBox[c2_i823] = 0.0;
  }

  c2_b_statsOneObj.MajorAxisLength = 0.0;
  c2_b_statsOneObj.MinorAxisLength = 0.0;
  c2_b_statsOneObj.Eccentricity = 0.0;
  c2_b_statsOneObj.Orientation = 0.0;
  c2_i824 = c2_b_statsOneObj.Image.size[0] * c2_b_statsOneObj.Image.size[1];
  c2_b_statsOneObj.Image.size[0] = 0;
  c2_b_statsOneObj.Image.size[1] = 0;
  c2_i825 = c2_b_statsOneObj.FilledImage.size[0] *
    c2_b_statsOneObj.FilledImage.size[1];
  c2_b_statsOneObj.FilledImage.size[0] = 0;
  c2_b_statsOneObj.FilledImage.size[1] = 0;
  c2_b_statsOneObj.FilledArea = 0.0;
  c2_b_statsOneObj.EulerNumber = 0.0;
  for (c2_i826 = 0; c2_i826 < 16; c2_i826++) {
    c2_b_statsOneObj.Extrema[c2_i826] = 0.0;
  }

  c2_b_statsOneObj.EquivDiameter = 0.0;
  c2_b_statsOneObj.Extent = 0.0;
  c2_i827 = c2_b_statsOneObj.PixelIdxList->size[0];
  c2_b_statsOneObj.PixelIdxList->size[0] = 0;
  c2_i828 = c2_b_statsOneObj.PixelList->size[0] *
    c2_b_statsOneObj.PixelList->size[1];
  c2_b_statsOneObj.PixelList->size[0] = 0;
  c2_b_statsOneObj.PixelList->size[1] = 2;
  c2_i829 = c2_b_statsOneObj.PixelList->size[0];
  c2_i830 = c2_b_statsOneObj.PixelList->size[1];
  c2_b_statsOneObj.Perimeter = 0.0;
  c2_b_statsOneObj.Circularity = 0.0;
  c2_i831 = c2_b_statsOneObj.PixelValues->size[0];
  c2_b_statsOneObj.PixelValues->size[0] = 0;
  for (c2_i832 = 0; c2_i832 < 2; c2_i832++) {
    c2_b_statsOneObj.WeightedCentroid[c2_i832] = 0.0;
  }

  c2_b_statsOneObj.MeanIntensity = 0.0;
  c2_b_statsOneObj.MinIntensity = 0.0;
  c2_b_statsOneObj.MaxIntensity = 0.0;
  c2_i833 = c2_b_statsOneObj.SubarrayIdx.size[0] *
    c2_b_statsOneObj.SubarrayIdx.size[1];
  c2_b_statsOneObj.SubarrayIdx.size[0] = 1;
  c2_b_statsOneObj.SubarrayIdx.size[1] = 0;
  for (c2_i834 = 0; c2_i834 < 2; c2_i834++) {
    c2_b_statsOneObj.SubarrayIdxLengths[c2_i834] = 0.0;
  }

  c2_k_varargin_1 = c2_d_numObjs;
  c2_assertValidSizeArg(chartInstance, c2_k_varargin_1);
  c2_i835 = c2_tile->size[0];
  c2_tile->size[0] = (int32_T)c2_k_varargin_1;
  c2_emxEnsureCapacity_boolean_T1(chartInstance, c2_tile, c2_i835,
    &c2_qg_emlrtRTEI);
  c2_c_loop_ub = (int32_T)c2_k_varargin_1 - 1;
  for (c2_i836 = 0; c2_i836 <= c2_c_loop_ub; c2_i836++) {
    c2_tile->data[c2_i836] = false;
  }

  c2_b_outsize[0] = c2_tile->size[0];
  if ((real_T)c2_b_outsize[0] == (real_T)c2_tile->size[0]) {
  } else {
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv10, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14, c2_f_y);
  }

  c2_emxFree_boolean_T(chartInstance, &c2_tile);
  c2_emxInit_s9uuw2Xu7QLvohu1q5iD2hG(chartInstance, &c2_stats, 1,
    &c2_uh_emlrtRTEI);
  c2_i837 = c2_stats->size[0];
  c2_stats->size[0] = c2_b_outsize[0];
  c2_emxEnsureCapacity_s9uuw2Xu7QLvo(chartInstance, c2_stats, c2_i837,
    &c2_sg_emlrtRTEI);
  c2_d_loop_ub = c2_b_outsize[0] - 1;
  for (c2_i838 = 0; c2_i838 <= c2_d_loop_ub; c2_i838++) {
    c2_emxCopyStruct_s9uuw2Xu7QLvohu1q(chartInstance, &c2_stats->data[c2_i838],
      &c2_b_statsOneObj, &c2_sg_emlrtRTEI);
  }

  c2_emxFreeStruct_s9uuw2Xu7QLvohu1q(chartInstance, &c2_b_statsOneObj);
  c2_e_numObjs = c2_numObjs;
  c2_emxInit_int32_T(chartInstance, &c2_regionLengths, 1, &c2_wh_emlrtRTEI);
  c2_emxInit_real_T1(chartInstance, &c2_regionIndices, 1, &c2_xh_emlrtRTEI);
  c2_emxInit_int32_T(chartInstance, &c2_idxCount, 1, &c2_yh_emlrtRTEI);
  if (c2_e_numObjs != 0.0) {
    c2_i839 = c2_regionIndices->size[0];
    c2_regionIndices->size[0] = c2_CC.RegionIndices->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_regionIndices, c2_i839,
      &c2_tg_emlrtRTEI);
    c2_e_loop_ub = c2_CC.RegionIndices->size[0] - 1;
    for (c2_i840 = 0; c2_i840 <= c2_e_loop_ub; c2_i840++) {
      c2_regionIndices->data[c2_i840] = c2_CC.RegionIndices->data[c2_i840];
    }

    c2_i842 = c2_regionLengths->size[0];
    c2_regionLengths->size[0] = c2_CC.RegionLengths->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_regionLengths, c2_i842,
      &c2_ug_emlrtRTEI);
    c2_f_loop_ub = c2_CC.RegionLengths->size[0] - 1;
    for (c2_i843 = 0; c2_i843 <= c2_f_loop_ub; c2_i843++) {
      c2_regionLengths->data[c2_i843] = c2_CC.RegionLengths->data[c2_i843];
    }

    c2_dim = 2;
    if ((real_T)c2_regionLengths->size[0] != 1.0) {
      c2_dim = 1;
    }

    c2_varargin_3 = c2_dim;
    if ((1 == c2_varargin_3) && (!(c2_regionLengths->size[0] == 0))) {
      c2_f_varargin_2 = c2_regionLengths->size[0];
      c2_g_varargin_2 = c2_f_varargin_2;
      c2_n = (real_T)c2_g_varargin_2;
      c2_nx = (int32_T)c2_n - 2;
      if ((real_T)c2_regionLengths->size[0] == 1.0) {
      } else {
        c2_i852 = c2_nx;
        c2_b = c2_i852 + 1;
        c2_b_b = c2_b;
        if (1 > c2_b_b) {
          c2_overflow = false;
        } else {
          c2_overflow = (c2_b_b > 2147483646);
        }

        if (c2_overflow) {
          c2_check_forloop_overflow_error(chartInstance, true);
        }

        for (c2_i_k = 0; c2_i_k <= c2_i852; c2_i_k++) {
          c2_k_k = c2_i_k;
          c2_regionLengths->data[c2_k_k + 1] += c2_regionLengths->data[c2_k_k];
        }
      }
    }

    c2_i845 = c2_idxCount->size[0];
    c2_idxCount->size[0] = 1 + c2_regionLengths->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_idxCount, c2_i845,
      &c2_wg_emlrtRTEI);
    c2_idxCount->data[0] = 0;
    c2_h_loop_ub = c2_regionLengths->size[0] - 1;
    for (c2_i851 = 0; c2_i851 <= c2_h_loop_ub; c2_i851++) {
      c2_idxCount->data[c2_i851 + 1] = c2_regionLengths->data[c2_i851];
    }

    c2_d23 = (real_T)c2_stats->size[0];
    c2_i856 = (int32_T)c2_d23 - 1;
    for (c2_g_k = 0; c2_g_k <= c2_i856; c2_g_k++) {
      c2_h_k = 1.0 + (real_T)c2_g_k;
      c2_i864 = c2_idxCount->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)c2_h_k, 1, c2_idxCount->size[0]) - 1] + 1;
      c2_i867 = c2_idxCount->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)(c2_h_k + 1.0), 1, c2_idxCount->size[0]) - 1];
      c2_b58 = (c2_i864 > c2_i867);
      if (c2_b58) {
        c2_i871 = 0;
        c2_i873 = -1;
      } else {
        c2_i871 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_i864, 1,
          c2_regionIndices->size[0]) - 1;
        c2_i873 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_i867, 1,
          c2_regionIndices->size[0]) - 1;
      }

      c2_i876 = c2_stats->size[0];
      c2_i877 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_h_k, 1, c2_i876) -
        1;
      c2_i880 = c2_stats->data[c2_i877].PixelIdxList->size[0];
      c2_stats->data[c2_i877].PixelIdxList->size[0] = (c2_i873 - c2_i871) + 1;
      c2_emxEnsureCapacity_real_T1(chartInstance, c2_stats->data[c2_i877].
        PixelIdxList, c2_i880, &c2_hh_emlrtRTEI);
      c2_o_loop_ub = c2_i873 - c2_i871;
      for (c2_i884 = 0; c2_i884 <= c2_o_loop_ub; c2_i884++) {
        c2_stats->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_h_k, 1, c2_i876)
          - 1].PixelIdxList->data[c2_i884] = c2_regionIndices->data[c2_i871 +
          c2_i884];
      }
    }
  }

  c2_emxFreeStruct_scIvRXQeSh8yxCxSm(chartInstance, &c2_CC);
  c2_b_varargin_2 = c2_stats->size[0];
  c2_c_varargin_2 = c2_b_varargin_2;
  c2_d21 = (real_T)c2_c_varargin_2;
  c2_i841 = (int32_T)c2_d21 - 1;
  c2_c_k = 0;
  c2_emxInit_real_T1(chartInstance, &c2_r13, 1, &c2_ai_emlrtRTEI);
  c2_emxInitMatrix_cell_wrap_49(chartInstance, c2_reshapes, &c2_bi_emlrtRTEI);
  c2_emxInit_real_T1(chartInstance, &c2_c, 1, &c2_ci_emlrtRTEI);
  c2_emxInit_int32_T(chartInstance, &c2_varargout_4, 1, &c2_ai_emlrtRTEI);
  c2_emxInit_int32_T(chartInstance, &c2_b_regionLengths, 1, &c2_ch_emlrtRTEI);
  while (c2_c_k <= c2_i841) {
    c2_d_k = 1.0 + (real_T)c2_c_k;
    c2_i844 = c2_r13->size[0];
    c2_r13->size[0] = c2_stats->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)c2_d_k, 1, c2_stats->size[0]) - 1].PixelIdxList->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_r13, c2_i844,
      &c2_vg_emlrtRTEI);
    c2_g_loop_ub = c2_stats->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)c2_d_k, 1, c2_stats->size[0]) - 1].PixelIdxList->size[0] - 1;
    for (c2_i847 = 0; c2_i847 <= c2_g_loop_ub; c2_i847++) {
      c2_r13->data[c2_i847] = c2_stats->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)c2_d_k, 1, c2_stats->size[0]) - 1].PixelIdxList->data[c2_i847];
    }

    if (c2_r13->size[0] != 0) {
      c2_i849 = c2_regionIndices->size[0];
      c2_regionIndices->size[0] = c2_stats->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)c2_d_k, 1, c2_stats->size[0]) - 1].PixelIdxList->size[0];
      c2_emxEnsureCapacity_real_T1(chartInstance, c2_regionIndices, c2_i849,
        &c2_xg_emlrtRTEI);
      c2_i_loop_ub = c2_stats->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)c2_d_k, 1, c2_stats->size[0]) - 1].PixelIdxList->size[0] - 1;
      for (c2_i855 = 0; c2_i855 <= c2_i_loop_ub; c2_i855++) {
        c2_regionIndices->data[c2_i855] = c2_stats->
          data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_d_k, 1,
          c2_stats->size[0]) - 1].PixelIdxList->data[c2_i855];
      }

      c2_i859 = c2_regionLengths->size[0];
      c2_regionLengths->size[0] = c2_regionIndices->size[0];
      c2_emxEnsureCapacity_int32_T(chartInstance, c2_regionLengths, c2_i859,
        &c2_ah_emlrtRTEI);
      c2_k_loop_ub = c2_regionIndices->size[0] - 1;
      for (c2_i866 = 0; c2_i866 <= c2_k_loop_ub; c2_i866++) {
        c2_regionLengths->data[c2_i866] = (int32_T)c2_regionIndices->
          data[c2_i866];
      }

      c2_i869 = c2_b_regionLengths->size[0];
      c2_b_regionLengths->size[0] = c2_regionLengths->size[0];
      c2_emxEnsureCapacity_int32_T(chartInstance, c2_b_regionLengths, c2_i869,
        &c2_ch_emlrtRTEI);
      c2_l_loop_ub = c2_regionLengths->size[0] - 1;
      for (c2_i875 = 0; c2_i875 <= c2_l_loop_ub; c2_i875++) {
        c2_b_regionLengths->data[c2_i875] = c2_regionLengths->data[c2_i875];
      }

      if (c2_b_allinrange(chartInstance, c2_b_regionLengths, 1.0, 19200)) {
      } else {
        c2_g_y = NULL;
        sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_cv56, 10, 0U, 1U, 0U, 2, 1,
          36), false);
        c2_h_y = NULL;
        sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv56, 10, 0U, 1U, 0U, 2, 1,
          36), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                          c2_g_y, 14, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "getString", 1U, 1U, 14,
                           sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 1U, 14, c2_h_y)));
      }

      c2_i881 = c2_regionLengths->size[0];
      c2_regionLengths->size[0];
      c2_emxEnsureCapacity_int32_T(chartInstance, c2_regionLengths, c2_i881,
        &c2_gh_emlrtRTEI);
      c2_p_loop_ub = c2_regionLengths->size[0] - 1;
      for (c2_i887 = 0; c2_i887 <= c2_p_loop_ub; c2_i887++) {
        c2_regionLengths->data[c2_i887]--;
      }

      c2_i889 = c2_idxCount->size[0];
      c2_idxCount->size[0] = c2_regionLengths->size[0];
      c2_emxEnsureCapacity_int32_T(chartInstance, c2_idxCount, c2_i889,
        &c2_ih_emlrtRTEI);
      c2_s_loop_ub = c2_regionLengths->size[0] - 1;
      for (c2_i893 = 0; c2_i893 <= c2_s_loop_ub; c2_i893++) {
        c2_idxCount->data[c2_i893] = c2_div_nzp_s32(chartInstance,
          c2_regionLengths->data[c2_i893], 120, 0, 1U, 0, 0);
      }

      c2_i894 = c2_varargout_4->size[0];
      c2_varargout_4->size[0] = c2_idxCount->size[0];
      c2_emxEnsureCapacity_int32_T(chartInstance, c2_varargout_4, c2_i894,
        &c2_jh_emlrtRTEI);
      c2_u_loop_ub = c2_idxCount->size[0] - 1;
      for (c2_i899 = 0; c2_i899 <= c2_u_loop_ub; c2_i899++) {
        c2_varargout_4->data[c2_i899] = c2_idxCount->data[c2_i899] + 1;
      }

      c2_i901 = c2_idxCount->size[0];
      c2_idxCount->size[0];
      c2_emxEnsureCapacity_int32_T(chartInstance, c2_idxCount, c2_i901,
        &c2_lh_emlrtRTEI);
      c2_x_loop_ub = c2_idxCount->size[0] - 1;
      for (c2_i906 = 0; c2_i906 <= c2_x_loop_ub; c2_i906++) {
        c2_idxCount->data[c2_i906] *= 120;
      }

      c2_i909 = c2_regionLengths->size[0];
      c2_regionLengths->size[0];
      c2_emxEnsureCapacity_int32_T(chartInstance, c2_regionLengths, c2_i909,
        &c2_mh_emlrtRTEI);
      c2_ab_loop_ub = c2_regionLengths->size[0] - 1;
      for (c2_i912 = 0; c2_i912 <= c2_ab_loop_ub; c2_i912++) {
        c2_regionLengths->data[c2_i912] -= c2_idxCount->data[c2_i912];
      }

      c2_i915 = c2_regionLengths->size[0];
      c2_regionLengths->size[0];
      c2_emxEnsureCapacity_int32_T(chartInstance, c2_regionLengths, c2_i915,
        &c2_nh_emlrtRTEI);
      c2_db_loop_ub = c2_regionLengths->size[0] - 1;
      for (c2_i918 = 0; c2_i918 <= c2_db_loop_ub; c2_i918++) {
        c2_regionLengths->data[c2_i918]++;
      }

      c2_i920 = c2_regionIndices->size[0];
      c2_regionIndices->size[0] = c2_regionLengths->size[0];
      c2_emxEnsureCapacity_real_T1(chartInstance, c2_regionIndices, c2_i920,
        &c2_oh_emlrtRTEI);
      c2_gb_loop_ub = c2_regionLengths->size[0] - 1;
      for (c2_i923 = 0; c2_i923 <= c2_gb_loop_ub; c2_i923++) {
        c2_regionIndices->data[c2_i923] = (real_T)c2_regionLengths->data[c2_i923];
      }

      c2_i925 = c2_c->size[0];
      c2_c->size[0] = c2_varargout_4->size[0];
      c2_emxEnsureCapacity_real_T1(chartInstance, c2_c, c2_i925,
        &c2_oh_emlrtRTEI);
      c2_ib_loop_ub = c2_varargout_4->size[0] - 1;
      for (c2_i927 = 0; c2_i927 <= c2_ib_loop_ub; c2_i927++) {
        c2_c->data[c2_i927] = (real_T)c2_varargout_4->data[c2_i927];
      }

      c2_result = c2_c->size[0];
      c2_sizes[0] = c2_result;
      c2_expected = c2_sizes[0];
      if (c2_c->size[0] == c2_expected) {
        c2_b59 = true;
      } else {
        c2_b59 = false;
      }

      if (c2_b59) {
      } else {
        c2_k_y = NULL;
        sf_mex_assign(&c2_k_y, sf_mex_create("y", c2_cv58, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        c2_l_y = NULL;
        sf_mex_assign(&c2_l_y, sf_mex_create("y", c2_cv58, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                          c2_k_y, 14, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "getString", 1U, 1U, 14,
                           sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 1U, 14, c2_l_y)));
      }

      if (c2_regionIndices->size[0] == c2_expected) {
        c2_b59 = true;
      } else {
        c2_b59 = false;
      }

      if (c2_b59) {
      } else {
        c2_m_y = NULL;
        sf_mex_assign(&c2_m_y, sf_mex_create("y", c2_cv58, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        c2_n_y = NULL;
        sf_mex_assign(&c2_n_y, sf_mex_create("y", c2_cv58, 10, 0U, 1U, 0U, 2, 1,
          39), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                          c2_m_y, 14, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "getString", 1U, 1U, 14,
                           sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 1U, 14, c2_n_y)));
      }

      c2_i933 = c2_reshapes[0].f1->size[0];
      c2_reshapes[0].f1->size[0] = c2_c->size[0];
      c2_emxEnsureCapacity_real_T1(chartInstance, c2_reshapes[0].f1, c2_i933,
        &c2_qh_emlrtRTEI);
      c2_mb_loop_ub = c2_c->size[0] - 1;
      for (c2_i935 = 0; c2_i935 <= c2_mb_loop_ub; c2_i935++) {
        c2_reshapes[0].f1->data[c2_i935] = c2_c->data[c2_i935];
      }

      c2_i937 = c2_reshapes[1].f1->size[0];
      c2_reshapes[1].f1->size[0] = c2_regionIndices->size[0];
      c2_emxEnsureCapacity_real_T1(chartInstance, c2_reshapes[1].f1, c2_i937,
        &c2_qh_emlrtRTEI);
      c2_ob_loop_ub = c2_regionIndices->size[0] - 1;
      for (c2_i939 = 0; c2_i939 <= c2_ob_loop_ub; c2_i939++) {
        c2_reshapes[1].f1->data[c2_i939] = c2_regionIndices->data[c2_i939];
      }

      c2_i941 = c2_regionIndices->size[0];
      c2_regionIndices->size[0] = c2_reshapes[0].f1->size[0];
      c2_emxEnsureCapacity_real_T1(chartInstance, c2_regionIndices, c2_i941,
        &c2_rh_emlrtRTEI);
      c2_pb_loop_ub = c2_reshapes[0].f1->size[0] - 1;
      for (c2_i942 = 0; c2_i942 <= c2_pb_loop_ub; c2_i942++) {
        c2_regionIndices->data[c2_i942] = c2_reshapes[0].f1->data[c2_i942];
      }

      c2_i944 = c2_c->size[0];
      c2_c->size[0] = c2_reshapes[1].f1->size[0];
      c2_emxEnsureCapacity_real_T1(chartInstance, c2_c, c2_i944,
        &c2_rh_emlrtRTEI);
      c2_qb_loop_ub = c2_reshapes[1].f1->size[0] - 1;
      for (c2_i945 = 0; c2_i945 <= c2_qb_loop_ub; c2_i945++) {
        c2_c->data[c2_i945] = c2_reshapes[1].f1->data[c2_i945];
      }

      c2_i946 = c2_stats->size[0];
      c2_i947 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_d_k, 1, c2_i946) -
        1;
      c2_i948 = c2_stats->data[c2_i947].PixelList->size[0] * c2_stats->
        data[c2_i947].PixelList->size[1];
      c2_stats->data[c2_i947].PixelList->size[0] = c2_regionIndices->size[0];
      c2_i949 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_d_k, 1, c2_i946) -
        1;
      c2_stats->data[c2_i949].PixelList->size[1] = 2;
      c2_emxEnsureCapacity_real_T(chartInstance, c2_stats->data[c2_i949].
        PixelList, c2_i948, &c2_sh_emlrtRTEI);
      c2_rb_loop_ub = c2_regionIndices->size[0] - 1;
      for (c2_i950 = 0; c2_i950 <= c2_rb_loop_ub; c2_i950++) {
        c2_stats->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_d_k, 1, c2_i946)
          - 1].PixelList->data[c2_i950] = c2_regionIndices->data[c2_i950];
      }

      c2_sb_loop_ub = c2_c->size[0] - 1;
      for (c2_i951 = 0; c2_i951 <= c2_sb_loop_ub; c2_i951++) {
        c2_stats->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_d_k, 1, c2_i946)
          - 1].PixelList->data[c2_i951 + c2_stats->
          data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_d_k, 1, c2_i946)
          - 1].PixelList->size[0]] = c2_c->data[c2_i951];
      }
    } else {
      c2_i848 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_d_k, 1,
        c2_stats->size[0]) - 1;
      c2_i850 = c2_stats->data[c2_i848].PixelList->size[0] * c2_stats->
        data[c2_i848].PixelList->size[1];
      c2_stats->data[c2_i848].PixelList->size[0] = 0;
      c2_i854 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_d_k, 1,
        c2_stats->size[0]) - 1;
      c2_stats->data[c2_i854].PixelList->size[1] = 2;
      c2_i857 = c2_stats->size[0];
      c2_i858 = c2_stats->size[0];
      c2_i861 = c2_stats->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)c2_d_k, 1, c2_i858) - 1].PixelList->size[0];
      c2_i862 = c2_stats->size[0];
      c2_i863 = c2_stats->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)c2_d_k, 1, c2_i862) - 1].PixelList->size[1];
    }

    c2_c_k++;
  }

  c2_emxFree_int32_T(chartInstance, &c2_b_regionLengths);
  c2_emxFreeMatrix_cell_wrap_49(chartInstance, c2_reshapes);
  c2_d_varargin_2 = c2_stats->size[0];
  c2_e_varargin_2 = c2_d_varargin_2;
  c2_d22 = (real_T)c2_e_varargin_2;
  c2_i846 = (int32_T)c2_d22 - 1;
  c2_e_k = 0;
  c2_emxInit_int32_T(chartInstance, &c2_c_regionLengths, 1, &c2_ch_emlrtRTEI);
  while (c2_e_k <= c2_i846) {
    c2_f_k = 1.0 + (real_T)c2_e_k;
    c2_i853 = c2_r13->size[0];
    c2_r13->size[0] = c2_stats->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)c2_f_k, 1, c2_stats->size[0]) - 1].PixelIdxList->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_r13, c2_i853,
      &c2_yg_emlrtRTEI);
    c2_j_loop_ub = c2_stats->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)c2_f_k, 1, c2_stats->size[0]) - 1].PixelIdxList->size[0] - 1;
    for (c2_i860 = 0; c2_i860 <= c2_j_loop_ub; c2_i860++) {
      c2_r13->data[c2_i860] = c2_stats->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)c2_f_k, 1, c2_stats->size[0]) - 1].PixelIdxList->data[c2_i860];
    }

    c2_imageSize[0] = (real_T)c2_r13->size[0];
    c2_imageSize[1] = 1.0;
    for (c2_i868 = 0; c2_i868 < 2; c2_i868++) {
      c2_imageSize[c2_i868];
    }

    c2_i870 = c2_stats->size[0];
    c2_i872 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_f_k, 1, c2_i870) - 1;
    c2_i874 = c2_stats->data[c2_i872].PixelValues->size[0];
    c2_stats->data[c2_i872].PixelValues->size[0] = (int32_T)c2_imageSize[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_stats->data[c2_i872].
      PixelValues, c2_i874, &c2_dh_emlrtRTEI);
    c2_i879 = c2_regionIndices->size[0];
    c2_regionIndices->size[0] = c2_stats->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)c2_f_k, 1, c2_stats->size[0]) - 1].PixelIdxList->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_regionIndices, c2_i879,
      &c2_fh_emlrtRTEI);
    c2_n_loop_ub = c2_stats->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)c2_f_k, 1, c2_stats->size[0]) - 1].PixelIdxList->size[0] - 1;
    for (c2_i883 = 0; c2_i883 <= c2_n_loop_ub; c2_i883++) {
      c2_regionIndices->data[c2_i883] = c2_stats->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)c2_f_k, 1, c2_stats->size[0]) - 1].PixelIdxList->data[c2_i883];
    }

    c2_i886 = c2_regionLengths->size[0];
    c2_regionLengths->size[0] = c2_regionIndices->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_regionLengths, c2_i886,
      &c2_ah_emlrtRTEI);
    c2_r_loop_ub = c2_regionIndices->size[0] - 1;
    for (c2_i891 = 0; c2_i891 <= c2_r_loop_ub; c2_i891++) {
      c2_regionLengths->data[c2_i891] = (int32_T)c2_regionIndices->data[c2_i891];
    }

    c2_i892 = c2_c_regionLengths->size[0];
    c2_c_regionLengths->size[0] = c2_regionLengths->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_c_regionLengths, c2_i892,
      &c2_ch_emlrtRTEI);
    c2_t_loop_ub = c2_regionLengths->size[0] - 1;
    for (c2_i896 = 0; c2_i896 <= c2_t_loop_ub; c2_i896++) {
      c2_c_regionLengths->data[c2_i896] = c2_regionLengths->data[c2_i896];
    }

    if (c2_b_allinrange(chartInstance, c2_c_regionLengths, 1.0, 19200)) {
    } else {
      c2_i_y = NULL;
      sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_cv57, 10, 0U, 1U, 0U, 2, 1,
        36), false);
      c2_j_y = NULL;
      sf_mex_assign(&c2_j_y, sf_mex_create("y", c2_cv57, 10, 0U, 1U, 0U, 2, 1,
        36), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_i_y,
                        14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "message", 1U, 1U, 14, c2_j_y)));
    }

    c2_i900 = c2_regionLengths->size[0];
    c2_regionLengths->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_regionLengths, c2_i900,
      &c2_gh_emlrtRTEI);
    c2_w_loop_ub = c2_regionLengths->size[0] - 1;
    for (c2_i905 = 0; c2_i905 <= c2_w_loop_ub; c2_i905++) {
      c2_regionLengths->data[c2_i905]--;
    }

    c2_i908 = c2_idxCount->size[0];
    c2_idxCount->size[0] = c2_regionLengths->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_idxCount, c2_i908,
      &c2_ih_emlrtRTEI);
    c2_y_loop_ub = c2_regionLengths->size[0] - 1;
    for (c2_i911 = 0; c2_i911 <= c2_y_loop_ub; c2_i911++) {
      c2_idxCount->data[c2_i911] = c2_div_nzp_s32(chartInstance,
        c2_regionLengths->data[c2_i911], 120, 0, 1U, 0, 0);
    }

    c2_i914 = c2_varargout_4->size[0];
    c2_varargout_4->size[0] = c2_idxCount->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_varargout_4, c2_i914,
      &c2_jh_emlrtRTEI);
    c2_cb_loop_ub = c2_idxCount->size[0] - 1;
    for (c2_i917 = 0; c2_i917 <= c2_cb_loop_ub; c2_i917++) {
      c2_varargout_4->data[c2_i917] = c2_idxCount->data[c2_i917] + 1;
    }

    c2_i919 = c2_idxCount->size[0];
    c2_idxCount->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_idxCount, c2_i919,
      &c2_lh_emlrtRTEI);
    c2_fb_loop_ub = c2_idxCount->size[0] - 1;
    for (c2_i922 = 0; c2_i922 <= c2_fb_loop_ub; c2_i922++) {
      c2_idxCount->data[c2_i922] *= 120;
    }

    c2_i924 = c2_regionLengths->size[0];
    c2_regionLengths->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_regionLengths, c2_i924,
      &c2_mh_emlrtRTEI);
    c2_hb_loop_ub = c2_regionLengths->size[0] - 1;
    for (c2_i926 = 0; c2_i926 <= c2_hb_loop_ub; c2_i926++) {
      c2_regionLengths->data[c2_i926] -= c2_idxCount->data[c2_i926];
    }

    c2_i928 = c2_regionLengths->size[0];
    c2_regionLengths->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_regionLengths, c2_i928,
      &c2_nh_emlrtRTEI);
    c2_jb_loop_ub = c2_regionLengths->size[0] - 1;
    for (c2_i929 = 0; c2_i929 <= c2_jb_loop_ub; c2_i929++) {
      c2_regionLengths->data[c2_i929]++;
    }

    c2_i930 = c2_regionIndices->size[0];
    c2_regionIndices->size[0] = c2_regionLengths->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_regionIndices, c2_i930,
      &c2_oh_emlrtRTEI);
    c2_kb_loop_ub = c2_regionLengths->size[0] - 1;
    for (c2_i931 = 0; c2_i931 <= c2_kb_loop_ub; c2_i931++) {
      c2_regionIndices->data[c2_i931] = (real_T)c2_regionLengths->data[c2_i931];
    }

    c2_i932 = c2_c->size[0];
    c2_c->size[0] = c2_varargout_4->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_c, c2_i932, &c2_oh_emlrtRTEI);
    c2_lb_loop_ub = c2_varargout_4->size[0] - 1;
    for (c2_i934 = 0; c2_i934 <= c2_lb_loop_ub; c2_i934++) {
      c2_c->data[c2_i934] = (real_T)c2_varargout_4->data[c2_i934];
    }

    c2_i936 = c2_r13->size[0];
    c2_r13->size[0] = c2_stats->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)c2_f_k, 1, c2_stats->size[0]) - 1].PixelValues->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_r13, c2_i936,
      &c2_ph_emlrtRTEI);
    c2_nb_loop_ub = c2_stats->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)c2_f_k, 1, c2_stats->size[0]) - 1].PixelValues->size[0] - 1;
    for (c2_i938 = 0; c2_i938 <= c2_nb_loop_ub; c2_i938++) {
      c2_r13->data[c2_i938] = c2_stats->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)c2_f_k, 1, c2_stats->size[0]) - 1].PixelValues->data[c2_i938];
    }

    c2_d26 = (real_T)c2_r13->size[0];
    c2_i940 = (int32_T)c2_d26 - 1;
    for (c2_b_idx = 0; c2_b_idx <= c2_i940; c2_b_idx++) {
      c2_c_idx = 1.0 + (real_T)c2_b_idx;
      c2_i943 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_f_k, 1,
        c2_stats->size[0]) - 1;
      c2_b_stats[0] = c2_stats->data[c2_i943].PixelValues->size[0];
      c2_b_stats[1] = 1;
      c2_stats->data[c2_i943].PixelValues->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)c2_c_idx, 1, c2_stats->data[c2_i943].PixelValues->size[0]) - 1]
        = c2_varargin_2[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)
        c2_regionIndices->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)c2_c_idx, 1, c2_regionIndices->size[0]) - 1], 1, 120) + 120 *
                         (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_c->
        data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_c_idx, 1,
        c2_c->size[0]) - 1], 1, 160) - 1)) - 1];
    }

    c2_e_k++;
  }

  c2_emxFree_int32_T(chartInstance, &c2_c_regionLengths);
  c2_emxFree_int32_T(chartInstance, &c2_varargout_4);
  c2_emxFree_real_T(chartInstance, &c2_c);
  c2_emxFree_int32_T(chartInstance, &c2_idxCount);
  c2_emxFree_int32_T(chartInstance, &c2_regionLengths);
  c2_h_varargin_2 = c2_stats->size[0];
  c2_i_varargin_2 = c2_h_varargin_2;
  c2_d24 = (real_T)c2_i_varargin_2;
  c2_i865 = (int32_T)c2_d24 - 1;
  c2_j_k = 0;
  c2_emxInit_real_T(chartInstance, &c2_r14, 2, &c2_ai_emlrtRTEI);
  c2_emxInit_real_T1(chartInstance, &c2_b_regionIndices, 1, &c2_eh_emlrtRTEI);
  c2_emxInit_real_T1(chartInstance, &c2_r15, 1, &c2_kh_emlrtRTEI);
  while (c2_j_k <= c2_i865) {
    c2_l_k = 1.0 + (real_T)c2_j_k;
    c2_i878 = c2_regionIndices->size[0];
    c2_regionIndices->size[0] = c2_stats->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)c2_l_k, 1, c2_stats->size[0]) - 1].PixelValues->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_regionIndices, c2_i878,
      &c2_bh_emlrtRTEI);
    c2_m_loop_ub = c2_stats->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)c2_l_k, 1, c2_stats->size[0]) - 1].PixelValues->size[0] - 1;
    for (c2_i882 = 0; c2_i882 <= c2_m_loop_ub; c2_i882++) {
      c2_regionIndices->data[c2_i882] = c2_stats->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)c2_l_k, 1, c2_stats->size[0]) - 1].PixelValues->data[c2_i882];
    }

    c2_i885 = c2_b_regionIndices->size[0];
    c2_b_regionIndices->size[0] = c2_regionIndices->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_b_regionIndices, c2_i885,
      &c2_eh_emlrtRTEI);
    c2_q_loop_ub = c2_regionIndices->size[0] - 1;
    for (c2_i890 = 0; c2_i890 <= c2_q_loop_ub; c2_i890++) {
      c2_b_regionIndices->data[c2_i890] = c2_regionIndices->data[c2_i890];
    }

    c2_sumIntensity = c2_b_sum(chartInstance, c2_b_regionIndices);
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_l_k, 1,
      c2_stats->size[0]);
    for (c2_b_n = 0; c2_b_n < 2; c2_b_n++) {
      c2_c_n = 1.0 + (real_T)c2_b_n;
      c2_i898 = c2_r14->size[0] * c2_r14->size[1];
      c2_r14->size[0] = c2_stats->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)c2_l_k, 1, c2_stats->size[0]) - 1].PixelList->size[0];
      c2_r14->size[1] = 2;
      c2_emxEnsureCapacity_real_T(chartInstance, c2_r14, c2_i898,
        &c2_kh_emlrtRTEI);
      c2_i902 = c2_r14->size[0];
      c2_i903 = c2_r14->size[1];
      c2_v_loop_ub = c2_stats->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)c2_l_k, 1, c2_stats->size[0]) - 1].PixelList->size[0] *
        c2_stats->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_l_k, 1,
        c2_stats->size[0]) - 1].PixelList->size[1] - 1;
      for (c2_i904 = 0; c2_i904 <= c2_v_loop_ub; c2_i904++) {
        c2_r14->data[c2_i904] = c2_stats->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           (int32_T)c2_l_k, 1, c2_stats->size[0]) - 1].PixelList->data[c2_i904];
      }

      c2_i907 = c2_r14->size[0] - 1;
      c2_d_n = (int32_T)c2_c_n - 1;
      c2_i910 = c2_r13->size[0];
      c2_r13->size[0] = c2_i907 + 1;
      c2_emxEnsureCapacity_real_T1(chartInstance, c2_r13, c2_i910,
        &c2_kh_emlrtRTEI);
      c2_bb_loop_ub = c2_i907;
      for (c2_i913 = 0; c2_i913 <= c2_bb_loop_ub; c2_i913++) {
        c2_r13->data[c2_i913] = c2_r14->data[c2_i913 + c2_r14->size[0] * c2_d_n];
      }

      _SFD_SIZE_EQ_CHECK_1D(c2_r13->size[0], c2_regionIndices->size[0]);
      c2_i916 = c2_r15->size[0];
      c2_r15->size[0] = c2_r13->size[0];
      c2_emxEnsureCapacity_real_T1(chartInstance, c2_r15, c2_i916,
        &c2_kh_emlrtRTEI);
      c2_eb_loop_ub = c2_r13->size[0] - 1;
      for (c2_i921 = 0; c2_i921 <= c2_eb_loop_ub; c2_i921++) {
        c2_r15->data[c2_i921] = c2_r13->data[c2_i921] * c2_regionIndices->
          data[c2_i921];
      }

      c2_M = c2_b_sum(chartInstance, c2_r15);
      c2_imageSize[(int32_T)c2_c_n - 1] = c2_M / c2_sumIntensity;
    }

    c2_i895 = c2_stats->size[0];
    for (c2_i897 = 0; c2_i897 < 2; c2_i897++) {
      c2_stats->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_l_k, 1, c2_i895) -
        1].WeightedCentroid[c2_i897] = c2_imageSize[c2_i897];
    }

    c2_j_k++;
  }

  c2_emxFree_real_T(chartInstance, &c2_r15);
  c2_emxFree_real_T(chartInstance, &c2_b_regionIndices);
  c2_emxFree_real_T(chartInstance, &c2_r13);
  c2_emxFree_real_T(chartInstance, &c2_r14);
  c2_emxFree_real_T(chartInstance, &c2_regionIndices);
  c2_j_varargin_2 = c2_stats->size[0];
  c2_k_varargin_2 = c2_j_varargin_2;
  c2_d25 = (real_T)c2_k_varargin_2;
  c2_i888 = (int32_T)c2_d25 - 1;
  for (c2_m_k = 0; c2_m_k <= c2_i888; c2_m_k++) {
    c2_n_k = 1.0 + (real_T)c2_m_k;
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_n_k, 1,
      c2_stats->size[0]);
    (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_n_k, 1,
      c2_outstats->size[0]);
    for (c2_vIdx = 0; c2_vIdx < 2; c2_vIdx++) {
      c2_b_vIdx = 1.0 + (real_T)c2_vIdx;
      c2_outstats->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_n_k, 1,
        c2_outstats->size[0]) - 1].WeightedCentroid[(int32_T)c2_b_vIdx - 1] =
        c2_stats->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_n_k, 1,
        c2_stats->size[0]) - 1].WeightedCentroid[(int32_T)c2_b_vIdx - 1];
    }
  }

  c2_emxFree_s9uuw2Xu7QLvohu1q5iD2hG(chartInstance, &c2_stats);
}

static void c2_bwconncomp(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_h_varargin_1[19200], c2_scIvRXQeSh8yxCxSmtD63bE *c2_CC)
{
  int32_T c2_numRuns;
  int32_T c2_col;
  c2_emxArray_int32_T *c2_regionLengths;
  real_T c2_b_col;
  c2_emxArray_int32_T *c2_startRow;
  c2_emxArray_int32_T *c2_endRow;
  c2_emxArray_int32_T *c2_startCol;
  int32_T c2_k;
  int32_T c2_i952;
  int32_T c2_i953;
  real_T c2_b_k;
  int32_T c2_i954;
  int32_T c2_i955;
  int32_T c2_i956;
  int32_T c2_i957;
  int32_T c2_i958;
  int32_T c2_runCounter;
  int32_T c2_c_col;
  c2_emxArray_int32_T *c2_labelsRenumbered;
  int32_T c2_i959;
  real_T c2_d_col;
  int32_T c2_i960;
  int32_T c2_i961;
  int32_T c2_row;
  int32_T c2_loop_ub;
  real_T c2_numComponents;
  int32_T c2_i962;
  int32_T c2_i963;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_i964;
  int32_T c2_c_k;
  int32_T c2_currentColumn;
  boolean_T c2_overflow;
  int32_T c2_nextLabel;
  int32_T c2_firstRunOnPreviousColumn;
  int32_T c2_lastRunOnPreviousColumn;
  int32_T c2_firstRunOnThisColumn;
  int32_T c2_d_k;
  int32_T c2_i965;
  int32_T c2_e_k;
  int32_T c2_b_loop_ub;
  int32_T c2_i966;
  int32_T c2_p;
  int32_T c2_c_b;
  int32_T c2_d_b;
  boolean_T c2_b_overflow;
  int32_T c2_f_k;
  int32_T c2_b_p;
  int32_T c2_g_k;
  int32_T c2_node;
  int32_T c2_root_k;
  int32_T c2_vlen;
  int32_T c2_b_idx;
  int32_T c2_b_node;
  int32_T c2_root_p;
  int32_T c2_b_vlen;
  real_T c2_c_y;
  int32_T c2_b_regionLengths[2];
  int32_T c2_e_b;
  c2_emxArray_real_T *c2_pixelIdxList;
  int32_T c2_f_b;
  c2_emxArray_int32_T *c2_d_x;
  int32_T c2_b_root_k;
  int32_T c2_iv15[1];
  int32_T c2_b_root_p;
  boolean_T c2_c_overflow;
  int32_T c2_i967;
  int32_T c2_h_k;
  int32_T c2_c_p;
  int32_T c2_i968;
  int32_T c2_i_k;
  int32_T c2_c_loop_ub;
  int32_T c2_xoffset;
  int32_T c2_i969;
  int32_T c2_ix;
  int32_T c2_dim;
  int32_T c2_varargin_3;
  c2_emxArray_int32_T *c2_idxCount;
  int32_T c2_varargin_2;
  int32_T c2_i970;
  int32_T c2_b_varargin_2;
  real_T c2_n;
  int32_T c2_nx;
  int32_T c2_d_loop_ub;
  int32_T c2_i971;
  int32_T c2_i972;
  int32_T c2_g_b;
  int32_T c2_h_b;
  int32_T c2_i_b;
  boolean_T c2_d_overflow;
  int32_T c2_j_b;
  boolean_T c2_e_overflow;
  int32_T c2_j_k;
  int32_T c2_k_k;
  int32_T c2_l_k;
  int32_T c2_l_a;
  int32_T c2_c;
  int32_T c2_i973;
  int32_T c2_m_a;
  int32_T c2_column_offset;
  int32_T c2_i974;
  int32_T c2_i975;
  int32_T c2_i976;
  int32_T c2_e_loop_ub;
  int32_T c2_n_a;
  int32_T c2_i977;
  int32_T c2_k_b;
  int32_T c2_o_a;
  int32_T c2_l_b;
  int32_T c2_i978;
  boolean_T c2_f_overflow;
  int32_T c2_f_loop_ub;
  int32_T c2_i979;
  int32_T c2_rowidx;
  int32_T c2_p_a;
  int32_T c2_b_c;
  int32_T c2_b_pixelIdxList[2];
  c2_numRuns = 0;
  for (c2_col = 0; c2_col < 160; c2_col++) {
    c2_b_col = 1.0 + (real_T)c2_col;
    if (c2_h_varargin_1[120 * ((int32_T)c2_b_col - 1)]) {
      c2_numRuns++;
    }

    for (c2_k = 0; c2_k < 119; c2_k++) {
      c2_b_k = 2.0 + (real_T)c2_k;
      if (c2_h_varargin_1[((int32_T)c2_b_k + 120 * ((int32_T)c2_b_col - 1)) - 1]
          && (!c2_h_varargin_1[((int32_T)(c2_b_k - 1.0) + 120 * ((int32_T)
             c2_b_col - 1)) - 1])) {
        c2_numRuns++;
      }
    }
  }

  c2_emxInit_int32_T(chartInstance, &c2_regionLengths, 1, &c2_hi_emlrtRTEI);
  c2_emxInit_int32_T(chartInstance, &c2_startRow, 1, &c2_oi_emlrtRTEI);
  c2_emxInit_int32_T(chartInstance, &c2_endRow, 1, &c2_pi_emlrtRTEI);
  c2_emxInit_int32_T(chartInstance, &c2_startCol, 1, &c2_qi_emlrtRTEI);
  if (c2_numRuns == 0) {
    c2_i953 = c2_startRow->size[0];
    c2_startRow->size[0] = 0;
    c2_i954 = c2_endRow->size[0];
    c2_endRow->size[0] = 0;
    c2_i956 = c2_startCol->size[0];
    c2_startCol->size[0] = 0;
    c2_i958 = c2_regionLengths->size[0];
    c2_regionLengths->size[0] = 0;
    c2_numRuns = 0;
  } else {
    c2_i952 = c2_startRow->size[0];
    c2_startRow->size[0] = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)
      c2_numRuns);
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_startRow, c2_i952,
      &c2_di_emlrtRTEI);
    c2_i955 = c2_endRow->size[0];
    c2_endRow->size[0] = c2_numRuns;
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_endRow, c2_i955,
      &c2_di_emlrtRTEI);
    c2_i957 = c2_startCol->size[0];
    c2_startCol->size[0] = c2_numRuns;
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_startCol, c2_i957,
      &c2_di_emlrtRTEI);
    c2_runCounter = 1;
    for (c2_c_col = 0; c2_c_col < 160; c2_c_col++) {
      c2_d_col = 1.0 + (real_T)c2_c_col;
      c2_row = 1;
      while (c2_row <= 120) {
        while ((c2_row <= 120) && (!c2_h_varargin_1[(c2_row + 120 * ((int32_T)
                  c2_d_col - 1)) - 1])) {
          c2_row++;
        }

        if ((c2_row <= 120) && c2_h_varargin_1[(c2_row + 120 * ((int32_T)
              c2_d_col - 1)) - 1]) {
          c2_startCol->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c2_runCounter, 1, c2_startCol->size[0]) - 1] =
            (int32_T)c2_d_col;
          c2_startRow->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c2_runCounter, 1, c2_startRow->size[0]) - 1] = c2_row;
          while ((c2_row <= 120) && c2_h_varargin_1[(c2_row + 120 * ((int32_T)
                   c2_d_col - 1)) - 1]) {
            c2_row++;
          }

          c2_endRow->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_runCounter, 1,
            c2_endRow->size[0]) - 1] = c2_row - 1;
          c2_runCounter++;
        }
      }
    }

    c2_i959 = c2_regionLengths->size[0];
    c2_regionLengths->size[0] = c2_numRuns;
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_regionLengths, c2_i959,
      &c2_fi_emlrtRTEI);
    c2_loop_ub = c2_numRuns - 1;
    for (c2_i963 = 0; c2_i963 <= c2_loop_ub; c2_i963++) {
      c2_regionLengths->data[c2_i963] = 0;
    }

    c2_c_k = 1;
    c2_currentColumn = 2;
    c2_nextLabel = 1;
    c2_firstRunOnPreviousColumn = -1;
    c2_lastRunOnPreviousColumn = 0;
    c2_firstRunOnThisColumn = 1;
    while (c2_c_k <= c2_numRuns) {
      if (c2_startCol->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c2_c_k, 1, c2_startCol->size[0]) - 1] == c2_currentColumn) {
        c2_firstRunOnPreviousColumn = c2_firstRunOnThisColumn;
        c2_firstRunOnThisColumn = c2_c_k;
        c2_lastRunOnPreviousColumn = c2_c_k;
        c2_currentColumn = c2_startCol->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c2_c_k, 1, c2_startCol->size[0]) - 1] + 1;
      } else {
        if (c2_startCol->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c2_c_k, 1, c2_startCol->size[0]) - 1] >
            c2_currentColumn) {
          c2_firstRunOnPreviousColumn = -1;
          c2_lastRunOnPreviousColumn = 0;
          c2_firstRunOnThisColumn = c2_c_k;
          c2_currentColumn = c2_startCol->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c2_c_k, 1, c2_startCol->size[0]) - 1] + 1;
        }
      }

      if (c2_firstRunOnPreviousColumn >= 0) {
        for (c2_p = c2_firstRunOnPreviousColumn; c2_p <
             c2_lastRunOnPreviousColumn; c2_p++) {
          if ((c2_endRow->data[sf_eml_array_bounds_check
               (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                MAX_uint32_T, c2_c_k, 1, c2_endRow->size[0]) - 1] >=
               c2_startRow->data[sf_eml_array_bounds_check
               (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                MAX_uint32_T, c2_p, 1, c2_startRow->size[0]) - 1] - 1) &&
              (c2_startRow->data[sf_eml_array_bounds_check
               (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                MAX_uint32_T, c2_c_k, 1, c2_startRow->size[0]) - 1] <=
               c2_endRow->data[sf_eml_array_bounds_check
               (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                MAX_uint32_T, c2_p, 1, c2_endRow->size[0]) - 1] + 1)) {
            if (c2_regionLengths->data[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                 MAX_uint32_T, c2_c_k, 1, c2_regionLengths->size[0]) - 1] == 0)
            {
              c2_regionLengths->data[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                 MAX_uint32_T, c2_c_k, 1, c2_regionLengths->size[0]) - 1] =
                c2_regionLengths->data[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                 MAX_uint32_T, c2_p, 1, c2_regionLengths->size[0]) - 1];
              c2_nextLabel++;
            } else {
              if (c2_regionLengths->data[sf_eml_array_bounds_check
                  (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                   MAX_uint32_T, c2_c_k, 1, c2_regionLengths->size[0]) - 1] !=
                  c2_regionLengths->data[sf_eml_array_bounds_check
                  (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                   MAX_uint32_T, c2_p, 1, c2_regionLengths->size[0]) - 1]) {
                c2_f_k = c2_c_k;
                c2_b_p = c2_p;
                c2_node = c2_f_k;
                c2_root_k = c2_node;
                while (c2_root_k != c2_regionLengths->
                       data[sf_eml_array_bounds_check
                       (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                        MAX_uint32_T, c2_root_k, 1, c2_regionLengths->size[0]) -
                       1]) {
                  c2_regionLengths->data[sf_eml_array_bounds_check
                    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                     MAX_uint32_T, c2_root_k, 1, c2_regionLengths->size[0]) - 1]
                    = c2_regionLengths->data[sf_eml_array_bounds_check
                    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                     MAX_uint32_T, c2_regionLengths->
                     data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_root_k, 1,
                      c2_regionLengths->size[0]) - 1], 1, c2_regionLengths->
                     size[0]) - 1];
                  c2_root_k = c2_regionLengths->data[sf_eml_array_bounds_check
                    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                     MAX_uint32_T, c2_root_k, 1, c2_regionLengths->size[0]) - 1];
                }

                c2_b_node = c2_b_p;
                c2_root_p = c2_b_node;
                while (c2_root_p != c2_regionLengths->
                       data[sf_eml_array_bounds_check
                       (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                        MAX_uint32_T, c2_root_p, 1, c2_regionLengths->size[0]) -
                       1]) {
                  c2_regionLengths->data[sf_eml_array_bounds_check
                    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                     MAX_uint32_T, c2_root_p, 1, c2_regionLengths->size[0]) - 1]
                    = c2_regionLengths->data[sf_eml_array_bounds_check
                    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                     MAX_uint32_T, c2_regionLengths->
                     data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_root_p, 1,
                      c2_regionLengths->size[0]) - 1], 1, c2_regionLengths->
                     size[0]) - 1];
                  c2_root_p = c2_regionLengths->data[sf_eml_array_bounds_check
                    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                     MAX_uint32_T, c2_root_p, 1, c2_regionLengths->size[0]) - 1];
                }

                if (c2_root_k != c2_root_p) {
                  c2_b_root_k = c2_root_k;
                  c2_b_root_p = c2_root_p;
                  c2_h_k = c2_f_k;
                  c2_c_p = c2_b_p;
                  if (c2_b_root_p < c2_b_root_k) {
                    c2_regionLengths->data[sf_eml_array_bounds_check
                      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                       MAX_uint32_T, c2_b_root_k, 1, c2_regionLengths->size[0])
                      - 1] = c2_b_root_p;
                    c2_regionLengths->data[sf_eml_array_bounds_check
                      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                       MAX_uint32_T, c2_h_k, 1, c2_regionLengths->size[0]) - 1] =
                      c2_b_root_p;
                  } else {
                    c2_regionLengths->data[sf_eml_array_bounds_check
                      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                       MAX_uint32_T, c2_b_root_p, 1, c2_regionLengths->size[0])
                      - 1] = c2_b_root_k;
                    c2_regionLengths->data[sf_eml_array_bounds_check
                      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                       MAX_uint32_T, c2_c_p, 1, c2_regionLengths->size[0]) - 1] =
                      c2_b_root_k;
                  }
                }
              }
            }
          }
        }
      }

      if (c2_regionLengths->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c2_c_k, 1, c2_regionLengths->size[0]) - 1] == 0) {
        c2_regionLengths->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c2_c_k, 1, c2_regionLengths->size[0]) - 1] = c2_nextLabel;
        c2_nextLabel++;
      }

      c2_c_k++;
    }
  }

  if (c2_numRuns == 0) {
    c2_CC->Connectivity = 8.0;
    for (c2_i961 = 0; c2_i961 < 2; c2_i961++) {
      c2_CC->ImageSize[c2_i961] = 120.0 + 40.0 * (real_T)c2_i961;
    }

    c2_CC->NumObjects = 0.0;
    c2_i962 = c2_CC->RegionIndices->size[0];
    c2_CC->RegionIndices->size[0] = 0;
    c2_i964 = c2_CC->RegionLengths->size[0];
    c2_CC->RegionLengths->size[0] = 1;
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_CC->RegionLengths, c2_i964,
      &c2_gi_emlrtRTEI);
    c2_CC->RegionLengths->data[0] = 0;
  } else {
    c2_emxInit_int32_T(chartInstance, &c2_labelsRenumbered, 1, &c2_mi_emlrtRTEI);
    c2_i960 = c2_labelsRenumbered->size[0];
    c2_labelsRenumbered->size[0] = c2_regionLengths->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_labelsRenumbered, c2_i960,
      &c2_ei_emlrtRTEI);
    c2_numComponents = 0.0;
    c2_b = c2_numRuns;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }

    for (c2_d_k = 1; c2_d_k - 1 < c2_numRuns; c2_d_k++) {
      c2_e_k = c2_d_k;
      if (c2_regionLengths->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c2_e_k, 1, c2_regionLengths->size[0]) - 1] == c2_e_k) {
        c2_numComponents++;
        c2_labelsRenumbered->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c2_e_k, 1, c2_labelsRenumbered->size[0]) - 1] = (int32_T)
          c2_numComponents;
      }

      c2_labelsRenumbered->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c2_e_k, 1, c2_labelsRenumbered->size[0]) - 1] =
        c2_labelsRenumbered->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c2_regionLengths->data[sf_eml_array_bounds_check
         (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
          c2_e_k, 1, c2_regionLengths->size[0]) - 1], 1,
         c2_labelsRenumbered->size[0]) - 1];
    }

    c2_i965 = c2_regionLengths->size[0];
    c2_regionLengths->size[0] = (int32_T)sf_integer_check(chartInstance->S, 1U,
      0U, 0U, c2_numComponents);
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_regionLengths, c2_i965,
      &c2_hi_emlrtRTEI);
    c2_b_loop_ub = (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
      c2_numComponents) - 1;
    for (c2_i966 = 0; c2_i966 <= c2_b_loop_ub; c2_i966++) {
      c2_regionLengths->data[c2_i966] = 0;
    }

    c2_c_b = c2_numRuns;
    c2_d_b = c2_c_b;
    if (1 > c2_d_b) {
      c2_b_overflow = false;
    } else {
      c2_b_overflow = (c2_d_b > 2147483646);
    }

    if (c2_b_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }

    for (c2_g_k = 1; c2_g_k - 1 < c2_numRuns; c2_g_k++) {
      c2_e_k = c2_g_k;
      c2_b_idx = c2_labelsRenumbered->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c2_e_k, 1, c2_labelsRenumbered->size[0]) - 1];
      if (c2_b_idx > 0) {
        c2_b_regionLengths[0] = c2_regionLengths->size[0];
        c2_b_regionLengths[1] = 1;
        c2_regionLengths->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c2_b_idx, 1, c2_regionLengths->size[0]) - 1] =
          ((c2_regionLengths->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c2_b_idx, 1, c2_regionLengths->size[0]) - 1] +
            c2_endRow->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c2_e_k, 1, c2_endRow->size[0]) - 1]) -
           c2_startRow->data[sf_eml_array_bounds_check
           (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
            MAX_uint32_T, c2_e_k, 1, c2_startRow->size[0]) - 1]) + 1;
      }
    }

    c2_vlen = c2_regionLengths->size[0];
    if ((c2_regionLengths->size[0] == 0) || (c2_vlen == 0)) {
      c2_c_y = 0.0;
    } else {
      c2_b_vlen = c2_vlen;
      c2_c_y = (real_T)c2_regionLengths->data[0];
      c2_e_b = c2_b_vlen;
      c2_f_b = c2_e_b;
      if (2 > c2_f_b) {
        c2_c_overflow = false;
      } else {
        c2_c_overflow = (c2_f_b > 2147483646);
      }

      if (c2_c_overflow) {
        c2_check_forloop_overflow_error(chartInstance, true);
      }

      for (c2_i_k = 2; c2_i_k <= c2_b_vlen; c2_i_k++) {
        c2_xoffset = c2_i_k;
        c2_ix = c2_xoffset - 1;
        c2_c_y += (real_T)c2_regionLengths->data[c2_ix];
      }
    }

    c2_emxInit_real_T1(chartInstance, &c2_pixelIdxList, 1, &c2_ni_emlrtRTEI);
    c2_emxInit_int32_T(chartInstance, &c2_d_x, 1, &c2_ii_emlrtRTEI);
    c2_iv15[0] = (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
      _SFD_NON_NEGATIVE_CHECK("", c2_c_y));
    c2_i967 = c2_pixelIdxList->size[0];
    c2_pixelIdxList->size[0] = c2_iv15[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_pixelIdxList, c2_i967,
      &c2_ei_emlrtRTEI);
    c2_i968 = c2_d_x->size[0];
    c2_d_x->size[0] = c2_regionLengths->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_d_x, c2_i968,
      &c2_ii_emlrtRTEI);
    c2_c_loop_ub = c2_regionLengths->size[0] - 1;
    for (c2_i969 = 0; c2_i969 <= c2_c_loop_ub; c2_i969++) {
      c2_d_x->data[c2_i969] = c2_regionLengths->data[c2_i969];
    }

    c2_dim = 2;
    if ((real_T)c2_d_x->size[0] != 1.0) {
      c2_dim = 1;
    }

    c2_varargin_3 = c2_dim;
    if ((1 == c2_varargin_3) && (!(c2_d_x->size[0] == 0))) {
      c2_varargin_2 = c2_d_x->size[0];
      c2_b_varargin_2 = c2_varargin_2;
      c2_n = (real_T)c2_b_varargin_2;
      c2_nx = (int32_T)c2_n - 2;
      if ((real_T)c2_d_x->size[0] == 1.0) {
      } else {
        c2_i971 = c2_nx;
        c2_g_b = c2_i971 + 1;
        c2_h_b = c2_g_b;
        if (1 > c2_h_b) {
          c2_d_overflow = false;
        } else {
          c2_d_overflow = (c2_h_b > 2147483646);
        }

        if (c2_d_overflow) {
          c2_check_forloop_overflow_error(chartInstance, true);
        }

        for (c2_j_k = 0; c2_j_k <= c2_i971; c2_j_k++) {
          c2_l_k = c2_j_k;
          c2_d_x->data[c2_l_k + 1] += c2_d_x->data[c2_l_k];
        }
      }
    }

    c2_emxInit_int32_T(chartInstance, &c2_idxCount, 1, &c2_ji_emlrtRTEI);
    c2_i970 = c2_idxCount->size[0];
    c2_idxCount->size[0] = 1 + c2_d_x->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_idxCount, c2_i970,
      &c2_ji_emlrtRTEI);
    c2_idxCount->data[0] = 0;
    c2_d_loop_ub = c2_d_x->size[0] - 1;
    for (c2_i972 = 0; c2_i972 <= c2_d_loop_ub; c2_i972++) {
      c2_idxCount->data[c2_i972 + 1] = c2_d_x->data[c2_i972];
    }

    c2_emxFree_int32_T(chartInstance, &c2_d_x);
    c2_i_b = c2_numRuns;
    c2_j_b = c2_i_b;
    if (1 > c2_j_b) {
      c2_e_overflow = false;
    } else {
      c2_e_overflow = (c2_j_b > 2147483646);
    }

    if (c2_e_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }

    for (c2_k_k = 1; c2_k_k - 1 < c2_numRuns; c2_k_k++) {
      c2_e_k = c2_k_k;
      c2_l_a = c2_startCol->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c2_e_k, 1, c2_startCol->size[0]) - 1];
      c2_c = c2_l_a;
      c2_m_a = c2_c - 1;
      c2_column_offset = c2_m_a * 120;
      c2_b_idx = c2_labelsRenumbered->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c2_e_k, 1, c2_labelsRenumbered->size[0]) - 1];
      if (c2_b_idx > 0) {
        c2_i975 = c2_startRow->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c2_e_k, 1, c2_startRow->size[0]) - 1];
        c2_i976 = c2_endRow->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c2_e_k, 1, c2_endRow->size[0]) - 1];
        c2_n_a = c2_i975;
        c2_k_b = c2_i976;
        c2_o_a = c2_n_a;
        c2_l_b = c2_k_b;
        if (c2_o_a > c2_l_b) {
          c2_f_overflow = false;
        } else {
          c2_f_overflow = (c2_l_b > 2147483646);
        }

        if (c2_f_overflow) {
          c2_check_forloop_overflow_error(chartInstance, true);
        }

        for (c2_rowidx = c2_i975; c2_rowidx <= c2_i976; c2_rowidx++) {
          c2_p_a = c2_idxCount->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c2_b_idx, 1, c2_idxCount->size[0]) - 1];
          c2_b_c = c2_p_a;
          c2_idxCount->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c2_b_idx, 1, c2_idxCount->size[0]) - 1] = c2_b_c + 1;
          c2_b_pixelIdxList[0] = c2_pixelIdxList->size[0];
          c2_b_pixelIdxList[1] = 1;
          c2_pixelIdxList->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c2_idxCount->data[sf_eml_array_bounds_check
             (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
              MAX_uint32_T, c2_b_idx, 1, c2_idxCount->size[0]) - 1], 1,
             c2_pixelIdxList->size[0]) - 1] = (real_T)(c2_rowidx +
            c2_column_offset);
        }
      }
    }

    c2_emxFree_int32_T(chartInstance, &c2_idxCount);
    c2_emxFree_int32_T(chartInstance, &c2_labelsRenumbered);
    c2_CC->Connectivity = 8.0;
    for (c2_i973 = 0; c2_i973 < 2; c2_i973++) {
      c2_CC->ImageSize[c2_i973] = 120.0 + 40.0 * (real_T)c2_i973;
    }

    c2_CC->NumObjects = c2_numComponents;
    c2_i974 = c2_CC->RegionIndices->size[0];
    c2_CC->RegionIndices->size[0] = c2_pixelIdxList->size[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_CC->RegionIndices, c2_i974,
      &c2_ki_emlrtRTEI);
    c2_e_loop_ub = c2_pixelIdxList->size[0] - 1;
    for (c2_i977 = 0; c2_i977 <= c2_e_loop_ub; c2_i977++) {
      c2_CC->RegionIndices->data[c2_i977] = c2_pixelIdxList->data[c2_i977];
    }

    c2_emxFree_real_T(chartInstance, &c2_pixelIdxList);
    c2_i978 = c2_CC->RegionLengths->size[0];
    c2_CC->RegionLengths->size[0] = c2_regionLengths->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_CC->RegionLengths, c2_i978,
      &c2_li_emlrtRTEI);
    c2_f_loop_ub = c2_regionLengths->size[0] - 1;
    for (c2_i979 = 0; c2_i979 <= c2_f_loop_ub; c2_i979++) {
      c2_CC->RegionLengths->data[c2_i979] = c2_regionLengths->data[c2_i979];
    }
  }

  c2_emxFree_int32_T(chartInstance, &c2_startCol);
  c2_emxFree_int32_T(chartInstance, &c2_endRow);
  c2_emxFree_int32_T(chartInstance, &c2_startRow);
  c2_emxFree_int32_T(chartInstance, &c2_regionLengths);
}

static void c2_assertValidSizeArg(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real_T c2_h_varargin_1)
{
  real_T c2_arg;
  real_T c2_d_x;
  boolean_T c2_b;
  boolean_T c2_p;
  real_T c2_b_arg;
  boolean_T c2_b60;
  boolean_T c2_b_p;
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv59[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I', 'n',
    'p', 'u', 't' };

  real_T c2_i_varargin_1;
  const mxArray *c2_d_y = NULL;
  real_T c2_n;
  int32_T c2_e_u;
  const mxArray *c2_e_y = NULL;
  const mxArray *c2_f_y = NULL;
  int32_T c2_f_u;
  static char_T c2_cv60[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'p', 'm', 'a', 'x', 's', 'i', 'z', 'e' };

  const mxArray *c2_g_y = NULL;
  const mxArray *c2_h_y = NULL;
  (void)chartInstance;
  c2_arg = c2_h_varargin_1;
  if (c2_arg != c2_arg) {
    c2_p = false;
  } else {
    c2_d_x = c2_arg;
    c2_b = muDoubleScalarIsInf(c2_d_x);
    if (c2_b) {
      c2_p = false;
    } else {
      c2_p = true;
    }
  }

  if (c2_p) {
    c2_b_arg = c2_h_varargin_1;
    if (c2_b_arg > 2.147483647E+9) {
      c2_b_p = false;
    } else {
      c2_b_p = true;
    }

    if (c2_b_p) {
      c2_b60 = true;
    } else {
      c2_b60 = false;
    }
  } else {
    c2_b60 = false;
  }

  if (c2_b60) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv59, 10, 0U, 1U, 0U, 2, 1, 28),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv59, 10, 0U, 1U, 0U, 2, 1, 28),
                  false);
    c2_e_u = MIN_int32_T;
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_e_u, 6, 0U, 0U, 0U, 0), false);
    c2_f_u = MAX_int32_T;
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 3U, 14, c2_d_y, 14, c2_e_y, 14, c2_g_y)));
  }

  c2_i_varargin_1 = c2_h_varargin_1;
  if (c2_i_varargin_1 <= 0.0) {
    c2_n = 0.0;
  } else {
    c2_n = c2_i_varargin_1;
  }

  if (c2_n <= 2.147483647E+9) {
  } else {
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv60, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    c2_h_y = NULL;
    sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv60, 10, 0U, 1U, 0U, 2, 1, 21),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_f_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_h_y)));
  }
}

static boolean_T c2_b_allinrange(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_d_x, real_T c2_lo, int32_T c2_hi)
{
  boolean_T c2_p;
  real_T c2_d27;
  int32_T c2_i980;
  int32_T c2_k;
  real_T c2_b_k;
  boolean_T c2_b61;
  int32_T exitg1;
  (void)chartInstance;
  (void)c2_lo;
  (void)c2_hi;
  c2_d27 = (real_T)c2_d_x->size[0];
  c2_i980 = (int32_T)c2_d27 - 1;
  c2_k = 0;
  do {
    exitg1 = 0;
    if (c2_k <= c2_i980) {
      c2_b_k = 1.0 + (real_T)c2_k;
      if ((real_T)c2_d_x->data[(int32_T)c2_b_k - 1] >= 1.0) {
        c2_b61 = true;
      } else {
        c2_b61 = false;
      }

      if (!c2_b61) {
        c2_p = false;
        exitg1 = 1;
      } else {
        c2_k++;
      }
    } else {
      c2_p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c2_p;
}

static real_T c2_b_sum(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_real_T *c2_d_x)
{
  real_T c2_c_y;
  boolean_T c2_b62;
  const mxArray *c2_d_y = NULL;
  int32_T c2_vlen;
  const mxArray *c2_e_y = NULL;
  int32_T c2_b_vlen;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_xoffset;
  int32_T c2_ix;
  if ((c2_d_x->size[0] == 1) || ((real_T)c2_d_x->size[0] != 1.0)) {
    c2_b62 = true;
  } else {
    c2_b62 = false;
  }

  if (c2_b62) {
  } else {
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv9, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv9, 10, 0U, 1U, 0U, 2, 1, 36),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_d_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_e_y)));
  }

  c2_vlen = c2_d_x->size[0];
  if ((c2_d_x->size[0] == 0) || (c2_vlen == 0)) {
    c2_c_y = 0.0;
  } else {
    c2_b_vlen = c2_vlen;
    c2_c_y = c2_d_x->data[0];
    c2_b = c2_b_vlen;
    c2_b_b = c2_b;
    if (2 > c2_b_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }

    for (c2_k = 2; c2_k <= c2_b_vlen; c2_k++) {
      c2_xoffset = c2_k;
      c2_ix = c2_xoffset - 1;
      c2_c_y += c2_d_x->data[c2_ix];
    }
  }

  return c2_c_y;
}

static void c2_b_sort(SFc2_flightControlSystemInstanceStruct *chartInstance,
                      c2_emxArray_real_T *c2_d_x, c2_emxArray_real_T *c2_e_x,
                      c2_emxArray_int32_T *c2_b_idx)
{
  int32_T c2_i981;
  int32_T c2_i982;
  int32_T c2_i983;
  int32_T c2_loop_ub;
  int32_T c2_i984;
  c2_i981 = c2_e_x->size[0] * c2_e_x->size[1];
  c2_e_x->size[0] = c2_d_x->size[0];
  c2_e_x->size[1] = 1;
  c2_emxEnsureCapacity_real_T(chartInstance, c2_e_x, c2_i981, &c2_kf_emlrtRTEI);
  c2_i982 = c2_e_x->size[0];
  c2_i983 = c2_e_x->size[1];
  c2_loop_ub = c2_d_x->size[0] * c2_d_x->size[1] - 1;
  for (c2_i984 = 0; c2_i984 <= c2_loop_ub; c2_i984++) {
    c2_e_x->data[c2_i984] = c2_d_x->data[c2_i984];
  }

  c2_d_sort(chartInstance, c2_e_x, c2_b_idx);
}

static void c2_b_merge_block(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real_T *c2_d_x,
  int32_T c2_offset, int32_T c2_n, int32_T c2_preSortLevel, c2_emxArray_int32_T *
  c2_b_iwork, c2_emxArray_real_T *c2_xwork, c2_emxArray_int32_T *c2_c_idx,
  c2_emxArray_real_T *c2_e_x, c2_emxArray_int32_T *c2_c_iwork,
  c2_emxArray_real_T *c2_b_xwork)
{
  int32_T c2_i985;
  int32_T c2_i986;
  int32_T c2_i987;
  int32_T c2_loop_ub;
  int32_T c2_i988;
  int32_T c2_i989;
  int32_T c2_i990;
  int32_T c2_i991;
  int32_T c2_b_loop_ub;
  int32_T c2_i992;
  int32_T c2_i993;
  int32_T c2_c_loop_ub;
  int32_T c2_i994;
  int32_T c2_i995;
  int32_T c2_d_loop_ub;
  int32_T c2_i996;
  c2_i985 = c2_c_idx->size[0] * c2_c_idx->size[1];
  c2_c_idx->size[0] = c2_b_idx->size[0];
  c2_c_idx->size[1] = 1;
  c2_emxEnsureCapacity_int32_T1(chartInstance, c2_c_idx, c2_i985,
    &c2_mf_emlrtRTEI);
  c2_i986 = c2_c_idx->size[0];
  c2_i987 = c2_c_idx->size[1];
  c2_loop_ub = c2_b_idx->size[0] * c2_b_idx->size[1] - 1;
  for (c2_i988 = 0; c2_i988 <= c2_loop_ub; c2_i988++) {
    c2_c_idx->data[c2_i988] = c2_b_idx->data[c2_i988];
  }

  c2_i989 = c2_e_x->size[0] * c2_e_x->size[1];
  c2_e_x->size[0] = c2_d_x->size[0];
  c2_e_x->size[1] = 1;
  c2_emxEnsureCapacity_real_T(chartInstance, c2_e_x, c2_i989, &c2_mf_emlrtRTEI);
  c2_i990 = c2_e_x->size[0];
  c2_i991 = c2_e_x->size[1];
  c2_b_loop_ub = c2_d_x->size[0] * c2_d_x->size[1] - 1;
  for (c2_i992 = 0; c2_i992 <= c2_b_loop_ub; c2_i992++) {
    c2_e_x->data[c2_i992] = c2_d_x->data[c2_i992];
  }

  c2_i993 = c2_c_iwork->size[0];
  c2_c_iwork->size[0] = c2_b_iwork->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_c_iwork, c2_i993,
    &c2_mf_emlrtRTEI);
  c2_c_loop_ub = c2_b_iwork->size[0] - 1;
  for (c2_i994 = 0; c2_i994 <= c2_c_loop_ub; c2_i994++) {
    c2_c_iwork->data[c2_i994] = c2_b_iwork->data[c2_i994];
  }

  c2_i995 = c2_b_xwork->size[0];
  c2_b_xwork->size[0] = c2_xwork->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_b_xwork, c2_i995,
    &c2_mf_emlrtRTEI);
  c2_d_loop_ub = c2_xwork->size[0] - 1;
  for (c2_i996 = 0; c2_i996 <= c2_d_loop_ub; c2_i996++) {
    c2_b_xwork->data[c2_i996] = c2_xwork->data[c2_i996];
  }

  c2_d_merge_block(chartInstance, c2_c_idx, c2_e_x, c2_offset, c2_n,
                   c2_preSortLevel, c2_c_iwork, c2_b_xwork);
}

static void c2_b_merge(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real_T *c2_d_x, int32_T c2_offset,
  int32_T c2_np, int32_T c2_nq, c2_emxArray_int32_T *c2_b_iwork,
  c2_emxArray_real_T *c2_xwork, c2_emxArray_int32_T *c2_c_idx,
  c2_emxArray_real_T *c2_e_x, c2_emxArray_int32_T *c2_c_iwork,
  c2_emxArray_real_T *c2_b_xwork)
{
  int32_T c2_i997;
  int32_T c2_i998;
  int32_T c2_i999;
  int32_T c2_loop_ub;
  int32_T c2_i1000;
  int32_T c2_i1001;
  int32_T c2_i1002;
  int32_T c2_i1003;
  int32_T c2_b_loop_ub;
  int32_T c2_i1004;
  int32_T c2_i1005;
  int32_T c2_c_loop_ub;
  int32_T c2_i1006;
  int32_T c2_i1007;
  int32_T c2_d_loop_ub;
  int32_T c2_i1008;
  c2_i997 = c2_c_idx->size[0] * c2_c_idx->size[1];
  c2_c_idx->size[0] = c2_b_idx->size[0];
  c2_c_idx->size[1] = 1;
  c2_emxEnsureCapacity_int32_T1(chartInstance, c2_c_idx, c2_i997,
    &c2_nf_emlrtRTEI);
  c2_i998 = c2_c_idx->size[0];
  c2_i999 = c2_c_idx->size[1];
  c2_loop_ub = c2_b_idx->size[0] * c2_b_idx->size[1] - 1;
  for (c2_i1000 = 0; c2_i1000 <= c2_loop_ub; c2_i1000++) {
    c2_c_idx->data[c2_i1000] = c2_b_idx->data[c2_i1000];
  }

  c2_i1001 = c2_e_x->size[0] * c2_e_x->size[1];
  c2_e_x->size[0] = c2_d_x->size[0];
  c2_e_x->size[1] = 1;
  c2_emxEnsureCapacity_real_T(chartInstance, c2_e_x, c2_i1001, &c2_nf_emlrtRTEI);
  c2_i1002 = c2_e_x->size[0];
  c2_i1003 = c2_e_x->size[1];
  c2_b_loop_ub = c2_d_x->size[0] * c2_d_x->size[1] - 1;
  for (c2_i1004 = 0; c2_i1004 <= c2_b_loop_ub; c2_i1004++) {
    c2_e_x->data[c2_i1004] = c2_d_x->data[c2_i1004];
  }

  c2_i1005 = c2_c_iwork->size[0];
  c2_c_iwork->size[0] = c2_b_iwork->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_c_iwork, c2_i1005,
    &c2_nf_emlrtRTEI);
  c2_c_loop_ub = c2_b_iwork->size[0] - 1;
  for (c2_i1006 = 0; c2_i1006 <= c2_c_loop_ub; c2_i1006++) {
    c2_c_iwork->data[c2_i1006] = c2_b_iwork->data[c2_i1006];
  }

  c2_i1007 = c2_b_xwork->size[0];
  c2_b_xwork->size[0] = c2_xwork->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_b_xwork, c2_i1007,
    &c2_nf_emlrtRTEI);
  c2_d_loop_ub = c2_xwork->size[0] - 1;
  for (c2_i1008 = 0; c2_i1008 <= c2_d_loop_ub; c2_i1008++) {
    c2_b_xwork->data[c2_i1008] = c2_xwork->data[c2_i1008];
  }

  c2_d_merge(chartInstance, c2_c_idx, c2_e_x, c2_offset, c2_np, c2_nq,
             c2_c_iwork, c2_b_xwork);
}

static boolean_T c2_c_all(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_boolean_T *c2_d_x)
{
  boolean_T c2_c_y;
  boolean_T c2_b63;
  const mxArray *c2_d_y = NULL;
  const mxArray *c2_e_y = NULL;
  real_T c2_vlen;
  real_T c2_l_a;
  int32_T c2_c;
  int32_T c2_m_a;
  int32_T c2_vspread;
  int32_T c2_b;
  int32_T c2_c_i2;
  int32_T c2_n_a;
  int32_T c2_b_b;
  int32_T c2_c_b;
  boolean_T c2_overflow;
  int32_T c2_ix;
  boolean_T exitg1;
  if ((c2_d_x->size[0] == 1) || ((real_T)c2_d_x->size[0] != 1.0)) {
    c2_b63 = true;
  } else {
    c2_b63 = false;
  }

  if (c2_b63) {
  } else {
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv7, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv7, 10, 0U, 1U, 0U, 2, 1, 51),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_d_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_e_y)));
  }

  c2_c_y = true;
  c2_vlen = (real_T)c2_d_x->size[0];
  c2_l_a = c2_vlen;
  c2_c = (int32_T)c2_l_a;
  c2_m_a = c2_c - 1;
  c2_vspread = c2_m_a;
  c2_b = c2_vspread;
  c2_c_i2 = c2_b;
  c2_n_a = c2_c_i2 + 1;
  c2_c_i2 = c2_n_a;
  c2_b_b = c2_c_i2;
  c2_c_b = c2_b_b;
  if (1 > c2_c_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_c_b > 2147483646);
  }

  if (c2_overflow) {
    c2_check_forloop_overflow_error(chartInstance, true);
  }

  c2_ix = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_ix + 1 <= c2_c_i2)) {
    if (!c2_d_x->data[c2_ix]) {
      c2_c_y = false;
      exitg1 = true;
    } else {
      c2_ix++;
    }
  }

  return c2_c_y;
}

static void c2_houghpeaks(SFc2_flightControlSystemInstanceStruct *chartInstance,
  real_T c2_h_varargin_1[71820], real_T c2_varargin_4, c2_emxArray_real_T
  *c2_peaks)
{
  real_T c2_b_varargin_4;
  int32_T c2_i1009;
  real_T c2_varargin_2;
  real_T c2_b_varargin_2;
  real_T c2_c_varargin_2;
  real_T c2_threshold;
  real_T c2_b_threshold;
  real_T c2_c_threshold;
  real_T c2_l_a;
  real_T c2_m_a;
  real_T c2_n_a;
  boolean_T c2_p;
  real_T c2_d_x;
  real_T c2_e_x;
  boolean_T c2_b;
  boolean_T c2_b_p;
  boolean_T c2_b64;
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv61[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o', 'u',
    'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  boolean_T c2_c_p;
  const mxArray *c2_d_y = NULL;
  int32_T c2_k;
  const mxArray *c2_e_y = NULL;
  static char_T c2_cv62[9] = { 'T', 'h', 'r', 'e', 's', 'h', 'o', 'l', 'd' };

  real_T c2_b_k;
  real_T c2_f_x;
  boolean_T c2_b65;
  real_T c2_g_x;
  boolean_T c2_b_b;
  boolean_T c2_b66;
  const mxArray *c2_f_y = NULL;
  real_T c2_h_x;
  int32_T c2_i1010;
  boolean_T c2_c_b;
  const mxArray *c2_g_y = NULL;
  boolean_T c2_b67;
  real_T c2_dv10[2];
  boolean_T c2_d_b;
  const mxArray *c2_h_y = NULL;
  boolean_T c2_b68;
  static char_T c2_cv63[9] = { 'N', 'H', 'o', 'o', 'd', 'S', 'i', 'z', 'e' };

  const mxArray *c2_i_y = NULL;
  boolean_T c2_d_p;
  const mxArray *c2_j_y = NULL;
  int32_T c2_c_k;
  const mxArray *c2_k_y = NULL;
  static char_T c2_cv64[9] = { 'N', 'H', 'o', 'o', 'd', 'S', 'i', 'z', 'e' };

  real_T c2_d_k;
  real_T c2_i_x;
  boolean_T c2_b69;
  boolean_T c2_e_p;
  const mxArray *c2_l_y = NULL;
  static char_T c2_cv65[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o', 'u',
    'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  boolean_T c2_f_p;
  const mxArray *c2_m_y = NULL;
  int32_T c2_e_k;
  const mxArray *c2_n_y = NULL;
  static char_T c2_cv66[9] = { 'N', 'H', 'o', 'o', 'd', 'S', 'i', 'z', 'e' };

  real_T c2_f_k;
  real_T c2_j_x;
  boolean_T c2_b70;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  const mxArray *c2_o_y = NULL;
  real_T c2_n_x;
  static char_T c2_cv67[29] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o', 'u',
    'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'O', 'd', 'd' };

  boolean_T c2_g_p;
  real_T c2_o_x;
  const mxArray *c2_p_y = NULL;
  int32_T c2_g_k;
  boolean_T c2_e_b;
  static char_T c2_cv68[43] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
    'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    'O', 'd', 'd' };

  const mxArray *c2_q_y = NULL;
  real_T c2_p_x;
  static char_T c2_cv69[9] = { 'N', 'H', 'o', 'o', 'd', 'S', 'i', 'z', 'e' };

  real_T c2_h_k;
  boolean_T c2_f_b;
  real_T c2_r;
  real_T c2_q_x;
  boolean_T c2_b71;
  real_T c2_r_x;
  boolean_T c2_h_p;
  boolean_T c2_g_b;
  boolean_T c2_rEQ0;
  boolean_T c2_b72;
  const mxArray *c2_r_y = NULL;
  real_T c2_s_x;
  int32_T c2_ixLead;
  boolean_T c2_h_b;
  const mxArray *c2_s_y = NULL;
  int32_T c2_iyLead;
  boolean_T c2_b73;
  real_T c2_work;
  boolean_T c2_i_b;
  const mxArray *c2_t_y = NULL;
  int32_T c2_m;
  static char_T c2_cv70[5] = { 'T', 'h', 'e', 't', 'a' };

  real_T c2_y1[179];
  real_T c2_t_x[178];
  real_T c2_tmp1;
  real_T c2_u_y;
  real_T c2_tmp2;
  int32_T c2_i_k;
  real_T c2_u_x;
  int32_T c2_xoffset;
  real_T c2_v_x;
  int32_T c2_ix;
  real_T c2_w_x;
  real_T c2_v_y;
  const mxArray *c2_w_y = NULL;
  static char_T c2_cv71[43] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'h', 'o', 'u',
    'g', 'h', 'p', 'e', 'a', 'k', 's', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'h', 'e', 't', 'a', 'V', 'e', 'c', 't', 'o', 'r', 'S', 'p', 'a', 'c',
    'i', 'n', 'g' };

  boolean_T c2_isDone;
  const mxArray *c2_x_y = NULL;
  int32_T c2_i1011;
  int32_T c2_peakIdx;
  real_T c2_ex;
  int32_T c2_j_k;
  real_T c2_minTheta;
  real_T c2_b_ex;
  int32_T c2_k_k;
  real_T c2_maxTheta;
  real_T c2_x_x;
  real_T c2_y_x;
  real_T c2_ab_x;
  real_T c2_y_y;
  real_T c2_thetaResolution;
  real_T c2_bb_x;
  real_T c2_cb_x;
  real_T c2_db_x;
  real_T c2_ab_y;
  boolean_T c2_isThetaAntisymmetric;
  int32_T c2_iPeak;
  int32_T c2_i1012;
  int32_T c2_i1013;
  int32_T c2_jPeak;
  int32_T c2_i1014;
  real_T c2_maxVal;
  int32_T c2_j;
  int32_T c2_i1015;
  int32_T c2_i1016;
  int32_T c2_b_j;
  int32_T c2_i1017;
  int32_T c2_i;
  int32_T c2_loop_ub;
  int32_T c2_b_i;
  int32_T c2_i1018;
  int32_T c2_rhoMin;
  real_T c2_val;
  int32_T c2_rhoMax;
  int32_T c2_thetaMin;
  int32_T c2_thetaMax;
  int32_T c2_o_a;
  int32_T c2_j_b;
  int32_T c2_p_a;
  int32_T c2_k_b;
  boolean_T c2_overflow;
  int32_T c2_theta;
  int32_T c2_q_a;
  int32_T c2_l_b;
  int32_T c2_r_a;
  int32_T c2_m_b;
  boolean_T c2_b_overflow;
  int32_T c2_rho;
  int32_T c2_rhoToRemove;
  int32_T c2_thetaToRemove;
  boolean_T exitg1;
  c2_b_varargin_4 = c2_varargin_4;
  for (c2_i1009 = 0; c2_i1009 < 71820; c2_i1009++) {
    chartInstance->c2_varargin_1[c2_i1009] = c2_h_varargin_1[c2_i1009];
  }

  c2_c_validateattributes(chartInstance, chartInstance->c2_varargin_1);
  c2_varargin_2 = c2_b_varargin_4;
  c2_b_varargin_2 = c2_varargin_2;
  c2_c_varargin_2 = c2_b_varargin_2;
  c2_threshold = c2_c_varargin_2;
  c2_b_threshold = c2_threshold;
  c2_c_threshold = c2_threshold;
  c2_l_a = c2_c_threshold;
  c2_m_a = c2_l_a;
  c2_n_a = c2_m_a;
  c2_p = true;
  c2_d_x = c2_n_a;
  c2_e_x = c2_d_x;
  c2_b = muDoubleScalarIsNaN(c2_e_x);
  c2_b_p = !c2_b;
  if (c2_b_p) {
  } else {
    c2_p = false;
  }

  if (c2_p) {
    c2_b64 = true;
  } else {
    c2_b64 = false;
  }

  if (c2_b64) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv61, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv8, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv62, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c2_d_y, 14, c2_e_y)));
  }

  c2_c_p = true;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k < 2)) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_f_x = 9.0 + -4.0 * (real_T)((int32_T)c2_b_k - 1);
    c2_g_x = c2_f_x;
    c2_b_b = muDoubleScalarIsInf(c2_g_x);
    c2_b66 = !c2_b_b;
    c2_h_x = c2_f_x;
    c2_c_b = muDoubleScalarIsNaN(c2_h_x);
    c2_b67 = !c2_c_b;
    c2_d_b = (c2_b66 && c2_b67);
    if (c2_d_b) {
      c2_k++;
    } else {
      c2_c_p = false;
      exitg1 = true;
    }
  }

  if (c2_c_p) {
    c2_b65 = true;
  } else {
    c2_b65 = false;
  }

  if (c2_b65) {
  } else {
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv11, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c2_h_y = NULL;
    sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv63, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_f_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c2_g_y, 14, c2_h_y)));
  }

  for (c2_i1010 = 0; c2_i1010 < 2; c2_i1010++) {
    c2_dv10[c2_i1010] = 9.0 + -4.0 * (real_T)c2_i1010;
  }

  if (c2_all(chartInstance, c2_dv10)) {
    c2_b68 = true;
  } else {
    c2_b68 = false;
  }

  if (c2_b68) {
  } else {
    c2_i_y = NULL;
    sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_cv12, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c2_j_y = NULL;
    sf_mex_assign(&c2_j_y, sf_mex_create("y", c2_cv6, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c2_k_y = NULL;
    sf_mex_assign(&c2_k_y, sf_mex_create("y", c2_cv64, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_i_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c2_j_y, 14, c2_k_y)));
  }

  c2_d_p = true;
  c2_c_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_c_k < 2)) {
    c2_d_k = 1.0 + (real_T)c2_c_k;
    c2_i_x = 9.0 + -4.0 * (real_T)((int32_T)c2_d_k - 1);
    c2_e_p = !(c2_i_x <= 0.0);
    if (c2_e_p) {
      c2_c_k++;
    } else {
      c2_d_p = false;
      exitg1 = true;
    }
  }

  if (c2_d_p) {
    c2_b69 = true;
  } else {
    c2_b69 = false;
  }

  if (c2_b69) {
  } else {
    c2_l_y = NULL;
    sf_mex_assign(&c2_l_y, sf_mex_create("y", c2_cv65, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    c2_m_y = NULL;
    sf_mex_assign(&c2_m_y, sf_mex_create("y", c2_cv5, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c2_n_y = NULL;
    sf_mex_assign(&c2_n_y, sf_mex_create("y", c2_cv66, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_l_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c2_m_y, 14, c2_n_y)));
  }

  c2_f_p = true;
  c2_e_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_e_k < 2)) {
    c2_f_k = 1.0 + (real_T)c2_e_k;
    c2_j_x = 9.0 + -4.0 * (real_T)((int32_T)c2_f_k - 1);
    c2_k_x = c2_j_x;
    c2_l_x = c2_k_x;
    c2_m_x = c2_l_x;
    c2_n_x = c2_m_x;
    c2_o_x = c2_n_x;
    c2_e_b = muDoubleScalarIsNaN(c2_o_x);
    if (c2_e_b) {
      c2_r = rtNaN;
    } else {
      c2_p_x = c2_n_x;
      c2_f_b = muDoubleScalarIsInf(c2_p_x);
      if (c2_f_b) {
        c2_r = rtNaN;
      } else {
        c2_r = muDoubleScalarRem(c2_n_x, 2.0);
        c2_rEQ0 = (c2_r == 0.0);
        if (c2_rEQ0) {
          c2_r = 0.0;
        }
      }
    }

    c2_h_p = (c2_r == 1.0);
    if (c2_h_p) {
      c2_e_k++;
    } else {
      c2_f_p = false;
      exitg1 = true;
    }
  }

  if (c2_f_p) {
    c2_b70 = true;
  } else {
    c2_b70 = false;
  }

  if (c2_b70) {
  } else {
    c2_o_y = NULL;
    sf_mex_assign(&c2_o_y, sf_mex_create("y", c2_cv67, 10, 0U, 1U, 0U, 2, 1, 29),
                  false);
    c2_p_y = NULL;
    sf_mex_assign(&c2_p_y, sf_mex_create("y", c2_cv68, 10, 0U, 1U, 0U, 2, 1, 43),
                  false);
    c2_q_y = NULL;
    sf_mex_assign(&c2_q_y, sf_mex_create("y", c2_cv69, 10, 0U, 1U, 0U, 2, 1, 9),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_o_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c2_p_y, 14, c2_q_y)));
  }

  c2_g_p = true;
  c2_g_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_g_k < 180)) {
    c2_h_k = 1.0 + (real_T)c2_g_k;
    c2_q_x = -90.0 + (real_T)((int32_T)c2_h_k - 1);
    c2_r_x = c2_q_x;
    c2_g_b = muDoubleScalarIsInf(c2_r_x);
    c2_b72 = !c2_g_b;
    c2_s_x = c2_q_x;
    c2_h_b = muDoubleScalarIsNaN(c2_s_x);
    c2_b73 = !c2_h_b;
    c2_i_b = (c2_b72 && c2_b73);
    if (c2_i_b) {
      c2_g_k++;
    } else {
      c2_g_p = false;
      exitg1 = true;
    }
  }

  if (c2_g_p) {
    c2_b71 = true;
  } else {
    c2_b71 = false;
  }

  if (c2_b71) {
  } else {
    c2_r_y = NULL;
    sf_mex_assign(&c2_r_y, sf_mex_create("y", c2_cv11, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    c2_s_y = NULL;
    sf_mex_assign(&c2_s_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c2_t_y = NULL;
    sf_mex_assign(&c2_t_y, sf_mex_create("y", c2_cv70, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_r_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c2_s_y, 14, c2_t_y)));
  }

  c2_ixLead = 1;
  c2_iyLead = 0;
  c2_work = -90.0;
  for (c2_m = 0; c2_m < 179; c2_m++) {
    c2_tmp1 = -90.0 + (real_T)c2_ixLead;
    c2_tmp2 = c2_work;
    c2_work = c2_tmp1;
    c2_tmp1 -= c2_tmp2;
    c2_ixLead++;
    c2_y1[c2_iyLead] = c2_tmp1;
    c2_iyLead++;
  }

  c2_diff(chartInstance, c2_y1, c2_t_x);
  c2_u_y = c2_t_x[0];
  for (c2_i_k = 0; c2_i_k < 177; c2_i_k++) {
    c2_xoffset = c2_i_k;
    c2_ix = c2_xoffset;
    c2_u_y += c2_t_x[c2_ix + 1];
  }

  c2_u_x = c2_u_y;
  c2_v_x = c2_u_x;
  c2_w_x = c2_v_x;
  c2_v_y = muDoubleScalarAbs(c2_w_x);
  if (!(c2_v_y > 1.4901161193847656E-8)) {
  } else {
    c2_w_y = NULL;
    sf_mex_assign(&c2_w_y, sf_mex_create("y", c2_cv71, 10, 0U, 1U, 0U, 2, 1, 43),
                  false);
    c2_x_y = NULL;
    sf_mex_assign(&c2_x_y, sf_mex_create("y", c2_cv71, 10, 0U, 1U, 0U, 2, 1, 43),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_w_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_x_y)));
  }

  c2_isDone = false;
  for (c2_i1011 = 0; c2_i1011 < 71820; c2_i1011++) {
    chartInstance->c2_hnew[c2_i1011] = c2_h_varargin_1[c2_i1011];
  }

  c2_peakIdx = 0;
  c2_ex = -90.0;
  for (c2_j_k = 1; c2_j_k + 1 < 181; c2_j_k++) {
    if (c2_ex > -90.0 + (real_T)c2_j_k) {
      c2_ex = -90.0 + (real_T)c2_j_k;
    }
  }

  c2_minTheta = c2_ex;
  c2_b_ex = -90.0;
  for (c2_k_k = 1; c2_k_k + 1 < 181; c2_k_k++) {
    if (c2_b_ex < -90.0 + (real_T)c2_k_k) {
      c2_b_ex = -90.0 + (real_T)c2_k_k;
    }
  }

  c2_maxTheta = c2_b_ex;
  c2_x_x = c2_maxTheta - c2_minTheta;
  c2_y_x = c2_x_x;
  c2_ab_x = c2_y_x;
  c2_y_y = muDoubleScalarAbs(c2_ab_x);
  c2_thetaResolution = c2_y_y / 179.0;
  c2_bb_x = c2_minTheta + c2_thetaResolution * 5.0;
  c2_cb_x = c2_bb_x;
  c2_db_x = c2_cb_x;
  c2_ab_y = muDoubleScalarAbs(c2_db_x);
  c2_isThetaAntisymmetric = (c2_ab_y <= c2_maxTheta);
  while (!c2_isDone) {
    c2_iPeak = 0;
    c2_jPeak = 0;
    c2_maxVal = -1.0;
    for (c2_j = 0; c2_j < 180; c2_j++) {
      c2_b_j = c2_j;
      for (c2_i = 0; c2_i < 399; c2_i++) {
        c2_b_i = c2_i;
        c2_val = chartInstance->c2_hnew[c2_b_i + 399 * c2_b_j];
        if (c2_val > c2_maxVal) {
          c2_iPeak = c2_b_i + 1;
          c2_jPeak = c2_b_j + 1;
          c2_maxVal = c2_val;
        }
      }
    }

    if (chartInstance->c2_hnew[(sf_eml_array_bounds_check
         (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
          c2_iPeak, 1, 399) + 399 * (sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c2_jPeak, 1, 180) - 1)) - 1] >= c2_b_threshold) {
      c2_peakIdx++;
      chartInstance->c2_peakCoordinates[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c2_peakIdx, 1, 71820) - 1] = (real_T)c2_iPeak;
      chartInstance->c2_peakCoordinates[c2_peakIdx + 71819] = (real_T)c2_jPeak;
      c2_rhoMin = c2_iPeak - 4;
      c2_rhoMax = c2_iPeak + 4;
      c2_thetaMin = c2_jPeak - 2;
      c2_thetaMax = c2_jPeak + 2;
      if (c2_rhoMin < 1) {
        c2_rhoMin = 1;
      }

      if (c2_rhoMax > 399) {
        c2_rhoMax = 399;
      }

      c2_o_a = c2_thetaMin;
      c2_j_b = c2_thetaMax;
      c2_p_a = c2_o_a;
      c2_k_b = c2_j_b;
      if (c2_p_a > c2_k_b) {
        c2_overflow = false;
      } else {
        c2_overflow = (c2_k_b > 2147483646);
      }

      if (c2_overflow) {
        c2_check_forloop_overflow_error(chartInstance, true);
      }

      for (c2_theta = c2_thetaMin; c2_theta <= c2_thetaMax; c2_theta++) {
        c2_q_a = c2_rhoMin;
        c2_l_b = c2_rhoMax;
        c2_r_a = c2_q_a;
        c2_m_b = c2_l_b;
        if (c2_r_a > c2_m_b) {
          c2_b_overflow = false;
        } else {
          c2_b_overflow = (c2_m_b > 2147483646);
        }

        if (c2_b_overflow) {
          c2_check_forloop_overflow_error(chartInstance, true);
        }

        for (c2_rho = c2_rhoMin; c2_rho <= c2_rhoMax; c2_rho++) {
          c2_rhoToRemove = c2_rho;
          c2_thetaToRemove = c2_theta;
          if (c2_isThetaAntisymmetric) {
            if (c2_theta > 180) {
              c2_rhoToRemove = 400 - c2_rho;
              c2_thetaToRemove = c2_theta - 180;
            } else {
              if (c2_theta < 1) {
                c2_rhoToRemove = 400 - c2_rho;
                c2_thetaToRemove = c2_theta + 180;
              }
            }
          }

          if ((c2_thetaToRemove > 180) || (c2_thetaToRemove < 1)) {
          } else {
            chartInstance->c2_hnew[(c2_rhoToRemove + 399 * (c2_thetaToRemove - 1))
              - 1] = 0.0;
          }
        }
      }

      c2_isDone = (c2_peakIdx == 5);
    } else {
      c2_isDone = true;
    }
  }

  if (c2_peakIdx == 0) {
    c2_i1013 = c2_peaks->size[0] * c2_peaks->size[1];
    c2_peaks->size[0] = 0;
    c2_peaks->size[1] = 0;
    c2_i1015 = c2_peaks->size[0];
    c2_i1016 = c2_peaks->size[1];
  } else {
    c2_i1012 = c2_peakIdx - 1;
    c2_i1014 = c2_peaks->size[0] * c2_peaks->size[1];
    c2_peaks->size[0] = c2_i1012 + 1;
    c2_peaks->size[1] = 2;
    c2_emxEnsureCapacity_real_T(chartInstance, c2_peaks, c2_i1014,
      &c2_ri_emlrtRTEI);
    for (c2_i1017 = 0; c2_i1017 < 2; c2_i1017++) {
      c2_loop_ub = c2_i1012;
      for (c2_i1018 = 0; c2_i1018 <= c2_loop_ub; c2_i1018++) {
        c2_peaks->data[c2_i1018 + c2_peaks->size[0] * c2_i1017] =
          chartInstance->c2_peakCoordinates[c2_i1018 + 71820 * c2_i1017];
      }
    }
  }
}

static void c2_c_validateattributes(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real_T c2_l_a[71820])
{
  boolean_T c2_p;
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_d_x;
  boolean_T c2_b74;
  real_T c2_e_x;
  boolean_T c2_b;
  boolean_T c2_b75;
  const mxArray *c2_c_y = NULL;
  real_T c2_f_x;
  boolean_T c2_b_p;
  boolean_T c2_b_b;
  const mxArray *c2_d_y = NULL;
  int32_T c2_c_k;
  boolean_T c2_b76;
  boolean_T c2_c_b;
  const mxArray *c2_e_y = NULL;
  static char_T c2_cv72[18] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '1', ',', ' ', 'H', ',' };

  real_T c2_d_k;
  real_T c2_g_x;
  boolean_T c2_b77;
  real_T c2_h_x;
  real_T c2_i_x;
  boolean_T c2_d_b;
  const mxArray *c2_f_y = NULL;
  boolean_T c2_b78;
  real_T c2_j_x;
  const mxArray *c2_g_y = NULL;
  boolean_T c2_e_b;
  boolean_T c2_b79;
  const mxArray *c2_h_y = NULL;
  boolean_T c2_f_b;
  static char_T c2_cv73[18] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '1', ',', ' ', 'H', ',' };

  real_T c2_k_x;
  boolean_T c2_c_p;
  real_T c2_l_x;
  boolean_T c2_d_p;
  boolean_T exitg1;
  (void)chartInstance;
  c2_p = true;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k < 71820)) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_d_x = c2_l_a[(int32_T)c2_b_k - 1];
    c2_e_x = c2_d_x;
    c2_b = muDoubleScalarIsInf(c2_e_x);
    c2_b75 = !c2_b;
    c2_f_x = c2_d_x;
    c2_b_b = muDoubleScalarIsNaN(c2_f_x);
    c2_b76 = !c2_b_b;
    c2_c_b = (c2_b75 && c2_b76);
    if (c2_c_b) {
      c2_k++;
    } else {
      c2_p = false;
      exitg1 = true;
    }
  }

  if (c2_p) {
    c2_b74 = true;
  } else {
    c2_b74 = false;
  }

  if (c2_b74) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv11, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 46),
                  false);
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv72, 10, 0U, 1U, 0U, 2, 1, 18),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c2_d_y, 14, c2_e_y)));
  }

  c2_b_p = true;
  c2_c_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_c_k < 71820)) {
    c2_d_k = 1.0 + (real_T)c2_c_k;
    c2_g_x = c2_l_a[(int32_T)c2_d_k - 1];
    c2_h_x = c2_g_x;
    c2_i_x = c2_h_x;
    c2_d_b = muDoubleScalarIsInf(c2_i_x);
    c2_b78 = !c2_d_b;
    c2_j_x = c2_h_x;
    c2_e_b = muDoubleScalarIsNaN(c2_j_x);
    c2_b79 = !c2_e_b;
    c2_f_b = (c2_b78 && c2_b79);
    if (c2_f_b) {
      c2_k_x = c2_g_x;
      c2_l_x = c2_k_x;
      c2_l_x = muDoubleScalarFloor(c2_l_x);
      if (c2_l_x == c2_g_x) {
        c2_c_p = true;
      } else {
        c2_c_p = false;
      }
    } else {
      c2_c_p = false;
    }

    c2_d_p = c2_c_p;
    if (c2_d_p) {
      c2_c_k++;
    } else {
      c2_b_p = false;
      exitg1 = true;
    }
  }

  if (c2_b_p) {
    c2_b77 = true;
  } else {
    c2_b77 = false;
  }

  if (c2_b77) {
  } else {
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv12, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_cv6, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c2_h_y = NULL;
    sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv73, 10, 0U, 1U, 0U, 2, 1, 18),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_f_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c2_g_y, 14, c2_h_y)));
  }
}

static void c2_diff(SFc2_flightControlSystemInstanceStruct *chartInstance,
                    real_T c2_d_x[179], real_T c2_c_y[178])
{
  int32_T c2_ixLead;
  int32_T c2_iyLead;
  real_T c2_work;
  int32_T c2_m;
  real_T c2_tmp1;
  real_T c2_tmp2;
  (void)chartInstance;
  c2_ixLead = 1;
  c2_iyLead = 0;
  c2_work = c2_d_x[0];
  for (c2_m = 0; c2_m < 178; c2_m++) {
    c2_tmp1 = c2_d_x[c2_ixLead];
    c2_tmp2 = c2_work;
    c2_work = c2_tmp1;
    c2_tmp1 -= c2_tmp2;
    c2_ixLead++;
    c2_c_y[c2_iyLead] = c2_tmp1;
    c2_iyLead++;
  }
}

static void c2_houghlines(SFc2_flightControlSystemInstanceStruct *chartInstance,
  boolean_T c2_h_varargin_1[19200], c2_emxArray_real_T *c2_varargin_4,
  c2_emxArray_skoeQIuVNKJRHNtBIlOCZh *c2_lines)
{
  c2_emxArray_real_T *c2_l_a;
  int32_T c2_i1019;
  int32_T c2_i1020;
  int32_T c2_i1021;
  int32_T c2_loop_ub;
  int32_T c2_i1022;
  boolean_T c2_p;
  real_T c2_d28;
  int32_T c2_i1023;
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_d_x;
  boolean_T c2_b_p;
  boolean_T c2_b80;
  const mxArray *c2_c_y = NULL;
  static char_T c2_cv74[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o', 'u',
    'g', 'h', 'l', 'i', 'n', 'e', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'P', 'o', 's', 'i', 't', 'i', 'v', 'e' };

  boolean_T c2_c_p;
  const mxArray *c2_d_y = NULL;
  real_T c2_d29;
  int32_T c2_i1024;
  const mxArray *c2_e_y = NULL;
  int32_T c2_c_k;
  static char_T c2_cv75[22] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '4', ',', ' ', 'P', 'E', 'A', 'K', 'S', ',' };

  real_T c2_d_k;
  real_T c2_e_x;
  boolean_T c2_b81;
  real_T c2_f_x;
  real_T c2_g_x;
  boolean_T c2_b;
  const mxArray *c2_f_y = NULL;
  boolean_T c2_b82;
  static char_T c2_cv76[33] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'h', 'o', 'u',
    'g', 'h', 'l', 'i', 'n', 'e', 's', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'I', 'n', 't', 'e', 'g', 'e', 'r' };

  real_T c2_h_x;
  const mxArray *c2_g_y = NULL;
  const mxArray *c2_h_y = NULL;
  boolean_T c2_b_b;
  static char_T c2_cv77[30] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'h', 'o', 'u',
    'g', 'h', 'l', 'i', 'n', 'e', 's', ':', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'P', 'E', 'A', 'K', 'S' };

  c2_emxArray_real_T *c2_peaks;
  boolean_T c2_b83;
  const mxArray *c2_i_y = NULL;
  const mxArray *c2_j_y = NULL;
  int32_T c2_i1025;
  boolean_T c2_c_b;
  static char_T c2_cv78[22] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', '4', ',', ' ', 'P', 'E', 'A', 'K', 'S', ',' };

  real_T c2_i_x;
  boolean_T c2_d_p;
  real_T c2_j_x;
  int32_T c2_i1026;
  int32_T c2_i1027;
  boolean_T c2_e_p;
  int32_T c2_b_loop_ub;
  int32_T c2_i1028;
  int32_T c2_numNonZero;
  int32_T c2_j;
  c2_emxArray_int32_T *c2_nonZeroPixels;
  real_T c2_b_j;
  int32_T c2_i1029;
  int32_T c2_i;
  real_T c2_b_i;
  real_T c2_e_k;
  int32_T c2_c_j;
  c2_emxArray_int32_T *c2_point1Array;
  c2_emxArray_int32_T *c2_point2Array;
  int32_T c2_c_i;
  c2_emxArray_real32_T *c2_thetaArray;
  c2_emxArray_real32_T *c2_rhoArray;
  int32_T c2_numLines;
  int32_T c2_i1030;
  int32_T c2_i1031;
  int32_T c2_i1032;
  int32_T c2_i1033;
  int32_T c2_i1034;
  int32_T c2_i1035;
  int32_T c2_i1036;
  int32_T c2_i1037;
  real_T c2_numPeaks;
  int32_T c2_i1038;
  int32_T c2_peakIdx;
  c2_emxArray_real_T *c2_indices;
  c2_emxArray_int32_T *c2_houghPix;
  c2_emxArray_int32_T *c2_rhoBinIdx;
  c2_emxArray_int32_T *c2_b_houghPix;
  c2_emxArray_real_T *c2_distances2;
  c2_emxArray_int32_T *c2_b_point1Array;
  c2_emxArray_int32_T *c2_b_point2Array;
  c2_emxArray_real32_T *c2_b_thetaArray;
  c2_emxArray_real32_T *c2_b_rhoArray;
  real_T c2_b_peakIdx;
  int32_T c2_peak1;
  int32_T c2_peak2;
  int32_T c2_b_peak1;
  int32_T c2_b_peak2;
  real_T c2_b_numNonZero;
  int32_T c2_i1039;
  int32_T c2_numHoughPix;
  real_T c2_thetaVal;
  c2_emxArray_boolean_T *c2_tile;
  real_T c2_k_x;
  int32_T c2_b_numLines;
  real_T c2_cosTheta;
  int32_T c2_c_numLines;
  int32_T c2_varargin_2;
  real_T c2_l_x;
  int32_T c2_i1040;
  real_T c2_sinTheta;
  int32_T c2_i1041;
  int32_T c2_f_k;
  int32_T c2_i1042;
  int32_T c2_i1043;
  int32_T c2_c_loop_ub;
  real_T c2_g_k;
  int32_T c2_i1044;
  int32_T c2_i1045;
  int32_T c2_i1046;
  real_T c2_rhoVal;
  real_T c2_m_x;
  int32_T c2_outsize[2];
  int32_T c2_k_y;
  int32_T c2_i1047;
  const mxArray *c2_l_y = NULL;
  real_T c2_n;
  int32_T c2_i1048;
  int32_T c2_i1049;
  int32_T c2_i1050;
  int32_T c2_h_k;
  real_T c2_b_numHoughPix;
  int32_T c2_i1051;
  c2_skoeQIuVNKJRHNtBIlOCZhD c2_s;
  int32_T c2_i1052;
  real_T c2_rowMax;
  real_T c2_rowMin;
  real_T c2_colMax;
  real_T c2_numPairs;
  int32_T c2_i1053;
  real_T c2_colMin;
  real_T c2_d30;
  int32_T c2_d_b;
  int32_T c2_i1054;
  int32_T c2_e_b;
  int32_T c2_i_k;
  int32_T c2_i1055;
  boolean_T c2_overflow;
  int32_T c2_i1056;
  int32_T c2_i1057;
  real_T c2_j_k;
  int32_T c2_d_loop_ub;
  int32_T c2_i1058;
  int32_T c2_k_k;
  int32_T c2_f_b;
  int32_T c2_g_b;
  real_T c2_b_n;
  int32_T c2_m_a;
  real_T c2_rowRange;
  int32_T c2_l_k;
  real_T c2_d31;
  int32_T c2_n_a;
  boolean_T c2_b_overflow;
  real_T c2_colRange;
  real_T c2_r;
  int32_T c2_i1059;
  int32_T c2_o_a;
  int32_T c2_m_k;
  int32_T c2_n_x;
  int32_T c2_i1060;
  int32_T c2_i1061;
  int32_T c2_p_a;
  int32_T c2_c;
  int32_T c2_n_k;
  real_T c2_sortingOrder[2];
  real_T c2_d32;
  int32_T c2_bu;
  real_T c2_b_c;
  int32_T c2_i1062;
  int32_T c2_i1063;
  int32_T c2_o_k;
  int32_T c2_p_k;
  int32_T c2_i1064;
  int32_T c2_iv16[1];
  real_T c2_q_k;
  int32_T c2_i1065;
  int32_T c2_i1066;
  int32_T c2_i1067;
  int32_T c2_q_a;
  int32_T c2_r_k;
  int32_T c2_i1068;
  int32_T c2_b_indices;
  int32_T c2_r_a;
  int32_T c2_i1069;
  int32_T c2_e_loop_ub;
  int32_T c2_point1_size[2];
  int32_T c2_s_a;
  int32_T c2_i1070;
  int32_T c2_o_x;
  int32_T c2_i1071;
  int32_T c2_f_loop_ub;
  int32_T c2_t_a;
  int32_T c2_iv17[1];
  int32_T c2_i1072;
  int32_T c2_c_c;
  int32_T c2_i1073;
  int32_T c2_b_bu;
  int32_T c2_s_k;
  int32_T c2_i1074;
  int32_T c2_point1_data[2];
  int32_T c2_i1075;
  int32_T c2_c_indices;
  int32_T c2_point2_size[2];
  int32_T c2_g_loop_ub;
  int32_T c2_i1076;
  int32_T c2_point2_data[2];
  int32_T c2_u_a;
  int32_T c2_v_a;
  int32_T c2_w_a;
  int32_T c2_p_x;
  int32_T c2_x_a;
  int32_T c2_d_c;
  int32_T c2_c_bu;
  int32_T c2_y_a;
  int32_T c2_ab_a;
  int32_T c2_bb_a;
  int32_T c2_q_x;
  int32_T c2_cb_a;
  int32_T c2_e_c;
  int32_T c2_d_bu;
  int32_T c2_lineLength2;
  int32_T c2_point1[1];
  int32_T c2_b_point1[1];
  int32_T c2_i1077;
  int32_T c2_i1078;
  int32_T c2_h_loop_ub;
  int32_T c2_i1079;
  int32_T c2_i1080;
  int32_T c2_i1081;
  int32_T c2_i1082;
  int32_T c2_i_loop_ub;
  int32_T c2_i1083;
  int32_T c2_point2[1];
  int32_T c2_b_point2[1];
  int32_T c2_i1084;
  int32_T c2_i1085;
  int32_T c2_j_loop_ub;
  int32_T c2_i1086;
  int32_T c2_i1087;
  int32_T c2_i1088;
  int32_T c2_i1089;
  int32_T c2_k_loop_ub;
  int32_T c2_i1090;
  int32_T c2_i1091;
  int32_T c2_l_loop_ub;
  int32_T c2_i1092;
  int32_T c2_i1093;
  int32_T c2_m_loop_ub;
  int32_T c2_i1094;
  int32_T c2_i1095;
  int32_T c2_n_loop_ub;
  int32_T c2_i1096;
  int32_T c2_i1097;
  int32_T c2_o_loop_ub;
  int32_T c2_i1098;
  boolean_T exitg1;
  int32_T exitg2;
  c2_emxInit_real_T(chartInstance, &c2_l_a, 2, &c2_si_emlrtRTEI);
  c2_i1019 = c2_l_a->size[0] * c2_l_a->size[1];
  c2_l_a->size[0] = c2_varargin_4->size[0];
  c2_l_a->size[1] = c2_varargin_4->size[1];
  c2_emxEnsureCapacity_real_T(chartInstance, c2_l_a, c2_i1019, &c2_si_emlrtRTEI);
  c2_i1020 = c2_l_a->size[0];
  c2_i1021 = c2_l_a->size[1];
  c2_loop_ub = c2_varargin_4->size[0] * c2_varargin_4->size[1] - 1;
  for (c2_i1022 = 0; c2_i1022 <= c2_loop_ub; c2_i1022++) {
    c2_l_a->data[c2_i1022] = c2_varargin_4->data[c2_i1022];
  }

  c2_p = true;
  c2_d28 = (real_T)(c2_l_a->size[0] * c2_l_a->size[1]);
  c2_i1023 = (int32_T)c2_d28 - 1;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k <= c2_i1023)) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_d_x = c2_l_a->data[(int32_T)c2_b_k - 1];
    c2_b_p = !(c2_d_x <= 0.0);
    if (c2_b_p) {
      c2_k++;
    } else {
      c2_p = false;
      exitg1 = true;
    }
  }

  c2_emxFree_real_T(chartInstance, &c2_l_a);
  if (c2_p) {
    c2_b80 = true;
  } else {
    c2_b80 = false;
  }

  if (c2_b80) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv74, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv5, 10, 0U, 1U, 0U, 2, 1, 48),
                  false);
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv75, 10, 0U, 1U, 0U, 2, 1, 22),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c2_d_y, 14, c2_e_y)));
  }

  c2_c_p = true;
  c2_d29 = (real_T)(c2_varargin_4->size[0] * c2_varargin_4->size[1]);
  c2_i1024 = (int32_T)c2_d29 - 1;
  c2_c_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_c_k <= c2_i1024)) {
    c2_d_k = 1.0 + (real_T)c2_c_k;
    c2_e_x = c2_varargin_4->data[(int32_T)c2_d_k - 1];
    c2_f_x = c2_e_x;
    c2_g_x = c2_f_x;
    c2_b = muDoubleScalarIsInf(c2_g_x);
    c2_b82 = !c2_b;
    c2_h_x = c2_f_x;
    c2_b_b = muDoubleScalarIsNaN(c2_h_x);
    c2_b83 = !c2_b_b;
    c2_c_b = (c2_b82 && c2_b83);
    if (c2_c_b) {
      c2_i_x = c2_e_x;
      c2_j_x = c2_i_x;
      c2_j_x = muDoubleScalarFloor(c2_j_x);
      if (c2_j_x == c2_e_x) {
        c2_d_p = true;
      } else {
        c2_d_p = false;
      }
    } else {
      c2_d_p = false;
    }

    c2_e_p = c2_d_p;
    if (c2_e_p) {
      c2_c_k++;
    } else {
      c2_c_p = false;
      exitg1 = true;
    }
  }

  if (c2_c_p) {
    c2_b81 = true;
  } else {
    c2_b81 = false;
  }

  if (c2_b81) {
  } else {
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv76, 10, 0U, 1U, 0U, 2, 1, 33),
                  false);
    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_cv6, 10, 0U, 1U, 0U, 2, 1, 47),
                  false);
    c2_i_y = NULL;
    sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_cv78, 10, 0U, 1U, 0U, 2, 1, 22),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_f_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 2U, 14, c2_g_y, 14, c2_i_y)));
  }

  if (!((real_T)c2_varargin_4->size[1] != 2.0)) {
  } else {
    c2_h_y = NULL;
    sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_cv77, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c2_j_y = NULL;
    sf_mex_assign(&c2_j_y, sf_mex_create("y", c2_cv77, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_h_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_j_y)));
  }

  c2_emxInit_real_T(chartInstance, &c2_peaks, 2, &c2_qj_emlrtRTEI);
  c2_i1025 = c2_peaks->size[0] * c2_peaks->size[1];
  c2_peaks->size[0] = c2_varargin_4->size[0];
  c2_peaks->size[1] = c2_varargin_4->size[1];
  c2_emxEnsureCapacity_real_T(chartInstance, c2_peaks, c2_i1025,
    &c2_ti_emlrtRTEI);
  c2_i1026 = c2_peaks->size[0];
  c2_i1027 = c2_peaks->size[1];
  c2_b_loop_ub = c2_varargin_4->size[0] * c2_varargin_4->size[1] - 1;
  for (c2_i1028 = 0; c2_i1028 <= c2_b_loop_ub; c2_i1028++) {
    c2_peaks->data[c2_i1028] = c2_varargin_4->data[c2_i1028];
  }

  c2_numNonZero = 0;
  for (c2_j = 0; c2_j < 160; c2_j++) {
    c2_b_j = 1.0 + (real_T)c2_j;
    for (c2_i = 0; c2_i < 120; c2_i++) {
      c2_b_i = 1.0 + (real_T)c2_i;
      c2_numNonZero += (int32_T)c2_h_varargin_1[((int32_T)c2_b_i + 120 *
        ((int32_T)c2_b_j - 1)) - 1];
    }
  }

  c2_emxInit_int32_T1(chartInstance, &c2_nonZeroPixels, 2, &c2_kj_emlrtRTEI);
  c2_i1029 = c2_nonZeroPixels->size[0] * c2_nonZeroPixels->size[1];
  c2_nonZeroPixels->size[0] = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)
    c2_numNonZero);
  c2_nonZeroPixels->size[1] = 2;
  c2_emxEnsureCapacity_int32_T1(chartInstance, c2_nonZeroPixels, c2_i1029,
    &c2_ui_emlrtRTEI);
  c2_e_k = 0.0;
  for (c2_c_j = 0; c2_c_j < 160; c2_c_j++) {
    c2_b_j = 1.0 + (real_T)c2_c_j;
    for (c2_c_i = 0; c2_c_i < 120; c2_c_i++) {
      c2_b_i = 1.0 + (real_T)c2_c_i;
      if (c2_h_varargin_1[((int32_T)c2_b_i + 120 * ((int32_T)c2_b_j - 1)) - 1])
      {
        c2_e_k++;
        c2_nonZeroPixels->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           (int32_T)c2_e_k, 1, c2_nonZeroPixels->size[0]) - 1] = (int32_T)
          (c2_b_j - 1.0);
        c2_nonZeroPixels->data[(sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           (int32_T)c2_e_k, 1, c2_nonZeroPixels->size[0]) +
          c2_nonZeroPixels->size[0]) - 1] = (int32_T)(c2_b_i - 1.0);
      }
    }
  }

  c2_emxInit_int32_T1(chartInstance, &c2_point1Array, 2, &c2_lj_emlrtRTEI);
  c2_emxInit_int32_T1(chartInstance, &c2_point2Array, 2, &c2_mj_emlrtRTEI);
  c2_emxInit_real32_T1(chartInstance, &c2_thetaArray, 1, &c2_nj_emlrtRTEI);
  c2_emxInit_real32_T1(chartInstance, &c2_rhoArray, 1, &c2_oj_emlrtRTEI);
  c2_numLines = 0;
  0;
  c2_i1030 = c2_point1Array->size[0] * c2_point1Array->size[1];
  c2_point1Array->size[0] = 0;
  c2_point1Array->size[1] = 2;
  c2_i1031 = c2_point1Array->size[0];
  c2_i1032 = c2_point1Array->size[1];
  0;
  c2_i1033 = c2_point2Array->size[0] * c2_point2Array->size[1];
  c2_point2Array->size[0] = 0;
  c2_point2Array->size[1] = 2;
  c2_i1034 = c2_point2Array->size[0];
  c2_i1035 = c2_point2Array->size[1];
  0;
  c2_i1036 = c2_thetaArray->size[0];
  c2_thetaArray->size[0] = 0;
  0;
  c2_i1037 = c2_rhoArray->size[0];
  c2_rhoArray->size[0] = 0;
  c2_numPeaks = (real_T)c2_peaks->size[0];
  c2_i1038 = (int32_T)c2_numPeaks - 1;
  c2_peakIdx = 0;
  c2_emxInit_real_T1(chartInstance, &c2_indices, 1, &c2_pj_emlrtRTEI);
  c2_emxInit_int32_T1(chartInstance, &c2_houghPix, 2, &c2_rj_emlrtRTEI);
  c2_emxInit_int32_T(chartInstance, &c2_rhoBinIdx, 1, &c2_sj_emlrtRTEI);
  c2_emxInit_int32_T1(chartInstance, &c2_b_houghPix, 2, &c2_tj_emlrtRTEI);
  c2_emxInit_real_T1(chartInstance, &c2_distances2, 1, &c2_uj_emlrtRTEI);
  c2_emxInit_int32_T1(chartInstance, &c2_b_point1Array, 2, &c2_cj_emlrtRTEI);
  c2_emxInit_int32_T1(chartInstance, &c2_b_point2Array, 2, &c2_ej_emlrtRTEI);
  c2_emxInit_real32_T1(chartInstance, &c2_b_thetaArray, 1, &c2_gj_emlrtRTEI);
  c2_emxInit_real32_T1(chartInstance, &c2_b_rhoArray, 1, &c2_ij_emlrtRTEI);
  while (c2_peakIdx <= c2_i1038) {
    c2_b_peakIdx = 1.0 + (real_T)c2_peakIdx;
    c2_peak1 = (int32_T)c2_peaks->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)c2_b_peakIdx, 1, c2_peaks->size[0]) - 1];
    c2_peak2 = (int32_T)c2_peaks->data[(sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)c2_b_peakIdx, 1, c2_peaks->size[0]) + c2_peaks->size[0]) - 1];
    c2_b_peak1 = c2_peak1;
    c2_b_peak2 = c2_peak2;
    c2_b_numNonZero = (real_T)c2_nonZeroPixels->size[0];
    c2_i1039 = c2_rhoBinIdx->size[0];
    c2_rhoBinIdx->size[0] = (int32_T)c2_b_numNonZero;
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_rhoBinIdx, c2_i1039,
      &c2_vi_emlrtRTEI);
    c2_numHoughPix = 0;
    c2_thetaVal = (-90.0 + (real_T)(sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       c2_b_peak2, 1, 180) - 1)) * 3.1415926535897931 / 180.0;
    c2_k_x = c2_thetaVal;
    c2_cosTheta = c2_k_x;
    c2_cosTheta = muDoubleScalarCos(c2_cosTheta);
    c2_l_x = c2_thetaVal;
    c2_sinTheta = c2_l_x;
    c2_sinTheta = muDoubleScalarSin(c2_sinTheta);
    c2_i1041 = (int32_T)c2_b_numNonZero - 1;
    for (c2_f_k = 0; c2_f_k <= c2_i1041; c2_f_k++) {
      c2_g_k = 1.0 + (real_T)c2_f_k;
      c2_rhoVal = (real_T)c2_nonZeroPixels->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)c2_g_k, 1, c2_nonZeroPixels->size[0]) - 1] * c2_cosTheta +
        (real_T)c2_nonZeroPixels->data[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)c2_g_k, 1, c2_nonZeroPixels->size[0]) + c2_nonZeroPixels->
        size[0]) - 1] * c2_sinTheta;
      c2_m_x = (c2_rhoVal - -199.0) + 1.0;
      c2_k_y = (int32_T)(c2_m_x + 0.5);
      c2_rhoBinIdx->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_g_k, 1,
        c2_rhoBinIdx->size[0]) - 1] = c2_k_y;
      if (c2_rhoBinIdx->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           (int32_T)c2_g_k, 1, c2_rhoBinIdx->size[0]) - 1] == c2_b_peak1) {
        c2_numHoughPix++;
      }
    }

    if (c2_numHoughPix < 1) {
      c2_i1046 = c2_houghPix->size[0] * c2_houghPix->size[1];
      c2_houghPix->size[0] = 0;
      c2_houghPix->size[1] = 0;
      c2_i1047 = c2_houghPix->size[0];
      c2_i1048 = c2_houghPix->size[1];
    } else {
      c2_i1045 = c2_b_houghPix->size[0] * c2_b_houghPix->size[1];
      c2_b_houghPix->size[0] = c2_numHoughPix;
      c2_b_houghPix->size[1] = 2;
      c2_emxEnsureCapacity_int32_T1(chartInstance, c2_b_houghPix, c2_i1045,
        &c2_vi_emlrtRTEI);
      c2_n = 0.0;
      c2_i1049 = (int32_T)c2_b_numNonZero - 1;
      for (c2_h_k = 0; c2_h_k <= c2_i1049; c2_h_k++) {
        c2_g_k = 1.0 + (real_T)c2_h_k;
        if (c2_rhoBinIdx->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, (int32_T)c2_g_k, 1, c2_rhoBinIdx->size[0]) - 1] ==
            c2_b_peak1) {
          c2_n++;
          c2_b_houghPix->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, (int32_T)c2_n, 1, c2_b_houghPix->size[0]) - 1] =
            c2_nonZeroPixels->data[(sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, (int32_T)c2_g_k, 1, c2_nonZeroPixels->size[0]) +
            c2_nonZeroPixels->size[0]) - 1] + 1;
          c2_b_houghPix->data[(sf_eml_array_bounds_check
                               (sfGlobalDebugInstanceStruct, chartInstance->S,
                                1U, 0, 0, MAX_uint32_T, (int32_T)c2_n, 1,
                                c2_b_houghPix->size[0]) + c2_b_houghPix->size[0])
            - 1] = c2_nonZeroPixels->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, (int32_T)c2_g_k, 1, c2_nonZeroPixels->size[0]) - 1] +
            1;
        }
      }

      c2_rowMax = 0.0;
      c2_rowMin = rtInf;
      c2_colMax = 0.0;
      c2_colMin = rtInf;
      c2_d_b = c2_numHoughPix;
      c2_e_b = c2_d_b;
      if (1 > c2_e_b) {
        c2_overflow = false;
      } else {
        c2_overflow = (c2_e_b > 2147483646);
      }

      if (c2_overflow) {
        c2_check_forloop_overflow_error(chartInstance, true);
      }

      for (c2_k_k = 1; c2_k_k - 1 < c2_numHoughPix; c2_k_k++) {
        c2_l_k = c2_k_k;
        c2_r = (real_T)c2_b_houghPix->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c2_l_k, 1, c2_b_houghPix->size[0]) - 1];
        if (c2_r > c2_rowMax) {
          c2_rowMax = c2_r;
        }

        if (c2_rowMin > c2_r) {
          c2_rowMin = c2_r;
        }

        c2_b_c = (real_T)c2_b_houghPix->data[(sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c2_l_k, 1, c2_b_houghPix->size[0]) + c2_b_houghPix->size[0]) - 1];
        if (c2_b_c > c2_colMax) {
          c2_colMax = c2_b_c;
        }

        if (c2_colMin > c2_b_c) {
          c2_colMin = c2_b_c;
        }
      }

      c2_rowRange = c2_rowMax - c2_rowMin;
      c2_colRange = c2_colMax - c2_colMin;
      if (c2_rowRange > c2_colRange) {
        for (c2_i1061 = 0; c2_i1061 < 2; c2_i1061++) {
          c2_sortingOrder[c2_i1061] = 1.0 + (real_T)c2_i1061;
        }
      } else {
        for (c2_i1060 = 0; c2_i1060 < 2; c2_i1060++) {
          c2_sortingOrder[c2_i1060] = 2.0 - (real_T)c2_i1060;
        }
      }

      c2_b_sortrows(chartInstance, c2_b_houghPix, c2_sortingOrder);
      c2_i1063 = c2_houghPix->size[0] * c2_houghPix->size[1];
      c2_houghPix->size[0] = c2_b_houghPix->size[0];
      c2_houghPix->size[1] = 2;
      c2_emxEnsureCapacity_int32_T1(chartInstance, c2_houghPix, c2_i1063,
        &c2_yi_emlrtRTEI);
      c2_i1066 = c2_houghPix->size[0];
      c2_i1068 = c2_houghPix->size[1];
      c2_e_loop_ub = c2_b_houghPix->size[0] * c2_b_houghPix->size[1] - 1;
      for (c2_i1070 = 0; c2_i1070 <= c2_e_loop_ub; c2_i1070++) {
        c2_houghPix->data[c2_i1070] = c2_b_houghPix->data[c2_i1070];
      }
    }

    if (c2_numHoughPix < 1) {
    } else {
      c2_b_numHoughPix = (real_T)c2_houghPix->size[0];
      c2_i1052 = c2_distances2->size[0];
      c2_distances2->size[0] = (int32_T)_SFD_NON_NEGATIVE_CHECK("",
        c2_b_numHoughPix - 1.0);
      c2_emxEnsureCapacity_real_T1(chartInstance, c2_distances2, c2_i1052,
        &c2_xi_emlrtRTEI);
      c2_numPairs = 0.0;
      c2_d30 = c2_b_numHoughPix - 1.0;
      c2_i1054 = (int32_T)c2_d30 - 1;
      for (c2_i_k = 0; c2_i_k <= c2_i1054; c2_i_k++) {
        c2_j_k = 1.0 + (real_T)c2_i_k;
        (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_houghPix->size[1]);
        (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_houghPix->size[1]);
        (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c2_houghPix->size[1]);
        (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c2_houghPix->size[1]);
        c2_m_a = c2_houghPix->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           (int32_T)(c2_j_k + 1.0), 1, c2_houghPix->size[0]) - 1] -
          c2_houghPix->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           (int32_T)c2_j_k, 1, c2_houghPix->size[0]) - 1];
        c2_n_a = c2_m_a;
        c2_o_a = c2_n_a;
        c2_n_x = c2_o_a;
        c2_p_a = c2_n_x;
        c2_c = 1;
        c2_bu = 2;
        do {
          exitg2 = 0;
          if ((c2_bu & 1) != 0) {
            c2_c *= c2_p_a;
          }

          c2_bu >>= 1;
          if (c2_bu == 0) {
            exitg2 = 1;
          } else {
            c2_p_a *= c2_p_a;
          }
        } while (exitg2 == 0);

        c2_q_a = c2_houghPix->data[(sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           (int32_T)(c2_j_k + 1.0), 1, c2_houghPix->size[0]) + c2_houghPix->
          size[0]) - 1] - c2_houghPix->data[(sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           (int32_T)c2_j_k, 1, c2_houghPix->size[0]) + c2_houghPix->size[0]) - 1];
        c2_r_a = c2_q_a;
        c2_s_a = c2_r_a;
        c2_o_x = c2_s_a;
        c2_t_a = c2_o_x;
        c2_c_c = 1;
        c2_b_bu = 2;
        do {
          exitg2 = 0;
          if ((c2_b_bu & 1) != 0) {
            c2_c_c *= c2_t_a;
          }

          c2_b_bu >>= 1;
          if (c2_b_bu == 0) {
            exitg2 = 1;
          } else {
            c2_t_a *= c2_t_a;
          }
        } while (exitg2 == 0);

        c2_distances2->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           (int32_T)c2_j_k, 1, c2_distances2->size[0]) - 1] = (real_T)(c2_c +
          c2_c_c);
        if (c2_distances2->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, (int32_T)c2_j_k, 1, c2_distances2->size[0]) - 1] >
            25.0) {
          c2_numPairs++;
        }
      }

      c2_i1057 = c2_indices->size[0];
      c2_indices->size[0] = (int32_T)sf_integer_check(chartInstance->S, 1U, 0U,
        0U, c2_numPairs + 2.0);
      c2_emxEnsureCapacity_real_T1(chartInstance, c2_indices, c2_i1057,
        &c2_xi_emlrtRTEI);
      c2_indices->data[0] = 0.0;
      c2_indices->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_indices->size[0], 1,
        c2_indices->size[0]) - 1] = c2_b_numHoughPix;
      c2_b_n = 1.0;
      c2_d31 = c2_b_numHoughPix - 1.0;
      c2_i1059 = (int32_T)c2_d31 - 1;
      for (c2_m_k = 0; c2_m_k <= c2_i1059; c2_m_k++) {
        c2_j_k = 1.0 + (real_T)c2_m_k;
        if (c2_distances2->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, (int32_T)c2_j_k, 1, c2_distances2->size[0]) - 1] >
            25.0) {
          c2_b_n++;
          c2_indices->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_b_n, 1,
            c2_indices->size[0]) - 1] = c2_j_k;
        }
      }

      c2_d32 = (real_T)c2_indices->size[0] - 1.0;
      c2_i1062 = (int32_T)c2_d32 - 1;
      for (c2_o_k = 0; c2_o_k <= c2_i1062; c2_o_k++) {
        c2_q_k = 1.0 + (real_T)c2_o_k;
        c2_i1067 = c2_houghPix->size[1] - 1;
        c2_b_indices = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(c2_indices->
          data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_q_k, 1,
          c2_indices->size[0]) - 1] + 1.0), 1, c2_houghPix->size[0]) - 1;
        c2_point1_size[0] = 1;
        c2_point1_size[1] = c2_i1067 + 1;
        c2_f_loop_ub = c2_i1067;
        for (c2_i1072 = 0; c2_i1072 <= c2_f_loop_ub; c2_i1072++) {
          c2_point1_data[c2_i1072] = c2_houghPix->data[c2_b_indices +
            c2_houghPix->size[0] * c2_i1072];
        }

        c2_i1074 = c2_houghPix->size[1] - 1;
        c2_c_indices = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)c2_indices->
          data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)(c2_q_k + 1.0), 1,
          c2_indices->size[0]) - 1], 1, c2_houghPix->size[0]) - 1;
        c2_point2_size[0] = 1;
        c2_point2_size[1] = c2_i1074 + 1;
        c2_g_loop_ub = c2_i1074;
        for (c2_i1076 = 0; c2_i1076 <= c2_g_loop_ub; c2_i1076++) {
          c2_point2_data[c2_i1076] = c2_houghPix->data[c2_c_indices +
            c2_houghPix->size[0] * c2_i1076];
        }

        (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_point2_size[1]);
        (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_point1_size[1]);
        (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c2_point2_size[1]);
        (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c2_point1_size[1]);
        c2_u_a = c2_point2_data[0] - c2_point1_data[0];
        c2_v_a = c2_u_a;
        c2_w_a = c2_v_a;
        c2_p_x = c2_w_a;
        c2_x_a = c2_p_x;
        c2_d_c = 1;
        c2_c_bu = 2;
        do {
          exitg2 = 0;
          if ((c2_c_bu & 1) != 0) {
            c2_d_c *= c2_x_a;
          }

          c2_c_bu >>= 1;
          if (c2_c_bu == 0) {
            exitg2 = 1;
          } else {
            c2_x_a *= c2_x_a;
          }
        } while (exitg2 == 0);

        c2_y_a = c2_point2_data[1] - c2_point1_data[1];
        c2_ab_a = c2_y_a;
        c2_bb_a = c2_ab_a;
        c2_q_x = c2_bb_a;
        c2_cb_a = c2_q_x;
        c2_e_c = 1;
        c2_d_bu = 2;
        do {
          exitg2 = 0;
          if ((c2_d_bu & 1) != 0) {
            c2_e_c *= c2_cb_a;
          }

          c2_d_bu >>= 1;
          if (c2_d_bu == 0) {
            exitg2 = 1;
          } else {
            c2_cb_a *= c2_cb_a;
          }
        } while (exitg2 == 0);

        c2_lineLength2 = c2_d_c + c2_e_c;
        if (c2_lineLength2 >= 100) {
          c2_numLines++;
          (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c2_point1_size[1]);
          (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_point1_size[1]);
          c2_point1[0] = c2_point1_size[1];
          c2_b_point1[0] = c2_point1_size[1];
          c2_i1077 = c2_b_point1Array->size[0] * c2_b_point1Array->size[1];
          c2_b_point1Array->size[0] = c2_point1Array->size[0] + 1;
          c2_b_point1Array->size[1] = 2;
          c2_emxEnsureCapacity_int32_T1(chartInstance, c2_b_point1Array,
            c2_i1077, &c2_cj_emlrtRTEI);
          for (c2_i1078 = 0; c2_i1078 < 2; c2_i1078++) {
            c2_h_loop_ub = c2_point1Array->size[0] - 1;
            for (c2_i1079 = 0; c2_i1079 <= c2_h_loop_ub; c2_i1079++) {
              c2_b_point1Array->data[c2_i1079 + c2_b_point1Array->size[0] *
                c2_i1078] = c2_point1Array->data[c2_i1079 + c2_point1Array->
                size[0] * c2_i1078];
            }
          }

          c2_b_point1Array->data[c2_point1Array->size[0]] = c2_point1_data[1];
          c2_b_point1Array->data[c2_point1Array->size[0] +
            c2_b_point1Array->size[0]] = c2_point1_data[0];
          c2_i1080 = c2_point1Array->size[0] * c2_point1Array->size[1];
          c2_point1Array->size[0] = c2_b_point1Array->size[0];
          c2_point1Array->size[1] = 2;
          c2_emxEnsureCapacity_int32_T1(chartInstance, c2_point1Array, c2_i1080,
            &c2_dj_emlrtRTEI);
          c2_i1081 = c2_point1Array->size[0];
          c2_i1082 = c2_point1Array->size[1];
          c2_i_loop_ub = c2_b_point1Array->size[0] * c2_b_point1Array->size[1] -
            1;
          for (c2_i1083 = 0; c2_i1083 <= c2_i_loop_ub; c2_i1083++) {
            c2_point1Array->data[c2_i1083] = c2_b_point1Array->data[c2_i1083];
          }

          (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, 2, 1, c2_point2_size[1]);
          (real_T)sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, 1, 1, c2_point2_size[1]);
          c2_point2[0] = c2_point2_size[1];
          c2_b_point2[0] = c2_point2_size[1];
          c2_i1084 = c2_b_point2Array->size[0] * c2_b_point2Array->size[1];
          c2_b_point2Array->size[0] = c2_point2Array->size[0] + 1;
          c2_b_point2Array->size[1] = 2;
          c2_emxEnsureCapacity_int32_T1(chartInstance, c2_b_point2Array,
            c2_i1084, &c2_ej_emlrtRTEI);
          for (c2_i1085 = 0; c2_i1085 < 2; c2_i1085++) {
            c2_j_loop_ub = c2_point2Array->size[0] - 1;
            for (c2_i1086 = 0; c2_i1086 <= c2_j_loop_ub; c2_i1086++) {
              c2_b_point2Array->data[c2_i1086 + c2_b_point2Array->size[0] *
                c2_i1085] = c2_point2Array->data[c2_i1086 + c2_point2Array->
                size[0] * c2_i1085];
            }
          }

          c2_b_point2Array->data[c2_point2Array->size[0]] = c2_point2_data[1];
          c2_b_point2Array->data[c2_point2Array->size[0] +
            c2_b_point2Array->size[0]] = c2_point2_data[0];
          c2_i1087 = c2_point2Array->size[0] * c2_point2Array->size[1];
          c2_point2Array->size[0] = c2_b_point2Array->size[0];
          c2_point2Array->size[1] = 2;
          c2_emxEnsureCapacity_int32_T1(chartInstance, c2_point2Array, c2_i1087,
            &c2_fj_emlrtRTEI);
          c2_i1088 = c2_point2Array->size[0];
          c2_i1089 = c2_point2Array->size[1];
          c2_k_loop_ub = c2_b_point2Array->size[0] * c2_b_point2Array->size[1] -
            1;
          for (c2_i1090 = 0; c2_i1090 <= c2_k_loop_ub; c2_i1090++) {
            c2_point2Array->data[c2_i1090] = c2_b_point2Array->data[c2_i1090];
          }

          c2_i1091 = c2_b_thetaArray->size[0];
          c2_b_thetaArray->size[0] = c2_thetaArray->size[0] + 1;
          c2_emxEnsureCapacity_real32_T1(chartInstance, c2_b_thetaArray,
            c2_i1091, &c2_gj_emlrtRTEI);
          c2_l_loop_ub = c2_thetaArray->size[0] - 1;
          for (c2_i1092 = 0; c2_i1092 <= c2_l_loop_ub; c2_i1092++) {
            c2_b_thetaArray->data[c2_i1092] = c2_thetaArray->data[c2_i1092];
          }

          c2_b_thetaArray->data[c2_thetaArray->size[0]] = (real32_T)(-90.0 +
            (real_T)(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_peak2, 1, 180) - 1));
          c2_i1093 = c2_thetaArray->size[0];
          c2_thetaArray->size[0] = c2_b_thetaArray->size[0];
          c2_emxEnsureCapacity_real32_T1(chartInstance, c2_thetaArray, c2_i1093,
            &c2_hj_emlrtRTEI);
          c2_m_loop_ub = c2_b_thetaArray->size[0] - 1;
          for (c2_i1094 = 0; c2_i1094 <= c2_m_loop_ub; c2_i1094++) {
            c2_thetaArray->data[c2_i1094] = c2_b_thetaArray->data[c2_i1094];
          }

          c2_i1095 = c2_b_rhoArray->size[0];
          c2_b_rhoArray->size[0] = c2_rhoArray->size[0] + 1;
          c2_emxEnsureCapacity_real32_T1(chartInstance, c2_b_rhoArray, c2_i1095,
            &c2_ij_emlrtRTEI);
          c2_n_loop_ub = c2_rhoArray->size[0] - 1;
          for (c2_i1096 = 0; c2_i1096 <= c2_n_loop_ub; c2_i1096++) {
            c2_b_rhoArray->data[c2_i1096] = c2_rhoArray->data[c2_i1096];
          }

          c2_b_rhoArray->data[c2_rhoArray->size[0]] = (real32_T)(-199.0 +
            (real_T)(c2_peak1 - 1));
          c2_i1097 = c2_rhoArray->size[0];
          c2_rhoArray->size[0] = c2_b_rhoArray->size[0];
          c2_emxEnsureCapacity_real32_T1(chartInstance, c2_rhoArray, c2_i1097,
            &c2_jj_emlrtRTEI);
          c2_o_loop_ub = c2_b_rhoArray->size[0] - 1;
          for (c2_i1098 = 0; c2_i1098 <= c2_o_loop_ub; c2_i1098++) {
            c2_rhoArray->data[c2_i1098] = c2_b_rhoArray->data[c2_i1098];
          }
        }
      }
    }

    c2_peakIdx++;
  }

  c2_emxFree_real32_T(chartInstance, &c2_b_rhoArray);
  c2_emxFree_real32_T(chartInstance, &c2_b_thetaArray);
  c2_emxFree_int32_T(chartInstance, &c2_b_point2Array);
  c2_emxFree_int32_T(chartInstance, &c2_b_point1Array);
  c2_emxFree_real_T(chartInstance, &c2_distances2);
  c2_emxFree_int32_T(chartInstance, &c2_b_houghPix);
  c2_emxFree_int32_T(chartInstance, &c2_rhoBinIdx);
  c2_emxFree_int32_T(chartInstance, &c2_houghPix);
  c2_emxFree_real_T(chartInstance, &c2_peaks);
  c2_emxFree_real_T(chartInstance, &c2_indices);
  c2_emxFree_int32_T(chartInstance, &c2_nonZeroPixels);
  c2_emxInit_boolean_T(chartInstance, &c2_tile, 2, &c2_qg_emlrtRTEI);
  c2_b_numLines = c2_numLines;
  c2_c_numLines = c2_b_numLines;
  c2_varargin_2 = c2_c_numLines;
  c2_i1040 = c2_tile->size[0] * c2_tile->size[1];
  c2_tile->size[0] = 1;
  c2_tile->size[1] = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c2_varargin_2);
  c2_emxEnsureCapacity_boolean_T(chartInstance, c2_tile, c2_i1040,
    &c2_qg_emlrtRTEI);
  c2_i1042 = c2_tile->size[0];
  c2_i1043 = c2_tile->size[1];
  c2_c_loop_ub = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c2_varargin_2) - 1;
  for (c2_i1044 = 0; c2_i1044 <= c2_c_loop_ub; c2_i1044++) {
    c2_tile->data[c2_i1044] = false;
  }

  c2_outsize[1] = c2_tile->size[1];
  if ((real_T)c2_outsize[1] == (real_T)c2_tile->size[1]) {
  } else {
    c2_l_y = NULL;
    sf_mex_assign(&c2_l_y, sf_mex_create("y", c2_cv10, 10, 0U, 1U, 0U, 2, 1, 15),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14, c2_l_y);
  }

  c2_emxFree_boolean_T(chartInstance, &c2_tile);
  for (c2_i1050 = 0; c2_i1050 < 2; c2_i1050++) {
    c2_s.point1[c2_i1050] = 0.0;
  }

  for (c2_i1051 = 0; c2_i1051 < 2; c2_i1051++) {
    c2_s.point2[c2_i1051] = 0.0;
  }

  c2_s.theta = 0.0;
  c2_s.rho = 0.0;
  c2_i1053 = c2_lines->size[0] * c2_lines->size[1];
  c2_lines->size[0] = 1;
  c2_lines->size[1] = c2_outsize[1];
  c2_emxEnsureCapacity_skoeQIuVNKJRH(chartInstance, c2_lines, c2_i1053,
    &c2_wi_emlrtRTEI);
  c2_i1055 = c2_lines->size[0];
  c2_i1056 = c2_lines->size[1];
  c2_d_loop_ub = c2_outsize[1] - 1;
  for (c2_i1058 = 0; c2_i1058 <= c2_d_loop_ub; c2_i1058++) {
    c2_lines->data[c2_i1058] = c2_s;
  }

  c2_f_b = c2_b_numLines;
  c2_g_b = c2_f_b;
  if (1 > c2_g_b) {
    c2_b_overflow = false;
  } else {
    c2_b_overflow = (c2_g_b > 2147483646);
  }

  if (c2_b_overflow) {
    c2_check_forloop_overflow_error(chartInstance, true);
  }

  for (c2_n_k = 1; c2_n_k - 1 < c2_b_numLines; c2_n_k++) {
    c2_p_k = c2_n_k;
    c2_i1064 = c2_lines->size[1];
    c2_iv16[0] = c2_i1064;
    c2_i1065 = c2_lines->size[1];
    c2_r_k = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_p_k, 1, c2_point1Array->size
      [0]) - 1;
    for (c2_i1069 = 0; c2_i1069 < 2; c2_i1069++) {
      c2_lines->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_p_k, 1, c2_i1065) - 1].
        point1[c2_i1069] = (real_T)c2_point1Array->data[c2_r_k +
        c2_point1Array->size[0] * c2_i1069];
    }

    c2_i1071 = c2_lines->size[1];
    c2_iv17[0] = c2_i1071;
    c2_i1073 = c2_lines->size[1];
    c2_s_k = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_p_k, 1, c2_point2Array->size
      [0]) - 1;
    for (c2_i1075 = 0; c2_i1075 < 2; c2_i1075++) {
      c2_lines->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_p_k, 1, c2_i1073) - 1].
        point2[c2_i1075] = (real_T)c2_point2Array->data[c2_s_k +
        c2_point2Array->size[0] * c2_i1075];
    }

    c2_lines->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_p_k, 1, c2_lines->size[1]) -
      1].theta = c2_thetaArray->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       c2_p_k, 1, c2_thetaArray->size[0]) - 1];
    c2_lines->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c2_p_k, 1, c2_lines->size[1]) -
      1].rho = c2_rhoArray->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       c2_p_k, 1, c2_rhoArray->size[0]) - 1];
  }

  c2_emxFree_real32_T(chartInstance, &c2_rhoArray);
  c2_emxFree_real32_T(chartInstance, &c2_thetaArray);
  c2_emxFree_int32_T(chartInstance, &c2_point2Array);
  c2_emxFree_int32_T(chartInstance, &c2_point1Array);
}

static void c2_sortrows(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_int32_T *c2_c_y, real_T c2_h_varargin_1[2], c2_emxArray_int32_T
  *c2_d_y)
{
  int32_T c2_i1099;
  int32_T c2_i1100;
  int32_T c2_i1101;
  int32_T c2_loop_ub;
  int32_T c2_i1102;
  int32_T c2_i1103;
  real_T c2_i_varargin_1[2];
  c2_i1099 = c2_d_y->size[0] * c2_d_y->size[1];
  c2_d_y->size[0] = c2_c_y->size[0];
  c2_d_y->size[1] = 2;
  c2_emxEnsureCapacity_int32_T1(chartInstance, c2_d_y, c2_i1099,
    &c2_vj_emlrtRTEI);
  c2_i1100 = c2_d_y->size[0];
  c2_i1101 = c2_d_y->size[1];
  c2_loop_ub = c2_c_y->size[0] * c2_c_y->size[1] - 1;
  for (c2_i1102 = 0; c2_i1102 <= c2_loop_ub; c2_i1102++) {
    c2_d_y->data[c2_i1102] = c2_c_y->data[c2_i1102];
  }

  for (c2_i1103 = 0; c2_i1103 < 2; c2_i1103++) {
    c2_i_varargin_1[c2_i1103] = c2_h_varargin_1[c2_i1103];
  }

  c2_b_sortrows(chartInstance, c2_d_y, c2_i_varargin_1);
}

static boolean_T c2_b_sortLE(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_v, int32_T c2_dir[2], int32_T c2_idx1,
  int32_T c2_idx2)
{
  boolean_T c2_p;
  int32_T c2_irow1;
  int32_T c2_irow2;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_colk;
  int32_T c2_d_x;
  int32_T c2_e_x;
  int32_T c2_f_x;
  int32_T c2_abscolk;
  int32_T c2_v1;
  int32_T c2_v2;
  boolean_T c2_v1eqv2;
  boolean_T c2_b84;
  int32_T c2_l_a;
  int32_T c2_b;
  int32_T c2_m_a;
  int32_T c2_b_b;
  boolean_T exitg1;
  (void)chartInstance;
  c2_irow1 = c2_idx1 - 1;
  c2_irow2 = c2_idx2 - 1;
  c2_p = true;
  c2_k = 0;
  exitg1 = false;
  while ((!exitg1) && (c2_k < 2)) {
    c2_b_k = c2_k;
    c2_colk = c2_dir[c2_b_k];
    c2_d_x = c2_colk;
    c2_e_x = c2_d_x;
    c2_f_x = c2_e_x;
    c2_abscolk = c2_f_x - 1;
    c2_v1 = c2_v->data[c2_irow1 + c2_v->size[0] * c2_abscolk];
    c2_v2 = c2_v->data[c2_irow2 + c2_v->size[0] * c2_abscolk];
    c2_v1eqv2 = (c2_v1 == c2_v2);
    if (c2_v1eqv2) {
      c2_b84 = true;
    } else {
      c2_b84 = false;
    }

    if (!c2_b84) {
      c2_l_a = c2_v1;
      c2_b = c2_v2;
      c2_m_a = c2_l_a;
      c2_b_b = c2_b;
      c2_p = (c2_m_a <= c2_b_b);
      exitg1 = true;
    } else {
      c2_k++;
    }
  }

  return c2_p;
}

static const mxArray *c2_emlrt_marshallOut
  (SFc2_flightControlSystemInstanceStruct *chartInstance, const char_T c2_e_u[30])
{
  const mxArray *c2_c_y = NULL;
  (void)chartInstance;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_e_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  return c2_c_y;
}

static const mxArray *c2_b_emlrt_marshallOut
  (SFc2_flightControlSystemInstanceStruct *chartInstance, const char_T c2_e_u[36])
{
  const mxArray *c2_c_y = NULL;
  (void)chartInstance;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_e_u, 10, 0U, 1U, 0U, 2, 1, 36),
                false);
  return c2_c_y;
}

static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_e_u;
  const mxArray *c2_c_y = NULL;
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_e_u = *(int32_T *)c2_inData;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_e_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_c_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_i_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_e_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_c_y;
  int32_T c2_i1104;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_e_u), &c2_i1104, 1, 6, 0U, 0, 0U, 0);
  c2_c_y = c2_i1104;
  sf_mex_destroy(&c2_e_u);
  return c2_c_y;
}

static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_c_y;
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_c_y = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_c_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_j_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_flightControlSystem, const
  char_T *c2_identifier)
{
  uint8_T c2_c_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_c_y = c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_flightControlSystem), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_flightControlSystem);
  return c2_c_y;
}

static uint8_T c2_k_emlrt_marshallIn(SFc2_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c2_e_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_c_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_e_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_c_y = c2_u0;
  sf_mex_destroy(&c2_e_u);
  return c2_c_y;
}

static void c2_b_round(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_real_T *c2_d_x)
{
  int32_T c2_nx;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  real_T c2_e_x;
  real_T c2_f_x;
  c2_nx = c2_d_x->size[0];
  c2_b = c2_nx;
  c2_b_b = c2_b;
  if (1 > c2_b_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_check_forloop_overflow_error(chartInstance, true);
  }

  for (c2_k = 0; c2_k < c2_nx; c2_k++) {
    c2_b_k = c2_k;
    c2_e_x = c2_d_x->data[c2_b_k];
    c2_f_x = c2_e_x;
    c2_f_x = muDoubleScalarRound(c2_f_x);
    c2_d_x->data[c2_b_k] = c2_f_x;
  }
}

static void c2_d_nullAssignment(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_d_x, c2_emxArray_int32_T *c2_b_idx)
{
  c2_emxArray_real_T *c2_e_x;
  int32_T c2_i1105;
  int32_T c2_loop_ub;
  int32_T c2_i1106;
  c2_emxArray_int32_T *c2_c_idx;
  int32_T c2_i1107;
  int32_T c2_b_loop_ub;
  int32_T c2_i1108;
  c2_emxArray_int32_T *c2_d_idx;
  int32_T c2_nxin;
  int32_T c2_nrowx;
  int32_T c2_i1109;
  int32_T c2_c_loop_ub;
  int32_T c2_i1110;
  boolean_T c2_b_data[19200];
  int32_T c2_b_size[2];
  int32_T c2_b_b_size[2];
  int32_T c2_i1111;
  int32_T c2_i1112;
  int32_T c2_d_loop_ub;
  int32_T c2_i1113;
  int32_T c2_nxout;
  boolean_T c2_b_b_data[19200];
  int32_T c2_nb;
  int32_T c2_k0;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  boolean_T c2_b85;
  int32_T c2_i1114;
  int32_T c2_i1115;
  c2_emxInit_real_T1(chartInstance, &c2_e_x, 1, &c2_wj_emlrtRTEI);
  c2_i1105 = c2_e_x->size[0];
  c2_e_x->size[0] = c2_d_x->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_e_x, c2_i1105, &c2_wj_emlrtRTEI);
  c2_loop_ub = c2_d_x->size[0] - 1;
  for (c2_i1106 = 0; c2_i1106 <= c2_loop_ub; c2_i1106++) {
    c2_e_x->data[c2_i1106] = c2_d_x->data[c2_i1106];
  }

  c2_emxInit_int32_T(chartInstance, &c2_c_idx, 1, &c2_xj_emlrtRTEI);
  c2_i1107 = c2_c_idx->size[0];
  c2_c_idx->size[0] = c2_b_idx->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_c_idx, c2_i1107,
    &c2_xj_emlrtRTEI);
  c2_b_loop_ub = c2_b_idx->size[0] - 1;
  for (c2_i1108 = 0; c2_i1108 <= c2_b_loop_ub; c2_i1108++) {
    c2_c_idx->data[c2_i1108] = c2_b_idx->data[c2_i1108];
  }

  c2_emxInit_int32_T(chartInstance, &c2_d_idx, 1, &c2_yj_emlrtRTEI);
  c2_validate_inputs(chartInstance, c2_e_x, c2_c_idx);
  c2_nxin = c2_d_x->size[0];
  c2_nrowx = c2_d_x->size[0];
  c2_i1109 = c2_d_idx->size[0];
  c2_d_idx->size[0] = c2_b_idx->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_d_idx, c2_i1109,
    &c2_yj_emlrtRTEI);
  c2_c_loop_ub = c2_b_idx->size[0] - 1;
  c2_emxFree_int32_T(chartInstance, &c2_c_idx);
  c2_emxFree_real_T(chartInstance, &c2_e_x);
  for (c2_i1110 = 0; c2_i1110 <= c2_c_loop_ub; c2_i1110++) {
    c2_d_idx->data[c2_i1110] = c2_b_idx->data[c2_i1110];
  }

  c2_make_bitarray(chartInstance, c2_nxin, c2_d_idx, c2_b_data, c2_b_size);
  c2_b_b_size[0] = 1;
  c2_b_b_size[1] = c2_b_size[1];
  c2_i1111 = c2_b_b_size[0];
  c2_i1112 = c2_b_b_size[1];
  c2_d_loop_ub = c2_b_size[0] * c2_b_size[1] - 1;
  c2_emxFree_int32_T(chartInstance, &c2_d_idx);
  for (c2_i1113 = 0; c2_i1113 <= c2_d_loop_ub; c2_i1113++) {
    c2_b_b_data[c2_i1113] = c2_b_data[c2_i1113];
  }

  c2_nxout = c2_nxin - c2_num_true(chartInstance, c2_b_b_data, c2_b_b_size);
  c2_nb = c2_b_size[1];
  c2_k0 = -1;
  c2_b = c2_nxin;
  c2_b_b = c2_b;
  if (1 > c2_b_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_check_forloop_overflow_error(chartInstance, true);
  }

  for (c2_k = 0; c2_k < c2_nxin; c2_k++) {
    c2_b_k = c2_k;
    if ((c2_b_k + 1 > c2_nb) || (!c2_b_data[c2_b_k])) {
      c2_k0++;
      c2_d_x->data[c2_k0] = c2_d_x->data[c2_b_k];
    }
  }

  if (c2_nxout <= c2_nrowx) {
  } else {
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                      c2_emlrt_marshallOut(chartInstance, c2_cv1), 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
      1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
      1U, 14, c2_emlrt_marshallOut(chartInstance, c2_cv1))));
  }

  c2_b85 = (1 > c2_nxout);
  if (c2_b85) {
    c2_i1114 = 0;
  } else {
    c2_i1114 = c2_nxout;
  }

  c2_i1115 = c2_d_x->size[0];
  c2_d_x->size[0] = c2_i1114;
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_d_x, c2_i1115, &c2_bk_emlrtRTEI);
}

static void c2_e_nullAssignment(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_d_x, int32_T c2_b_idx)
{
  int32_T c2_c_idx;
  int32_T c2_d_idx;
  real_T c2_d33;
  int32_T c2_n;
  boolean_T c2_p;
  int32_T c2_e_x;
  int32_T c2_f_x;
  const mxArray *c2_c_y = NULL;
  int32_T c2_e_idx;
  const mxArray *c2_d_y = NULL;
  int32_T c2_nrowx;
  int32_T c2_nrows;
  int32_T c2_l_a;
  int32_T c2_b;
  int32_T c2_m_a;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_i;
  int32_T c2_g_x[2];
  const mxArray *c2_e_y = NULL;
  boolean_T c2_b86;
  const mxArray *c2_f_y = NULL;
  int32_T c2_i1116;
  c2_emxArray_real_T *c2_h_x;
  int32_T c2_i1117;
  int32_T c2_loop_ub;
  int32_T c2_i1118;
  int32_T c2_i1119;
  int32_T c2_b_loop_ub;
  int32_T c2_i1120;
  c2_c_idx = c2_b_idx;
  c2_d_idx = c2_c_idx;
  c2_d33 = (real_T)c2_d_x->size[0];
  c2_n = (int32_T)c2_d33;
  c2_p = true;
  if (c2_d_idx > c2_n) {
    c2_p = false;
  } else {
    c2_e_x = c2_d_idx;
    c2_f_x = c2_e_x;
    if (c2_d_idx != c2_f_x) {
      c2_p = false;
    }
  }

  if (c2_p) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_d_y)));
  }

  c2_e_idx = c2_b_idx;
  c2_nrowx = c2_d_x->size[0];
  c2_nrows = c2_nrowx - 1;
  c2_l_a = c2_e_idx;
  c2_b = c2_nrows;
  c2_m_a = c2_l_a;
  c2_b_b = c2_b;
  if (c2_m_a > c2_b_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_check_forloop_overflow_error(chartInstance, true);
  }

  for (c2_i = c2_e_idx; c2_i <= c2_nrows; c2_i++) {
    c2_g_x[0] = c2_d_x->size[0];
    c2_g_x[1] = 1;
    c2_d_x->data[c2_i - 1] = c2_d_x->data[c2_i];
  }

  if (c2_nrows <= c2_nrowx) {
  } else {
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_e_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_f_y)));
  }

  c2_b86 = (1 > c2_nrows);
  if (c2_b86) {
    c2_i1116 = -1;
  } else {
    c2_i1116 = c2_nrows - 1;
  }

  c2_emxInit_real_T1(chartInstance, &c2_h_x, 1, &c2_tf_emlrtRTEI);
  c2_i1117 = c2_h_x->size[0];
  c2_h_x->size[0] = c2_i1116 + 1;
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_h_x, c2_i1117, &c2_tf_emlrtRTEI);
  c2_loop_ub = c2_i1116;
  for (c2_i1118 = 0; c2_i1118 <= c2_loop_ub; c2_i1118++) {
    c2_h_x->data[c2_i1118] = c2_d_x->data[c2_i1118];
  }

  c2_i1119 = c2_d_x->size[0];
  c2_d_x->size[0] = c2_h_x->size[0];
  c2_emxEnsureCapacity_real_T1(chartInstance, c2_d_x, c2_i1119, &c2_uf_emlrtRTEI);
  c2_b_loop_ub = c2_h_x->size[0] - 1;
  for (c2_i1120 = 0; c2_i1120 <= c2_b_loop_ub; c2_i1120++) {
    c2_d_x->data[c2_i1120] = c2_h_x->data[c2_i1120];
  }

  c2_emxFree_real_T(chartInstance, &c2_h_x);
}

static void c2_f_nullAssignment(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_d_x, boolean_T c2_idx_data[], int32_T
  c2_idx_size[2])
{
  int32_T c2_n;
  int32_T c2_k;
  boolean_T c2_p;
  const mxArray *c2_c_y = NULL;
  int32_T c2_nxin;
  const mxArray *c2_d_y = NULL;
  int32_T c2_b_n;
  int32_T c2_i1121;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_b_k;
  int32_T c2_nxout;
  int32_T c2_c_k;
  int32_T c2_nb;
  int32_T c2_i1122;
  int32_T c2_k0;
  int32_T c2_i1123;
  int32_T c2_c_b;
  int32_T c2_d_b;
  boolean_T c2_b_overflow;
  int32_T c2_d_k;
  int32_T c2_e_k;
  const mxArray *c2_e_y = NULL;
  boolean_T c2_b87;
  const mxArray *c2_f_y = NULL;
  int32_T c2_i1124;
  int32_T c2_i1125;
  int32_T c2_e_x[1];
  int32_T c2_i1126;
  int32_T c2_i1127;
  c2_n = c2_d_x->size[1];
  c2_k = c2_idx_size[1];
  while ((c2_k >= 1) && (!c2_idx_data[c2_k - 1])) {
    c2_k--;
  }

  c2_p = (c2_k <= c2_n);
  if (c2_p) {
  } else {
    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv4, 10, 0U, 1U, 0U, 2, 1, 25),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_c_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_d_y)));
  }

  c2_nxin = c2_d_x->size[1];
  c2_b_n = 0;
  c2_i1121 = c2_idx_size[1];
  c2_b = c2_i1121;
  c2_b_b = c2_b;
  if (1 > c2_b_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_check_forloop_overflow_error(chartInstance, true);
  }

  for (c2_b_k = 0; c2_b_k < c2_i1121; c2_b_k++) {
    c2_c_k = c2_b_k;
    c2_i1122 = c2_idx_size[1];
    c2_i1123 = c2_i1122;
    c2_b_n += (int32_T)c2_idx_data[c2_c_k];
  }

  c2_nxout = c2_nxin - c2_b_n;
  c2_nb = c2_idx_size[1];
  c2_k0 = -1;
  c2_c_b = c2_nxin;
  c2_d_b = c2_c_b;
  if (1 > c2_d_b) {
    c2_b_overflow = false;
  } else {
    c2_b_overflow = (c2_d_b > 2147483646);
  }

  if (c2_b_overflow) {
    c2_check_forloop_overflow_error(chartInstance, true);
  }

  for (c2_d_k = 0; c2_d_k < c2_nxin; c2_d_k++) {
    c2_e_k = c2_d_k;
    if ((c2_e_k + 1 > c2_nb) || (!c2_idx_data[c2_e_k])) {
      c2_k0++;
      c2_i1125 = c2_d_x->size[1];
      c2_e_x[0] = c2_d_x->size[1];
      c2_i1127 = c2_i1125;
      c2_d_x->data[c2_k0] = c2_d_x->data[c2_e_k];
    }
  }

  if (c2_nxout <= c2_nxin) {
  } else {
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    c2_f_y = NULL;
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_e_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_f_y)));
  }

  c2_b87 = (1 > c2_nxout);
  if (c2_b87) {
    c2_i1124 = 0;
  } else {
    c2_i1124 = c2_nxout;
  }

  c2_i1126 = c2_d_x->size[0] * c2_d_x->size[1];
  c2_d_x->size[1] = c2_i1124;
  c2_emxEnsureCapacity_real32_T(chartInstance, c2_d_x, c2_i1126,
    &c2_bk_emlrtRTEI);
}

static void c2_c_sort(SFc2_flightControlSystemInstanceStruct *chartInstance,
                      c2_emxArray_real32_T *c2_d_x)
{
  c2_emxArray_int32_T *c2_b_idx;
  int32_T c2_i1128;
  int32_T c2_i1129;
  int32_T c2_i1130;
  int32_T c2_loop_ub;
  int32_T c2_i1131;
  int32_T c2_n;
  int32_T c2_b_n;
  int32_T c2_i1132;
  int32_T c2_i1133;
  real32_T c2_x4[4];
  c2_emxArray_int32_T *c2_b_iwork;
  int32_T c2_idx4[4];
  int32_T c2_i1134;
  int32_T c2_iv18[1];
  int32_T c2_i1135;
  int32_T c2_i1136;
  int32_T c2_i1137;
  int32_T c2_b_loop_ub;
  int32_T c2_i1138;
  c2_emxArray_real32_T *c2_xwork;
  real_T c2_dv11[2];
  int32_T c2_i1139;
  int32_T c2_i1140;
  int32_T c2_i1141;
  int32_T c2_i1142;
  int32_T c2_c_loop_ub;
  int32_T c2_i1143;
  int32_T c2_nNaNs;
  int32_T c2_ib;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_wOffset;
  int32_T c2_b_k;
  real32_T c2_e_x;
  int32_T c2_c_n;
  boolean_T c2_c_b;
  int32_T c2_m;
  int32_T c2_i1144;
  int32_T c2_d_b;
  int32_T c2_e_b;
  int32_T c2_perm[4];
  boolean_T c2_b_overflow;
  int32_T c2_f_b;
  int32_T c2_quartetOffset;
  int32_T c2_g_b;
  int32_T c2_c_i1;
  int32_T c2_c_k;
  boolean_T c2_c_overflow;
  int32_T c2_c_i2;
  int32_T c2_i3;
  int32_T c2_f_x[1];
  int32_T c2_itmp;
  int32_T c2_d_k;
  int32_T c2_i4;
  int32_T c2_nNonNaN;
  int32_T c2_i1145;
  int32_T c2_preSortLevel;
  int32_T c2_i1146;
  int32_T c2_nBlocks;
  int32_T c2_g_x[1];
  int32_T c2_h_x[1];
  int32_T c2_h_b;
  int32_T c2_i_x[1];
  int32_T c2_i_b;
  boolean_T c2_d_overflow;
  int32_T c2_j_b;
  int32_T c2_j_x[1];
  int32_T c2_k_x[1];
  int32_T c2_tailOffset;
  int32_T c2_k_b;
  int32_T c2_nLastBlock;
  int32_T c2_l_x[1];
  int32_T c2_m_x[1];
  c2_emxInit_int32_T1(chartInstance, &c2_b_idx, 2, &c2_ik_emlrtRTEI);
  c2_i1128 = c2_b_idx->size[0] * c2_b_idx->size[1];
  c2_b_idx->size[0] = 1;
  c2_b_idx->size[1] = c2_d_x->size[1];
  c2_emxEnsureCapacity_int32_T1(chartInstance, c2_b_idx, c2_i1128,
    &c2_ck_emlrtRTEI);
  c2_i1129 = c2_b_idx->size[0];
  c2_i1130 = c2_b_idx->size[1];
  c2_loop_ub = c2_d_x->size[1] - 1;
  for (c2_i1131 = 0; c2_i1131 <= c2_loop_ub; c2_i1131++) {
    c2_b_idx->data[c2_i1131] = 0;
  }

  c2_n = c2_d_x->size[1];
  c2_b_n = c2_d_x->size[1];
  for (c2_i1132 = 0; c2_i1132 < 4; c2_i1132++) {
    c2_x4[c2_i1132] = 0.0F;
  }

  for (c2_i1133 = 0; c2_i1133 < 4; c2_i1133++) {
    c2_idx4[c2_i1133] = 0;
  }

  c2_emxInit_int32_T(chartInstance, &c2_b_iwork, 1, &c2_jk_emlrtRTEI);
  c2_i1134 = c2_b_iwork->size[0];
  c2_b_iwork->size[0] = c2_b_idx->size[1];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_b_iwork, c2_i1134,
    &c2_dk_emlrtRTEI);
  c2_iv18[0] = c2_b_iwork->size[0];
  c2_i1135 = c2_b_iwork->size[0];
  c2_b_iwork->size[0] = c2_iv18[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_b_iwork, c2_i1135,
    &c2_ek_emlrtRTEI);
  c2_i1136 = c2_b_iwork->size[0];
  c2_i1137 = c2_b_iwork->size[0];
  c2_b_iwork->size[0] = c2_i1136;
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_b_iwork, c2_i1137,
    &c2_fk_emlrtRTEI);
  c2_b_loop_ub = c2_i1136 - 1;
  for (c2_i1138 = 0; c2_i1138 <= c2_b_loop_ub; c2_i1138++) {
    c2_b_iwork->data[c2_i1138] = 0;
  }

  c2_emxInit_real32_T1(chartInstance, &c2_xwork, 1, &c2_kk_emlrtRTEI);
  c2_dv11[0] = (real_T)c2_d_x->size[1];
  c2_dv11[1] = 1.0;
  c2_i1139 = c2_xwork->size[0];
  c2_xwork->size[0] = (int32_T)c2_dv11[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_xwork, c2_i1139,
    &c2_gk_emlrtRTEI);
  c2_iv18[0] = c2_xwork->size[0];
  c2_i1140 = c2_xwork->size[0];
  c2_xwork->size[0] = c2_iv18[0];
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_xwork, c2_i1140,
    &c2_ek_emlrtRTEI);
  c2_i1141 = c2_xwork->size[0];
  c2_i1142 = c2_xwork->size[0];
  c2_xwork->size[0] = c2_i1141;
  c2_emxEnsureCapacity_real32_T1(chartInstance, c2_xwork, c2_i1142,
    &c2_hk_emlrtRTEI);
  c2_c_loop_ub = c2_i1141 - 1;
  for (c2_i1143 = 0; c2_i1143 <= c2_c_loop_ub; c2_i1143++) {
    c2_xwork->data[c2_i1143] = 0.0F;
  }

  c2_nNaNs = 0;
  c2_ib = 0;
  c2_b = c2_b_n;
  c2_b_b = c2_b;
  if (1 > c2_b_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  if (c2_overflow) {
    c2_check_forloop_overflow_error(chartInstance, true);
  }

  for (c2_k = 0; c2_k < c2_b_n; c2_k++) {
    c2_b_k = c2_k;
    c2_e_x = c2_d_x->data[c2_b_k];
    c2_c_b = muSingleScalarIsNaN(c2_e_x);
    if (c2_c_b) {
      c2_b_idx->data[(c2_b_n - c2_nNaNs) - 1] = c2_b_k + 1;
      c2_xwork->data[(c2_b_n - c2_nNaNs) - 1] = c2_d_x->data[c2_b_k];
      c2_nNaNs++;
    } else {
      c2_ib++;
      c2_idx4[c2_ib - 1] = c2_b_k + 1;
      c2_x4[c2_ib - 1] = c2_d_x->data[c2_b_k];
      if (c2_ib == 4) {
        c2_quartetOffset = c2_b_k - c2_nNaNs;
        if (c2_x4[0] <= c2_x4[1]) {
          c2_c_i1 = 1;
          c2_c_i2 = 2;
        } else {
          c2_c_i1 = 2;
          c2_c_i2 = 1;
        }

        if (c2_x4[2] <= c2_x4[3]) {
          c2_i3 = 3;
          c2_i4 = 4;
        } else {
          c2_i3 = 4;
          c2_i4 = 3;
        }

        if (c2_x4[c2_c_i1 - 1] <= c2_x4[c2_i3 - 1]) {
          if (c2_x4[c2_c_i2 - 1] <= c2_x4[c2_i3 - 1]) {
            c2_perm[0] = c2_c_i1;
            c2_perm[1] = c2_c_i2;
            c2_perm[2] = c2_i3;
            c2_perm[3] = c2_i4;
          } else if (c2_x4[c2_c_i2 - 1] <= c2_x4[c2_i4 - 1]) {
            c2_perm[0] = c2_c_i1;
            c2_perm[1] = c2_i3;
            c2_perm[2] = c2_c_i2;
            c2_perm[3] = c2_i4;
          } else {
            c2_perm[0] = c2_c_i1;
            c2_perm[1] = c2_i3;
            c2_perm[2] = c2_i4;
            c2_perm[3] = c2_c_i2;
          }
        } else if (c2_x4[c2_c_i1 - 1] <= c2_x4[c2_i4 - 1]) {
          if (c2_x4[c2_c_i2 - 1] <= c2_x4[c2_i4 - 1]) {
            c2_perm[0] = c2_i3;
            c2_perm[1] = c2_c_i1;
            c2_perm[2] = c2_c_i2;
            c2_perm[3] = c2_i4;
          } else {
            c2_perm[0] = c2_i3;
            c2_perm[1] = c2_c_i1;
            c2_perm[2] = c2_i4;
            c2_perm[3] = c2_c_i2;
          }
        } else {
          c2_perm[0] = c2_i3;
          c2_perm[1] = c2_i4;
          c2_perm[2] = c2_c_i1;
          c2_perm[3] = c2_c_i2;
        }

        c2_b_idx->data[c2_quartetOffset - 3] = c2_idx4[c2_perm[0] - 1];
        c2_b_idx->data[c2_quartetOffset - 2] = c2_idx4[c2_perm[1] - 1];
        c2_b_idx->data[c2_quartetOffset - 1] = c2_idx4[c2_perm[2] - 1];
        c2_b_idx->data[c2_quartetOffset] = c2_idx4[c2_perm[3] - 1];
        c2_j_x[0] = c2_d_x->size[1];
        c2_d_x->data[c2_quartetOffset - 3] = c2_x4[c2_perm[0] - 1];
        c2_k_x[0] = c2_d_x->size[1];
        c2_d_x->data[c2_quartetOffset - 2] = c2_x4[c2_perm[1] - 1];
        c2_l_x[0] = c2_d_x->size[1];
        c2_d_x->data[c2_quartetOffset - 1] = c2_x4[c2_perm[2] - 1];
        c2_m_x[0] = c2_d_x->size[1];
        c2_d_x->data[c2_quartetOffset] = c2_x4[c2_perm[3] - 1];
        c2_ib = 0;
      }
    }
  }

  c2_wOffset = (c2_b_n - c2_nNaNs) - 1;
  if (c2_ib > 0) {
    c2_c_n = c2_ib;
    for (c2_i1144 = 0; c2_i1144 < 4; c2_i1144++) {
      c2_perm[c2_i1144] = 0;
    }

    if (c2_c_n == 1) {
      c2_perm[0] = 1;
    } else if (c2_c_n == 2) {
      if (c2_x4[0] <= c2_x4[1]) {
        c2_perm[0] = 1;
        c2_perm[1] = 2;
      } else {
        c2_perm[0] = 2;
        c2_perm[1] = 1;
      }
    } else if (c2_x4[0] <= c2_x4[1]) {
      if (c2_x4[1] <= c2_x4[2]) {
        c2_perm[0] = 1;
        c2_perm[1] = 2;
        c2_perm[2] = 3;
      } else if (c2_x4[0] <= c2_x4[2]) {
        c2_perm[0] = 1;
        c2_perm[1] = 3;
        c2_perm[2] = 2;
      } else {
        c2_perm[0] = 3;
        c2_perm[1] = 1;
        c2_perm[2] = 2;
      }
    } else if (c2_x4[0] <= c2_x4[2]) {
      c2_perm[0] = 2;
      c2_perm[1] = 1;
      c2_perm[2] = 3;
    } else if (c2_x4[1] <= c2_x4[2]) {
      c2_perm[0] = 2;
      c2_perm[1] = 3;
      c2_perm[2] = 1;
    } else {
      c2_perm[0] = 3;
      c2_perm[1] = 2;
      c2_perm[2] = 1;
    }

    c2_f_b = c2_ib;
    c2_g_b = c2_f_b;
    if (1 > c2_g_b) {
      c2_c_overflow = false;
    } else {
      c2_c_overflow = (c2_g_b > 2147483646);
    }

    if (c2_c_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }

    for (c2_d_k = 0; c2_d_k < c2_ib; c2_d_k++) {
      c2_b_k = c2_d_k;
      c2_b_idx->data[((c2_wOffset - c2_ib) + c2_b_k) + 1] =
        c2_idx4[c2_perm[c2_b_k] - 1];
      c2_h_x[0] = c2_d_x->size[1];
      c2_d_x->data[((c2_wOffset - c2_ib) + c2_b_k) + 1] = c2_x4[c2_perm[c2_b_k]
        - 1];
    }
  }

  c2_m = c2_nNaNs >> 1;
  c2_d_b = c2_m;
  c2_e_b = c2_d_b;
  if (1 > c2_e_b) {
    c2_b_overflow = false;
  } else {
    c2_b_overflow = (c2_e_b > 2147483646);
  }

  if (c2_b_overflow) {
    c2_check_forloop_overflow_error(chartInstance, true);
  }

  for (c2_c_k = 1; c2_c_k - 1 < c2_m; c2_c_k++) {
    c2_b_k = c2_c_k;
    c2_itmp = c2_b_idx->data[c2_wOffset + c2_b_k];
    c2_i1145 = c2_b_idx->size[1];
    c2_i1146 = c2_i1145;
    c2_b_idx->data[c2_wOffset + c2_b_k] = c2_b_idx->data[c2_b_n - c2_b_k];
    c2_b_idx->data[c2_b_n - c2_b_k] = c2_itmp;
    c2_g_x[0] = c2_d_x->size[1];
    c2_d_x->data[c2_wOffset + c2_b_k] = c2_xwork->data[c2_b_n - c2_b_k];
    c2_i_x[0] = c2_d_x->size[1];
    c2_d_x->data[c2_b_n - c2_b_k] = c2_xwork->data[c2_wOffset + c2_b_k];
  }

  if ((c2_nNaNs & 1) != 0) {
    c2_f_x[0] = c2_d_x->size[1];
    c2_d_x->data[(c2_wOffset + c2_m) + 1] = c2_xwork->data[(c2_wOffset + c2_m) +
      1];
  }

  c2_nNonNaN = c2_n - c2_nNaNs;
  c2_preSortLevel = 2;
  if (c2_nNonNaN > 1) {
    if (c2_n >= 256) {
      c2_nBlocks = c2_nNonNaN >> 8;
      if (c2_nBlocks > 0) {
        c2_h_b = c2_nBlocks;
        c2_i_b = c2_h_b;
        if (1 > c2_i_b) {
          c2_d_overflow = false;
        } else {
          c2_d_overflow = (c2_i_b > 2147483646);
        }

        if (c2_d_overflow) {
          c2_check_forloop_overflow_error(chartInstance, true);
        }

        for (c2_j_b = 0; c2_j_b < c2_nBlocks; c2_j_b++) {
          c2_k_b = c2_j_b;
          c2_b_merge_pow2_block(chartInstance, c2_b_idx, c2_d_x, c2_k_b << 8);
        }

        c2_tailOffset = c2_nBlocks << 8;
        c2_nLastBlock = c2_nNonNaN - c2_tailOffset;
        if (c2_nLastBlock > 0) {
          c2_c_merge_block(chartInstance, c2_b_idx, c2_d_x, c2_tailOffset,
                           c2_nLastBlock, 2, c2_b_iwork, c2_xwork);
        }

        c2_preSortLevel = 8;
      }
    }

    c2_c_merge_block(chartInstance, c2_b_idx, c2_d_x, 0, c2_nNonNaN,
                     c2_preSortLevel, c2_b_iwork, c2_xwork);
  }

  c2_emxFree_real32_T(chartInstance, &c2_xwork);
  c2_emxFree_int32_T(chartInstance, &c2_b_iwork);
  c2_emxFree_int32_T(chartInstance, &c2_b_idx);
}

static void c2_b_merge_pow2_block(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T *c2_d_x,
  int32_T c2_offset)
{
  int32_T c2_b;
  int32_T c2_bLen;
  int32_T c2_bLen2;
  int32_T c2_nPairs;
  int32_T c2_b_b;
  int32_T c2_c_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_blockOffset;
  int32_T c2_d_b;
  int32_T c2_e_b;
  boolean_T c2_b_overflow;
  int32_T c2_j;
  int32_T c2_p;
  int32_T c2_b_j;
  int32_T c2_q;
  int32_T c2_b_iwork[256];
  int32_T c2_iout;
  real32_T c2_xwork[256];
  int32_T c2_c_idx[1];
  int32_T c2_d_idx[1];
  int32_T c2_e_x[1];
  int32_T c2_f_x[1];
  int32_T c2_offset1;
  int32_T c2_l_a;
  int32_T c2_f_b;
  int32_T c2_m_a;
  int32_T c2_g_b;
  boolean_T c2_c_overflow;
  int32_T c2_c_j;
  int32_T c2_e_idx[1];
  int32_T c2_g_x[1];
  int32_T exitg1;
  for (c2_b = 0; c2_b < 6; c2_b++) {
    c2_bLen = 1 << (c2_b + 2);
    c2_bLen2 = c2_bLen << 1;
    c2_nPairs = 256 >> (c2_b + 3);
    c2_b_b = c2_nPairs;
    c2_c_b = c2_b_b;
    if (1 > c2_c_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_c_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }

    for (c2_k = 0; c2_k < c2_nPairs; c2_k++) {
      c2_b_k = c2_k;
      c2_blockOffset = (c2_offset + c2_b_k * c2_bLen2) - 1;
      c2_d_b = c2_bLen2;
      c2_e_b = c2_d_b;
      if (1 > c2_e_b) {
        c2_b_overflow = false;
      } else {
        c2_b_overflow = (c2_e_b > 2147483646);
      }

      if (c2_b_overflow) {
        c2_check_forloop_overflow_error(chartInstance, true);
      }

      for (c2_j = 0; c2_j < c2_bLen2; c2_j++) {
        c2_b_j = c2_j;
        c2_b_iwork[c2_b_j] = c2_b_idx->data[(c2_blockOffset + c2_b_j) + 1];
        c2_xwork[c2_b_j] = c2_d_x->data[(c2_blockOffset + c2_b_j) + 1];
      }

      c2_p = 0;
      c2_q = c2_bLen;
      c2_iout = c2_blockOffset;
      do {
        exitg1 = 0;
        c2_iout++;
        if (c2_xwork[c2_p] <= c2_xwork[c2_q]) {
          c2_d_idx[0] = c2_b_idx->size[1];
          c2_b_idx->data[c2_iout] = c2_b_iwork[c2_p];
          c2_f_x[0] = c2_d_x->size[1];
          c2_d_x->data[c2_iout] = c2_xwork[c2_p];
          if (c2_p + 1 < c2_bLen) {
            c2_p++;
          } else {
            exitg1 = 1;
          }
        } else {
          c2_c_idx[0] = c2_b_idx->size[1];
          c2_b_idx->data[c2_iout] = c2_b_iwork[c2_q];
          c2_e_x[0] = c2_d_x->size[1];
          c2_d_x->data[c2_iout] = c2_xwork[c2_q];
          if (c2_q + 1 < c2_bLen2) {
            c2_q++;
          } else {
            c2_offset1 = c2_iout - c2_p;
            c2_l_a = c2_p + 1;
            c2_f_b = c2_bLen;
            c2_m_a = c2_l_a;
            c2_g_b = c2_f_b;
            if (c2_m_a > c2_g_b) {
              c2_c_overflow = false;
            } else {
              c2_c_overflow = (c2_g_b > 2147483646);
            }

            if (c2_c_overflow) {
              c2_check_forloop_overflow_error(chartInstance, true);
            }

            for (c2_c_j = c2_p + 1; c2_c_j <= c2_bLen; c2_c_j++) {
              c2_e_idx[0] = c2_b_idx->size[1];
              c2_b_idx->data[c2_offset1 + c2_c_j] = c2_b_iwork[c2_c_j - 1];
              c2_g_x[0] = c2_d_x->size[1];
              c2_d_x->data[c2_offset1 + c2_c_j] = c2_xwork[c2_c_j - 1];
            }

            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);
    }
  }
}

static void c2_c_merge_block(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T *c2_d_x,
  int32_T c2_offset, int32_T c2_n, int32_T c2_preSortLevel, c2_emxArray_int32_T *
  c2_b_iwork, c2_emxArray_real32_T *c2_xwork)
{
  int32_T c2_nBlocks;
  int32_T c2_bLen;
  int32_T c2_bLen2;
  int32_T c2_tailOffset;
  int32_T c2_nPairs;
  int32_T c2_nTail;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  c2_nBlocks = c2_n >> c2_preSortLevel;
  c2_bLen = 1 << c2_preSortLevel;
  while (c2_nBlocks > 1) {
    if ((c2_nBlocks & 1) != 0) {
      c2_nBlocks--;
      c2_tailOffset = c2_bLen * c2_nBlocks;
      c2_nTail = c2_n - c2_tailOffset;
      if (c2_nTail > c2_bLen) {
        c2_c_merge(chartInstance, c2_b_idx, c2_d_x, c2_offset + c2_tailOffset,
                   c2_bLen, c2_nTail - c2_bLen, c2_b_iwork, c2_xwork);
      }
    }

    c2_bLen2 = c2_bLen << 1;
    c2_nPairs = c2_nBlocks >> 1;
    c2_b = c2_nPairs;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }

    for (c2_k = 0; c2_k < c2_nPairs; c2_k++) {
      c2_b_k = c2_k;
      c2_c_merge(chartInstance, c2_b_idx, c2_d_x, c2_offset + c2_b_k * c2_bLen2,
                 c2_bLen, c2_bLen, c2_b_iwork, c2_xwork);
    }

    c2_bLen = c2_bLen2;
    c2_nBlocks = c2_nPairs;
  }

  if (c2_n > c2_bLen) {
    c2_c_merge(chartInstance, c2_b_idx, c2_d_x, c2_offset, c2_bLen, c2_n -
               c2_bLen, c2_b_iwork, c2_xwork);
  }
}

static void c2_c_merge(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real32_T *c2_d_x, int32_T c2_offset,
  int32_T c2_np, int32_T c2_nq, c2_emxArray_int32_T *c2_b_iwork,
  c2_emxArray_real32_T *c2_xwork)
{
  int32_T c2_n;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_j;
  int32_T c2_p;
  int32_T c2_b_j;
  int32_T c2_q;
  int32_T c2_qend;
  int32_T c2_iout;
  int32_T c2_c_idx[1];
  int32_T c2_d_idx[1];
  int32_T c2_e_x[1];
  int32_T c2_f_x[1];
  int32_T c2_offset1;
  int32_T c2_l_a;
  int32_T c2_c_b;
  int32_T c2_m_a;
  int32_T c2_d_b;
  boolean_T c2_b_overflow;
  int32_T c2_c_j;
  int32_T c2_e_idx[1];
  int32_T c2_g_x[1];
  int32_T exitg1;
  if (c2_nq == 0) {
  } else {
    c2_n = c2_np + c2_nq;
    c2_b = c2_n;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }

    for (c2_j = 0; c2_j < c2_n; c2_j++) {
      c2_b_j = c2_j;
      c2_b_iwork->data[c2_b_j] = c2_b_idx->data[c2_offset + c2_b_j];
      c2_xwork->data[c2_b_j] = c2_d_x->data[c2_offset + c2_b_j];
    }

    c2_p = 1;
    c2_q = c2_np;
    c2_qend = c2_np + c2_nq;
    c2_iout = c2_offset - 1;
    do {
      exitg1 = 0;
      c2_iout++;
      if (c2_xwork->data[c2_p - 1] <= c2_xwork->data[c2_q]) {
        c2_d_idx[0] = c2_b_idx->size[1];
        c2_b_idx->data[c2_iout] = c2_b_iwork->data[c2_p - 1];
        c2_f_x[0] = c2_d_x->size[1];
        c2_d_x->data[c2_iout] = c2_xwork->data[c2_p - 1];
        if (c2_p < c2_np) {
          c2_p++;
        } else {
          exitg1 = 1;
        }
      } else {
        c2_c_idx[0] = c2_b_idx->size[1];
        c2_b_idx->data[c2_iout] = c2_b_iwork->data[c2_q];
        c2_e_x[0] = c2_d_x->size[1];
        c2_d_x->data[c2_iout] = c2_xwork->data[c2_q];
        if (c2_q + 1 < c2_qend) {
          c2_q++;
        } else {
          c2_offset1 = (c2_iout - c2_p) + 1;
          c2_l_a = c2_p;
          c2_c_b = c2_np;
          c2_m_a = c2_l_a;
          c2_d_b = c2_c_b;
          if (c2_m_a > c2_d_b) {
            c2_b_overflow = false;
          } else {
            c2_b_overflow = (c2_d_b > 2147483646);
          }

          if (c2_b_overflow) {
            c2_check_forloop_overflow_error(chartInstance, true);
          }

          for (c2_c_j = c2_p; c2_c_j <= c2_np; c2_c_j++) {
            c2_e_idx[0] = c2_b_idx->size[1];
            c2_b_idx->data[c2_offset1 + c2_c_j] = c2_b_iwork->data[c2_c_j - 1];
            c2_g_x[0] = c2_d_x->size[1];
            c2_d_x->data[c2_offset1 + c2_c_j] = c2_xwork->data[c2_c_j - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void c2_d_sort(SFc2_flightControlSystemInstanceStruct *chartInstance,
                      c2_emxArray_real_T *c2_d_x, c2_emxArray_int32_T *c2_b_idx)
{
  int32_T c2_i1147;
  int32_T c2_i1148;
  real_T c2_e_x[2];
  int32_T c2_i1149;
  int32_T c2_i1150;
  int32_T c2_i1151;
  int32_T c2_loop_ub;
  int32_T c2_i1152;
  boolean_T c2_b88;
  int32_T c2_n;
  int32_T c2_b_n;
  int32_T c2_i1153;
  int32_T c2_i1154;
  real_T c2_x4[4];
  c2_emxArray_int32_T *c2_b_iwork;
  int32_T c2_idx4[4];
  int32_T c2_i1155;
  int32_T c2_iv19[1];
  int32_T c2_i1156;
  int32_T c2_i1157;
  int32_T c2_i1158;
  int32_T c2_b_loop_ub;
  int32_T c2_i1159;
  c2_emxArray_real_T *c2_xwork;
  int32_T c2_i1160;
  int32_T c2_i1161;
  int32_T c2_i1162;
  int32_T c2_i1163;
  int32_T c2_c_loop_ub;
  int32_T c2_i1164;
  int32_T c2_nNaNs;
  int32_T c2_ib;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_wOffset;
  int32_T c2_b_k;
  real_T c2_f_x;
  int32_T c2_c_n;
  boolean_T c2_c_b;
  int32_T c2_m;
  int32_T c2_i1165;
  int32_T c2_d_b;
  int32_T c2_e_b;
  int32_T c2_perm[4];
  boolean_T c2_b_overflow;
  int32_T c2_f_b;
  int32_T c2_quartetOffset;
  int32_T c2_g_b;
  int32_T c2_c_i1;
  int32_T c2_c_k;
  boolean_T c2_c_overflow;
  int32_T c2_c_i2;
  int32_T c2_i3;
  int32_T c2_g_x[1];
  int32_T c2_itmp;
  int32_T c2_d_k;
  int32_T c2_i4;
  int32_T c2_nNonNaN;
  int32_T c2_i1166;
  int32_T c2_preSortLevel;
  int32_T c2_i1167;
  int32_T c2_nBlocks;
  int32_T c2_h_x[1];
  int32_T c2_i_x[1];
  int32_T c2_b_nNonNaN;
  int32_T c2_h_b;
  int32_T c2_j_x[1];
  int32_T c2_b_nNaNs;
  int32_T c2_i_b;
  int32_T c2_j_b;
  int32_T c2_k_b;
  boolean_T c2_d_overflow;
  boolean_T c2_e_overflow;
  int32_T c2_l_b;
  int32_T c2_k_x[1];
  int32_T c2_e_k;
  int32_T c2_l_x[1];
  int32_T c2_tailOffset;
  int32_T c2_m_b;
  int32_T c2_nLastBlock;
  int32_T c2_offset;
  int32_T c2_m_x[1];
  int32_T c2_f_k;
  int32_T c2_g_k;
  int32_T c2_n_b;
  int32_T c2_n_x[1];
  int32_T c2_bLen;
  int32_T c2_o_b;
  int32_T c2_i1168;
  int32_T c2_bLen2;
  int32_T c2_p_b;
  int32_T c2_o_x[1];
  int32_T c2_nPairs;
  int32_T c2_i1169;
  int32_T c2_q_b;
  boolean_T c2_f_overflow;
  int32_T c2_r_b;
  int32_T c2_i1170;
  int32_T c2_i1171;
  boolean_T c2_g_overflow;
  int32_T c2_h_k;
  int32_T c2_i_k;
  int32_T c2_p_x[1];
  int32_T c2_j_k;
  int32_T c2_blockOffset;
  int32_T c2_s_b;
  int32_T c2_t_b;
  boolean_T c2_h_overflow;
  int32_T c2_j;
  int32_T c2_p;
  int32_T c2_b_j;
  int32_T c2_q;
  int32_T c2_c_iwork[256];
  int32_T c2_iout;
  real_T c2_b_xwork[256];
  int32_T c2_q_x[1];
  int32_T c2_r_x[1];
  int32_T c2_offset1;
  int32_T c2_l_a;
  int32_T c2_u_b;
  int32_T c2_m_a;
  int32_T c2_v_b;
  boolean_T c2_i_overflow;
  int32_T c2_c_j;
  int32_T c2_s_x[1];
  int32_T exitg1;
  for (c2_i1147 = 0; c2_i1147 < 2; c2_i1147++) {
    c2_e_x[c2_i1147] = (real_T)c2_d_x->size[c2_i1147];
  }

  for (c2_i1148 = 0; c2_i1148 < 2; c2_i1148++) {
    c2_e_x[c2_i1148];
  }

  c2_i1149 = c2_b_idx->size[0] * c2_b_idx->size[1];
  c2_b_idx->size[0] = (int32_T)c2_e_x[0];
  c2_b_idx->size[1] = 1;
  c2_emxEnsureCapacity_int32_T1(chartInstance, c2_b_idx, c2_i1149,
    &c2_lk_emlrtRTEI);
  c2_i1150 = c2_b_idx->size[0];
  c2_i1151 = c2_b_idx->size[1];
  c2_loop_ub = (int32_T)c2_e_x[0] - 1;
  for (c2_i1152 = 0; c2_i1152 <= c2_loop_ub; c2_i1152++) {
    c2_b_idx->data[c2_i1152] = 0;
  }

  c2_b88 = (c2_d_x->size[0] == 0);
  if (c2_b88) {
  } else {
    c2_n = c2_d_x->size[0];
    c2_b_n = c2_d_x->size[0];
    for (c2_i1153 = 0; c2_i1153 < 4; c2_i1153++) {
      c2_x4[c2_i1153] = 0.0;
    }

    for (c2_i1154 = 0; c2_i1154 < 4; c2_i1154++) {
      c2_idx4[c2_i1154] = 0;
    }

    c2_emxInit_int32_T(chartInstance, &c2_b_iwork, 1, &c2_jk_emlrtRTEI);
    c2_i1155 = c2_b_iwork->size[0];
    c2_b_iwork->size[0] = c2_b_idx->size[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_b_iwork, c2_i1155,
      &c2_dk_emlrtRTEI);
    c2_iv19[0] = c2_b_iwork->size[0];
    c2_i1156 = c2_b_iwork->size[0];
    c2_b_iwork->size[0] = c2_iv19[0];
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_b_iwork, c2_i1156,
      &c2_ek_emlrtRTEI);
    c2_i1157 = c2_b_iwork->size[0];
    c2_i1158 = c2_b_iwork->size[0];
    c2_b_iwork->size[0] = c2_i1157;
    c2_emxEnsureCapacity_int32_T(chartInstance, c2_b_iwork, c2_i1158,
      &c2_fk_emlrtRTEI);
    c2_b_loop_ub = c2_i1157 - 1;
    for (c2_i1159 = 0; c2_i1159 <= c2_b_loop_ub; c2_i1159++) {
      c2_b_iwork->data[c2_i1159] = 0;
    }

    c2_emxInit_real_T1(chartInstance, &c2_xwork, 1, &c2_kk_emlrtRTEI);
    c2_e_x[0] = (real_T)c2_d_x->size[0];
    c2_e_x[1] = 1.0;
    c2_i1160 = c2_xwork->size[0];
    c2_xwork->size[0] = (int32_T)c2_e_x[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_xwork, c2_i1160,
      &c2_gk_emlrtRTEI);
    c2_iv19[0] = c2_xwork->size[0];
    c2_i1161 = c2_xwork->size[0];
    c2_xwork->size[0] = c2_iv19[0];
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_xwork, c2_i1161,
      &c2_ek_emlrtRTEI);
    c2_i1162 = c2_xwork->size[0];
    c2_i1163 = c2_xwork->size[0];
    c2_xwork->size[0] = c2_i1162;
    c2_emxEnsureCapacity_real_T1(chartInstance, c2_xwork, c2_i1163,
      &c2_hk_emlrtRTEI);
    c2_c_loop_ub = c2_i1162 - 1;
    for (c2_i1164 = 0; c2_i1164 <= c2_c_loop_ub; c2_i1164++) {
      c2_xwork->data[c2_i1164] = 0.0;
    }

    c2_nNaNs = 0;
    c2_ib = 0;
    c2_b = c2_b_n;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }

    for (c2_k = 0; c2_k < c2_b_n; c2_k++) {
      c2_b_k = c2_k;
      c2_f_x = c2_d_x->data[c2_b_k];
      c2_c_b = muDoubleScalarIsNaN(c2_f_x);
      if (c2_c_b) {
        c2_b_idx->data[(c2_b_n - c2_nNaNs) - 1] = c2_b_k + 1;
        c2_xwork->data[(c2_b_n - c2_nNaNs) - 1] = c2_d_x->data[c2_b_k];
        c2_nNaNs++;
      } else {
        c2_ib++;
        c2_idx4[c2_ib - 1] = c2_b_k + 1;
        c2_x4[c2_ib - 1] = c2_d_x->data[c2_b_k];
        if (c2_ib == 4) {
          c2_quartetOffset = c2_b_k - c2_nNaNs;
          if (c2_x4[0] >= c2_x4[1]) {
            c2_c_i1 = 1;
            c2_c_i2 = 2;
          } else {
            c2_c_i1 = 2;
            c2_c_i2 = 1;
          }

          if (c2_x4[2] >= c2_x4[3]) {
            c2_i3 = 3;
            c2_i4 = 4;
          } else {
            c2_i3 = 4;
            c2_i4 = 3;
          }

          if (c2_x4[c2_c_i1 - 1] >= c2_x4[c2_i3 - 1]) {
            if (c2_x4[c2_c_i2 - 1] >= c2_x4[c2_i3 - 1]) {
              c2_perm[0] = c2_c_i1;
              c2_perm[1] = c2_c_i2;
              c2_perm[2] = c2_i3;
              c2_perm[3] = c2_i4;
            } else if (c2_x4[c2_c_i2 - 1] >= c2_x4[c2_i4 - 1]) {
              c2_perm[0] = c2_c_i1;
              c2_perm[1] = c2_i3;
              c2_perm[2] = c2_c_i2;
              c2_perm[3] = c2_i4;
            } else {
              c2_perm[0] = c2_c_i1;
              c2_perm[1] = c2_i3;
              c2_perm[2] = c2_i4;
              c2_perm[3] = c2_c_i2;
            }
          } else if (c2_x4[c2_c_i1 - 1] >= c2_x4[c2_i4 - 1]) {
            if (c2_x4[c2_c_i2 - 1] >= c2_x4[c2_i4 - 1]) {
              c2_perm[0] = c2_i3;
              c2_perm[1] = c2_c_i1;
              c2_perm[2] = c2_c_i2;
              c2_perm[3] = c2_i4;
            } else {
              c2_perm[0] = c2_i3;
              c2_perm[1] = c2_c_i1;
              c2_perm[2] = c2_i4;
              c2_perm[3] = c2_c_i2;
            }
          } else {
            c2_perm[0] = c2_i3;
            c2_perm[1] = c2_i4;
            c2_perm[2] = c2_c_i1;
            c2_perm[3] = c2_c_i2;
          }

          c2_b_idx->data[c2_quartetOffset - 3] = c2_idx4[c2_perm[0] - 1];
          c2_b_idx->data[c2_quartetOffset - 2] = c2_idx4[c2_perm[1] - 1];
          c2_b_idx->data[c2_quartetOffset - 1] = c2_idx4[c2_perm[2] - 1];
          c2_b_idx->data[c2_quartetOffset] = c2_idx4[c2_perm[3] - 1];
          c2_k_x[0] = c2_d_x->size[0];
          c2_d_x->data[c2_quartetOffset - 3] = c2_x4[c2_perm[0] - 1];
          c2_l_x[0] = c2_d_x->size[0];
          c2_d_x->data[c2_quartetOffset - 2] = c2_x4[c2_perm[1] - 1];
          c2_m_x[0] = c2_d_x->size[0];
          c2_d_x->data[c2_quartetOffset - 1] = c2_x4[c2_perm[2] - 1];
          c2_n_x[0] = c2_d_x->size[0];
          c2_d_x->data[c2_quartetOffset] = c2_x4[c2_perm[3] - 1];
          c2_ib = 0;
        }
      }
    }

    c2_wOffset = (c2_b_n - c2_nNaNs) - 1;
    if (c2_ib > 0) {
      c2_c_n = c2_ib;
      for (c2_i1165 = 0; c2_i1165 < 4; c2_i1165++) {
        c2_perm[c2_i1165] = 0;
      }

      if (c2_c_n == 1) {
        c2_perm[0] = 1;
      } else if (c2_c_n == 2) {
        if (c2_x4[0] >= c2_x4[1]) {
          c2_perm[0] = 1;
          c2_perm[1] = 2;
        } else {
          c2_perm[0] = 2;
          c2_perm[1] = 1;
        }
      } else if (c2_x4[0] >= c2_x4[1]) {
        if (c2_x4[1] >= c2_x4[2]) {
          c2_perm[0] = 1;
          c2_perm[1] = 2;
          c2_perm[2] = 3;
        } else if (c2_x4[0] >= c2_x4[2]) {
          c2_perm[0] = 1;
          c2_perm[1] = 3;
          c2_perm[2] = 2;
        } else {
          c2_perm[0] = 3;
          c2_perm[1] = 1;
          c2_perm[2] = 2;
        }
      } else if (c2_x4[0] >= c2_x4[2]) {
        c2_perm[0] = 2;
        c2_perm[1] = 1;
        c2_perm[2] = 3;
      } else if (c2_x4[1] >= c2_x4[2]) {
        c2_perm[0] = 2;
        c2_perm[1] = 3;
        c2_perm[2] = 1;
      } else {
        c2_perm[0] = 3;
        c2_perm[1] = 2;
        c2_perm[2] = 1;
      }

      c2_f_b = c2_ib;
      c2_g_b = c2_f_b;
      if (1 > c2_g_b) {
        c2_c_overflow = false;
      } else {
        c2_c_overflow = (c2_g_b > 2147483646);
      }

      if (c2_c_overflow) {
        c2_check_forloop_overflow_error(chartInstance, true);
      }

      for (c2_d_k = 0; c2_d_k < c2_ib; c2_d_k++) {
        c2_b_k = c2_d_k;
        c2_b_idx->data[((c2_wOffset - c2_ib) + c2_b_k) + 1] =
          c2_idx4[c2_perm[c2_b_k] - 1];
        c2_i_x[0] = c2_d_x->size[0];
        c2_d_x->data[((c2_wOffset - c2_ib) + c2_b_k) + 1] = c2_x4[c2_perm[c2_b_k]
          - 1];
      }
    }

    c2_m = c2_nNaNs >> 1;
    c2_d_b = c2_m;
    c2_e_b = c2_d_b;
    if (1 > c2_e_b) {
      c2_b_overflow = false;
    } else {
      c2_b_overflow = (c2_e_b > 2147483646);
    }

    if (c2_b_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }

    for (c2_c_k = 1; c2_c_k - 1 < c2_m; c2_c_k++) {
      c2_b_k = c2_c_k;
      c2_itmp = c2_b_idx->data[c2_wOffset + c2_b_k];
      c2_i1166 = c2_b_idx->size[0];
      c2_i1167 = c2_i1166;
      c2_b_idx->data[c2_wOffset + c2_b_k] = c2_b_idx->data[c2_b_n - c2_b_k];
      c2_b_idx->data[c2_b_n - c2_b_k] = c2_itmp;
      c2_h_x[0] = c2_d_x->size[0];
      c2_d_x->data[c2_wOffset + c2_b_k] = c2_xwork->data[c2_b_n - c2_b_k];
      c2_j_x[0] = c2_d_x->size[0];
      c2_d_x->data[c2_b_n - c2_b_k] = c2_xwork->data[c2_wOffset + c2_b_k];
    }

    if ((c2_nNaNs & 1) != 0) {
      c2_g_x[0] = c2_d_x->size[0];
      c2_d_x->data[(c2_wOffset + c2_m) + 1] = c2_xwork->data[(c2_wOffset + c2_m)
        + 1];
    }

    c2_nNonNaN = c2_n - c2_nNaNs;
    c2_preSortLevel = 2;
    if (c2_nNonNaN > 1) {
      if (c2_n >= 256) {
        c2_nBlocks = c2_nNonNaN >> 8;
        if (c2_nBlocks > 0) {
          c2_h_b = c2_nBlocks;
          c2_i_b = c2_h_b;
          if (1 > c2_i_b) {
            c2_d_overflow = false;
          } else {
            c2_d_overflow = (c2_i_b > 2147483646);
          }

          if (c2_d_overflow) {
            c2_check_forloop_overflow_error(chartInstance, true);
          }

          for (c2_l_b = 0; c2_l_b < c2_nBlocks; c2_l_b++) {
            c2_m_b = c2_l_b;
            c2_offset = c2_m_b << 8;
            for (c2_n_b = 0; c2_n_b < 6; c2_n_b++) {
              c2_bLen = 1 << (c2_n_b + 2);
              c2_bLen2 = c2_bLen << 1;
              c2_nPairs = 256 >> (c2_n_b + 3);
              c2_q_b = c2_nPairs;
              c2_r_b = c2_q_b;
              if (1 > c2_r_b) {
                c2_g_overflow = false;
              } else {
                c2_g_overflow = (c2_r_b > 2147483646);
              }

              if (c2_g_overflow) {
                c2_check_forloop_overflow_error(chartInstance, true);
              }

              for (c2_i_k = 0; c2_i_k < c2_nPairs; c2_i_k++) {
                c2_j_k = c2_i_k;
                c2_blockOffset = (c2_offset + c2_j_k * c2_bLen2) - 1;
                c2_s_b = c2_bLen2;
                c2_t_b = c2_s_b;
                if (1 > c2_t_b) {
                  c2_h_overflow = false;
                } else {
                  c2_h_overflow = (c2_t_b > 2147483646);
                }

                if (c2_h_overflow) {
                  c2_check_forloop_overflow_error(chartInstance, true);
                }

                for (c2_j = 0; c2_j < c2_bLen2; c2_j++) {
                  c2_b_j = c2_j;
                  c2_c_iwork[c2_b_j] = c2_b_idx->data[(c2_blockOffset + c2_b_j)
                    + 1];
                  c2_b_xwork[c2_b_j] = c2_d_x->data[(c2_blockOffset + c2_b_j) +
                    1];
                }

                c2_p = 0;
                c2_q = c2_bLen;
                c2_iout = c2_blockOffset;
                do {
                  exitg1 = 0;
                  c2_iout++;
                  if (c2_b_xwork[c2_p] >= c2_b_xwork[c2_q]) {
                    c2_b_idx->data[c2_iout] = c2_c_iwork[c2_p];
                    c2_r_x[0] = c2_d_x->size[0];
                    c2_d_x->data[c2_iout] = c2_b_xwork[c2_p];
                    if (c2_p + 1 < c2_bLen) {
                      c2_p++;
                    } else {
                      exitg1 = 1;
                    }
                  } else {
                    c2_b_idx->data[c2_iout] = c2_c_iwork[c2_q];
                    c2_q_x[0] = c2_d_x->size[0];
                    c2_d_x->data[c2_iout] = c2_b_xwork[c2_q];
                    if (c2_q + 1 < c2_bLen2) {
                      c2_q++;
                    } else {
                      c2_offset1 = c2_iout - c2_p;
                      c2_l_a = c2_p + 1;
                      c2_u_b = c2_bLen;
                      c2_m_a = c2_l_a;
                      c2_v_b = c2_u_b;
                      if (c2_m_a > c2_v_b) {
                        c2_i_overflow = false;
                      } else {
                        c2_i_overflow = (c2_v_b > 2147483646);
                      }

                      if (c2_i_overflow) {
                        c2_check_forloop_overflow_error(chartInstance, true);
                      }

                      for (c2_c_j = c2_p + 1; c2_c_j <= c2_bLen; c2_c_j++) {
                        c2_b_idx->data[c2_offset1 + c2_c_j] = c2_c_iwork[c2_c_j
                          - 1];
                        c2_s_x[0] = c2_d_x->size[0];
                        c2_d_x->data[c2_offset1 + c2_c_j] = c2_b_xwork[c2_c_j -
                          1];
                      }

                      exitg1 = 1;
                    }
                  }
                } while (exitg1 == 0);
              }
            }
          }

          c2_tailOffset = c2_nBlocks << 8;
          c2_nLastBlock = c2_nNonNaN - c2_tailOffset;
          if (c2_nLastBlock > 0) {
            c2_d_merge_block(chartInstance, c2_b_idx, c2_d_x, c2_tailOffset,
                             c2_nLastBlock, 2, c2_b_iwork, c2_xwork);
          }

          c2_preSortLevel = 8;
        }
      }

      c2_d_merge_block(chartInstance, c2_b_idx, c2_d_x, 0, c2_nNonNaN,
                       c2_preSortLevel, c2_b_iwork, c2_xwork);
    }

    if ((c2_nNaNs > 0) && (c2_nNonNaN > 0)) {
      c2_b_nNonNaN = c2_nNonNaN - 1;
      c2_b_nNaNs = c2_nNaNs - 1;
      c2_j_b = c2_b_nNaNs + 1;
      c2_k_b = c2_j_b;
      if (1 > c2_k_b) {
        c2_e_overflow = false;
      } else {
        c2_e_overflow = (c2_k_b > 2147483646);
      }

      if (c2_e_overflow) {
        c2_check_forloop_overflow_error(chartInstance, true);
      }

      for (c2_e_k = 0; c2_e_k <= c2_b_nNaNs; c2_e_k++) {
        c2_g_k = c2_e_k;
        c2_xwork->data[c2_g_k] = c2_d_x->data[(c2_b_nNonNaN + c2_g_k) + 1];
        c2_b_iwork->data[c2_g_k] = c2_b_idx->data[(c2_b_nNonNaN + c2_g_k) + 1];
      }

      for (c2_f_k = c2_b_nNonNaN + 1; c2_f_k > 0; c2_f_k--) {
        c2_i1168 = c2_d_x->size[0];
        c2_o_x[0] = c2_d_x->size[0];
        c2_i1169 = c2_i1168;
        c2_d_x->data[c2_b_nNaNs + c2_f_k] = c2_d_x->data[c2_f_k - 1];
        c2_i1170 = c2_b_idx->size[0];
        c2_i1171 = c2_i1170;
        c2_b_idx->data[c2_b_nNaNs + c2_f_k] = c2_b_idx->data[c2_f_k - 1];
      }

      c2_o_b = c2_b_nNaNs + 1;
      c2_p_b = c2_o_b;
      if (1 > c2_p_b) {
        c2_f_overflow = false;
      } else {
        c2_f_overflow = (c2_p_b > 2147483646);
      }

      if (c2_f_overflow) {
        c2_check_forloop_overflow_error(chartInstance, true);
      }

      for (c2_h_k = 0; c2_h_k <= c2_b_nNaNs; c2_h_k++) {
        c2_g_k = c2_h_k;
        c2_p_x[0] = c2_d_x->size[0];
        c2_d_x->data[c2_g_k] = c2_xwork->data[c2_g_k];
        c2_b_idx->data[c2_g_k] = c2_b_iwork->data[c2_g_k];
      }
    }

    c2_emxFree_real_T(chartInstance, &c2_xwork);
    c2_emxFree_int32_T(chartInstance, &c2_b_iwork);
  }
}

static void c2_d_merge_block(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real_T *c2_d_x,
  int32_T c2_offset, int32_T c2_n, int32_T c2_preSortLevel, c2_emxArray_int32_T *
  c2_b_iwork, c2_emxArray_real_T *c2_xwork)
{
  int32_T c2_nBlocks;
  int32_T c2_bLen;
  int32_T c2_bLen2;
  int32_T c2_tailOffset;
  int32_T c2_nPairs;
  int32_T c2_nTail;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  c2_nBlocks = c2_n >> c2_preSortLevel;
  c2_bLen = 1 << c2_preSortLevel;
  while (c2_nBlocks > 1) {
    if ((c2_nBlocks & 1) != 0) {
      c2_nBlocks--;
      c2_tailOffset = c2_bLen * c2_nBlocks;
      c2_nTail = c2_n - c2_tailOffset;
      if (c2_nTail > c2_bLen) {
        c2_d_merge(chartInstance, c2_b_idx, c2_d_x, c2_offset + c2_tailOffset,
                   c2_bLen, c2_nTail - c2_bLen, c2_b_iwork, c2_xwork);
      }
    }

    c2_bLen2 = c2_bLen << 1;
    c2_nPairs = c2_nBlocks >> 1;
    c2_b = c2_nPairs;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }

    for (c2_k = 0; c2_k < c2_nPairs; c2_k++) {
      c2_b_k = c2_k;
      c2_d_merge(chartInstance, c2_b_idx, c2_d_x, c2_offset + c2_b_k * c2_bLen2,
                 c2_bLen, c2_bLen, c2_b_iwork, c2_xwork);
    }

    c2_bLen = c2_bLen2;
    c2_nBlocks = c2_nPairs;
  }

  if (c2_n > c2_bLen) {
    c2_d_merge(chartInstance, c2_b_idx, c2_d_x, c2_offset, c2_bLen, c2_n -
               c2_bLen, c2_b_iwork, c2_xwork);
  }
}

static void c2_d_merge(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_int32_T *c2_b_idx, c2_emxArray_real_T *c2_d_x, int32_T c2_offset,
  int32_T c2_np, int32_T c2_nq, c2_emxArray_int32_T *c2_b_iwork,
  c2_emxArray_real_T *c2_xwork)
{
  int32_T c2_n;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_j;
  int32_T c2_p;
  int32_T c2_b_j;
  int32_T c2_q;
  int32_T c2_qend;
  int32_T c2_iout;
  int32_T c2_c_idx[1];
  int32_T c2_d_idx[1];
  int32_T c2_e_x[1];
  int32_T c2_f_x[1];
  int32_T c2_offset1;
  int32_T c2_l_a;
  int32_T c2_c_b;
  int32_T c2_m_a;
  int32_T c2_d_b;
  boolean_T c2_b_overflow;
  int32_T c2_c_j;
  int32_T c2_e_idx[1];
  int32_T c2_g_x[1];
  int32_T exitg1;
  if (c2_nq == 0) {
  } else {
    c2_n = c2_np + c2_nq;
    c2_b = c2_n;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = false;
    } else {
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }

    for (c2_j = 0; c2_j < c2_n; c2_j++) {
      c2_b_j = c2_j;
      c2_b_iwork->data[c2_b_j] = c2_b_idx->data[c2_offset + c2_b_j];
      c2_xwork->data[c2_b_j] = c2_d_x->data[c2_offset + c2_b_j];
    }

    c2_p = 1;
    c2_q = c2_np;
    c2_qend = c2_np + c2_nq;
    c2_iout = c2_offset - 1;
    do {
      exitg1 = 0;
      c2_iout++;
      if (c2_xwork->data[c2_p - 1] >= c2_xwork->data[c2_q]) {
        c2_d_idx[0] = c2_b_idx->size[0];
        c2_b_idx->data[c2_iout] = c2_b_iwork->data[c2_p - 1];
        c2_f_x[0] = c2_d_x->size[0];
        c2_d_x->data[c2_iout] = c2_xwork->data[c2_p - 1];
        if (c2_p < c2_np) {
          c2_p++;
        } else {
          exitg1 = 1;
        }
      } else {
        c2_c_idx[0] = c2_b_idx->size[0];
        c2_b_idx->data[c2_iout] = c2_b_iwork->data[c2_q];
        c2_e_x[0] = c2_d_x->size[0];
        c2_d_x->data[c2_iout] = c2_xwork->data[c2_q];
        if (c2_q + 1 < c2_qend) {
          c2_q++;
        } else {
          c2_offset1 = (c2_iout - c2_p) + 1;
          c2_l_a = c2_p;
          c2_c_b = c2_np;
          c2_m_a = c2_l_a;
          c2_d_b = c2_c_b;
          if (c2_m_a > c2_d_b) {
            c2_b_overflow = false;
          } else {
            c2_b_overflow = (c2_d_b > 2147483646);
          }

          if (c2_b_overflow) {
            c2_check_forloop_overflow_error(chartInstance, true);
          }

          for (c2_c_j = c2_p; c2_c_j <= c2_np; c2_c_j++) {
            c2_e_idx[0] = c2_b_idx->size[0];
            c2_b_idx->data[c2_offset1 + c2_c_j] = c2_b_iwork->data[c2_c_j - 1];
            c2_g_x[0] = c2_d_x->size[0];
            c2_d_x->data[c2_offset1 + c2_c_j] = c2_xwork->data[c2_c_j - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void c2_b_sortrows(SFc2_flightControlSystemInstanceStruct *chartInstance,
  c2_emxArray_int32_T *c2_c_y, real_T c2_h_varargin_1[2])
{
  int32_T c2_k;
  boolean_T c2_p;
  real_T c2_b_k;
  real_T c2_d_x;
  real_T c2_e_x;
  const mxArray *c2_d_y = NULL;
  real_T c2_f_x;
  static char_T c2_cv79[32] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 's', 's',
    'o', 'r', 't', 'e', 'd', 'r', 'o', 'w', 's', ':', 'C', 'o', 'l', 'M', 'i',
    's', 'm', 'a', 't', 'c', 'h', 'X' };

  int32_T c2_i1172;
  real_T c2_ck;
  const mxArray *c2_e_y = NULL;
  real_T c2_g_x;
  c2_emxArray_int32_T *c2_b_idx;
  int32_T c2_col[2];
  real_T c2_h_x;
  int32_T c2_n;
  int32_T c2_i1173;
  int32_T c2_loop_ub;
  int32_T c2_i1174;
  c2_emxArray_int32_T *c2_b_iwork;
  int32_T c2_b_n;
  int32_T c2_len;
  int32_T c2_i1175;
  int32_T c2_iv20[1];
  int32_T c2_i1176;
  int32_T c2_np1;
  int32_T c2_i1177;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_c_k;
  c2_emxArray_int32_T *c2_f_y;
  int32_T c2_i1178;
  int32_T c2_i;
  c2_emxArray_int32_T *c2_g_y;
  int32_T c2_i1179;
  int32_T c2_i1180;
  int32_T c2_b_loop_ub;
  int32_T c2_l_a;
  int32_T c2_i1181;
  int32_T c2_m;
  int32_T c2_c_i2;
  int32_T c2_j;
  int32_T c2_i1182;
  int32_T c2_pEnd;
  int32_T c2_i1183;
  int32_T c2_b_col[2];
  int32_T c2_b_p;
  int32_T c2_b_j;
  int32_T c2_q;
  int32_T c2_qEnd;
  int32_T c2_c_j;
  int32_T c2_c_b;
  int32_T c2_d_b;
  int32_T c2_d_k;
  int32_T c2_kEnd;
  boolean_T c2_b_overflow;
  int32_T c2_i1184;
  int32_T c2_e_b;
  int32_T c2_b_i;
  int32_T c2_f_b;
  boolean_T c2_c_overflow;
  int32_T c2_i1185;
  int32_T c2_g_b;
  int32_T c2_c_i;
  int32_T c2_i1186;
  int32_T c2_h_b;
  int32_T c2_c_loop_ub;
  int32_T c2_i1187;
  boolean_T c2_d_overflow;
  int32_T c2_e_k;
  int32_T c2_i1188;
  int32_T c2_c_col[2];
  int32_T c2_d_i;
  int32_T exitg1;
  c2_k = 0;
  do {
    exitg1 = 0;
    if (c2_k < 2) {
      c2_b_k = 1.0 + (real_T)c2_k;
      c2_d_x = c2_h_varargin_1[(int32_T)c2_b_k - 1];
      c2_e_x = c2_d_x;
      c2_f_x = c2_e_x;
      c2_ck = muDoubleScalarAbs(c2_f_x);
      c2_g_x = c2_ck;
      c2_h_x = c2_g_x;
      c2_h_x = muDoubleScalarFloor(c2_h_x);
      if ((c2_h_x != c2_ck) || (c2_ck < 1.0) || (c2_ck > 2.0)) {
        c2_p = false;
        exitg1 = 1;
      } else {
        c2_k++;
      }
    } else {
      c2_p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (c2_p) {
  } else {
    c2_d_y = NULL;
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_cv79, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    c2_e_y = NULL;
    sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_cv79, 10, 0U, 1U, 0U, 2, 1, 32),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c2_d_y,
                      14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "getString", 1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
      "message", 1U, 1U, 14, c2_e_y)));
  }

  for (c2_i1172 = 0; c2_i1172 < 2; c2_i1172++) {
    c2_col[c2_i1172] = (int32_T)c2_h_varargin_1[c2_i1172];
  }

  c2_emxInit_int32_T(chartInstance, &c2_b_idx, 1, &c2_mk_emlrtRTEI);
  c2_n = c2_c_y->size[0];
  c2_i1173 = c2_b_idx->size[0];
  c2_b_idx->size[0] = c2_c_y->size[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_b_idx, c2_i1173,
    &c2_mk_emlrtRTEI);
  c2_loop_ub = c2_c_y->size[0] - 1;
  for (c2_i1174 = 0; c2_i1174 <= c2_loop_ub; c2_i1174++) {
    c2_b_idx->data[c2_i1174] = 0;
  }

  c2_emxInit_int32_T(chartInstance, &c2_b_iwork, 1, &c2_rk_emlrtRTEI);
  c2_b_n = c2_n;
  c2_len = c2_b_idx->size[0];
  c2_i1175 = c2_b_iwork->size[0];
  c2_b_iwork->size[0] = c2_len;
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_b_iwork, c2_i1175,
    &c2_nk_emlrtRTEI);
  c2_iv20[0] = c2_b_iwork->size[0];
  c2_i1176 = c2_b_iwork->size[0];
  c2_b_iwork->size[0] = c2_iv20[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_b_iwork, c2_i1176,
    &c2_ok_emlrtRTEI);
  c2_np1 = c2_b_n + 1;
  c2_i1177 = c2_b_n - 1;
  c2_b = c2_i1177;
  c2_b_b = c2_b;
  if (1 > c2_b_b) {
    c2_overflow = false;
  } else {
    c2_overflow = (c2_b_b > 2147483645);
  }

  if (c2_overflow) {
    c2_check_forloop_overflow_error(chartInstance, true);
  }

  c2_c_k = 1;
  c2_emxInit_int32_T1(chartInstance, &c2_f_y, 2, &c2_pk_emlrtRTEI);
  while (c2_c_k <= c2_i1177) {
    c2_i1178 = c2_f_y->size[0] * c2_f_y->size[1];
    c2_f_y->size[0] = c2_c_y->size[0];
    c2_f_y->size[1] = 2;
    c2_emxEnsureCapacity_int32_T1(chartInstance, c2_f_y, c2_i1178,
      &c2_pk_emlrtRTEI);
    c2_i1179 = c2_f_y->size[0];
    c2_i1180 = c2_f_y->size[1];
    c2_b_loop_ub = c2_c_y->size[0] * c2_c_y->size[1] - 1;
    for (c2_i1181 = 0; c2_i1181 <= c2_b_loop_ub; c2_i1181++) {
      c2_f_y->data[c2_i1181] = c2_c_y->data[c2_i1181];
    }

    for (c2_i1182 = 0; c2_i1182 < 2; c2_i1182++) {
      c2_b_col[c2_i1182] = c2_col[c2_i1182];
    }

    if (c2_b_sortLE(chartInstance, c2_f_y, c2_b_col, c2_c_k, c2_c_k + 1)) {
      c2_b_idx->data[c2_c_k - 1] = c2_c_k;
      c2_b_idx->data[c2_c_k] = c2_c_k + 1;
    } else {
      c2_b_idx->data[c2_c_k - 1] = c2_c_k + 1;
      c2_b_idx->data[c2_c_k] = c2_c_k;
    }

    c2_c_k += 2;
  }

  c2_emxFree_int32_T(chartInstance, &c2_f_y);
  if ((c2_b_n & 1) != 0) {
    c2_b_idx->data[c2_b_n - 1] = c2_b_n;
  }

  c2_i = 2;
  c2_emxInit_int32_T1(chartInstance, &c2_g_y, 2, &c2_pk_emlrtRTEI);
  while (c2_i < c2_b_n) {
    c2_l_a = c2_i;
    c2_c_i2 = c2_l_a << 1;
    c2_j = 1;
    for (c2_pEnd = 1 + c2_i; c2_pEnd < c2_np1; c2_pEnd = c2_qEnd + c2_i) {
      c2_b_p = c2_j - 1;
      c2_q = c2_pEnd - 1;
      c2_qEnd = c2_j + c2_c_i2;
      if (c2_qEnd > c2_np1) {
        c2_qEnd = c2_np1;
      }

      c2_d_k = 0;
      c2_kEnd = c2_qEnd - c2_j;
      while (c2_d_k + 1 <= c2_kEnd) {
        c2_i1184 = c2_g_y->size[0] * c2_g_y->size[1];
        c2_g_y->size[0] = c2_c_y->size[0];
        c2_g_y->size[1] = 2;
        c2_emxEnsureCapacity_int32_T1(chartInstance, c2_g_y, c2_i1184,
          &c2_pk_emlrtRTEI);
        c2_i1185 = c2_g_y->size[0];
        c2_i1186 = c2_g_y->size[1];
        c2_c_loop_ub = c2_c_y->size[0] * c2_c_y->size[1] - 1;
        for (c2_i1187 = 0; c2_i1187 <= c2_c_loop_ub; c2_i1187++) {
          c2_g_y->data[c2_i1187] = c2_c_y->data[c2_i1187];
        }

        for (c2_i1188 = 0; c2_i1188 < 2; c2_i1188++) {
          c2_c_col[c2_i1188] = c2_col[c2_i1188];
        }

        if (c2_b_sortLE(chartInstance, c2_g_y, c2_c_col, c2_b_idx->data[c2_b_p],
                        c2_b_idx->data[c2_q])) {
          c2_b_iwork->data[c2_d_k] = c2_b_idx->data[c2_b_p];
          c2_b_p++;
          if (c2_b_p + 1 == c2_pEnd) {
            while (c2_q + 1 < c2_qEnd) {
              c2_d_k++;
              c2_b_iwork->data[c2_d_k] = c2_b_idx->data[c2_q];
              c2_q++;
            }
          }
        } else {
          c2_b_iwork->data[c2_d_k] = c2_b_idx->data[c2_q];
          c2_q++;
          if (c2_q + 1 == c2_qEnd) {
            while (c2_b_p + 1 < c2_pEnd) {
              c2_d_k++;
              c2_b_iwork->data[c2_d_k] = c2_b_idx->data[c2_b_p];
              c2_b_p++;
            }
          }
        }

        c2_d_k++;
      }

      c2_b_p = c2_j - 2;
      c2_e_b = c2_kEnd;
      c2_f_b = c2_e_b;
      if (1 > c2_f_b) {
        c2_c_overflow = false;
      } else {
        c2_c_overflow = (c2_f_b > 2147483646);
      }

      if (c2_c_overflow) {
        c2_check_forloop_overflow_error(chartInstance, true);
      }

      for (c2_e_k = 0; c2_e_k < c2_kEnd; c2_e_k++) {
        c2_d_k = c2_e_k;
        c2_b_idx->data[(c2_b_p + c2_d_k) + 1] = c2_b_iwork->data[c2_d_k];
      }

      c2_j = c2_qEnd;
    }

    c2_i = c2_c_i2;
  }

  c2_emxFree_int32_T(chartInstance, &c2_g_y);
  c2_m = c2_c_y->size[0];
  c2_col[0] = c2_m;
  c2_col[1] = 1;
  c2_i1183 = c2_b_iwork->size[0];
  c2_b_iwork->size[0] = c2_col[0];
  c2_emxEnsureCapacity_int32_T(chartInstance, c2_b_iwork, c2_i1183,
    &c2_qk_emlrtRTEI);
  for (c2_b_j = 0; c2_b_j < 2; c2_b_j++) {
    c2_c_j = c2_b_j;
    c2_c_b = c2_m;
    c2_d_b = c2_c_b;
    if (1 > c2_d_b) {
      c2_b_overflow = false;
    } else {
      c2_b_overflow = (c2_d_b > 2147483646);
    }

    if (c2_b_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }

    for (c2_b_i = 0; c2_b_i < c2_m; c2_b_i++) {
      c2_c_i = c2_b_i;
      c2_b_iwork->data[c2_c_i] = c2_c_y->data[(c2_b_idx->data[c2_c_i] +
        c2_c_y->size[0] * c2_c_j) - 1];
    }

    c2_g_b = c2_m;
    c2_h_b = c2_g_b;
    if (1 > c2_h_b) {
      c2_d_overflow = false;
    } else {
      c2_d_overflow = (c2_h_b > 2147483646);
    }

    if (c2_d_overflow) {
      c2_check_forloop_overflow_error(chartInstance, true);
    }

    for (c2_d_i = 0; c2_d_i < c2_m; c2_d_i++) {
      c2_c_i = c2_d_i;
      c2_c_y->data[c2_c_i + c2_c_y->size[0] * c2_c_j] = c2_b_iwork->data[c2_c_i];
    }
  }

  c2_emxFree_int32_T(chartInstance, &c2_b_iwork);
  c2_emxFree_int32_T(chartInstance, &c2_b_idx);
}

static void c2_emxEnsureCapacity_real_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(real_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(real_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (real_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_skoeQIuVNKJRH
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_skoeQIuVNKJRHNtBIlOCZh *c2_emxArray, int32_T c2_oldNumel, const
   emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof
      (c2_skoeQIuVNKJRHNtBIlOCZhD));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(c2_skoeQIuVNKJRHNtBIlOCZhD) *
             (uint32_T)c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (c2_skoeQIuVNKJRHNtBIlOCZhD *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxInit_real_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_real_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_real_T *)emlrtMallocMex(sizeof(c2_emxArray_real_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (real_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_skoeQIuVNKJRHNtBIlOCZhD
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_skoeQIuVNKJRHNtBIlOCZh **c2_pEmxArray, int32_T c2_numDimensions,
   const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_skoeQIuVNKJRHNtBIlOCZh *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_skoeQIuVNKJRHNtBIlOCZh *)emlrtMallocMex(sizeof
    (c2_emxArray_skoeQIuVNKJRHNtBIlOCZh));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (c2_skoeQIuVNKJRHNtBIlOCZhD *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxFree_real_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_real_T *)NULL) {
    if (((*c2_pEmxArray)->data != (real_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c2_pEmxArray)->data);
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_real_T *)NULL;
  }
}

static void c2_emxFree_skoeQIuVNKJRHNtBIlOCZhD
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_skoeQIuVNKJRHNtBIlOCZh **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_skoeQIuVNKJRHNtBIlOCZh *)NULL) {
    if (((*c2_pEmxArray)->data != (c2_skoeQIuVNKJRHNtBIlOCZhD *)NULL) &&
        (*c2_pEmxArray)->canFreeData) {
      emlrtFreeMex((*c2_pEmxArray)->data);
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_skoeQIuVNKJRHNtBIlOCZh *)NULL;
  }
}

static void c2_emxEnsureCapacity_real_T1(SFc2_flightControlSystemInstanceStruct *
  chartInstance, c2_emxArray_real_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(real_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(real_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (real_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_int32_T(SFc2_flightControlSystemInstanceStruct *
  chartInstance, c2_emxArray_int32_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(int32_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(int32_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (int32_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxInit_int32_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_int32_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_int32_T *)emlrtMallocMex(sizeof
    (c2_emxArray_int32_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (int32_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_real_T1(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_real_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_real_T *)emlrtMallocMex(sizeof(c2_emxArray_real_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (real_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxFree_int32_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_int32_T *)NULL) {
    if (((*c2_pEmxArray)->data != (int32_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c2_pEmxArray)->data);
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_int32_T *)NULL;
  }
}

static void c2_emxEnsureCapacity_boolean_T
  (SFc2_flightControlSystemInstanceStruct *chartInstance, c2_emxArray_boolean_T *
   c2_emxArray, int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(boolean_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(boolean_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (boolean_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_boolean_T1
  (SFc2_flightControlSystemInstanceStruct *chartInstance, c2_emxArray_boolean_T *
   c2_emxArray, int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(boolean_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(boolean_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (boolean_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_creal_T(SFc2_flightControlSystemInstanceStruct *
  chartInstance, c2_emxArray_creal_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(creal_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(creal_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (creal_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxInit_boolean_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_boolean_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_boolean_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c2_emxArray_boolean_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (boolean_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_creal_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_creal_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_creal_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_creal_T *)emlrtMallocMex(sizeof
    (c2_emxArray_creal_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (creal_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_boolean_T1(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_boolean_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_boolean_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c2_emxArray_boolean_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (boolean_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxFree_boolean_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_boolean_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_boolean_T *)NULL) {
    if (((*c2_pEmxArray)->data != (boolean_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c2_pEmxArray)->data);
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_boolean_T *)NULL;
  }
}

static void c2_emxFree_creal_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_creal_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_creal_T *)NULL) {
    if (((*c2_pEmxArray)->data != (creal_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c2_pEmxArray)->data);
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_creal_T *)NULL;
  }
}

static void c2_emxEnsureCapacity_real32_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real32_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(real32_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(real32_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (real32_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxEnsureCapacity_creal_T1(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_creal_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(creal_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(creal_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (creal_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxInit_real32_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real32_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_real32_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_real32_T *)emlrtMallocMex(sizeof
    (c2_emxArray_real32_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (real32_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_creal_T1(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_creal_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_creal_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_creal_T *)emlrtMallocMex(sizeof
    (c2_emxArray_creal_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (creal_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxFree_real32_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real32_T **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_real32_T *)NULL) {
    if (((*c2_pEmxArray)->data != (real32_T *)NULL) && (*c2_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex((*c2_pEmxArray)->data);
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_real32_T *)NULL;
  }
}

static void c2_emxEnsureCapacity_real32_T1
  (SFc2_flightControlSystemInstanceStruct *chartInstance, c2_emxArray_real32_T
   *c2_emxArray, int32_T c2_oldNumel, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(real32_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(real32_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (real32_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxInit_real32_T1(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real32_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_real32_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_real32_T *)emlrtMallocMex(sizeof
    (c2_emxArray_real32_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (real32_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxEnsureCapacity_int32_T1(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T *c2_emxArray, int32_T c2_oldNumel, const
  emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof(int32_T));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(int32_T) * (uint32_T)
             c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (int32_T *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxInit_sBO2RC5RVZVTbundPSRqHnH
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_sBO2RC5RVZVTbundPSRqHn **c2_pEmxArray, int32_T c2_numDimensions,
   const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_sBO2RC5RVZVTbundPSRqHn *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_sBO2RC5RVZVTbundPSRqHn *)emlrtMallocMex(sizeof
    (c2_emxArray_sBO2RC5RVZVTbundPSRqHn));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (c2_sBO2RC5RVZVTbundPSRqHnH *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInit_int32_T1(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_int32_T **c2_pEmxArray, int32_T c2_numDimensions,
  const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_int32_T *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_int32_T *)emlrtMallocMex(sizeof
    (c2_emxArray_int32_T));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (int32_T *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxFree_sBO2RC5RVZVTbundPSRqHnH
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_sBO2RC5RVZVTbundPSRqHn **c2_pEmxArray)
{
  (void)chartInstance;
  if (*c2_pEmxArray != (c2_emxArray_sBO2RC5RVZVTbundPSRqHn *)NULL) {
    if (((*c2_pEmxArray)->data != (c2_sBO2RC5RVZVTbundPSRqHnH *)NULL) &&
        (*c2_pEmxArray)->canFreeData) {
      emlrtFreeMex((*c2_pEmxArray)->data);
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_sBO2RC5RVZVTbundPSRqHn *)NULL;
  }
}

static void c2_emxEnsureCapacity_sBO2RC5RVZVTb
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_sBO2RC5RVZVTbundPSRqHn *c2_emxArray, int32_T c2_oldNumel, const
   emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof
      (c2_sBO2RC5RVZVTbundPSRqHnH));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(c2_sBO2RC5RVZVTbundPSRqHnH) *
             (uint32_T)c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (c2_sBO2RC5RVZVTbundPSRqHnH *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }
}

static void c2_emxFreeStruct_s9uuw2Xu7QLvohu1q
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_s9uuw2Xu7QLvohu1q5iD2hG *c2_pStruct)
{
  c2_emxFree_real_T(chartInstance, &c2_pStruct->PixelIdxList);
  c2_emxFree_real_T(chartInstance, &c2_pStruct->PixelList);
  c2_emxFree_real_T(chartInstance, &c2_pStruct->PixelValues);
}

static void c2_emxTrim_s9uuw2Xu7QLvohu1q5iD2hG
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c2_emxArray, int32_T c2_fromIndex,
   int32_T c2_toIndex)
{
  int32_T c2_i;
  for (c2_i = c2_fromIndex; c2_i < c2_toIndex; c2_i++) {
    c2_emxFreeStruct_s9uuw2Xu7QLvohu1q(chartInstance, &c2_emxArray->data[c2_i]);
  }
}

static void c2_emxInitStruct_s9uuw2Xu7QLvohu1q
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_s9uuw2Xu7QLvohu1q5iD2hG *c2_pStruct, const emlrtRTEInfo *c2_srcLocation)
{
  c2_pStruct->Image.size[0] = 0;
  c2_pStruct->Image.size[1] = 0;
  c2_pStruct->FilledImage.size[0] = 0;
  c2_pStruct->FilledImage.size[1] = 0;
  c2_emxInit_real_T1(chartInstance, &c2_pStruct->PixelIdxList, 1, c2_srcLocation);
  c2_emxInit_real_T(chartInstance, &c2_pStruct->PixelList, 2, c2_srcLocation);
  c2_emxInit_real_T1(chartInstance, &c2_pStruct->PixelValues, 1, c2_srcLocation);
  c2_pStruct->SubarrayIdx.size[0] = 0;
  c2_pStruct->SubarrayIdx.size[1] = 0;
}

static void c2_emxExpand_s9uuw2Xu7QLvohu1q5iD2
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c2_emxArray, int32_T c2_fromIndex,
   int32_T c2_toIndex, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_i;
  for (c2_i = c2_fromIndex; c2_i < c2_toIndex; c2_i++) {
    c2_emxInitStruct_s9uuw2Xu7QLvohu1q(chartInstance, &c2_emxArray->data[c2_i],
      c2_srcLocation);
  }
}

static void c2_emxEnsureCapacity_s9uuw2Xu7QLvo
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c2_emxArray, int32_T c2_oldNumel, const
   emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_newNumel;
  int32_T c2_i;
  int32_T c2_newCapacity;
  void *c2_newData;
  if (c2_oldNumel < 0) {
    c2_oldNumel = 0;
  }

  c2_newNumel = 1;
  for (c2_i = 0; c2_i < c2_emxArray->numDimensions; c2_i++) {
    c2_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c2_newNumel, (uint32_T)
      c2_emxArray->size[c2_i], c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  if (c2_newNumel > c2_emxArray->allocatedSize) {
    c2_newCapacity = c2_emxArray->allocatedSize;
    if (c2_newCapacity < 16) {
      c2_newCapacity = 16;
    }

    while (c2_newCapacity < c2_newNumel) {
      if (c2_newCapacity > 1073741823) {
        c2_newCapacity = MAX_int32_T;
      } else {
        c2_newCapacity <<= 1;
      }
    }

    c2_newData = emlrtCallocMex((uint32_T)c2_newCapacity, sizeof
      (c2_s9uuw2Xu7QLvohu1q5iD2hG));
    if (c2_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
    }

    if (c2_emxArray->data != NULL) {
      memcpy(c2_newData, c2_emxArray->data, sizeof(c2_s9uuw2Xu7QLvohu1q5iD2hG) *
             (uint32_T)c2_oldNumel);
      if (c2_emxArray->canFreeData) {
        emlrtFreeMex(c2_emxArray->data);
      }
    }

    c2_emxArray->data = (c2_s9uuw2Xu7QLvohu1q5iD2hG *)c2_newData;
    c2_emxArray->allocatedSize = c2_newCapacity;
    c2_emxArray->canFreeData = true;
  }

  if (c2_oldNumel > c2_newNumel) {
    c2_emxTrim_s9uuw2Xu7QLvohu1q5iD2hG(chartInstance, c2_emxArray, c2_newNumel,
      c2_oldNumel);
  } else {
    if (c2_oldNumel < c2_newNumel) {
      c2_emxExpand_s9uuw2Xu7QLvohu1q5iD2(chartInstance, c2_emxArray, c2_oldNumel,
        c2_newNumel, c2_srcLocation);
    }
  }
}

static void c2_emxCopyStruct_s9uuw2Xu7QLvohu1q
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_s9uuw2Xu7QLvohu1q5iD2hG *c2_dst, const c2_s9uuw2Xu7QLvohu1q5iD2hG *c2_src,
   const emlrtRTEInfo *c2_srcLocation)
{
  c2_dst->Area = c2_src->Area;
  c2_emxCopyMatrix_real_T(chartInstance, c2_dst->Centroid, c2_src->Centroid,
    c2_srcLocation);
  c2_emxCopyMatrix_real_T1(chartInstance, c2_dst->BoundingBox,
    c2_src->BoundingBox, c2_srcLocation);
  c2_dst->MajorAxisLength = c2_src->MajorAxisLength;
  c2_dst->MinorAxisLength = c2_src->MinorAxisLength;
  c2_dst->Eccentricity = c2_src->Eccentricity;
  c2_dst->Orientation = c2_src->Orientation;
  c2_emxCopy_boolean_T_0x0(chartInstance, &c2_dst->Image, &c2_src->Image,
    c2_srcLocation);
  c2_emxCopy_boolean_T_0x0(chartInstance, &c2_dst->FilledImage,
    &c2_src->FilledImage, c2_srcLocation);
  c2_dst->FilledArea = c2_src->FilledArea;
  c2_dst->EulerNumber = c2_src->EulerNumber;
  c2_emxCopyMatrix_real_T2(chartInstance, c2_dst->Extrema, c2_src->Extrema,
    c2_srcLocation);
  c2_dst->EquivDiameter = c2_src->EquivDiameter;
  c2_dst->Extent = c2_src->Extent;
  c2_emxCopy_real_T(chartInstance, &c2_dst->PixelIdxList, &c2_src->PixelIdxList,
                    c2_srcLocation);
  c2_emxCopy_real_T1(chartInstance, &c2_dst->PixelList, &c2_src->PixelList,
                     c2_srcLocation);
  c2_dst->Perimeter = c2_src->Perimeter;
  c2_dst->Circularity = c2_src->Circularity;
  c2_emxCopy_real_T(chartInstance, &c2_dst->PixelValues, &c2_src->PixelValues,
                    c2_srcLocation);
  c2_emxCopyMatrix_real_T(chartInstance, c2_dst->WeightedCentroid,
    c2_src->WeightedCentroid, c2_srcLocation);
  c2_dst->MeanIntensity = c2_src->MeanIntensity;
  c2_dst->MinIntensity = c2_src->MinIntensity;
  c2_dst->MaxIntensity = c2_src->MaxIntensity;
  c2_emxCopy_real_T_1x0(chartInstance, &c2_dst->SubarrayIdx,
                        &c2_src->SubarrayIdx, c2_srcLocation);
  c2_emxCopyMatrix_real_T(chartInstance, c2_dst->SubarrayIdxLengths,
    c2_src->SubarrayIdxLengths, c2_srcLocation);
}

static void c2_emxCopyMatrix_real_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real_T c2_dst[2], const real_T c2_src[2], const emlrtRTEInfo
  *c2_srcLocation)
{
  int32_T c2_i;
  (void)chartInstance;
  (void)c2_srcLocation;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_dst[c2_i] = c2_src[c2_i];
  }
}

static void c2_emxCopyMatrix_real_T1(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real_T c2_dst[4], const real_T c2_src[4], const emlrtRTEInfo
  *c2_srcLocation)
{
  int32_T c2_i;
  (void)chartInstance;
  (void)c2_srcLocation;
  for (c2_i = 0; c2_i < 4; c2_i++) {
    c2_dst[c2_i] = c2_src[c2_i];
  }
}

static void c2_emxCopy_boolean_T_0x0(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_boolean_T_0x0 *c2_dst, const
  c2_emxArray_boolean_T_0x0 *c2_src, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_numElDst;
  int32_T c2_numElSrc;
  int32_T c2_i;
  (void)chartInstance;
  (void)c2_srcLocation;
  c2_numElDst = 1;
  c2_numElSrc = 1;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_numElDst *= c2_dst->size[c2_i];
    c2_numElSrc *= c2_src->size[c2_i];
  }

  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_dst->size[c2_i] = c2_src->size[c2_i];
  }

  for (c2_i = 0; c2_i < c2_numElSrc; c2_i++) {
    c2_i;
    0;
  }
}

static void c2_emxCopyMatrix_real_T2(SFc2_flightControlSystemInstanceStruct
  *chartInstance, real_T c2_dst[16], const real_T c2_src[16], const emlrtRTEInfo
  *c2_srcLocation)
{
  int32_T c2_i;
  (void)chartInstance;
  (void)c2_srcLocation;
  for (c2_i = 0; c2_i < 16; c2_i++) {
    c2_dst[c2_i] = c2_src[c2_i];
  }
}

static void c2_emxCopy_real_T(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T **c2_dst, c2_emxArray_real_T * const
  *c2_src, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_numElDst;
  int32_T c2_numElSrc;
  int32_T c2_i;
  c2_numElDst = 1;
  c2_numElSrc = 1;
  for (c2_i = 0; c2_i < (*c2_dst)->numDimensions; c2_i++) {
    c2_numElDst *= (*c2_dst)->size[c2_i];
    c2_numElSrc *= (*c2_src)->size[c2_i];
  }

  for (c2_i = 0; c2_i < (*c2_dst)->numDimensions; c2_i++) {
    (*c2_dst)->size[c2_i] = (*c2_src)->size[c2_i];
  }

  c2_emxEnsureCapacity_real_T1(chartInstance, *c2_dst, c2_numElDst,
    c2_srcLocation);
  for (c2_i = 0; c2_i < c2_numElSrc; c2_i++) {
    (*c2_dst)->data[c2_i] = (*c2_src)->data[c2_i];
  }
}

static void c2_emxCopy_real_T1(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T **c2_dst, c2_emxArray_real_T * const
  *c2_src, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_numElDst;
  int32_T c2_numElSrc;
  int32_T c2_i;
  c2_numElDst = 1;
  c2_numElSrc = 1;
  for (c2_i = 0; c2_i < (*c2_dst)->numDimensions; c2_i++) {
    c2_numElDst *= (*c2_dst)->size[c2_i];
    c2_numElSrc *= (*c2_src)->size[c2_i];
  }

  for (c2_i = 0; c2_i < (*c2_dst)->numDimensions; c2_i++) {
    (*c2_dst)->size[c2_i] = (*c2_src)->size[c2_i];
  }

  c2_emxEnsureCapacity_real_T(chartInstance, *c2_dst, c2_numElDst,
    c2_srcLocation);
  for (c2_i = 0; c2_i < c2_numElSrc; c2_i++) {
    (*c2_dst)->data[c2_i] = (*c2_src)->data[c2_i];
  }
}

static void c2_emxCopy_real_T_1x0(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_emxArray_real_T_1x0 *c2_dst, const c2_emxArray_real_T_1x0
  *c2_src, const emlrtRTEInfo *c2_srcLocation)
{
  int32_T c2_numElDst;
  int32_T c2_numElSrc;
  int32_T c2_i;
  (void)chartInstance;
  (void)c2_srcLocation;
  c2_numElDst = 1;
  c2_numElSrc = 1;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_numElDst *= c2_dst->size[c2_i];
    c2_numElSrc *= c2_src->size[c2_i];
  }

  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_dst->size[c2_i] = c2_src->size[c2_i];
  }

  for (c2_i = 0; c2_i < c2_numElSrc; c2_i++) {
    c2_i;
    0;
  }
}

static void c2_emxInitStruct_scIvRXQeSh8yxCxSm
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_scIvRXQeSh8yxCxSmtD63bE *c2_pStruct, const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxInit_real_T1(chartInstance, &c2_pStruct->RegionIndices, 1,
                     c2_srcLocation);
  c2_emxInit_int32_T(chartInstance, &c2_pStruct->RegionLengths, 1,
                     c2_srcLocation);
}

static void c2_emxInit_s9uuw2Xu7QLvohu1q5iD2hG
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_s9uuw2Xu7QLvohu1q5iD2h **c2_pEmxArray, int32_T c2_numDimensions,
   const emlrtRTEInfo *c2_srcLocation)
{
  c2_emxArray_s9uuw2Xu7QLvohu1q5iD2h *c2_emxArray;
  int32_T c2_i;
  *c2_pEmxArray = (c2_emxArray_s9uuw2Xu7QLvohu1q5iD2h *)emlrtMallocMex(sizeof
    (c2_emxArray_s9uuw2Xu7QLvohu1q5iD2h));
  if ((void *)*c2_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray = *c2_pEmxArray;
  c2_emxArray->data = (c2_s9uuw2Xu7QLvohu1q5iD2hG *)NULL;
  c2_emxArray->numDimensions = c2_numDimensions;
  c2_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c2_numDimensions);
  if ((void *)c2_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c2_srcLocation, chartInstance->c2_fEmlrtCtx);
  }

  c2_emxArray->allocatedSize = 0;
  c2_emxArray->canFreeData = true;
  for (c2_i = 0; c2_i < c2_numDimensions; c2_i++) {
    c2_emxArray->size[c2_i] = 0;
  }
}

static void c2_emxInitMatrix_cell_wrap_49(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_cell_wrap_49 c2_pMatrix[2], const emlrtRTEInfo
  *c2_srcLocation)
{
  int32_T c2_i;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_emxInitStruct_cell_wrap_49(chartInstance, &c2_pMatrix[c2_i],
      c2_srcLocation);
  }
}

static void c2_emxInitStruct_cell_wrap_49(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_cell_wrap_49 *c2_pStruct, const emlrtRTEInfo
  *c2_srcLocation)
{
  c2_emxInit_real_T1(chartInstance, &c2_pStruct->f1, 1, c2_srcLocation);
}

static void c2_emxFreeStruct_scIvRXQeSh8yxCxSm
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_scIvRXQeSh8yxCxSmtD63bE *c2_pStruct)
{
  c2_emxFree_real_T(chartInstance, &c2_pStruct->RegionIndices);
  c2_emxFree_int32_T(chartInstance, &c2_pStruct->RegionLengths);
}

static void c2_emxFree_s9uuw2Xu7QLvohu1q5iD2hG
  (SFc2_flightControlSystemInstanceStruct *chartInstance,
   c2_emxArray_s9uuw2Xu7QLvohu1q5iD2h **c2_pEmxArray)
{
  int32_T c2_numEl;
  int32_T c2_i;
  int32_T c2_b_i;
  if (*c2_pEmxArray != (c2_emxArray_s9uuw2Xu7QLvohu1q5iD2h *)NULL) {
    if ((*c2_pEmxArray)->data != (c2_s9uuw2Xu7QLvohu1q5iD2hG *)NULL) {
      c2_numEl = 1;
      for (c2_i = 0; c2_i < (*c2_pEmxArray)->numDimensions; c2_i++) {
        c2_numEl *= (*c2_pEmxArray)->size[c2_i];
      }

      for (c2_b_i = 0; c2_b_i < c2_numEl; c2_b_i++) {
        c2_emxFreeStruct_s9uuw2Xu7QLvohu1q(chartInstance, &(*c2_pEmxArray)->
          data[c2_b_i]);
      }

      if ((*c2_pEmxArray)->canFreeData) {
        emlrtFreeMex((*c2_pEmxArray)->data);
      }
    }

    emlrtFreeMex((*c2_pEmxArray)->size);
    emlrtFreeMex(*c2_pEmxArray);
    *c2_pEmxArray = (c2_emxArray_s9uuw2Xu7QLvohu1q5iD2h *)NULL;
  }
}

static void c2_emxFreeMatrix_cell_wrap_49(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_cell_wrap_49 c2_pMatrix[2])
{
  int32_T c2_i;
  for (c2_i = 0; c2_i < 2; c2_i++) {
    c2_emxFreeStruct_cell_wrap_49(chartInstance, &c2_pMatrix[c2_i]);
  }
}

static void c2_emxFreeStruct_cell_wrap_49(SFc2_flightControlSystemInstanceStruct
  *chartInstance, c2_cell_wrap_49 *c2_pStruct)
{
  c2_emxFree_real_T(chartInstance, &c2_pStruct->f1);
}

static int32_T c2_div_nzp_s32(SFc2_flightControlSystemInstanceStruct
  *chartInstance, int32_T c2_numerator, int32_T c2_denominator, int32_T
  c2_EMLOvCount_src_loc, uint32_T c2_ssid_src_loc, int32_T c2_offset_src_loc,
  int32_T c2_length_src_loc)
{
  int32_T c2_quotient;
  uint32_T c2_absNumerator;
  uint32_T c2_absDenominator;
  boolean_T c2_quotientNeedsNegation;
  uint32_T c2_tempAbsQuotient;
  (void)chartInstance;
  (void)c2_EMLOvCount_src_loc;
  (void)c2_ssid_src_loc;
  (void)c2_offset_src_loc;
  (void)c2_length_src_loc;
  if (c2_numerator < 0) {
    c2_absNumerator = ~(uint32_T)c2_numerator + 1U;
  } else {
    c2_absNumerator = (uint32_T)c2_numerator;
  }

  if (c2_denominator < 0) {
    c2_absDenominator = ~(uint32_T)c2_denominator + 1U;
  } else {
    c2_absDenominator = (uint32_T)c2_denominator;
  }

  c2_quotientNeedsNegation = ((c2_numerator < 0) != (c2_denominator < 0));
  c2_tempAbsQuotient = c2_absNumerator / c2_absDenominator;
  if (c2_quotientNeedsNegation) {
    c2_quotient = -(int32_T)c2_tempAbsQuotient;
  } else {
    c2_quotient = (int32_T)c2_tempAbsQuotient;
  }

  return c2_quotient;
}

static void init_dsm_address_info(SFc2_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c2_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_d_u = (real_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_data = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_b_y = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_number = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_data1 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_angle_ = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_angelina = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
}

/* SFunction Glue Code */
void sf_c2_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3523173939U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1874697832U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1016870159U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(801870676U);
}

mxArray *sf_c2_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,10);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Grayto8Buildable"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.GetnumcoresBuildable"));
  mxSetCell(mxcell3p, 2, mxCreateString(
             "images.internal.coder.buildable.IppfilterBuildable"));
  mxSetCell(mxcell3p, 3, mxCreateString(
             "images.internal.coder.buildable.ImfilterBuildable"));
  mxSetCell(mxcell3p, 4, mxCreateString(
             "images.internal.coder.buildable.CannyThresholdingTbbBuildable"));
  mxSetCell(mxcell3p, 5, mxCreateString(
             "images.internal.coder.buildable.IppreconstructBuildable"));
  mxSetCell(mxcell3p, 6, mxCreateString(
             "images.internal.coder.buildable.Bwlookup_tbb_Buildable"));
  mxSetCell(mxcell3p, 7, mxCreateString(
             "images.internal.coder.buildable.TbbhistBuildable"));
  mxSetCell(mxcell3p, 8, mxCreateString(
             "images.internal.coder.buildable.Ordfilt2Buildable"));
  mxSetCell(mxcell3p, 9, mxCreateString(
             "images.internal.coder.buildable.ImregionalmaxBuildable"));
  return(mxcell3p);
}

mxArray *sf_c2_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("grayto8_real64");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiAOYGFgYAPSHEDMxAABrFA+I5TNCBdngYsrAHFJZUEqSLy4KNkzBUjnJeaC+Ym"
    "lFZ55aflg8y0YEOazYTGfEcl8Tqg4BHywp0y/mgO6fhYs+jmQ9AtA+Yl56ak5mXmJfFDxgfWHEl"
    "H+YEXzB4ifkliSaAh1/8D7Q4sof7Ch+QPEzyvNTUotGiz+EAH7w4CAPxhR/MHIUEm1eFBwoEw/N"
    "N8TcL8CWjyA+JnF8YnJJZllqfHJRvFpOZnpGSXO+XklRfk5wZXFJam5MP8BAGdXLP0="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_flightControlSystemInstanceStruct *chartInstance =
      (SFc2_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _flightControlSystemMachineNumber_,
           2,
           1,
           1,
           0,
           7,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_flightControlSystemMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_flightControlSystemMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _flightControlSystemMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,1,1,0,"data");
          _SFD_SET_DATA_PROPS(2,1,1,0,"angle_");
          _SFD_SET_DATA_PROPS(3,2,0,1,"y");
          _SFD_SET_DATA_PROPS(4,2,0,1,"number");
          _SFD_SET_DATA_PROPS(5,2,0,1,"data1");
          _SFD_SET_DATA_PROPS(6,2,0,1,"angelina");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 120U;
          dimVector[1]= 160U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_i_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_h_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_h_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_h_sf_marshallOut,(MexInFcnForType)c2_f_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_h_sf_marshallOut,(MexInFcnForType)c2_f_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_h_sf_marshallOut,(MexInFcnForType)c2_f_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_h_sf_marshallOut,(MexInFcnForType)c2_f_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _flightControlSystemMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_flightControlSystemInstanceStruct *chartInstance =
      (SFc2_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c2_d_u);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c2_data);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c2_b_y);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c2_number);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c2_data1);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c2_angle_);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c2_angelina);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s3rHCupAxkjZLEOUyTKx2IC";
}

static void sf_opaque_initialize_c2_flightControlSystem(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_flightControlSystemInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_flightControlSystem
    ((SFc2_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c2_flightControlSystem((SFc2_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_flightControlSystem(void *chartInstanceVar)
{
  enable_c2_flightControlSystem((SFc2_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_flightControlSystem(void *chartInstanceVar)
{
  disable_c2_flightControlSystem((SFc2_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c2_flightControlSystem((SFc2_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c2_flightControlSystem
    ((SFc2_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c2_flightControlSystem((SFc2_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c2_flightControlSystem(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    finalize_c2_flightControlSystem((SFc2_flightControlSystemInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_flightControlSystem((SFc2_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_flightControlSystem(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_flightControlSystem
      ((SFc2_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
    initSimStructsc2_flightControlSystem((SFc2_flightControlSystemInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c2_flightControlSystem_get_post_codegen_info(void)
{
  return
    (
     "eNrtVttu20YQpRzZSIDEcIAEfQkKIw+N0ackRYGieahiSoKFyrFQ2g6QF2NFjsStlrvMXmQJ/YE"
     "gH9Dv6yfkEzJLyTazIik5yhUoAZpa+syZOTPD2fVqnUMPr2289+563hY+b+K94c2uzfm6lrtn7+"
     "veo/n6BEHcJD0iSaK8youTBP4CJZjRVPAOH4hCGOUDkMBDxKZC6jI2RRPDKB+1DQ8tn3oZ0zAOY"
     "mFYtI+2JDribIpsqdE95GlSCaFuA0Q6lsIM4zYjw8uIpT73YwhHyiRVEhTowKQ2LHVomKYpg9YE"
     "wg5XmmDE6iq2QBMNvp6UyrRKVXABFEnKKOGFamOiAkgxwRpO0gj/HhmNolxYGBOp9yEmY1BdOso"
     "4BQeXkyr8R59yooWkhLUS5lvDxdh6DOM5FBGwioRgbPsSyCgVlOvy+gdtVNripM+gCX0zLGcL4L"
     "WxxT+lcA6yNG8DX4xBkiEc8VKnWUJak6xal12yCNM0gVMin4dYPwVRafdi56iAYJ3gGC3KYJCJ7"
     "KhjSceY3lI2k3RsZy77ZEwyK7ZaBsvYWmOoqsIlWzvkPmFMlcKORdqFMbCMtUk0qYbNWItxqRQp"
     "GWLXRphk2+K+4BFdqEVolBaJj+3W7HZf4KQoDu4K1uEa5ICEUPTdqjCGyDBAoTiZdOaugDSiylZ"
     "rCWpe02UoTw0Mb54LOUKhFZ/9lQRbg6r5YOfyY+9qLt9eYS5f2LnPvRxPrYDHyz1dv7c2PsTfcP"
     "xu4JtarZbZNXJ2dxw/dcfO4nbwftP/8ffG6b1n7X//+/X+27v/LPNfW/Bfy35vz0HX2ce25+sHF"
     "wPjsp3GC1W02INcXPUC/h9y/DvztfpFHvgmfT4Z/f2q2zo6mR7/OXna8TO+Xr063k0n3ov3u3Zy"
     "TdNsDikZdqL5BmvXxMy2Hcv/Wy7erSX5uDV/P7ve/bGe/U8N174oXzedfNk14UPArZ3k+/fr6Xi"
     "4ko5NR4dd415Nnjjf4dfT8fNKOrYcHVuzSd+3e/G3oeNew50P9SX2O/hr+snqsNtYz37mv7ck/l"
     "2nDrvZueeM4ClmDGfh07MBo8PYbqZaChZMlYZke8X5XTU/r2vnfWG77yXO//Py+fWtch668ZF29"
     "TXPX1/Kbl191z0XrnOOdOec5+B31vDzufH553tull50"
     );
}

static void mdlSetWorkWidths_c2_flightControlSystem(SimStruct *S)
{
  sf_set_work_widths(S, sf_c2_flightControlSystem_get_post_codegen_info());
  ssSetChecksum0(S,(975069832U));
  ssSetChecksum1(S,(991188544U));
  ssSetChecksum2(S,(903910982U));
  ssSetChecksum3(S,(2064747029U));
}

static void mdlRTW_c2_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_flightControlSystem(SimStruct *S)
{
  SFc2_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc2_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_flightControlSystem;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_flightControlSystem;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_flightControlSystem;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0, NULL, NULL);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c2_flightControlSystem(chartInstance);
}

void c2_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
