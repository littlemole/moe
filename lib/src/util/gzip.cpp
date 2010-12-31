#include "util/gzip.h"
#include "StdAfx.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "zutil.h"
#include <string>

namespace mol {

//////////////////////////////////////////////////////////////////////////////////
// deflate
//////////////////////////////////////////////////////////////////////////////////

#define CHUNK 16384
std::string deflate( const std::string& src, int level )
{
	std::istringstream iss(src);
	return deflate( iss,level);
}

std::string deflate( std::istream& iss, int level )
{
    int ret, flush;
    unsigned have;
    z_stream strm;
    unsigned char in[CHUNK];
    unsigned char out[CHUNK];

    /* allocate deflate state */
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    ret = deflateInit(&strm, level);
    if (ret != Z_OK)
        return "";

	std::ostringstream dest;
	size_t nread = 0;
    /* compress until end of file */
    do {
		size_t want = CHUNK;//(src.size()-nread) > CHUNK ? CHUNK : (src.size()-nread);
		iss.read( (char*)in,want);
		size_t s = iss.gcount();
		strm.avail_in = (uInt)s;

        flush = iss.eof() ? Z_FINISH : Z_NO_FLUSH;
        strm.next_in = in;

        /* run deflate() on input until output buffer not full, finish
           compression if all of source has been read in */
        do {
            strm.avail_out = CHUNK;
            strm.next_out = out;
            ret = deflate(&strm, flush);    /* no bad return value */
            //assert(ret != Z_STREAM_ERROR);  /* state not clobbered */
            have = CHUNK - strm.avail_out;
			dest.write( (const char*)out,have);
			if ( dest.bad() )
			{
                (void)deflateEnd(&strm);
                return "";
            }
        } while (strm.avail_out == 0);
        //assert(strm.avail_in == 0);     /* all input will be used */

        /* done when last data in file processed */
    } while (flush != Z_FINISH);
    //assert(ret == Z_STREAM_END);        /* stream will be complete */

    /* clean up and return */
    (void)deflateEnd(&strm);

	return dest.str();
}

/* Decompress from file source to file dest until stream ends or EOF.
   inf() returns Z_OK on success, Z_MEM_ERROR if memory could not be
   allocated for processing, Z_DATA_ERROR if the deflate data is
   invalid or incomplete, Z_VERSION_ERROR if the version of zlib.h and
   the version of the library linked do not match, or Z_ERRNO if there
   is an error reading or writing the files. */
std::string inflate(const std::string& src,int bits)
{
	std::istringstream iss(src);
	return inflate(iss,bits);
}

std::string inflate( std::istream& iss,int bits)
{
    int ret;
    unsigned have;
    z_stream strm;
    unsigned char in[CHUNK];
    unsigned char out[CHUNK];

    /* allocate inflate state */
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = 0;
    strm.next_in = Z_NULL;
    ret = inflateInit2(&strm,-bits);
    if (ret != Z_OK)
        return "";

	//std::istringstream iss(src);
	std::ostringstream dest;
	size_t nread = 0;
    /* decompress until deflate stream ends or end of file */
    do {
		size_t want = CHUNK;//(src.size()-nread) > CHUNK ? CHUNK : (src.size()-nread);
		iss.read( (char*)in, want );
		size_t s = iss.gcount();
		nread += s;
		strm.avail_in = (uInt)s;
        if (s == 0)
            break;
        strm.next_in = in;

        /* run inflate() on input until output buffer not full */
        do {
            strm.avail_out = CHUNK;
            strm.next_out = out;
            ret = inflate(&strm, Z_NO_FLUSH);
            //assert(ret != Z_STREAM_ERROR);  /* state not clobbered */
            switch (ret) {
            case Z_NEED_DICT:
                ret = Z_DATA_ERROR;     /* and fall through */
            case Z_DATA_ERROR:
            case Z_MEM_ERROR:
                (void)inflateEnd(&strm);
                return "";
            }
            have = CHUNK - strm.avail_out;
			dest.write( (const char*)out,have);
			if ( dest.bad() )
			{
                (void)inflateEnd(&strm);
                return "";
            }
        } while (strm.avail_out == 0);

        /* done when inflate() says it's done */
    } while (ret != Z_STREAM_END);

    /* clean up and return */
    (void)inflateEnd(&strm);

	return dest.str();
}

//////////////////////////////////////////////////////////////////////////////////
// GZIP
//////////////////////////////////////////////////////////////////////////////////

#define ASCII_FLAG   0x01 /* bit 0 set: file probably ascii text */
#define HEAD_CRC     0x02 /* bit 1 set: header CRC present */
#define EXTRA_FIELD  0x04 /* bit 2 set: extra field present */
#define ORIG_NAME    0x08 /* bit 3 set: original file name present */
#define COMMENT      0x10 /* bit 4 set: file comment present */
#define RESERVED     0xE0 /* bits 5..7: reserved */

//////////////////////////////////////////////////////////////////////////////////

const int Z_BUFSIZE = 4096;

static const int gz_magic[2] = {0x1f, 0x8b}; /* gzip magic header */

//////////////////////////////////////////////////////////////////////////////////


typedef  unsigned char GZIP;
typedef  GZIP* LPGZIP;

class GzipImpl
{
public:

