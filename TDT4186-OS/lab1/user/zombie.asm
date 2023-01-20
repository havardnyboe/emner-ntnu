
user/_zombie:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <main>:
   0:	1141                	addi	sp,sp,-16
   2:	e406                	sd	ra,8(sp)
   4:	e022                	sd	s0,0(sp)
   6:	0800                	addi	s0,sp,16
   8:	00000097          	auipc	ra,0x0
   c:	2a0080e7          	jalr	672(ra) # 2a8 <fork>
  10:	00a04763          	bgtz	a0,1e <main+0x1e>
  14:	4501                	li	a0,0
  16:	00000097          	auipc	ra,0x0
  1a:	29a080e7          	jalr	666(ra) # 2b0 <exit>
  1e:	4515                	li	a0,5
  20:	00000097          	auipc	ra,0x0
  24:	320080e7          	jalr	800(ra) # 340 <sleep>
  28:	b7f5                	j	14 <main+0x14>

000000000000002a <_main>:
  2a:	1141                	addi	sp,sp,-16
  2c:	e406                	sd	ra,8(sp)
  2e:	e022                	sd	s0,0(sp)
  30:	0800                	addi	s0,sp,16
  32:	00000097          	auipc	ra,0x0
  36:	fce080e7          	jalr	-50(ra) # 0 <main>
  3a:	4501                	li	a0,0
  3c:	00000097          	auipc	ra,0x0
  40:	274080e7          	jalr	628(ra) # 2b0 <exit>

0000000000000044 <strcpy>:
  44:	1141                	addi	sp,sp,-16
  46:	e422                	sd	s0,8(sp)
  48:	0800                	addi	s0,sp,16
  4a:	87aa                	mv	a5,a0
  4c:	0585                	addi	a1,a1,1
  4e:	0785                	addi	a5,a5,1
  50:	fff5c703          	lbu	a4,-1(a1)
  54:	fee78fa3          	sb	a4,-1(a5)
  58:	fb75                	bnez	a4,4c <strcpy+0x8>
  5a:	6422                	ld	s0,8(sp)
  5c:	0141                	addi	sp,sp,16
  5e:	8082                	ret

0000000000000060 <strcmp>:
  60:	1141                	addi	sp,sp,-16
  62:	e422                	sd	s0,8(sp)
  64:	0800                	addi	s0,sp,16
  66:	00054783          	lbu	a5,0(a0)
  6a:	cb91                	beqz	a5,7e <strcmp+0x1e>
  6c:	0005c703          	lbu	a4,0(a1)
  70:	00f71763          	bne	a4,a5,7e <strcmp+0x1e>
  74:	0505                	addi	a0,a0,1
  76:	0585                	addi	a1,a1,1
  78:	00054783          	lbu	a5,0(a0)
  7c:	fbe5                	bnez	a5,6c <strcmp+0xc>
  7e:	0005c503          	lbu	a0,0(a1)
  82:	40a7853b          	subw	a0,a5,a0
  86:	6422                	ld	s0,8(sp)
  88:	0141                	addi	sp,sp,16
  8a:	8082                	ret

000000000000008c <strlen>:
  8c:	1141                	addi	sp,sp,-16
  8e:	e422                	sd	s0,8(sp)
  90:	0800                	addi	s0,sp,16
  92:	00054783          	lbu	a5,0(a0)
  96:	cf91                	beqz	a5,b2 <strlen+0x26>
  98:	0505                	addi	a0,a0,1
  9a:	87aa                	mv	a5,a0
  9c:	86be                	mv	a3,a5
  9e:	0785                	addi	a5,a5,1
  a0:	fff7c703          	lbu	a4,-1(a5)
  a4:	ff65                	bnez	a4,9c <strlen+0x10>
  a6:	40a6853b          	subw	a0,a3,a0
  aa:	2505                	addiw	a0,a0,1
  ac:	6422                	ld	s0,8(sp)
  ae:	0141                	addi	sp,sp,16
  b0:	8082                	ret
  b2:	4501                	li	a0,0
  b4:	bfe5                	j	ac <strlen+0x20>

00000000000000b6 <memset>:
  b6:	1141                	addi	sp,sp,-16
  b8:	e422                	sd	s0,8(sp)
  ba:	0800                	addi	s0,sp,16
  bc:	ca19                	beqz	a2,d2 <memset+0x1c>
  be:	87aa                	mv	a5,a0
  c0:	1602                	slli	a2,a2,0x20
  c2:	9201                	srli	a2,a2,0x20
  c4:	00a60733          	add	a4,a2,a0
  c8:	00b78023          	sb	a1,0(a5)
  cc:	0785                	addi	a5,a5,1
  ce:	fee79de3          	bne	a5,a4,c8 <memset+0x12>
  d2:	6422                	ld	s0,8(sp)
  d4:	0141                	addi	sp,sp,16
  d6:	8082                	ret

00000000000000d8 <strchr>:
  d8:	1141                	addi	sp,sp,-16
  da:	e422                	sd	s0,8(sp)
  dc:	0800                	addi	s0,sp,16
  de:	00054783          	lbu	a5,0(a0)
  e2:	cb99                	beqz	a5,f8 <strchr+0x20>
  e4:	00f58763          	beq	a1,a5,f2 <strchr+0x1a>
  e8:	0505                	addi	a0,a0,1
  ea:	00054783          	lbu	a5,0(a0)
  ee:	fbfd                	bnez	a5,e4 <strchr+0xc>
  f0:	4501                	li	a0,0
  f2:	6422                	ld	s0,8(sp)
  f4:	0141                	addi	sp,sp,16
  f6:	8082                	ret
  f8:	4501                	li	a0,0
  fa:	bfe5                	j	f2 <strchr+0x1a>

