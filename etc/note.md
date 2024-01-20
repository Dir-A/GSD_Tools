## Reference

https://github.com/shangjiaxuan/Crass-source/blob/4aff113b98fc39fb85f64501ab47c580df779a3d/cui-1.0.4/AGSD/AGSD.cpp



## Structure

```C
struct GSD_Pack_Info
{
	uint32_t uiFOA;
	uint32_t uiSize;
};

struct GSD_Pack_Entry
{
	GSD_Pack_Info Info;
	char aFileName[0x38];
};

struct GSD_Pack_HDR
{
	uint32_t uiEntryCount;
	GSD_Pack_Entry aEntry[uiEntryCount];
};

union GSD_STD_RawStr
{
  char *cpStr;
  char aStr[16];
};


struct GSD_STD_String
{
	GSD_STD_RawStr uStr;
	uint32_t uiLen;
	uint32_t uiReserve;
};

struct GSD_FS_Pack_Entry
{
	uint64_t uiFOA;
	uint64_t uiSize;
	char aFileName[0x70];
};

struct GSD_FS
{
  HANDLE hFile;
  uint32_t uiFilePointer_Back;
  uint32_t hFile_0;
  LARGE_INTEGER sOldFilePointer;
  uint32_t aUn0[3];
  LARGE_INTEGER sFilePointer;
  LARGE_INTEGER sFileSize;
  uint32_t hFile_1;
  uint32_t aUn1[28];
  uint32_t hFile_2;
  uint32_t aUn2[6];
  uint32_t hFile_3;
  uint32_t aUn3[6];
  uint32_t hFile_4;
  uint32_t aUn4[6];
  uint32_t uiSlot1_Handle;
  uint32_t uiSlot1_Un0;
  uint32_t uiSlot1_Handle_0;
  uint32_t aUn5[49];
  uint32_t pResSize;
  uint32_t nDecompressSize;
  uint32_t pResBuffer_Active;
  uint32_t uiEntryCount;
  uint32_t uiIsEntryMaxCount;
  uint32_t uiUnx;
  GSD_FS_Pack_Entry memEntry;
  uint8_t *pResBuffer_Org;
  uint32_t uiUnSize;
  uint32_t aUn6[52];
};

strutc GSD_Spt
{
	uint8_t ucDecBegIndex;
	uint8_t ucType;
	uint8_t ucUn1;
	uint8_t ucUn2;
};

struct GSD_Script_Decoder_One
{
	uint32_t aKey0[4];
};

struct GSD_Script_Decoder
{
	GSD_Script_Decoder_One[16];
};

struct GSD_ANIM_Entry
{
	uin8_t aUn[0x58];
};

struct GSD_ANIM_HDR
{
	char aSignature[0x8]; // "ANIMV450"
	uint32_t uiEntryCount;
	uint32_t uiWidth;
	uint32_	 uiHeigh;
};

struct GSD_ANIM
{
	GSD_ANIM_Entry EntryList[HDR.uiEntryCount];
	GSD_ANIM_HDR HDR;
}

struct GSD_BMZ
{
  uint8_t aSignature[4]; // ZLC3
  uint32_t uiDecompressSize;
  // zlib compress data
  if(BMZ_Size - 0x8 == "ANIMV450")
  {
	GSD_ANIM ANIM
  }
};

```



### SPT

