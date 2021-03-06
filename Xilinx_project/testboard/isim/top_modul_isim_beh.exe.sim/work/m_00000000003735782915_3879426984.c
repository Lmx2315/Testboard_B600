/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Work/Project_Testboard/Xilinx_project/testboard/spi_modul.v";
static int ng1[] = {0, 0};
static int ng2[] = {0, 0, 0, 0};
static unsigned int ng3[] = {12U, 0U};
static unsigned int ng4[] = {7U, 0U};
static int ng5[] = {1, 0};
static int ng6[] = {8, 0};
static unsigned int ng7[] = {1U, 0U};



static void Always_138_0(char *t0)
{
    char t4[8];
    char t7[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 4720U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(138, ng0);
    t2 = (t0 + 5784);
    *((int *)t2) = 1;
    t3 = (t0 + 4752);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(138, ng0);
    t5 = (t0 + 1800U);
    t6 = *((char **)t5);
    t5 = (t0 + 3000);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    memset(t7, 0, 8);
    t10 = (t7 + 4);
    t11 = (t9 + 4);
    t12 = *((unsigned int *)t9);
    t13 = (t12 >> 0);
    *((unsigned int *)t7) = t13;
    t14 = *((unsigned int *)t11);
    t15 = (t14 >> 0);
    *((unsigned int *)t10) = t15;
    t16 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t16 & 7U);
    t17 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t17 & 7U);
    xsi_vlogtype_concat(t4, 4, 4, 2U, t7, 3, t6, 1);
    t18 = (t0 + 3000);
    xsi_vlogvar_wait_assign_value(t18, t4, 0, 0, 4, 0LL);
    goto LAB2;

}

static void Always_139_1(char *t0)
{
    char t4[8];
    char t7[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 4968U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(139, ng0);
    t2 = (t0 + 5800);
    *((int *)t2) = 1;
    t3 = (t0 + 5000);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(139, ng0);
    t5 = (t0 + 2120U);
    t6 = *((char **)t5);
    t5 = (t0 + 3160);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    memset(t7, 0, 8);
    t10 = (t7 + 4);
    t11 = (t9 + 4);
    t12 = *((unsigned int *)t9);
    t13 = (t12 >> 0);
    *((unsigned int *)t7) = t13;
    t14 = *((unsigned int *)t11);
    t15 = (t14 >> 0);
    *((unsigned int *)t10) = t15;
    t16 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t16 & 7U);
    t17 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t17 & 7U);
    xsi_vlogtype_concat(t4, 4, 4, 2U, t7, 3, t6, 1);
    t18 = (t0 + 3160);
    xsi_vlogvar_wait_assign_value(t18, t4, 0, 0, 4, 0LL);
    goto LAB2;

}

static void Always_141_2(char *t0)
{
    char t13[8];
    char t30[16];
    char t31[8];
    char t57[8];
    char t79[8];
    char t82[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    char *t46;
    char *t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    char *t53;
    char *t54;
    char *t55;
    char *t56;
    char *t58;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    char *t72;
    char *t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    char *t80;
    char *t81;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    char *t93;
    int t94;
    int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;

LAB0:    t1 = (t0 + 5216U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(141, ng0);
    t2 = (t0 + 5816);
    *((int *)t2) = 1;
    t3 = (t0 + 5248);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(142, ng0);

LAB5:    xsi_set_current_line(144, ng0);
    t4 = (t0 + 2280U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(147, ng0);
    t2 = (t0 + 3160);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t13, 0, 8);
    t11 = (t4 + 4);
    t12 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = *((unsigned int *)t5);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t11);
    t10 = *((unsigned int *)t12);
    t14 = (t9 ^ t10);
    t15 = (t8 | t14);
    t16 = *((unsigned int *)t11);
    t17 = *((unsigned int *)t12);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB13;

LAB10:    if (t18 != 0)
        goto LAB12;

LAB11:    *((unsigned int *)t13) = 1;

LAB13:    t22 = (t13 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t13);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB14;

LAB15:    xsi_set_current_line(149, ng0);
    t2 = (t0 + 2120U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng1)));
    memset(t13, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t6 = *((unsigned int *)t3);
    t7 = *((unsigned int *)t2);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t14 = (t9 ^ t10);
    t15 = (t8 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB21;

LAB18:    if (t18 != 0)
        goto LAB20;

LAB19:    *((unsigned int *)t13) = 1;

LAB21:    t12 = (t13 + 4);
    t23 = *((unsigned int *)t12);
    t24 = (~(t23));
    t25 = *((unsigned int *)t13);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB22;

LAB23:
LAB24:
LAB16:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(145, ng0);

LAB9:    xsi_set_current_line(145, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 3480);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 8, 0LL);
    xsi_set_current_line(145, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3320);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    xsi_set_current_line(145, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3800);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 33, 0LL);
    xsi_set_current_line(145, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3640);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB8;