00000000000000fc <gets>:
  fc:	711d                	addi	sp,sp,-96
  fe:	ec86                	sd	ra,88(sp)
 100:	e8a2                	sd	s0,80(sp)
 102:	e4a6                	sd	s1,72(sp)
 104:	e0ca                	sd	s2,64(sp)
 106:	fc4e                	sd	s3,56(sp)
 108:	f852                	sd	s4,48(sp)
 10a:	f456                	sd	s5,40(sp)
 10c:	f05a                	sd	s6,32(sp)
 10e:	ec5e                	sd	s7,24(sp)
 110:	1080                	addi	s0,sp,96
 112:	8baa                	mv	s7,a0
 114:	8a2e                	mv	s4,a1
 116:	892a                	mv	s2,a0
 118:	4481                	li	s1,0
 11a:	4aa9                	li	s5,10
 11c:	4b35                	li	s6,13
 11e:	89a6                	mv	s3,s1
 120:	2485                	addiw	s1,s1,1
 122:	0344d863          	bge	s1,s4,152 <gets+0x56>
 126:	4605                	li	a2,1
 128:	faf40593          	addi	a1,s0,-81
 12c:	4501                	li	a0,0
 12e:	00000097          	auipc	ra,0x0
 132:	19a080e7          	jalr	410(ra) # 2c8 <read>
 136:	00a05e63          	blez	a0,152 <gets+0x56>
 13a:	faf44783          	lbu	a5,-81(s0)
 13e:	00f90023          	sb	a5,0(s2)
 142:	01578763          	beq	a5,s5,150 <gets+0x54>
 146:	0905                	addi	s2,s2,1
 148:	fd679be3          	bne	a5,s6,11e <gets+0x22>
 14c:	89a6                	mv	s3,s1
 14e:	a011                	j	152 <gets+0x56>
 150:	89a6                	mv	s3,s1
 152:	99de                	add	s3,s3,s7
 154:	00098023          	sb	zero,0(s3)
 158:	855e                	mv	a0,s7
 15a:	60e6                	ld	ra,88(sp)
 15c:	6446                	ld	s0,80(sp)
 15e:	64a6                	ld	s1,72(sp)
 160:	6906                	ld	s2,64(sp)
 162:	79e2                	ld	s3,56(sp)
 164:	7a42                	ld	s4,48(sp)
 166:	7aa2                	ld	s5,40(sp)
 168:	7b02                	ld	s6,32(sp)
 16a:	6be2                	ld	s7,24(sp)
 16c:	6125                	addi	sp,sp,96
 16e:	8082                	ret

0000000000000170 <stat>:
 170:	1101                	addi	sp,sp,-32
 172:	ec06                	sd	ra,24(sp)
 174:	e822                	sd	s0,16(sp)
 176:	e426                	sd	s1,8(sp)
 178:	e04a                	sd	s2,0(sp)
 17a:	1000                	addi	s0,sp,32
 17c:	892e                	mv	s2,a1
 17e:	4581                	li	a1,0
 180:	00000097          	auipc	ra,0x0
 184:	170080e7          	jalr	368(ra) # 2f0 <open>
 188:	02054563          	bltz	a0,1b2 <stat+0x42>
 18c:	84aa                	mv	s1,a0
 18e:	85ca                	mv	a1,s2
 190:	00000097          	auipc	ra,0x0
 194:	178080e7          	jalr	376(ra) # 308 <fstat>
 198:	892a                	mv	s2,a0
 19a:	8526                	mv	a0,s1
 19c:	00000097          	auipc	ra,0x0
 1a0:	13c080e7          	jalr	316(ra) # 2d8 <close>
 1a4:	854a                	mv	a0,s2
 1a6:	60e2                	ld	ra,24(sp)
 1a8:	6442                	ld	s0,16(sp)
 1aa:	64a2                	ld	s1,8(sp)
 1ac:	6902                	ld	s2,0(sp)
 1ae:	6105                	addi	sp,sp,32
 1b0:	8082                	ret
 1b2:	597d                	li	s2,-1
 1b4:	bfc5                	j	1a4 <stat+0x34>

00000000000001b6 <atoi>:
 1b6:	1141                	addi	sp,sp,-16
 1b8:	e422                	sd	s0,8(sp)
 1ba:	0800                	addi	s0,sp,16
 1bc:	00054683          	lbu	a3,0(a0)
 1c0:	fd06879b          	addiw	a5,a3,-48
 1c4:	0ff7f793          	zext.b	a5,a5
 1c8:	4625                	li	a2,9
 1ca:	02f66863          	bltu	a2,a5,1fa <atoi+0x44>
 1ce:	872a                	mv	a4,a0
 1d0:	4501                	li	a0,0
 1d2:	0705                	addi	a4,a4,1
 1d4:	0025179b          	slliw	a5,a0,0x2
 1d8:	9fa9                	addw	a5,a5,a0
 1da:	0017979b          	slliw	a5,a5,0x1
 1de:	9fb5                	addw	a5,a5,a3
 1e0:	fd07851b          	addiw	a0,a5,-48
 1e4:	00074683          	lbu	a3,0(a4)
 1e8:	fd06879b          	addiw	a5,a3,-48
 1ec:	0ff7f793          	zext.b	a5,a5
 1f0:	fef671e3          	bgeu	a2,a5,1d2 <atoi+0x1c>
 1f4:	6422                	ld	s0,8(sp)
 1f6:	0141                	addi	sp,sp,16
 1f8:	8082                	ret
 1fa:	4501                	li	a0,0
 1fc:	bfe5                	j	1f4 <atoi+0x3e>

