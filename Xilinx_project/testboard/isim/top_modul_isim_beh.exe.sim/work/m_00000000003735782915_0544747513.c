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
static unsigned int ng2[] = {12U, 0U};
static unsigned int ng3[] = {7U, 0U};
static int ng4[] = {1, 0};
static int ng5[] = {8, 0};
static unsigned int ng6[] = {1U, 0U};



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
    char t30[8];
    char t56[8];
    char t78[8];
    char t81[8];
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
    char *t31;
    char *t32;
    unsigned int t33;
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
    char *t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t53;
    char *t54;
    char *t55;
    char *t57;
    char *t58;
    unsigned int t59;
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
    char *t71;
    char *t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    char *t79;
    char *t80;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    char *t92;
    int t93;
    int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;

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
    t5 = ((char*)((ng2)));
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
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3800);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 17, 0LL);
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
    memcpy(t13, t3, 8);
    t2 = (t0 + 3800);
    xsi_vlogvar_wait_assign_value(t2, t13, 0, 0, 17, 0LL);
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
    memset(t30, 0, 8);
    t31 = (t28 + 4);
    t32 = (t29 + 4);
    t33 = *((unsigned int *)t28);
    t34 = *((unsigned int *)t29);
    t35 = (t33 ^ t34);
    t36 = *((unsigned int *)t31);
    t37 = *((unsigned int *)t32);
    t38 = (t36 ^ t37);
    t39 = (t35 | t38);
    t40 = *((unsigned int *)t31);
    t41 = *((unsigned int *)t32);
    t42 = (t40 | t41);
    t43 = (~(t42));
    t44 = (t39 & t43);
    if (t44 != 0)
        goto LAB29;

LAB26:    if (t42 != 0)
        goto LAB28;

LAB27:    *((unsigned int *)t30) = 1;

LAB29:    t46 = (t30 + 4);
    t47 = *((unsigned int *)t46);
    t48 = (~(t47));
    t49 = *((unsigned int *)t30);
    t50 = (t49 & t48);
    t51 = (t50 != 0);
    if (t51 > 0)
        goto LAB30;

LAB31:    xsi_set_current_line(166, ng0);
    t2 = (t0 + 3320);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
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

LAB28:    t45 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t45) = 1;
    goto LAB29;

LAB30:    xsi_set_current_line(152, ng0);

LAB33:    xsi_set_current_line(153, ng0);
    t52 = (t0 + 3000);
    t53 = (t52 + 56U);
    t54 = *((char **)t53);
    t55 = ((char*)((ng3)));
    memset(t56, 0, 8);
    t57 = (t54 + 4);
    t58 = (t55 + 4);
    t59 = *((unsigned int *)t54);
    t60 = *((unsigned int *)t55);
    t61 = (t59 ^ t60);
    t62 = *((unsigned int *)t57);
    t63 = *((unsigned int *)t58);
    t64 = (t62 ^ t63);
    t65 = (t61 | t64);
    t66 = *((unsigned int *)t57);
    t67 = *((unsigned int *)t58);
    t68 = (t66 | t67);
    t69 = (~(t68));
    t70 = (t65 & t69);
    if (t70 != 0)
        goto LAB37;

LAB34:    if (t68 != 0)
        goto LAB36;

LAB35:    *((unsigned int *)t56) = 1;

LAB37:    t72 = (t56 + 4);
    t73 = *((unsigned int *)t72);
    t74 = (~(t73));
    t75 = *((unsigned int *)t56);
    t76 = (t75 & t74);
    t77 = (t76 != 0);
    if (t77 > 0)
        goto LAB38;

LAB39:    xsi_set_current_line(158, ng0);
    t2 = (t0 + 3480);
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

LAB36:    t71 = (t56 + 4);
    *((unsigned int *)t56) = 1;
    *((unsigned int *)t71) = 1;
    goto LAB37;

LAB38:    xsi_set_current_line(154, ng0);