```C
struct SPT_Code_Append_Data_Type0
{
  uint32_t uiNameSeq0; // char name seq in global.dat
  uint32_t uiNameSeq1; // char name seq in global.dat
  uint32_t uiUn2;
  uint32_t uiUn3;
  uint32_t uiCharCount;
  uint32_t uiStrType0Len;
  uint32_t uiStrType1Len;
  SPT_Char_Entry aCharIndex[uiCharCount]
  char aStrType0[uiStrType0Len + 1]
  char aStrType0[uiStrType1Len + 1]
};

// if str_len == 0 {size = 0x1D} else {size = 0x1D + strlen + 1}
struct SPT_Code_Append_Data_Type1_Ele
{
  uint32_t uiVal_0;
  uint32_t uiVal_1;
  uint32_t uiVal_2;
  uint32_t uiVal_3;
  uint32_t uiStrLen; // Val_4
  uint32_t uiVal_5;
  uint8_t uiVal_6;
  uint32_t uiVal_7;
  char aStr[uiStrLen + 1];
};

struct SPT_Code_Append_Data_Type2_Ele
{
  uint32_t uiType1Count;
  SPT_Code_Append_Type1 aAppendType1[uiType1Count];
};

struct SPT_Code_Append_Data_Type3_Ele
{
  uint32_t uiVal_0;
  uint32_t uiVal_1;
  uint32_t uiVal_2;
};

struct SPT_Code
{
  uint32_t uiCommand;
  uint32_t uiVal_1;
  uint32_t uiVal_2;
  uint32_t uiVal_3;
  uint32_t uiVal_4;
  uint32_t uiSequnece;
  uint32_t uiAppendDataCount_Type1;
  uint32_t uiAppendDataCount_Type2;
  uint32_t uiAppendDataCount_Type3;
  SPT_Code_Append_Data_Type0 aDataType0
  SPT_Code_Append_Data_Type1 aDataType1[uiAppendDataCount_Type1]
  SPT_Code_Append_Data_Type2 aDataType2[uiAppendDataCount_Type2]
  SPT_Code_Append_Data_Type3 aDataType3[uiAppendDataCount_Type3]
};

struct SPT_Append_Script_info
{
  uint32_t uiStrLen0;
  if uiStrLen0
  {
    char aScriptName[uiStrLen0];
  }
  uint32_t uiStrLen1;
  if uiStrLen1
  {
    char aScriptName[uiStrLen1];
  }
  uint32_t uiUn0;
  uint32_t uiUn1;
  uint32_t uiUn2;
  uint8_t aAppendData[0x80];
};

if uiScriptCount == 0 -> size = 4;
else size = 4 + SPT_Append_Script_info * uiScriptCount
struct SPT_Append_Script
{
  uint32_t uiScriptCount;
  if uiScriptCount
  {
    SPT_Append_Script_info Info[uiScriptCount]
  }
};

struct SPT_Encryptor_Info
{
    uint8_t ucDecStartIndex;
	uint8_t ucDecModeType;
	uint8_t ucUn0;
	uint8_t ucUn1;
};

struct SPT_Codes_Info
{
  uint32_t uiChunkCount;
  uint32_t uiUn0;
  uint32_t uiUn1;
  uint32_t uiUn2;
};

struct SPT
{
  SPT_Encryptor_Info Encryptor_Info;
  uint32_t uiUnFlag; // == 0
  uint32_t uiScriptNameLen;
  char aScriptName[uiScriptNameLen];
  SPT_Codes_Info ChunksInfo;
  SPT_Append_Script[0xF]
  uint32_t uiUnSize;
  SPT_Code[Block_Info.uiBlockCount]
};

struct Global_Dat_Str
{
    char aStr[260];
};

struct Global_Dat
{
    SPT_Encryptor_Info Encryptor_Info;
    uint32_t uiUnFlag; // == 0
    SPT_Append_Script[0xF];
    uint32_t uiGlobalStrCount;
    Global_Dat_Str aStrIndex[260];
    uint8_t aUnData[0x60];
};
```



## Command

```ASM
脚本偏移0x60进入第一个op
op -> 0x24字节

0x00000001
	PushStr



01000000 --> 判断文本消息结果位
00000000
00000000
00000000
00000000
13000000 --> 有可能只是个行号，随着文本次序递增
00000000
00000000
00000000

FFFFFFFF --> 字符开始？没懂啥玩意，好像没什么实际作用
FFFFFFFF
FFFFFFFF
FFFFFFFF


09000000 --> 字符个数
00000000
00000000

07000000
00000000
81770000 --> 字符

07000000
00000000
82E20000 --> 字符

07000000
00000000
829F0000 --> 字符

07000000
00000000
82C10000 --> 字符

07000000
00000000
82C10000 --> 字符

07000000
00000000
81490000 --> 字符

07000000
00000000
81490000 --> 字符

07000000
00000000
81780000 --> 字符

0D000000 --> 结束标志 '\n'
00000000
00000000
```


## Tips
spt脚本可以不用加密回去，spt脚本开头有2个字节，
第一个字节是查找解密表的开始位置，但程序里有判断，大于等于8就不解密
第二个字节是第一次解密的模式，大于2就不解密
这两个字节都是xor了0xF0的，所以把开头的两个字节改成0xFF就可以跳过解密了

bmz图片其实就是 头四个字节，'ZLC3' 然后四个字节是解压后大小，后面就全是zlib的压缩数据
zib压缩数据解密后其实就是个bmp图片（完整的bmp文件结构）直接把解压后的数据保存，然后后缀改成bmp就可以查看了
也可以用zlib压缩回去，但没什么必要，因为程序里会判断ZLC3标识，即文件开头不是ZLC3就不会进行解压操作
所以直接把bmz解密后的bmp图片后缀改成bmz就可以了

spt脚本目前看来，很像是按照块来读取的，不过里面的结构很奇葩，有可能是直接从vector里拷贝出来的数据，其中有些数据看起来像是乱码的
估计是它这个加密的锅，但不影响正常读取，文本似乎可以直接按照结构变长，随便测了一下，没什么问题，暂时先这样用着把吧。