00000000000001fe <memmove>:
 1fe:	1141                	addi	sp,sp,-16
 200:	e422                	sd	s0,8(sp)
 202:	0800                	addi	s0,sp,16
 204:	02b57463          	bgeu	a0,a1,22c <memmove+0x2e>
 208:	00c05f63          	blez	a2,226 <memmove+0x28>
 20c:	1602                	slli	a2,a2,0x20
 20e:	9201                	srli	a2,a2,0x20
 210:	00c507b3          	add	a5,a0,a2
 214:	872a                	mv	a4,a0
 216:	0585                	addi	a1,a1,1
 218:	0705                	addi	a4,a4,1
 21a:	fff5c683          	lbu	a3,-1(a1)
 21e:	fed70fa3          	sb	a3,-1(a4)
 222:	fee79ae3          	bne	a5,a4,216 <memmove+0x18>
 226:	6422                	ld	s0,8(sp)
 228:	0141                	addi	sp,sp,16
 22a:	8082                	ret
 22c:	00c50733          	add	a4,a0,a2
 230:	95b2                	add	a1,a1,a2
 232:	fec05ae3          	blez	a2,226 <memmove+0x28>
 236:	fff6079b          	addiw	a5,a2,-1
 23a:	1782                	slli	a5,a5,0x20
 23c:	9381                	srli	a5,a5,0x20
 23e:	fff7c793          	not	a5,a5
 242:	97ba                	add	a5,a5,a4
 244:	15fd                	addi	a1,a1,-1
 246:	177d                	addi	a4,a4,-1
 248:	0005c683          	lbu	a3,0(a1)
 24c:	00d70023          	sb	a3,0(a4)
 250:	fee79ae3          	bne	a5,a4,244 <memmove+0x46>
 254:	bfc9                	j	226 <memmove+0x28>

0000000000000256 <memcmp>:
 256:	1141                	addi	sp,sp,-16
 258:	e422                	sd	s0,8(sp)
 25a:	0800                	addi	s0,sp,16
 25c:	ca05                	beqz	a2,28c <memcmp+0x36>
 25e:	fff6069b          	addiw	a3,a2,-1
 262:	1682                	slli	a3,a3,0x20
 264:	9281                	srli	a3,a3,0x20
 266:	0685                	addi	a3,a3,1
 268:	96aa                	add	a3,a3,a0
 26a:	00054783          	lbu	a5,0(a0)
 26e:	0005c703          	lbu	a4,0(a1)
 272:	00e79863          	bne	a5,a4,282 <memcmp+0x2c>
 276:	0505                	addi	a0,a0,1
 278:	0585                	addi	a1,a1,1
 27a:	fed518e3          	bne	a0,a3,26a <memcmp+0x14>
 27e:	4501                	li	a0,0
 280:	a019                	j	286 <memcmp+0x30>
 282:	40e7853b          	subw	a0,a5,a4
 286:	6422                	ld	s0,8(sp)
 288:	0141                	addi	sp,sp,16
 28a:	8082                	ret
 28c:	4501                	li	a0,0
 28e:	bfe5                	j	286 <memcmp+0x30>

0000000000000290 <memcpy>:
 290:	1141                	addi	sp,sp,-16
 292:	e406                	sd	ra,8(sp)
 294:	e022                	sd	s0,0(sp)
 296:	0800                	addi	s0,sp,16
 298:	00000097          	auipc	ra,0x0
 29c:	f66080e7          	jalr	-154(ra) # 1fe <memmove>
 2a0:	60a2                	ld	ra,8(sp)
 2a2:	6402                	ld	s0,0(sp)
 2a4:	0141                	addi	sp,sp,16
 2a6:	8082                	ret

00000000000002a8 <fork>:
 2a8:	4885                	li	a7,1
 2aa:	00000073          	ecall
 2ae:	8082                	ret

00000000000002b0 <exit>:
 2b0:	4889                	li	a7,2
 2b2:	00000073          	ecall
 2b6:	8082                	ret

00000000000002b8 <wait>:
 2b8:	488d                	li	a7,3
 2ba:	00000073          	ecall
 2be:	8082                	ret

00000000000002c0 <pipe>:
 2c0:	4891                	li	a7,4
 2c2:	00000073          	ecall
 2c6:	8082                	ret

00000000000002c8 <read>:
 2c8:	4895                	li	a7,5
 2ca:	00000073          	ecall
 2ce:	8082                	ret

00000000000002d0 <write>:
 2d0:	48c1                	li	a7,16
 2d2:	00000073          	ecall
 2d6:	8082                	ret

00000000000002d8 <close>:
 2d8:	48d5                	li	a7,21
 2da:	00000073          	ecall
 2de:	8082                	ret

00000000000002e0 <kill>:
 2e0:	4899                	li	a7,6
 2e2:	00000073          	ecall
 2e6:	8082                	ret

00000000000002e8 <exec>:
 2e8:	489d                	li	a7,7
 2ea:	00000073          	ecall
 2ee:	8082                	ret

