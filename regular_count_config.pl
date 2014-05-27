#Not all fields need to be named -- extra fields are handled gracefully
%field_names = qw(
    0   mid
    1   sid
    2   ev
    3   ip
    4   ctry
    5   datetime
    6   pbmid
    7   uuid
    8   cookied
    9   hostnum
    10  os
    11  browser
    12  device
    13  state
    14  dma
    15  inmarket_clk
    16  inmarket_act
    17  inmarket_rt
    18  gender
);

#Space efficient encodings for certain types of data.
#Current choices:
# ip - IPv4 address
# uuid - Stores only the first 8 bytes of the SHA256 of the UUID. This can still be safely assumed to be universally unique, you can have many billion of unique ID's without a single collision
# datetime - expects a value looking like this: 2014-05-07 23:50:00 -- and does not store the seconds column, the output will be at :00 seconds.
# ignore - encode this column as the empty string

$column_encodings[3]='ip';
$column_encodings[7]='uuid';
$column_encodings[5]='datetime';


#How To Pick a driving column
#1. All values MUST be the same length, always.
#2. There should be very many possible values.
#3. The values should be essentially random binary data.
#4. Which means the only two real choices for the driving column are IP and UUID, and only if they are using the dedicated encodings above

$driving_column = 3;#ip



#MID SID EV REF_IP CTRY TIME PBMID UUID COOKIED HOSTNUM OS BROWSER DEVICE? STATE DMA INMARKET_CLK INMARKET_ACT INMARKET_RT GENDER
#But, to assign predictors, the field must be named

#A lower level predictor CANNOT predict the driving column of a higher level one.
#Lines here can be commented out with #
$predictor_string = '
    uuid => ip sid ev cookied browser device os inmarket_clk inmarket_act inmarket_rt gender
    uuid => browser device os inmarket_clk inmarket_act inmarket_rt gender
    #uuid => ip ev cookied ctry state dma browser device os inmarket_clk inmarket_act inmarket_rt gender
    uuid => cookied browser device os
    ip   => sid ev cookied ctry state dma browser device os inmarket_clk inmarket_act inmarket_rt gender
    ip   => ctry state dma
    sid  => ctry browser
    sid  => gender
    inmarket_clk  => inmarket_act inmarket_rt
    #pbmid => mid
    cookied => os browser device
    #browser => device
    #device => os browser
    os   => browser
    dma  => state ctry
    state => ctry
    sid pbmid ctry  => mid
    #sid  => mid
';