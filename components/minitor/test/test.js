for ( let i = 0; i < 186; i++ ) {
  if ( i < 16 ) {
    process.stdout.write( '0x0' + i.toString( 16 ) + ', ' );
  } else {
    process.stdout.write( '0x' + i.toString( 16 ) + ', ' );
  }
}

process.stdout.write( '\n' );