LAB41:    xsi_set_current_line(155, ng0);
    t79 = (t0 + 1960U);
    t80 = *((char **)t79);
    t79 = (t0 + 2840);
    t82 = (t79 + 56U);
    t83 = *((char **)t82);
    memset(t81, 0, 8);
    t84 = (t81 + 4);
    t85 = (t83 + 4);
    t86 = *((unsigned int *)t83);
    t87 = (t86 >> 0);
    *((unsigned int *)t81) = t87;
    t88 = *((unsigned int *)t85);
    t89 = (t88 >> 0);
    *((unsigned int *)t84) = t89;
    t90 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t90 & 32767U);
    t91 = *((unsigned int *)t84);
    *((unsigned int *)t84) = (t91 & 32767U);
    xsi_vlogtype_concat(t78, 16, 16, 2U, t81, 15, t80, 1);
    t92 = (t0 + 2840);
    xsi_vlogvar_wait_assign_value(t92, t78, 0, 0, 16, 0LL);
    xsi_set_current_line(156, ng0);
    t2 = (t0 + 3480);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
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
    memset(t30, 0, 8);
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
    t33 = (t23 & t27);
    if (t33 != 0)
        goto LAB53;

LAB50:    if (t26 != 0)
        goto LAB52;

LAB51:    *((unsigned int *)t30) = 1;

LAB53:    t29 = (t30 + 4);
    t34 = *((unsigned int *)t29);
    t35 = (~(t34));
    t36 = *((unsigned int *)t30);
    t37 = (t36 & t35);
    t38 = (t37 != 0);
    if (t38 > 0)
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

LAB52:    t28 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB53;

LAB54:    xsi_set_current_line(161, ng0);
    t31 = ((char*)((ng4)));
    t32 = (t0 + 3320);
    xsi_vlogvar_wait_assign_value(t32, t31, 0, 0, 4, 0LL);
    goto LAB56;

LAB59:    t21 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB60;

LAB61:    xsi_set_current_line(167, ng0);

LAB64:    xsi_set_current_line(168, ng0);
    t28 = (t0 + 3640);
    t29 = (t28 + 56U);
    t31 = *((char **)t29);
    t32 = ((char*)((ng1)));
    memset(t30, 0, 8);
    t45 = (t31 + 4);
    t46 = (t32 + 4);
    t33 = *((unsigned int *)t31);
    t34 = *((unsigned int *)t32);
    t35 = (t33 ^ t34);
    t36 = *((unsigned int *)t45);
    t37 = *((unsigned int *)t46);
    t38 = (t36 ^ t37);
    t39 = (t35 | t38);
    t40 = *((unsigned int *)t45);
    t41 = *((unsigned int *)t46);
    t42 = (t40 | t41);
    t43 = (~(t42));
    t44 = (t39 & t43);
    if (t44 != 0)
        goto LAB68;

LAB65:    if (t42 != 0)
        goto LAB67;

LAB66:    *((unsigned int *)t30) = 1;

LAB68:    t53 = (t30 + 4);
    t47 = *((unsigned int *)t53);
    t48 = (~(t47));
    t49 = *((unsigned int *)t30);
    t50 = (t49 & t48);
    t51 = (t50 != 0);
    if (t51 > 0)
        goto LAB69;

LAB70:
LAB71:    goto LAB63;

LAB67:    t52 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t52) = 1;
    goto LAB68;

LAB69:    xsi_set_current_line(169, ng0);

LAB72:    xsi_set_current_line(170, ng0);
    t54 = (t0 + 3000);
    t55 = (t54 + 56U);
    t57 = *((char **)t55);
    t58 = ((char*)((ng2)));
    memset(t56, 0, 8);
    t71 = (t57 + 4);
    t72 = (t58 + 4);
    t59 = *((unsigned int *)t57);
    t60 = *((unsigned int *)t58);
    t61 = (t59 ^ t60);
    t62 = *((unsigned int *)t71);
    t63 = *((unsigned int *)t72);
    t64 = (t62 ^ t63);
    t65 = (t61 | t64);
    t66 = *((unsigned int *)t71);
    t67 = *((unsigned int *)t72);
    t68 = (t66 | t67);
    t69 = (~(t68));
    t70 = (t65 & t69);
    if (t70 != 0)
        goto LAB76;