  GzipImpl(const std::string& in, const int nLevel = Z_DEFAULT_COMPRESSION, const int nStrategy = Z_DEFAULT_STRATEGY );
  ~GzipImpl();

  std::string gzipped();

private:  

   void dozip ();

   int write( LPGZIP buf, int count );
   int finish();
   int destroy();
   void putLong (uLong x);

   const std::string& input_;
   const int nLevel_ ;
   const int nStrategy_;

   size_t size_;
   GZIP* pgzip_;

   static const size_t nBufferLen_ = 1024;
   GZIP buffer_[nBufferLen_];
   int currentBufferSize_;
   Byte* outbuffer_;

   int z_err_;
   z_stream zstream_;
};

////////////////////////////////////////////////////////////////////////////////////


class GunzipImpl
{
public:

  GunzipImpl(LPGZIP pgzip,int len);
  GunzipImpl(const std::string& gzipped);
  ~GunzipImpl();

  std::string toString();

private:

   void init();
   
   void check_header();
   int get_byte();
   int read(LPGZIP buf,int size);
   int gzread(char* buf,int len);
   uLong getLong();
   int write(char* buf,int count);
   int destroy();

   static const int nBufferLen_ = 1024;
   char *psz_;
   int  length_;

   char buffer_[nBufferLen_+1];
   int currentBufferSize_;

   z_stream zstream_;
   int      z_err_;   
   Byte     *inbuffer_;
   uLong    crc_;    
   int      z_eof_;
   int      transparent_;