LAB12:    t21 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB13;

LAB14:    xsi_set_current_line(147, ng0);

LAB17:    xsi_set_current_line(147, ng0);
    t28 = ((char*)((ng1)));
    t29 = (t0 + 3480);
    xsi_vlogvar_wait_assign_value(t29, t28, 0, 0, 8, 0LL);
    xsi_set_current_line(147, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3320);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    xsi_set_current_line(147, ng0);
    t2 = (t0 + 1320U);
    t3 = *((char **)t2);
    memcpy(t30, t3, 8);
    t2 = (t30 + 8);
    memset(t2, 0, 8);
    t4 = (t0 + 3800);
    xsi_vlogvar_wait_assign_value(t4, t30, 0, 0, 33, 0LL);
    goto LAB16;

LAB20:    t11 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB21;

LAB22:    xsi_set_current_line(150, ng0);

LAB25:    xsi_set_current_line(151, ng0);
    t21 = (t0 + 3320);
    t22 = (t21 + 56U);
    t28 = *((char **)t22);
    t29 = ((char*)((ng1)));
    memset(t31, 0, 8);
    t32 = (t28 + 4);
    t33 = (t29 + 4);
    t34 = *((unsigned int *)t28);
    t35 = *((unsigned int *)t29);
    t36 = (t34 ^ t35);
    t37 = *((unsigned int *)t32);
    t38 = *((unsigned int *)t33);
    t39 = (t37 ^ t38);
    t40 = (t36 | t39);
    t41 = *((unsigned int *)t32);
    t42 = *((unsigned int *)t33);
    t43 = (t41 | t42);
    t44 = (~(t43));
    t45 = (t40 & t44);
    if (t45 != 0)
        goto LAB29;

LAB26:    if (t43 != 0)
        goto LAB28;

LAB27:    *((unsigned int *)t31) = 1;

LAB29:    t47 = (t31 + 4);
    t48 = *((unsigned int *)t47);
    t49 = (~(t48));
    t50 = *((unsigned int *)t31);
    t51 = (t50 & t49);
    t52 = (t51 != 0);
    if (t52 > 0)
        goto LAB30;

LAB31:    xsi_set_current_line(166, ng0);
    t2 = (t0 + 3320);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t13, 0, 8);
    t11 = (t4 + 4);
    t12 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = *((unsigned int *)t5);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t11);
    t10 = *((unsigned int *)t12);
    t14 = (t9 ^ t10);
    t15 = (t8 | t14);
    t16 = *((unsigned int *)t11);
    t17 = *((unsigned int *)t12);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB60;

LAB57:    if (t18 != 0)
        goto LAB59;

LAB58:    *((unsigned int *)t13) = 1;

LAB60:    t22 = (t13 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t13);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB61;

LAB62:
LAB63:
LAB32:    goto LAB24;

LAB28:    t46 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t46) = 1;
    goto LAB29;

LAB30:    xsi_set_current_line(152, ng0);

LAB33:    xsi_set_current_line(153, ng0);
    t53 = (t0 + 3000);
    t54 = (t53 + 56U);
    t55 = *((char **)t54);
    t56 = ((char*)((ng4)));
    memset(t57, 0, 8);
    t58 = (t55 + 4);
    t59 = (t56 + 4);
    t60 = *((unsigned int *)t55);
    t61 = *((unsigned int *)t56);
    t62 = (t60 ^ t61);
    t63 = *((unsigned int *)t58);
    t64 = *((unsigned int *)t59);
    t65 = (t63 ^ t64);
    t66 = (t62 | t65);
    t67 = *((unsigned int *)t58);
    t68 = *((unsigned int *)t59);
    t69 = (t67 | t68);
    t70 = (~(t69));
    t71 = (t66 & t70);
    if (t71 != 0)
        goto LAB37;

LAB34:    if (t69 != 0)
        goto LAB36;

LAB35:    *((unsigned int *)t57) = 1;

LAB37:    t73 = (t57 + 4);
    t74 = *((unsigned int *)t73);
    t75 = (~(t74));
    t76 = *((unsigned int *)t57);
    t77 = (t76 & t75);
    t78 = (t77 != 0);
    if (t78 > 0)
        goto LAB38;