LAB73:    if (t68 != 0)
        goto LAB75;

LAB74:    *((unsigned int *)t56) = 1;

LAB76:    t80 = (t56 + 4);
    t73 = *((unsigned int *)t80);
    t74 = (~(t73));
    t75 = *((unsigned int *)t56);
    t76 = (t75 & t74);
    t77 = (t76 != 0);
    if (t77 > 0)
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

LAB84:    memset(t30, 0, 8);
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

LAB88:    t29 = (t30 + 4);
    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t29);
    t35 = (t33 || t34);
    if (t35 > 0)
        goto LAB89;

LAB90:    memcpy(t81, t30, 8);

LAB91:    t82 = (t81 + 4);
    t99 = *((unsigned int *)t82);
    t100 = (~(t99));
    t101 = *((unsigned int *)t81);
    t102 = (t101 & t100);
    t103 = (t102 != 0);
    if (t103 > 0)
        goto LAB103;

LAB104:
LAB105:
LAB79:    goto LAB71;

LAB75:    t79 = (t56 + 4);
    *((unsigned int *)t56) = 1;
    *((unsigned int *)t79) = 1;
    goto LAB76;

LAB77:    xsi_set_current_line(171, ng0);

LAB80:    xsi_set_current_line(172, ng0);
    t82 = (t0 + 3800);
    t83 = (t82 + 56U);
    t84 = *((char **)t83);
    t85 = ((char*)((ng4)));
    memset(t78, 0, 8);
    xsi_vlog_unsigned_lshift(t78, 17, t84, 17, t85, 32);
    t92 = (t0 + 3800);
    xsi_vlogvar_wait_assign_value(t92, t78, 0, 0, 17, 0LL);
    xsi_set_current_line(173, ng0);
    t2 = (t0 + 3480);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t13, 0, 8);
    xsi_vlog_unsigned_add(t13, 32, t4, 8, t5, 32);
    t11 = (t0 + 3480);
    xsi_vlogvar_wait_assign_value(t11, t13, 0, 0, 8, 0LL);
    goto LAB79;

LAB83:    t21 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB84;

LAB85:    *((unsigned int *)t30) = 1;
    goto LAB88;

LAB87:    t28 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB88;

LAB89:    t31 = (t0 + 3000);
    t32 = (t31 + 56U);
    t45 = *((char **)t32);
    t46 = ((char*)((ng3)));
    memset(t56, 0, 8);
    t52 = (t45 + 4);
    t53 = (t46 + 4);
    t36 = *((unsigned int *)t45);
    t37 = *((unsigned int *)t46);
    t38 = (t36 ^ t37);
    t39 = *((unsigned int *)t52);
    t40 = *((unsigned int *)t53);
    t41 = (t39 ^ t40);
    t42 = (t38 | t41);
    t43 = *((unsigned int *)t52);
    t44 = *((unsigned int *)t53);
    t47 = (t43 | t44);
    t48 = (~(t47));
    t49 = (t42 & t48);
    if (t49 != 0)
        goto LAB95;

LAB92:    if (t47 != 0)
        goto LAB94;

LAB93:    *((unsigned int *)t56) = 1;

LAB95:    memset(t78, 0, 8);
    t55 = (t56 + 4);
    t50 = *((unsigned int *)t55);
    t51 = (~(t50));
    t59 = *((unsigned int *)t56);
    t60 = (t59 & t51);
    t61 = (t60 & 1U);
    if (t61 != 0)
        goto LAB96;

LAB97:    if (*((unsigned int *)t55) != 0)
        goto LAB98;

LAB99:    t62 = *((unsigned int *)t30);
    t63 = *((unsigned int *)t78);
    t64 = (t62 & t63);
    *((unsigned int *)t81) = t64;
    t58 = (t30 + 4);
    t71 = (t78 + 4);
    t72 = (t81 + 4);
    t65 = *((unsigned int *)t58);
    t66 = *((unsigned int *)t71);
    t67 = (t65 | t66);
    *((unsigned int *)t72) = t67;
    t68 = *((unsigned int *)t72);
    t69 = (t68 != 0);
    if (t69 == 1)
        goto LAB100;