   int      pos_;
   LPGZIP   gzip_;
   int      gziplen_;
};

//////////////////////////////////////////////////////////////////////////////////


std::string gzip(const std::string& src, const int nLevel, const int nStrategy )
{
	GzipImpl gz(src,nLevel,nStrategy);
	return gz.gzipped();
}

std::string gunzip(const std::string& src)
{
	GunzipImpl gunz(src);
	return gunz.toString();
}



GzipImpl::GzipImpl(const std::string& in, const int nLevel, const int nStrategy )
  : input_(in), nLevel_(nLevel), nStrategy_(nStrategy)
{
	size_ = 0;
	pgzip_ = 0;
	currentBufferSize_ = 0;

	zstream_.zalloc = (alloc_func)0;
	zstream_.zfree = (free_func)0;
	zstream_.opaque = (voidpf)0;
	zstream_.next_in = Z_NULL;
	zstream_.next_out = Z_NULL;
	zstream_.avail_in = 0;
	zstream_.avail_out = 0;

	z_err_ = Z_OK; 

	dozip();
}

std::string GzipImpl::gzipped() 
{
	  if ( z_err_ < 0 )
		  return "";

	  return std::string( (const char*)pgzip_, size_);
}

GzipImpl::~GzipImpl()
{
	destroy();
}

void GzipImpl::dozip ()
{
	 // input
     char * lpsz = (char*)(input_.c_str());
     size_t len  = input_.size()+1;
    
     uLong    crc = crc32(0L, Z_NULL, 0);     /* crc32 of uncompressed data */
   
     currentBufferSize_ = nBufferLen_;
     pgzip_ = buffer_;   
     
     crc = crc32(0L, Z_NULL, 0);
     
     int err = deflateInit2( &zstream_, nLevel_,Z_DEFLATED, -MAX_WBITS, DEF_MEM_LEVEL, nStrategy_);
     outbuffer_ = (Byte*)malloc(Z_BUFSIZE);
     zstream_.next_out = outbuffer_;
     if (err != Z_OK || outbuffer_ == Z_NULL)
     {
        int err = Z_OK;
		if (zstream_.state != NULL) 
		{
			  err = deflateEnd(&(zstream_));
		}
		if (z_err_ < 0) 
		{
			  err = z_err_;
		}
		if ( outbuffer_ )
			free (outbuffer_);     
		return;
	 }
     
     zstream_.avail_out = Z_BUFSIZE;
     
	 GZIP header[10]={0x1f,0x8b,Z_DEFLATED, 0 /*flags*/, 0,0,0,0 /*time*/, 0 /*xflags*/, OS_CODE};
     write( (GZIP*)header, 10 );

     zstream_.next_in = (Bytef*)lpsz;
     zstream_.avail_in = len;

     while (zstream_.avail_in != 0)
     {
        if (zstream_.avail_out == 0)
        {
            zstream_.next_out = outbuffer_;
            write(outbuffer_,Z_BUFSIZE);
            zstream_.avail_out = Z_BUFSIZE;
        }
        z_err_ = deflate(&zstream_,Z_NO_FLUSH);
        if (z_err_ != Z_OK) 
          break;
    }
    
    crc = crc32(crc, (const Bytef *)lpsz, len);
    if (finish())
    { 
      destroy();
      return;
    }
    
    putLong(crc);
    putLong (zstream_.total_in );    
 }
   
int GzipImpl::write( LPGZIP buf, int count )
{
     if ( !buf ) 
       return 0;
     
     if ( size_ + count > (size_t)currentBufferSize_ )
     {
	   int nTimes = ( size_ + count ) / nBufferLen_ +1;
	   LPGZIP pTemp = pgzip_;
	   pgzip_ = static_cast<LPGZIP>( malloc( nTimes * nBufferLen_) );
	   currentBufferSize_ = nTimes * nBufferLen_;
	   memcpy( pgzip_, pTemp, size_);
	   if ( pTemp != buffer_ ) 
	     free(pTemp);
     }
     memcpy( pgzip_ + size_, buf, count );
     size_ += count;
     return count;
}

int GzipImpl::finish()
{
     uInt len;
     int done = 0;
     zstream_.avail_in = 0; 
     for (;;)
     {
        len = Z_BUFSIZE - zstream_.avail_out;
        if (len != 0)
        {
			write( outbuffer_, len );
            zstream_.next_out = outbuffer_;
            zstream_.avail_out = Z_BUFSIZE;
        }
        if (done) 
          break;
          
        z_err_ = deflate( &(zstream_), Z_FINISH);
        
		if (len == 0 && z_err_ == Z_BUF_ERROR) z_err_ = Z_OK;
        
		done = (zstream_.avail_out != 0 || z_err_ == Z_STREAM_END);
	
        if (z_err_ != Z_OK && z_err_ != Z_STREAM_END) 
          break;
    }
    return  z_err_ == Z_STREAM_END ? Z_OK : z_err_;
 }
 
 int GzipImpl::destroy()
 {
    int err = Z_OK;

    if (zstream_.state != NULL) 
    {
      err = deflateEnd(&(zstream_));
    }
    if (z_err_ < 0) 
      err = z_err_;
      
    if (outbuffer_)
		free(outbuffer_);
    return err;
 }

