#ifndef _ROS_vector_map_msgs_Lane_h
#define _ROS_vector_map_msgs_Lane_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace vector_map_msgs
{

  class Lane : public ros::Msg
  {
    public:
      typedef int32_t _lnid_type;
      _lnid_type lnid;
      typedef int32_t _did_type;
      _did_type did;
      typedef int32_t _blid_type;
      _blid_type blid;
      typedef int32_t _flid_type;
      _flid_type flid;
      typedef int32_t _bnid_type;
      _bnid_type bnid;
      typedef int32_t _fnid_type;
      _fnid_type fnid;
      typedef int32_t _jct_type;
      _jct_type jct;
      typedef int32_t _blid2_type;
      _blid2_type blid2;
      typedef int32_t _blid3_type;
      _blid3_type blid3;
      typedef int32_t _blid4_type;
      _blid4_type blid4;
      typedef int32_t _flid2_type;
      _flid2_type flid2;
      typedef int32_t _flid3_type;
      _flid3_type flid3;
      typedef int32_t _flid4_type;
      _flid4_type flid4;
      typedef int32_t _clossid_type;
      _clossid_type clossid;
      typedef float _span_type;
      _span_type span;
      typedef int32_t _lcnt_type;
      _lcnt_type lcnt;
      typedef int32_t _lno_type;
      _lno_type lno;
      typedef int32_t _lanetype_type;
      _lanetype_type lanetype;
      typedef int32_t _limitvel_type;
      _limitvel_type limitvel;
      typedef int32_t _refvel_type;
      _refvel_type refvel;
      typedef int32_t _roadsecid_type;
      _roadsecid_type roadsecid;
      typedef int32_t _lanecfgfg_type;
      _lanecfgfg_type lanecfgfg;
      typedef int32_t _linkwaid_type;
      _linkwaid_type linkwaid;
      enum { NORMAL = 0 };
      enum { LEFT_BRANCHING = 1 };
      enum { RIGHT_BRANCHING = 2 };
      enum { LEFT_MERGING = 3 };
      enum { RIGHT_MERGING = 4 };
      enum { COMPOSITION = 5 };
      enum { STRAIGHT = 0 };
      enum { LEFT_TURN = 1 };
      enum { RIGHT_TURN = 2 };
      enum { PASS = 0 };
      enum { FAIL = 1 };

    Lane():
      lnid(0),
      did(0),
      blid(0),
      flid(0),
      bnid(0),
      fnid(0),
      jct(0),
      blid2(0),
      blid3(0),
      blid4(0),
      flid2(0),
      flid3(0),
      flid4(0),
      clossid(0),
      span(0),
      lcnt(0),
      lno(0),
      lanetype(0),
      limitvel(0),
      refvel(0),
      roadsecid(0),
      lanecfgfg(0),
      linkwaid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_lnid;
      u_lnid.real = this->lnid;
      *(outbuffer + offset + 0) = (u_lnid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lnid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lnid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lnid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lnid);
      union {
        int32_t real;
        uint32_t base;
      } u_did;
      u_did.real = this->did;
      *(outbuffer + offset + 0) = (u_did.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_did.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_did.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_did.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->did);
      union {
        int32_t real;
        uint32_t base;
      } u_blid;
      u_blid.real = this->blid;
      *(outbuffer + offset + 0) = (u_blid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_blid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_blid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_blid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->blid);
      union {
        int32_t real;
        uint32_t base;
      } u_flid;
      u_flid.real = this->flid;
      *(outbuffer + offset + 0) = (u_flid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_flid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_flid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_flid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flid);
      union {
        int32_t real;
        uint32_t base;
      } u_bnid;
      u_bnid.real = this->bnid;
      *(outbuffer + offset + 0) = (u_bnid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bnid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bnid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bnid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bnid);
      union {
        int32_t real;
        uint32_t base;
      } u_fnid;
      u_fnid.real = this->fnid;
      *(outbuffer + offset + 0) = (u_fnid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fnid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fnid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fnid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fnid);
      union {
        int32_t real;
        uint32_t base;
      } u_jct;
      u_jct.real = this->jct;
      *(outbuffer + offset + 0) = (u_jct.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_jct.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_jct.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_jct.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->jct);
      union {
        int32_t real;
        uint32_t base;
      } u_blid2;
      u_blid2.real = this->blid2;
      *(outbuffer + offset + 0) = (u_blid2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_blid2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_blid2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_blid2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->blid2);
      union {
        int32_t real;
        uint32_t base;
      } u_blid3;
      u_blid3.real = this->blid3;
      *(outbuffer + offset + 0) = (u_blid3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_blid3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_blid3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_blid3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->blid3);
      union {
        int32_t real;
        uint32_t base;
      } u_blid4;
      u_blid4.real = this->blid4;
      *(outbuffer + offset + 0) = (u_blid4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_blid4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_blid4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_blid4.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->blid4);
      union {
        int32_t real;
        uint32_t base;
      } u_flid2;
      u_flid2.real = this->flid2;
      *(outbuffer + offset + 0) = (u_flid2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_flid2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_flid2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_flid2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flid2);
      union {
        int32_t real;
        uint32_t base;
      } u_flid3;
      u_flid3.real = this->flid3;
      *(outbuffer + offset + 0) = (u_flid3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_flid3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_flid3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_flid3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flid3);
      union {
        int32_t real;
        uint32_t base;
      } u_flid4;
      u_flid4.real = this->flid4;
      *(outbuffer + offset + 0) = (u_flid4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_flid4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_flid4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_flid4.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flid4);
      union {
        int32_t real;
        uint32_t base;
      } u_clossid;
      u_clossid.real = this->clossid;
      *(outbuffer + offset + 0) = (u_clossid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_clossid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_clossid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_clossid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->clossid);
      offset += serializeAvrFloat64(outbuffer + offset, this->span);
      union {
        int32_t real;
        uint32_t base;
      } u_lcnt;
      u_lcnt.real = this->lcnt;
      *(outbuffer + offset + 0) = (u_lcnt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lcnt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lcnt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lcnt.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lcnt);
      union {
        int32_t real;
        uint32_t base;
      } u_lno;
      u_lno.real = this->lno;
      *(outbuffer + offset + 0) = (u_lno.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lno.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lno.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lno.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lno);
      union {
        int32_t real;
        uint32_t base;
      } u_lanetype;
      u_lanetype.real = this->lanetype;
      *(outbuffer + offset + 0) = (u_lanetype.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lanetype.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lanetype.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lanetype.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lanetype);
      union {
        int32_t real;
        uint32_t base;
      } u_limitvel;
      u_limitvel.real = this->limitvel;
      *(outbuffer + offset + 0) = (u_limitvel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_limitvel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_limitvel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_limitvel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->limitvel);
      union {
        int32_t real;
        uint32_t base;
      } u_refvel;
      u_refvel.real = this->refvel;
      *(outbuffer + offset + 0) = (u_refvel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_refvel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_refvel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_refvel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->refvel);
      union {
        int32_t real;
        uint32_t base;
      } u_roadsecid;
      u_roadsecid.real = this->roadsecid;
      *(outbuffer + offset + 0) = (u_roadsecid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roadsecid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roadsecid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roadsecid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roadsecid);
      union {
        int32_t real;
        uint32_t base;
      } u_lanecfgfg;
      u_lanecfgfg.real = this->lanecfgfg;
      *(outbuffer + offset + 0) = (u_lanecfgfg.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lanecfgfg.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lanecfgfg.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lanecfgfg.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lanecfgfg);
      union {
        int32_t real;
        uint32_t base;
      } u_linkwaid;
      u_linkwaid.real = this->linkwaid;
      *(outbuffer + offset + 0) = (u_linkwaid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_linkwaid.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_linkwaid.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_linkwaid.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->linkwaid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_lnid;
      u_lnid.base = 0;
      u_lnid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lnid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lnid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lnid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lnid = u_lnid.real;
      offset += sizeof(this->lnid);
      union {
        int32_t real;
        uint32_t base;
      } u_did;
      u_did.base = 0;
      u_did.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_did.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_did.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_did.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->did = u_did.real;
      offset += sizeof(this->did);
      union {
        int32_t real;
        uint32_t base;
      } u_blid;
      u_blid.base = 0;
      u_blid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_blid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_blid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_blid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->blid = u_blid.real;
      offset += sizeof(this->blid);
      union {
        int32_t real;
        uint32_t base;
      } u_flid;
      u_flid.base = 0;
      u_flid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_flid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_flid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_flid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->flid = u_flid.real;
      offset += sizeof(this->flid);
      union {
        int32_t real;
        uint32_t base;
      } u_bnid;
      u_bnid.base = 0;
      u_bnid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bnid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bnid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bnid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bnid = u_bnid.real;
      offset += sizeof(this->bnid);
      union {
        int32_t real;
        uint32_t base;
      } u_fnid;
      u_fnid.base = 0;
      u_fnid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fnid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fnid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fnid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fnid = u_fnid.real;
      offset += sizeof(this->fnid);
      union {
        int32_t real;
        uint32_t base;
      } u_jct;
      u_jct.base = 0;
      u_jct.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_jct.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_jct.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_jct.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->jct = u_jct.real;
      offset += sizeof(this->jct);
      union {
        int32_t real;
        uint32_t base;
      } u_blid2;
      u_blid2.base = 0;
      u_blid2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_blid2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_blid2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_blid2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->blid2 = u_blid2.real;
      offset += sizeof(this->blid2);
      union {
        int32_t real;
        uint32_t base;
      } u_blid3;
      u_blid3.base = 0;
      u_blid3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_blid3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_blid3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_blid3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->blid3 = u_blid3.real;
      offset += sizeof(this->blid3);
      union {
        int32_t real;
        uint32_t base;
      } u_blid4;
      u_blid4.base = 0;
      u_blid4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_blid4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_blid4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_blid4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->blid4 = u_blid4.real;
      offset += sizeof(this->blid4);
      union {
        int32_t real;
        uint32_t base;
      } u_flid2;
      u_flid2.base = 0;
      u_flid2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_flid2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_flid2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_flid2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->flid2 = u_flid2.real;
      offset += sizeof(this->flid2);
      union {
        int32_t real;
        uint32_t base;
      } u_flid3;
      u_flid3.base = 0;
      u_flid3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_flid3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_flid3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_flid3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->flid3 = u_flid3.real;
      offset += sizeof(this->flid3);
      union {
        int32_t real;
        uint32_t base;
      } u_flid4;
      u_flid4.base = 0;
      u_flid4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_flid4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_flid4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_flid4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->flid4 = u_flid4.real;
      offset += sizeof(this->flid4);
      union {
        int32_t real;
        uint32_t base;
      } u_clossid;
      u_clossid.base = 0;
      u_clossid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_clossid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_clossid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_clossid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->clossid = u_clossid.real;
      offset += sizeof(this->clossid);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->span));
      union {
        int32_t real;
        uint32_t base;
      } u_lcnt;
      u_lcnt.base = 0;
      u_lcnt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lcnt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lcnt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lcnt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lcnt = u_lcnt.real;
      offset += sizeof(this->lcnt);
      union {
        int32_t real;
        uint32_t base;
      } u_lno;
      u_lno.base = 0;
      u_lno.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lno.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lno.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lno.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lno = u_lno.real;
      offset += sizeof(this->lno);
      union {
        int32_t real;
        uint32_t base;
      } u_lanetype;
      u_lanetype.base = 0;
      u_lanetype.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lanetype.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lanetype.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lanetype.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lanetype = u_lanetype.real;
      offset += sizeof(this->lanetype);
      union {
        int32_t real;
        uint32_t base;
      } u_limitvel;
      u_limitvel.base = 0;
      u_limitvel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_limitvel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_limitvel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_limitvel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->limitvel = u_limitvel.real;
      offset += sizeof(this->limitvel);
      union {
        int32_t real;
        uint32_t base;
      } u_refvel;
      u_refvel.base = 0;
      u_refvel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_refvel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_refvel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_refvel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->refvel = u_refvel.real;
      offset += sizeof(this->refvel);
      union {
        int32_t real;
        uint32_t base;
      } u_roadsecid;
      u_roadsecid.base = 0;
      u_roadsecid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roadsecid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roadsecid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roadsecid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->roadsecid = u_roadsecid.real;
      offset += sizeof(this->roadsecid);
      union {
        int32_t real;
        uint32_t base;
      } u_lanecfgfg;
      u_lanecfgfg.base = 0;
      u_lanecfgfg.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lanecfgfg.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lanecfgfg.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lanecfgfg.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lanecfgfg = u_lanecfgfg.real;
      offset += sizeof(this->lanecfgfg);
      union {
        int32_t real;
        uint32_t base;
      } u_linkwaid;
      u_linkwaid.base = 0;
      u_linkwaid.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_linkwaid.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_linkwaid.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_linkwaid.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->linkwaid = u_linkwaid.real;
      offset += sizeof(this->linkwaid);
     return offset;
    }

    const char * getType(){ return "vector_map_msgs/Lane"; };
    const char * getMD5(){ return "1967b64bed3d11de28c30e4af14007c3"; };

  };

}
#endif