LAB101:
LAB102:    goto LAB91;

LAB94:    t54 = (t56 + 4);
    *((unsigned int *)t56) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB95;

LAB96:    *((unsigned int *)t78) = 1;
    goto LAB99;

LAB98:    t57 = (t78 + 4);
    *((unsigned int *)t78) = 1;
    *((unsigned int *)t57) = 1;
    goto LAB99;

LAB100:    t70 = *((unsigned int *)t81);
    t73 = *((unsigned int *)t72);
    *((unsigned int *)t81) = (t70 | t73);
    t79 = (t30 + 4);
    t80 = (t78 + 4);
    t74 = *((unsigned int *)t30);
    t75 = (~(t74));
    t76 = *((unsigned int *)t79);
    t77 = (~(t76));
    t86 = *((unsigned int *)t78);
    t87 = (~(t86));
    t88 = *((unsigned int *)t80);
    t89 = (~(t88));
    t93 = (t75 & t77);
    t94 = (t87 & t89);
    t90 = (~(t93));
    t91 = (~(t94));
    t95 = *((unsigned int *)t72);
    *((unsigned int *)t72) = (t95 & t90);
    t96 = *((unsigned int *)t72);
    *((unsigned int *)t72) = (t96 & t91);
    t97 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t97 & t90);
    t98 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t98 & t91);
    goto LAB102;

LAB103:    xsi_set_current_line(175, ng0);

LAB106:    xsi_set_current_line(175, ng0);
    t83 = ((char*)((ng1)));
    t84 = (t0 + 3480);
    xsi_vlogvar_wait_assign_value(t84, t83, 0, 0, 8, 0LL);
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
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t53;
    char *t54;
    char *t55;
    char *t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    char *t62;
    unsigned int t63;
    unsigned int t64;
    char *t65;

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

LAB20:    t52 = (t0 + 5912);
    t53 = (t52 + 56U);
    t54 = *((char **)t53);
    t55 = (t54 + 56U);
    t56 = *((char **)t55);
    memset(t56, 0, 8);
    t57 = 1U;
    t58 = t57;
    t59 = (t3 + 4);
    t60 = *((unsigned int *)t3);
    t57 = (t57 & t60);
    t61 = *((unsigned int *)t59);
    t58 = (t58 & t61);
    t62 = (t56 + 4);
    t63 = *((unsigned int *)t56);
    *((unsigned int *)t56) = (t63 | t57);
    t64 = *((unsigned int *)t62);
    *((unsigned int *)t62) = (t64 | t58);
    xsi_driver_vfirst_trans(t52, 0, 0);
    t65 = (t0 + 5832);
    *((int *)t65) = 1;

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

LAB12:    t35 = ((char*)((ng6)));
    goto LAB13;

LAB14:    t40 = (t0 + 3800);
    t41 = (t40 + 56U);
    t42 = *((char **)t41);
    memset(t43, 0, 8);
    t44 = (t43 + 4);
    t45 = (t42 + 4);
    t46 = *((unsigned int *)t42);
    t47 = (t46 >> 16);
    t48 = (t47 & 1);
    *((unsigned int *)t43) = t48;
    t49 = *((unsigned int *)t45);
    t50 = (t49 >> 16);
    t51 = (t50 & 1);
    *((unsigned int *)t44) = t51;
    goto LAB15;

LAB16:    xsi_vlog_unsigned_bit_combine(t3, 1, t35, 1, t43, 1);
    goto LAB20;

LAB18:    memcpy(t3, t35, 8);
    goto LAB20;

}


extern void work_m_00000000003735782915_0544747513_init()
{
	static char *pe[] = {(void *)Always_138_0,(void *)Always_139_1,(void *)Always_141_2,(void *)Cont_181_3};
	xsi_register_didat("work_m_00000000003735782915_0544747513", "isim/top_modul_isim_beh.exe.sim/work/m_00000000003735782915_0544747513.didat");
	xsi_register_executes(pe);
}