LAB39:    xsi_set_current_line(158, ng0);
    t2 = (t0 + 3480);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng6)));
    memset(t13, 0, 8);
    t11 = (t4 + 4);
    t12 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = *((unsigned int *)t5);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t11);
    t10 = *((unsigned int *)t12);
    t14 = (t9 ^ t10);
    t15 = (t8 | t14);
    t16 = *((unsigned int *)t11);
    t17 = *((unsigned int *)t12);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB45;

LAB42:    if (t18 != 0)
        goto LAB44;

LAB43:    *((unsigned int *)t13) = 1;

LAB45:    t22 = (t13 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t13);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB46;

LAB47:
LAB48:
LAB40:    goto LAB32;

LAB36:    t72 = (t57 + 4);
    *((unsigned int *)t57) = 1;
    *((unsigned int *)t72) = 1;
    goto LAB37;

LAB38:    xsi_set_current_line(154, ng0);

LAB41:    xsi_set_current_line(155, ng0);
    t80 = (t0 + 1960U);
    t81 = *((char **)t80);
    t80 = (t0 + 2840);
    t83 = (t80 + 56U);
    t84 = *((char **)t83);
    memset(t82, 0, 8);
    t85 = (t82 + 4);
    t86 = (t84 + 4);
    t87 = *((unsigned int *)t84);
    t88 = (t87 >> 0);
    *((unsigned int *)t82) = t88;
    t89 = *((unsigned int *)t86);
    t90 = (t89 >> 0);
    *((unsigned int *)t85) = t90;
    t91 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t91 & 2147483647U);
    t92 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t92 & 2147483647U);
    xsi_vlogtype_concat(t79, 32, 32, 2U, t82, 31, t81, 1);
    t93 = (t0 + 2840);
    xsi_vlogvar_wait_assign_value(t93, t79, 0, 0, 32, 0LL);
    xsi_set_current_line(156, ng0);
    t2 = (t0 + 3480);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t13, 0, 8);
    xsi_vlog_unsigned_add(t13, 32, t4, 8, t5, 32);
    t11 = (t0 + 3480);
    xsi_vlogvar_wait_assign_value(t11, t13, 0, 0, 8, 0LL);
    goto LAB40;

LAB44:    t21 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB45;

LAB46:    xsi_set_current_line(159, ng0);

LAB49:    xsi_set_current_line(160, ng0);
    t28 = ((char*)((ng1)));
    t29 = (t0 + 3480);
    xsi_vlogvar_wait_assign_value(t29, t28, 0, 0, 8, 0LL);
    xsi_set_current_line(161, ng0);
    t2 = (t0 + 2840);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t13, 0, 8);
    t5 = (t13 + 4);
    t11 = (t4 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 0);
    *((unsigned int *)t13) = t7;
    t8 = *((unsigned int *)t11);
    t9 = (t8 >> 0);
    *((unsigned int *)t5) = t9;
    t10 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t10 & 127U);
    t14 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t14 & 127U);
    t12 = (t0 + 608);
    t21 = *((char **)t12);
    memset(t31, 0, 8);
    t12 = (t13 + 4);
    t22 = (t21 + 4);
    t15 = *((unsigned int *)t13);
    t16 = *((unsigned int *)t21);
    t17 = (t15 ^ t16);
    t18 = *((unsigned int *)t12);
    t19 = *((unsigned int *)t22);
    t20 = (t18 ^ t19);
    t23 = (t17 | t20);
    t24 = *((unsigned int *)t12);
    t25 = *((unsigned int *)t22);
    t26 = (t24 | t25);
    t27 = (~(t26));
    t34 = (t23 & t27);
    if (t34 != 0)
        goto LAB53;

LAB50:    if (t26 != 0)
        goto LAB52;

LAB51:    *((unsigned int *)t31) = 1;

LAB53:    t29 = (t31 + 4);
    t35 = *((unsigned int *)t29);
    t36 = (~(t35));
    t37 = *((unsigned int *)t31);
    t38 = (t37 & t36);
    t39 = (t38 != 0);
    if (t39 > 0)
        goto LAB54;

LAB55:
LAB56:    xsi_set_current_line(162, ng0);
    t2 = (t0 + 2840);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t13, 0, 8);
    t5 = (t13 + 4);
    t11 = (t4 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 7);
    t8 = (t7 & 1);
    *((unsigned int *)t13) = t8;
    t9 = *((unsigned int *)t11);
    t10 = (t9 >> 7);
    t14 = (t10 & 1);
    *((unsigned int *)t5) = t14;
    t12 = (t0 + 3640);
    xsi_vlogvar_wait_assign_value(t12, t13, 0, 0, 1, 0LL);
    goto LAB48;

