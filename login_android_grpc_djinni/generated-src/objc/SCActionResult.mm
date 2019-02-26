// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from demo.djinni

#import "SCActionResult.h"


@implementation SCActionResult

- (nonnull instancetype)initWithCode:(int32_t)code
                                 msg:(nonnull NSString *)msg
                                data:(nonnull NSString *)data
{
    if (self = [super init]) {
        _code = code;
        _msg = [msg copy];
        _data = [data copy];
    }
    return self;
}

+ (nonnull instancetype)actionResultWithCode:(int32_t)code
                                         msg:(nonnull NSString *)msg
                                        data:(nonnull NSString *)data
{
    return [(SCActionResult*)[self alloc] initWithCode:code
                                                   msg:msg
                                                  data:data];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p code:%@ msg:%@ data:%@>", self.class, (void *)self, @(self.code), self.msg, self.data];
}

@end