00000000000002f0 <open>:
 2f0:	48bd                	li	a7,15
 2f2:	00000073          	ecall
 2f6:	8082                	ret

00000000000002f8 <mknod>:
 2f8:	48c5                	li	a7,17
 2fa:	00000073          	ecall
 2fe:	8082                	ret

0000000000000300 <unlink>:
 300:	48c9                	li	a7,18
 302:	00000073          	ecall
 306:	8082                	ret

0000000000000308 <fstat>:
 308:	48a1                	li	a7,8
 30a:	00000073          	ecall
 30e:	8082                	ret

0000000000000310 <link>:
 310:	48cd                	li	a7,19
 312:	00000073          	ecall
 316:	8082                	ret

0000000000000318 <mkdir>:
 318:	48d1                	li	a7,20
 31a:	00000073          	ecall
 31e:	8082                	ret

0000000000000320 <chdir>:
 320:	48a5                	li	a7,9
 322:	00000073          	ecall
 326:	8082                	ret

0000000000000328 <dup>:
 328:	48a9                	li	a7,10
 32a:	00000073          	ecall
 32e:	8082                	ret

0000000000000330 <getpid>:
 330:	48ad                	li	a7,11
 332:	00000073          	ecall
 336:	8082                	ret

0000000000000338 <sbrk>:
 338:	48b1                	li	a7,12
 33a:	00000073          	ecall
 33e:	8082                	ret

0000000000000340 <sleep>:
 340:	48b5                	li	a7,13
 342:	00000073          	ecall
 346:	8082                	ret

0000000000000348 <uptime>:
 348:	48b9                	li	a7,14
 34a:	00000073          	ecall
 34e:	8082                	ret

0000000000000350 <putc>:

static char digits[] = "0123456789ABCDEF";

static void
putc(int fd, char c)
{
 350:	1101                	addi	sp,sp,-32
 352:	ec06                	sd	ra,24(sp)
 354:	e822                	sd	s0,16(sp)
 356:	1000                	addi	s0,sp,32
 358:	feb407a3          	sb	a1,-17(s0)
  write(fd, &c, 1);
 35c:	4605                	li	a2,1
 35e:	fef40593          	addi	a1,s0,-17
 362:	00000097          	auipc	ra,0x0
 366:	f6e080e7          	jalr	-146(ra) # 2d0 <write>
}
 36a:	60e2                	ld	ra,24(sp)
 36c:	6442                	ld	s0,16(sp)
 36e:	6105                	addi	sp,sp,32
 370:	8082                	ret

0000000000000372 <printint>:

static void
printint(int fd, int xx, int base, int sgn)
{
 372:	7139                	addi	sp,sp,-64
 374:	fc06                	sd	ra,56(sp)
 376:	f822                	sd	s0,48(sp)
 378:	f426                	sd	s1,40(sp)
 37a:	f04a                	sd	s2,32(sp)
 37c:	ec4e                	sd	s3,24(sp)
 37e:	0080                	addi	s0,sp,64
 380:	84aa                	mv	s1,a0
  char buf[16];
  int i, neg;
  uint x;

  neg = 0;
  if(sgn && xx < 0){
 382:	c299                	beqz	a3,388 <printint+0x16>
 384:	0805c963          	bltz	a1,416 <printint+0xa4>
    neg = 1;
    x = -xx;
  } else {
    x = xx;
 388:	2581                	sext.w	a1,a1
  neg = 0;
 38a:	4881                	li	a7,0
 38c:	fc040693          	addi	a3,s0,-64
  }

  i = 0;
 390:	4701                	li	a4,0
  do{
    buf[i++] = digits[x % base];
 392:	2601                	sext.w	a2,a2
 394:	00000517          	auipc	a0,0x0
 398:	48c50513          	addi	a0,a0,1164 # 820 <digits>
 39c:	883a                	mv	a6,a4
 39e:	2705                	addiw	a4,a4,1
 3a0:	02c5f7bb          	remuw	a5,a1,a2
 3a4:	1782                	slli	a5,a5,0x20
 3a6:	9381                	srli	a5,a5,0x20
 3a8:	97aa                	add	a5,a5,a0
 3aa:	0007c783          	lbu	a5,0(a5)
 3ae:	00f68023          	sb	a5,0(a3)
  }while((x /= base) != 0);
 3b2:	0005879b          	sext.w	a5,a1
 3b6:	02c5d5bb          	divuw	a1,a1,a2
 3ba:	0685                	addi	a3,a3,1
 3bc:	fec7f0e3          	bgeu	a5,a2,39c <printint+0x2a>
  if(neg)
 3c0:	00088c63          	beqz	a7,3d8 <printint+0x66>
    buf[i++] = '-';
 3c4:	fd070793          	addi	a5,a4,-48
 3c8:	00878733          	add	a4,a5,s0
 3cc:	02d00793          	li	a5,45
 3d0:	fef70823          	sb	a5,-16(a4)
 3d4:	0028071b          	addiw	a4,a6,2

  while(--i >= 0)
 3d8:	02e05863          	blez	a4,408 <printint+0x96>
 3dc:	fc040793          	addi	a5,s0,-64
 3e0:	00e78933          	add	s2,a5,a4
 3e4:	fff78993          	addi	s3,a5,-1
 3e8:	99ba                	add	s3,s3,a4
 3ea:	377d                	addiw	a4,a4,-1
 3ec:	1702                	slli	a4,a4,0x20
 3ee:	9301                	srli	a4,a4,0x20
 3f0:	40e989b3          	sub	s3,s3,a4
    putc(fd, buf[i]);
 3f4:	fff94583          	lbu	a1,-1(s2)
 3f8:	8526                	mv	a0,s1
 3fa:	00000097          	auipc	ra,0x0
 3fe:	f56080e7          	jalr	-170(ra) # 350 <putc>
  while(--i >= 0)
 402:	197d                	addi	s2,s2,-1
 404:	ff3918e3          	bne	s2,s3,3f4 <printint+0x82>
}
 408:	70e2                	ld	ra,56(sp)
 40a:	7442                	ld	s0,48(sp)
 40c:	74a2                	ld	s1,40(sp)
 40e:	7902                	ld	s2,32(sp)
 410:	69e2                	ld	s3,24(sp)
 412:	6121                	addi	sp,sp,64
 414:	8082                	ret
    x = -xx;
 416:	40b005bb          	negw	a1,a1
    neg = 1;
 41a:	4885                	li	a7,1
    x = -xx;
 41c:	bf85                	j	38c <printint+0x1a>