LAB52:    t28 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB53;

LAB54:    xsi_set_current_line(161, ng0);
    t32 = ((char*)((ng5)));
    t33 = (t0 + 3320);
    xsi_vlogvar_wait_assign_value(t33, t32, 0, 0, 4, 0LL);
    goto LAB56;

LAB59:    t21 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB60;

LAB61:    xsi_set_current_line(167, ng0);

LAB64:    xsi_set_current_line(168, ng0);
    t28 = (t0 + 3640);
    t29 = (t28 + 56U);
    t32 = *((char **)t29);
    t33 = ((char*)((ng1)));
    memset(t31, 0, 8);
    t46 = (t32 + 4);
    t47 = (t33 + 4);
    t34 = *((unsigned int *)t32);
    t35 = *((unsigned int *)t33);
    t36 = (t34 ^ t35);
    t37 = *((unsigned int *)t46);
    t38 = *((unsigned int *)t47);
    t39 = (t37 ^ t38);
    t40 = (t36 | t39);
    t41 = *((unsigned int *)t46);
    t42 = *((unsigned int *)t47);
    t43 = (t41 | t42);
    t44 = (~(t43));
    t45 = (t40 & t44);
    if (t45 != 0)
        goto LAB68;

LAB65:    if (t43 != 0)
        goto LAB67;

LAB66:    *((unsigned int *)t31) = 1;

LAB68:    t54 = (t31 + 4);
    t48 = *((unsigned int *)t54);
    t49 = (~(t48));
    t50 = *((unsigned int *)t31);
    t51 = (t50 & t49);
    t52 = (t51 != 0);
    if (t52 > 0)
        goto LAB69;

LAB70:
LAB71:    goto LAB63;

LAB67:    t53 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t53) = 1;
    goto LAB68;

LAB69:    xsi_set_current_line(169, ng0);

LAB72:    xsi_set_current_line(170, ng0);
    t55 = (t0 + 3000);
    t56 = (t55 + 56U);
    t58 = *((char **)t56);
    t59 = ((char*)((ng3)));
    memset(t57, 0, 8);
    t72 = (t58 + 4);
    t73 = (t59 + 4);
    t60 = *((unsigned int *)t58);
    t61 = *((unsigned int *)t59);
    t62 = (t60 ^ t61);
    t63 = *((unsigned int *)t72);
    t64 = *((unsigned int *)t73);
    t65 = (t63 ^ t64);
    t66 = (t62 | t65);
    t67 = *((unsigned int *)t72);
    t68 = *((unsigned int *)t73);
    t69 = (t67 | t68);
    t70 = (~(t69));
    t71 = (t66 & t70);
    if (t71 != 0)
        goto LAB76;

LAB73:    if (t69 != 0)
        goto LAB75;

LAB74:    *((unsigned int *)t57) = 1;

LAB76:    t81 = (t57 + 4);
    t74 = *((unsigned int *)t81);
    t75 = (~(t74));
    t76 = *((unsigned int *)t57);
    t77 = (t76 & t75);
    t78 = (t77 != 0);
    if (t78 > 0)
        goto LAB77;

LAB78:    xsi_set_current_line(175, ng0);
    t2 = (t0 + 3480);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 472);
    t11 = *((char **)t5);
    memset(t13, 0, 8);
    t5 = (t4 + 4);
    t12 = (t11 + 4);
    t6 = *((unsigned int *)t4);
    t7 = *((unsigned int *)t11);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t12);
    t14 = (t9 ^ t10);
    t15 = (t8 | t14);
    t16 = *((unsigned int *)t5);
    t17 = *((unsigned int *)t12);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB84;

LAB81:    if (t18 != 0)
        goto LAB83;

LAB82:    *((unsigned int *)t13) = 1;

LAB84:    memset(t31, 0, 8);
    t22 = (t13 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t13);
    t26 = (t25 & t24);
    t27 = (t26 & 1U);
    if (t27 != 0)
        goto LAB85;

LAB86:    if (*((unsigned int *)t22) != 0)
        goto LAB87;

LAB88:    t29 = (t31 + 4);
    t34 = *((unsigned int *)t31);
    t35 = *((unsigned int *)t29);
    t36 = (t34 || t35);
    if (t36 > 0)
        goto LAB89;

