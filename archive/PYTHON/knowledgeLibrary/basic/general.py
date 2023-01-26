# A question as come up about how this works:
#     if any( x in pCell for x in ticker_col ): 
# So I'm going back to understand the key word 'for' and the keyword 'in'
# for reference: https://www.programiz.com/python-programming/for-loop


# This line doesn't work:
# print( "range(10): " + range( 10 ) )
nl = '\n'
print( "range(10): " )
print( range( 10 ) )
print( nl )

print( "list(range(10)):" ) 
print( list( range( 10 ) ) )
print( nl )

print( "list(range(2,8)):" )
print( list( range( 2, 8) ) )
print( nl )

print( "list(range(2,20,3)):" )
print( list( range( 2, 20, 3 ) ) )
print( nl )