000000000000041e <vprintf>:
}

// Print to the given fd. Only understands %d, %x, %p, %s.
void
vprintf(int fd, const char *fmt, va_list ap)
{
 41e:	715d                	addi	sp,sp,-80
 420:	e486                	sd	ra,72(sp)
 422:	e0a2                	sd	s0,64(sp)
 424:	fc26                	sd	s1,56(sp)
 426:	f84a                	sd	s2,48(sp)
 428:	f44e                	sd	s3,40(sp)
 42a:	f052                	sd	s4,32(sp)
 42c:	ec56                	sd	s5,24(sp)
 42e:	e85a                	sd	s6,16(sp)
 430:	e45e                	sd	s7,8(sp)
 432:	e062                	sd	s8,0(sp)
 434:	0880                	addi	s0,sp,80
  char *s;
  int c, i, state;

  state = 0;
  for(i = 0; fmt[i]; i++){
 436:	0005c903          	lbu	s2,0(a1)
 43a:	18090c63          	beqz	s2,5d2 <vprintf+0x1b4>
 43e:	8aaa                	mv	s5,a0
 440:	8bb2                	mv	s7,a2
 442:	00158493          	addi	s1,a1,1
  state = 0;
 446:	4981                	li	s3,0
      if(c == '%'){
        state = '%';
      } else {
        putc(fd, c);
      }
    } else if(state == '%'){
 448:	02500a13          	li	s4,37
 44c:	4b55                	li	s6,21
 44e:	a839                	j	46c <vprintf+0x4e>
        putc(fd, c);
 450:	85ca                	mv	a1,s2
 452:	8556                	mv	a0,s5
 454:	00000097          	auipc	ra,0x0
 458:	efc080e7          	jalr	-260(ra) # 350 <putc>
 45c:	a019                	j	462 <vprintf+0x44>
    } else if(state == '%'){
 45e:	01498d63          	beq	s3,s4,478 <vprintf+0x5a>
  for(i = 0; fmt[i]; i++){
 462:	0485                	addi	s1,s1,1
 464:	fff4c903          	lbu	s2,-1(s1)
 468:	16090563          	beqz	s2,5d2 <vprintf+0x1b4>
    if(state == 0){
 46c:	fe0999e3          	bnez	s3,45e <vprintf+0x40>
      if(c == '%'){
 470:	ff4910e3          	bne	s2,s4,450 <vprintf+0x32>
        state = '%';
 474:	89d2                	mv	s3,s4
 476:	b7f5                	j	462 <vprintf+0x44>
      if(c == 'd'){
 478:	13490263          	beq	s2,s4,59c <vprintf+0x17e>
 47c:	f9d9079b          	addiw	a5,s2,-99
 480:	0ff7f793          	zext.b	a5,a5
 484:	12fb6563          	bltu	s6,a5,5ae <vprintf+0x190>
 488:	f9d9079b          	addiw	a5,s2,-99
 48c:	0ff7f713          	zext.b	a4,a5
 490:	10eb6f63          	bltu	s6,a4,5ae <vprintf+0x190>
 494:	00271793          	slli	a5,a4,0x2
 498:	00000717          	auipc	a4,0x0
 49c:	33070713          	addi	a4,a4,816 # 7c8 <malloc+0xf8>
 4a0:	97ba                	add	a5,a5,a4
 4a2:	439c                	lw	a5,0(a5)
 4a4:	97ba                	add	a5,a5,a4
 4a6:	8782                	jr	a5
        printint(fd, va_arg(ap, int), 10, 1);
 4a8:	008b8913          	addi	s2,s7,8
 4ac:	4685                	li	a3,1
 4ae:	4629                	li	a2,10
 4b0:	000ba583          	lw	a1,0(s7)
 4b4:	8556                	mv	a0,s5
 4b6:	00000097          	auipc	ra,0x0
 4ba:	ebc080e7          	jalr	-324(ra) # 372 <printint>
 4be:	8bca                	mv	s7,s2
      } else {
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c);
      }
      state = 0;
 4c0:	4981                	li	s3,0
 4c2:	b745                	j	462 <vprintf+0x44>
        printint(fd, va_arg(ap, uint64), 10, 0);
 4c4:	008b8913          	addi	s2,s7,8
 4c8:	4681                	li	a3,0
 4ca:	4629                	li	a2,10
 4cc:	000ba583          	lw	a1,0(s7)
 4d0:	8556                	mv	a0,s5
 4d2:	00000097          	auipc	ra,0x0
 4d6:	ea0080e7          	jalr	-352(ra) # 372 <printint>
 4da:	8bca                	mv	s7,s2
      state = 0;
 4dc:	4981                	li	s3,0
 4de:	b751                	j	462 <vprintf+0x44>
        printint(fd, va_arg(ap, int), 16, 0);
 4e0:	008b8913          	addi	s2,s7,8
 4e4:	4681                	li	a3,0
 4e6:	4641                	li	a2,16
 4e8:	000ba583          	lw	a1,0(s7)
 4ec:	8556                	mv	a0,s5
 4ee:	00000097          	auipc	ra,0x0
 4f2:	e84080e7          	jalr	-380(ra) # 372 <printint>
 4f6:	8bca                	mv	s7,s2
      state = 0;
 4f8:	4981                	li	s3,0
 4fa:	b7a5                	j	462 <vprintf+0x44>
        printptr(fd, va_arg(ap, uint64));
 4fc:	008b8c13          	addi	s8,s7,8
 500:	000bb983          	ld	s3,0(s7)
  putc(fd, '0');
 504:	03000593          	li	a1,48
 508:	8556                	mv	a0,s5
 50a:	00000097          	auipc	ra,0x0
 50e:	e46080e7          	jalr	-442(ra) # 350 <putc>
  putc(fd, 'x');
 512:	07800593          	li	a1,120
 516:	8556                	mv	a0,s5
 518:	00000097          	auipc	ra,0x0
 51c:	e38080e7          	jalr	-456(ra) # 350 <putc>
 520:	4941                	li	s2,16
    putc(fd, digits[x >> (sizeof(uint64) * 8 - 4)]);
 522:	00000b97          	auipc	s7,0x0
 526:	2feb8b93          	addi	s7,s7,766 # 820 <digits>
 52a:	03c9d793          	srli	a5,s3,0x3c
 52e:	97de                	add	a5,a5,s7
 530:	0007c583          	lbu	a1,0(a5)
 534:	8556                	mv	a0,s5
 536:	00000097          	auipc	ra,0x0
 53a:	e1a080e7          	jalr	-486(ra) # 350 <putc>
  for (i = 0; i < (sizeof(uint64) * 2); i++, x <<= 4)
 53e:	0992                	slli	s3,s3,0x4
 540:	397d                	addiw	s2,s2,-1
 542:	fe0914e3          	bnez	s2,52a <vprintf+0x10c>
        printptr(fd, va_arg(ap, uint64));
 546:	8be2                	mv	s7,s8
      state = 0;
 548:	4981                	li	s3,0
 54a:	bf21                	j	462 <vprintf+0x44>
        s = va_arg(ap, char*);
 54c:	008b8993          	addi	s3,s7,8
 550:	000bb903          	ld	s2,0(s7)
        if(s == 0)
 554:	02090163          	beqz	s2,576 <vprintf+0x158>
        while(*s != 0){
 558:	00094583          	lbu	a1,0(s2)
 55c:	c9a5                	beqz	a1,5cc <vprintf+0x1ae>
          putc(fd, *s);
 55e:	8556                	mv	a0,s5
 560:	00000097          	auipc	ra,0x0
 564:	df0080e7          	jalr	-528(ra) # 350 <putc>
          s++;
 568:	0905                	addi	s2,s2,1
        while(*s != 0){
 56a:	00094583          	lbu	a1,0(s2)
 56e:	f9e5                	bnez	a1,55e <vprintf+0x140>
        s = va_arg(ap, char*);
 570:	8bce                	mv	s7,s3
      state = 0;
 572:	4981                	li	s3,0
 574:	b5fd                	j	462 <vprintf+0x44>
          s = "(null)";
 576:	00000917          	auipc	s2,0x0
 57a:	24a90913          	addi	s2,s2,586 # 7c0 <malloc+0xf0>
        while(*s != 0){
 57e:	02800593          	li	a1,40
 582:	bff1                	j	55e <vprintf+0x140>
        putc(fd, va_arg(ap, uint));
 584:	008b8913          	addi	s2,s7,8
 588:	000bc583          	lbu	a1,0(s7)
 58c:	8556                	mv	a0,s5
 58e:	00000097          	auipc	ra,0x0
 592:	dc2080e7          	jalr	-574(ra) # 350 <putc>
 596:	8bca                	mv	s7,s2
      state = 0;
 598:	4981                	li	s3,0
 59a:	b5e1                	j	462 <vprintf+0x44>
        putc(fd, c);
 59c:	02500593          	li	a1,37
 5a0:	8556                	mv	a0,s5
 5a2:	00000097          	auipc	ra,0x0
 5a6:	dae080e7          	jalr	-594(ra) # 350 <putc>
      state = 0;
 5aa:	4981                	li	s3,0
 5ac:	bd5d                	j	462 <vprintf+0x44>
        putc(fd, '%');
 5ae:	02500593          	li	a1,37
 5b2:	8556                	mv	a0,s5
 5b4:	00000097          	auipc	ra,0x0
 5b8:	d9c080e7          	jalr	-612(ra) # 350 <putc>
        putc(fd, c);
 5bc:	85ca                	mv	a1,s2
 5be:	8556                	mv	a0,s5
 5c0:	00000097          	auipc	ra,0x0
 5c4:	d90080e7          	jalr	-624(ra) # 350 <putc>
      state = 0;
 5c8:	4981                	li	s3,0
 5ca:	bd61                	j	462 <vprintf+0x44>
        s = va_arg(ap, char*);
 5cc:	8bce                	mv	s7,s3
      state = 0;
 5ce:	4981                	li	s3,0
 5d0:	bd49                	j	462 <vprintf+0x44>
    }
  }
}
 5d2:	60a6                	ld	ra,72(sp)
 5d4:	6406                	ld	s0,64(sp)
 5d6:	74e2                	ld	s1,56(sp)
 5d8:	7942                	ld	s2,48(sp)
 5da:	79a2                	ld	s3,40(sp)
 5dc:	7a02                	ld	s4,32(sp)
 5de:	6ae2                	ld	s5,24(sp)
 5e0:	6b42                	ld	s6,16(sp)
 5e2:	6ba2                	ld	s7,8(sp)
 5e4:	6c02                	ld	s8,0(sp)
 5e6:	6161                	addi	sp,sp,80
 5e8:	8082                	ret

00000000000005ea <fprintf>:

void
fprintf(int fd, const char *fmt, ...)
{
 5ea:	715d                	addi	sp,sp,-80
 5ec:	ec06                	sd	ra,24(sp)
 5ee:	e822                	sd	s0,16(sp)
 5f0:	1000                	addi	s0,sp,32
 5f2:	e010                	sd	a2,0(s0)
 5f4:	e414                	sd	a3,8(s0)
 5f6:	e818                	sd	a4,16(s0)
 5f8:	ec1c                	sd	a5,24(s0)
 5fa:	03043023          	sd	a6,32(s0)
 5fe:	03143423          	sd	a7,40(s0)
  va_list ap;

  va_start(ap, fmt);
 602:	fe843423          	sd	s0,-24(s0)
  vprintf(fd, fmt, ap);
 606:	8622                	mv	a2,s0
 608:	00000097          	auipc	ra,0x0
 60c:	e16080e7          	jalr	-490(ra) # 41e <vprintf>
}
 610:	60e2                	ld	ra,24(sp)
 612:	6442                	ld	s0,16(sp)
 614:	6161                	addi	sp,sp,80
 616:	8082                	ret

0000000000000618 <printf>:

void
printf(const char *fmt, ...)
{
 618:	711d                	addi	sp,sp,-96
 61a:	ec06                	sd	ra,24(sp)
 61c:	e822                	sd	s0,16(sp)
 61e:	1000                	addi	s0,sp,32
 620:	e40c                	sd	a1,8(s0)
 622:	e810                	sd	a2,16(s0)
 624:	ec14                	sd	a3,24(s0)
 626:	f018                	sd	a4,32(s0)
 628:	f41c                	sd	a5,40(s0)
 62a:	03043823          	sd	a6,48(s0)
 62e:	03143c23          	sd	a7,56(s0)
  va_list ap;

  va_start(ap, fmt);
 632:	00840613          	addi	a2,s0,8
 636:	fec43423          	sd	a2,-24(s0)
  vprintf(1, fmt, ap);
 63a:	85aa                	mv	a1,a0
 63c:	4505                	li	a0,1
 63e:	00000097          	auipc	ra,0x0
 642:	de0080e7          	jalr	-544(ra) # 41e <vprintf>
}
 646:	60e2                	ld	ra,24(sp)
 648:	6442                	ld	s0,16(sp)
 64a:	6125                	addi	sp,sp,96
 64c:	8082                	ret

000000000000064e <free>:
 64e:	1141                	addi	sp,sp,-16
 650:	e422                	sd	s0,8(sp)
 652:	0800                	addi	s0,sp,16
 654:	ff050693          	addi	a3,a0,-16
 658:	00001797          	auipc	a5,0x1
 65c:	9a87b783          	ld	a5,-1624(a5) # 1000 <freep>
 660:	a02d                	j	68a <free+0x3c>
 662:	4618                	lw	a4,8(a2)
 664:	9f2d                	addw	a4,a4,a1
 666:	fee52c23          	sw	a4,-8(a0)
 66a:	6398                	ld	a4,0(a5)
 66c:	6310                	ld	a2,0(a4)
 66e:	a83d                	j	6ac <free+0x5e>
 670:	ff852703          	lw	a4,-8(a0)
 674:	9f31                	addw	a4,a4,a2
 676:	c798                	sw	a4,8(a5)
 678:	ff053683          	ld	a3,-16(a0)
 67c:	a091                	j	6c0 <free+0x72>
 67e:	6398                	ld	a4,0(a5)
 680:	00e7e463          	bltu	a5,a4,688 <free+0x3a>
 684:	00e6ea63          	bltu	a3,a4,698 <free+0x4a>
 688:	87ba                	mv	a5,a4
 68a:	fed7fae3          	bgeu	a5,a3,67e <free+0x30>
 68e:	6398                	ld	a4,0(a5)
 690:	00e6e463          	bltu	a3,a4,698 <free+0x4a>
 694:	fee7eae3          	bltu	a5,a4,688 <free+0x3a>
 698:	ff852583          	lw	a1,-8(a0)
 69c:	6390                	ld	a2,0(a5)
 69e:	02059813          	slli	a6,a1,0x20
 6a2:	01c85713          	srli	a4,a6,0x1c
 6a6:	9736                	add	a4,a4,a3
 6a8:	fae60de3          	beq	a2,a4,662 <free+0x14>
 6ac:	fec53823          	sd	a2,-16(a0)
 6b0:	4790                	lw	a2,8(a5)
 6b2:	02061593          	slli	a1,a2,0x20
 6b6:	01c5d713          	srli	a4,a1,0x1c
 6ba:	973e                	add	a4,a4,a5
 6bc:	fae68ae3          	beq	a3,a4,670 <free+0x22>
 6c0:	e394                	sd	a3,0(a5)
 6c2:	00001717          	auipc	a4,0x1
 6c6:	92f73f23          	sd	a5,-1730(a4) # 1000 <freep>
 6ca:	6422                	ld	s0,8(sp)
 6cc:	0141                	addi	sp,sp,16
 6ce:	8082                	ret

00000000000006d0 <malloc>:
 6d0:	7139                	addi	sp,sp,-64
 6d2:	fc06                	sd	ra,56(sp)
 6d4:	f822                	sd	s0,48(sp)
 6d6:	f426                	sd	s1,40(sp)
 6d8:	f04a                	sd	s2,32(sp)
 6da:	ec4e                	sd	s3,24(sp)
 6dc:	e852                	sd	s4,16(sp)
 6de:	e456                	sd	s5,8(sp)
 6e0:	e05a                	sd	s6,0(sp)
 6e2:	0080                	addi	s0,sp,64
 6e4:	02051493          	slli	s1,a0,0x20
 6e8:	9081                	srli	s1,s1,0x20
 6ea:	04bd                	addi	s1,s1,15
 6ec:	8091                	srli	s1,s1,0x4
 6ee:	0014899b          	addiw	s3,s1,1
 6f2:	0485                	addi	s1,s1,1
 6f4:	00001517          	auipc	a0,0x1
 6f8:	90c53503          	ld	a0,-1780(a0) # 1000 <freep>
 6fc:	c515                	beqz	a0,728 <malloc+0x58>
 6fe:	611c                	ld	a5,0(a0)
 700:	4798                	lw	a4,8(a5)
 702:	02977f63          	bgeu	a4,s1,740 <malloc+0x70>
 706:	8a4e                	mv	s4,s3
 708:	0009871b          	sext.w	a4,s3
 70c:	6685                	lui	a3,0x1
 70e:	00d77363          	bgeu	a4,a3,714 <malloc+0x44>
 712:	6a05                	lui	s4,0x1
 714:	000a0b1b          	sext.w	s6,s4
 718:	004a1a1b          	slliw	s4,s4,0x4
 71c:	00001917          	auipc	s2,0x1
 720:	8e490913          	addi	s2,s2,-1820 # 1000 <freep>
 724:	5afd                	li	s5,-1
 726:	a895                	j	79a <malloc+0xca>
 728:	00001797          	auipc	a5,0x1
 72c:	8e878793          	addi	a5,a5,-1816 # 1010 <base>
 730:	00001717          	auipc	a4,0x1
 734:	8cf73823          	sd	a5,-1840(a4) # 1000 <freep>
 738:	e39c                	sd	a5,0(a5)
 73a:	0007a423          	sw	zero,8(a5)
 73e:	b7e1                	j	706 <malloc+0x36>
 740:	02e48c63          	beq	s1,a4,778 <malloc+0xa8>
 744:	4137073b          	subw	a4,a4,s3
 748:	c798                	sw	a4,8(a5)
 74a:	02071693          	slli	a3,a4,0x20
 74e:	01c6d713          	srli	a4,a3,0x1c
 752:	97ba                	add	a5,a5,a4
 754:	0137a423          	sw	s3,8(a5)
 758:	00001717          	auipc	a4,0x1
 75c:	8aa73423          	sd	a0,-1880(a4) # 1000 <freep>
 760:	01078513          	addi	a0,a5,16
 764:	70e2                	ld	ra,56(sp)
 766:	7442                	ld	s0,48(sp)
 768:	74a2                	ld	s1,40(sp)
 76a:	7902                	ld	s2,32(sp)
 76c:	69e2                	ld	s3,24(sp)
 76e:	6a42                	ld	s4,16(sp)
 770:	6aa2                	ld	s5,8(sp)
 772:	6b02                	ld	s6,0(sp)
 774:	6121                	addi	sp,sp,64
 776:	8082                	ret
 778:	6398                	ld	a4,0(a5)
 77a:	e118                	sd	a4,0(a0)
 77c:	bff1                	j	758 <malloc+0x88>
 77e:	01652423          	sw	s6,8(a0)
 782:	0541                	addi	a0,a0,16
 784:	00000097          	auipc	ra,0x0
 788:	eca080e7          	jalr	-310(ra) # 64e <free>
 78c:	00093503          	ld	a0,0(s2)
 790:	d971                	beqz	a0,764 <malloc+0x94>
 792:	611c                	ld	a5,0(a0)
 794:	4798                	lw	a4,8(a5)
 796:	fa9775e3          	bgeu	a4,s1,740 <malloc+0x70>
 79a:	00093703          	ld	a4,0(s2)
 79e:	853e                	mv	a0,a5
 7a0:	fef719e3          	bne	a4,a5,792 <malloc+0xc2>
 7a4:	8552                	mv	a0,s4
 7a6:	00000097          	auipc	ra,0x0
 7aa:	b92080e7          	jalr	-1134(ra) # 338 <sbrk>
 7ae:	fd5518e3          	bne	a0,s5,77e <malloc+0xae>
 7b2:	4501                	li	a0,0
 7b4:	bf45                	j	764 <malloc+0x94>