LAB90:    memcpy(t82, t31, 8);

LAB91:    t83 = (t82 + 4);
    t100 = *((unsigned int *)t83);
    t101 = (~(t100));
    t102 = *((unsigned int *)t82);
    t103 = (t102 & t101);
    t104 = (t103 != 0);
    if (t104 > 0)
        goto LAB103;

LAB104:
LAB105:
LAB79:    goto LAB71;

LAB75:    t80 = (t57 + 4);
    *((unsigned int *)t57) = 1;
    *((unsigned int *)t80) = 1;
    goto LAB76;

LAB77:    xsi_set_current_line(171, ng0);

LAB80:    xsi_set_current_line(172, ng0);
    t83 = (t0 + 3800);
    t84 = (t83 + 56U);
    t85 = *((char **)t84);
    t86 = ((char*)((ng5)));
    xsi_vlog_unsigned_lshift(t30, 33, t85, 33, t86, 32);
    t93 = (t0 + 3800);
    xsi_vlogvar_wait_assign_value(t93, t30, 0, 0, 33, 0LL);
    xsi_set_current_line(173, ng0);
    t2 = (t0 + 3480);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t13, 0, 8);
    xsi_vlog_unsigned_add(t13, 32, t4, 8, t5, 32);
    t11 = (t0 + 3480);
    xsi_vlogvar_wait_assign_value(t11, t13, 0, 0, 8, 0LL);
    goto LAB79;

LAB83:    t21 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB84;

LAB85:    *((unsigned int *)t31) = 1;
    goto LAB88;

LAB87:    t28 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB88;

LAB89:    t32 = (t0 + 3000);
    t33 = (t32 + 56U);
    t46 = *((char **)t33);
    t47 = ((char*)((ng4)));
    memset(t57, 0, 8);
    t53 = (t46 + 4);
    t54 = (t47 + 4);
    t37 = *((unsigned int *)t46);
    t38 = *((unsigned int *)t47);
    t39 = (t37 ^ t38);
    t40 = *((unsigned int *)t53);
    t41 = *((unsigned int *)t54);
    t42 = (t40 ^ t41);
    t43 = (t39 | t42);
    t44 = *((unsigned int *)t53);
    t45 = *((unsigned int *)t54);
    t48 = (t44 | t45);
    t49 = (~(t48));
    t50 = (t43 & t49);
    if (t50 != 0)
        goto LAB95;

LAB92:    if (t48 != 0)
        goto LAB94;

LAB93:    *((unsigned int *)t57) = 1;

LAB95:    memset(t79, 0, 8);
    t56 = (t57 + 4);
    t51 = *((unsigned int *)t56);
    t52 = (~(t51));
    t60 = *((unsigned int *)t57);
    t61 = (t60 & t52);
    t62 = (t61 & 1U);
    if (t62 != 0)
        goto LAB96;

LAB97:    if (*((unsigned int *)t56) != 0)
        goto LAB98;

LAB99:    t63 = *((unsigned int *)t31);
    t64 = *((unsigned int *)t79);
    t65 = (t63 & t64);
    *((unsigned int *)t82) = t65;
    t59 = (t31 + 4);
    t72 = (t79 + 4);
    t73 = (t82 + 4);
    t66 = *((unsigned int *)t59);
    t67 = *((unsigned int *)t72);
    t68 = (t66 | t67);
    *((unsigned int *)t73) = t68;
    t69 = *((unsigned int *)t73);
    t70 = (t69 != 0);
    if (t70 == 1)
        goto LAB100;

LAB101:
LAB102:    goto LAB91;

LAB94:    t55 = (t57 + 4);
    *((unsigned int *)t57) = 1;
    *((unsigned int *)t55) = 1;
    goto LAB95;

LAB96:    *((unsigned int *)t79) = 1;
    goto LAB99;

LAB98:    t58 = (t79 + 4);
    *((unsigned int *)t79) = 1;
    *((unsigned int *)t58) = 1;
    goto LAB99;