 void GzipImpl::putLong (uLong x)
 {
    for(int n = 0; n < 4; n++) 
    {
        unsigned char c = (unsigned char)(x & 0xff);
        write(&c,1);
        x >>= 8;
    }
 }


////////////////////////////////////////////////////////////////////////////////////


GunzipImpl::GunzipImpl(LPGZIP pgzip,int len)
	: gzip_(pgzip),gziplen_(len),psz_(0),length_(0),pos_(0)
{
init(); 
}


GunzipImpl::GunzipImpl(const std::string& gzipped)
	: gzip_( (unsigned char*)gzipped.c_str() ),
	  gziplen_( gzipped.size() + 1 ),
	  psz_(0),
	  length_(0),
	  pos_(0)
{
  init(); 
}

GunzipImpl::~GunzipImpl()
{
	if ( psz_ != buffer_) 
		if (psz_)
			free(psz_);
}

std::string GunzipImpl::toString()
{
	return std::string( psz_, length_ );
}

void GunzipImpl::init()
{
	if ( gzip_ == 0 )
	{
	  psz_ = 0; 
	  length_ = 0;
	  return ;
	}

	currentBufferSize_ = nBufferLen_;
	psz_ = buffer_;
	memset(psz_,0,currentBufferSize_+1);

	zstream_.zalloc = (alloc_func)0;
    zstream_.zfree = (free_func)0;
    zstream_.opaque = (voidpf)0;
    zstream_.next_in = inbuffer_ = Z_NULL;
    zstream_.next_out = Z_NULL;
    zstream_.avail_in = zstream_.avail_out = 0;
    z_err_ = Z_OK;
	z_eof_ = 0;
	transparent_ = 0;
    crc_ = crc32(0L, Z_NULL, 0);
    
	zstream_.next_in = inbuffer_ = (Byte*)malloc(Z_BUFSIZE);
    int  err = inflateInit2(&(zstream_), -MAX_WBITS);
	if (err != Z_OK || inbuffer_ == Z_NULL)
	{
	  destroy();
	  return;
    }
    zstream_.avail_out = Z_BUFSIZE;
	check_header();
	char outbuf[Z_BUFSIZE];
	int nRead;
	while(true)
	{
	  nRead = gzread( outbuf,Z_BUFSIZE);
	  if ( nRead <= 0 ) 
		  break;

	  write(outbuf,nRead);
	}
	destroy();
  }

   
  void GunzipImpl::check_header()
  {
    int method; /* method byte */
    int flags;  /* flags byte */
    uInt len;
    int c;

    /* Check the gzip magic header */
    for (len = 0; len < 2; len++) 
	{
	  c = get_byte();
	  if (c != gz_magic[len]) 
	  {
	    if (len != 0) 
			zstream_.avail_in++, zstream_.next_in--;
	    if (c != EOF) 
		{
		  zstream_.avail_in++, zstream_.next_in--;
		  transparent_ = 1;
	    }
	    z_err_ = zstream_.avail_in != 0 ? Z_OK : Z_STREAM_END;
	    return;
	}
    }
    method = get_byte();
    flags = get_byte();
    if (method != Z_DEFLATED || (flags & RESERVED) != 0) 
	{
	  z_err_ = Z_DATA_ERROR;
	  return;
    }
    /* Discard time, xflags and OS code: */
    for (len = 0; len < 6; len++) (void)get_byte();

    if ((flags & EXTRA_FIELD) != 0) 
	{ /* skip the extra field */
	  len  =  (uInt)get_byte();
	  len += ((uInt)get_byte())<<8;
	  /* len is garbage if EOF but the loop below will quit anyway */
	  while (len-- != 0 && get_byte() != EOF) ;
    }
    if ((flags & ORIG_NAME) != 0) 
	{ /* skip the original file name */
	  while ((c = get_byte()) != 0 && c != EOF) ;
    }
    if ((flags & COMMENT) != 0) 
	{   /* skip the .gz file comment */
	  while ((c = get_byte()) != 0 && c != EOF) ;
    }
    if ((flags & HEAD_CRC) != 0) 
	{  /* skip the header crc */
	  for (len = 0; len < 2; len++) (void)get_byte();
    }
    z_err_ = z_eof_ ? Z_DATA_ERROR : Z_OK;
  }

  int GunzipImpl::get_byte()
  {
    if (z_eof_) 
		return EOF;

    if (zstream_.avail_in == 0) 
	{
	  errno = 0;
	  zstream_.avail_in =read(inbuffer_,Z_BUFSIZE);
	  if(zstream_.avail_in == 0)
	  {
	    z_eof_ = 1;
	    return EOF;
	  }
	  zstream_.next_in = inbuffer_;
    }
    zstream_.avail_in--;
    return *(zstream_.next_in)++;
  }

  int GunzipImpl::read(LPGZIP buf,int size)
  {
    int nRead=size;
    if( pos_ + size >= gziplen_ )
    {
      nRead = gziplen_ - pos_;
    }
    if ( nRead <= 0 ) 
		return 0;

   memcpy( buf, gzip_ + pos_, nRead );
   pos_ += nRead;
   return nRead;
  }