LAB100:    t71 = *((unsigned int *)t82);
    t74 = *((unsigned int *)t73);
    *((unsigned int *)t82) = (t71 | t74);
    t80 = (t31 + 4);
    t81 = (t79 + 4);
    t75 = *((unsigned int *)t31);
    t76 = (~(t75));
    t77 = *((unsigned int *)t80);
    t78 = (~(t77));
    t87 = *((unsigned int *)t79);
    t88 = (~(t87));
    t89 = *((unsigned int *)t81);
    t90 = (~(t89));
    t94 = (t76 & t78);
    t95 = (t88 & t90);
    t91 = (~(t94));
    t92 = (~(t95));
    t96 = *((unsigned int *)t73);
    *((unsigned int *)t73) = (t96 & t91);
    t97 = *((unsigned int *)t73);
    *((unsigned int *)t73) = (t97 & t92);
    t98 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t98 & t91);
    t99 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t99 & t92);
    goto LAB102;

LAB103:    xsi_set_current_line(175, ng0);

LAB106:    xsi_set_current_line(175, ng0);
    t84 = ((char*)((ng1)));
    t85 = (t0 + 3480);
    xsi_vlogvar_wait_assign_value(t85, t84, 0, 0, 8, 0LL);
    xsi_set_current_line(175, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3320);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    goto LAB105;

}

static void Cont_181_3(char *t0)
{
    char t3[8];
    char t4[8];
    char t8[8];
    char t43[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    char *t42;
    char *t44;
    char *t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    char *t53;
    char *t54;
    char *t55;
    char *t56;
    char *t57;
    unsigned int t58;
    unsigned int t59;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;

LAB0:    t1 = (t0 + 5464U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(181, ng0);
    t2 = (t0 + 3320);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    memset(t8, 0, 8);
    t9 = (t6 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB7;

LAB4:    if (t20 != 0)
        goto LAB6;

LAB5:    *((unsigned int *)t8) = 1;

LAB7:    memset(t4, 0, 8);
    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 & 1U);
    if (t29 != 0)
        goto LAB8;

LAB9:    if (*((unsigned int *)t24) != 0)
        goto LAB10;

LAB11:    t31 = (t4 + 4);
    t32 = *((unsigned int *)t4);
    t33 = *((unsigned int *)t31);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB12;

LAB13:    t36 = *((unsigned int *)t4);
    t37 = (~(t36));
    t38 = *((unsigned int *)t31);
    t39 = (t37 || t38);
    if (t39 > 0)
        goto LAB14;

LAB15:    if (*((unsigned int *)t31) > 0)
        goto LAB16;

LAB17:    if (*((unsigned int *)t4) > 0)
        goto LAB18;

LAB19:    memcpy(t3, t43, 8);

LAB20:    t53 = (t0 + 5912);
    t54 = (t53 + 56U);
    t55 = *((char **)t54);
    t56 = (t55 + 56U);
    t57 = *((char **)t56);
    memset(t57, 0, 8);
    t58 = 1U;
    t59 = t58;
    t60 = (t3 + 4);
    t61 = *((unsigned int *)t3);
    t58 = (t58 & t61);
    t62 = *((unsigned int *)t60);
    t59 = (t59 & t62);
    t63 = (t57 + 4);
    t64 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t64 | t58);
    t65 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t65 | t59);
    xsi_driver_vfirst_trans(t53, 0, 0);
    t66 = (t0 + 5832);
    *((int *)t66) = 1;

LAB1:    return;
LAB6:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB7;

LAB8:    *((unsigned int *)t4) = 1;
    goto LAB11;

LAB10:    t30 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t30) = 1;
    goto LAB11;

LAB12:    t35 = ((char*)((ng7)));
    goto LAB13;

LAB14:    t40 = (t0 + 3800);
    t41 = (t40 + 56U);
    t42 = *((char **)t41);
    memset(t43, 0, 8);
    t44 = (t43 + 4);
    t45 = (t42 + 8);
    t46 = (t42 + 12);
    t47 = *((unsigned int *)t45);
    t48 = (t47 >> 0);
    t49 = (t48 & 1);
    *((unsigned int *)t43) = t49;
    t50 = *((unsigned int *)t46);
    t51 = (t50 >> 0);
    t52 = (t51 & 1);
    *((unsigned int *)t44) = t52;
    goto LAB15;

LAB16:    xsi_vlog_unsigned_bit_combine(t3, 1, t35, 1, t43, 1);
    goto LAB20;

LAB18:    memcpy(t3, t35, 8);
    goto LAB20;

}


extern void work_m_00000000003735782915_3879426984_init()
{
	static char *pe[] = {(void *)Always_138_0,(void *)Always_139_1,(void *)Always_141_2,(void *)Cont_181_3};
	xsi_register_didat("work_m_00000000003735782915_3879426984", "isim/top_modul_isim_beh.exe.sim/work/m_00000000003735782915_3879426984.didat");
	xsi_register_executes(pe);
}