  int GunzipImpl::gzread(char* buf,int len)
  {
    Bytef *start = (Bytef*)buf; /* starting point for crc computation */
    Byte  *next_out; /* == stream.next_out but not forced far (for MSDOS) */
   
	if (z_err_ == Z_DATA_ERROR || z_err_ == Z_ERRNO) 
		return -1;

    if (z_err_ == Z_STREAM_END) 
		return 0;  /* EOF */

    next_out = (Byte*)buf;
    zstream_.next_out = (Bytef*)buf;
    zstream_.avail_out = len;
    while (zstream_.avail_out != 0) 
	{
		if (transparent_)
		{
			/* Copy first the lookahead bytes: */
			uInt n = zstream_.avail_in;
			if (n > zstream_.avail_out) n = zstream_.avail_out;
			if (n > 0) 
			{
			  zmemcpy(zstream_.next_out,zstream_.next_in, n);
			  next_out += n;
			  zstream_.next_out = next_out;
			  zstream_.next_in   += n;
			  zstream_.avail_out -= n;
			  zstream_.avail_in  -= n;
			}
			if (zstream_.avail_out > 0) {
			   zstream_.avail_out -=read(next_out,zstream_.avail_out);
			}
			len -= zstream_.avail_out;
			zstream_.total_in  += (uLong)len;
			zstream_.total_out += (uLong)len;
			if (len == 0) 
				z_eof_ = 1;

			return (int)len;
		}
		if (zstream_.avail_in == 0 && !z_eof_)
		{
			errno = 0;
			zstream_.avail_in = read(inbuffer_,Z_BUFSIZE);
			if (zstream_.avail_in == 0)
			{
				 z_eof_ = 1;
			}
			zstream_.next_in = inbuffer_;
		}
    
		z_err_ = inflate(&(zstream_), Z_NO_FLUSH);

		if ( z_err_ == Z_STREAM_END)
		{
			/* Check CRC and original size */
			crc_ = crc32(crc_, start, (uInt)(zstream_.next_out - start));
			start = zstream_.next_out;
			if (getLong() != crc_) 
			{
  			  z_err_ = Z_DATA_ERROR;
			}
			else
			{
				(void)getLong();
         		check_header();
				if (z_err_ == Z_OK)
				{
					uLong total_in = zstream_.total_in;
					uLong total_out = zstream_.total_out;
					inflateReset(&(zstream_));
					zstream_.total_in = total_in;
					zstream_.total_out = total_out;
					crc_ = crc32(0L, Z_NULL, 0);
				}
			}
		}
		if (z_err_ != Z_OK || z_eof_) 
			break;
    } // end while

    crc_ = crc32(crc_, start, (uInt)(zstream_.next_out - start));
    return (int)(len - zstream_.avail_out);
 }

 uLong GunzipImpl::getLong()
 {
    uLong x = (uLong)get_byte();
    int c;
    x += ((uLong)get_byte())<<8;
    x += ((uLong)get_byte())<<16;
    c = get_byte();

    if (c == EOF) 
		z_err_ = Z_DATA_ERROR;

    x += ((uLong)c)<<24;
    return x;
 }

 int GunzipImpl::write(char* buf,int count)
 {
     if ( !buf ) 
		 return 0;

	 if( length_ + count > currentBufferSize_)
	 {
	   int nTimes = (length_ + count) / nBufferLen_ + 1;
	   char *pTemp = psz_;
	   psz_ = static_cast<char*>( malloc(nTimes*nBufferLen_+1));
	   currentBufferSize_ = nTimes*nBufferLen_;

	   memset(psz_,0,currentBufferSize_+1);
	   memcpy(psz_,pTemp,length_);
	   if ( pTemp != buffer_ ) 
		   free(pTemp);
	 }

	 memcpy(psz_ + length_, buf, count);
	 length_ += count;
	 return count;
 }

 int GunzipImpl::destroy()
 {
    int err = Z_OK;
	if (zstream_.state != NULL) {
	    err = inflateEnd(&(zstream_));
	}
    if (z_err_ < 0) 
		err = z_err_;

    if (inbuffer_)
		free(inbuffer_);
    return err;
}



}


